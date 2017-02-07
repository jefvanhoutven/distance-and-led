// Ping sensor constants & variables
#define trigPin 11 // Trigger Pin
#define echoPin 12 // Echo Pin
NewPing sonar(trigPin, echoPin, 200);

// Ping sensor initial setup
void pingSensorSetup(){
    // Ping sensor
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
};

class Distance{
    private:
        NonBlockDelay d;
        static const long t = 200;
        
        int maximumRange = 200; // Maximum range needed
        int minimumRange = 2; // Minimum range needed
        long distance;
    public:
      Distance(){
        d.Delay(t);
      };
      long GetMedianDistance(){
        long ms = sonar.ping_median(8);
        return sonar.convert_cm(ms);
      };

      long CheckDistance(){
        if(d.Timeout()){
          this->GetMedianDistance();
          d.Delay(t);
        }
      return distance;
    };
};
