//To write this code I followed the steps in the NeoPixel Color Cycle tutorial

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



  colorWipe(small.Color(214,0,206), 1000); 
  colorWipe(small.Color(129, 250, 255), 1000); 

 
   delay(1000);   
     
  colorWipe(small.Color(255,147, 0), 1000);
  colorWipe(small.Color(0,129, 224), 1000);
  colorWipe(small.Color(255,248, 62), 1000); 

   delay(1000);   

 colorWipe(small.Color(255,248, 62), 1000);
  colorWipe(small.Color(108,0,255), 1000); 


   delay(1000);   
  
  colorWipe(small.Color(255, 235, 0), 1000); 
  colorWipe(small.Color(255,0, 186), 1000);
  colorWipe(small.Color(121,255, 173), 1000);

}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<small.numPixels(); i++) { 
    small.setPixelColor(i, color);        
    small.show();                         
    delay(wait);                           
  }
}
