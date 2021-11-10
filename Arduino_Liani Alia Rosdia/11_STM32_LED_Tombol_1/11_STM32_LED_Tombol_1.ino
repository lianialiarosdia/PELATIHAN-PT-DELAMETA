//inisialisasi OUTPUT
int R = PA0;
int Y = PA1;
int G = PA2;

//inisialisasi INPUT
int tb1 =PA3;
int tb2 =PA4;
int tb3 =PA5;

void setup() {
  // put your setup code here, to run once:

  //Penyetingan pin sebagai INPUT
  pinMode(tb1, INPUT);
  pinMode(tb2, INPUT);
  pinMode(tb3, INPUT);

  //Penyetingan pin sebagai OUTPUT
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
  int bacatb1 = digitalRead(tb1);
  int bacatb2 = digitalRead(tb2);
  int bacatb3 = digitalRead(tb3);

  //LOGIKA
  //untuk tombol 1 (RED ON)
  if(bacatb1 == 1){
    digitalWrite(R, HIGH);
  }
  else{
    digitalWrite(R, LOW);
  }

  //untuk tombol 2 (YELLOW ON)
  if(bacatb2 == 1){
    digitalWrite(Y, HIGH);
  }
  else{
    digitalWrite(Y, LOW);
  }

  //untuk tombol 3 (GREEN ON)
  if(bacatb3 == 1){
    digitalWrite(G, HIGH);
  }
  else{
    digitalWrite(G, LOW);
  }
}
