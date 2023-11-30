#define BUTTON_PIN 8
#define LED_PIN 13

void setup() {
  //setup run once
  pinMode(BUTTON_PIN, INPUT_PULLUP); // connects internal pull-up resistor to button pin
  pinMode(LED_PIN, OUTPUT);

  //turn the led OFF when we start
 // digitalWrite(LED_PIN, LOW);
}

void loop() {

  //boolean value = digitalRead(BUTTON_PIN);
if(digitalRead(BUTTON_PIN) == HIGH){
  digitalWrite(LED_PIN, HIGH);
}
else{
  digitalWrite(LED_PIN, LOW);
}

    //digitalWrite(LED_PIN, value);

}