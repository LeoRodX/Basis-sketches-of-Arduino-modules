/*
TestTapeAddressRGB
Тест адресной светодиодной ленты WS2812b 5V. Отрезок в 4-е светодиода можно питать напрямую от Arduino.
Получим эффект "Бегущий огонь".
Схема: Din ленты - резистор 270 Ом - pin 8; GND и +5V для ленты берем с Arduino.
By LeoRodX, 2024
*/

#define LED_PIN 8 // пин управления лентой
#define LED_NUM 4 // количество адресуемых светодиодов
#include "FastLED.h"
CRGB leds[LED_NUM];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(50);
 }
void loop(){
     // поочередное вкючение светодиодов, цвета устанавливаем индивидуально  
     leds[0].setRGB(255, 0, 0); // установим цвет первого светодиода
     FastLED.show(); // применим установку, включим первый светодиод 
     delay(100); // длительность свечения светодиода
     leds[0].setRGB(0, 0, 0); // установим яркость 0 светодиода
     FastLED.show();

     leds[1].setRGB(255, 255, 0);
     FastLED.show();
     delay(100);     
     leds[1].setRGB(0, 0, 0);
     FastLED.show();     

     leds[2].setRGB(0, 255, 0);
     FastLED.show();
     delay(100);     
     leds[2].setRGB(0, 0, 0);
     FastLED.show();

     leds[3].setRGB(0, 255, 255);
     FastLED.show();
     delay(100);
     leds[3].setRGB(0, 0, 0);
     FastLED.show();
}