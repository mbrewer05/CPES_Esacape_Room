#define LED 7
#define trigger 5
#define echo 6

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  //send wave
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger,LOW):
  long time = pulseIn(echo, HIGH);
  Serial.print("distance cm: ");
  Serial.print(34300.0*time/2);
}
