/*
Кнопка
Антидребезг, нажатие, импульсы перебора при удержании.
by LeoRodX 2024
*/

void setup() {
  Serial.begin(9600);
  pinMode(10, INPUT_PULLUP);  
}
bool flag = false;
uint32_t btnTimer = 0;
void loop() {
  bool btnState = !digitalRead(10);
  if (btnState && !flag && millis() - btnTimer > 100) {    // > 100, устранение дребезга 
    flag = true;
    btnTimer = millis();
    Serial.println("Нажатие");
  }
  if (btnState && flag && millis() - btnTimer > 500) {    // > 500, при удержании кнопки код генерирует импульсы, например, для "перебора режимов"
    btnTimer = millis();
    Serial.println("Удержание");
  }
   if (!btnState && flag && millis() - btnTimer > 500) {    // если кнопка не нажата
    flag = false;
    btnTimer = millis();
  }  
}