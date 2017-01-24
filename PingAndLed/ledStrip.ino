void updateLedStrip(int brightness, uint32_t color){
    strip.setBrightness(brightness);

    for(int i = 0; i < NUMPIXELS; i++){
        strip.setPixelColor(i, color);
        delay(20);
    }
        
    strip.show();
}
