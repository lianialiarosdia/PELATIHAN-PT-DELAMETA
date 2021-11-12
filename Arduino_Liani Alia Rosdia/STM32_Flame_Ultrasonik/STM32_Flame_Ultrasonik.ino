#include <NewPing.h>

//INISIALISASI
int trig = PA1;
int echo = PA0;
int batas = 400;

int flame = PA2;
int PIR = PA3;
int kunci =0;

int r = PA4;
int y = PA5;
int g = PA6;
NewPing cm(trig, echo, batas);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig, INPUT);
  pinMode(echo, INPUT);
  pinMode(flame, INPUT);
  pinMode(PIR, INPUT);

  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
  int bacajarak = cm.ping_cm();
  int bacaflame = digitalRead(flame);
  int bacaPIR = digitalRead(PIR);
  Serial.println("NILAI FLAME : " + String(bacaflame) + " | JARAK : " + String(bacajarak) + " | NILAI PIR : " + String(bacaPIR));
  delay(100);

  //LOGIKA
  if(bacaflame == 0 and kunci == 0){
    delay(500);
    kunci =1;
  }
  else if(bacaflame == 0 and kunci == 1){
    delay(500);
    kunci=0;
  }
  if(kunci == 1){
    if(bacajarak<=20 and bacajarak!=0){
      digitalWrite(r, HIGH);
        digitalWrite(y, HIGH);
        digitalWrite(g, HIGH);
        delay(100);
        digitalWrite(r, LOW);
        digitalWrite(y, LOW);
        digitalWrite(g, LOW);
        delay(100);
        Serial.println("TIDAK TERDETEKSI");
        delay(100);
    }
    else if(bacajarak >= 21 and bacajarak<=70){
      digitalWrite(r, HIGH);
      digitalWrite(y, HIGH);
      digitalWrite(g, HIGH);
      delay(1000);
      digitalWrite(r, LOW);
      digitalWrite(y, LOW);
      digitalWrite(g, LOW);
      delay(1000);
      Serial.println("JARAK TERDETEKSI MENDEKAT");
      delay(100);
      }
      else if(bacajarak>=71){
        digitalWrite(r, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(g, LOW);
      delay(500);
      digitalWrite(y, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(g, LOW);
      delay(500);
      digitalWrite(g, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(r, LOW);
      delay(500);
      digitalWrite(y, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(g, LOW);
      delay(500);
    }
  }
  else if (kunci == 0){
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
  }
  
}
