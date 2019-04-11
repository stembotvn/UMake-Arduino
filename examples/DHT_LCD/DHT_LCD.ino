#include "MakerKit.h"
#include "LiquidCrystal_I2C.h"

#define DHT_pin 2

float Temp, Hum;

MakerKit Umake;
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Khởi tạo đối tượng LCD 16x2 I2C ở địa chỉ 0x3F

void setup() {
    Serial.begin(115200);
    lcd.begin(); 
    lcd.backlight(); // Bật đèn nền LCD
}

void loop() {
    Temp = Umake.getTemperature(DHT_pin); // Lấy giá trị nhiệt độ 
    Hum = Umake.getHumidity(DHT_pin); // Lấy giá trị độ ẩm
    lcd.setCursor(0,0); // Xét vị trí con trỏ ở LCD (hàng 0, vị trí thứ 0)
    lcd.print(String("Temperature: ") + Temp); // In ra giá trị của Nhiệt độ
    lcd.setCursor(0,1); // Xét vị trí con trỏ ở LCD (hàng 1, vị trí thứ 0)
    lcd.print(String("Humidity: ") + Hum); // In ra giá trị của độ ẩm
    delay(1000); // Chờ 1 khoảng thời gian cho lần đọc tiếp theo
}