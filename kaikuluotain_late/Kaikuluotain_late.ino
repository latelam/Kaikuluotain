#include "Kaiku.h"                  // Liitos Kaiku-kirjastoon.
#define TAUSTAVALO 6                // Taustavalon ohjaus Arduinon pinnin 6 kautta.
Kaiku kaiku(10,13);                 // Ultraäänisensorin trig ja echo pinnit. ("laukaus" ja kaiun vastaanotto).

void setup() {

  pinMode(TAUSTAVALO, OUTPUT);      // Taustavalon päälle/pois kytkevä pinni 6 asetettu lähdöksi.  
  digitalWrite(TAUSTAVALO, HIGH);   // LCD-näytön taustavalon voi valita päälle/pois >> HIGH/LOW.
}

void loop() {
  
  sarjamonitori();                  // Funktiokutsut sarjamonitoriin- tai lcd-näytölle tulostukseen.
  lcdmonitori();
  
}


void sarjamonitori() {
  kaiku.Laskee();
}


void lcdmonitori() {
  kaiku.Nayttaa();
}
    
  
