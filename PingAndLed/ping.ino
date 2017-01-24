int getDistance(){
    long duration, distance; // Duration used to calculate distance
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2); 
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    
    //Calculate the distance (in cm) based on the speed of sound.
    distance = duration/58.2;
    
    if (distance >= maximumRange){
        distance = 201;
    }
    if(distance <= minimumRange){
        distance = 0;
    }
    return distance;
}


