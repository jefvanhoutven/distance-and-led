// LED Matrix constants & variables
#define dinPin 52 // Din (digital)
#define clkPin 50 // clock (digital)
#define csPin 48 // CS (digital)
int numberOfMatrices = 1;
LedControl lc = LedControl(dinPin, clkPin, csPin, numberOfMatrices);

// LED Matrix initial setup
void ledMatrixSetup(){
  // LED Matrix
  lc.shutdown(0,false);// turn off power saving, enables display
  lc.setIntensity(0,1);// sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
};

class LedMatrixDistance{
    private:
        bool blinkState = 0;
        NonBlockDelay d;
        static const long t = 1000;
        

        int snake = 0;
        int snakeLength = 4;
        NonBlockDelay d2;
        static const long t2 = 250;
        void SetSnakeLed(int led){
          lc.shutdown(0, false);
          lc.setIntensity(0, 3);          
          
          
          int row = led / 8;
          int col = led % 8;
          if(row % 2 == 0){
            col = 7 - col;
          }
          lc.setLed(0, row, col, 1);
        };
    public:
        void SetSuperClose(){
          lc.shutdown(0, false);
          lc.setIntensity(0, 15);
          
          lc.setRow(0,7, B11111111);
          lc.setRow(0,6, B11111111);
          lc.setRow(0,5, B11111111);
          lc.setRow(0,4, B11111111);
          lc.setRow(0,3, B11111111);
          lc.setRow(0,2, B11111111);
          lc.setRow(0,1, B11111111);
          lc.setRow(0,0, B11111111);
        };
        void SetClose(){
          lc.shutdown(0, false);
          lc.setIntensity(0, 11);
          
          lc.setRow(0,7, B00000000);
          lc.setRow(0,6, B00000000);
          lc.setRow(0,5, B01111110);
          lc.setRow(0,4, B01111110);
          lc.setRow(0,3, B01111110);
          lc.setRow(0,2, B01111110);
          lc.setRow(0,1, B01111110);
          lc.setRow(0,0, B01111110);
        };
        
        void SetFar(){
          lc.shutdown(0, false);
          lc.setIntensity(0, 7);
          
          lc.setRow(0,7, B00000000);
          lc.setRow(0,6, B00000000);
          lc.setRow(0,5, B00000000);
          lc.setRow(0,4, B00000000);
          lc.setRow(0,3, B00111100);
          lc.setRow(0,2, B00111100);
          lc.setRow(0,1, B00111100);
          lc.setRow(0,0, B00111100);
        };
        
        void CheckOutOfBounds(){
          if(d.Timeout()){
            blinkState = !blinkState;
            d.Delay(t);
          }
          lc.shutdown(0, false);
          lc.setIntensity(0, 3);          
  
          lc.setRow(0,7, B00000000);
          lc.setRow(0,6, B00000000);
          lc.setRow(0,5, B00000000);
          lc.setRow(0,4, B00000000);
          lc.setRow(0,3, B00000000);
          lc.setRow(0,2, B00000000);

          // Blink the lowest 2 rows
          if(blinkState){
            lc.setRow(0,1, B00001000);
            lc.setRow(0,0, B00010000);
          } else{
            lc.setRow(0,1, B00010000);
            lc.setRow(0,0, B00001000);
          }
        };

        void CheckSnake(){
          if(d2.Timeout()){
            snake++;
            if(snake > 64){
              snake = 0;
            }
            d2.Delay(t2);
          }

          lc.clearDisplay(0);
          for(int i = 0; i < snakeLength; i++){
            int led = snake-i;
            if(led < 0){
              led = led + 64;
            }
            SetSnakeLed(led);
          }
        };
};
