/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define TOTAL_MOLES 4
struct Mole
{
	int led_pin;
  	int button_pin;
};

struct Mole mole_array[TOTAL_MOLES] = {
  {.led_pin = A0, .button_pin = 6},
  {.led_pin = A1, .button_pin = 7},
  {.led_pin = A2, .button_pin = 8},
  {.led_pin = A3, .button_pin=9}
};

int total_score;
void setup() {
  randomSeed(analogRead(A5));
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  total_score = 0;
}

void use_mole(struct Mole* mole)
{
  lcd.clear();
  lcd.print("Score: " + String(total_score));
  
  digitalWrite(mole->led_pin, HIGH);
  delay(2000);
  digitalWrite(mole->led_pin, LOW);
  lcd.clear();
  if(digitalRead(mole->button_pin) == LOW)
  {
    lcd.print("You hit the mole!");
    total_score += 1;
  }
  else
  {
    lcd.print("You failed!");
    total_score -= 1;
  }
  
  delay(1500);
}

void loop() {
 int r = random(TOTAL_MOLES);
 struct Mole* mole = &mole_array[r];
 use_mole(mole);
}
 