int PIR = 2;
int buz=5;

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 pinMode(PIR,INPUT);
 pinMode(buz, OUTPUT);
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 int bacaPIR=digitalRead(PIR); //Membaca Nilai Sensor PIR
 //Print ke Serial Monitor
 Serial.print("Sensor PIR:");
 Serial.print(bacaPIR);
 Serial.println();
  delay(500);
 for (int i=700; i<=1000; i++){
  tone(buz, i);
  
 }
}
