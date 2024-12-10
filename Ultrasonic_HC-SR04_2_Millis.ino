/*
Скетч без блокировки основного кода измеряет расстояние до препятствия с помощью датчика hc-sr04 и выводит результат в Serial.
Created 2024 by LeoRodX
*/

#include <NewPing.h>

//Схема:
#define PIN_TRIG 12
#define PIN_ECHO 11

#define MAX_DISTANCE 200 // Константа для определения максимального расстояния, которое мы будем считать корректным.

long currentMillis;
long previousMillis = 0;    // значение последнего измерения
long interval = 50;    // интервал измерений
int distance;

// Создаем объект, методами которого будем затем пользоваться для получения расстояния.
// В качестве параметров передаем номера пинов, к которым подключены выходы ECHO и TRIG датчика
NewPing sonar(PIN_TRIG, PIN_ECHO, MAX_DISTANCE);

void setup() {
  // Инициализируем взаимодействие по последовательному порту на скорости 9600
  Serial.begin(9600);
}

void loop() {  
  currentMillis = millis();    // сохраним текущее значение времени
  if(currentMillis - previousMillis > interval) {    // если прошедшее время больше интервала
    previousMillis = currentMillis;    // обновим время осчета интервала      
    distance = sonar.ping_cm();    // Получаем значение от датчика расстояния и сохраняем его в переменную
    
    Serial.print(distance);    // Печатаем расстояние в мониторе порта
    Serial.println("см");

  }



  

  

}