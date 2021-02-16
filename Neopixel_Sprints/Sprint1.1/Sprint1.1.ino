/*To write this code I followed the steps 
in the 01_Color_cycle code modified Jan 2020
by Doug Whitton and Sweep_tutorial by BARRAGAN 
<http://barraganstudio.com> 
and modified 8 Nov 2013
by Scott Fitzgerald
http://www.arduino.cc/en/Tutorial/Sweep 
to write my own code.*/

#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 1

Adafruit_NeoPixel small(LED_COUNT, LED_PIN, NEO_GRB);


void setup() {

  small.begin();      
  small.show();            
  small.setBrightness(250); 

}

void loop() {

  colorWipe(small.Color(0,245,255), 1000); 
  colorWipe(small.Color(255, 235, 0), 1000); 
  colorWipe(small.Color(255,0, 186), 1000);
  colorWipe(small.Color(121,255, 173), 1000);
  colorWipe(small.Color(153,42, 203), 1000); 

}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<small.numPixels(); i++) { 
    small.setPixelColor(i, color);        
    small.show();                         
    delay(wait);                           
  }
}
