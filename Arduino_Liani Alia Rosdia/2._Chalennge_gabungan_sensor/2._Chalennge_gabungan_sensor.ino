//inisialisasi
int ldr =A0;
int flame = A1;
int PIR = 4;

int r = 3;
int buzzer = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(flame, INPUT);
  pinMode(PIR, INPUT);

  pinMode(r, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   //Untuk sensor PIR
   int bacapir = digitalRead(PIR);
   Serial.println("Nilai PIR : " + String(bacapir));
   int bacaldr = analogRead(ldr);
    bacaldr = map (bacaldr, 0, 1024, 0, 255);
    int bacaflame = analogRead(flame);
    bacaflame = map(bacaflame, 1024, 0,0, 100);
  
   
   //Untuk Sensor LDR
   
   analogWrite(r, bacaldr);
   delay(100);

   //Untuk sensor Flame
   

   if(bacaflame==0 && bacaflame>=20){
    digitalWrite(buzzer, LOW);
   }
   else if(bacaflame==100){
    digitalWrite(buzzer, HIGH);
   }
   Serial.println("Nilai PIR : " + String(bacapir) +" | Nilai LDR : " +String(bacaldr) + " | Nilai Flame : " + String (bacaflame));
}
