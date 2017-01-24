void setMatrixForDistance(int distance) //distance in cm
{
    if(distance > 140 || distance < 0){
        // too far
        lc.setIntensity(0, 0);
        lc.shutdown(0, true);
    }
    else if(distance <= 20 ){
        // super close
        lc.shutdown(0, false);
        lc.setIntensity(0, 15);
        
        lc.setRow(0,7, B10000001);
        lc.setRow(0,6, B01000010);
        lc.setRow(0,5, B00100100);
        lc.setRow(0,4, B00011000);
        lc.setRow(0,3, B00011000);
        lc.setRow(0,2, B00100100);
        lc.setRow(0,1, B01000010);
        lc.setRow(0,0, B10000001);
    }
    else if(distance <= 140 && distance > 125) {
        lc.shutdown(0, false);
        lc.setIntensity(0, 3);
        lc.setRow(0,7, B00000000);
        lc.setRow(0,6, B00000000);
        lc.setRow(0,5, B00000000);
        lc.setRow(0,4, B00000000);
        lc.setRow(0,3, B00000000);
        lc.setRow(0,2, B00000000);
        lc.setRow(0,1, B00000000);
        lc.setRow(0,0, B00011000);
    }
    else if(distance <= 125 && distance > 110) {
        lc.shutdown(0, false);
        lc.setIntensity(0, 5);
        lc.setRow(0,7, B00000000);
        lc.setRow(0,6, B00000000);
        lc.setRow(0,5, B00000000);
        lc.setRow(0,4, B00000000);
        lc.setRow(0,3, B00000000);
        lc.setRow(0,2, B00000000);
        lc.setRow(0,1, B00011000);
        lc.setRow(0,0, B00011000);
    }
    else if(distance <= 110 && distance > 95) {
        lc.shutdown(0, false);
        lc.setIntensity(0, 7);
        lc.setRow(0,7, B00000000);
        lc.setRow(0,6, B00000000);
        lc.setRow(0,5, B00000000);
        lc.setRow(0,4, B00000000);
        lc.setRow(0,3, B00000000);
        lc.setRow(0,2, B00111100);
        lc.setRow(0,1, B00111100);
        lc.setRow(0,0, B00111100);
    }
    else if(distance <= 95 && distance > 80) {
        lc.shutdown(0, false);
        lc.setIntensity(0, 9);
        lc.setRow(0,7, B00000000);
        lc.setRow(0,6, B00000000);
        lc.setRow(0,5, B00000000);
        lc.setRow(0,4, B00000000);
        lc.setRow(0,3, B00111100);
        lc.setRow(0,2, B00111100);
        lc.setRow(0,1, B00111100);
        lc.setRow(0,0, B00111100);
    }
    else if(distance <= 80 && distance > 65) {
        lc.shutdown(0, false);
        lc.setIntensity(0, 11);
        lc.setRow(0,7, B00000000);
        lc.setRow(0,6, B00000000);
        lc.setRow(0,5, B00000000);
        lc.setRow(0,4, B01111110);
        lc.setRow(0,3, B01111110);
        lc.setRow(0,2, B01111110);
        lc.setRow(0,1, B01111110);
        lc.setRow(0,0, B01111110);
    }
    else if(distance <= 65 && distance > 50) {
        lc.shutdown(0, false);
        lc.setIntensity(0, 13);
        lc.setRow(0,7, B00000000);
        lc.setRow(0,6, B00000000);
        lc.setRow(0,5, B01111110);
        lc.setRow(0,4, B01111110);
        lc.setRow(0,3, B01111110);
        lc.setRow(0,2, B01111110);
        lc.setRow(0,1, B01111110);
        lc.setRow(0,0, B01111110);
    }
    else if(distance <= 65 && distance > 50) {
        lc.shutdown(0, false);
        lc.setIntensity(0, 13);
        lc.setRow(0,7, B00000000);
        lc.setRow(0,6, B11111111);
        lc.setRow(0,5, B11111111);
        lc.setRow(0,4, B11111111);
        lc.setRow(0,3, B11111111);
        lc.setRow(0,2, B11111111);
        lc.setRow(0,1, B11111111);
        lc.setRow(0,0, B11111111);
    }
    else if(distance <= 50 && distance > 35) {
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
    }
}
