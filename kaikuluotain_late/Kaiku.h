#ifndef Kaiku_h
#define Kaiku_h

#include "Arduino.h"

class Kaiku {

  public:
  Kaiku(int TRIG, int ECHO);
  void Mittaa();
  float Laskee();
  void NayttaaSarja();
  void NayttaaLCD();
  void Alkudemo();
 
  byte ae[8] = {      //ÄÄKKÖSET /ä
  0b01010,
  0b00000,
  0b01110,
  0b00001,
  0b01111,
  0b10001,
  0b01111,
  0b00000
};

byte oo[8] = {      //ö
  0b01010,
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b01110,
  0b00000
};

byte AE[8] = {      //Ä
  0b01010,
  0b00000,
  0b00100,
  0b01010,
  0b10001,
  0b11111,
  0b10001,
  0b10001
};

byte OO[8] = {      //Ö
  0b01010,
  0b00000,
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b01110
};

  private:
  int sarja = 500;
  int viive = 500;
  int Trig_pin;
  int Echo_pin;
  float kestoaika,valimatka;
};

#endif

