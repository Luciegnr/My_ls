#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"

void _ls(const char *dir, int op_a) {
    struct dirent *d; 
    DIR *dh = opendir(dir);/*Ouvrir le repertoire*/

    while ((d = readdir(dh)) != NULL) { /*Lecture du répertoire*/

        if(!op_a && d->d_name[0] == '.')continue;
        {
            my_putstr(d->d_name); /*Affiche tout les nom des fichier */
            my_putchar('\n'); /*Retour a la ligne */
        }
    }
}

void _ls_A(const char *dir) {
    int count= 0;
    struct dirent *d;
    DIR *dh = opendir(dir); /*Ouvrir le repertoire*/

    while ((d = readdir(dh)) != NULL) { /*Lecture du répertoire*/
        count = 0; 
        while(d->d_name[count] != 0) { /*Compte le nombre de char du nom fichier*/
            count++; /*Incrémente de 1 */
        }
               if((d->d_name[0] == '.' && count == 1) || (d->d_name[0] == '.' && d->d_name[1] == '.' && count == 2)) {/*Verif si nom fichier = . ou .. si oui pas afficher */
        } else {
            my_putstr(d->d_name); /*Affiche tout les nom des fichier */
            my_putchar('\n'); /*Retour a la ligne */
        }
    }
}


int main(int argc, char *argv[]) {
    char *chemin = ".";
    int list = 1;
    int opt;

    if(argc == 1) {
        _ls(chemin, 0); /*Fonction lancer ls*/
    } else {
        while(argv[list] != 0) {/*Parcours la list*/
            if(argv[list] [0] != 45) { /*Verif pour pas prendre option en chemin*/
                chemin = argv[list]; 
            }
            list++; /*Incrémente de 1 */                                                                                                                                                                }

        if(argv[1][0] == '-') {
            while ((opt = getopt(argc, argv, "aAd")) !=-1) { /*Choix option*/
                switch (opt) {
                case 'a':
                    _ls(chemin, 1);
                    return 0;
                case 'A':
                    _ls_A(chemin);
                    return 0;
                case 'd':
                    my_putstr(chemin); /*Affiche tout les nom des fichier */
                    my_putchar('\n'); /*Retour a la ligne */
                    return 0;
                }
            }
        }
        _ls(chemin, 0);  
                return 0;
    }
}