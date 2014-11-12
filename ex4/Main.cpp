#include "CorpoCeleste.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cout << "Materiale\tDensita' (Kg/m^3)\tV ingr. in Acqua (m/s)\tCond. Finale" << endl;
	double densita[4] = {150, 500, 2700, 8000};
	string materiale[4] = {"Gomma Rigida", "Legno    ", "Alluminio", "Ferro    "};
	for (int i=0; i<4; i++) {
		double r = 0.5;
		double volume = 4/3 * 3.14 * r * r * r;
		double massa = densita[i] * volume;
		CorpoCeleste pallina ("Pallina", massa, 0, 100, 0, 0);
		double altezza = pallina.Y();
		double fy = pallina.M() * -9.81;
		double k1Aria = 0.00035;
		double k1Acqua = 0.02;
		double k2Aria = 0.84;
		double k2Acqua = 700;
		double fIdroAria = k1Aria * r * abs(pallina.Vy()) + k2Aria * r * r * (pallina.Vy() * pallina.Vy());
		double fIdroAcqua = k1Acqua * r * abs(pallina.Vy()) + k2Acqua * r * r * (pallina.Vy() * pallina.Vy());
		double fArchimedeAcqua = 1000 * volume * 9.81;
		double velocitaIngresso;
		while (pallina.Y() >= 0) {
			double forzaDaUsare = fy + fIdroAria;
			pallina.calcolaPosizione(0, forzaDaUsare, 0.001);
			fIdroAria = k1Aria * r * abs(pallina.Vy()) + k2Aria * r * r * (pallina.Vy() * pallina.Vy());
			if (pallina.Y() <= 0) {
				velocitaIngresso = pallina.Vy();
			}
			altezza = pallina.Y();
		}
		while (pallina.Y() <= 0 && pallina.Y()> -150) {
			double forzaDaUsare = fy + fIdroAcqua + fArchimedeAcqua;
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

