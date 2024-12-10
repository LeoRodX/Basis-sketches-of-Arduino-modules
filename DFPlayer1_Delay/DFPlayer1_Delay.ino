/* 
Скетч в определенном порядке воспроизводит мелодии на DFPlayer mini
Сreated in 2024 by LeoRodX
*/

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>
void setup () {
  Serial.begin (9600);
  mp3_set_serial (Serial);    // Установим Serial for DFPlayer-mini mp3 module 
  delay (100);                // Обязательная задержка для корректного выполнения команд  
  mp3_set_volume (20);        // Установим уровень громкости
}
void loop () {        
  delay (100);
  mp3_play (16);  // Проигрываем "mp3/00016.mp3"
  delay (3000);   // Задержка равная длительности mp3
  mp3_play (1);   // Проигрываем "mp3/0001.mp3"
  delay (4000);
  mp3_play (14);
  delay (3000);
  mp3_play (8);
  delay (5000);
  mp3_play (15);
  delay (3000);
  mp3_play (13);
  delay (35000);
  //mp3_stop ();
}