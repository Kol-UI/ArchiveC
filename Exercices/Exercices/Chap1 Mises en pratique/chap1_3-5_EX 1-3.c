/*
*   Pour tester la solution d'un exercice il faut :
*   - faire un projet c en mode console
*   - copier le code correspondant dans le fichier c
*   - compiler et exécuter
*
*   ou
*   - copier tous dans le fichier c du projet
*   - enlever le commentaires de l'exercice à tester
*   - mettre en commentaire tous les autres
*   - compiler et exécuter
*/
/********************************************************************
*   Chapitre 1 : Variables simples                                  *
*   3. Les opérations                                               *
*   3.5 Mise en pratique : oopérations et nombres aléatoires        *
*********************************************************************


/************************************
Exercice 1
Choisissez pile ou face dans votre tête, lancer un programme qui
annonce au hasard 0 pour face et 1 pour pile... gagné ?
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    printf("choisissez pile ou face puis lancer\n");

    system("PAUSE");

    printf("%d",rand()%2);

    return 0;
}



/************************************
Exercice 2
Choisissez dans votre tête un nombre entre 2 et 12 et lancer votre programme
qui simule un tirage avec deux dés à six faces... gagné ?
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    printf("choisissez un nombre entre 2 et 12 puis lancer\n");

    system("PAUSE");

    printf("%d",2+rand()%11);
    return 0;
}

/************************************
Exercice 3
Ecrire un programme qui génère et affiche 7 nombres aléatoires selon les
contraintes suivantes :
afficher un nombre aléatoire selon la plage maximum du générateur aléatoire.
afficher une valeur aléatoire comprise entre 0 et 367
afficher un nombre aléatoire compris entre 0 et une valeur "seuil haut" entrée par
l'utilisateur
afficher un nombre aléatoire compris entre 678 et 7354
afficher un nombre aléatoire compris entre une valeur seuil bas et une valeur
seuil haut entrées par l'utilisateur
afficher un nombre aléatoire compris entre 0 et 1
afficher un nombre aléatoire à deux décimales compris entre 0 et 50
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
int sh,sb;
    srand(time(NULL));

    printf("%d\n",rand());

    printf("%d\n",rand()%367);

    printf("entrer seuil haut : ");
    scanf("%d",&sh);
    printf("%d\n",rand()%sh);

    printf("%d\n",678+rand()%(7354-678));

    printf("entrer seuil haut : ");
    scanf("%d",&sh);
    printf("entrer seuil bas : ");
    scanf("%d",&sb);
    printf("%d\n",sb+rand()%(sh-sb));

    printf("%f\n", (float)rand()/RAND_MAX);

    printf("%.2f",(rand()%5000)/100.0);

    return 0;
}
/*********************************
*/

