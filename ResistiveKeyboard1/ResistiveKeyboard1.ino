/*
Резистивная клавиатура by LeoRodX (2024)
Четыре кнопки, антидребезг, нажатие(только по одной кнопке), импульсы перебора при удержании.
Respect AlexGyver
*/

/* Ниже надо внести коды уровня кнопок. Коды уровня зависят от вашей схемы и сопротивления резисторов, в разных схемах они всегда
будут разные. Для определения кодов уровня кнопок необходимо раскомментировать строку "Получение кода уровня напряжения кнопок",
включить Монитор порта, нажимать на кнопки и записывать значения, после чего указать эти значения в константах button_x, после чего 
строку опять закомментировать. */
const int button_1 = 220;
const int button_2 = 427;
const int button_3 = 672;
const int button_4 = 1023;
int btn_value;
int gap_value;

void setup() {
  Serial.begin(9600);
  gap_value = button_1 / 10;  
}
bool flag = false;
uint32_t btnTimer = 0;
void loop() {
//Serial.println(analogRead(0));   // Получение кода уровня напряжения кнопок
btn_value = analogRead(0);
  if (btn_value > gap_value && !flag && millis() - btnTimer > 50) {
    flag = true;
    btnTimer = millis();
    if ( abs(button_1 - btn_value) < gap_value){
      //вызов функции 1
      Serial.println("Нажата белая кнопка");
    }
    if ( abs(button_2 - btn_value) < gap_value){
       //вызов функции 2
      Serial.println("Нажата синяя кнопка");
    }
    if ( abs(button_3 - btn_value) < gap_value){
       //вызов функции 3
      Serial.println("Нажата желтая кнопка");
    }
    if ( abs(button_4 - btn_value) < gap_value){
       //вызов функции 1
      Serial.println("Нажата красная кнопка");
    }
  }
  if (btn_value > gap_value && flag && millis() - btnTimer > 500) {
    btnTimer = millis();
    if ( abs(button_1 - btn_value) < gap_value){
      //вызов функции 1
      Serial.println("Удерживается белая кнопка");
    }
    if ( abs(button_2 - btn_value) < gap_value){
      //вызов функции 2
      Serial.println("Удерживается синяя кнопка");
    }
    if ( abs(button_3 - btn_value) < gap_value){
      //вызов функции 3
      Serial.println("Удерживается желтая кнопка");
    }
    if ( abs(button_4 - btn_value) < gap_value){
      //вызов функции 4
      Serial.println("Удерживается красная кнопка");
    }
  }
  if (btn_value < gap_value && flag && millis() - btnTimer > 500) {
    flag = false;
    btnTimer = millis();
  }  
}