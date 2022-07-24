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
*   Chapitre 4 : Les tableaux											*
*   1. Tableaux statiques                                               *
*   1.7 Mise en pratique : base tableaux statiques (non dynamiques)     *
*************************************************************************

/************************************************
*                                               *
*  Déclaration de tableaux, accès aux éléments  *
*                                               *
************************************************/

/*********************************
Exercice 1
Soit un tableau de 5 entiers, Appliquer les instructions suivantes :
1) initialiser le tableau avec des valeurs aléatoires comprises entre 0 et 20.
2) afficher le tableau de façon claire et lisible.
3) Si  la première valeur est supérieure à la seconde, permuter les deux valeurs,
si la seconde est supérieure à la troisième permuter,
si la troisième est supérieure à la quatrième permuter,
si la quatrième est supérieure à la cinquième permuter,
A quelle position se trouve la plus grande valeur ?
4) Afficher le tableau pour constater les changements opérés.
*

#include <stdio.h>
#include <stdlib.h>

int main()
{
int tab[5];
int tmp,i;

    // accés "manuel" à chaque élément du tableau pour une valeur
    // aléatoire choisie par le programmeur :
    tab[0]= 19;
    tab[1]= 3;
    tab[2]= 17;
    tab[3]= 10;
    tab[4]= 0;

    // l'affichage, boucle
    for (i=0;i<5; i++)
        printf("tab[%d]=%d\n",i,tab[i]);

    // permutations
    for(i=0; i<4; i++)
        if(tab[i]>tab[i+1]){
            tmp=tab[i];
            tab[i]=tab[i+1];
            tab[i+1]=tmp;
        }

    // la plus grande valeur est à l'indice 4
    // vérification
    for (i=0;i<5; i++)
        printf("tab[%d]=%d\n",i,tab[i]);


    return 0;
}

/*********************************
Exercice 2
Soit un tableau de 3 entiers et un autre tableau de 5 floats.
1) Initialiser ces tableaux avec des valeurs aléatoires
2) Pour chaque indice comparer les valeurs des deux tableaux et stockez
la différence exacte  dans un troisième tableau.
3) vérifiez vos résultats par l'affichage.
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int t1[3];
float t2[5];
float t3[3];
int i;
    // initiallisation
    for (i=0; i<3; i++)
        t1[i]=rand()%1000;
    for (i=0; i<5; i++)
        t2[i]=((float)rand()/RAND_MAX)*1000;

    // la comparaison ne peut se faire que sur les trois premiers indices
    for (i=0; i<3; i++){
        t3[i]=t1[i]-t2[i];
        if (t1[i]>t2[i])
            printf("t1[%d]=%d > t2[%d]=%f, ",i,t1[i],i,t2[i]);
        else if(t1[i]<t2[i])
            printf("t1[%d]=%d < t2[%d]=%f, ",i,t1[i],i,t2[i]);
        else
            printf("t1[%d]=%d == t2[%d]=%f, ",i,t1[i],i,t2[i]);

        printf("difference : %f\n",t3[i]);
    }
    return 0;
}

/************************************************
*                                               *
*  Initialisation de tableaux à la déclaration  *
*                                               *
************************************************/

/*********************************
Exercice 3
Faire un programme qui déclare un tableau de 10 entiers initialisé avec
les valeurs d'indice. Affichez trois positions choisies aléatoirement.
A ces positions mettez une valeur comprise entre 0 et 256, affichez la
nouvelle valeur à cette position
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int tab[10],i,r1,r2,r3;

    // initialisation avec valeur d'indice
    for (i=0; i<10; i++)
        tab[i]=i;

    // trois positions aléatoires
    // si vous les choisissez à la min pas de problème mais se seront
    // toujours les même valeurs
    // si vous le faite faire par la machine il ne faut pas que
    // deux positions se répètent
    srand(time(NULL));
    r1=rand()%10;
    r2=rand()%10;
    r2=(r2==r1)? (r2+1)%10: r2;

    r3=rand()%10;
    while(r3==r2||r3==r1)
        r3=(r3+1)%10;

    tab[r1]=rand()%256;
    tab[r2]=rand()%256;
    tab[r3]=rand()%256;

    printf("tab[%d]=%d\n",r1,tab[r1]);
    printf("tab[%d]=%d\n",r2,tab[r2]);
    printf("tab[%d]=%d\n",r3,tab[r3]);

    return 0;
}

/*********************************
Exercice 4
Sans préciser le nombre de lettres qu'il contient déclarer un tableau de char
initialisé avec un message simple. Choisissez trois positions aléatoires et
modifiez les lettres de ces positions.
Mettez le signe  '\0' (antislash zéro) à la dernière position de votre tableau
et affichez le message avec la fonction printf() et le format %s
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
char tab[]={'t','o','t','o',' ','m','a','n','g','e'};// tableau de char
int r1,r2,r3,nb;

    // 3 positions aléatoires : il ne faut pas que deux positions se répètent
    // nombre d'éléments du tableau statique :
    nb=sizeof(tab);

    srand(time(NULL));
    r1=rand()%nb;
    r2=rand()%nb;
    r2=(r2==r1)? (r2+1)%nb: r2;
    r3=rand()%nb;
    while(r3==r2||r3==r1)
        r3=(r3+1)%nb;

    tab[r1]++;
    tab[r2]++;
    tab[r3]++;
    tab[nb-1]='\0';
    printf("%s\n",tab);

    return 0;
}

/************************************************
*                                               *
*       Tableaux à plusieurs dimensions         *
*                                               *
************************************************/

/*********************************
Exercice 5
Vous vous lancez dans la programmation d'un tétris (bientôt). Coder les formes T,
S et Z, O-carré, I, J et L sachant que pour chacune il y a quatre positions possibles
pour les rotations gauche ou droite et que la taille de chaque forme sera de 4 sur 4.
*

//
//       Les formes I, J, L, O, T, S, Z,
//       pour chacune quatre positions possibles par rotation gauche ou droite.
//       Matrices 4*4*4 initialisées à la définition; le numéro contenu
//       correspond à un identificateur pour une lettre (ou une image)
//       utilisée par la forme dans le programme ensuite
//
//
 char IF[4][4][4]={
                    {
                     {0, 0, 6, 0},
                     {0, 0, 6, 0},
                     {0, 0, 6, 0},
                     {0, 0, 6, 0}
                    },
                    {
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {6, 6, 6, 6},
                     {0, 0, 0, 0}
                     },
                    {
                     {0, 0, 6, 0},
                     {0, 0, 6, 0},
                     {0, 0, 6, 0},
                     {0, 0, 6, 0}
                    },
                    {
                     {0, 0, 0, 0},
                     {0, 0, 0, 0},
                     {6, 6, 6, 6},
                     {0, 0, 0, 0}
                    }
                 };
char JF[4][4][4]={
                   {
                     {0, 3, 0, 0},
                     {0, 3, 0, 0},
                     {0, 3, 3, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 3, 3, 3},
                     {0, 3, 0, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 3, 3, 0},
                     {0, 0, 3, 0},
                     {0, 0, 3, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 0, 3, 0},
                     {3, 3, 3, 0},
                     {0, 0, 0, 0}
                   }
};
char LF[4][4][4]={
                   {
                     {0, 0, 0, 0},
                     {0, 4, 4, 0},
                     {0, 4, 0, 0},
                     {0, 4, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {4, 4, 4, 0},
                     {0, 0, 4, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 4, 0},
                     {0, 0, 4, 0},
                     {0, 4, 4, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 4, 0, 0},
                     {0, 4, 4, 4},
                     {0, 0, 0, 0}
                   }
                 };
char OF[4][4][4]={
                   {
                     {0, 0, 0, 0},
                     {0, 7, 7, 0},
                     {0, 7, 7, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 7, 7, 0},
                     {0, 7, 7, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 7, 7, 0},
                     {0, 7, 7, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 7, 7, 0},
                     {0, 7, 7, 0},
                     {0, 0, 0, 0}
                   }
                 };
char TF[4][4][4]={
                   {
                     {0, 5, 0, 0},
                     {0, 5, 5, 0},
                     {0, 5, 0, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {5, 5, 5, 0},
                     {0, 5, 0, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 5, 0, 0},
                     {5, 5, 0, 0},
                     {0, 5, 0, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 5, 0, 0},
                     {5, 5, 5, 0},
                     {0, 0, 0, 0},
                     {0, 0, 0, 0}
                   }
                 };
char SF[4][4][4]={
                   {
                     {0, 0, 2, 0},
                     {0, 2, 2, 0},
                     {0, 2, 0, 0},
					 {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {2, 2, 0, 0},
                     {0, 2, 2, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 2, 0},
                     {0, 2, 2, 0},
                     {0, 2, 0, 0},
					 {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {2, 2, 0, 0},
                     {0, 2, 2, 0},
                     {0, 0, 0, 0}
                   }
                 };
char ZF[4][4][4]={
                   {
                     {0, 1, 0, 0},
                     {0, 1, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 1, 1, 0},
                     {1, 1, 0, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 1, 0, 0},
                     {0, 1, 1, 0},
                     {0, 0, 1, 0},
                     {0, 0, 0, 0}
                   },
                   {
                     {0, 0, 0, 0},
                     {0, 1, 1, 0},
                     {1, 1, 0, 0},
                     {0, 0, 0, 0}
                   }
                 };

/*********************************
Exercice 6
Faire un programme qui déclare un tableau de 543*896*531 éléments du type que vous voulez.
Tester. Quel résultat obtenez-vous ?
Modifier la taille du tableau de façon à ce que ça marche. Quelle taille fonctionne ?
Le tableau est initialisé à la déclaration (deux ou trois valeurs uniquement).
Affichez trois positions choisis aléatoirement.
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
//int tab[543][896][531]; // produit un débordement
//int tab[521156]; // compile sur ma machine, soit 2084624 octets

    // mais ne permet plus rien
    // printf("nombre d'octets max pour tableaux statiques : %d\n",sizeof(tab));

    // autre test
int tab[520724];

    printf("nombre d'octets max pour tableaux statiques : %d\n",sizeof(tab));

    return 0;
}

/*********************************
Exercice 7
Faire un programme qui déclare un tableau à 3 dimensions
de 2*2*2 et :
initialiser ce tableau en stockant à chaque position le numéro
de la position (1, 2, 3 ...)
afficher le résultat.
*
#include <stdio.h>
#include <stdlib.h>


int main()
{
int t[2][2][2]={1,2,3,4,5,6,7,8};
int i,j,k;
    for (i=0; i<2; i++)
        for (j=0; j<2; j++)
            for (k=0; k<2; k++)
                printf("t[%d][%d][%d]=%d\n",i,j,k,t[i][j][k]);
    return 0;
}

/*********************************
Exercice 8
Faire un programme qui déclare  deux matrices d'entiers de 2*3 et :
initialisez ces matrices avec des valeurs aléatoires entre 0 et 20
pour chaque position comparez les valeurs stockées et stockez
la plus grande dans une troisième matrice.
affichez les trois matrices (sur 6 lignes uniquement)
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int t1[2][3];
int t2[2][3];
int t3[2][3];
int i,j;
    for (i=0; i<2; i++)
        for (j=0; j<3; j++){
            t1[i][j]=rand()%1000;
            t2[i][j]=rand()%1000;
            t3[i][j]=(t1[i][j]>=t2[i][j])?t1[i][j]:t2[i][j];
        }
    // affichage sans colonne
    for (i=0; i<2; i++)
        for (j=0; j<3; j++){
            printf("t1[%d][%d]=%4d-",i,j,t1[i][j]);
            printf("t2[%d][%d]=%4d-",i,j,t2[i][j]);
            printf("t3[%d][%d]=%4d\n",i,j,t3[i][j]);
        }
    return 0;
}

/*********************************
Exercices 9
Faire un programme qui déclare une matrice de 100*450 floats.
initialisez 3 positions différentes choisies aléatoirement dans
la matrice avec des valeurs entre 0 et 2
affichez les trois positions et les valeurs aux trois positions.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
//solution 1
float f[100][450];
int i1,j1,i2,j2,i3,j3;

    srand(time(NULL));

    printf("// -----------------solution 1 :\n");
    i1=rand()%100;
    i2=rand()%100;
    i2=(i2==i1)? (i2+1)%100: i2;
    i3=rand()%100;
    while(i3==i2||i3==i1)
        i3=(i3+1)%100;

    j1=rand()%450;
    j2=rand()%450;
    j2=(j2==j1)? (j2+1)%450: j2;
    j3=rand()%450;
    while(j3==j2||j3==j1)
        j3=(j3+1)%450;

    f[i1][j1]=((float)rand()/RAND_MAX)*2;
    f[i2][j2]=((float)rand()/RAND_MAX)*2;
    f[i3][j3]=((float)rand()/RAND_MAX)*2;

    printf("f[%d][%d]=%f\n",i1,j1,f[i1][j1]);
    printf("f[%d][%d]=%f\n",i2,j2,f[i2][j2]);
    printf("f[%d][%d]=%f\n",i3,j3,f[i3][j3]);

    //
    printf("// -----------------solution 2 :\n");

    // remarque pour plus de 3 positions il serait obligatoire prendre deux
    //  ou une matrice d'indices et pour chaque nouvelle position tirée vérifier
    // qu'elle n'a pas été déjà tirée
float _f[100][450];
int ti[30],tj[30],i,j,k;

    srand(time(NULL));
    // au départ le tableau ne contient rien
    for (i=0; i<100;i++)
        for (j=0; j<450; j++)
            _f[i][j]=-1;

    // chercher des positions différentes au hasard et disséminées
    for (k=0; k<30; k++){
        ti[k]=rand()%100;
        tj[k]=rand()%450;
        while(_f[ti[k]][tj[k]]>0){
            tj[k]= (tj[k]+1);
            if(tj[k]==450){
                tj[k]=0;
                ti[k]=(ti[k]+1)%100;
            }
        }
        _f[ti[k]][tj[k]]=((float)rand()/RAND_MAX)*2;
        printf("f[%3d][%3d]=%.2f\n",ti[k],tj[k],_f[ti[k]][tj[k]]);
     }

    return 0;
}

/************************************************
*                                               *
*       Boucles et tableaux                     *
*                                               *
************************************************/


/*********************************
Exercice 10
Soit un tableau de 2000 float
l'initialiser avec des valeurs aléatoires comprises entre 0 et 10
afficher le tableau avec uniquement 2 chiffres après la virgule
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
float f[2000];
int i;
    for (i=0; i<2000; i++){
        f[i]=((float)rand()/RAND_MAX)*10;
        printf("f[%d]=%.2f\n",i,f[i]);
    }
    return 0;
}

/*********************************
Exercice 11
Soit un tableau de 150 int,
initialisez aléatoirement le tableau avec uniquement des 0 ou des 1.
affichez le  tableau  en 10 colonnes de 3 caractères et 15 lignes.
La taille des colonnes est spécifiée entre le % et le d du format
de la façon suivante  "%3d".
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int t[150];
int i,j,k;

    for (k=0,j=0; j<15; j++){
        for (i=0; i<10; i++,k++){
            t[k]=rand()%2;
            printf("%3d",t[k]);
        }
        putchar('\n');
    }
    return 0;
}

/*********************************
Exercice 12
Soit une matrice de 15 lignes par 10 colonnes :
initialisez le tableau avec des valeurs croissantes aléatoires.
affichez le résultat. La taille des colonnes est spécifiée comme
dans l'exercice précédent avec un  intervalle de un caractère
entre chaque nombre.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int m[15][10], i,j,val=0;

    srand(time(NULL));
    for(j=0; j<15; j++){
        for (i=0; i<10; i++){
            m[j][i]=val+rand()%100;
            val=m[j][i];
            printf("%5d",m[j][i]);
        }
        putchar('\n');
    }
    return 0;
}
/*********************************
Exercice 13
Soit une matrice de 15*15. Faire un damier et afficher le résultat.
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int d[15][15],i,j;

    for (j=0; j<15; j++){
        for (i=0; i<15; i++){
            d[j][i]=(i+j)%2;
            printf("%2d",d[j][i]);
        }
        putchar('\n');
    }

    return 0;
}

/*********************************
Exercice 14
Remplir un tableau avec des valeurs aléatoires et opérer une rotation
des valeurs afin que ce qui est à la position 0 passe à la position 1,
ce qui est à la position 1 passe à la position 2 et ainsi de suite
jusqu'au dernier qui vient à la position 0.
Faire le même exercice avec une matrice : la valeur de chaque position
passe à la position suivante jusqu'à la dernière qui vient en première
position.
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int t[10],i,tmp;

    for (i=0; i<10; i++){
        t[i]=rand()%100;
        printf("%3d",t[i]);
    }
    putchar('\n');

    // rotation
    tmp=t[9];
    for(i=9; i>0;i--){ // parcours à partir de la fin
        t[i]=t[i-1];
    }
    t[0]=tmp;

    printf("appres rotation :\n");
    for (i=0; i<10; i++)
        printf("%3d",t[i]);
    return 0;
}

/*********************************
Exercice 15
Remplir un tableau avec des valeurs aléatoires, afficher le tableau puis :
affichez les deux plus grandes valeurs
affichez la plus petite valeur et sa position dans le tableau
affichez les valeurs du tableau en ordre croissant sans modifier le tableau
modifiez le tableau afin que toutes ses valeurs soient triées en ordre
décroissant et affichez le résultat.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int t[10],i, m1, m2,p,id;
int s,j,k,cmpt;

    srand(time(NULL));

    // initialisation
    for (i=0; i<10; i++){
        t[i]=rand()%100;
        printf("%3d",t[i]);
    }
    putchar('\n');

    // recherche deux plus grandes valeurs
    m1=0;
    for (i=0; i<10;i++)
        if (m1<t[i]){
            m1=t[i];
            id=i;
        }
    printf("premiere plus grande valeur : %d\n",m1);

    // id est l'indice du plus grand précédent, pour le cas ou il y a deux fois
    // la plus grande valeur dans le tableau
    m2=0;
    for (i=0; i<10;i++)
        if (m2<t[i]&&t[i]<=m1 && i!=id)
            m2=t[i];
    printf("seconde plus grande valeur : %d\n",m2);

    // plus petite valeur :
    p=100;
    for (i=0; i<10; i++)
        if(t[i]<p){
            p=t[i];
            id=i;
        }

    printf("plus petite valeur : %d, position %d\n",p,id);

    // afficher en ordre croissant sans modifier le tableau
    // il y a un solution qui consiste à copier le tableau
    // trier la copie et afficher la copie. Mais nous allons
    // faire autrement, pour le fun
    // il faut parcourir le tableau pour chaque élément et afficher
    // à chaque fois le plus petit au dessus du plus petit précédent
    printf("ordre croissant 1 :\n");
    p=100;
    s=-1;
    for (i=0; i<10; i++){
        for (j=0; j<10; j++)
            if (p>t[j] && t[j]>s)
                p=t[j];
        printf("%3d",p);
        // réinitialisations pour tours suivant
        s=p;
        p=100;
    }
    putchar('\n');
    // le problème de cette solution est qu'elle ne gère pas les répétitions
    // si une valeur est répétée dans le tableau elle ne sera pas affichée
    // et les dernier tours afficherons p à 100.

    // pour pouvoir afficher les répétitions il faut pour chaque valeur trouvée
    // compter les éventuelles répétions, les afficher tout de suite et
    // incrémenter d'autant le nombre de tours de recherche en i

    printf("ordre croissant 2 :\n");
    p=100;
    s=-1;
    for (i=0; i<10; i++){
        for (j=0; j<10; j++)
            if (p>t[j] && t[j]>s){
                p=t[j];
                // compter les répétitions
                for (k=j+1,cmpt=0; k<10; k++)
                    if(t[k]==p)
                        cmpt++;
            }
        // affichage
        printf("%3d",p);
        // affichage répétitions
        for (k=0; k<cmpt; k++)
            printf("%3d",p);
        // supprimer les boucles selon nombre de répétition
        i+=cmpt;
        // réinitialisations pour tours suivant
        s=p;
        p=100;
    }
    return 0;
}

/*********************************
Exercice 16
Soit un groupe d’enfants dans une cours d’école. Ils veulent jouer à chat
et pour désigner le chat ils utilisent la méthode "am stram gram pic et pic
et co le gram bou ret bou ret ra ta tam am stram gram". En répétant de façon
rythmée cette phrase l’un d’entre eux désigne, à chaque syllabe une personne
du groupe, toujours selon le même ordre et en tournant toujours dans le même
sens, celle désignée avec la dernière syllabe ne sera pas le chat et est sortie
du groupe. L’opération est recommencée jusqu’à ce qu’il n’en reste plus qu’une
qui est le chat.
Faire un programme où le groupe des enfants est représenté par un tableau et
utiliser cette méthode pour désigner le chat qui correspondra au dernier indice
restant du tableau.
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int e[11]={0}; // onze enfants
int cmptine=19; // pour les 20 (0 à 19 compris) syllabes de la comptine
int i,res=11; //enfants restants

    i=0;
    cmptine=0;
    do{
        if(e[i%11]==0){ // progression de la comptine avec les cases à 0
            cmptine++;
        }
        if(cmptine==19){ // dernière désignée passe à 1
            e[i%11]=1;
            printf("enfant %d sort\n",i%11);
            res--;       // un de moins dans la recherche
            cmptine=0;   // comptine reprend au départ
        }
        i++;             // i continue à boucler à partir de la position courante
    }while (res>1);      // jusqu'à ce que 10 aient été sortis

    // trouver le seul encore à 0, c'est lui le chat
    for (i=0; e[i]==1 ; i++)
        ;
    printf("le chat est l'enfant %d\n",i);

    return 0;
}

/*********************************
Exercice 17
Un poète maudit vit dans un grenier. Il manque deux tuiles au toit et il pleut.
Le poète a placé une bassine sous chaque trou. Les bassines ont la même taille
et chaque bassine se remplit goutte à goutte en fonction d'un temps aléatoire.
Laquelle des deux bassines est remplie en premier et en combien de temps ?
Faire une simulation en prenant comme bassine deux tableaux, pour chaque goutte
le temps écoulé depuis la dernière goute de la même bassine est stocké.
*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int main()
{
int b1[20]={0},g1=0,start1=clock();
int b2[20]={0},g2=0,start2=clock();
int fin=0;

    // remarque : chaque bassine est en fait une pile

    srand(time(NULL));
    while (!fin){
        if(kbhit())
            fin=1;

        if(clock()>start1+b1[g1]){
            start1=clock();
            if (g1<18){ // attention dernière goutte à 19
                g1++;
                b1[g1]=100+rand()%2000;
                printf("goutte bassine 1\n");
            }
            else{
                printf("Bassine 1 remplie, le poete la vide\n");
                g1=0;
                b1[g1]=0;
            }
        }
        if(clock()>start2+b2[g2]){
            start2=clock();
            if (g2<19){
                g2++;
                b2[g2]=100+rand()%2000;
                printf("goutte bassine 2\n");
            }
            else{
                printf("Bassine 2 remplie, le poete la vide\n");
                g2=0;
                b2[g2]=0;
            }
        }
    }
    return 0;
}
/*********************************
Exercice 18
Le lave vaisselle est en panne et la vaisselle s’accumule. Le plongeur s’active,
il essaie de nettoyer les assiettes et autres objets dés qu’ils arrivent mais
ils arrivent très vite et s’empilent à côté de lui. Définissez quatre types
d'objets (par exemple assiette plate, creuse, à désert et plat). A partir
d’un tableau simuler la situation de la pile de vaisselle. Lorsque l’on
appuie sur une touche des objets sont ajoutés et lorsque l’on appuie
sur une autre touche du clavier des objets sont retirés de la pile.
Lorsque l'on appuie sur enter le contenu de la pile des objets
est affiché.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
int pile[15], sommet=0;
int i,fin=0;
    while (!fin){
        if (kbhit()){
            switch(getch()){
                case 'e' : // empile
                    if(sommet<15){
                        pile[sommet++]=rand()%4;
                        printf("empile %d\n",sommet);
                    }
                    else
                        printf("pile pleine\n");
                    break;
                case 'd' : // dépile
                    if (sommet>0){
                        sommet--;
                        printf("depile %d\n",sommet);
                    }
                    else
                        printf("pile vide\n");
                    break;
                case 13 : // enter pour affiche
                    if(sommet){
                        for (i=0; i<sommet; i++){
                            switch(pile[i]){//assiette plate 0, creuse 1, à désert 2 et plat 3
                                case 0 : printf("assiette platte\n");     break;
                                case 1 : printf("assiette creuse\n");     break;
                                case 2 : printf("assiette a dessert\n");  break;
                                case 3 : printf("plat\n");                break;
                            }
                        }
                        printf("-------------------------\n");
                    }
                    else
                        printf("pile vide\n");
                    break;
                default : fin=1;
            }
        }
    }
    return 0;
}
/*********************************
Exercice 19
Nous sommes à un carrefour routier, il y a un feu qui est rouge ou vert.
Faire une simulation simplifiée de la constitution d’une file de voiture
à l’un des feux. Lorsque le feu est rouge les voitures qui arrivent sont
ajoutées à la file. Lorsque le feu passe au vert les voitures en tête de
la file partent une à une et libèrent leur place. Mettre en place ce système
de file en utilisant un tableau.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
int file[10], tete=0,queue=0; // pour une file il y a deux indices
// début tete (départ voiture), et fin queue (arrivée voitures)
// le tableau est circulaire (arrivé à la fin on revient au début
// l'indice de queue peut être avant ou après l'indice de tete.
// On peut enfiler (ajouter à la file) si (queue+1)%10 est différent de tete
// c'est à dire si la file n'est pas pleine. De ce fait la file contient une
// voiture de moins.
// On peut défiler (retirer de la file) si tete est différent de queue
// Le feu ici est manuel avec les touches e (feu rouge) pour enfiler
//(arrivée voitures) et d (feu vert) pour defiler (départ voitures)

int i,fin=0;
    while (!fin){
        if (kbhit()){
            switch(getch()){
                case 'e' : // FEU ROUGE enfile
                    if( (queue+1)%10!=tete){
                        file[queue]=rand()%4;
                        printf("enfile pos %d\n",queue);
                        queue=(queue+1)%10;
                    }
                    else
                        printf("file pleine\n");
                    break;
                case 'd' : // FEU VERT défile
                    if (tete!=queue){
                        printf("defile pos %d\n",tete);
                        tete=(tete+1)%10;
                    }
                    else
                        printf("file vide\n");
                    break;
                case 13 : // enter pour affiche
                    if(tete!=queue){
                        for (i=tete; i != queue; i=(i+1)%10){
                            switch(file[i]){//assiette plate 0, creuse 1, à désert 2 et plat 3
                                case 0 : printf("renault ");     break;
                                case 1 : printf("citroen ");     break;
                                case 2 : printf("peugeot ");     break;
                                case 3 : printf("mercedes ");    break;
                            }
                            printf("pos %d\n",i);
                        }
                        printf("-------------------------\n");
                    }
                    else
                        printf("file vide\n");
                    break;
                default : fin=1;
            }
        }
    }
    return 0;
}
/*********************************
*/
