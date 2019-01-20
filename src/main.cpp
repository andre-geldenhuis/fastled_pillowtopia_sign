#include "FastLED.h"

FASTLED_USING_NAMESPACE


#define NUM_LEDS 200
#define NUM_LEDS_S2  50
#define NUM_LEDS_G  31
#define NUM_LEDS_U 30
#define NUM_LEDS_N 10
#define NUM_LEDS_S1 10


CRGBArray<NUM_LEDS> leds;
CRGBSet leds_S2(leds, 0,                                                                    NUM_LEDS_S2);
CRGBSet leds_G(leds, NUM_LEDS_S2,                                                           NUM_LEDS_G);
// CRGBSet leds_U(leds, NUM_LEDS_S2+NUM_LEDS_G,                                                 NUM_LEDS_U);

#define BRIGHTNESS          35
#define FRAMES_PER_SECOND  120



uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void setup() {
  delay(200); // 3 second delay for recovery

  // tell FastLED there's 60 NEOPIXEL leds on pin 3, starting at index 0 in the led array
  FastLED.addLeds<NEOPIXEL, D3>(leds, 0, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setTemperature( Tungsten100W  ); // first temperature
  
}

void loop()
{
  fill_rainbow( leds, NUM_LEDS, gHue, 4);
  leds_S2=CRGB::Red;
  leds_G=CRGB::Blue;
  // leds_U=CRGB::Blue;
  // fill_rainbow( leds_G, NUM_LEDS_N, gHue, 4);
  // send the 'leds' array out to the actual LED strip
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND);

  // do some periodic updates
  EVERY_N_MILLISECONDS( 1 ) { gHue = gHue+1; } // slowly cycle the "base color" through the rainbow
}