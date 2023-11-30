#define LED 13

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  morse("SOS IM STARVING STOP PLEASE FEED ME");
}

void morse(String message) {
  Serial.print(message);

  for(char c : message){
    Serial.print(c);

    switch(c){
      case 'A': sendSymbols('.break;
      case 'B': break;
      case 'C': break;
      case 'D': break;
      case 'E': break;
      case 'F': break;
      case 'G': break;
      case 'H': break;
      case 'I': break;
      case 'J': break;
      case 'K': break;
      case 'L': break;
      case 'M': break;
      case 'N': break;
      case 'O': break;
      case 'P': break;
      case 'Q': break;
      case 'R': break;
      case 'S': break;
      case 'T': break;
      case 'U': break;
      case 'V': break;
      case 'W': break;
      case 'X': break;
      case 'W': break;
      case 'X': break;
    }

   /* if (c == 'S'){
      ti();ti();ti();
    }
        if (c == 'O'){
      ta();ta();ta();
    }
        if (c == ''){
      endOfLetter();
    }*/
      endOfLetter();

  }
}

void sendSymbols(String symbols){
  for (char c : symbols){
    switch (c) {
      case '.': ti(); break;
      case '_'
    }
  }
}

//Ti
void ti() {
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}

// Ta
void ta() {
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}

//End of letter
void endOfLetter() {
  delay(400);
}
}
