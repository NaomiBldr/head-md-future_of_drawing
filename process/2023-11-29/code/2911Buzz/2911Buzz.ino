#define PIEZO 8

int sound = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(PIEZO, OUTPUT);

}

void loop() {

   int value = analogRead(A0);

  sound = map(value,0,1023,0,20);

  /*digitalWrite(PIEZO, HIGH); //5V or 3.3v
  delay(10);
  digitalWrite(PIEZO, LOW);
  delay(10);*/
  // put your main code here, to run repeatedly:


//plays 1 sec
  tone(PIEZO, sound,1000); //piece frequence et temps

  //wait 2 secc
  delay(2000);

//plays 1 sec
  tone(PIEZO, 2000); //forever until you hear no tone
  delay(1000);
  noTone(PIEZO); //reference de pin

  delay(1000);
}
