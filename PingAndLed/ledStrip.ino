// Dotstar LED strip constants & variables
#define DATAPIN    4  // GREEN WIRE
#define CLOCKPIN   5  // YELLOW WIRE
#define NUMPIXELS 144 // Number of LEDs in strip
#define COLOR_ORDER RGB
CRGB dotstarLeds[NUMPIXELS];      //naming our LED array

// Dotstar LED strip initial setup
void ledStripSetup(){
  // LED STRIP
  FastLED.addLeds<DOTSTAR, DATAPIN, CLOCKPIN, COLOR_ORDER>(dotstarLeds, NUMPIXELS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  255 );
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
  #endif
}

class LedStripRainbow{
  private:
    NonBlockDelay d;
    static const long t = 1000;
    CRGBPalette16 currentPalette;
    TBlendType currentBlending = LINEARBLEND;
    int brightness = 255;
    int steps = 10;
    uint8_t colorIndex;
    
    void DoRainbow(){
      currentPalette = RainbowColors_p;
      FastLED.setBrightness(  brightness );
      
      for( int i = 0; i < NUMPIXELS; i++) {
        dotstarLeds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += steps;
      }
      FastLED.show();
    };
  public:
    LedStripRainbow(){
      colorIndex = 0;
      this->DoRainbow();
      d.Delay(t);
    };
  
    void CheckRainbow(){
      if(d.Timeout()){
        this->DoRainbow();
        d.Delay(t);
      }
  };
};

class LedStripBlink{
    private:
        int colNum;
        CRGB color;
        NonBlockDelay d;
        static const long t = 1000;
    public:
        LedStripBlink(){
            colNum = 0;
            color = CRGB::Red;
            for( int i = 0; i < NUMPIXELS; i++) {
                dotstarLeds[i] = color;
            }
            FastLED.show();
            d.Delay(t);
        };
        void CheckBlink(){
            if(d.Timeout()){
                colNum++;
                if(colNum > 2) colNum = 0;
                if(colNum == 0){
                   color = CRGB::Red;
                }
                else if(colNum == 1){
                   color = CRGB::Green; 
                }
                else{
                    color = CRGB::Blue;
                }
                
                // Set all leds to color
                for( int i = 0; i < NUMPIXELS; i++) {
                    dotstarLeds[i] = color;
                }
                FastLED.show();
                d.Delay(t);
            }
        };
};

class LedStripSolid{
  private:
    CRGB color;
  public:
    LedStripSolid(){
      color = CRGB::Black;
    }
    void SetColor(String colorString){
      if(colorString == "red"){
        color = CRGB::Red;
      }
      else if(colorString == "green"){
        color = CRGB::Green;
      }
      else if(colorString == "blue"){
        color = CRGB::Blue;
      }
      else{
        color = CRGB::Black;
      }
      
      for( int i = 0; i < NUMPIXELS; i++) {
        dotstarLeds[i] = color;
      }
      FastLED.show();
    };
};

