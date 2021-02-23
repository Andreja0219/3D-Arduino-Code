/* This code has been re-written and edited by me but is taken from: 
 *  
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-servo-motor
 */

#include <Servo.h>

const int BUTTON_PIN = 7; 
const int SERVO_PIN  = 9; 

Servo servo; 

int angle = 0;          
int lastButtonState;    
int currentButtonState; 

void setup() {
  Serial.begin(9600);                
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  servo.attach(SERVO_PIN);           

  servo.write(angle);
  currentButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  lastButtonState    = currentButtonState;     
  currentButtonState = digitalRead(BUTTON_PIN); 

  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("Eureka!!");

    // change angle of servo motor
    if(angle == 0)
      angle = 10;
    else
    if(angle == 10)
      angle = 90;
     else
     if(angle==90)
     angle = 100;
      else
    if(angle == 100)
      angle = 180; 
      else if(angle == 180)
      angle = 75;
       else if(angle == 75)
      angle = 0;
    servo.write(angle);
  }
}
