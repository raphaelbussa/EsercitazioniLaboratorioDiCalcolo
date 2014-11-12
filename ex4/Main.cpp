#include "CorpoCeleste.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double r = 0.5;
	double volume = 4/3 * 3.14 * r * r * r;
	double densita[4] = {150, 500, 2700, 8000};
	double k1Aria = 0.00035;
	double k1Acqua = 0.02;
	double k2Aria = 0.84;
	double k2Acqua = 700;
	double fIdroAria;
	double fIdroAcqua;
	double massa;
	double fy;
	double altezza;
	double velocitaIngresso;
	double fArchimedeAcqua;
	double forzaDaUsare;
	string materiale[4] = {"Gomma Rigida", "Legno    ", "Alluminio", "Ferro    "};
	cout << "Materiale\tDensita' (Kg/m^3)\tV ingr. in Acqua (m/s)\tCond. Finale" << endl;
	for (int i=0; i<4; i++) {
		massa = densita[i] * volume;
		CorpoCeleste pallina ("Pallina", massa, 0, 100, 0, 0);
		altezza = pallina.Y();
		fy = pallina.M() * -9.81;
		fIdroAria = k1Aria * r * abs(pallina.Vy()) + k2Aria * r * r * (pallina.Vy() * pallina.Vy());
		fIdroAcqua = k1Acqua * r * abs(pallina.Vy()) + k2Acqua * r * r * (pallina.Vy() * pallina.Vy());
		fArchimedeAcqua = 1000 * volume * 9.81;
		while (pallina.Y() >= 0) {
			forzaDaUsare = fy + fIdroAria;
			pallina.calcolaPosizione(0, forzaDaUsare, 0.001);
			fIdroAria = k1Aria * r * abs(pallina.Vy()) + k2Aria * r * r * (pallina.Vy() * pallina.Vy());
			if (pallina.Y() <= 0) {
				velocitaIngresso = pallina.Vy();
			}
			altezza = pallina.Y();
		}
		while (pallina.Y() <= 0 && pallina.Y()> -150) {
			forzaDaUsare = fy + fIdroAcqua + fArchimedeAcqua;
			pallina.calcolaPosizione(0, forzaDaUsare, 0.001);
			fIdroAcqua = k1Acqua * r * abs(pallina.Vy()) + k2Acqua * r * r * (pallina.Vy() * pallina.Vy());
			if (altezza > pallina.Y()) {
				altezza = pallina.Y();
			}
		}
		
		cout << materiale[i] << "\t" <<  densita[i] << "\t\t\t" << velocitaIngresso << "\t\t" << altezza << endl;
	}
	
	return 1;
}

