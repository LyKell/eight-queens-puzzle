/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 08-04-2019 */

#ifndef __ECHIQUIER__
#define __ECHIQUIER__

/* Inclusion des bibliotheques et autres fichiers necessaires */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Definition des structures */
typedef enum {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
}Case;
typedef unsigned long long Position;

/* Definition des constantes */
Position tab_cases_attaquees[64];

/* Definition des fonctions */

/*
BUT		Change le bit en position i à 1. Les bits commencent à 0, donc on change le bit n°(i-1)
PARAM	Position pos : L'adresse de la position de jeu actuelle
		int i : La position du bit à changer
RETOUR	void
*/
void allume_bit(Position *pos, int i);
/*
BUT		Change le bit en position i à 0. Les bits commencent à 0, donc on change le bit n°(i-1)
PARAM	Position pos : L'adresse de la position de jeu actuelle
		int i : La position du bit à changer
RETOUR	void
*/
void eteind_bit(Position *pos, int i);
/*
BUT		Afficher la position de jeu pos actuelle
PARAM	Position pos : La position de jeu actuelle
RETOUR	1 : Affichage réussi
*/
int afficher_position(Position pos);
/*
BUT		Fonction permettant d'allumer les cases attaquables par la dame en c
PARAM	Position *pos : L'adresse de la position que l'on veut modifier
		Case c : La position de la dame
RETOUR	1 : Calcul effectué sans problème
*/
int calculer_cases_attaquees(Position *pos, Case c);
/*
BUT		Fonction permettant d'allumer les cases verticales attaquables par la dame en c
PARAM	Position *pos : L'adresse de la position que l'on veut modifier
		int place : La case que l'on veut allumer
		Case c : La position de la dame
RETOUR	1 : La case est attaquable
		0 : La case n'est pas attaquable
*/
int attaquer_verticale(Position *pos, int place, Case c);
/*
BUT		Fonction permettant d'allumer les cases horizontales attaquables par la dame en c
PARAM	Position *pos : L'adresse de la position que l'on veut modifier
		int place : La case que l'on veut allumer
		Case c : La position de la dame
RETOUR	1 : La case est attaquable
		0 : La case n'est pas attaquable
*/
int attaquer_horizontale(Position *pos, int place, Case c);
/*
BUT		Fonction permettant d'allumer les cases diagonales nord_ouest et sud_est attaquables par la dame en case c
PARAM	Position *pos : L'adresse de la position que l'on veut modifier
		int place : La case que l'on veut allumer
		Case c : La position de la dame
RETOUR	1 : La case est attaquable
		0 : La case n'est pas attaquable
*/
int attaquer_diag_no_se(Position *pos, int place, Case c);
/*
BUT		Fonction permettant d'allumer les cases diagonales nord_ouest et sud_est attaquables par la dame en case c
PARAM	Position *pos : L'adresse de la position que l'on veut modifier
		int place : La case que l'on veut allumer
		Case c : La position de la dame
RETOUR	1 : La case est attaquable
		0 : La case n'est pas attaquable
*/
int attaquer_diag_se_no(Position *pos, int place, Case c);
/*
BUT		Fonction permettant d'initialiser la liste des positions contenant les cases attaquables par chaque dame
PARAM	void
RETOUR	void
*/
void initialiser_cases_attaquees();
/*
BUT		Fonction permettant de vérifier si des dames peuvent mutuellement s'attaquer
PARAM	Position pos : La position de jeu actuelle
RETOUR	1 : Aucune dame ne s'attaque
		0 : Plusieurs dames s'attaquent
*/
int est_sans_attaque_mutuelle(Position pos);

#endif
