// Arduino Code: Ultrasonic Sensor Object Detection (0 = No Object, 1 = Object Detected)
// Author: Jawad Naik
// Date: 2025-02-26
// Description: Sends "0" when no object is detected and "1" when an object is within range.

const int trigPin = 9;  // Trig pin of HC-SR04
const int echoPin = 10; // Echo pin of HC-SR04
long duration;
int distance_cm;
const int detectionThreshold = 20; // Set object detection range in cm

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read echo pin and calculate distance in cm
  duration = pulseIn(echoPin, HIGH);
  distance_cm = duration * 0.034 / 2.0; // Convert to cm
  
  // Send "1" if an object is within the detection threshold, otherwise "0"
  if (distance_cm > 0 && distance_cm < detectionThreshold) {
    Serial.println(1);
  } else {
    Serial.println(0);
  }
  
  delay(100); // Delay for stable readings
}
