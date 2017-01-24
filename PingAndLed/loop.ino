SmoothSensor pingSensorSmooth;
boolean fastLed = false;
void loop()
{
    //int distance = getDistance();
    int sensor = getDistance();
    int distance = pingSensorSmooth.ReadAverage(sensor);
    //int brightness = 255-distance*1.25;
    int brightness = 255;
    uint32_t color;
    Serial.println(distance);

    if(distance < 40){
        color = green;
        fastLed = false;
    }
    else if(distance < 120){
        color = blue;
        fastLed = false;   
    }
    else if(distance >120 && distance < 170){
        color = red;
        fastLed = false;  
    }
    else if( distance > 170 ){
      fastLed = true;      
    }

    switch(fastLed){
      case false: updateLedStrip(brightness, color); break;
      case true:  Rainbow(); break;
      }
    
    delay(10);
    //setMatrixForDistance(distance);
}
