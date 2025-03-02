import processing.sound.*;
import processing.serial.*;

SoundFile alarm;  // Sound file
Serial myPort;    // Serial communication
boolean isPlaying = false; // Track sound state

void setup() {
  size(400, 200);
  background(0);
  
  // Use the correct port for your Arduino
  String portName = "/dev/cu.usbmodem2101"; 
  myPort = new Serial(this, portName, 9600);
  
  // Load sound file (Ensure it's in the sketch folder)
  alarm = new SoundFile(this, "alarm.mp3"); 
}

void draw() {
  // Check if data is available
  while (myPort.available() > 0) {
    String value = myPort.readStringUntil('\n'); // Read serial data
    if (value != null) {
      value = value.trim(); // Remove extra spaces
      
      if (value.equals("1")) { 
        if (!isPlaying) { 
          alarm.loop(); // Play sound in loop
          isPlaying = true;
        }
      } else if (value.equals("0")) { 
        alarm.stop();  // Stop playing
        isPlaying = false;
      }
    }
  }
}
