/**
 * @file Main.cpp
 * MineSweepers
 * @author Maël Chanon, Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief regroupement des 5 opérations
 */
#include "ProchainCoup.h"
#include <iostream>

using namespace std;
int main() {
	Grille grille;
	unsigned int val =0;
	cin >> val;
	switch (val) {
	case 1:
		Probleme pb = initPB();
		randomBombGenerator(pb, pb.largeur*pb.longueur);
		afficherProbleme(pb);
		detruireProbleme(pb);
		break;
	case 2:
		grille = initGrille(-1);
		affichageGrille(grille);
		detruireTableau2D(grille);
		break;
	case 3:
		grille =initGrille(0);
		detruireTableau2D(grille);
		break;
	case 4:
		grille=initGrille(1);
		detruireTableau2D(grille);
		break;
	case 5:
		grille = enregistrerGrille();
		Coup coup = prochainCoup(grille);
		detruireTableau2D(grille);
		afficherCoup(coup);
		break;
	default:
		return 0;
	}
}