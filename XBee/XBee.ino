void setup() {
  //start serial ports
  Serial.begin(9600); //for computer
  Serial2.begin(9600); //for bot

  //green LED - sending
  pinMode(11, OUTPUT); 
  digitalWrite(11, LOW);

  //green LED - receiving
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);

  pinMode(2, INPUT);   //button
  delay(500);  
}

void loop() {
  //if transmitting
  if(!digitalRead(2)) {
    Serial2.print("s");
    
    //turn on green LED
    digitalWrite(11, HIGH);
    delay(100);
    digitalWrite(11, LOW);
  }

  //if receiving
  if(Serial2.available()){
    char incoming = Serial2.read();
    //turn on red LED
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
    Serial.println(incoming);
  }
  delay(50);
}
