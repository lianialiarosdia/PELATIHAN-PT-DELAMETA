//inisialisasi input (tombol)
int tb1 =2;
int tb2=3;
int tb3=4;

//inisialisasi output(LED)
int R =5;
int Y =6;
int G =7;

void setup() {
  // penyetingan input, output, dan baudrate
  Serial.begin (9600);
  for(int i=5; i<=7; i++){pinMode(i, OUTPUT);} 
  for(int x=2; x<=4; x++){pinMode(x, INPUT);}
}

void loop() {
  //BACA DATA INPUT
  int bacatb1 = digitalRead(tb1);
  int bacatb2 = digitalRead(tb2); 
  int bacatb3 = digitalRead(tb3); 

 // LOGIKA
 //START TOMBOL1
 if( bacatb1 ==1 || bacatb2 ==1 ){digitalWrite(R, HIGH);} //untuk fungsi or dapat menggunakan (|| atau or)
 else{digitalWrite(R, LOW); digitalWrite(Y, LOW);}
 //STOP TOMBOL1

 //START TOMBOL2
 //if( bacatb2 ==1 ){digitalWrite(Y, HIGH); digitalWrite(R, LOW); digitalWrite(G, HIGH);}
 //else{digitalWrite(Y, LOW); digitalWrite(G, LOW);}
 //STOP TOMBOL2

 //START TOMBOL3
 //if( bacatb3 ==1 ){digitalWrite(G, HIGH); digitalWrite(R, HIGH); digitalWrite(Y, LOW);}
 //else{digitalWrite(G, LOW); digitalWrite(R, LOW);}
 //STOP TOMBOL3
 
 //PRINT SERIAL
 Serial.println("Kondisi Tombol 1: " + String(bacatb1)+ " | Kondisi Tombol 2: " + String(bacatb2)+ " | Kondisi Tombol 3 :" + String(bacatb3) );
   
}
