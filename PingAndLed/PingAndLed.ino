// General libraries
#include "SmoothSensor.cpp"
#include "NonBlockDelay.cpp"

// LED Matrix libraries
#include "LedControl.h" //  need the library
#include <binary.h>

// Dotstar LED strip libraries
#include <FastLED.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>

// Ping sensor library
#include <NewPing.h>

void setup()
{
  // Serial setup
  serialSetup();
  
  // Ping sensor setup
  pingSensorSetup();
  
  // LED Matrix setup
  // ledMatrixSetup();
  
  // Dotstar LED Strip setup
  ledStripSetup();    
}


