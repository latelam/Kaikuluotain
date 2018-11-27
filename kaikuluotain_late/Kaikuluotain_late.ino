#include "Kaiku.h"
Kaiku kaiku(10,13);

void setup() {

}

void loop() {
  
  sarjamonitori();
  lcdmonitori();
  
}


void sarjamonitori() {
  kaiku.Laskee();
}


void lcdmonitori() {
  kaiku.Nayttaa();
}
    
  
