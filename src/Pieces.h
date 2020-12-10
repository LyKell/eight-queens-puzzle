/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 08-04-2019 */

#ifndef __PIECES__
#define __PIECES__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Echiquier.h"

/* Definition des structures */

/* Definition des constantes */

/* Definition des fonctions */
/*
BUT		Vérifie si une case est occupée ou non
PARAM	Position pos : La position de jeu actuelle
		Case c : La case que l'on veut vérifier
RETOUR	0 : La case est occupée
		1 : La case est libre
*/
int est_case_occupee(Position pos, Case c);
/*
BUT		Place une dame sur la position de jeu *pos, à la case c
PARAM	Position *pos : L'adresse de la position de jeu actuelle
		Case c : La case à laquelle on veut placer la dame
RETOUR	0 : La case est déjà
		1 : La case est libre
*/
int placer_dame_position(Position *pos, Case c);


#endif
