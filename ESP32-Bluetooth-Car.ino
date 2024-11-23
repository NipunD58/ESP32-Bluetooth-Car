#include "BluetoothSerial.h"
#include "Arduino.h"

BluetoothSerial SerialBT;

int IN1 = 26;  // Motor A forward
int IN2 = 27;  // Motor A backward
int IN3 = 14;  // Motor B forward
int IN4 = 12;  // Motor B backward

char command = ' ';
char lastCommand = ' '; 

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  SerialBT.begin("ESP32_RC_Car"); 
  Serial.begin(9600);
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
 
  while (SerialBT.available()) {
    command = SerialBT.read(); 
    Serial.print("Received Command: ");
    Serial.println(command); 
  }

  if (command != lastCommand) {
    lastCommand = command;

    switch (command) {
      case 'F':
        // forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        Serial.println("Moving Forward");
        break;

      case 'B':
        // backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        Serial.println("Moving Backward");
        break;

      case 'L':
        // left 
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        Serial.println("Turning Left");
        break;

      case 'R':
        // right 
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        Serial.println("Turning Right");
        break;

      case 'S':
        // stop 
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        Serial.println("Stopping");
        break;

      default:
        
        break;
    }
  }
}
