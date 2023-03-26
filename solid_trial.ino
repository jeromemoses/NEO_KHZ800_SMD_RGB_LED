// Modified simple sketch to support RGBW strips like SK6812 based:
// http://www.szledcolor.com/download/SK6812RGBW.pdf
// Should be used with Adafruit NeoPixel version 1.0.3
// Hacked by G. Knauf 2015-12-06
// ws2812 RGBW나 sk6812 RGBW 칩을 사용할 경우에는 이 예제를 사용하세요.

#include <Adafruit_NeoPixel.h>


#define NEO_PIN 4 // NeoPixel DATA


// What type of NeoPixel strip is attached to the Arduino?
#define NEO_PTYPE NEO_GRBW  // f.e. SK6812
//#define NEO_PTYPE NEO_GRB   // most NeoPixel products

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32

int BRIGHTNESS = 200;   
int temp_brt = BRIGHTNESS;
#define IWAIT   2000
#define SWAIT   25
#define LWAIT   50
#define HWAIT   500

int r = 255;
int g = 100;
int b = 0;
uint32_t c = 0;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_GRBW    Pixels are wired for GRBW bitstream (f.e. SK6812)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEO_PIN, NEO_PTYPE + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

// NOTE: RGBW LEDs draw up to 80mA with all colors + white at full brightness!
// That means that a 60-pixel strip can draw up to 60x 80 = 4800mA, so you
// should use a 5A power supply; for a 144-pixel strip its max 11520mA = 12A!

void setup() {
  
  strip.begin(); // This initializes the NeoPixel library.
  strip.setBrightness(BRIGHTNESS); // set brightness
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);

#ifdef IWAIT
  delay(IWAIT);
#endif
delay(1000);

for(int i =0;i<NUMPIXELS;i++)
  {
    strip.setPixelColor(i, r,g,b);
    delay(10); 
  }
  strip.show(); 
}

void loop() {
//for(int i =0;i<NUMPIXELS;i++)
//  {
//    strip.setPixelColor(i, r,g,b);
//    delay(10);  
//  }
//  strip.show();
  serialEvent();
}

void serialEvent() {
  Serial.print("Enter colour ");
  Serial.println(": ");
  delay(2000);
  if(Serial.available())
  {
  r = Serial.parseInt();
  g = Serial.parseInt();
  b = Serial.parseInt(); 
   delay(10);
   if(Serial.read() == '\n')   
   {
    Serial.println("received successfully");
   }
     //strip.setBrightness(BRIGHTNESS);
    //colorWipe(strip.Color(r,g,b,0), LWAIT);

    //reduces led brightness if white colour code is given.
    if ((r >= 220) && (b >= 220) && (g >= 220) )
    {
      BRIGHTNESS = 100;
      strip.setBrightness(BRIGHTNESS);
    }
    else
    {
     BRIGHTNESS = temp_brt;
     strip.setBrightness(BRIGHTNESS);
    }
    
    for(int i =0;i<NUMPIXELS;i++)
    {
      strip.setPixelColor(i, r,g,b);
      delay(10);  
      strip.show(); 
    }
  }
}
