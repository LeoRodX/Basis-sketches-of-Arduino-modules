#include <TM1637Display.h>

#define CLK 7   // D7
#define DIO 8   // D8

TM1637Display display(CLK, DIO);

// Таблица сегментов для цифр 0-9
const uint8_t digits[] = {
  0b00111111,  // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  0b00000111,  // 7
  0b01111111,  // 8
  0b01101111   // 9
};

// Таблица сегментов для букв
const uint8_t letter_d = 0b01011110;  // "d"
const uint8_t letter_o = 0b00111111;  // "O" (как 0, но выглядит как O)
const uint8_t letter_n = 0b01010100;  // "n"
const uint8_t letter_E = 0b01111001;  // "E"

void setup() {
  display.setBrightness(7);  // яркость 0-7
  display.clear();
  delay(500);
}

void loop() {
  // ========== ТЕСТ 1: Мигание дисплея ==========
  // Показываем все сегменты включенными
  uint8_t all_on[] = {0b11111111, 0b11111111, 0b11111111, 0b11111111};
  for(int i = 0; i < 2; i++) {
    display.setSegments(all_on);
    delay(400);
    display.clear();
    delay(400);
  }
  delay(500);
  
  // ========== ТЕСТ 2: Тест каждой точки (десятичной) ==========
  // Зажигаем цифру 8 с десятичной точкой в каждой позиции по очереди
  for(int pos = 0; pos < 4; pos++) {
    for(int blink = 0; blink < 2; blink++) {
      uint8_t test_digits[4] = {0, 0, 0, 0};
      for(int i = 0; i < 4; i++) {
        test_digits[i] = digits[8];  // цифра 8
      }
      test_digits[pos] |= 0b10000000;  // включаем точку (старший бит)
      display.setSegments(test_digits);
      delay(300);
      
      test_digits[pos] &= 0b01111111;  // выключаем точку
      display.setSegments(test_digits);
      delay(300);
    }
    display.clear();
    delay(200);
  }
  
  // ========== ТЕСТ 3: Слово "dOnE" ==========
  // Показываем работу с разными сегментами
  uint8_t word_done[] = {letter_d, letter_o, letter_n, letter_E};
  display.setSegments(word_done);
  delay(2000);
  
  // ========== ТЕСТ 4: Цифры 1-9 на всех разрядах ==========
  for(uint8_t digit = 1; digit <= 9; digit++) {
    uint8_t show_digits[] = {digits[digit], digits[digit], digits[digit], digits[digit]};
    display.setSegments(show_digits);
    delay(800);
  }
  
  display.clear();
  delay(1000);
}

// ========== Дополнительная функция для ручного теста ==========
// Вызовите эту функцию из loop() если нужно проверить конкретный сегмент
void testAllSegments() {
  // Тест каждого сегмента отдельно
  uint8_t segments[] = {0b00000001,  // A
                        0b00000010,  // B
                        0b00000100,  // C
                        0b00001000,  // D
                        0b00010000,  // E
                        0b00100000,  // F
                        0b01000000,  // G
                        0b10000000}; // DP (точка)
                        
  for(int s = 0; s < 8; s++) {
    uint8_t seg_display[] = {segments[s], segments[s], segments[s], segments[s]};
    display.setSegments(seg_display);
    delay(500);
  }
  display.clear();
}