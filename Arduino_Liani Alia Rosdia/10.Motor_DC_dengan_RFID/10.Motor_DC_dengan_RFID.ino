#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

#define A1 5 // Motor B pins
#define A2 6

int incomingByte = 0; // for incoming serial data
int input = 0;
String uidString;
int buzzer = 2;
int ir = 7;
int kunci =0;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 
LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(A1, OUTPUT);
 pinMode(A2, OUTPUT);
 pinMode(buzzer,OUTPUT);
 pinMode(ir, INPUT);
 digitalWrite(A1, LOW);
 digitalWrite(A2, LOW);
 SPI.begin(); // Initiate SPI bus
 lcd.begin();
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
    lcd.clear();
    bunyibuzzeroke();
    analogWrite(A1, 255);
    delay(80);
    analogWrite(A1, 0);
    lcd.setCursor(3,0);lcd.print("BERHASIL!");
    lcd.setCursor(0,1);lcd.print("SILAHKAN MASUK.");
    delay(100);
    Serial.println("PALANG TERBUKA");
    kunci = 1;
  }
  else{
    lcd.clear();
    digitalWrite(buzzer, HIGH);
    lcd.setCursor(1,1);lcd.print("GAGAL MASUK!");
    delay(100);
  }
  }
  if(bacair == 0 && kunci ==1){
    lcd.clear();
    analogWrite(A2, 255);
    delay(80);
    analogWrite(A2, 0);
    lcd.setCursor(2,0);lcd.print("TERIMAKASIH.");
    lcd.setCursor(1,1);lcd.print("SELAMAT JALAN.");
    delay(100);
    bunyibuzzergagal();
    Serial.println("PALANG TERTUTUP");
    delay(100);
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
