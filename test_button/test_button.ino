// Скетч модуля с кнопкой с визуальной индикацией (встроенный LED на пине D13)
// Модуль кнопки -> Arduino Nano
// S (сигнал)   -> D2 (можно любой цифровой пин)
// средний пин  -> 5V (питание)
// - (GND)      -> GND

// Компактный тест кнопки с LED индикацией

const int BUTTON_PIN = 2;   // Пин для кнопки (S)
const int LED_PIN = 13;     // Встроенный LED

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Кнопка нажата (LOW) - LED горит, иначе - не горит
  digitalWrite(LED_PIN, digitalRead(BUTTON_PIN) == LOW ? HIGH : LOW);
  delay(20);  // Небольшая задержка для стабильности
}