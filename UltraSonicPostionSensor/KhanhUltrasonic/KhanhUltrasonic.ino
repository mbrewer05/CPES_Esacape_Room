int trigPin = 5;
int echoPin = 6;
int ledPin = 7;
long duration, cm, inches;
boolean ledOn = false;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;

  if(5<inches && inches<8){
    digitalWrite(ledPin,HIGH);
    ledOn = true;
  } else if(ledOn){
    digitalWrite(ledPin,LOW);
    ledOn = false;
  }
  
  delay(100);
  
}
