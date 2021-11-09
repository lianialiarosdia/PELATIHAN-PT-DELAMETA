int sensorFlame =A0;

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(sensorFlame,INPUT);
 pinMode(3, OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaFlame=analogRead(sensorFlame); //Membaca Nilai LDR
 //Print ke Serial Monitor
 bacaFlame = map(bacaFlame, 0, 1024, 0, 255);
 Serial.print("Nilai Flame:");
 Serial.print(bacaFlame);
 Serial.println();

  analogWrite(3, bacaFlame);
  delay(100);//Jeda waktu perulagan seama 500 mili detik
}
