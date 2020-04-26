// the setup function runs once when you press reset or power the board

#define LED_PIN    13
#define BUTTON_PIN 10
#define BUZZER_PIN 13

#define PHOTO_TR_PIN 16

void setup() {
  //start serial connection
  Serial.begin(9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int freq = 0;
  
  while(1) {
    Serial.println(freq);
    
    tone(BUZZER_PIN, freq);

    freq += 1;

    if (freq > 2000) freq = 0;
  
    delay(6);
  }
  
}
