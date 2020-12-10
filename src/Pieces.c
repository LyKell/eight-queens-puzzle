/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 08-04-2019 */

/* Inclusion du fichier necessaire */
#include "Pieces.h"


int est_case_occupee(Position pos, Case c) {
	Position bit = 1;
	if ((pos & (bit << c)) == 0) {
		return 1;	/* Case libre */
	}
	return 0;	/* Case occupée */
}




int placer_dame_position(Position *pos, Case c) {
	assert(pos != NULL);
	assert(c >= A1);
	assert(c <= H8);
	Position *tmp;
	tmp = pos;
	if (est_case_occupee(*pos, c)) {
		allume_bit(pos, c);	/* On change le bit à la position c */

		if (est_sans_attaque_mutuelle(*pos)) {
			return 1;	/* Placement d'une dame réussi */
		}
	}
	pos = tmp;
	return 0;	/* Placement d'une dame échoué */
}
