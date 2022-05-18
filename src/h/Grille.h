#ifndef _GRILLE_
#define _GRILLE_

#include "Pile.h"
#include "Historique.h"
#include "Probleme.h"

/**
 * @file Grille.h
 * MineSweepers
 * @author Maël Chanon, Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief initialisation, affichage et vérification d'une grille
 */

struct Grille {
	unsigned int longueur; // longueur de la grille 
	unsigned int largeur; // largeur de la grille
	char** tab;	//la grille
};


/**
 * @brief initalise les parametres d'une grille
 * La Grille est allouée en mémoire dynamique 
 * @see détruire le tableau en fin d'utilisation
 * @return une grille
 */
Grille initGrille(int i);

/*@brief enregistre une grille rentrée au clavier
*  * @see détruire le tableau en fin d'utilisation
* @return une Grille
*/
Grille enregistrerGrille();

/**
 * @brief initalise un tableau en 2 dimentions 
 * Le tableau est alloué en mémoire dynamique selon la longueur et la largueur de la grille
 * @see détruire le tableau en fin d'utilisation
 * @param[in-out] grille : une référence vers une grille
 */
void initTableau2D(Grille& grille);

/**
 * @brief détruit le tableau d'une grille
 * @param[in-out] grille : une référence vers une grille
 */
void detruireTableau2D(Grille& grille);

/**
 * @brief enregistre les différents coups et verifie leurs validités
 * @param[in-out] grille : une référence vers une grille
 * @param[in] probleme : la référence vers un probleme
 * @param[in] historique : référence vers un historique
 */
void definirCoups(Grille& grille, const Probleme& probleme, const Historique& historique);

/**
 * @brief remplie la grille selon un histoirique de coups et un problème
 * Le tableau est alloué en mémoire dynamique selon la longueur et la largueur de la grille
 * @param[in-out] grille :  référence vers une grille
 * @param[in-out] p :  référence vers une pile de coups 
 * @param[in] historique :  référence vers un historique des coups
 * @param[in] probleme :  référence vers un probleme
 */
void remplirGrille(Grille& grille, Pile& p, const Historique& historique, const Probleme& probleme);

/**
 * @brief renvoie les position autours d'une case
 * @param[in] position : reférence versune position
 * @see penser à désalouer le tableau en fin d'utilisation
 * @return pointeur d'un tableau vers une position
 */
Position* caseAutour(const Position& position);

/**
 * @brief marque une case de la grille 
 * @param[in-out] grille : référence sur une grille
 * @param[in] position : référence vers une position valide
 * @param[in] compteur : renseigne sur l'état de la case
 */
void marquerCase(Grille& grille, const Position& position, int compteur);
/**
 * @brief affiche toute la grille
 * @param[in] g : référence sur une grille
 */
void affichageGrille(const Grille& g);

/**
 * @brief remplace les cases de la grille par les mines du problème
 * @param[in-out] grille : référence vers une grille
 * @param[in] probleme : référence vers un problème
 */
void placerMines(Grille& grille, const Probleme& probleme);

 /**
  * @brief determine si une case se trouve dans les limites de la grille
  * @param[in] position : reférence vers une position
  * @param[in] longueur : longueur de la grille
  * @param[in] largeur : largeur de la grille
  * @return True si la Position est valide, sinon False
  */
bool estValide(const Position& position, unsigned int longueur, unsigned int largeur);

/**
 * @brief dit si une position de la grille est une mine
 * @param[in] probleme : la référence vers un probleme
 * @param[in] position : une position
 * @return True si position est une mine false si elle n'est pas une mine
 */
bool isMine(const Probleme& probleme, const Position& position);

/**
 * @brief determine si une partie est gagnée
 * @param[in] grille : référence vers une Grille
 * @param[in] nbMine : le nombre de Mines
 * @return true si la partie est gagnée, sinon false
 */
bool isWin(const Grille& grille, unsigned int nbMines);
/**
 * @brief determine si une partie est perdue 
 * @param[in] coup : référence vers un type de coup
 * @param[in] probleme : reférence vers un probleme
 * @return true si la partie est perdue, sinon false
 */
bool isLose(const Coup& coup, const Probleme& probleme);

#endif


