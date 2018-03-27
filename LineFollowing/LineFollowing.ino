#include <Servo.h>

Servo servoLeft;
Servo servoRight;

//pin numbers
int RIGHT_QTI = 52;
int CENTER_QTI = 51;
int LEFT_QTI = 47;

void setup() {
  Serial.begin(9600);

  //QTI pins
  pinMode(RIGHT_QTI, INPUT); //right
  pinMode(CENTER_QTI, INPUT); //center
  pinMode(LEFT_QTI, INPUT);

  //servos
  servoLeft.attach(13);
  servoRight.attach(12);
}

void loop() {
  if(rcTime(RIGHT_QTI) > 150 && rcTime(LEFT_QTI) > 150) {
//    checkHash();
    servoLeft.writeMicroseconds(1500); //counterclockwise
    servoRight.writeMicroseconds(1500);
    
  } else if (rcTime(RIGHT_QTI) > 150) {
      servoLeft.writeMicroseconds(1700);
      servoRight.writeMicroseconds(1700);
      Serial.println("Turn Left");
  } else if(rcTime(LEFT_QTI) > 150) {
      servoLeft.writeMicroseconds(1300);
      servoRight.writeMicroseconds(1300);
      Serial.println("Turn Right");
  } else { //move forward
      servoLeft.writeMicroseconds(1700);
      servoRight.writeMicroseconds(1300);
  }
}

bool checkHash() {
  
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(50);
  if (rcTime(RIGHT_QTI) < 150 && rcTime(LEFT_QTI) < 150) { //all white
    //is a square, move backwards at an angle
    if(rcTime(RIGHT_QTI) < 150) { //turning left
      servoLeft.writeMicroseconds(1400);
      servoRight.writeMicroseconds(1700);
      delay(1500);
    } else if(rcTime(LEFT_QTI) <150) { //turning right
      servoLeft.writeMicroseconds(1300);
      servoRight.writeMicroseconds(1600);
      delay(1500);
    }
  } else {
    servoLeft.writeMicroseconds(1500);
    servoRight.writeMicroseconds(1500);
  }
}

long rcTime( int pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(10);
  pinMode(pin, INPUT);
  digitalWrite(pin, LOW); 
  long time = micros();
  while(digitalRead(pin));

  //time = micros() - time;
  time = 1.153*(micros() - time);

  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  return time; 
}

