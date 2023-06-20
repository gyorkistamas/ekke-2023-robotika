#include <Stepper.h>

#define trigger 11
#define echo 10

long duration;
int distance;

int stepsPerRevolution = 102;
int fullRotation = 2038;
int limit = 0;
int currStep = 0;
bool clockwise = true;
int count = 0;
Stepper myStepper(fullRotation, 6, 8, 7, 9);


void setup() {

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(12, OUTPUT);
  myStepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() 
{
	MotorHandler();
}

void SensorHandler()
{
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration * 0.034 / 2;
  //Serial.print("Distance: ");
  //Serial.println(distance);
  if(distance < 10){
    Buzz();
    Serial.println(count);
  }
}

float microsecondsToCentimeters(float microseconds) {
   return microseconds / 29 / 2;
}

void MotorHandler(){
  
  if(clockwise){

    while(currStep < limit){
    myStepper.step(stepsPerRevolution);
    currStep += stepsPerRevolution;
    count++;
    SensorHandler();
  }

    stepsPerRevolution = -stepsPerRevolution;
    limit = 0;
    clockwise = false;
  }
  else{
      while(currStep > limit){
      myStepper.step(stepsPerRevolution);
      currStep += stepsPerRevolution;
      count--;
      SensorHandler();
    }
      stepsPerRevolution = -stepsPerRevolution;
      limit = fullRotation;
      clockwise = true;
  }
  
}

void Buzz(){
  tone(12, 3000);
  delay(10);
  noTone(12);
}
  

