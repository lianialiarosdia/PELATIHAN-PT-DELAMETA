////Download Library LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

int outServo=6;//Pin untuk Servo
Servo myservo;

String uidString;
int buzzer = 5;
int tb1 = 3;
int kunci =0;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
 myservo.attach(outServo);
  pinMode(buzzer,OUTPUT);
  pinMode(tb1, INPUT);
 SPI.begin(); // Initiate SPI bus
 mfrc522.PCD_Init(); // Initiate MFRC522
 bunyibuzzeroke();
 lcd.setCursor(1,0);lcd.print("SELAMAT DATANG");
 lcd.setCursor(0,1);lcd.print(" TEMPELKAN KARTU");
}
void loop() {
  int bacatb1 = digitalRead(tb1);

  if (mfrc522.PICC_IsNewCardPresent() && kunci==0) {
  readRFID();

  if(uidString == "EA-06-D5-80"){
    lcd.clear();
    bunyibuzzeroke();
    lcd.setCursor(0,0);lcd.print("    BERHASIL!   ");
    delay(1000);
    lcd.setCursor(0,1);lcd.print(" SILAHKAN MASUK ");
    delay(100); 
    myservo.write(90); //0-180
    
    kunci = 1;
  }
  else if(uidString == "C7-9D-88-4A"){
    lcd.clear();
    bunyibuzzeroke();
    myservo.write(90); //0-180
    lcd.setCursor(0,0);lcd.print("    BERHASIL!   ");
    delay(1000);
    lcd.setCursor(0,1);lcd.print(" SILAHKAN MASUK ");
    delay(1000); 
    
    
    kunci = 1;
  }
  else{
    lcd.clear();
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(5,0);lcd.print(" GAGAL");
    delay(1000);
  }
  }
  if(bacatb1 == 1 && kunci ==1){
    lcd.clear();
    bunyibuzzergagal();
    myservo.write(0); //0-180
    lcd.setCursor(0,0);lcd.print("  TERIMAKASIH.  ");
    lcd.setCursor(0,1);lcd.print("  SELAMAT JALAN.   ");
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
 
