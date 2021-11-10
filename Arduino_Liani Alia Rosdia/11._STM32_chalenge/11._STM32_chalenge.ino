//INISIALISASI INPUT
int tb1 = PA0;
int tb2 = PA1;
int tb3 = PA2;

//inisialisasi OUTPUT
int R = PA3;
int Y = PA4;
int G = PA5;

int kunci = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tb1, INPUT);
  pinMode(tb2, INPUT);
  pinMode(tb3, INPUT);

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

  Serial.println("Tombol 1 : " + String(bacatb1) + " | Tombol 2 : " + String(bacatb2) + " | Tombol 3 : " + String(bacatb3));

  //LOGIKA
  if(bacatb1 == 1 and kunci == 0){
    delay(500);
    digitalWrite(R, HIGH);
    kunci = 1;
  }
  else if(bacatb1 == 1 and kunci == 1){
    delay(500);
    digitalWrite(R, LOW);
    kunci =0;
  }
  if(bacatb2 == 1 and kunci == 0){
    delay(500);
    digitalWrite(Y, HIGH);
    kunci = 1;
  }
  else if(bacatb2 == 1 and kunci == 1){
    delay(500);
    digitalWrite(Y, LOW);
    kunci =0;
  }
  if(bacatb3 == 1 and kunci == 0){
    delay(500);
    digitalWrite(G, HIGH);
    kunci =1;
  }
  else if(bacatb3 == 1 and kunci == 1){
    delay(500);
    digitalWrite(G, LOW);
    kunci =0;
  }
}
