//Download Library LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>
//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(3,0); lcd.print(" WELCOME: ");
 lcd.setCursor(0,1); lcd.print("LIANI ALIA ROSDI");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
 lcd.clear();
  lcd.setCursor(3,0); lcd.print(" WELCOME: ");
 lcd.setCursor(2,1); lcd.print("ALIFIA ANDINI");
 delay(1000);
}
