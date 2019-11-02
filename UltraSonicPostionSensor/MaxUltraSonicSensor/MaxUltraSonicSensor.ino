//pin numbers
const int TRIGx = 5;
const int ECHOx = 6;
const int TRIGy = 9;
const int ECHOy = 10;
const int led1 = 7;

const int distanceToX = 16;
const int distanceToY = 14;

long durationx;
long durationy;
int distancex;
int distancey;
//use to get a consitant reading
int cycleCount;
  
void setup(){
  // initialize outputs and inputs
  pinMode(TRIGx, OUTPUT);
  pinMode(ECHOx, INPUT);
  pinMode(TRIGy, OUTPUT);
  pinMode(ECHOy, INPUT);
  pinMode(led1, OUTPUT);
  //clear output
  digitalWrite(led1, LOW);
  Serial.begin(9600);
  cycleCount = 0;
}

void loop(){
  //clear trig pin
  digitalWrite(TRIGx, LOW);
  digitalWrite(TRIGy, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIGx, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGx, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationx = pulseIn(ECHOx, HIGH);
  // Calculating the distance
  distancex= durationx*0.034/2;

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIGy, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGy, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationy = pulseIn(ECHOy, HIGH);  
  // Calculating the distance
  distancey= durationy*0.034/2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("DistanceX: ");
  Serial.println(distancex);
  Serial.print("DistanceY: ");
  Serial.println(distancey);

  //process output
  if (((distanceToX - 3) < distancex && distancex < (distanceToX +3)) && ((distanceToY - 3) < distancey && distancey < (distanceToY +3)))
  {
      cycleCount ++;
      if (cycleCount > 25){
        digitalWrite(led1, HIGH);
      }
  }
  else
  {
    cycleCount = 0;
    digitalWrite(led1, LOW);
  }
  delay(10);
}
