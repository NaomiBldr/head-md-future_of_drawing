#define BUTTON_PIN 7 //define constantes
#define LED_PIN 13

void setup() {
  //setup run once
  pinMode(BUTTON_PIN, INPUT_PULLUP); // connects internal pull-up resistor to button pin pullup on ajoute les 5v par defaut
  
  pinMode(LED_PIN, OUTPUT); //output sortie

  //turn the led OFF when we start
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
  Serial.println("Hello World");
}

void loop() {

  boolean value = digitalRead(BUTTON_PIN); //boolean vrai 1 ou faux 0
  Serial.print("Button is ");
  Serial.println(btn);

    digitalWrite(LED_PIN, !value);

}