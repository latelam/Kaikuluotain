#ifndef Kaiku_h
#define Kaiku_h

#include "Arduino.h"


class Kaiku {

  public:
  Kaiku(int TRIG, int ECHO);
  float Mittaa();
  float Laskee();

  private:
  int viive = 500;
  int Trig_pin;
  int Echo_pin;
  float kestoaika,valimatka;
};

#endif

