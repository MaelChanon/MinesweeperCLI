#ifndef _Historique_
#define _Historique_


/**
 * @file Historique.h
 * MineSweepers
 * @author Maël Chanon,Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief Initialisation et affichage d'un historique
 */

struct Coup {
	char type; //le type du coup (M ou D)
	int position; //la position
};

struct Historique {
	unsigned int nbCoups; //le nombre de coups
	Coup* listeDesCoups; //la liste des coups
};

/**
 * @brief initalise un histoirique 
 * la liste est alloué dynamiquement 
 * @see detruire le tableau, pour une désallocation en fin d’utilisation
 * @return un historique
 */
Historique initHistorique();

/**
 * @brief detruit le tableau d'un historique
 * @param[in-out] historique : un pointeur vers un historique
 */
void detruireHistorique(Historique& historique);

/** @brief affiche un coup
* @param[in] coup : référence vers un coup
*/
void afficherCoup(const Coup& coup);

#endif
