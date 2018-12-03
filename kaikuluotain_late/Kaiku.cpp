#include "Arduino.h"
#include "Kaiku.h"
#include <LiquidCrystal.h>

Kaiku::Kaiku(int TRIG, int ECHO) {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Trig_pin=TRIG;
  Echo_pin=ECHO;
}

void Kaiku::Mittaa() {

  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  kestoaika = pulseIn(Echo_pin,HIGH);
  return kestoaika;
}

float Kaiku::Laskee() {
 
  valimatka = (kestoaika / 2) * 0.0344;           // Etäisyys lasketaan: "pingin" eli äänisignaalin meno-paluuaika / 2 x 0.0344 (äänennopeus 344 metriä/s = 0.0344 cm mikrosekunnissa).
}

void Kaiku::NayttaaSarja() {
    
  Serial.begin(9600);

  Mittaa();
  Laskee();         
  
    if (valimatka >= 500 || valimatka <= 2){      // Jos välimatka yli 5 metriä tai alle 2 senttiä, ilmoita: "alueen ulkopuolella"..
    Serial.println("Alueen ulkopuolella !!!");
    delay(sarja);
    } else { 
    Serial.print("Välimatka : ");               // ..muutoin näytä etäisyys senttimetreinä.
    Serial.print(valimatka);
    Serial.println(" cm");
    delay(sarja);
  }
}


void Kaiku::NayttaaLCD() {
  
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  lcd.begin(16, 2);
  lcd.createChar(1, ae);
  lcd.createChar(2, oo);
  lcd.createChar(3, AE);
  lcd.createChar(4, OO);

  Mittaa();
  Laskee();
  
    if (valimatka >= 500 || valimatka <= 2){      // Jos välimatka yli 5 metriä tai alle 2 senttiä, ilmoita: "alueen ulkopuolella"..
    lcd.setCursor (0, 0);
    lcd.print("Alueen");
    lcd.setCursor (0, 1);
    lcd.print("ulkopuolella !!!");
    } else {
    lcd.clear();
    lcd.setCursor (0, 0);
    lcd.print("V");             // ..muutoin näytä etäisyys senttimetreinä.
    lcd.write(byte(1));
    lcd.print("limatka :");
    lcd.setCursor (0, 1); 
    lcd.print(valimatka);
    lcd.print(" cm");
    }
    delay(viive);   
}

void Kaiku::Alkudemo() {

  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  lcd.begin(16, 2);
   
    lcd.setCursor (0, 0);
    lcd.print("Kaikuluotain");
    lcd.setCursor (0, 1);
    lcd.print("LATE 2018");
    delay(5000);  
}

