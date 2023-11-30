#define LED 13

int lum = 15; // brightness betweenn 0 and 1
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(LED, OUTPUT);
}

void loop() {
  // will get the value between 0 and 1023
 int value = analogRead(A0);
 Serial.println(value);


lum = map(value,0,1023,0,20);

  Serial.print(value);
  Serial.print("\t");
  Serial.println(lum);

 //pulse the LED
 digitalWrite(LED, HIGH);
 delay(lum);
 digitalWrite(LED, LOW);
 delay(20-lum);

  delay(100);
}
