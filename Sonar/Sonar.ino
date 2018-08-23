// Written by Sumner J Bradley
// 02/22/18

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;
int piezoPin1 = 8;
int piezoPin2 = 7;
int buttonPin = 6;
int buttonState;
int freq = 1000;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buttonPin, INPUT); // Sets buttonPin as input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Get button high or low
  buttonState = digitalRead(buttonPin);
  
  // Calculating the distance
  distance= duration*0.034/2;
  
  // Print distance an button state to serial
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("Button state = ");
  Serial.println(buttonState);

  // If button is pushed ping for location
  if (buttonState == HIGH) {
    // Check distance
    if (distance <= 25) {
      delay(500);
      tone(piezoPin1, freq, 100);
      tone(piezoPin2, freq, 100);
    }
    else if (distance <= 50) {
      delay(1000);
      tone(piezoPin1, freq, 100);
      tone(piezoPin2, freq, 100);
    }
    else if (distance <= 80) {
      delay(1500);
      tone(piezoPin1, freq, 100);
      tone(piezoPin2, freq, 100);
    }
    else {
      tone(piezoPin1, 0, 100);
      tone(piezoPin2, 0, 100);
    }
  }
  // Sound buzzers if button is not pushed
  else {
    tone(piezoPin1, freq, 100);
    tone(piezoPin2, freq, 100);
  }
}
