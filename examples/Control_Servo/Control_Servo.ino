#include "MakerKit.h"

#define Servo_pin 2
#define VR_pin A0

int val_VR;
int angle;

MakerKit Umake;

void setup() {
    Serial.begin(115200);
}

void loop() {
    val_VR = Umake.getPotentiomenterLocation(VR_pin);
    angle = map(val_VR, 0, 100, 0, 180);
    Umake.setServo(Servo_pin, angle);
    delay(10);
}