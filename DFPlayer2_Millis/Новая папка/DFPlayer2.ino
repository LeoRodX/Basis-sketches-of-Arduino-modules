/* BlinkMillis 
Светодиодный маячек без остановки выполнения кода
by LeoRodX, 2024
*/

#include <SoftwareSerial.h>
#include <DFPlayer_Mini_Mp3.h>

const int ledPin =  13;    // укажем номер пина встроенного светодиода
int ledState = LOW;    // состояние порта светодиода
long previousMillis = 0;    // значение последнего включения светодиода
long interval = 4000;    // интервал включение светодиода
int score = 0;    // счет включений светодиода  
 
void setup() {  
  pinMode(ledPin, OUTPUT);    // укажем режим работы порта светодиода 
  Serial.begin(9600);
  mp3_set_serial (Serial);    //set Serial for DFPlayer-mini mp3 module   
  delay (100);
  mp3_stop ();
  delay (100);
  mp3_set_volume (20);
  delay (100); 
}
 
void loop()
{
  unsigned long currentMillis = millis();    // сохраним текущее значение времени
  if(currentMillis - previousMillis > interval) {    // если прошедшее время больше интервала
    previousMillis = currentMillis;    // обновим время осчета интервала    
    if (ledState == LOW){    // определим состояния светодиода   
      ledState = HIGH;
      score++;
      if (score == 1) {
        mp3_play (1);
      }
      if (score == 3) {
        mp3_play (2);
      }
      if (score == 5) {
        mp3_stop ();
        score = 0;
      } 
    }else{
      ledState = LOW;    
    }
    //Serial.println(score);
    digitalWrite(ledPin, ledState);    // применим изменение состояния светодиода
  }
}
