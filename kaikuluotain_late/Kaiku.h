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

  private:
  int sarja = 500;
  int viive = 500;
  int Trig_pin;
  int Echo_pin;
  float kestoaika,valimatka;
};

#endif

