/* Auteurs : Kevin SAVANE et Tom REDON
 * Creation : 26-03-2019
 * Modification : 26-03-2019 */

/* Inclusion des bibliotheques */
#include <stdlib.h>
#include <stdio.h>


void affichebin(unsigned int val, int taille_bits){
    int i;
    unsigned int bit;

	for (i = taille_bits-1; i >= 0 ; --i){
		bit = (val >> i) & 1;
		printf("%d", bit);
	}
    printf("\n");
}


/*
Fonction principale contenant les lignes de réponse à l'exercice 2 du TP5.
Ne prend pas de paramètre.
Retourne 1 si tout s'est bien passé.
*/
int main(void){
    int valeur, x, y, i, nb_bits = sizeof(int)*8;

    printf("Choisissez les valeurs à utiliser au fil de l'exercice (sauf pour les 2 premières questions) : ");
    scanf("%d %d", &x, &y);

    printf("\nQuestion 1 : \n");
    valeur = (1 << 14);
    affichebin(valeur, nb_bits);

    printf("\n\nQuestion 2 :\n");
    valeur = ~(1 << 13);
    affichebin(valeur, nb_bits);

    printf("\n\nQuestion 3 : \n");
    valeur = (x) | (1 << 12);
    affichebin(x, nb_bits);
    affichebin(valeur, nb_bits);

    printf("\n\nQuestion 4 : \n");
    valeur = x & ~(1 << 11);
    affichebin(x, nb_bits);
    affichebin(valeur, nb_bits);

    printf("\n\nQuestion 5 : \n");
    affichebin(x, nb_bits);
    if ((x & (1 << 10))){
        printf ("bit 11 = 1\n");
    }

    printf("\n\nQuestion 6 : \n");
    affichebin(x, nb_bits);
    for (i = 0; i < 3; i++){
        if ((x & (1 << i))){
            printf ("bit %d = 1\n", i+1);
        }
    }

    printf("\n\nQuestion 7 : \n");
    affichebin(x, nb_bits);
    for (i = 0; i < 4; i++){
        if ((x & (1 << i)) == 0){
            printf ("bit %d = 0\n", i+1);
        }
    }

    printf("\n\nQuestion 8 : \n");
    affichebin(x, nb_bits);
    affichebin(y, nb_bits);
    if (((y & (1 << 9)) ^ (x & (1 << 9))) == 0){
        printf ("Les bits 10 sont égaux\n");
    }
    else {
        printf("Les bits 10 ne sont pas égaux\n");
    }
    /* Question 9 */
    printf("\n\nQuestion 9 : \n");
    affichebin(x, nb_bits);
    affichebin(y, nb_bits);
    for (i = 0; i < nb_bits; i++){
        if (((y & (1 << i)) & (x & (1 << i)))){
            printf("bit %d à 1\n", i+1);
            break;
        }
    }
    /* Question 10 */
    printf("\n\nQuestion 10 : \n");
    affichebin(x, nb_bits);
    affichebin(y, nb_bits);
    for (i = 0; i < nb_bits; i++){
        if (((y & (1 << i)) ^ (x & (1 << i)))){
            printf("Tous les bits ne sont pas égaux");
            break;
        }
    }
    if (i == nb_bits){
        printf("Tous les bits sont égaux\n");
    }
    /* Question 11 */
    printf("\n\nQuestion 11 : \n");
    affichebin(x, nb_bits);
    affichebin(y, nb_bits);
    for (i = 0; i < nb_bits; i++){
        if (((y & (1 << i)) ^ (x & (1 << i))) == 0){
            printf("Deux bits sont égaux\n");
            break;
        }
    }
    if (i == nb_bits){
        printf("Tous les bits sont différents\n");
    }
    printf("\n");
    return 1;
}
