/**
 * @file Probleme.cpp
 * MineSweepers
 * @author Maël Chanon,Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief initialisation, affichage d'un probleme
 */
#include "Probleme.h"
#include <cassert>
#include <time.h>
#include <iostream>
#include <ctime>
using namespace std;


Probleme initPB() {

	Probleme probleme;
	cin >> probleme.largeur;
	cin >> probleme.longueur;
 	cin >> probleme.nbMine;

	unsigned int N = probleme.longueur * probleme.largeur;
	probleme.tabMine = new unsigned int[probleme.nbMine];
	return probleme;
}

void randomBombGenerator(Probleme& probleme, unsigned int N) {
	srand(time(NULL));
	int save = 0;
	int randomNumber = 0;
	unsigned int compteur = 0;
	int* tab = new int[N];
	for (unsigned int i = 0; i < probleme.nbMine; ++i) {
		tab[i] = 1;
	}
	//on permute les différentes positionss
	for (unsigned int i = 0; i < 10*N; ++i) {
		randomNumber = rand() % N;
		save = tab[i % N];
		tab[i % N] = tab[randomNumber];
		tab[randomNumber] = save;
	}
	for (unsigned int i = 0; i < N; ++i) {
		if (tab[i] == 1) {
			probleme.tabMine[compteur] = i;
			compteur++;
		}
	}
	delete[] tab;
}

void afficherProbleme(const Probleme& probleme) {
	cout << probleme.largeur<< ' '<< probleme.longueur << ' '<< probleme.nbMine << ' ';
	for (unsigned int i = 0; i < probleme.nbMine; ++i) {
		cout << probleme.tabMine[i] << ' ';
	}
	cout << endl;
}
	
void detruireProbleme(Probleme& probleme) {
	delete[] probleme.tabMine;
}
void saisirMines(Probleme& probleme) {
	for (unsigned int i = 0; i < probleme.nbMine; ++i)
		cin >> probleme.tabMine[i];
}