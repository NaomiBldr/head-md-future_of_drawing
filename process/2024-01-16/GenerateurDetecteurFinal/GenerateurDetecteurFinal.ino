#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A1;
bool pencilWasPresent = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("DESSINE-MOI ...");
}

void loop() {
  lcd.setCursor(0, 1);

  int ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);

  bool pencilIsPresent = ldrVal < 320;

  if (pencilWasPresent && !pencilIsPresent) {
    Serial.println("Crayon enleve");


    // Liste des mots aléatoires
    const char* randomWords[] = {
      "UN ELEPHANT", "UNE CASCADE", " DU CHOCOLAT", "UN LABYRINTHE", "UN ARC-EN-CIEL", "UN MOUTON","UNE GALAXIE", "UNE GIRAFE", "UNE TEMPETE", "UN PIANO", "UN EMERAUDE", "UN TRAMPOLINE", "UN PAMPLEMOUSSE", "UNE BIBLIOTHEQUE", "LA PLUIE", "UN SAPHIR", "UNE COCCINELLE", "L'OXYGENE", "UNE MONTGOLFIERE", "UN FESTIVAL", "UNE FOUGERE", "UN BISCUIT", "L'HARMONIE", "UNE BOUSSOLE", "LE SOLEIL", "UN PAPILLON", "UN CRISTAL", "DE LA MAGIE", "UN BAMBOU", "UNE ECLIPSE", "UNE MELODIE", "UNE CASCADE", "UN CINEMA", "UNE ETOILE", "UN MIRAGE", "UN OASIS", "UN VOYAGEUR", "UNE PASTEQUE", "UN ORCHESTRE", "UNE ECLOSION", "L'AURORE", "UNE GALAXIE", "UN PARAPLUIE",  "UNE GARGOUILLE", "TA NOSTALGIE", "UNE VIBRATIONS", "UN HOLOGRAMME", "LE ZENITH", "L'INFINI"
    };

    int indexWord = random(0, sizeof(randomWords) / sizeof(randomWords[0]));

    lcd.print(randomWords[indexWord]);
  }

  pencilWasPresent = pencilIsPresent;
  delay(1000);
}
