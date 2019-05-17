#include "MakerKit.h"

#define Vib_pin 2 // Khai báo cảm biến rung được cắm vào cổng D2
#define LED_pin 3 // Khai báo LED được cắm vào cổng D3

MakerKit Umake;

void setup() {
    Serial.begin(115200);
}

void loop() {
    if(Umake.readVibration(2)){ // Nếu có tác động vào cảm biến rung
      for(int i=0; i<50; i++)
      {
        Umake.setLED(3,1); // Bật đèn LED
        delay(1000); // Chờ trong 1s
        Umake.setLED(3,0); // Tắt đèn LED
        delay(1000); // Chờ trong 1s
      }
    }
}
