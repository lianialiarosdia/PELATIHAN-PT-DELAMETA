//Inisialisasi
#include <OneWire.h>
#include <DallasTemperature.h>

int sensorSuhu = 2;
int buzzer = 3;
int Red = 4;
int Green = 5;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sensors.begin();
  pinMode(sensorSuhu, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  float bacasuhu = sensors.getTempCByIndex(0);
  if(bacasuhu >= 30){
    Serial.print("Data Suhu yang terbaca pada bus 1 (Index0) : ");
    Serial.println(bacasuhu);
    digitalWrite(buzzer, HIGH);
    digitalWrite(Red, HIGH);
    digitalWrite(Green, LOW);
  }
  else{
    Serial.println(" Suhu Normal ");
    digitalWrite(buzzer, LOW);
    digitalWrite(Green, HIGH);
    digitalWrite(Red, LOW);
  }
}
