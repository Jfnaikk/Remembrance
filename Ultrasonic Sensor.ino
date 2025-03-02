#define TRIG_PIN 9
#define ECHO_PIN 10
#define DISTANCE_THRESHOLD 10 // Distance in cm to detect an object

void setup() {
    Serial.begin(9600);  // Initialize Serial Communication
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    long duration;
    int distance;

    // Send a 10us HIGH pulse to trigger the sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read the echo pulse duration
    duration = pulseIn(ECHO_PIN, HIGH);

    // Convert duration to distance in cm
    distance = duration * 0.034 / 2;

    // Send 0 if an object is detected within threshold, otherwise send 1
    if (distance > 0 && distance <= DISTANCE_THRESHOLD) {
        Serial.println(0);
    } else {
        Serial.println(1);
    }

    delay(100); // Short delay before the next measurement
}
