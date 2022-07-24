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
*   Chapitre 6 :Les pointeurs										    *
*   1.   Principe du pointeur                                           *
*   1.10 Mise en pratique : base pointeurs                               *
*************************************************************************

/*************************************
Avoir des pointeurs et les manipuler
**************************************
Exercice 1
Dans un programme, déclarer un int, un double et un float. Leur affecter des valeurs
aléatoires entre 600 et 700 avec une valeur décimale.  Afficher les valeurs. Modifier
les valeurs de chaque variable via son adresse mémoire récupérée dans un pointeur et
afficher le nouveau résultat. A l'issue le programme demande s'il faut recommencer ou
quitter.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
char continuer='o';
int i,*pi=&i;
float f,*pf=&f;
double d,*pd=&d;
    srand(time(NULL));

    while(continuer=='o'){
        i=600+rand()%100;
        f=600+((float)rand()/RAND_MAX)*100;
        d=600+((double)rand()/RAND_MAX)*100;
        printf("i=%d,f=%f,d=%lf\n",i,f,d);
        *pi+=100;
        *pf+=100;
        *pd+=100;
        printf("i=%d,f=%f,d=%lf\n",i,f,d);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 2
Dans un programme déclarer deux variables, leur affecter à chacune une valeur et inverser
les valeurs sans toucher directement les variables mais en passant par leurs adresses
mémoire récupérées dans des pointeurs. Afficher avant et après modification. Le programme
quitte si l'utilisateur le demande.
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int tmp,a,b,*pa=&a,*pb=&b;
char continuer='o';
    while(continuer=='o'){
        printf("valeurs de depart :\n");
        a=rand()%100;
        b=rand()%100;
        printf("*pa=%d, *pb=%d\n",*pa,*pb);

        printf("inversion des adresses :\n");
        pa=&b;
        pb=&a;
        printf("*pa=%d, *pb=%d\n",*pa,*pb);

        printf("inversion des valeurs :\n");
        tmp=*pa;
        *pa=*pb;
        *pb=tmp;
        printf("a=%d, b=%d\n",a,b);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 3
Soit une structure personne comprenant des informations de nom, prénom, adresse, age, date
de naissance, nationalité, métier, hobby. Dans un programme :
définir le type
initialiser une structure personne uniquement en passant par l'adresse mémoire
afficher le résultat
recommencer ou quitter.
Modifier le programme pour avoir un tableau de nb structures personne.
Faire une fonction d'initialisation et initialiser le tableau (de préférence avec des
valeurs aléatoires). L'utilisateur peut modifier l'élément de son choix toujours en passant
par l'adresse mémoire via un pointeur.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NBMAX   10
typedef struct{
    char nom[80];
    char prenom[80];
    char adresse[256];
    int age;
    char datenais[80];
    char nationalite[80];
    char metier[80];
    char hobby[80];

}personne;

void affiche(personne e);
personne init(void);

int main()
{
char continuer='o',rep;
int i,id;
personne e, *p=&e;
personne all[NBMAX];

    // une seule
    strcpy(p->nom,"delalande");
    strcpy(p->prenom,"Toto");
    strcpy(p->adresse,"11 rue des marsoins, La-fleur sur mer, 00120");
    p->age=51;
    strcpy(p->datenais,"03/03/1960");
    strcpy(p->nationalite,"Francais");
    strcpy(p->metier,"boulanger");
    strcpy(p->hobby,"patisserie");
    affiche(*p);


    while(continuer=='o'){

        // le tableau
        for(i=0; i<NBMAX; i++){
            all[i]=init();
            affiche(all[i]);
        }
        printf("Modifier un element ?(o/n)");
        scanf("%c",&rep);
        rewind(stdin);
        if(rep=='o'){
            printf("entrer id de l'element :");
            scanf("%d",&id);
            rewind(stdin);
            if(id>=0 && id<NBMAX){
                p=&all[id];
                *p=init();
                affiche(*p);
            }
        }

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }

    return 0;
}
void affiche(personne e)
{
    printf("%s\n",e.nom);
    printf("%s\n",e.prenom);
    printf("%s\n",e.adresse);
    printf("%d\n",e.age);
    printf("%s\n",e.datenais);
    printf("%s\n",e.nationalite);
    printf("%s\n",e.metier);
    printf("%s\n",e.hobby);
    printf("--------------------------\n");
}

personne init()
{
char*n[11]={"aaaaa","bbbbbb","ccccccc","ddddddd","eeeeeeeee","ffffffffffff",
            "gggggggggggg","hhhhhhhhhhhhh","iiiiiiiiii","jjjjjjjjjjj","kkkkkkkk"};

personne e;

    strcpy(e.nom,n[rand()%11]);
    strcpy(e.prenom,n[rand()%11]);
    strcpy(e.adresse,n[rand()%11]);
    e.age=1+rand()%120;
    strcpy(e.datenais,n[rand()%11]);
    strcpy(e.nationalite,n[rand()%11]);
    strcpy(e.metier,n[rand()%11]);
    strcpy(e.hobby,n[rand()%11]);
    return e;
}

/*************************************
Exercice 4
Dans un programme, soit un tableau d'entiers initialisés à 0  :
l'utilisateur entre le nombre nb de modifications qu'il veut faire
faire ensuite les nb modifications (que vous voulez) sur des éléments sélectionnés au hasard,
uniquement si la valeur de l'élément est inférieure à 10. Les modifications sont faites en
utilisant l'adresse mémoire de chaque élément via un pointeur d'entier. quitter ou recommencer
*
#include <stdio.h>
#include <stdlib.h>
#define NBMAX   10

void affiche(int t[])
{
int i;
    for (i=0; i<NBMAX; i++)
        printf("%3d",t[i]);
    putchar('\n');
}

int main()
{
char continuer='o';
int tab[NBMAX]={0},nb,i,*p;

    affiche(tab);
    while (continuer=='o'){

        printf("entrer le nombre de modifications");
        scanf("%d",&nb);
        rewind(stdin);

        while(nb--){
            i=rand()%NBMAX;
            p=&tab[i];
            if(*p<10)
                *p=rand()%100;
        }

        affiche(tab);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }

    return 0;
}

/*************************************
Tests tableaux / pointeurs           *
**************************************
Exercice 5
Dans un programme initialiser un tableau statique de 5 entiers avec des  valeurs comprises
entre 0 et 255 (à la déclaration). Ensuite récupérez l'adresse du tableau avec un pointeur
char* et afficher votre tableau avec le pointeur de char … Que se passe t-il ? Combien de
valeurs pouvez-vous afficher à votre avis ? Quelle boucle permet de parcourir tout l'espace
mémoire du tableau ?
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int tab[5]={16,32,64,128,255};
unsigned char*p=tab;  // unsigned pour que les valeurs ne soient pas interprétées avec le signe

    printf("%p\n",tab);
    printf("%p\n",tab+(sizeof(tab)/4));
    for (p=tab; p<tab+5; p++)
        printf("%d-",*p);  // affiche le contenu de chaque octet de tab à tab + 5 int
    putchar('\n');

    return 0;
}
/*************************************
Exercice 6
Quels résultats fournit ce programme ?

*

// De tête d'abord !
// 024
// 024
// 024
// 420

#include <stdio.h>

int main()
{
int t[3];
int i, j;
int* ptr;

	for (i=0, j=0; i<3; i++)		// 1
	    t[i]=j++ +i;

   for (i=0; i<3; i++)			// 2
	    printf("%d ", t[i]);
	putchar('\n');

   for (i=0; i<3; i++)			// 3
	    printf("%d ", *(t+i));
	putchar('\n');

	for (ptr=t; ptr<t+3; ptr++)	// 4
	    printf("%d ", *ptr);
	putchar('\n');

	for (ptr=t+2; ptr>=t; ptr--)	// 5
	    printf("%d ", *ptr);
	putchar('\n');

	return 0;
}

/*************************************
Exercice 7
Dans un programme, un tableau de 15 entiers est déclaré mais pas de pointeur.
Écrire de deux façons différentes, l'une avec l'opérateur crochet [ ] et l'autre
avec l'opérateur étoile * :
l'initialisation du tableau avec 12 valeurs aléatoires et 3 entrées par l'utilisateur
l'affichage du tableau
la recherche du plus grand
la recherche du plus petit
l'affichage des résultats
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
int t[15],i,max,min;

    printf("opérateur crochet :\n");
    for (i=0; i<12; i++)
        t[i]=rand()%100;
    for (i=12; i<15; i++){
        printf("enter la valeur %d :",i);
        scanf("%d",&t[i]);
        rewind(stdin);
    }
    for (i=0; i<15; i++)
        printf("%d-",t[i]);
    putchar('\n');

    // recherche plus grand / plus petit
    for (i=0, max=0,min=100; i<15; i++){
        if(t[i]>max)
            max=t[i];
        if(t[i]<min)
            min=t[i];
    }
    printf("max : %d\nmin : %d\n",max,min);

    //
    printf("*(t+i) :\n");
    for (i=0; i<12; i++)
        *(t+i)=rand()%100;
    for (i=12; i<15; i++){
        printf("enter la valeur %d :",i);
        scanf("%d",t+i);
        rewind(stdin);
    }
    for (i=0; i<15; i++)
        printf("%d-",*(t+i));
    putchar('\n');

    // recherche plus grand / plus petit
    for (i=0, max=0,min=100; i<15; i++){
        if(*(t+i)>max)
            max=*(t+i);
        if(*(t+i)<min)
            min=*(t+i);
    }
    printf("max : %d\nmin : %d\n",max,min);
    return 0;
}
/*************************************
Exercice 8
Dans un programme, un tableau de 10 entiers est déclaré.
Faire une fonction d'initialisation du tableau en parcourant le tableau avec un pointeur
Faire une fonction d'affichage du tableau avec parcours par un pointeur
Quitter ou recommencer
*
#include <stdio.h>
#include <stdlib.h>

void init(int*p, int nb)
{
int *i;
    for (i=p; i<p+nb; i++)
        *i=rand()%100;
}
void affiche(int*p, int nb)
{
int*i;
    for (i=p; i<p+nb; i++)
        printf("%d-",*i);
    putchar('\n');
}

int main()
{
int t[10];
char continuer='o';
    while(continuer=='o'){
        init(t,10);
        affiche(t,10);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 9
Dans un programme, une matrice de 20 * 15 entiers est déclarée.
Faire une fonction d'initialisation de la matrice dans laquelle la matrice est parcourue
avec un pointeur. Les valeurs seront aléatoires sauf une entrée par l'utilisateur toutes
les 100 valeurs.
Faire une fonction d'affichage pareillement parcourue avec un pointeur.
Quitter ou recommencer
*
#include <stdio.h>
#include <stdlib.h>

void init(int mat[20][15])
{
int *m,*start=&mat[0][0],i,j;
    for (m=start,i=0; i<20; i++) // cause mat et un (*)[15]
        for (j=0; j<15; j++,m++){
            *m=rand()%100;
            if((m-start)%100==99){
                printf("entrer une valeur :");
                scanf("%d",m);
                rewind(stdin);
            }
        }

}
void affiche(int mat[20][15])
{
int *m,i,j;
    for (m=&mat[0][0],i=0; i<20; i++){
        for (j=0; j<15; j++,m++)
            printf("%3d",*m);
        putchar('\n');
    }
}

int main()
{
char continuer='o';
int m[20][15];

    while(continuer=='o'){

        init(m);
        affiche(m);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 10
Dans un programme :
saisir une chaine de caractères
faire une fonction d'affichage de la chaine à l'envers en parcourant la chaine avec un pointeur.
quitter ou recommencer
*
#include <stdio.h>

void affiche(char*s)
{
char*p=s+strlen(s);
    while(p>=s)
        printf("%c",*p--);// parenthèses implicites : *(p--)
    putchar('\n');
}

int main()
{
char continuer='o';
char s[256];

    while(continuer=='o'){
        printf("entrer une chaine :");
        fgets(s,256,stdin);

        affiche(s);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Base allocation dynamique            *
**************************************
Exercice 11
Dans un programme :
allouez de la mémoire pour un char, un entier, un float
initialiser avec des valeurs entrées par l'utilisateur
affichez
quitter si l'utilisateur le demande (sinon recommencer, attention mémoire)
*
#include <stdio.h>
#include <stdlib.h>


int main()
{
char continuer='o';
char*c;
int*i;
float*f;

    while(continuer=='o'){
        // allocation
        c=(char*)malloc(sizeof(char));
        i=(int*)malloc(sizeof(int));
        f=(float*)malloc(sizeof(float));

        printf("entrer un char, un int, un float :");
        scanf("%c%d%f",c,i,f);
        rewind(stdin);

        printf("val : %c,%d, %f\n",*c,*i,*f);

        // libérer la mémoire parce que une allocation a lieu à chaque tour de boucle
        // (ou alors il faut mettre l'allocation avant la boucle et faire le free après
        // la boucle )
        free(c);
        free(i);
        free(f);


        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 12
Dans un programme :
écrire une fonction d'allocation avec contrôle d'erreur pour un entier
initialiser un tableau de 10 pointeurs d'entier
donner des  valeurs décroissantes aux entiers
afficher les valeurs
quitter si l'utilisateur le demande (sinon recommencer, attention mémoire)
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
char continuer='o';
int*tab[10],i;

    while(continuer=='o'){
        for (i=0; i<10; i++){
            tab[i]=(int*)malloc(sizeof(int));
            if(i==0)
                *tab[i]=1000+rand()%100;
            else
                *tab[i]=*tab[i-1]-rand()%100;

            printf("%4d",*tab[i]);
        }
        putchar('\n');

        // déallouer (ou allouer en dehors de la boucle
        for (i=0; i<10; i++)
            free(tab[i]);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 13
Dans un programme, une entité est définie par un nom, un caractère, un code génétique
stocké dans un tableau de 4 entiers (4 séquences), une position, un déplacement, une
apparence, une couleur, éventuellement d'autres traits caractéristiques :
définir un type pour l'entité
déclarer deux pointeurs pour deux entités et initialiser avec des valeurs chacune
des caractéristiques des entités
comparer les caractéristiques des deux entités et afficher le résultat.
quitter si l'utilisateur le demande ou recommencer, attention à la mémoire.

ERRATUM :
à peu près identique à l'exercice 14.Sauf que les fonctions ne sont pas demandées
mais c'est dommage de s'en priver.

*
#include <stdio.h>
#include <stdlib.h>
#define TX  40
#define TY  20

typedef struct {
    char nom[80];
    char l; // une lettre pour le caractère et l'apparence (26 caractères max)
    int gen[4];
    int x,y,dx,dy; // deplacements
    int color;

}entite;

entite* init()
{
char* n[10]={"baaa","zereta","aesrgviod","moqfeigfi","uysdqraem", "tfioyu","rmaiwd","yrf","okghki","ifgh"};
entite *e;
int i;
    e=(entite*)malloc(sizeof(entite));
    strcpy(e->nom,n[rand()%10]);
    e->l=e->nom[0]-('a'-'A');
    for (i=0; i<4; i++)
        e->gen[i]=1+rand()%10;
    e->x=rand()%TX;
    e->y=rand()%TY;
    e->dx=rand()%4-2;
    e->dy=rand()%4-2;
    e->color=1+rand()%254;
    return e;
}
void compare(entite e1, entite e2)
{
    if(strcmp(e1.nom,e2.nom)==0)
        printf("elles ont le meme nom\n");
    else
        printf("elles n'ont pas le meme nom\n");

    if(e1.x<e2.x)
        printf("%s (e1) plus a gauche que %s (e2)\n",e1.nom,e2.nom);
    else
        printf("%s (e2) plus a gauche que %s (e1)\n",e2.nom,e1.nom);

    if(abs(e1.dx)+abs(e1.dy)>abs(e2.dx)+abs(e2.dy))
        printf("%s (e1) plus rapide\n");
    if(e1.color==e2.color)
        printf("meme couleur ");
    if (e1.l!=e2.l)
        printf("caracteres differents\n");

    //(...)
}

int main()
{
char continuer='o';
entite*e1,*e2;

    while(continuer=='o'){

        e1=init();
        e2=init();

        compare(*e1,*e2);

        free(e1);
        free(e2);
        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 14
Dans un programme, reprendre le type défini pour une entité dans l'exercice 13 et :
déclarer deux pointeurs entités
écrire une fonction d'initialisation et initialiser chaque entité
écrire une fonction d'affichage et afficher chaque entité
écrire une fonction qui affiche le nom de l'entité avec le caractère le plus fort
*
#include <stdio.h>
#include <stdlib.h>
#define TX  40
#define TY  20

typedef struct {
    char nom[80];
    char l; // une lettre pour le caractère et l'apparence (26 caractères max)
    int gen[4];
    int x,y,dx,dy; // deplacements
    int color;

}entite;

entite* init()
{
char* n[10]={"baaa","zereta","aesrgviod","moqfeigfi","uysdqraem", "tfioyu","rmaiwd","yrf","okghki","ifgh"};
entite *e;
int i;
    e=(entite*)malloc(sizeof(entite));
    strcpy(e->nom,n[rand()%10]);
    e->l='A'+rand()%26;
    for (i=0; i<4; i++)
        e->gen[i]=1+rand()%10;
    e->x=rand()%TX;
    e->y=rand()%TY;
    e->dx=rand()%4-2;
    e->dy=rand()%4-2;
    e->color=1+rand()%254;
    return e;
}
void compare(entite e1, entite e2)
{
    if(e1.l==e2.l)
        printf("%s et %s ont le meme caractere\n",e1.nom,e2.nom);
    else
        printf("%s a le caractere le plus fort\n",(e1.l>e2.l)? e1.nom:e2.nom);
}

int main()
{
char continuer='o';
entite*e1,*e2;

    while(continuer=='o'){

        e1=init();
        e2=init();

        compare(*e1,*e2);

        free(e1);
        free(e2);
        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 15
Dans un programme, reprendre le type défini pour une entité dans l'exercice 13 et :
déclarer un tableau de pointeurs pour NB_MAX entités
écrire une fonction d'initialisation et initialiser le tableau
écrire une fonction d'affichage et afficher le tableau
écrire une fonction qui affiche le nom de l'entité avec le caractère le plus fort
Attention aux erreurs
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TX      40
#define TY      20
#define NBMAX   50

typedef struct {
    char nom[80];
    char l; // une lettre pour le caractère et l'apparence (26 caractères max)
    int gen[4];
    int x,y,dx,dy; // deplacements
    int color;

}entite;

entite*     init        (void);
void        init_all    (entite*e[]);
void        affiche     (entite e);
void        affiche_all (entite*e[]);
entite      compare     (entite e1, entite e2);
entite      plus_fort   (entite*e[]);
void        libere_all  (entite*e[]);

int main()
{
char continuer='o';
entite*e[NBMAX];

    srand(time(NULL));
    while(continuer=='o'){

        init_all(e);
        affiche_all(e);
        plus_fort(e);
        libere_all(e);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
//
entite* init()
{
char* n[10]={"baaa","zereta","aesrgviod","moqfeigfi","uysdqraem", "tfioyu","rmaiwd","yrf","okghki","ifgh"};
entite *e;
int i;
    e=(entite*)malloc(sizeof(entite));
    strcpy(e->nom,n[rand()%10]);
    e->l='A'+rand()%26;
    for (i=0; i<4; i++)
        e->gen[i]=1+rand()%10;
    e->x=rand()%TX;
    e->y=rand()%TY;
    e->dx=rand()%4-2;
    e->dy=rand()%4-2;
    e->color=1+rand()%254;
    return e;
}
//
void init_all(entite*e[])
{
int i;
    for(i=0; i<NBMAX; i++)
        e[i]=init();
}
//
void affiche(entite e)
{
int i;
    printf("nom         : %s\n",e.nom);
    printf("caractere   : %c\n",e.l);
    printf("genes       : ");
    for (i=0; i<4; i++)
        printf("%d-", e.gen[i]);
    putchar('\n');
    printf("couleur     : %d\n", e.color);
    printf("position    : (%d, %d)\n",e.x,e.y);
    printf("deplacement : (%d, %d)\n",e.dx,e.dy);
    printf("-------------------------------\n");

}
void affiche_all(entite*e[])
{
int i;
    for(i=0; i<NBMAX; i++)
        affiche(*e[i]);
}
entite compare(entite e1, entite e2)
{
    return (e1.l>e2.l)? e1:e2;
}

entite plus_fort(entite*e[])
{
int i;
entite n=*e[0];
    for (i=1; i<NBMAX; i++)
        n=compare(n,*e[i]);
    printf("l'entite %s a le caractere le plus fort %c\n",n.nom, n.l);
    return n;
}

void libere_all(entite*e[])
{
int i;
    for (i=0; i<NBMAX; i++)
        free(e[i]);
}
/*************************************
Exercice 16
Que fait le programme suivant ?, Y a t-il des erreurs, si oui lesquelles ?
comment les corriger ?  :

int main()
{
char*s1;
char s2[80];
int i;

	fgets(s2,100,stdin);
	strcpy(s1, s2);       // ERR : s1 non allouée

	s1=s2;                  // ATTENTION : s1 pointe sur le même bloc que s2
	fgets(s2,100,stdin);    // en fait il n'y a qu'une seule chaine s2
	if (strcmp(s1,s2)==0)   // alors toujours vrai
	    printf("les deux phrase sont identiques\n");
	else
	    printf("elles sont différentes\n");

	s1="bonjour";           // ERR : affectation impossible en C utiliser la fonction strcpy
	printf("s1 :%s\n",s1);
	strcpy(s2,"il fait beau je prends ma canne et mon chapeau");
	printf("s2 :%s\n",s2);

	while(s2[i]){       // ERR : i non initialisé au départ
	    s1[i]=s2[i];    // ATTENTION si s1 plus courte que s2
	    i++;
	}
	printf("s1 :%s\n",s1);
	printf("s2 :%s\n",s2);
	return 0;
}
/*************************************
Tableaux de chaines                  *
**************************************
Exercice 17
Créer un jeu de 52 cartes à partir d'une liste de mots. Au départ, affichez le jeu ordonné
par couleurs. Ensuite, faire une fonction de mélange des cartes,  faire une fonction de
distribution des cartes entre deux joueurs et afficher le jeu de chacun.
*
#include <stdio.h>
#include <stdlib.h>

void creer_jeu(char*j[52])
{
int i,f,c;
    for (i=0,f=3; i<52; i++){
        j[i]=(char*)malloc(sizeof(char)*5);
        memset(j[i],0,5);
        c=i%13;
        if( c+2<=10)
            sprintf(j[i],"%d",c+2);
        else{
            switch(c+2){
                case 11 : strcpy(j[i],"V"); break;
                case 12 : strcpy(j[i],"D"); break;
                case 13 : strcpy(j[i],"R"); break;
                case 14 : strcpy(j[i],"A"); break;
            }
        }
        j[i][strlen(j[i])]=f;
        if(i%13==12)
            f++;
    }
}
//
void affiche_jeu(char*msg,char*j[], int nb)
{
int i;
    printf("JEU %s :\n",msg);
    for (i=0; i<nb; i++){
        printf("%s-",j[i]);
        if(i%13==12)
            putchar('\n');
    }
    printf("---------------------\n");

}
//
void melange_jeu(char*t[52])
{
int i,j,k;
char*tmp;
    for (k=0; k<1000;k++){ // 1000 permutations
        i=rand()%52;
        j=rand()%52;
        if(i!=j){
            tmp=t[i];
            t[i]=t[j];
            t[j]=tmp;
        }
    }
}
void distrib(char*j[],int nb,char*j1[],char*j2[])
{
int i,k;
    for (i=0,k=nb/2; i<nb/2; i++,k++){
        j1[i]=j[i];
        j2[i]=j[k];
    }
}
int main()
{
char* j[52];
char* j1[26];
char* j2[26];
    creer_jeu(j);
    affiche_jeu("ordonne",j,52);
    melange_jeu(j);
    affiche_jeu("melange",j,52);
    distrib(j,52,j1,j2);
    affiche_jeu("joueur 1",j1,26);
    affiche_jeu("joueur 2",j2,26);

    return 0;
}

/*************************************
Exercice 18
soit une liste de mot :
char*liste[ ={"moule","frite","patate","pomme","camembert",
              "gruyère","crêpes", "miel", "cidre","omelette","fin"};
Faire un programme qui affiche la liste telle quelle, puis la liste classée en ordre alphabétique.
Le classement par ordre alphabétique est fait dans une fonction qui reçoit la liste en argument.
*
#include <stdio.h>
#include <stdlib.h>

void classement(char*l[])
{
int i,j;
char*tmp;
    for (i=0; strcmp(l[i],"fin")!=0; i++)
        for (j=i+1; strcmp(l[j],"fin")!=0; j++ )
            if(strcmp(l[j],l[i])<0){
                tmp=l[j];
                l[j]=l[i];
                l[i]=tmp;
            }


}

int main()
{
char*liste[] ={"moule","frite","patate","pomme","camembert",
              "gruyere","crepes", "miel", "cidre","omelette","fin"};
int i;
    for (i=0; strcmp(liste[i],"fin")!=0; i++)
        printf("%s\n",liste[i]);

    classement(liste);
    printf("----------------------------\n");

    for (i=0; strcmp(liste[i],"fin")!=0; i++)
        printf("%s\n",liste[i]);

    return 0;
}
*/
