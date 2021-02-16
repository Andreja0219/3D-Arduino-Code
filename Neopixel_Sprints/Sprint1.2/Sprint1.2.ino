//To write this code I followed the steps in Theatre Mode Neopixel tutorial

#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 2

Adafruit_NeoPixel small(LED_COUNT, LED_PIN, NEO_GRB);


void setup() {

  small.begin();      
  small.show();            
  small.setBrightness(255); 

}

void loop() {

  uint32_t(small.Color(253,184,251), 1000); 
  uint32_t(small.Color(226, 0, 255), 1000); 
  uint32_t(small.Color(255,16, 186), 1000);
  uint32_t(small.Color(255,121, 245), 1000);
  uint32_t(small.Color(255,221, 250), 1000);
  uint32_t(small.Color(255,80, 248), 1000);  

int pause = 1000;

colourCycle(200);

}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<small.numPixels(); i++) { 
    small.setPixelColor(i, color);        
    small.show();                         
    delay(wait);                           
  }
}

void colourCycle(uint32_t color, int wait) {
  for(int a=0; a<6; a++) {  
    for(int b=0; b<3; b++) { 
      small.clear();        
    
      for(int c=b; c<small.numPixels(); c += 3) {
        small.setPixelColor(c, color); 
      }
      small.show(); 
      delay(wait);  
    }
  }
}


void rainbow(int wait) {
  
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<small.numPixels(); i++) { 
      
      int pixelHue = firstPixelHue + (i * 65536L / small.numPixels());
     
      small.setPixelColor(i, small.gamma32(small.ColorHSV(pixelHue)));
    }
    small.show(); 
    delay(wait);  
  }
}

void colourCycle(int wait) {
  int firstPixelHue = 0;     
  for(int a=0; a<30; a++) { 
    for(int b=0; b<3; b++) { 
      small.clear();       
     
      for(int c=b; c<small.numPixels(); c += 3) {
       
        int      hue   = firstPixelHue + c * 65536L / small.numPixels();
        uint32_t color = small.gamma32(small.ColorHSV(hue)); 
        small.setPixelColor(c, color); 
      }
      small.show();                
      delay(wait);               
      firstPixelHue += 65536 / 90; 
    }
  }
}
