// accelerometer
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

// display
#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 9
#define DIO 8
TM1637Display display(CLK, DIO);

#define LED_PIN    13
#define G_THRESHOLD 7.0


void setup() {
  //start serial connection
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);

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

  digitalWrite(LED_PIN, HIGH);
  display.setBrightness(0x0f);
  display.showNumberDec(8888);
  delay(200);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);

 /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);

  digitalWrite(LED_PIN, LOW); 
  
  /* Display the results (acceleration is measured in m/s^2) */
  //Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  //Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  //Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");

  unsigned char currentAxis, currentSite;

  if (abs(event.acceleration.x) > G_THRESHOLD) {
    currentAxis = 'x';
    currentSite = event.acceleration.x > 0 ? '1' : '2';
  }
  else if (abs(event.acceleration.y) > G_THRESHOLD) {
    currentAxis = 'y';
    currentSite = event.acceleration.y > 0 ? '3' : '4';
  }
  else if (abs(event.acceleration.z) > G_THRESHOLD) {
    currentAxis = 'z';
    currentSite = event.acceleration.z > 0 ? '5' : '6';
  }

  Serial.print("Current axis: "); Serial.print(char(currentAxis));  Serial.println();
  Serial.print("Current site: "); Serial.print(char());  Serial.println();

  display.showNumberDec(currentSite - '0');
  
  delay(50);
}
