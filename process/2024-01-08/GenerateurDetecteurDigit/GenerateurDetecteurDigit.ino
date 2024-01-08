#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A0;
// Lire la valeur du LDR (résistance dépendante de la lumière)



void setup() {
  lcd.begin(16, 2);
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 0);

  int ldrVal = digitalRead(ldrPin);
  Serial.println(ldrVal);

  // Si la lumière est détectée (ajustez la valeur seuil en fonction de votre environnement)
  if (digitalRead(ldrPin) == HIGH) {
    lcd.clear();

    // Liste des mots aléatoires
    const char* randomWords[] = {
      "Apple", "Banana", "Cherry", "Dragon", "Elephant", "Forest",
      "Giraffe", "Harmony", "Island", "Jupiter", "Kangaroo", "Lighthouse",
      "Mountain", "Nebula", "Ocean", "Penguin", "Quasar", "Rainbow",
      "Sunflower", "Tiger", "Umbrella", "Vortex", "Waffle", "Xylophone",
      "Yogurt", "Zeppelin", "Aurora", "Breeze", "Cascade", "Dolphin",
      "Enigma", "Flamingo", "Galaxy", "Horizon", "Infinity", "Jasmine",
      "Kaleidoscope", "Lagoon", "Mystique", "Nectar", "Orchid", "Paradox",
      "Quintessence", "Radiance", "Sapphire", "Tranquil", "Utopia", "Velvet",
      "Whisper", "Xanadu", "Yesterday", "Zephyr", "Cerulean", "Dandelion",
      "Ephemeral", "Fandango", "Gazelle", "Hibiscus", "Iridescent", "Jamboree",
      "Kismet", "Lullaby", "Majestic", "Nirvana", "Oasis", "Pandemonium",
      "Quicksilver", "Rhapsody", "Serenity", "Twilight", "Utopian", "Vivacious",
      "Wanderlust", "Xerox", "Yonder", "Zestful"
    };

    // Générer un index de mot aléatoire
    int indexWord = random(0, sizeof(randomWords) / sizeof(randomWords[0]));

    // Afficher le mot aléatoire sur l'écran LCD
    lcd.print(randomWords[indexWord]);

    delay(500);
  }
}
