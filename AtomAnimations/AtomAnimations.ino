

#include "M5AtomS3.h"
#include "frames.h"
#include "frames2.h"
#include "frames3.h"
#include "nyan.h"

int n=0;
int ani=0;

int aniDelay[4]={80,50,75,70};
int aniFrames[4]={18,24,22,8};

void setup() {
    auto cfg = M5.config();
    AtomS3.begin(cfg);
    AtomS3.Display.setSwapBytes(1);
    AtomS3.Display.setBrightness(120);
}

void loop() {
  AtomS3.update();
    if (AtomS3.BtnA.wasPressed()) {
    ani++;
    if(ani>3) ani=0;
    n=0;
    }
  if(ani==0)
  AtomS3.Display.pushImage(0,0,128,128,frame[n]);  
  if(ani==1)
  AtomS3.Display.pushImage(0,0,128,128,carlton[n]);
  if(ani==2)
  AtomS3.Display.pushImage(0,0,128,128,rick[n]);
    if(ani==3)
  AtomS3.Display.pushImage(0,0,128,128,nyan[n]);
  
  n++;
  if(n==aniFrames[ani]) n=0;
  delay(aniDelay[ani]);
}