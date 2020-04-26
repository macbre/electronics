#define LED_PIN    13
#define TEMP_PIN   17 // A3

#define Vcc 1023.0 // analog read out at VCC
#define R   10000.0 // Ohm

#define R_threshold 5000 // Ohm

// 4-digit display (I2C)
// https://www.makerguides.com/tm1637-arduino-tutorial/
#include <TM1637Display.h>

// Create display object of type TM1637Display:
#define CLK 9
#define DIO 8
TM1637Display display = TM1637Display(CLK, DIO);

void setup() {
  //start serial connection
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

   // Set the brightness:
  display.setBrightness(2);
}

float readTemperature() {

  float vin = (float) analogRead(TEMP_PIN);
  float rt = (vin * R) / (Vcc - vin);

  // 4700 - 25C
  return rt;
}

void loop() {
  // 0     0V
  // 1023  5V
  // 862   4.19V
  int readOut = readTemperature();
  
  Serial.println(readOut);

  // 4-digit display (I2C)
  // https://www.makerguides.com/tm1637-arduino-tutorial/
  display.showNumberDec(readOut);

  if (readOut > R_threshold) {
    // temp below threshold
    display.setBrightness(2);
    digitalWrite(LED_PIN, HIGH);
  }
  else {
    display.setBrightness(7);
    digitalWrite(LED_PIN, LOW);
  }

  delay(500);
}
