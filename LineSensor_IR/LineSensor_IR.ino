/*
Тест инфракрасного датчика препятсвия(черной линии).
Подключим OUT датчика к 8-му пину, загрузим скетч. После чего приближая к датчику белый или черный предмет наблюдаем 
расстояние срабатывания датчика по индикатору на датчике и по данным Serial порта.
By LeoRodX, 2024
*/
#define LEFT_SENSOR_PIN  8

void setup() {
  pinMode(LEFT_SENSOR_PIN,INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(LEFT_SENSOR_PIN));
}
