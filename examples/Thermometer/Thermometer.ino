#include "MakerKit.h"

#define Servo_pin 2
#define DHT_pin 3

int angle;
int Temp;

MakerKit Umake;

void setup() {
    Serial.begin(115200);
}

void loop() {
    Temp = Umake.getTemperature(DHT_pin); // Lấy giá trị nhiệt độ
    angle = map(Temp,0,51,180,0); // Chuyển đổi từ nhiệt độ sang góc quay của Servo
    Umake.setServo(Servo_pin, angle); // Set góc quay cho servo
}