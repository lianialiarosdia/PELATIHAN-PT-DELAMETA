//INISIALISASI
int IR = PA0;
int LDR = PA1;

int r = PA2;
int y = PA3;
int g = PA4;

int kunci = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(IR, INPUT);
  pinMode(LDR, INPUT);

  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  //BACA DATA
  int bacair = digitalRead(IR);
  int bacaldr = analogRead(LDR);
  bacaldr = map(bacaldr, 4095, 0, 0, 255);

  if(bacair == 1 and kunci == 0){
    delay(500);
    kunci=1;   
    }
  else  if(bacair==1 and kunci == 1){
    delay(500);
    kunci =0;   
  }

  if(kunci == 1){
    if( bacaldr<=100){
      digitalWrite(r, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(g, LOW);
    }
    else if(bacaldr>=101 and bacaldr<=200){
      digitalWrite(y, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(g, LOW);
    }
    else if(bacaldr>=201 and bacaldr<=255){
      digitalWrite(g, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(r, LOW);
    }
  }
  else if(kunci ==0){
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
  }
  Serial.println("NILAI LDR : " +String(bacaldr) + " | Nilai IR : " +String(bacair));
}
