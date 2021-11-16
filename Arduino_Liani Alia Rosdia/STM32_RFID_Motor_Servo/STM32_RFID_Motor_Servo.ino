//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_pin PB1
#define RST_pin PB0
int outServo = PA2;
String uidString;

Servo myservo;
MFRC522 mfrc522(SS_pin, RST_pin);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  myservo.attach(outServo);
}

void loop() {
  // put your main code here, to run repeatedly:
  if ( ! mfrc522.PICC_IsNewCardPresent()) {return;}
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {return;}
  
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ""));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  
  mfrc522.PICC_ReadCardSerial();
  //pembatasan bisa dirubah sesuai keinginan, disini yang digunakan"-"
  uidString = String(mfrc522.uid.uidByte[0], HEX) + "-" +
              String(mfrc522.uid.uidByte[1], HEX) + "-" +
              String(mfrc522.uid.uidByte[2], HEX) + "-" +
              String(mfrc522.uid.uidByte[3], HEX);
              uidString.toUpperCase();
   Serial.println(" TAG UID : " + String(uidString));

   if(uidString == "8A-37-5A-1A"){
    myservo.write(0);
    Serial.println(" BERHASIL ");
    delay(100);
   }
   else{
    myservo.write(90);
    Serial.println( " GAGAL ");
    delay(100);
   }

}
