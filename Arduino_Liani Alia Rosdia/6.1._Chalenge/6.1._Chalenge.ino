#include <NewPing.h>

//Inisialisasi pembuatan variable
int triger =6;
int echo =7;
int batas =200; //Maksimal 400 cm

int buzzer = 3;
int Red = 4;
int yellow = 8;
int green =5;

NewPing cm(triger,echo,batas);
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(buzzer, OUTPUT);
 pinMode(triger, INPUT);
 pinMode(echo, INPUT);
 pinMode(Red, OUTPUT);
 pinMode(yellow, OUTPUT);
 pinMode(green, OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaJarak=cm.ping_cm();
 //Print ke Serial Monitor
 if(bacaJarak <=20 and bacaJarak != 0){
  Serial.println("BERHENTI");
  delay(100);
  digitalWrite(Red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
 }else if(bacaJarak >=21 and bacaJarak <=70){
  Serial.println("BAHAYA");
  delay(100);
  digitalWrite(green, LOW);
  digitalWrite(Red, LOW);
  digitalWrite(yellow, HIGH);
  delay(100);
  digitalWrite(yellow, LOW);
  delay(100);
 }
 else if(bacaJarak>=71){
  Serial.println("AMAN");
  delay(100);
  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(Red, LOW);
 }
 Serial.print("Data jarak:");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();
 delay(500); //Jeda waktu perulagan seama 500 mili detik
}
