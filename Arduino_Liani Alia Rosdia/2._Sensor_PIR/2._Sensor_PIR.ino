//Inisialisasi pembuatan variable
int sensorPIR =2;
int buz=5;
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(sensorPIR,INPUT);
 pinMode(buz, OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaPIR=digitalRead(sensorPIR); //Membaca Nilai Sensor PIR
 //Print ke Serial Monitor
 Serial.print("Sensor PIR:");
 Serial.print(bacaPIR);
 Serial.println();
  delay(500);

 if(bacaPIR==1){
  digitalWrite(buz, HIGH);
  delay(500);
  digitalWrite(buz, LOW);
  delay(500);
  Serial.println("WARNING!");
 }
 else{digitalWrite(buz, LOW);
 Serial.println("SAVE");}
 
 //Jeda waktu perulagan seama 500 mili detik
}
