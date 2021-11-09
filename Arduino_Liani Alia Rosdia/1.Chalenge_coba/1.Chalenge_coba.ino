//inisialisasi 
int ir = 2;
int tb =3;

int R =4;
int Y =5;
int G=6;

int kunci =0;
int kunci1=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ir, INPUT);
  pinMode(tb, INPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  digitalWrite(R, HIGH);
  Serial.println("SYSTEM START");
}

void loop() {
  // put your main code here, to run repeatedly:
  //BACA DATA
  int bacaIR = digitalRead(ir);
  int bacatb = digitalRead(tb);

  //LOGIKA
  if(bacaIR == 0){
    delay(500);
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
  }
  if (bacatb == 1){
    delay(500);
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);
    delay(1000);
    digitalWrite(Y, LOW);
    digitalWrite(G, HIGH);
    }

}
