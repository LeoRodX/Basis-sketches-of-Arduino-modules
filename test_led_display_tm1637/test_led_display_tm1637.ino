#define SENSOR_PIN 12
#define LED_PIN 13

void setup() {
  pinMode(SENSOR_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int pulseCount = 0;
  int lastState = HIGH;
  unsigned long startTime = millis();
  
  // Считаем импульсы 3 секунды
  while (millis() - startTime < 3000) {
    int currentState = digitalRead(SENSOR_PIN);
    
    // Ловим фронт (HIGH -> LOW, т.к. с подтяжкой)
    if (lastState == HIGH && currentState == LOW) {
      pulseCount++;
    }
    lastState = currentState;
  }
  
  // Мигаем LED столько раз, сколько насчитали
  for (int i = 0; i < pulseCount; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
    delay(100);
  }
  
  delay(500); // Пауза перед следующим циклом
}