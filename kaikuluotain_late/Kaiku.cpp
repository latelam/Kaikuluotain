#include "Arduino.h"                        // Liitetään Arduino-kirjasto
#include "Kaiku.h"                          // Liitetään Kaiku-kirjasto
#include <LiquidCrystal.h>                  // Liitetään LCD-näytön kirjasto

Kaiku::Kaiku(int TRIG, int ECHO) {          // Konstruktori, funktio joka luo uuden ilmentymän Kaiku-luokasta.

  pinMode(TRIG, OUTPUT);                    // Määritetään sensorin lähdöt ja tulot
  pinMode(ECHO, INPUT);
  Trig_pin=TRIG;
  Echo_pin=ECHO;
}

void Kaiku::Mittaa() {

  digitalWrite(Trig_pin, LOW);              // Lähettää äänipulssin (trig).. 
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  kestoaika = pulseIn(Echo_pin,HIGH);      // ..ja vastaanottaa sen kaiun (echo) pulseIn()-funktio toimii ajastimena lukemalla echo-pinnin pulssia ja saaden näin arvon kestoajalle.
  return kestoaika;                        // palauttaa kestoajan arvon
}

float Kaiku::Laskee() {                           // float-funktio pystyy käsittelemään desimaalilukuja joita tässä laskutoimituksessa tarvitaan.
 
  valimatka = (kestoaika / 2) * 0.0344;           // Etäisyys lasketaan: "pingin" eli äänisignaalin meno-paluuaika / 2 x 0.0344 (äänennopeus 344 metriä/s = 0.0344 cm mikrosekunnissa).
}

void Kaiku::NayttaaSarja() {                    
    
  Serial.begin(9600);                             // Sarjaportin alustus

  Mittaa();                                       // tekee mittauksen
  Laskee();                                       // tekee laskutoimituksen
  
    if (valimatka >= 400 || valimatka <= 2){      // Jos välimatka yli 4 metriä tai alle 2 senttiä, ilmoita: "alueen ulkopuolella"..
    Serial.println("Alueen ulkopuolella !!!");
    delay(sarja);                               // odottaa muuttujissa määritetyn ajan
    } else { 
    Serial.print("Välimatka : ");               // ..muutoin näytä etäisyys senttimetreinä.
    Serial.print(valimatka);
    Serial.println(" cm");
    delay(sarja);                              // odottaa muuttujissa määritetyn ajan
  }
}


void Kaiku::NayttaaLCD() {
  
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);    // LCD-näytön pinnien määritys
  lcd.begin(16, 2);                         // LCD-näytön alustus
  lcd.createChar(1, ae);                    // luo kirjaimen ä
  lcd.createChar(2, oo);                    // luo kirjaimen ö
  lcd.createChar(3, AE);                    // luo kirjaimen Ä
  lcd.createChar(4, OO);                    // luo kirjaimen Ö

  Mittaa();                          // tekee mittauksen
  Laskee();                          // tekee laskutoimituksen
  
    if (valimatka >= 400 || valimatka <= 2){      // Jos välimatka yli 4 metriä tai alle 2 senttiä, ilmoittaa: "alueen ulkopuolella"
    lcd.setCursor (0, 0);                       // asettaa kursorin ylärivin alkuun
    lcd.print("Alueen");                        // näyttää tekstin
    lcd.setCursor (0, 1);                       // asettaa kursorin alarivin alkuun
    lcd.print("ulkopuolella !!!");
    } else {                            // ..muutoin näytä etäisyys senttimetreinä.
    lcd.clear();                        // tyhjentää näytön uutta tulostusta varten
    lcd.setCursor (0, 0);       // asettaa kursorin ylärivin alkuun
    lcd.print("V");             
    lcd.write(byte(1));         // piirtää kirjaimen ä LCD-näytölle (koska LCD:n omassa kirjastossa ei ole ääkkösiä).
    lcd.print("limatka :");
    lcd.setCursor (0, 1);       // asettaa kursorin alarivin alkuun
    lcd.print(valimatka);       // näyttää laskutoimituksen tuloksen
    lcd.print(" cm");
    }
    delay(viive);   // odottaa muuttujissa määritetyn ajan
}

void Kaiku::Alkudemo() {

  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);    // LCD-näytön pinnien määritys
  lcd.begin(16, 2);                         // LCD-näytön alustus
   
    lcd.setCursor (0, 0);               // asettaa kursorin ylärivin alkuun
    lcd.print("Kaikuluotain");          // näyttää tekstin
    lcd.setCursor (0, 1);               // asettaa kursorin alarivin alkuun
    lcd.print("LATE 2018");             // näyttää tekstin
    delay(5000);                  // näyttää tekstiä 5 sekuntia
}

