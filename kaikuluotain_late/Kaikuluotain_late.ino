#include "Kaiku.h"                  // Liitos Kaiku-kirjastoon.
const int TAUSTAVALO = 6;           // Taustavalon ohjaus Arduinon pinnin 6 kautta.
Kaiku kaiku(10,13);                 // Ultraäänisensorin trig ja echo pinnit. ("laukaus" ja kaiun vastaanotto).

void setup() {                      // Tässä alustetaan ja valmistellaan kortti ennen varsinaista ohjelmasilmukkaa. Tämä ajetaan vain kerran kun Arduinoon kytketään virta.

  pinMode(TAUSTAVALO, OUTPUT);      // Taustavalon päälle/pois kytkevä pinni 6 asetettu lähdöksi.  
  digitalWrite(TAUSTAVALO, HIGH);   // LCD-näytön taustavalon voi valita päälle/pois >> HIGH/LOW.
  alkudemo();                       // Alkudemon funktiokutsu
}
  
void loop() {                      // Tässä osassa sijaitsee ohjelman pääkoodi. Siinä olevien komentojen muodostamaa kokonaisuutta toistetaan uudelleen ja uudelleen, kunnes Arduinosta katkaistaan virta.
  
 sarjamonitori();                  // Funktiokutsut sarjamonitoriin- tai lcd-näytölle tulostukseen.
 lcdmonitori();
}

void sarjamonitori() {            // Funktio sarjamonitoriin tulostukseen
  kaiku.NayttaaSarja();
}

void lcdmonitori() {              // Funktio LCD-näytölle tulostukseen
  kaiku.NayttaaLCD();
}

void alkudemo() {                // Alkudemon funktio
  kaiku.Alkudemo();
}

  
