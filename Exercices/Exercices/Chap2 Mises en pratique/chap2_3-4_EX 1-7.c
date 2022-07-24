/*
*   Pour tester la solution d'un exercice il faut :
*   - faire un projet c en mode console
*   - copier le code correspondant dans le fichier c
*   - compiler et exécuter
*
*   ou
*   - copier tous dans le fichier c du projet
*   - enlever le commentaires de l'exercice à tester mettre en commentaire tous les autres
    ( pour obtenir ce résultat il suffit de fermer le commentaire de l'énoncé de l'exercie
     à tester en laissant ouverts tous les autres)
*   - compiler et exécuter
*/
/********************************************************************
*   Chapitre 2 : Contrôles des blocs d'instruction                  *
*   3. Branchements                                                 *
*   3.4 Mise en pratique : l'aiguillage switch                      *
*********************************************************************/

/*********************************
Exercice 1   // pas de programme ici
Qu'imprime la séquence suivante :

scanf("%d", &choix);
switch( choix ){
	case 1 :  printf ("bonjour");  break;
	case 2 : printf ( "bonsoir");  break;
	default : printf ( "hello") ;  break;
}
Pour choix égal à 0, 1 et 3 ?

pour 0 et 3 "hello"
pour 1 "bonjour"


/*********************************
Exercice 2
Faire un programme qui affiche une phrase différente à chaque lancement.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
    srand(time(NULL));
    switch(rand()%5){  // inutile de stocker la valeur

        case 0 : printf("L'eau s'ecoulait\n");                              break;
        case 1 : printf("Les haies bruissaient\n");                         break;
        case 2 : printf("les amis ne savaient que faire apres la pluie\n"); break;
        case 3 : printf("de quoi sont nostalgiques les photographes\n");    break;
        case 4 : printf("sinon de lieux de personnages perdus d'avance\n"); break;
        // ...
    }

	return 0;
}
/*********************************
Exercice 3
Écrire un programme qui lit deux nombres entiers a et b et donne le choix à l'utilisateur :
1. de savoir si la somme de a+b est paire.
2. de savoir si le produit a*b est pair.
3. de connaître le signe de a-b;
4. de connaître le signe de a*b
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int a,b,choix;

    printf("entrer deux valeurs : ");
    scanf("%d %d",&a,&b);

    printf( "AU CHOIX :\n"
            "1. de savoir si la somme de a+b est paire.\n"
            "2. de savoir si le produit a*b est pair.\n"
            "3. de connaitre le signe de a-b\n"
            "4. de connaitre le signe de a*b\n");

    scanf("%d",&choix);
    switch(choix){
        case 1 :
            if((a+b)%2==0)
                printf("a+b est paire\n");
            else
                printf("a+b est impaire\n");
            break;
        case 2 :
            if((a*b)%2==0)
                printf("a*b est pair\n");
            else
                printf("a*b est impair\n");
            break;
        case 3 :
            if((a-b)>0)
                printf("a-b positif\n");
            else
                printf("a-b 0 ou negatif \n");
            break;
        case 4 :
            if((a*b)>0)
                printf("a*b positif\n");
            else
                printf("a*b 0 ou negatif\n");
            break;
        default :
                printf("commande inconnue\n");
            break;
    }

	return 0;
}
/*********************************
Exercice 4
Au lancement du programme le programme demande à l'utilisateur de se situer
par rapport à l'apprentissage du langage C : excellent, bien, honnête, mauvais,
horrible. En fonction de la réponse le programme propose une solution ou donne
un conseil.  Programmez.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int choix;
    printf( "En C vous vous considerez comme :\n"
            "1. excellent\n"
            "2. bon\n"
            "3. moyen\n"
            "4. mauvais\n"
            "5. horrible\n");

    scanf("%d",&choix);
    switch(choix){
        case 1 :
            printf("Faites des projets de plus haut niveau\n");
            break;
        case 2 :
            printf("essayer d'etre excellent\n");
            break;
        case 3 :
            printf("essayer d'etre bon\n");
            break;
        case 4 :
            printf("essayer d'etre moyen\n");
            break;
        case 5 :
            printf("essayer d'etre mauvais\n");
            break;
        default :
            printf("cas inconnu\n");
    }

	return 0;
}
/*********************************
Exercice 5
Écrire un programme affichant un menu proposant de jouer avec un, deux, trois
ou quatre dés. Selon le choix fait le programme lance les dés. Les dés identiques
sont relancés et il y a cumul des points. L'utilisateur gagne si : le total est
supérieur au deux tiers du maximum (avec deux dés ça fait 8 : (12 / 3) *2 ).
Le programme indique combien il manque pour gagner ou combien il y a de plus.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int d1,d2,d3,d4,nb;
int b1,b2,b3,b4;

    // remarque :
    // les dés égaux sont relancés une seule fois
    // (en principe nous ne disposons pas des boucles à cette étape du cours)
    srand(time(NULL));
    printf("Combien de des voulez-vous lancer ? (1-4) : ");
    scanf("%d",&nb);

    switch(nb){

        case 1 :
            d1=1+rand()%6;
            (d1 > (6/3)*2) ? printf("gagne\n") : printf("perdu\n");
            break;

        case 2 :
            d1=1+rand()%6;
            d2=1+rand()%6;
            if (d1==d2){
                d1=1+rand()%6;
                d2=1+rand()%6;
            }
            (d1+d2 > (6*2/3)*2) ? printf("gagne\n") : printf("perdu\n");
            break;

        case 3 :
            d1=1+rand()%6;
            d2=1+rand()%6;
            d3=1+rand()%6;
            //
            if(d1==d2){
                if(d1==d3)
                    d3=1+rand()%6;
                d1=1+rand()%6;
                d2=1+rand()%6;
            }
            else if(d2==d3){
                d2=1+rand()%6;
                d3=1+rand()%6;
            }
            else if(d1==d3){
                d1=1+rand()%6;
                d3=1+rand()%6;
            }
            (d1+d2+d3 > (6*3/3)*2) ? printf("gagne\n") : printf("perdu\n");
            break;

        case 4 :
            d1=1+rand()%6;
            d2=1+rand()%6;
            d3=1+rand()%6;
            d4=1+rand()%6;
            printf("d1: %d | d2: %d | d3: %d | d4: %d \n",d1,d2,d3,d4);
            b1=b2=b3=b4=0;

            if(d1==d2)
                b1=b2=1;
            if(d1==d3)
                b1=b3=1;
            if(d1==d4)
                b1=b4=1;
            if(d2==d3)
                b2=b3=1;
            if (d2==d4)
                b2=b4=1;
            if (d3==d4)
                b3=b4=1;

            if(b1==1){
                d1=1+rand()%6;
                printf("d1 rejoue %d\n",d1);
            }
            if(b2==1){
                d2=1+rand()%6;
                printf("d2 rejoue %d\n",d2);
            }
            if(b3==1){
                d3=1+rand()%6;
                printf("d3 rejoue %d\n",d3);
            }
            if(b4==1){
                d4=1+rand()%6;
                printf("d4 rejoue %d\n",d4);
            }

            (d1+d2+d3+d4 > (6*4/3)*2) ? printf("gagne\n") : printf("perdu\n");
            break;
        default : printf("nombre de des non accepte\n");
    }
	return 0;
}
/*********************************
Exercice 6
Un personnage arrive devant une porte. Un gardien est devant l’entrée.
Il pose une question au personnage. Si le personnage donne la bonne réponse
il peut passer, sinon il est détruit.
Faire un programme qui traduise cette situation en langage C.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int question, reponse;

    // l'intérêt de cet exercice est de passer d'un registre de sens à du code
    // il y a moyen ici d'envisager des scénario compliqués, mais je souhaite
    // faire apparaître surtout le côté bricolage de théâtre présent dans tous
    // les jeux vidéo
    srand(time(NULL));

    // admettons que nous ayons un maximum de 5 questions avec 5 réponses
    // choisissons une question au hasard:
    question = rand()%5;

    printf("Halte ! Repond a la question pour survivre :\n"
           "nuqnuturbertudhsdbxox bagorquidside bec sqghddf ?");
           scanf("%d",&reponse);
    if(reponse == question)
        printf("c'est bon tu vis et tu passes\n");
    else
        printf("tu trepasses\n");

	return 0;
}
/*********************************
Exercice 7
Faire un programme qui donne votre horoscope numérologique.
L'utilisateur entre sa date de naissance. Le programme calcul le numéro
correspondant. Par exemple soit une date de naissance 09051969 il faut
additionner tous les chiffres jusqu'à n'en avoir qu'un  :
0+9+0+5+1+9+6+9 donne 39,  3+9 donne 12, 1+2 donne 3,
le numéro correspondant à la date de naissance est 3.
A partir du numéro obtenu le programme donne un horoscope pour
l'année en cours.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int date_naissance,nb;
    // à réaliser toujours sans boucle
    printf("entrer une date de naissance (jjmmaaaa) :\n");
    scanf("%d",&date_naissance);

    // le problème principal est d'obtenir le fameux nombre
    // ultérieurement il faudra remplacer cette répétition par une boucle
    nb=date_naissance%10;
    date_naissance/=10;
    nb+=date_naissance%10;
    date_naissance/=10;
    nb+=date_naissance%10;
    date_naissance/=10;
    nb+=date_naissance%10;
    date_naissance/=10;
    nb+=date_naissance%10;
    date_naissance/=10;
    nb+=date_naissance%10;
    date_naissance/=10;
    nb+=date_naissance%10;
    date_naissance/=10;
    nb+=date_naissance%10;

    nb= nb%10 + (nb/10)%10;
    nb= nb%10 + (nb/10)%10;// une deuxième fois pour si nb>=10
    printf("votre nombre est : %d\n",nb);

    // ensuite envoyer un horoscope selon le nombre
    switch(nb){
        case 1 : printf("horoscope 1\n");   break;
        case 2 : printf("horoscope 2\n");   break;
        case 3 : printf("horoscope 3\n");   break;
        case 4 : printf("horoscope 4\n");   break;
        case 5 : printf("horoscope 5\n");   break;
        case 6 : printf("horoscope 6\n");   break;
        case 7 : printf("horoscope 7\n");   break;
        case 8 : printf("horoscope 8\n");   break;
        case 9 : printf("horoscope 9\n");   break;
    }
	return 0;
}
/*********************************
*/





