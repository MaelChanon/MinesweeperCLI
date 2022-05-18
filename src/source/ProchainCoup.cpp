/**
 * @file ProchainCoup.cpp
 * MineSweepers
 * @author Maël Chanon, Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief génération d'un prochain coup
 */
#include "ProchainCoup.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;

Coup prochainCoup(const Grille& grille) {
	char valCase;
	Position* tabPostion;
	unsigned int MineAutours;
	Coup coupRetours;

	for (unsigned int i = 0; i < grille.longueur * grille.largeur; ++i) {
		valCase = grille.tab[i / grille.longueur][i % grille.longueur];
		//on ne regarque que les cases avec des mines autours
		if (valCase != '.' && valCase != ' ' && valCase != 'x') {
			sscanf_s(&valCase, "%d", &MineAutours);
			tabPostion = caseAutour(numberToPosition(i, grille.longueur));
			//pour une case i on regarde si on peut deminer après si on peut marquer
			coupRetours.position = obviousBox(grille, tabPostion, MineAutours);
			if (coupRetours.position != -1) {
				delete[] tabPostion;
				coupRetours.type = 'D';
				cout << i << endl;
				return coupRetours;
			}

			coupRetours.position = obviousMine(grille, tabPostion, MineAutours);
			if (coupRetours.position != -1) {
				delete[] tabPostion;
				coupRetours.type = 'M';
				return coupRetours;
			}
			delete[] tabPostion;
		}	
	}
	return randomWay(grille);
}

int obviousMine(const Grille& grille, const Position* tabPosition, int MineAutours) {
	unsigned int compteurMine = 0;
	unsigned int compteurCaseVide = 0;
	Position p;

	for (unsigned int i = 0; i < 8; ++i) {
		if (estValide(tabPosition[i], grille.longueur, grille.largeur)) {
			if (grille.tab[tabPosition[i].ord][tabPosition[i].abs] == 'x') {
				++compteurMine;
				continue;
			}
			if (grille.tab[tabPosition[i].ord][tabPosition[i].abs] == '.') {
				p = tabPosition[i];
				++compteurCaseVide;
				continue;
			}
		}
	}
	//si les mines n'ont pas toutes été posées et que il reste autant de cases libres que de mines à poser
	if (MineAutours - compteurMine != 0 && MineAutours - compteurMine == compteurCaseVide)  
		return positionToNumber(p, grille.longueur);
	return -1;
}

int obviousBox(const Grille& grille,const Position* tabPosition, int MineAutours) {
	unsigned int compteurMine = 0;
	Position p;
	bool isFree = false; //pour voir si il y a une case libre autours
	for (unsigned int i = 0; i < 8; ++i) {
		if (estValide(tabPosition[i], grille.longueur, grille.largeur)) {
			if (grille.tab[tabPosition[i].ord][tabPosition[i].abs] == 'x') {
				++compteurMine;
				continue;
			}
			if (grille.tab[tabPosition[i].ord][tabPosition[i].abs] == '.') {
				isFree = true;
				p = tabPosition[i];
				continue;
			}
		}
	}
	//si les toutes les cases n'ont pas été dévoilées et que il reste autant de cases que de mines à poser
	if (compteurMine == MineAutours && isFree)
		return positionToNumber(p, grille.longueur);
	return -1;
}

Coup randomWay(const Grille& grille) {
	unsigned int* tab = new unsigned int[grille.longueur * grille.largeur];
	Coup PositionRetours;
	unsigned int compteur = 0;
	srand(time(NULL));
	for(unsigned int i = 0; i< grille.longueur* grille.largeur;++i){
		if (grille.tab[i / grille.longueur][i % grille.longueur] == '.') {
			tab[compteur] = i;
			++compteur;
		}
	}
	PositionRetours.position = tab[rand() % compteur];
	delete[] tab;
	if (rand() % 2 == 0)
		PositionRetours.type = 'D';
	else
		PositionRetours.type = 'M';

	return PositionRetours;
}