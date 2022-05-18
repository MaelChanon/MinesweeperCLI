/**
 * @file Historique.cpp
 * MineSweepers
 * @author Maël Chanon,Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief Initialisation et affichage d'un historique
 */
#include "Historique.h"
#include <iostream>
#include <cassert>
using namespace std;

Historique initHistorique() {
	Historique historique;
	cin >> historique.nbCoups;
	historique.listeDesCoups = new Coup[historique.nbCoups];
	for (unsigned i = 0; i < historique.nbCoups; ++i) {
		cin >> historique.listeDesCoups[i].type;
		assert(historique.listeDesCoups[i].type == 'M' || historique.listeDesCoups[i].type == 'D');
		cin >> historique.listeDesCoups[i].position;
	}
	return historique;
}

void afficherCoup(const Coup& coup){
	cout << coup.type << coup.position<<endl;
}
void detruireHistorique(Historique& historique) {
	delete[] historique.listeDesCoups;
}
