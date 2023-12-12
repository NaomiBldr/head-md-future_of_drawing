#include <LiquidCrystal.h> //bibliothèque liquidcrystal

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //broches associées

void setup() {

  lcd.begin(16, 2); //16 colonnes 2 lignes configuration de l'écran


}

void loop() {

  lcd.setCursor(0, 0); //position du curseur
  lcd.print("Jar maninc"); //texte qui s'affiche

}
