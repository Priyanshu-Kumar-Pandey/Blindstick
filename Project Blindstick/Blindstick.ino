
const int trigPin = 7;
const int echoPin = 6;
const int buzzerPin = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Send ultrasonic trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time (30 ms timeout)
  long duration = pulseIn(echoPin, HIGH, 30000);

  // Calculate distance in cm
  float distance = duration / 58.0;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Buzzer behaviour

  if (distance > 0 && distance <= 20) {
    // Very close obstacle: continuous buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(100);
  }

  else if (distance > 20 && distance <= 50) {
    // Medium distance: fast beeping
    digitalWrite(buzzerPin, HIGH);
    delay(150);
    digitalWrite(buzzerPin, LOW);
    delay(150);
  }

  else if (distance > 50 && distance <= 100) {
    // Far obstacle: slow beeping
    digitalWrite(buzzerPin, HIGH);
    delay(300);
    digitalWrite(buzzerPin, LOW);
    delay(500);
  }

  else {
    // No obstacle detected
    digitalWrite(buzzerPin, LOW);
  }

  delay(50);
}
