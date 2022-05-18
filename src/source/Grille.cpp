/**
 * @file Grille.cpp
 * MineSweepers
 * @author Maël Chanon, Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief initialisation, affichage et vérification d'une grille
 */
#include "Grille.h"
#include <iostream>
#include <cassert>

using namespace std;


//-----------------INITIALISATION DE LA GRILLE----------------------
Grille initGrille(int i) {
	Grille grille;
 	Probleme probleme = initPB();
	grille.largeur = probleme.largeur;
	grille.longueur = probleme.longueur;
	saisirMines(probleme);
	Historique historique = initHistorique();
	initTableau2D(grille);
	definirCoups(grille, probleme,historique);

	/*permet de faire les opération 3 4 en ne recopiant pas
	 trop les mêmes lignes*/
	if (i == 0) {
		if (isWin(grille, probleme.nbMine))
			cout << "game won";
		else
			cout << "game not won";
	}
	if (i == 1) {
		if (isLose(historique.listeDesCoups[historique.nbCoups-1], probleme))
			cout << "game lost";
		else
			cout << "game not lost";
	}

	detruireProbleme(probleme);
	detruireHistorique(historique);
	return grille;
}

Grille enregistrerGrille() {

	Grille grille;

	cin >> grille.largeur;
	cin >> grille.longueur;
	unsigned int taille = (grille.longueur * 4+2);
	char* buffer = new char[taille];
	initTableau2D(grille);
	cin.getline(buffer, taille);
	// ici on enregistre que le contenue des cases
	for (unsigned int i = 0; i < grille.largeur * 2 + 1; ++i) {
		cin.getline(buffer, taille);
		//on ne s'intéresse qu'à une seule ligne sur deux 
		if (i % 2 == 1){
			grille.tab[i/2][0] = buffer[2];
			for (unsigned int o = 1; o < grille.longueur; ++o) {
				grille.tab[i / 2][o] = buffer[o* 4 + 2];
			}
		}
	}
	delete buffer;
	return grille;
}

void initTableau2D(Grille& grille) {
	grille.tab = new char* [grille.largeur];
	for (unsigned int i = 0; i < grille.largeur; i++) {
		grille.tab[i] = new char[grille.longueur];
		for (unsigned int o = 0; o < grille.longueur; ++o) {
			grille.tab[i][o] = '.'; //toutes les cases non visitées 
		}
	}
}

void detruireTableau2D(Grille& grille) {
	for (unsigned int i = 0; i < grille.largeur; i++) {
		delete[] grille.tab[i];
	}
	delete[] grille.tab;
}

void definirCoups(Grille& grille, const Probleme& probleme, const Historique& historique) {
	Pile p;
	initialiser(p, 1, 2); //la pile est extensible 

	for (unsigned int i = 0; i < historique.nbCoups; ++i) {
		assert(historique.listeDesCoups[i].position < grille.largeur* grille.longueur); //on verifie que les coups sont valides 
		if (historique.listeDesCoups[i].type == 'M') 
			marquerCase(grille, numberToPosition(historique.listeDesCoups[i].position, grille.longueur), -1); 
		if (historique.listeDesCoups[i].type == 'D') 
			empiler(p, numberToPosition(historique.listeDesCoups[i].position, grille.longueur));
	}
	while (!estVide(p)) 
		remplirGrille(grille, p, historique, probleme);
	
	if (isWin(grille, probleme.nbMine) || isLose(historique.listeDesCoups[historique.nbCoups-1], probleme))
		placerMines(grille, probleme);
	detruire(p); //detruire la pile
}

void remplirGrille(Grille& grille, Pile& p, const Historique& historique, const Probleme& probleme) {
	unsigned int nbEmpile = 0; //nombre de positions à depiler si la case possède des bombes autours
	unsigned int compteur = 0;
	Position positionInitiale = sommet(p);
	depiler(p);
	Position* tabPosition = caseAutour(positionInitiale);

	for (short i = 0; i < 8; ++i) {
		if (!estValide(tabPosition[i], grille.longueur, grille.largeur) || grille.tab[tabPosition[i].ord][tabPosition[i].abs] == ' ') {
			continue;
		}
		if (isMine(probleme, tabPosition[i])) {
			++compteur;
			continue;
		}
		if (grille.tab[tabPosition[i].ord][tabPosition[i].abs] == '.') {
			empiler(p, tabPosition[i]);
			++nbEmpile;
		}
	}
	if (compteur != 0) { //si on se rend compte que la case a des mines autours
		for (unsigned short i = 0; i < nbEmpile; ++i) {
			depiler(p);
		}
	}
	marquerCase(grille, positionInitiale, compteur);
	delete[] tabPosition;
}

Position* caseAutour(const Position& position) {
	unsigned int compteur = 0;
	Position tmp;
	Position* tabPosition = new Position[8];
	for (short x = -1; x < 2; ++x) { //on inspecte les 9 cases 
		for (short y = -1; y < 2; ++y) {
			if ((y == 0 && x == 0))
				continue;
			tmp = position;
			tmp.abs += x;
			tmp.ord += y;
			tabPosition[compteur] = tmp;
			++compteur;
		}
	}
	return tabPosition;
}

void placerMines(Grille& grille, const Probleme& probleme) {
	for (unsigned int i = 0; i < probleme.nbMine; ++i)
		marquerCase(grille, numberToPosition(probleme.tabMine[i], grille.longueur), -2);
}
void marquerCase(Grille& grille, const Position& position, int compteur) {
	if (compteur == 0) {
		grille.tab[position.ord][position.abs] = ' ';
		return;
	}
	if (compteur == -1) {
		grille.tab[position.ord][position.abs] = 'x';
		return;
	}
	if (compteur == -2) {
		grille.tab[position.ord][position.abs] = 'm';
		return;
	}
	char buffer[2];
	sprintf_s(buffer,2,"%d", compteur);
	grille.tab[position.ord][position.abs] = buffer[0];
}


//-------------------AFFICHAGE DE LA GRILLE-----------------------------------------
void affichageGrille(const Grille& g) {
	unsigned int position = 0;
	cout << g.largeur << " " << g.longueur<<endl;
	for (unsigned int i = 0; i < g.largeur* 2; i++) {
		for (unsigned int o = 0; o < g.longueur*2+1; o++) {
			if (o < g.longueur)
				cout << " ___";
			else if(o == g.longueur)
				cout << endl;
			else {
				if (position >= g.largeur * g.longueur)
					return;
				cout<<"| " << g.tab[position / g.longueur][position % g.longueur] << " ";
				++position;
			}
		}
		cout << "|"<< endl;
	}
}
//---------------------------------VERIFICATION DE LA GRILLE--------------------------------------------------------
bool estValide(const Position& position, unsigned int longueur, unsigned int largeur) {
	return !(position.abs < 0 || position.abs >= longueur || position.ord < 0 || position.ord >= largeur);
}
bool isMine(const Probleme& probleme, const Position& position) {
	for (unsigned int i = 0; i < probleme.nbMine; ++i) {
		if ((position.abs == probleme.tabMine[i] % probleme.longueur) && (position.ord == probleme.tabMine[i] / probleme.longueur))
			return true;
	}
	return false;
}

bool isWin(const Grille& grille, unsigned int nbBombe) {
	unsigned int N = grille.longueur * grille.largeur;
	for (int i = 0; i < N; ++i){
		if (grille.tab[i / grille.longueur][i % grille.longueur] == '.' || grille.tab[i / grille.longueur][i % grille.longueur] == 'm')
			return false;
	}
	return true;
}
bool isLose(const Coup& coup, const Probleme& probleme) {
	if (coup.type == 'D') {
		for (unsigned int i = 0; i < probleme.nbMine; i++) {
			if (coup.position == probleme.tabMine[i])
				return true;
		}
		return false;
	}
	for (unsigned int i = 0; i < probleme.nbMine; i++) {
		if (coup.position == probleme.tabMine[i])
			return false;
	}
	return true;
}

