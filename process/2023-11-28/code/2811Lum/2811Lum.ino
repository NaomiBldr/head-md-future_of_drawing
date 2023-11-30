#define BUTTON_PIN 7
#define LED 13
float lum = 15; //brightness between 0 and 20

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  // put your setup code here, to run once:

}


void loop() {
  boolean btnDown = !digitalRead(BUTTON_PIN);

//change brightness when button is pressed
if(btnDown){
  lum = lum + 0.1;
  if (lum > 20){
    lum = 0;
  }
}

//control the LED
  digitalWrite(LED,HIGH);
  delay(lum);
  digitalWrite(LED, LOW);
  delay(20 - lum);
  // put your main code here, to run repeatedly:

}
