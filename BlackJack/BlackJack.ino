#include "M5AtomS3.h"
#include "frames.h"

int positions[4][5]={{2,64,0,0,0},
                     {2,42,82,0,0},
                     {2,32,62,92,0},
                     {2,22,42,62,82}};
int n=2;
int cards[5];
void draw()
{
  AtomS3.Display.fillScreen(BLACK);
  AtomS3.Display.drawString("New Game!",3,2,2);
  AtomS3.Display.drawString("HIT ME",42,110,2);
  for(int i=0;i<n;i++)
  AtomS3.Display.pushImage(positions[n-2][i],22,60,84,card[cards[i]]);
}

void setup() {
    auto cfg = M5.config();
    AtomS3.begin(cfg);
    AtomS3.Display.setSwapBytes(1);
    AtomS3.Display.fillScreen(BLACK);
    AtomS3.Display.setBrightness(120);
    for(int i=0;i<n;i++)
    cards[i]=random(0,52);
    draw();
}


void loop() {

    AtomS3.update();
    if (AtomS3.BtnA.wasPressed() && n<5) {
    n++;
    cards[n]=random(0,52);
    draw();
    }
}