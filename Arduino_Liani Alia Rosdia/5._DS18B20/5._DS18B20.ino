//Inisialisasi
#include <OneWire.h>
#include <DallasTemperature.h>

int sensorSuhu = 2;
OneWire oneWire(sensorSuhu);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sensors.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  float bacasuhu = sensors.getTempCByIndex(0);
  if(bacasuhu != DEVICE_DISCONNECTED_C){
    Serial.print("Data Suhu yang terbaca pada bus 1 (Index0) : ");
    Serial.println(bacasuhu);
  }
  else{
    Serial.println("Error : sensor pada index 0 tidak ditemukan ");
  }
}
