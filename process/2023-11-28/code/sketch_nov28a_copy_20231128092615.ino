#define LED 13
#define BUTTON 8
boolean val = HIGH; //high means one which mean turn on the light

void setup() {
  pinMode(LED, OUTPUT);
 
 //digitalWrite(13, HIGH);
 //digitalWrite(13, LOW);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(LED, val);
delay(1000);
val = !val; //reverse the value so it is turning it off

}
