#include <SPI.h>
#include <MFRC522.h>

String uidString;
int buzzer = 2;
int ir = 7;
int kunci =0;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(buzzer,OUTPUT);
 pinMode(ir, INPUT);
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
 bunyibuzzeroke();
 Serial.println("Tempelkan kartu!");
}

void loop() {
  // put your main code here, to run repeatedly:
  int bacair = digitalRead(ir);
 if (mfrc522.PICC_IsNewCardPresent() && kunci==0) {
  readRFID();

  if(uidString == "A7-32-89-4B"){
    bunyibuzzeroke();
    Serial.println("BERHASIL!");
    delay(1000);
    Serial.println("PALANG TERBUKA");
    kunci = 1;
  }
  else{
    digitalWrite(buzzer, HIGH);
    Serial.println("GAGAL");
    delay(1000);
  }
  }
  if(bacair == 0 && kunci ==1){
    bunyibuzzergagal();
    Serial.println("PALANG TERTUTUP");
    delay(1000);
    kunci = 0;
  }
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  //pembatasan bisa dirubah sesuai keinginan, disini yang digunakan"-"
  uidString = String(mfrc522.uid.uidByte[0], HEX) + "-" +
              String(mfrc522.uid.uidByte[1], HEX) + "-" +
              String(mfrc522.uid.uidByte[2], HEX) + "-" +
              String(mfrc522.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}

void bunyibuzzeroke(){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}

void bunyibuzzergagal(){
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
}
