#include <Stepper.h>

#define trigger 11
#define echo 10

long duration;
int distance;

int stepsPerRevolution = 64;
int fullRotation = 2038;
int limit = 0;
int currStep = 0;
bool clockwise = true;
Stepper myStepper(fullRotation, 6, 8, 7, 9);


void setup() {

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  myStepper.setSpeed(11);
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
}

float microsecondsToCentimeters(float microseconds) {
   return microseconds / 29 / 2;
}

void MotorHandler(){
  
  if(clockwise){

    while(currStep < limit){
    myStepper.step(stepsPerRevolution);
    currStep += stepsPerRevolution;
    SensorHandler();
    Serial.print(currStep);
    Serial.print("<");
    Serial.println(limit); 
  }

    stepsPerRevolution = -stepsPerRevolution;
    limit = 0;
    clockwise = false;
    Serial.println("true");

  }
  else{
      while(currStep > limit){
      myStepper.step(stepsPerRevolution);
      currStep += stepsPerRevolution;
      SensorHandler();
      Serial.print(currStep);
      Serial.print("<");
      Serial.println(limit); 
    }
      stepsPerRevolution = -stepsPerRevolution;
      limit = fullRotation;
      clockwise = true;
      Serial.println("false");
  }
  
}

