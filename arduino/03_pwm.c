#define LED_PIN    13
#define BUTTON_PIN 10
#define MOTOR_PIN  11 // PWM

void setup() {
  //start serial connection
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  // the duty cycle: between 0 (always off) and 255 (always on).
  unsigned char fill = 0;

  while(1) {
    Serial.println(fill);

    // https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/
    // Mega / Pins 2 - 13, 44 - 46 / 490 Hz (pins 4 and 13: 980 Hz)
    analogWrite(MOTOR_PIN, fill);
    analogWrite(LED_PIN, fill);

    fill += 100;

    delay(40);
  }
  
}
