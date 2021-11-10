int R = PA0;
int Y = PA1;
int G = PA2;
void setup() {
  // put your setup code here, to run once:
  pinMode(PC13, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(R, HIGH);
  delay(100);
  digitalWrite(R, LOW);
  delay(100);
  digitalWrite(Y, HIGH);
  delay(100);
  digitalWrite(Y, LOW);
  delay(100);
  digitalWrite(G, HIGH);
  delay(100);
  digitalWrite(G, LOW);
  delay(100);
  
  
}
