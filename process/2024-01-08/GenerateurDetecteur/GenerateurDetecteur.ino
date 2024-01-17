#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A1;
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

  bool pencilIsPresent = ldrVal < 100;

  // Si la lumière est détectée (ajustez la valeur seuil en fonction de votre environnement)
  if (pencilWasPresent && !pencilIsPresent) {
    Serial.println("Crayon enleve");
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


  }
  //On se rapelle de la présence du crayon pour le prochain loop
  pencilWasPresent = pencilIsPresent;
      delay(200);
}
