//definisi pin input-output sinyal ultrasonic
const int pingPin = A1;
const int echoPin = A0;
 
int kiriA = 13;
int kiriB = 12;
int kananA = 9;
int kananB = 8;
int en1 = 11;
int en2 = 10;


void setup()
{
  //initialize serial communication
  Serial.begin(9600);
  pinMode(kiriA,OUTPUT);
  pinMode(kiriB,OUTPUT);
  pinMode(kananA,OUTPUT);
  pinMode(kananB,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
}
void loop()
{
  long duration, inches, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  //SERIAL DEBUG
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  analogWrite(en1,255);
  analogWrite(en2,255);
  
  if (cm <=50){
  digitalWrite(kiriA,HIGH);
  digitalWrite(kiriB,LOW);
  digitalWrite(kananA,HIGH);
  digitalWrite(kananB,LOW);
    Serial.println ("Belok Kiri");
  }
  else 
  {
  digitalWrite(kiriA,LOW);
  digitalWrite(kiriB,HIGH);
  digitalWrite(kananA,LOW);
  digitalWrite(kananB,HIGH);
    Serial.println ("Maju");
  }
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29 /2;
}