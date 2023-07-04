//defining the ultrasonic sensor pins
  const int trigPin = 9;
  const int echoPin = 10;

long duration;
int distance;
long notInUse;

void setup() {
  // put your setup code here, to run once:
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

//clears the alr stored data
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);

  duration = pulseIn(echoPin,HIGH);  //gives time value (kitne time tak pulse high rehti hai)
  distance = duration * 0.352/2;

  notInUse = pulseIn(echoPin,LOW);



  if (distance <= 500){
    Serial.println(distance);
   }
   else{
     Serial.println(notInUse);
   }


}
