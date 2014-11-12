#include "CorpoCeleste.h"
#include <iostream>
using namespace std;
int main() {
    float massa, x, y, vx, vy;
    float tempo = 0.0;
    cout << "Assegnare la posizione iniziale (x, y): ";
    cin >> x >> y;
    cout << "Assegnare la massa: ";
    cin >> massa;
    cout << "Assegnare la velocita' iniziale (vx, vy): ";
    cin >> vx >> vy;
    CorpoCeleste sasso ("Sasso", massa, x, y, vx, vy);
    double fy = sasso.M() * -9.81;
    while(sasso.Y() >= 0) {
        sasso.calcolaPosizione(0, fy, 0.001);
	cout << "t: " << tempo << " ";
	sasso.stampaPosizione();
	cout << " vx: " << sasso.Vx() << " vy: " << sasso.Vy() << "\r";
	tempo = tempo + 0.001;
    }
    cout << endl;
    return 1;

}
