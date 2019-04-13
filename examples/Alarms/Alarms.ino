#include "MakerKit.h"
#include "LiquidCrystal_I2C.h"

#define Relay_pin 2
#define Vib_pin 3
#define Button_pin 4

MakerKit Umake;
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Khởi tạo đối tượng LCD 16x2 I2C ở địa chỉ 0x3F

void setup() {
    Serial.begin(115200);
    lcd.begin(); 
    lcd.backlight(); // Bật đèn nền LCD
}
void loop() {
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("Umake");
    lcd.setCursor(4,1);
    lcd.print("NEGENDO");
    Umake.relay(Relay_pin, 0); // Tắt chuông báo
    while(!(Umake.readVibration(Vib_pin))){} // Chờ cho đến khi cảm biến rung bị tác động
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Bao dong");
    while(!(Umake.buttonPressed(Button_pin))) // Lặp lại cho đến khi  nút nhấn được nhấn
    {
        Umake.relay(Relay_pin,1); // Bật tắt chuông báo liên tục với tần số 1Hz
        delay(500);
        Umake.relay(Relay_pin,0);
        delay(500);
    }
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Tat chuc nang");
    lcd.setCursor(3,1);
    lcd.print("Bao dong");
    delay(3000);
}