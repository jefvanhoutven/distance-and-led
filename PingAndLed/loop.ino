SmoothSensor pingSensorSmooth;

void loop()
{
    //int distance = getDistance();
    int sensor = getDistance();
    int distance = pingSensorSmooth.ReadAverage(sensor);
    
    //Serial.print(sensor);
    //Serial.print(",");
    Serial.println(distance);

    uint32_t color;
    if(distance < 60){
        color = green;
    }
    else if(distance < 120){
        color = blue;
    }
    else{
        color = red;
    }

    int brightness = 255;
    //int brightness = 255-distance*1.25;
    updateLedStrip(brightness, color);
    
    //setMatrixForDistance(distance);
    delay(10);
}
