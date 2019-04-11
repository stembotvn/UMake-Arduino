#include "MakerKit.h"

#define Light_pin A0

int light;

MakerKit Umake;

void setup() {
    Serial.begin(115200);
}

void loop() {
    light = Umake.getLight(Light_pin); // Lấy giá trị cường độ ánh sáng (tính theo %)
    Serial.println(String("Light level: ") + light); // In ra trên cổng Serial giá trị vừa đọc được
    delay(1000); // Chờ một khoảng thời gian cho lần đọc tiếp theo
}