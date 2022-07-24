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
*   Chapitre 3 : Variables ensembles (structures et tableaux)           *
*   8. Gestion des variables                                            *
*   8.4 Mise en pratique : gestion de variables                         *
*************************************************************************

/*********************************
Exercice 1
De tête, quel résultat donne le programme suivant ?
#include<stdio.h>

int i=0;
int main()
{
int i=1;
	printf("i=%d\n",i);
	{
	int i=2;
       printf("i=%d\n",i);
	    {
	        i+=1;
	        printf("i=%d\n",i);
	    }
	    printf("i=%d\n",i);
	}
	printf("i=%d\n",i);
}
*
#include <stdio.h>
#include <stdlib.h>

// à faire d'abord de tête :
// i=1
// i=2
// i=3
// i=3
// i=1

// puis vérifier
int i=0;
int main()
{
int i=1;
	printf("i=%d\n",i);
	{
	int i=2;
       printf("i=%d\n",i);
	    {
	        i+=1;
	        printf("i=%d\n",i);
	    }
	    printf("i=%d\n",i);
	}
	printf("i=%d\n",i);
}

/*********************************
Exercice 2
De tête, quel résultat donne le programme suivant ?
#include<stdio.h>

int f1(int);
void f2(void);

int n=10, q=2;

int main()
{
int n=0, p=5;
	n=f1(p);
	printf("A : dans main, n=%d, p=%d, q=%d\n",n,p,q);
	f2();
	return 0;
}

int f1(int p)
{
int q;
	q=2*p+n;
	printf("B : dans f1, n=%d, p=%d, q=%d\n",n,p,q);
	return q;
}

void f2(void)
{
int p=q*n;
	printf("C : dans f2, n=%d, p=%d, q=%d\n",n,p,q);

}
*

// d'abord de tête
//  B dans f1, 10, 5, 20
//  A dans main 20, 5, 2
//  C dans f2 10, 20, 2
//

#include<stdio.h>

int f1(int);
void f2(void);

int n=10, q=2;

int main()
{
int n=0, p=5;
	n=f1(p);
	printf("A : dans main, n=%d, p=%d, q=%d\n",n,p,q);
	f2();
	return 0;
}

int f1(int p)
{
int q;
	q=2*p+n;
	printf("B : dans f1, n=%d, p=%d, q=%d\n",n,p,q);
	return q;
}

void f2(void)
{
int p=q*n;
	printf("C : dans f2, n=%d, p=%d, q=%d\n",n,p,q);

}

/*********************************
Exercice 3
De tête, quel résultat donne le programme suivant ?
#include<stdio.h>
#define LOW		0
#define HIGH	5
#define CHANGE	2

void workover(int i);
int reset(int i);
int i=LOW;

int main()
{
int i=HIGH;
	reset(i/2);
	printf("i=%d\n",i);
	reset (i=i/2);
	printf("i=%d\n",i);
	i=reset(i/2);
	printf("i=%d\n",i);

	workover(i);
	printf("i=%d\n",i);
}

void workover(int i)
{
	i=(i%i) * ((i*i)/(2*i) +4);
	printf("i=%d\n",i);
}

int reset (int i)
{
	if (i<=CHANGE)
	    i=HIGH;
   else
	    i=LOW;
	return i;
}
*

// i= 5, 2, 5, 0, 5


#include<stdio.h>
#define LOW		0
#define HIGH	5
#define CHANGE	2

void workover(int i);
int reset(int i);
int i=LOW;

int main()
{
int i=HIGH;
	reset(i/2);
	printf("i=%d\n",i);
	reset (i=i/2);
	printf("i=%d\n",i);
	i=reset(i/2);
	printf("i=%d\n",i);

	workover(i);
	printf("i=%d\n",i);
}

void workover(int i)
{
	i=(i%i) * ((i*i)/(2*i) +4);
	printf("i=%d\n",i);
}

int reset (int i)
{
	if (i<=CHANGE)
	    i=HIGH;
   else
	    i=LOW;
	return i;
}
/*********************************
Exercice 4
Soit la fonction  :
void wait(int tmps)
{
int start=clock();
   while (clock()<start+tmps){}
}

Modifiez cette fonction afin de déclencher une action tous les nb millisecondes
mais sans arrêter le programme. Faire un programme de test.
*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int wait(int tmps)
{
static int start=0;
int res=0;
    if(clock()>start+tmps){
        start=clock();
        res=1;
    }
    return res;
}

int main()
{
    while (!kbhit()){

        if(wait(10))
            putchar('A'+rand()%26);

        putchar('.');

    }
    return 0;
}
/*********************************
Exercice 5
Faire deux fonctions différentes appelées dans une même boucle.  Chaque fonction
est ralentie avec une valeur différente et chacune affiche a chaque appel le nombre
total de fois où elles a été appelée. Tester dans un programme.
*
#include <stdio.h>
#include <stdlib.h>
void f1(int tmps)
{
static int start=0;
static nb=0;
    if(start+tmps<clock()){
        printf("f1 %d\n",++nb);
        start=clock();
    }
}
void f2(int tmps)
{
static int start=0;
static nb=0;
    if(start+tmps<clock()){
        printf("f2 %d\n",++nb);
        start=clock();
    }
}
int main()
{
    while(!kbhit()){

        f1(50);  // 4 f1 pour un f2
        f2(200);

    }
    return 0;
}

/*********************************
Exercice 6
Soit un tableau d'entiers déclaré en global, faire deux fonctions d'initialisation
(valeurs aléatoires) une avec paramètre, l'autre sans. Faire également deux fonctions
d'affichage une avec paramètre et l'autre sans. Tester dans un programme.
*
#include <stdio.h>
#include <stdlib.h>

int TAB[10];

void init1();
void init2(int t[]);
void affiche1();
void affiche2(int t[]);

int main()
{
    init1();
    affiche1();
    affiche2(TAB);
    printf("--------------------\n");
    init2(TAB);
    affiche1();
    affiche2(TAB);

    return 0;
}

void init1()
{
int i;
    for (i=0; i<10; i++)
        TAB[i]=rand()%100;
}
void init2(int t[])
{
int i;
    for (i=0; i<10; i++)
        t[i]=rand()%100;
}
void affiche1()
{
int i;
    printf("affiche1 :\n");
    for (i=0; i<10; i++)
        printf("%3d",TAB[i]);
    putchar('\n');
}
void affiche2(int t[])
{
    int i;
    printf("affiche2 :\n");
    for (i=0; i<10; i++)
        printf("%3d",t[i]);
    putchar('\n');
}
/*********************************
*/

