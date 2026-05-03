// Проверка реле-модуля 5V (IN, GND, VCC)
// Реле подключается: VCC -> 5V, GND -> GND, IN -> D4

const int RELAY_PIN = 4;

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  
  // Начальное состояние - реле выключено (можно LOW или HIGH, 
  // зависит от модуля: активный LOW или активный HIGH)
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH);  // Включаем реле
  delay(1000);                     // Ждём 1 секунду
  digitalWrite(RELAY_PIN, LOW);   // Выключаем реле
  delay(1000);                     // Ждём 1 секунду
}