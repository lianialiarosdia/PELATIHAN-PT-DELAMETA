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
 //bacaFlame = map(bacaFlame, 1024, 0, 0, 100);
 Serial.print("Nilai Flame:");
 Serial.print(bacaFlame);
 Serial.println();

//  if(bacaFlame <
// if(bacaFlame == 100){
//  digitalWrite(3, HIGH);
//  digitalWrite(
// }
}
