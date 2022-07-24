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
/************************************************************************
*   Chapitre 3 : Les structures									        *
*   1.   Structures                                                     *
*   1.4 Mise en pratique : définir, déclarer,initialiser des structures *
*************************************************************************

/*********************************
Exercice 1
Une menuiserie industrielle gère un stock de panneaux de bois. Chaque panneau
possède une largeur, une longueur et une épaisseur en millimètres ainsi que le
type de bois. Il y a trois types de bois : pin (code 0), chêne (code 1), hêtre
(code 2).
Définir une structure panneau contenant toutes les informations relatives à
un panneau de bois.
Dans un programme initialisez deux panneaux à la déclaration et deux panneaux
avec des valeurs aléatoires. Affichez les valeurs.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct panneau{
    int longueur,largeur,epaisseur; // en millimètre
    int type; //pin 0, chêne 1, hêtre 2
};

int main()
{
struct panneau p1={100,50,5,0};
struct panneau p2={150,100,10,1};
struct panneau p3,p4;
    srand(time(NULL));

    p3.longueur = 50+rand()%1000;
    p3.largeur = 50+rand()%1000;
    p3.epaisseur = 1+rand()%100;
    p3.type = rand()%3;

    p4.longueur = 50+rand()%1000;
    p4.largeur = 50+rand()%1000;
    p4.epaisseur = 1+rand()%100;
    p4.type = rand()%3;

    printf("P1 :\n"
           "- longueur  : %d\n"
           "- largeur   : %d\n"
           "- epaisseur : %d\n"
           "- type bois : %s\n", p1.longueur,p1.largeur,p1.epaisseur,
                                (p1.type==0)?"pin":((p1.type==1)?"chene":"hetre"));
    printf("P2 :\n"
           "- longueur  : %d\n"
           "- largeur   : %d\n"
           "- epaisseur : %d\n"
           "- type bois : %s\n", p2.longueur,p2.largeur,p2.epaisseur,
                                (p2.type==0)?"pin":((p2.type==1)?"chene":"hetre"));
    printf("P3 :\n"
           "- longueur  : %d\n"
           "- largeur   : %d\n"
           "- epaisseur : %d\n"
           "- type bois : %s\n", p3.longueur,p3.largeur,p3.epaisseur,
                                (p3.type==0)?"pin":((p3.type==1)?"chene":"hetre"));
    printf("P4 :\n"
           "- longueur  : %d\n"
           "- largeur   : %d\n"
           "- epaisseur : %d\n"
           "- type bois : %s\n", p4.longueur,p4.largeur,p4.epaisseur,
                                (p4.type==0)?"pin":((p4.type==1)?"chene":"hetre"));

    return 0;
}

/*********************************
Exercice 2
Un grossiste de composants électronique vend quatre types de produits :
des cartes mères (code 1)
des processeurs (code 2)
des barrettes mémoire (code 3)
des cartes graphiques (code 4)
Chaque produit possède une référence, qui est un nombre entier, un prix en
euros et une quantité disponible. Définir une structure produit qui code un
produit et dans un programme initialisez deux produits à la déclaration et
deux produits avec des valeurs entrées par l'utilisateur. Affichez les
valeurs et clonez le produit le plus cher.
*
#include <stdio.h>
#include <stdlib.h>

struct produit{
    int type; // cartes mères 1, processeurs 2, barrettes mémoire 3, cartes graphiques 4
    int ref;
    float prix;
    int nb;
};

int main()
{
struct produit p1={4,1234,120.5,10};
struct produit p2={2,2345,400,5};
struct produit p3,p4,p5;

    printf("entrer un produit :\n");
    printf("type de produit (1,2,3,4):\n");
    scanf("%d",&p3.type);
    rewind(stdin);

    printf("reference produit:\n");
    scanf("%d",&p3.ref);
    rewind(stdin);

    printf("prix produit:\n");
    scanf("%f",&p3.prix);
    rewind(stdin);

    printf("quantite produit:\n");
    scanf("%d",&p3.nb);
    rewind(stdin);
    printf("-------------------\n");
    //
    printf("entrer un produit :\n");
    printf("type de produit (1,2,3,4):\n");
    scanf("%d",&p4.type);
    rewind(stdin);

    printf("reference produit:\n");
    scanf("%d",&p4.ref);
    rewind(stdin);

    printf("prix produit:\n");
    scanf("%f",&p4.prix);
    rewind(stdin);

    printf("quantite produit:\n");
    scanf("%d",&p4.nb);
    rewind(stdin);
    printf("-------------------\n");

    // affichage
    printf("produit 1 : \n");
    printf("- type : ");
    switch(p1.type){ //cartes mères 1, processeurs 2, barrettes mémoire 3, cartes graphiques 4
        case 1 : printf("carte mere\n");        break;
        case 2 : printf("processeur\n");        break;
        case 3 : printf("barrette memoire\n");  break;
        case 4 : printf("cartes graphiques\n"); break;
    }
    printf("- prix : %.2f\n",p1.prix);
    printf("- quantite : %d",p1.nb);
    printf("- reference :%d",p1.ref);
    printf("-------------------\n");

    printf("produit 2 : \n");
    printf("- type : ");
    switch(p2.type){ //cartes mères 1, processeurs 2, barrettes mémoire 3, cartes graphiques 4
        case 1 : printf("carte mere\n");        break;
        case 2 : printf("processeur\n");        break;
        case 3 : printf("barrette memoire\n");  break;
        case 4 : printf("cartes graphiques\n"); break;
    }
    printf("- prix : %.2f\n",p2.prix);
    printf("- quantite : %d",p2.nb);
    printf("- reference :%d",p2.ref);
    printf("-------------------\n");

    printf("produit 3 : \n");
    printf("- type : ");
    switch(p3.type){ //cartes mères 1, processeurs 2, barrettes mémoire 3, cartes graphiques 4
        case 1 : printf("carte mere\n");        break;
        case 2 : printf("processeur\n");        break;
        case 3 : printf("barrette memoire\n");  break;
        case 4 : printf("cartes graphiques\n"); break;
    }
    printf("- prix : %.2f\n",p3.prix);
    printf("- quantite : %d",p3.nb);
    printf("- reference :%d",p3.ref);
    printf("-------------------\n");

    printf("produit 4 : \n");
    printf("- type : ");
    switch(p4.type){ //cartes mères 1, processeurs 2, barrettes mémoire 3, cartes graphiques 4
        case 1 : printf("carte mere\n");        break;
        case 2 : printf("processeur\n");        break;
        case 3 : printf("barrette memoire\n");  break;
        case 4 : printf("cartes graphiques\n"); break;
    }
    printf("- prix : %.2f\n",p4.prix);
    printf("- quantite : %d",p4.nb);
    printf("- reference :%d",p4.ref);
    printf("-------------------\n");

    // produit le plus cher
    p5=p1;
    p5=(p2.prix>p5.prix)?p2:p5;
    p5=(p3.prix>p5.prix)?p3:p5;
    p5=(p4.prix>p5.prix)?p4:p5;

    printf("produit le plus cher : \n");
    printf("- type : ");
    switch(p5.type){ //cartes mères 1, processeurs 2, barrettes mémoire 3, cartes graphiques 4
        case 1 : printf("carte mere\n");        break;
        case 2 : printf("processeur\n");        break;
        case 3 : printf("barrette memoire\n");  break;
        case 4 : printf("cartes graphiques\n"); break;
    }
    printf("- prix : %.2f\n",p5.prix);
    printf("- quantite : %d",p5.nb);
    printf("- reference :%d",p5.ref);
    printf("-------------------\n");

    // remarque : sans fonction c'est fastidieux !

    return 0;
}

/*********************************
Exercice 3
Soit un programme de flocons de neige qui tombe du haut de la fenêtre
console en bas. Chaque flocon est une lettre. Donnez une structure de
données qui permet de coder un flocon. Dans un programme déclarez quatre
flocons. Initialisez un flocon à la déclaration et un autre avec des
valeurs aléatoires. Copiez chaque flocon et affichez les valeurs des
quatre flocons de façon claire.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct flocon{
    int x;  // position horizontale fixe
    float y;  // position verticale mobile
    float dy;   // vitesse descente
    int l;      // la lettre du flocon
};

int main()
{
struct flocon p1={1,0,0.5,'A'},p2,p3,p4;
    p2.x=rand()%80;
    p2.y=rand()%10;
    p2.dy=((float)rand()/RAND_MAX)*2; // entre 0 et 2

    p3=p1;
    p4=p2;

    printf("flocon 1 : x %3d, y %3.2f, dy : %2.2f, l : %c\n",p1.x,p1.y,p1.dy,p1.l);
    printf("flocon 2 : x %3d, y %3.2f, dy : %2.2f, l : %c\n",p2.x,p2.y,p2.dy,p2.l);
    printf("flocon 3 : x %3d, y %3.2f, dy : %2.2f, l : %c\n",p3.x,p3.y,p3.dy,p3.l);
    printf("flocon 4 : x %3d, y %3.2f, dy : %2.2f, l : %c\n",p4.x,p4.y,p4.dy,p4.l);


    return 0;
}

/*********************************
Exercice 4
Le monde où se trouve le player est parcouru par des ennemis.
Donnez les caractéristiques essentielles d'un ennemi que vous
imaginez et la structure de données le mieux adaptée. Initialisez
un ennemi à la déclaration et un autre avec des valeurs aléatoires.
Affichez les valeurs de votre ennemi. Faites un clone.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ennemi{
    int x,y; // position
    int dx,dy; // deplacement
    int agress; // taux d'agressivité
};

int main()
{
struct ennemi e1={10,10,1,3,150},e2,e3;

    srand(time(NULL));
    e2.x=rand()%80;
    e2.y=rand()%20;
    e2.dx= (rand()%2*2-1)*(1+rand()%2); // entre -3 et 3 valeurs entières
    e2.dy= (rand()%2*2-1)*(1+rand()%2);
    e2.agress=rand()%1000;

    e3=e2;

    printf("(x,y) : (%3d,%3d),(dx,dy) : (%2d,%2d), Agressivite : %5d\n",e1.x,e1.y,e1.dx,e1.dy,e1.agress);
    printf("(x,y) : (%3d,%3d),(dx,dy) : (%2d,%2d), Agressivite : %5d\n",e2.x,e2.y,e2.dx,e2.dy,e2.agress);
    printf("(x,y) : (%3d,%3d),(dx,dy) : (%2d,%2d), Agressivite : %5d\n",e3.x,e3.y,e3.dx,e3.dy,e3.agress);


    return 0;
}
/*********************************
*/




