Distance distance;
LedStripBlink blink;
LedStripRainbow rainbow;
LedStripSolid solid;
LedMatrixDistance matrixDistance;
void loop()
{
  long d = distance.GetMedianDistance();
  Serial.println(d);
  
  setLedStrip(d);
  setLedMatrix(d);
}

void setLedStrip(long distance){
  if(distance == 0){
    rainbow.CheckRainbow();
  }
  else if(distance < 40){ //0-40
    solid.SetColor("red");
  }
  else if(distance < 120){ //40-120
    solid.SetColor("blue");
  }
  else if(distance < 170){ //120-170
    solid.SetColor("green");
  }
  else if(distance > 170 ){ //170+
    rainbow.CheckRainbow();
  }
}


void setLedMatrix(long distance){
  if(distance == 0){
    matrixDistance.CheckSnake();
  }
  else if(distance < 40){ //0-40
    matrixDistance.SetSuperClose();
  }
  else if(distance < 120){ //40-120
    matrixDistance.SetClose();
  }
  else if(distance < 170){ //120-170
    matrixDistance.SetFar();
  }
  else if(distance > 170 ){ //170+
    matrixDistance.CheckSnake();
  }
}
