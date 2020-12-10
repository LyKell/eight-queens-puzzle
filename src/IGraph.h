/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 08-04-2019 */

#ifndef __IGRAPH__
#define __IGRAPH__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <stdio.h>
#include <stdlib.h>
#include <MLV/MLV_all.h>
#include "Pieces.h"
#include "Echiquier.h"

/* Definition des structures */

/* Definition des constantes */
#define TAILLE_FENETRE_X 820
#define TAILLE_FENETRE_Y 820
#define NB_CASES_LIGNE 8
#define TAILLE_CASE 100

/* Definition des fonctions */
/*
BUT		Affiche le plateau vide et les indices de a à h et de 1 a 8 pour les cases.
PARAM	void
RETOUR	void
*/
void dessiner_plateau(void);
/*
BUT		Détecte le clic de l'utilisateur sur la fenêtre
        et renvoie la position du clic dans la structure Position
PARAM	void
RETOUR	La valeur de la position du clic.
*/
int detecter_clic(void);
/*
BUT		Dessine la position du jeu actuelle
PARAM	Position pos : L'adresse de la position de jeu actuelle
RETOUR	void
*/
void dessiner_position(Position pos);
/*
BUT		Affiche sur l'écran la défaite du joueur lorsqu'il essaye d'effectuer un
        placement impossible
PARAM	void
RETOUR	void
*/
void signaler_placement_impossible(void);
/*
BUT		Affiche sur l'écran la victoire du joueur lorsqu'il a rempli les conditions
        de victoire
PARAM	void
RETOUR	void
*/
void signaler_victoire(void);

#endif
