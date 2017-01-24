#include "LedControl.h" //  need the library
#include <binary.h>
#include "SmoothSensor.cpp"
#include <FastLED.h>

// LED 8x8 Matrix
#define dinPin 52 // Din (digital)
#define clkPin 50 // clock (digital)
#define csPin 48 // CS (digital)

// Ping sensor
#define echoPin 12 // Echo Pin
#define trigPin 11 // Trigger Pin
#define LEDPin 13 // Onboard LED

// LED Matrix
int numberOfMatrices = 1;
LedControl lc = LedControl(dinPin, clkPin, csPin, numberOfMatrices); // 


// DOTSTAR
#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
#define NUMPIXELS 144 // Number of LEDs in strip
#define red 0xFF00 // red
#define blue 0xFF // blue
#define green 0xFF0000 // green
#define DATAPIN    4
#define CLOCKPIN   5 
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

//FASTLED
#define COLOR_ORDER GBR
CRGB leds[NUMPIXELS];      //naming our LED array

//BUTTON SETUP STUFF
byte prevKeyState = HIGH;        


int ledMode = 0;  //FIRST ACTIVE MODE

CRGBPalette16 currentPalette;
TBlendType    currentBlending;


// MODE VARIABLES -- Change these numbers to create new interesting modes

int BRIGHTNESS = 255;    //0-255.  Lower number saves battery life, higher number is screamingly bright
int SATURATION = 255;    //0 is white (no color) and 255 is fully saturated with color
int HUE = 0;             //0-255, around the color wheel
int STEPS = 4;           //Wider or narrower bands of color
int SPEEDO = 10;         //The speed of the animation

// SIN WAVE SETUP

#define qsubd(x, b)  ((x>b)?wavebright:0)                   // Digital unsigned subtraction macro. if result <0, then => 0. Otherwise, take on fixed value.
#define qsuba(x, b)  ((x>b)?x-b:0)                          // Analog Unsigned subtraction macro. if result <0, then => 0


// SINWAVE VARIABLES -- change these numbers to modify Sinwave mode
uint8_t wavebright = 255;                                     // You can change the brightness of the waves/bars rolling across the screen.
uint8_t thishue = 30;                                          // You can change the starting hue value for the first wave.
uint8_t thisrot = 1;                                          // You can change how quickly the hue rotates for this wave. 0= color stays the same
uint8_t allsat = 255;                                         // I like 'em fully saturated with colour.
bool thisdir = 0;                                             // You can change direction.
int8_t thisspeed = 4;                                         // You can change the speed, and use negative values.
uint8_t allfreq = 25;                                         // You can change the frequency, thus overall width of bars.
int thisphase = 0;                                            // Phase change value gets calculated.
uint8_t thiscutoff = 192;                                     // You can change the cutoff value to display this wave. Lower value = longer wave.
int loopdelay = 4;                                           // You can change the delay. Also you can change the allspeed variable above. 
uint8_t bgclr = 0;                                            // A rotating background colour.
uint8_t bgbright = 55;                                        // Background color brightness

//RIPPLE VARIABLES
uint8_t colour;                                               // Ripple colour is randomized.
int center = 0;                                               // Center of the current ripple.
int step = -1;                                                // -1 is the initializing step.
uint8_t myfade = 255;                                         // Starting brightness.
#define maxsteps 16 

// RAINBOW --------------------------------------------------
void Rainbow()
{ 
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = RainbowColors_p;
  
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; 

  FillLEDsFromPaletteColors( startIndex);
    
  FastLED.show();
  FastLED.delay(SPEEDO);  
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  
  for( int i = 0; i < NUMPIXELS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    colorIndex += STEPS;
  }
}

// Ping sensor
int maximumRange = 200; // Maximum range needed
int minimumRange = 40; // Minimum range needed
int previousDistance = -1;

void setup()
{
  // Ping sensor
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)

  //FastLed
  FastLED.addLeds<DOTSTAR, DATAPIN, CLOCKPIN, COLOR_ORDER>(leds, NUMPIXELS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  currentBlending = LINEARBLEND;
 
  // LED Matrix
  /*
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,1);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  */


  // LED STRIP
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
      clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
    #endif
    
    strip.begin(); // Initialize pins for output
    strip.show();  // Turn all LEDs off ASAP
    strip.clear();

  
}
