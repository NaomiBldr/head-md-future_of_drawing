#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A0;
// Lire la valeur du LDR (résistance dépendante de la lumière)

bool pencilWasPresent = false;


void setup() {
  lcd.begin(16, 2);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
  lcd.print("Hello World");
}

void loop() {
  lcd.setCursor(0, 0);

  int ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);

  bool pencilIsPresent = ldrVal < 320;

  // Si la lumière est détectée (ajustez la valeur seuil en fonction de votre environnement)
  if (pencilWasPresent && !pencilIsPresent) {
    Serial.println("Crayon enleve");
    lcd.clear();

    // Liste des mots aléatoires
    const char* randomWords[] = {
      "ELEPHANT", "CASCADE", "CHOCOLAT", "LABYRINTHE", "ARC-EN-CIEL", "GALAXIE", "GIRAFE", "TEMPETE", "PIANO", "AVENTURE", "ECLAT", "SERENITE", "EMERAUDE", "TRAMPOLINE", "MIRACLE", "PAMPLEMOUSSE", "FELICITE", "BIBLIOTHEQUE", "MYSTERE", "VOYAGE", "PLUIE", "SAPHIR", "LIBERTE", "COCCINELLE", "OXYGENE", "MONTGOLFIERE", "FESTIVAL", "FOUGERE", "EXOTIQUE", "MYSTIQUE", "BISCUIT", "HARMONIE", "BOUSSOLE", "SOLEIL", "PAPILLON", "CRISTAL", "INSOUCIANCE", "MAGIE", "BAMBOU", "REFLEXION", "ECLIPSE", "MELODIE", "CASCADE", "CINEMA", "ETOILE", "MIRAGE", "VOYAGEUR", "BALLET", "ENIGME", "PASTEQUE", "ORCHESTRE", "ECLOSION", "FANTAISIE", "AURORA", "BIBLIOPHILIE", "RAFALE", "EPOUSTOUFLANT", "GALAXIE", "JUBILATION", "OPULENCE", "EQUINOXE", "PARAPLUIE", "CAPITULATION", "LEGENDAIRE", "EFFERVESCENT", "GARGOUILLE", "MERVEILLE", "NOSTALGIE", "ECLIPSES", "QUINTESSENCE", "VIBRATIONS", "HOLOGRAMME", "ZENITH", "ENCHANTEMENT", "PETILLANT", "INFINI", "RESONANCE", "QUASAR"
    };

    // Générer un index de mot aléatoire
    int indexWord = random(0, sizeof(randomWords) / sizeof(randomWords[0]));

    // Afficher le mot aléatoire sur l'écran LCD
    lcd.print(randomWords[indexWord]);
  }
  //On se rapelle de la présence du crayon pour le prochain loop
  pencilWasPresent = pencilIsPresent;
  delay(200);
}
