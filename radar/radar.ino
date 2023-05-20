//#include <Stepper.h>

#define trigger 9
#define echo 10

long duration;
int distance;

int stepsPerRevolution = 64;
int fullRotation = 2038
string state = "clockwise";
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
  Serial.print("Distance: ");
  Serial.println(distance);
}

float microsecondsToCentimeters(float microseconds) {
   return microseconds / 29 / 2;
}

void MotorHandler(){

  switch(state){
    case "clockwise":
      stepsPerRevolution = -stepsPerRevolution;
      limit = 0;
      state = "counterClockwise"
    break;
    case "counterClockwise":
      stepsPerRevolution = -stepsPerRevolution;
      limit = fullRotation;
      state = "clockwise";
    break;
  }

  while(currStep < limit){
    SetSpeed();
    myStepper.step(stepsPerRevolution);
    SensorHandler();
  }
}

void SetSpeed(){
  //potmeter
}

