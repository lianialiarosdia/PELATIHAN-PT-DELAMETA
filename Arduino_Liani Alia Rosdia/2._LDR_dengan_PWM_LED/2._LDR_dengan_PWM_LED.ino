int sensorLDR =A0;

void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(sensorLDR,INPUT);
 pinMode(3, OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaLDR=analogRead(sensorLDR); //Membaca Nilai LDR
 //Print ke Serial Monitor
 bacaLDR = map(bacaLDR, 0, 1024, 0, 255);
 Serial.print("Nilai LDR:");
 Serial.print(bacaLDR);
 Serial.println();

  analogWrite(3, bacaLDR);
  delay(100);//Jeda waktu perulagan seama 500 mili detik
}
