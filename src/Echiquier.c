/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 08-04-2019 */

/* Inclusion du fichier necessaire */
#include "Echiquier.h"


void allume_bit(Position *pos, int i) {
	Position bit = 1;
	assert(pos != NULL);
	*pos |= (bit << i);
}



void eteind_bit(Position *pos, int i) {
	Position bit = 1;
	assert(pos != NULL);
	*pos &= ~(bit << i);
}



int afficher_position(Position pos) {
	int i, j;
	Position bit, lecture;

	bit = 1;
	for (j = 7; j >= 0; --j) {
		for (i = 0; i < 8; ++i) {
			lecture = pos & (bit << (i + (j * 8)));
			if (lecture) {
				printf("+ ");
			} else {
				printf("- ");
			}
		}
		printf("\n");
	}
	return 1;
}



int calculer_cases_attaquees(Position *pos, Case c) {
	int i;
	assert(pos != NULL);
	assert(c >= A1);
	assert(c <= H8);
	*pos = 0;

	for (i = 1; i < 8; i++) {
		attaquer_verticale(pos, c + 8*i, c);	/* Vers le haut */
		attaquer_verticale(pos, c - 8*i, c);	/* Vers le bas */

		attaquer_horizontale(pos, c + i, c);	/* Vers la droite */
		attaquer_horizontale(pos, c - i, c);	/* Vers la gauche */

		attaquer_diag_no_se(pos, c + 7*i, c);	/* Vers le nord-ouest */
		attaquer_diag_no_se(pos, c - 7*i, c);	/* Vers le sud-est */

		attaquer_diag_se_no(pos, c + 9*i, c);	/* Vers le nord-est */
		attaquer_diag_se_no(pos, c - 9*i, c);	/* Vers le sud-ouest */
	}

	return 1;
}



int attaquer_verticale(Position *pos, int place, Case c) {
	assert(pos != NULL);
	assert(c >= A1);
	assert(c <= H8);
	if (place % 8 == c % 8 && place >= A1 && place <= H8) {
		allume_bit(pos, place);
		return 1;	/* Succès */
	}
	return 0;	/* Echec */
}




int attaquer_horizontale(Position *pos, int place, Case c) {
	assert(pos != NULL);
	assert(c >= A1);
	assert(c <= H8);
	if (place / 8 == c / 8 && place >= A1 && place <= H8) {
		allume_bit(pos, place);
		return 1;	/* Succès */
	}
	return 0;	/* Echec */
}




int attaquer_diag_no_se(Position *pos, int place, Case c) {
	assert(pos != NULL);
	assert(c >= A1);
	assert(c <= H8);
	if (place % 8 + place / 8 == c % 8 + c / 8 && place >= A1 && place <= H8) {
		allume_bit(pos, place);
		return 1;	/* Succès */
	}
	return 0;	/* Echec */
}




int attaquer_diag_se_no(Position *pos, int place, Case c) {
	assert(pos != NULL);
	assert(c >= A1);
	assert(c <= H8);
	if (place % 8 - place / 8 == c % 8 - c / 8 && place >= A1 && place <= H8) {
		allume_bit(pos, place);
		return 1;	/* Succès */
	}
	return 0;	/* Echec */
}




void initialiser_cases_attaquees() {
	int i;
	for (i = A1; i <= H8; i++) {
		calculer_cases_attaquees(&tab_cases_attaquees[i], i);
	}
}




int est_sans_attaque_mutuelle(Position pos) {
	Position attaque, preattaque, bit;
	int i;

	bit = 1;
	attaque = 0;

	for (i = A1; i <= H8; i++) {
		if (pos & (bit << i)) {	/* On vérifie si le bit en position i est à 1 */
			preattaque = attaque;
			attaque |= tab_cases_attaquees[i];	/* On rajoute les cases attaquables par la nouvelle dame */

			if ((pos & (bit << i)) & (attaque & (bit << i))) {	/* On vérifie si la nouvelle dame peut se faire attaquer */
				attaque = preattaque;	/* On récupère les cases attaquables avant l'ajout de la dame */
				return 0;
			}
		}
	}
	return 1;
}
