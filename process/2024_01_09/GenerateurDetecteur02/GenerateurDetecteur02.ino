#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A0;
bool wordDisplayed = false; // Variable pour vérifier si le mot a déjà été affiché
unsigned long lastDisplayTime = 0; // Variable pour stocker le temps du dernier affichage

void setup() {
  lcd.begin(16, 2);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 0);

  int ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);

  // Si la lumière est détectée (ajustez la valeur seuil en fonction de votre environnement)
  if (ldrVal > 500 && !wordDisplayed && (millis() - lastDisplayTime >= 5000)) {
    lcd.clear();

    // Liste des mots aléatoires
    const char* randomWords[] = {
      "Coucher de soleil sur une ville futuriste",
      "Portrait abstrait mêlant nature et technologie",
      "Labyrinthe complexe avec des éléments fantastiques",
      "Animaux sauvages dans un écosystème mystique",
      "Fusion de cultures à travers des symboles traditionnels",
      "Vision artistique d'une galaxie lointaine",
      "Paysage sous-marin avec des créatures imaginaires",
      "Personnages fantastiques dans un monde steampunk",
      "Illustration d'une légende urbaine locale",
      "Composition florale abstraite en noir et blanc"
    };

    // Générer un index de mot aléatoire
    int indexWord = random(0, sizeof(randomWords) / sizeof(randomWords[0]));

    // Afficher le mot aléatoire sur l'écran LCD
    lcd.print(randomWords[indexWord]);

    wordDisplayed = true; // Mettez à jour la variable pour indiquer que le mot a été affiché
    lastDisplayTime = millis(); // Mettez à jour le temps du dernier affichage

    delay(500);
  } else if (ldrVal <= 500 && wordDisplayed) {
    // Réinitialiser la variable si la luminosité est en dessous du seuil
    wordDisplayed = false;
  }
}
