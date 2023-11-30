#define BUTTON_PIN 7

void setup() {
  // put your setup code here, to run once:

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Hello world");

}

void loop() {
  boolean btn = digitalREead(BUTTON_PIN);
  Serial.print("Button is");
  Serial.println(btn);
  // put your main code here, to run repeatedly:

}
