int ldr = A2;
int R = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 pinMode(ldr, INPUT);
 pinMode(R, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int bacaldr = analogRead(ldr);
 Serial.println("nilai LDR : " + String(bacaldr));
 int nilaildr = bacaldr/895 * 255;
  digitalWrite(R, nilaildr);
  delay(500);
  Serial.println("nilai ldr :" + String(nilaildr));
}
