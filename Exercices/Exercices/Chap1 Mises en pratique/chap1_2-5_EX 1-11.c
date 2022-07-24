/*
*   Pour tester la solution d'un exercice il faut :
*   - faire un projet c en mode console
*   - copier le code correspondant dans le fichier c
*   - compiler et exécuter
*
*   ou
*   - copier tout dans le fichier c du projet
*   - enlever les commentaires du code de l'exercice à tester
*   - mettre en commentaire tous les autres
*   - compiler et exécuter
*/
/********************************************************************
*   Chapitre 1 : Variables simples                                  *
*   2. Variables simples                                            *
*   2.5 Mise en pratique : manipulations de variables               *
*********************************************************************

/*************************************
Exercice 1
Faire un programme qui déclare trois int, deux float, un double et deux char,
affecter une  valeur à chaque variable, afficher le résultat.

*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int v1,v2,v3;
float f1,f2;
double d;
char c1,c2;
    v1=10;
    v2=20;
    v3=30;
    printf("%d,%d,%d\n",v1,v2,v3);

    f1=1.5;
    f2=2.5;
    printf("%f,%f\n",f1,f2);

    d=123456789.123456789;
    c1=100;
    c2=100;
    printf("%lf, %d, %c",d,c1,c2 );

    return 0;
}

/*************************************
Exercice 2
Dans un programme, déclarer un char et lui affecter une valeur choisie au hasard.
Afficher la valeur entrée en utilisant les deux formats %d et %c, qu'est ce que ça donne ?
Réessayer en demandant cette fois une valeur comprise entre  97 et 122. Que remarquez-vous ?
Quelles valeurs permettent d'afficher les caractères *, @, ♠, ♣, ♥, ♦. ?


*
#include <stdio.h>
#include <stdlib.h>
int main()
{
char c = 69;

    printf("%d, %c\n", c,c); // imprime 69, E

    c=110;
    printf("%d, %c\n", c,c);  // imprime 110, n , lettre minuscule

    printf("%d, %d, %d, %d\n", '♠','♣', '♥', '♦'); // pose un petit problème ...

    printf("%c, %c, %c, %c, %c, %c, %c\n",64, 1, 2, 3, 4, 5, 6);// c'est le résultat avec smiley en prime

    return 0;
}

/*************************************
Exercice 3
La fonction putchar(char c) permet d'afficher un caractère tout seul.
Dans un programme, utiliser cette fonction pour afficher le mot "TataFaitDuZele"
caractère par caractère, en allant à la ligne au moins trois fois.


*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    putchar('T');
    putchar('a');
    putchar('t');
    putchar('a');
    putchar('\n');
    putchar('F');
    putchar('a');
    putchar('i');
    putchar('t');
    putchar('\n');
    putchar('D');
    putchar('u');
    putchar('\n');
    putchar('Z');
    putchar('e');
    putchar('l');
    putchar('e');
    putchar('\n');

    return 0;
}

/*************************************
Exercice 4
Afficher lettre par lettre le mot "fourchette" en ajoutant
ou soustrayant ce qu'il faut à chaque lettre du mot "contrainte"
(utiliser opérateur arithmétique  + ou - )

*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    // fourchette
    // contrainte
    putchar('c'+3);
    putchar('o');
    putchar('n'+7);
    putchar('t'-2);
    putchar('r'-15);
    putchar('a'+7);
    putchar('i'-4);
    putchar('n'+6);
    putchar('t');
    putchar('e');
    putchar('\n');
    return 0;
}
/*************************************
Exercice 5
Dans un programme crypter un mot à partir d'une clé (une valeur) entrée par l'utilisateur.
Le mot crypté est affiché lettre par lettre  (utiliser opérateur arithmétique  + ou - ).
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int cle=0;

    printf("entrer une cle de cryptage :\n");
    scanf("%d",&cle); // la clé peut être en positif ou négatif

    printf("cryptage du mot \"bonjour\" :\n");
    putchar('b'+cle);
    putchar('o'+cle);
    putchar('n'+cle);
    putchar('j'+cle);
    putchar('o'+cle);
    putchar('u'+cle);
    putchar('r'+cle);

    return 0;
}

/*************************************
Exercice 6
Dans un programme déclarer quatre variables de type int. Afficher pour chacune son adresse
mémoire dans l'ordre où vous les avez déclarées. Entre chaque affichage intercalez la commande :
system("PAUSE"); Cette commande arrête le programme et il attend que vous pressiez une touche
pour continuer son exécution.
Pouvez-vous prédire à chaque arrêt quel sera l'adresse de la variable suivante ?
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int i1,i2,i3,i4;

    printf("%p",&i1);
    system("PAUSE");

    printf("%p",&i2);
    system("PAUSE");

    printf("%p",&i3);
    system("PAUSE");

    printf("%p",&i4);    // lors de mon test diminue de quatre en quatre
    system("PAUSE");

    return 0;
}

/*************************************
Exercice 7
Faire un programme qui déclare cinq variables chacune d'un type différent.
Pour chacune demandez à l'utilisateur d'entrer une valeur. Ensuite afficher
toutes les informations obtenues (valeur, taille, adresse) en commençant par
les variables qui prennent le moins de place en mémoire.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
char c;
short s;
int i;
float f;
double d;
    printf("entrer un char :\n");
    scanf("%c",&c);
    printf("val : %d, taille : %d, adresse : %p\n", c, sizeof(c), &c);

    printf("entrer un short :\n");
    scanf("%d",&s);
    printf("val : %d, taille : %d, adresse : %p\n", s, sizeof(s), &s);

    printf("entrer un int :\n");
    scanf("%d",&i);
    printf("val : %d, taille : %d, adresse : %p\n", i, sizeof(i), &i);

    printf("entrer un float :\n");
    scanf("%f",&f);
    printf("val : %f, taille : %d, adresse : %p\n", f, sizeof(f), &f);
    rewind(stdin);  // sinon petit problème

    printf("entrer un double :\n");
    scanf("%lf",&d);
    printf("val : %lf, taille : %d, adresse : %p\n", d, sizeof(d), &d);

    return 0;
}

/*************************************
Exercice 8
Dans un programme il y a 5 commandes possibles : commande 1, commande 2 ... commande 5.
Imaginer des commandes si vous préférez. L'objectif est de faire un menu qui permette de
récupérer le choix de l'utilisateur. Faire un programme qui demande à l'utilisateur la commande
qu'il veut exécuter et qui ensuite affiche la commande choisie par  l'utilisateur.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int choix;
    printf("entrer une commande entre 1 et 5\n");

    scanf("%d", &choix);
    printf("vous avez entre la commande %d\n",choix);

    printf("je ne peux pas verifier si elle est comprise entre 1 et 5\n");

    return 0;
}

/*************************************
Exercice 9
Faire un dessin avec des lettres choisies au début du programme par l'utilisateur.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
char c1,c2,c3;

    printf("entrer trois lettre pour le dessin :\n");
    scanf("%c %c %c",&c1,&c2,&c3);

    printf("voici un tapis raye a trois lettres :\n");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1,c1);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2,c2);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3,c3);

    return 0;
}


/*************************************
Exercice 10
Le programme à faire récupère avec deux variables v1 et v2 deux valeurs entrées par l'utilisateur.
Ensuite il inverse ces valeurs  (v1 prend la valeur de v2 et v2 prend la valeur de v1) et
réaffiche les variables pour vérifier que les valeurs ont bien été inversées.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int v1, v2;
int tmp;
    printf("entrer 2 valeurs :\n");
    scanf("%d%d",&v1,&v2);

    printf("v1=%d, v2=%d\n", v1, v2);

    tmp=v1;
    v1=v2;
    v2=tmp;

    printf("v1=%d, v2=%d\n", v1, v2);



    return 0;
}


/*************************************
Exercice 11
Soit cinq variables v1, v2, v3, v4, v5 contenant chacune une valeur entrée par l'utilisateur ou
choisie dans le programme. Permuter les valeurs en sorte que v1 prend la valeur de v2, v2
prend la valeur de v3, v3 prend la valeur de v4, v4 prend la valeur de v5 et v5 prend la valeur de v1.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int v1=1, v2=2, v3=3, v4=4, v5=5;
int tmp;

    printf("%d-%d-%d-%d-%d\n",v1,v2,v3,v4,v5);
    tmp=v1;
    v1=v2;
    v3=v3;
    v3=v4;
    v4=v5;
    v5=tmp;
    printf("%d-%d-%d-%d-%d\n",v1,v2,v3,v4,v5);


    return 0;
}
/*********************************
*/


