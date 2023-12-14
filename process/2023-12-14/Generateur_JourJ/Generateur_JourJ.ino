#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int boutonPin = 8;

void setup() {
  lcd.begin(16, 2);
  pinMode(boutonPin, INPUT);
}

void loop() {
  lcd.setCursor(0, 0);

  if (digitalRead(boutonPin) == HIGH) {
    lcd.clear();

    // List of extended random words
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

    int indexWord = random(0, sizeof(randomWords) / sizeof(randomWords[0]));
    lcd.print(randomWords[indexWord]);

    delay(500);
  }
}
