#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A0;
bool wordDisplayed = false; // Variable pour vérifier si le mot a déjà été affiché
unsigned long lastDisplayTime = 0; // Variable pour stocker le temps de la dernière affichage

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
      "Apple", "Banana", "Cherry", "Dragon", "Elephant", "Forest",
      "Giraffe", "Harmony", "Island", "Jupiter", "Kangaroo", "Lighthouse",
      "Mountain", "Nebula", "Ocean", "Penguin", "Quasar", "Rainbow",
      "Sunflower", "Tiger", "Umbrella"
    };

    // Générer un index de mot aléatoire
    int indexWord = random(0, sizeof(randomWords) / sizeof(randomWords[0]));

    // Afficher le mot aléatoire sur l'écran LCD
    lcd.print(randomWords[indexWord]);

    wordDisplayed = true; // Mettez à jour la variable pour indiquer que le mot a été affiché
    lastDisplayTime = millis(); // Mettez à jour le temps de la dernière affichage

    delay(500);
  } else if (ldrVal <= 500 && wordDisplayed) {
    // Réinitialiser la variable si la luminosité est en dessous du seuil
    wordDisplayed = false;
  }
}

