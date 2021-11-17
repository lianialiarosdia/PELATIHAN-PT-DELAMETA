//INISIALISASI
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

String uidString;
int pinservo =PA1;
int IR = PA2;
int r = PB5;
int y = PB4;
int g = PB3;
int kunci =0;

#define SS_pin PB1
#define RST_pin PB0

MFRC522 mfrc522(SS_pin, RST_pin);
Servo myservo;
LiquidCrystal_I2C lcd (0x27, 16, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  lcd.begin();
  mfrc522.PCD_Init();
  pinMode(IR, INPUT);
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  myservo.attach(pinservo);
  myservo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  int bacaIR = digitalRead(IR);
  Serial.println(" NILAI IR : " +String(bacaIR));

  if(mfrc522.PICC_IsNewCardPresent() and kunci ==0){
    readRFID();
    Serial.println(" TAG UID : " + String(uidString));
    if(uidString == "A-A8-90-15"){
      lcd.clear();
      myservo.write(90);
      digitalWrite(g, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(r, LOW);
      lcd.setCursor(0, 0); lcd.print(" BERJASIL ");
      Serial.println(" BERHASIL ");
      kunci =1;
    }
    else{
      digitalWrite(y, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(g, LOW);
      Serial.println(" KARTU BELUM TERDAFTAR");
      lcd.clear();
      lcd.setCursor(0, 0); lcd.print("GAGAL");
    }
  }
  if(bacaIR == 1 and kunci == 1){
    digitalWrite(g, LOW);
    digitalWrite(y, LOW);
    digitalWrite(r, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0); lcd.print("TERIMAKASIH");
    myservo.write(0);
    kunci=0;
  }  
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  uidString = String(mfrc522.uid.uidByte[0], HEX) + "-" +
              String(mfrc522.uid.uidByte[1], HEX) + "-" +
              String(mfrc522.uid.uidByte[2], HEX) + "-" +
              String(mfrc522.uid.uidByte[3], HEX);
              uidString.toUpperCase();
}
