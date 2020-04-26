// accelerometer
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// Arduino / ADXL345
// A4  SDA (green)
// A5  SCL (yellow)

// display
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 9
#define DIO 8
TM1637Display display(CLK, DIO);

#define LED_PIN     13
#define BUZZER_PIN  10
#define G_THRESHOLD 9.5


void beep(unsigned char repeats = 5) {
    for (unsigned char i=0; i<repeats; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(7);
      digitalWrite(BUZZER_PIN, LOW);
      delay(3);
    }
}

void setup() {
  //start serial connection
  Serial.begin(9600);
  Serial.println("Hi");

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // start-up
  digitalWrite(LED_PIN, HIGH);
  display.setBrightness(0x0f);
  display.showNumberDec(8888);

  beep(15); // N repeats * 10ms

  digitalWrite(LED_PIN, LOW);
  display.clear();
  display.setBrightness(2);

  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }

  /* Set the range to whatever is appropriate for your project */
  //accel.setRange(ADXL345_RANGE_16_G);
  // accel.setRange(ADXL345_RANGE_8_G);
  // accel.setRange(ADXL345_RANGE_4_G);
  accel.setRange(ADXL345_RANGE_2_G);

  Serial.println("ADXL345 detected");
}

// cube side that is in fixed state
// we wait for N loops for this value to become stable
char fixedSide = 0, lastCurrentAxis = 0, fixedFor = 0;
unsigned int onFixedSide = 0; // count seconds on this fixed side

void loop() {
  digitalWrite(LED_PIN, HIGH);

 /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);

  digitalWrite(LED_PIN, LOW); 
  
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");

  unsigned char currentAxis, currentSide;

  if (abs(event.acceleration.x) > G_THRESHOLD) {
    currentAxis = 'x';
    currentSide = event.acceleration.x > 0 ? 1 : 2;
  }
  else if (abs(event.acceleration.y) > G_THRESHOLD) {
    currentAxis = 'y';
    currentSide = event.acceleration.y > 0 ? 3 : 4;
  }
  else if (abs(event.acceleration.z) > G_THRESHOLD) {
    currentAxis = 'z';
    currentSide = event.acceleration.z > 0 ? 5 : 6;
  }

  // the delay check
  // if the currently measured site is different then the last measurement - reset the delay timer
  if (currentSide != lastCurrentAxis) {
    fixedFor = 8; // 8 loops * 250 ms ~ 2 seconds

    lastCurrentAxis = currentSide;
  }
  else {
    if (fixedFor > 0) fixedFor--;

    if (fixedFor == 0) {
      fixedSide = currentSide;

      display.setBrightness(7);
      display.showNumberDecEx(fixedSide, 0 /* dots */, false /* leading zero */, 1 /* length */, 0 /* pos */);
      Serial.println("===============");
      Serial.print("Side fixed to ");
      Serial.print(fixedSide);
      Serial.println("===============");
      beep(); delay(5); beep();

      delay(500);
      display.setBrightness(1);

      fixedFor = -1; // do not count down anymore
    }
  }
 
//  Serial.print("Current axis: "); Serial.print(char(currentAxis));  Serial.println();
//  Serial.print("Current site: "); Serial.print(currentSide);  Serial.println();

//  display.showNumberDecEx(fixedSide, 0 /* dots */, false /* leading zero */, 1 /* length */, 0 /* pos */);
  display.showNumberDecEx(currentSide, 0 /* dots */, false /* leading zero */, 1 /* length */, 3 /* pos */);

  delay(250);
}
