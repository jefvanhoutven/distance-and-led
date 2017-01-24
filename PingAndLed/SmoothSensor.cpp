class SmoothSensor{
    private:
        static const int numValues = 1;
        int values[numValues];      // the readings from the analog input
        int index = 0;              // the index of the current reading
        int outOfRange = 0;
        int bigDifference = 0;
        
    public:
        SmoothSensor(){
            // initialize array to 0
            for (int i=0; i<=numValues; i++) {
                values[i] = 0;
            }
        };
        
        int ReadAverage(int sensorValue){
            
            int difference = LastAverage() - sensorValue;
            if(difference > 100 || difference < -100){
                bigDifference++;
                if(bigDifference <= 2)
                    return LastAverage();
            }
            else{
                bigDifference = 0;
            }

            
            if(sensorValue < -1){
                outOfRange++;
            }else{
                outOfRange = 0;
            }
            
            if(outOfRange == 0 || outOfRange > 2){
                values[index] = sensorValue;
                index = index + 1;
                if(index >= numValues){
                    index = 0;
                }
            }

            return LastAverage();
        };

        int LastAverage(){
            int total = 0;
            for(int i=0; i<numValues; i++){
                total = total + values[i];
            }
            return total/numValues;
        };
};
