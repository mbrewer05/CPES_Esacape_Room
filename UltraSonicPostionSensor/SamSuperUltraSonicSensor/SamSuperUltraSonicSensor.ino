//part number for sensor: HC-SR04, Ultrasonic sensor, elegoo.com
//pinMode(x,y)
//digitalWrite(x,y)
//analogWrite(x,y)

int TRIG_PIN = 5; 
int ECHO_PIN = 6; 
long duration, cm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //pulse for 10 microseconds 
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  //read the input 
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH); 

  //take the time that it was pulsed and convert it into a distance in cm
  cm = (duration/2) / 29.1;

  Serial.print("cm: ");
  Serial.println(cm);

  delay(250);
}
