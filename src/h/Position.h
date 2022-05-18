#ifndef _POSITION_
#define _POSITION_

/**
 * @file Position.h
 * @author l'équipe pédagogique 
 * @version 1 19/12/05
 * @brief Projet sem04-tp-Cpp3 - Composant de positions sur une grille
 * Structures de données et algorithmes - DUT1 Paris 5
 */
 
/**
 * @brief Type position
 * invariant : la position doit être valide
 */
struct Position {
     int abs; // abscisse de la position
     int ord; // ordonnée de la position
};

/**
 * @Brief transforme un nombre en une position
 * @param[in] number : un nombre
 * @param[in] longueur : une longueur
 * @return une position
 */
Position numberToPosition(unsigned int number, unsigned int longueur);

/**
 * @Brief transforme une position en un nombre
 * @param[in] position : une position
 * @param[in] longueur : la longueur de la grille
 * @return une position sous la forme d'un nombre
 */
unsigned int positionToNumber(const Position& position, unsigned int longueur);



#endif
