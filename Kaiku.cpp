#include "Arduino.h"
#include "Kaiku.h"

Kaiku::Kaiku(int TRIG, int ECHO) {

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Trig_pin=TRIG;
  Echo_pin=ECHO;
}

float Kaiku::Mittaa() {

  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  kestoaika = pulseIn(Echo_pin,HIGH);
  return kestoaika;
  
}

float Kaiku::Laskee() {

  Mittaa();
  valimatka = (kestoaika / 2) * 0.0344;         // Etäisyys lasketaan: "pingin" eli äänisignaalin meno-paluuaika / 2 x 0.0344 (äänennopeus 344 metriä/s = 0.0344 cm mikrosekunnissa). 
    if (valimatka >= 500 || valimatka <= 2){      // Jos välimatka yli 5 metriä tai alle 2 senttiä, ilmoita: "alueen ulkopuolella"..
    Serial.print("Välimatka = ");
    Serial.println("Alueen ulkopuolella!");
    delay(viive); }
    else { Serial.print("Välimatka = ");               // ..muutoin näytä etäisyys senttimetreinä.
    Serial.print(valimatka);
    Serial.println(" cm");
    delay(viive);
  }
  delay(viive);
}
  

