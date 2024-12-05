/* BlinkMillis 
Светодиодный маячек без остановки выполнения кода
by LeoRodX, 2024
*/
 
const int ledPin =  13;    // укажем номер пина встроенного светодиода
int ledState = LOW;    // состояние порта светодиода
long previousMillis = 0;    // значение последнего включения светодиода
long interval = 500;    // интервал включение светодиода
 
void setup() {
  pinMode(ledPin, OUTPUT);    // укажем режим работы порта светодиода     
}
 
void loop()
{
  unsigned long currentMillis = millis();    // сохраним текущее значение времени
  if(currentMillis - previousMillis > interval) {    // если прошедшее время больше интервала
    previousMillis = currentMillis;    // обновим время осчета интервала    
    if (ledState == LOW)    // определим состояния светодиода   
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(ledPin, ledState);    // применим изменение состояния светодиода
  }
}
