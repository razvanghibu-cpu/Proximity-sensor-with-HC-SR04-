const int trigPin = 10;
const int echoPin = 11;
int verde=4;
int g1=2;
int g2=6;
int r=5;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(g1, OUTPUT);
  pinMode(g2, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(g1, LOW);
  digitalWrite(g2, LOW);

  digitalWrite(r, LOW);


  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance<15)
  {
      digitalWrite(verde, HIGH);
      if(distance<10)
      {
         digitalWrite(g1, HIGH);
            if(distance<5){
            digitalWrite(g2, HIGH);
            if(distance<3)
               digitalWrite(r, HIGH);

            }

      }


  }
  delay(50);
}
