#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

//Inisialisasi pembuatan variable
#define SS_PIN  PB1 //SDA
#define RST_PIN PB0  //RESET

String uidString;
int kunci = 0;

int pinButton = PA2;
int pinServo = PA1;
Servo myServo;

MFRC522 mfrc522(SS_PIN, RST_PIN); 

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("MULAI!");
  myServo.attach(pinServo);

  pinMode(pinButton, INPUT);
}

void loop() {
  int buttonRead = digitalRead(pinButton);
  Serial.println(buttonRead);
  if(mfrc522.PICC_IsNewCardPresent() && kunci == 0){
    readRFID();
    Serial.print("TAG UID : ");
    Serial.println(uidString);
    if (uidString == "A7-32-89-4B") //change here the UID of the card/cards that you want to give access
    {
      myServo.write(0); //0-180
      delay(1000); //Jeda waktu perulagan seama 1000 mili detik
      myServo.write(180); //0-180
      delay(1000);
      Serial.println("Terdaftar");
      kunci = 1;
    }
    else{
      Serial.println("Kartu Belum Terdaftar!");
    }
  }
  if(buttonRead == 1 && kunci == 1){
      myServo.write(180); //0-180
      delay(1000); //Jeda waktu perulagan seama 1000 mili detik
      myServo.write(0); //0-180
      delay(1000);
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
