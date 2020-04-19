/**
 * ATTiny85 demo
 */
// https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/i/0995f7a6-730b-48d0-8612-c4408d15e84d/dc7h4n3-51e6389c-5f86-4fb2-a7ad-34f75f672003.png
// P5 - 
// P4 - 4 (PWM)
// P3 - 3 (ADC3)
// P2 - 2 (INT0 / SCL)
// P1 - 1
// P0 - 0 (SDA)

int ledPin = 4; // P4
int buttonLeft = 3; // P3
int buttonRight= 2; // P2

void setup() {
  // @see https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
  // LED
  pinMode(ledPin, OUTPUT);

  // buttons (when pressed they pull down to GND)
  pinMode(buttonLeft, INPUT_PULLUP);
  pinMode(buttonRight, INPUT_PULLUP);
}

unsigned char delay_ms = 50;

void loop() {
  while(1) {
    // https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/
    if ((digitalRead(buttonLeft) == LOW) && (delay_ms > 15)) {
      delay_ms -= 10;
    }
    else if (digitalRead(buttonRight) == LOW && (delay_ms < 250)) {
      delay_ms += 10;
    }

    digitalWrite(ledPin, LOW);
    delay(delay_ms);
    digitalWrite(ledPin, HIGH);
    delay(25);
  }
}
