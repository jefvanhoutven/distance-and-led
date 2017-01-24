#include "LedControl.h" //  need the library
#include <binary.h>
#include "SmoothSensor.cpp"

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
#define NUMPIXELS 11 // Number of LEDs in strip
#define red 0xFF00 // red
#define blue 0xFF // blue
#define green 0xFF0000 // green
#define DATAPIN    4
#define CLOCKPIN   5
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);
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
