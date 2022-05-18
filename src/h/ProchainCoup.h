#ifndef _COUP_
#define _COUP_
#include "Grille.h"
/**
 * @file ProchainCoup.h
 * MineSweepers
 * @author Maël Chanon, Lionel Leguier
 * @version 1 - 28/12/2021
 * @brief génération d'un prochain coup
 */

/**
 * @brief retourne un prochain coup valide
 * @param[in] grille : reférence vers une Grille
 * @return un coup valide
 */
Coup prochainCoup(const Grille& grille);


/**
 * @brief retourne une position d'une case libre
 * @param[in] grille : reférence vers une Grille
 * @param[in] tabPosition : pointeur sur un tableau de positions
 * @param[in] MineAutours : nombre de mines autours d'une case
 * @return -1 si aucune case libre n'a été détéctée, sinon retourne la position de la case
 */
int obviousMine(const Grille& grille,const Position* tabPosition, int MineAutours);

/**
 * @brief retourne une position d'une case libre
 * @param[in] grille : reférence vers une Grille
 * @param[in] tabPosition : pointeur sur un tableau de positions
 * @param[in] MineAutours : nombre de mines autours d'une case
 * @return -1 si aucune case libre n'a été détéctée, sinon retourne la position de la case
 */
int obviousBox(const Grille& grille, const Position* tabPosition, int MineAutours);

/**
 * @brief retourne aléatoirement la position d'une case valide
 * @param[in] grille : reférence vers une Grille
 * @return un coup valide
 */
Coup randomWay(const Grille& grille);


#endif
