#include "MakerKit.h"

#define LED_pin 2

MakerKit Umake;

void setup() {
  Serial.begin(115200);
}

void loop() {
  //Umake.setLED(int pin, int status);
  // pin: use digital pins (D2 - D9)
  // status = 1 => LED ON
  // status = 2 => LED OFF
  Umake.setLED(LED_pin,1);
  delay(1000);
  Umake.setLED(LED_pin,0);
  delay(1000);
}