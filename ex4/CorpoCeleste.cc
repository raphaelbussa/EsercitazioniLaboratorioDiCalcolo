#include "CorpoCeleste.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
CorpoCeleste::CorpoCeleste() { }
CorpoCeleste::CorpoCeleste(string nomeCorpo, float mass, float xpos, float ypos, float vxi, float vyi) {
  Nome = nomeCorpo;
  m = mass;
  x = xpos;
  y = ypos;
  vx = vxi;
  vy = vyi;
}
void CorpoCeleste::calcolaPosizione(float fx, float fy, float t) {
  double ax = fx/m;
  double ay = fy/m;
  vx += ax*t;
  vy += ay*t;
  x += vx*t;
  y += vy*t;
}
void CorpoCeleste::stampaPosizione() {
  cout << "x: " << x << " y: " << y; 
}
string CorpoCeleste::nome() {
  return Nome;
}
double CorpoCeleste::M() {
  return m;
}
double CorpoCeleste::X() {
  return x;
}
double CorpoCeleste::Y() {
  return y;
}
double CorpoCeleste::Vx() {
  return vx;
}
double CorpoCeleste::Vy() {
  return vy;
}

