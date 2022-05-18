/**
 * @file Position.cpp
 * @author l'équipe pédagogique 
 * @version 1 19/12/05
 * @brief Projet sem04-tp-Cpp3 - Composant de positions sur une grille
 * Structures de données et algorithmes - DUT1 Paris 5
 */

#include "Position.h"

#include <iostream>
#include <cassert>
using namespace std;



Position numberToPosition(unsigned int number, unsigned int longueur) {
	Position p;
	p.ord = number / longueur;
	p.abs = number % longueur;

	return p;
}
unsigned int positionToNumber(const Position& position, unsigned int longueur) {
	return position.abs + position.ord * longueur;
}