/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 08-04-2019 */

/* Inclusion des bibliotheques et fichiers nécessaires */
#include <stdlib.h>
#include <stdio.h>
#include <MLV/MLV_all.h>
#include "Pieces.h"
#include "IGraph.h"

/*
BUT		Fonction contenant la boucle principale du programme.
PARAM	void
RETOUR	0 : La partie est perdue mais le programme n'a pas échoué.
        EXIT_SUCCESS : Le programme s'est déroulé sans accroc
*/
int main(void){
    int nb_pieces_posees = 0, val_retour;
    Case case_choisie;
    Position pos = 0;

    initialiser_cases_attaquees();

    MLV_create_window("Dames", "Dames", TAILLE_FENETRE_X, TAILLE_FENETRE_Y);
    while (nb_pieces_posees < 8){
        dessiner_plateau();
        dessiner_position(pos);
        case_choisie = detecter_clic();
        val_retour = placer_dame_position(&pos, case_choisie);
        if (val_retour == 0){
            signaler_placement_impossible();
            return 0;
        }
        nb_pieces_posees += 1;
    }
    dessiner_plateau();
    dessiner_position(pos);
    signaler_victoire();

    return EXIT_SUCCESS;
}
