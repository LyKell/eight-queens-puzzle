/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 08-04-2019 */

/* Inclusion du fichier necessaire */
#include "IGraph.h"

void dessiner_plateau(void){
    int i, j;

    MLV_draw_filled_rectangle(0, 0, TAILLE_FENETRE_X, TAILLE_FENETRE_Y, MLV_COLOR_WHITE);

    for(i = 0; i < NB_CASES_LIGNE; i++){
        for (j = 0; j < NB_CASES_LIGNE; j++){
            if ((i+j)%2 == 0){
                MLV_draw_filled_rectangle((i*TAILLE_CASE)+20, j*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE, MLV_COLOR_WHITE);
            }
            else {
                MLV_draw_filled_rectangle((i*TAILLE_CASE)+20, j*TAILLE_CASE, TAILLE_CASE, TAILLE_CASE, MLV_COLOR_GREY);
            }
        }
    }

    /* Dessin des positions de l'échiquier */
    i = 10;
    j = TAILLE_FENETRE_Y-15;

    MLV_draw_text(60, j,"a", MLV_COLOR_BLACK);
    MLV_draw_text(160, j, "b", MLV_COLOR_BLACK);
    MLV_draw_text(260, j, "c", MLV_COLOR_BLACK);
    MLV_draw_text(360, j, "d", MLV_COLOR_BLACK);
    MLV_draw_text(460, j, "e", MLV_COLOR_BLACK);
    MLV_draw_text(560, j, "f", MLV_COLOR_BLACK);
    MLV_draw_text(660, j, "g", MLV_COLOR_BLACK);
    MLV_draw_text(760, j, "h", MLV_COLOR_BLACK);

    MLV_draw_text(i, 50, "8", MLV_COLOR_BLACK);
    MLV_draw_text(i, 150, "7", MLV_COLOR_BLACK);
    MLV_draw_text(i, 250, "6", MLV_COLOR_BLACK);
    MLV_draw_text(i, 350, "5", MLV_COLOR_BLACK);
    MLV_draw_text(i, 450, "4", MLV_COLOR_BLACK);
    MLV_draw_text(i, 550, "3", MLV_COLOR_BLACK);
    MLV_draw_text(i, 650, "2", MLV_COLOR_BLACK);
    MLV_draw_text(i, 750, "1", MLV_COLOR_BLACK);

    MLV_actualise_window();
}

int detecter_clic(void){
    int i, j;
    int tab[8] = {7,6,5,4,3,2,1,0};

    MLV_wait_mouse(&i, &j);
    while (i < 20 || i > 820 || j < 0 || j > 800) {
        MLV_wait_mouse(&i, &j);
    }
    i  = ((i-20)/100);

    j  = tab[((j)/100)];

    return i+(j*8);
}


void dessiner_position(Position pos){
    int i, j;
    int tab[8] = {7,6,5,4,3,2,1,0};
    Position bit, lecture;
    MLV_Image *img;

    assert(pos >= 0);

    img = MLV_load_image("../images/queen.png");

    bit = 1;
    for (j = 7; j >= 0; --j) {
        for (i = 0; i < 8; ++i) {
            lecture = pos & (bit << (i + (j * 8)));
            if (lecture) {
                MLV_draw_image(img, (i*TAILLE_CASE)+20, tab[j]*TAILLE_CASE);
                MLV_actualise_window();
            }
        }
    }
}



void signaler_placement_impossible(void){
    MLV_draw_text(330, 360, "Défaite : Placement impossible !", MLV_COLOR_RED);
    MLV_actualise_window();
    MLV_wait_seconds(2);
}


void signaler_victoire(void){
    MLV_draw_text(340, 360, "Victoire !", MLV_COLOR_GREEN);
    MLV_actualise_window();
    MLV_wait_seconds(2);
}
