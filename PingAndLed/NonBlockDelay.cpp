#if defined(ARDUINO) && ARDUINO >= 100  
  #include <Arduino.h>  
#else  
  #include <WProgram.h>  
#endif  
class NonBlockDelay {  
    unsigned long iTimeout;  
  public:  
    void Delay (unsigned long t)  
    {
        iTimeout = millis() + t;  
        return;  
    };
    bool Timeout (void)  
    {
        return (iTimeout < millis());  
    };
    unsigned long Time(void)  
    {
        return iTimeout;  
    };
};
