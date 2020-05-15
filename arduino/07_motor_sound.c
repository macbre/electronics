#define LED_PIN  13
#define TONE_PIN 6

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  pinMode(TONE_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int freq = 0;
  
  while(1) {
    tone(TONE_PIN, freq);
    delay(3);
    noTone(TONE_PIN);
    delay(2);

    freq += 20;

    if (freq > 5000) freq = 0;
  }
}
