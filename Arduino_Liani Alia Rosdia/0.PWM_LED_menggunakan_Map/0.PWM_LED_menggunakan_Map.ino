
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=3; i<=6;i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(float i=0; i<=255 ;i++){
  analogWrite(3, i);
  analogWrite(5, i);
  analogWrite(6, i);
  float volt = map (i, 0.0, 255.0, 0.0,5.0);
  Serial.print("volt :");
  Serial.println(volt);
  delay(50);
  }
  for(float i=255; i>=0 ;i--){
  analogWrite(3, i);
  analogWrite(5, i);
  analogWrite(6, i);
  float volt = map (i, 0.0, 255.0, 0.0, 5.0);
  Serial.print("volt :");
  Serial.println(volt);
  delay(50);
  }
}
