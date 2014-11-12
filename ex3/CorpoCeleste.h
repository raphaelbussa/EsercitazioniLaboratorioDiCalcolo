#ifndef CORPOCELESTE_H
#define CORPOCELESTE_H
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class CorpoCeleste {
 protected:
  string Nome;
  double m;
  double x;
  double y;
  double vx;
  double vy;
 public:
  CorpoCeleste() ;
  CorpoCeleste(string nomeCorpo, float mass, float xpos, float ypos, float vxi,float vyi);
  //~CorpoCeleste();
  void calcolaPosizione(float fx, float fy, float t);
  void stampaPosizione();
  void stampaVelocita();
  string nome();
  double M();
  double X();
  double Y();
  double Vx();
  double Vy();
};

#endif
