#include "MakerKit.h"

#define LED_pin 2
#define Button_pin 3

MakerKit Umake;

void setup() {
    Serial.begin(115200);
    Umake.setLED(LED_pin, 0);
}

void loop() {
    while(!(Umake.buttonPressed(Button_pin))){}
    Umake.setLED(LED_pin, 1);
    delay(1000);
    while(!(Umake.buttonPressed(Button_pin))){}
    Umake.setLED(LED_pin, 0);
    delay(1000);
}