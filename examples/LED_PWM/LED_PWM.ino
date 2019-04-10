#include "MakerKit.h"

#define LED_pin 2
#define VR_pin A0

int val_VR;

MakerKit Umake;

void setup() {
    Serial.begin(115200);
}

void loop() {
    val_VR = Umake.getPotentiomenterLocation(VR_pin);
    Umake.setPWM(LED_pin, val_VR);
    delay(10);
}