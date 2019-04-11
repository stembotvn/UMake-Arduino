#include "MakerKit.h"

#define Light_pin A0
#define LED_pin 2

int light;
int ON = 10;
int OFF = 30;

MakerKit Umake;

void setup() {
    Serial.begin(115200);
}

void loop() {
    light = Umake.getLight(Light_pin); // Lấy giá trị cường độ ánh sáng (tính theo %)
    if(light < ON){ // Nếu cường độ ánh sáng đọc vào nhỏ hơn ngưỡng bật đèn
        Umake.setLED(LED_pin, 1); // Bật đèn
    }
    if(light > OFF){ // Nếu cường độ ánh sáng đọc vào lớn hơn ngưỡng tắt đèn
        Umake.setLED(LED_pin, 0); // Tắt đèn
    }
}