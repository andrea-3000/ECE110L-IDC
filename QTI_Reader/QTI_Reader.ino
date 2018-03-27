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
//  Serial.println(digitalRead(RIGHT_QTI));
//  Serial.println(digitalRead(CENTER_QTI));
//  Serial.println(digitalRead(LEFT_QTI));
  Serial.print("RIGHT: ");
  Serial.println(rcTime(RIGHT_QTI));
  Serial.print("CENTER: ");
  Serial.println(rcTime(CENTER_QTI));
  Serial.print("LEFT: ");
  Serial.println(rcTime(LEFT_QTI));
  delay(2000);

//  if() {
//    
//  }
}

long rcTime( int pin)

{
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

