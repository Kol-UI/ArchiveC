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
*   Chapitre 2 : Contrôles des blocs d'instruction                  *
*   2. Sauts conditionnels                                          *
*   2.6 Mise en pratique : les sauts conditionnels                  *
*********************************************************************
/*********************************
Exercice 1
Écrivez un programme qui demande deux entiers et indique lequel est
le plus petit, lequel est le plus grand.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int n1,n2;
    printf("entrer deux nombres\n");
    scanf("%d %d",&n1,&n2);

    if(n1>n2)
        printf("%d superieur a %d", n1,n2);
    else if (n1<n2)
        printf("%d superieur a %d", n2,n1);
    else
        printf("%d egal a %d", n1,n2);
	return 0;
}
/*********************************
Exercice 2
Faire le programme qui lit deux variables au clavier et les affiche en ordre croissant
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n1,n2;
    printf("entrer deux nombres\n");
    scanf("%d %d",&n1,&n2);

    if(n1<n2)
        printf("%d %d", n1,n2);
    else
        printf("%d %d", n2,n1);
    // l'égalité ici n'a pas besoin d'être prise en compte
	return 0;
}
/*********************************
exercice 3
Faire un programme qui demande un entier et indique s'il est pair ou impair
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int n;
    printf("entrer un nombre\n");
    scanf("%d",&n);

    if(n%2) // équivalent à (n%2 == 1)
        printf("impair\n");
    else
    printf("pair\n");

	return 0;
}
/*********************************
Exercice 4 :
Donnez l'affichage de chacune des trois séquences suivantes pour :

	a égal à 100,
	a égal à 1

Séquence 1 :

if ( a < 50 )
 printf("1");

if ( a < 40 )
 printf("2");

if ( a < 30 )
printf("3");

if ( a < 20 )
printf("4");

if ( a < 10 )
printf("5");

    pour a égal à 100 imprime :  rien
	pour a égal à 1   imprime :  12345

Séquence 2 :

if ( a < 50 )
    printf("1");
else
    printf("2");

if ( a < 30 )
    printf("3");
else
    printf("4");

    pour a égal à 100 imprime : 24
	pour a égal à 1   imprime : 13

Séquence 3 :

if ( a < 50 )
   printf("1");
else if ( a < 40 )
   printf("2");
else if ( a < 30 )
   printf("3");
else if ( a < 20 )
   printf("4");
else if ( a < 10 )
   printf("5");
else
   printf("0");

    pour a égal à 100 imprime : 0
	pour a égal à 1   imprime : 1

/*********************************
Exercice 5
Faire un programme pour jouer à pile ou face. Au départ l'utilisateur choisit
pile ou face, le programme lance la pièce et donne le résultat gagné ou perdu.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int pf, piece;

    srand(time(NULL));
    printf("choisir pile(1) ou face (0)\n");
    scanf("%d",&pf);

    piece=rand()%2;
    if(piece==1)
        printf("pile sort, ");
    else
        printf("face sort, ");

    if (pf==piece)
        printf("gagne\n");
    else
        printf("perdu\n");

	return 0;
}
/*********************************
Exercice 6
Écrire le jeu du nombre caché : un nombre est caché, le joueur essaie de trouver
lequel. Le programme indique si le joueur a gagné ou de combien le nombre donné
par le joueur est trop grand ou trop petit.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int nb1, nb2;
    srand(time(NULL));

    nb1=rand()%5;
    printf("c'est un nombre entre 0 et 4 lequel ?\n");
    scanf("%d",&nb2);

    if (nb2==nb1)
        printf("gagne\n");
    else if (nb2>nb1)
        printf("trop grand de %d", nb2-nb1);
    else
        printf("trop petit de %d", nb1-nb2);

	return 0;
}
/*********************************
Exercice 7
Deux créatures hargneuses possèdent un même pouvoir mais lorsqu’elles se
rencontrent celle qui en possède le plus détruit l’autre. Imaginer une
solution en C et faites un programme d'illustration.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int t1, t2;

    srand(time(NULL));
    t1=rand()%100;
    t2=rand()%100;
    printf("premier : %d, second : %d\n", t1, t2);

    if(t1>t2)
        printf("le premier troll detruit le second\n");
    else if (t1<t2)
        printf("le second troll detruit le premier\n");
    else
        printf("ils ont la meme force\n");

	return 0;
}
/*********************************
Exercice 8
L'utilisateur entre deux signes choisi parmi + et - et le programme indique le signe
du produit (celui donné par une multiplication avec les deux signes). Programmez.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int s1=0,s2=0;
    printf("entrer deux signes (+ et/ou -) : ");
    scanf("%c %c",&s1,&s2);

    if(s1==s2)
        printf("positif\n");
    else
        printf("negatif\n");

	return 0;
}
/*********************************
Exercice 9
Écrire un programme qui lit trois variables au clavier est affiche le maximum des trois.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int n1,n2,n3;
    printf("entrer trois nombres :");
    scanf("%d %d %d",&n1,&n2,&n3);

    if (n1>=n2)
        if (n1>=n3)
            printf("max=%d",n1);
        else
            printf("max=%d",n3);
    else
        if (n2>=n3)
            printf("max=%d",n2);
        else
            printf("max=%d",n3);


	return 0;
}
/*********************************
Exercice 10
Une entreprise vends deux types de produits. Les produits de type A qui donnent lieu
à une TVA de 5,5% et les produits de type B qui donnent lieu à une TVA de 19,6%.
Écrire un programme qui lit au clavier le prix hors taxe d'un produit, saisit au
clavier le type du produit et affiche le taux de TVA et le prix TTC du produit.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
char type;
float prix;
    printf("entrer prix et type (A ou B) du produit : ");
    scanf("%f %c",&prix,&type);

    if (type =='A')
        printf("(TVA 5.5)prix = %.2f + %.2f=%.2f\n", prix,prix*0.055,prix+prix*0.055 );
    else
        printf("TVA 19.6) prix = %.2f + %.2f=%.2f\n", prix,prix*0.196,prix+prix*0.196 );


	return 0;
}
/*********************************
Exercice 11
Un personnage arrive devant une porte. Un gardien est devant l’entrée. Il pose une question
au personnage. Si le personnage donne la bonne réponse il peut passer, sinon il est détruit.
Faire un programme qui traduise cette situation en langage C.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int question, reponse;

    srand(time(NULL));
    printf("le cerbère pose une question ... et\n");
    question = 'a'+rand()%3; // pour a, b ou c
    printf("le personnage a le choix entre les reponses a, b, c : ");
    scanf("%c",&reponse);

    if (reponse==question)
        printf("vous avez la vie sauve\n");
    else
        printf("vous allez etre detruit\n");
	return 0;
}
/*********************************
*/


