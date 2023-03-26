#include <Adafruit_NeoPixel.h>

#define NEO_PIN 4 // NeoPixel DATA

#define NEO_PTYPE NEO_GRBW  // f.e. SK6812

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32

int BRIGHTNESS = 125;   

int r = 0;
int g = 0;
int b = 0;
uint32_t c = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEO_PIN, NEO_PTYPE + NEO_KHZ800);

void glow();

void setup() {
  
  strip.begin(); // This initializes the NeoPixel library.
  strip.setBrightness(BRIGHTNESS); // set brightness
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);

for(int i =0;i<NUMPIXELS;i++)
  {
    strip.setPixelColor(i, r,g,b);
    delay(10); 
  }
  strip.show(); 
  delay(2000);
}

void loop() {
  //white
  r = 255;
  g = 100;
  b = 0;
  glow();
  delay(15000);
//  //warm yellow
//  r = 200;
//  g = 128;
//  b = 0;
//  glow();
//  delay(15000);
//  //golden 
//  r = 190;
//  g = 110;
//  b = 0;
//  glow();
//  delay(15000);
//  //cool moon light
//  r = 180;
//  g = 100;
//  b = 50;
//  glow();
//  delay(15000);
}

void glow()
{
   //reduces brightness if white color code occured
    for(int i =0;i<NUMPIXELS;i++)
    {
      strip.setPixelColor(i, r,g,b);
      delay(10);
      strip.show();
    }
}
