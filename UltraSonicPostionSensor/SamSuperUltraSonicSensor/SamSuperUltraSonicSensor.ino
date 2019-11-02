//part number for sensor: HC-SR04, Ultrasonic sensor, elegoo.com
//pinMode(x,y)
//digitalWrite(x,y)
//analogWrite(x,y)

int TRIG_PIN = 5; 
int ECHO_PIN = 6; 
int LED_PIN = 7; 
long duration, cm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
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
  //  print the cm distance in cm 
  //  Serial.print("cm: ");
  //  Serial.println(cm);
  int distance_off = abs(15 - cm); 
  if (distance_off <= 2){
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }
  delay(250);
}
