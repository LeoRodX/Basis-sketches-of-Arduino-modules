/*
TestTapeAddressRGB_Millis
Тест адресной светодиодной ленты WS2812b 5V без влияния на основной код.
Получим эффект "Бегущий огонь".
Схема: Din ленты - резистор 270 Ом - pin 8; GND и +5V для ленты берем с Arduino(Если включать по одному светодиоду ленты, то ленту можно питать напрямую от Arduino)
By LeoRodX, 2024
*/

#define LED_PIN 8 // пин управления лентой
#define LED_NUM 10 // количество адресуемых светодиодов
#include "FastLED.h"

long current_millis = 0;
long previous_millis = 0; 
int delay_glow = 500;  // время свечения светодиода
int stage = 1; 
int stage_cicle = 1;

CRGB leds[LED_NUM];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, LED_NUM);
  FastLED.setBrightness(50);
 }

void loop(){
  // поочередное вкючение первх трех светодиодов, цвета устанавливаем индивидуально  
  if(stage == 1){
    leds[0].setRGB(255, 0, 0); // установим цвет первого светодиода
     FastLED.show(); // применим установку, включим первый светодиод     
    stage = 2;
  }
  // отключим через 0, и включим второй
  current_millis = millis();    // сохраним текущее значение времени контроллера
  if(current_millis - previous_millis > delay_glow && stage == 2) { // если прошедшее время больше интервала
    previous_millis = current_millis;    // обновим время осчета интервала    
    leds[0].setRGB(0, 0, 0); // выключение первого светодиод
    leds[1].setRGB(255, 128, 0); // установиваем цвет первого светодиода
    FastLED.show();
    stage = 3;
  }
  // Стоп через 0,5 сек
  if(current_millis - previous_millis > delay_glow && stage == 3) { 
    previous_millis = current_millis;        
    leds[1].setRGB(0, 0, 0); 
    leds[2].setRGB(255, 255, 0); 
    FastLED.show();
    stage = 4;
    stage_cicle = 2;
  }
  // оставшие семь зажигаем одним цветом в цикле
  if(stage == 4) {
      if(stage_cicle < 9 && current_millis - previous_millis > delay_glow) {  
      stage_cicle = stage_cicle + 1;
      previous_millis = current_millis;     
      leds[stage_cicle - 1].setRGB(0, 0, 0); 
      leds[stage_cicle].setRGB(128, 0, 255); 
      FastLED.show();      
    }
    // возвращаемся к первым трем светодиодам
    if(stage_cicle == 9 && current_millis - previous_millis > delay_glow){
      previous_millis = current_millis;
      leds[stage_cicle].setRGB(0, 0, 0); 
      FastLED.show(); 
      stage_cicle = 2;
      stage = 1;
    }
  }
}