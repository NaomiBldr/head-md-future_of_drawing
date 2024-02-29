#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A1;
bool pencilWasPresent = false;

void setup() {
  lcd.begin(16, 2);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

// Liste des mots aléatoires
const char* randomWords[] = {
  "UN ELEPHANT", "UNE CASCADE", "DU CHOCOLAT", "UN LABYRINTHE", "UN ARC-EN-CIEL", "UN MOUTON", "UNE GALAXIE", "UNE GIRAFE", "UNE TEMPETE", "UN PIANO", "UNE EMERAUDE", "UN TRAMPOLINE", "UN PAMPLEMOUSSE", "UNE BIBLIOTHEQUE", "LA PLUIE", "UN SAPHIR", "UNE COCCINELLE", "L'OXYGENE", "UNE MONTGOLFIERE", "UN FESTIVAL", "UNE FOUGERE", "UN BISCUIT", "L'HARMONIE", "UNE BOUSSOLE", "LE SOLEIL", "UN PAPILLON", "UN CRISTAL", "DE LA MAGIE", "UN BAMBOU", "UNE ECLIPSE", "UNE MELODIE", "UNE CASCADE", "UN CINEMA", "UNE ETOILE", "UN MIRAGE", "UN OASIS", "UN VOYAGEUR", "UNE PASTEQUE", "UN ORCHESTRE", "UNE ECLOSION", "L'AURORE", "UNE GALAXIE", "UN PARAPLUIE", "UNE GARGOUILLE", "TA NOSTALGIE", "DES VIBRATIONs", "UN HOLOGRAMME", "LE ZENITH", "L'INFINI","ABEILLE","UNE BIBLIOTHEQUE","UN CACTUS","UN DINOSAURE","UN EXPLORATEUR","UNE FENETRE","L'HORIZON","DES JUMELLES","UN KANGOUROU","UNE LANTERNE","UN MAGNOLIA","UN NUAGE","UN PANTALON","UN SERPENT","UN TAMBOUR","UN VIOLONCELLE","UN WAGON","UN XYLOPHONE","UN ZEBRE","UN CROCODILE","UN PLUMEAU","UN PARAPLUIE","UN JARDIN","UN ORDINATEUR","L'HARMONIE","UNE CHAUSSURE","UNE RADIO","DES CISEAUX","UNE MONTAGNE","UN CROISSANT","UNE CARTE","UNE CLOCHETTE","UN CERCLE","UN TOURBILLON","UN ARBRE","UNE MAISON","UN SOLEIL","UNE FLEUR","UN CHAT","UNE LUNE","UNE VOITURE","UN COEUR","UN POISSON","UN ECUREUIL","UN AVION","UN OURS","UN CAMION","UNE GLACE","UNE TORTUE","UN CHIEN","UNE EPEE"
};



void loop() {

  lcd.setCursor(0, 0);
  lcd.print("DESSINE-MOI ...");
  int indexWord = random(0, sizeof(randomWords) / sizeof(randomWords[0]));


  int ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);

  bool pencilIsPresent = ldrVal < 200;

  if (pencilWasPresent && !pencilIsPresent) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DESSINE-MOI ...");
    lcd.setCursor(0, 1);

    Serial.println("Crayon enleve");





    lcd.print(randomWords[indexWord]);
  }

  pencilWasPresent = pencilIsPresent;
  delay(500);
}
