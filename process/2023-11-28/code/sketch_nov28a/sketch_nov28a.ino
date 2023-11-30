#define LED 13
boolean val = HIGH;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, val);
 //digitalWrite(13, HIGH);
 //digitalWrite(13, LOW);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED, HIGH);
delay(1000);
digitalWrite(LED, LOW);
delay(100);
}
