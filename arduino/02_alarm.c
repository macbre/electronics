#define LED_PIN    13
#define BUTTON_PIN 10
#define BUZZER_PIN 11

#define PHOTO_TR_PIN 16

void setup() {
  //start serial connection
  Serial.begin(9600);

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(PHOTO_TR_PIN);
  Serial.println(value);

  if (value > 1000) {
    digitalWrite(LED_PIN, LOW);
    //digitalWrite(BUZZER_PIN, LOW);
    noTone(BUZZER_PIN);
  }
  else {
    digitalWrite(LED_PIN, HIGH);
    //digitalWrite(BUZZER_PIN, HIGH);
    Serial.println("!!!ALERT");
    tone(BUZZER_PIN, 5000);
  }
  
  delay(500);
}
