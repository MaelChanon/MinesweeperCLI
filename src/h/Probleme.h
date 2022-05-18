#ifndef _PROBLEME_
#define _PROBLEME_

/**
 * @file Probleme.h
 * MineSweepers
 * @author Ma�l Chanon,Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief initialisation, affichage d'un probleme
 */
struct Probleme {
	unsigned int longueur; //longueur du probleme
	unsigned int largeur; //largeur du probleme
	unsigned int nbMine; //nombre de mines
	unsigned int* tabMine; //tableau de mines
};
/**
* @brief initialiser un problemes
* @see detruire le tableau de mines
* @return un probleme
*/
Probleme initPB();

/**
* @brief produit des positions de mines al�atoirement
* @param[in-out] probleme : r�f�rence vers un probleme
* @param[in] N : la borne maximale(exclue) des mines
*/
void randomBombGenerator(Probleme& probleme, unsigned int N);
/**
* @brief affiche un probleme
* @param[in] probleme :  r�f�rence vers un probleme
*/
void afficherProbleme(const Probleme& probleme);

/**
* @brief detruit le tableau de mines d'un probleme
* @param[in-out] probleme : r�f�rence vers un probleme
*/
void detruireProbleme(Probleme& probleme);

/**
* @brief permet � l'utilisateur de saisir des mines au clavier
* @param[in-out] probleme : r�f�rence vers un probleme
*/
void saisirMines(Probleme& probleme);

#endif
