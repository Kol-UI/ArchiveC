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
*   Chapitre 4 : Les tableaux								            *
*   3. Tableaux et structures                                           *
*   3.4 Mise en pratique : tableaux de structures                       *
*************************************************************************



/*********************************
Exercice 1
Soit les deux structures :
struct date{
		int jour, mois, annee;
};
struct personne{
		char nom[80];
		struct date date_embauche;
		struct date date_poste;
};
Ecrire une fonction pour initialiser une struct personne.
Ecrire une fonction d'affichage  afin d'obtenir :

nom : TOTO
date embauche (jj mm aa) : 09 09 10
date poste = date embauche ? (O/N)  : O

OU

nom : TOTO
date embauche (jj mm aa) : 09 09 10
date poste = date embauche ? (O/N)  : N
date poste (jj mm aa) :  01 01 11


ERRATUM : il manque à cet exercice (déjà donné en B.4 page 158 à propos des
structure avec les fonctions) la question :
- comment faire pour 100 personnes ?

*
#include <stdio.h>
#include <stdlib.h>

typedef struct {
		int j, m, a;
}date;
typedef struct {
		int identifiant;
		date de;
		date dp;
}personne;

personne init()
{
personne p;

    // des valeurs aléatoires pour tester
    p.identifiant=rand()%2000;
    p.de.j=rand()%29;
    p.de.m=rand()%12+1;
    p.de.a=rand()%13;

    p.dp.j=rand()%29;
    p.dp.m=rand()%12+1;
    p.dp.a=rand()%13;

    //printf("identifiant ? ");
    //scanf("%d",&p.identifiant);
    //rewind(stdin);
    //printf("date embauche (jj mm aa) : ");
    //scanf("%d%d%d",&p.de.j,&p.de.m,&p.de.a );
    //rewind(stdin);
    //printf("date poste (jj mm aa) : ");
    //scanf("%d%d%d",&p.dp.j,&p.dp.m,&p.dp.a );
    //rewind(stdin);
    return p;
}
void affiche(personne p)
{
    printf("Identifiant : %d\n",p.identifiant);
    printf("date embauche (jj mm aa) : %3d%3d%3d\n",p.de.j,p.de.m,p.de.a);
    if (p.de.j==p.dp.j && p.de.m==p.dp.m &&p.de.a==p.dp.a )
        printf("date poste = date embauche ? (O/N)  : 0\n");
    else{
        printf("date poste = date embauche ? (O/N)  : N\n");
        printf("date poste (jj mm aa) :  %3d%3d%3d\n",p.dp.j,p.dp.m,p.dp.a);
    }
    printf("-------------------------------\n");
}

int main()
{
personne p[100];
int i;
    for (i=0; i<100; i++){
        p[i]=init();
        affiche(p[i]);
    }
    return 0;
}

/*********************************
Exercice 2
Soit dans un jeu vidéo une entité en mode console. Elle est définie par une position,
un déplacement, un type (rampant, grouillant, serpentant, plombant, assommant),
une couleur et une lettre. L'entité a également un nom et une série de taux :
taux d'agressivité, de colère, de convoitise,  de faim, de peur.
Définir la structure de données pour coder une entité. Comment avoir 100 entités ?
Faire une fonction d'initialisation, une fonction de mise à 0 (reset) et une fonction
d'affichage. Tester dans un programme avec un menu : quitter, afficher, initialiser, reset.
Ajouter une fonction pour animer les entités (utiliser la fonction void gotoxy(int x, int y)
fournie en annexe) et quelques fonctions qui permettent aux entités d'établir des relations
entre elles.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define     TX          80  // taille zone de jeu
#define     TY          20
#define     MAXENTITE   100
enum{AGRESS,COLERE,CONVOIT,FAIM,PEUR,MAXTAUX};// identificateur des taux
enum{EFFACE,COLOR};
typedef struct {
    float x,y;      // position
    float dx, dy ;  // déplacement
    int type;       // hystérifique (-1), rampant 0, grouillant 1, serpentant 2,plombant 3, assommant 4
    char l;         // nom (lettre)
    int taux[MAXTAUX]; //AGRESS,COLERE,CONVOIT,FAIM,PEUR
}entite;

entite      init            (void);
entite      reset           (entite e);
void        affiche         (entite e, int efface);
entite      move            (entite e);
void        cntl_all        (void);
void        textcolor       (int color);
void        gotoxy          (int x, int y);
void        attendre        (int duree);

int main()
{
entite ALL[MAXENTITE],e;  // pour avoir 100 entités
int i,j,k,res,resj;

    for (i=0; i<MAXENTITE; i++)
        ALL[i]=init();

    while(!kbhit()){

        for (i=0; i<MAXENTITE; i++){

            affiche(ALL[i],EFFACE);
            ALL[i]=move(ALL[i]);

            // les rencontres :
            // chaque entité non hystérifiée regarde toutes les autres (coordonnées)
            // si rencontre, l'entité la plus cool gagne (l'autre est hystérifiée)

            // pour pouvoir écrire une fonction  il faut mettre le tableau ALL en globale ou
            // le passer en paramètre, voir partie suivante G page 195.

            e=ALL[i];
            for (j=0; j<MAXENTITE && e.type>=0; j++){

                // si rencontre avec une entité non hystérifiée
                if(ALL[j].type>=0 && (int)e.x==(int)ALL[j].x && (int)e.y==(int)ALL[j].y  ){
                    // je prends juste l'adition des taux
                    res=resj=0;
                    for(k=0; k<MAXTAUX;k++){
                        res+=e.taux[k];
                        resj+=ALL[j].taux[k];
                    }
                    // le plus tranquille et serein gagne, l'autre prend la couleur (bleue)
                    // de l'hystérie générale et est paralysée
                    if(res<resj)
                        ALL[j]=reset(ALL[j]);
                    else if (res>resj)
                        e.type=-1;
                    // si elles sont identiques, rien
                }
            }
            affiche(ALL[i],COLOR);
        }
        attendre(50);
    }
    gotoxy(0,TY+2);
    return 0;
}
//
entite init()
{
entite e;
int i;
    e.x=rand()%TX;
    e.y=rand()%TY;
    e.dx=((float)rand()/RAND_MAX)*4-2;
    e.dy=((float)rand()/RAND_MAX)*4-2;
    e.type=rand()%5;
    e.l='A'+rand()%26;
    for(i=0; i<MAXTAUX;i++)
        e.taux[i]=rand()%100;
    return e;
}
//
entite reset(entite e)
{
    e.dx=e.dy=0;
    e.l='H';
        e.type=-1;
    return e;
}
//
void affiche (entite e, int efface)
{
    gotoxy(e.x,e.y);
    textcolor( (e.type+10) * efface); // le type utilisé pour une couleur
    putchar(e.l);
}
//
entite move(entite e)
{
    e.x+=e.dx;
    if(e.x<0){
        e.dx=((float)rand()/RAND_MAX)*2+0.1;
        e.x=0;
    }
    else if(e.x>=TX){
        e.dx= -(((float)rand()/RAND_MAX)*2+0.1);
        e.x=TX-1;
    }

    e.y+=e.dy;
    if(e.y<0){
        e.dy=((float)rand()/RAND_MAX)*2+0.1;
        e.y=0;
    }
    else if(e.y>=TY){
        e.dy= -(((float)rand()/RAND_MAX)*2+0.1);
        e.y=TY-1;
    }
    return e;
}
//
void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
//
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
//
void attendre(int duree)
{
int start=clock();
    while(start+duree>clock()){}
}
/*********************************
Exercice 3
Faire carnet de NBMAX rendez-vous. Un rendez-vous sera défini par :
Un libellé
Un lieu de rendez-vous
Une date (choisissez un format qui permettra le tri)
Un horaire de début
Un horaire de fin
Une catégorie (bureau, personnel, loisirs etc.)
Tout autre champ pouvant vous sembler utile
1) définir le ou les types nécessaires à une bonne structure de données
2) Dans un menu donnez les possibilités de :
saisir un rendez-vous
afficher tous les rendez-vous
afficher une catégorie de rendez-vous
supprimer un rendez-vous
supprimer automatiquement des rendez-vous en doublon
ranger en ordre chronologique les rendez-vous
quitter
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RVMAX       30

typedef struct{
    int an,mois,jour;
}DATE;
typedef struct{
    int heure,minute;
}HEURE;
typedef struct{
    int id;
    char lieu[256];
    DATE date;
    HEURE debut,duree; // je remplace fin par durée pour simplifier
    int categorie; // 0 famille, 1 professionnel, 2 jeux, 3 recherche, 4 divers, 5 tous
    char remarque[2048];
}RV;
enum{VIDE=-1,FAMILLE,PROFESS,JEUX,RECHERCH,DIVERS,TOUS};

int     menu        (void);
RV      alea        (int id);
RV      saisie      (int id);
int     libre       (RV r);
void    afficher    (RV r, int categorie);
RV      supp        (RV r);
int     egaux       (RV r1, RV r2);

// remarque :
// comme dans l'exercice précédent le tableau n'est pas en global et
// nous n'écrivons pas de fonction avec tableau en paramètre nous attendons
// la partie G suivante pour le faire). C'est pourquoi Tous les traitements
// concernant l'ensemble du tableau sont faits dans le main.

int main()
{
int i,j,fin=0,cat,id,e;
RV ALL[RVMAX]={{0}},tmp;

    srand(time(NULL));
    // mise à VIDE tous les rendez-vous
    for(i=0;i<RVMAX;i++)
        ALL[i].categorie=VIDE;

    while(!fin){
        switch(menu()){
            case 0 : // remplir avec des RV aleatoires
                for(i=0; i<RVMAX; i++)
                    ALL[i]=alea(i);
                break;

            case 1 : // saisir un RV
                // obtenir une position libre
                for(i=0; i<RVMAX && !libre(ALL[i]); i++)
                    ;
                if(i!=RVMAX)
                    ALL[i]=saisie(i);
                else
                    printf("plus de place dans le carnet\n");
                break;

            case 2 : // afficher tous les RV
                for(i=0; i<RVMAX; i++)
                    afficher(ALL[i],TOUS);
                break;

            case 3 : // afficher une categorie
                printf("Categorie ? (0 famille, 1 professionnel, 2 jeux, 3 recherche, 4 divers)\n");
                scanf("%d",&cat);
                rewind(stdin);
                for(i=0; i<RVMAX; i++)
                    afficher(ALL[i],cat);
                break;

            case 4 : // supprimer un RV
                printf("entrer identificateur du RV a supprimer : ");
                scanf("%d",&id);
                rewind(stdin);
                // attention l'identificateur ne correspond pas nécessairement à la position dans le tableau
                // (cause tri chronologique)
                for (i=0; i<RVMAX;i++) // et il faut trouver le RV
                    if(ALL[i].id==id)
                        break;
                ALL[i]=supp(ALL[i]);    // supprimer le RV
                break;

            case 5 : // supprimer doublon
                for(i=0; i<RVMAX; i++)
                    for(j=0; j<RVMAX; j++){
                        if(i==j || libre(ALL[i])) // éviter les RV libres
                            continue;
                        if (egaux(ALL[i], ALL[j]))
                            ALL[id]=supp(ALL[j]);
                    }
                break;

            case 6 : // ranger en ordre chronologique

                for (e=0; e<5; e++){// an,mois,jour,heure,minute

                    for(i=0; i<RVMAX; i++){
                        if(libre(ALL[i]))
                            continue;

                        id=i;
                        for (j=i+1; j<RVMAX; j++){
                            if(libre(ALL[j]))
                                continue;

                            switch(e){

                                case 0 :  // année
                                    if(ALL[j].date.an<ALL[id].date.an)
                                        id=j;
                                    break;

                                case 1 : // mois
                                    if(ALL[j].date.an==ALL[id].date.an &&    // si même année
                                       ALL[j].date.mois<ALL[id].date.mois)
                                       id=j;
                                    break;

                                case 2 : // jour
                                    if(ALL[j].date.an==ALL[id].date.an &&    // si même année
                                       ALL[j].date.mois==ALL[id].date.mois && // si même mois
                                       ALL[j].date.jour<ALL[id].date.jour)
                                       id=j;
                                    break;

                                case 3 : // heure
                                    if(ALL[j].date.an==ALL[id].date.an &&    // si même année
                                       ALL[j].date.mois==ALL[id].date.mois && // si même mois
                                       ALL[j].date.jour==ALL[id].date.jour && // si même jour
                                       ALL[j].debut.heure<ALL[id].debut.heure)
                                       id=j;
                                    break;

                                case 4 : // minute
                                    if(ALL[j].date.an==ALL[i].date.an &&    // si même année
                                       ALL[j].date.mois==ALL[i].date.mois && // si même mois
                                       ALL[j].date.jour==ALL[i].date.jour && // si même jour
                                       ALL[j].debut.heure==ALL[i].debut.heure&&// si même heure
                                       ALL[j].debut.minute<ALL[i].debut.minute)
                                       id=j;
                                    break;
                            }
                        }
                        if(id!=i){
                            tmp=ALL[i];
                            ALL[i]=ALL[id];
                            ALL[id]=tmp;
                        }
                    }
                }
                break;
            default : fin=1;
        }
    }
    return 0;
}
int menu()
{
int choix=-1;
    printf("0 : remplir avec des RV aleatoires\n"
           "1 : saisir un RV\n"
           "2 : afficher tous les RV\n"
           "3 : afficher une categorie\n"
           "4 : supprimer un RV\n"
           "5 : supprimer doublon\n"
           "6 : ranger en ordre chronologique\n"
           "---------------------------------\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}

RV alea(int id)
{
char adresse[5][80]={
    "12 rue de la tourelle 57 432 Les pingoins",
    "Sous le troisieme chene entree sud de la foret",
    "la gare",
    "chez gegene",
    "465201, etage 300 tour la plombe, vitry les chameaux 107 657 760"};
RV r;
    r.id=id;
    r.categorie=rand()%TOUS;
    r.date.an=2011+rand()%2;
    r.date.mois=1+rand()%11;
    switch(r.date.mois){
        case 1 :
        case 3 :
        case 5 :
        case 7 :
        case 8 :
        case 10 :
        case 12 : r.date.jour=rand()%32; break;
        case 2  : r.date.jour=rand()%29; break;
        default : r.date.jour=rand()%31;
    }
    r.debut.heure=rand()%24;
    r.debut.minute=rand()%60;
    r.duree.heure=rand()%5;  // 4 heures max
    r.duree.minute=rand()%60;
    strcpy(r.lieu, adresse[rand()%5]);
    // pas de remarque
    return r;
}

RV saisie(int id)
{
RV r;
    r.id=id;
    printf("categorie ? (0 famille, 1 professionnel, 2 jeux, 3 recherche, 4 divers ");
    scanf("%d",&r.categorie);
    rewind(stdin);

    printf("date ? (jj mm AAAA) ");
    scanf("%d%d%d",&r.date.jour,&r.date.mois,&r.date.an);
    rewind(stdin);

    printf("heure ? (h m) ");
    scanf("%d%d",&r.debut.heure,&r.debut.minute);
    rewind(stdin);

    printf("duree ? (h m) ");
    scanf("%d%d",&r.duree.heure,&r.duree.minute);
    rewind(stdin);

    printf("lieu ? ");
    fgets(r.lieu,256,stdin);
    rewind(stdin);

    printf("des remarques ? ");
    fgets(r.remarque,2048,stdin);
    rewind(stdin);
    return r;
}

int libre (RV r)
{
    return (r.categorie==VIDE);
}

void afficher(RV r, int categorie)
{
    if( !libre(r) && (r.categorie==categorie || categorie==TOUS)){
        printf("categorie   : ");
        switch(r.categorie){ //0 famille, 1 professionnel, 2 jeux, 3 recherche, 4 divers,
            case FAMILLE  : printf("famille\n");       break;
            case PROFESS  : printf("professionnel\n"); break;
            case JEUX     : printf("jeux\n");          break;
            case RECHERCH : printf("recherche\n");     break;
            case DIVERS   : printf("divers\n");        break;
        }
        printf("date        : %2d/%2d/%2d\n",r.date.jour,r.date.mois,r.date.an);
        printf("heure debut : %2d:%2d\n",r.debut.heure,r.debut.minute);
        printf("duree       : %2dh %2d\n",r.duree.heure,r.duree.minute);
        printf("adresse     : %s\n",r.lieu);
        printf("identificateur : %d\n", r.id);
        printf("---------------------------------------\n");
    }
}
RV supp(RV r)
{
    r.categorie=VIDE;
    return r;
}

int egaux(RV r1, RV r2)
{
    return( strcmp(r1.lieu,r2.lieu)==0 &&
            r1.date.an==r2.date.an &&
            r1.date.mois==r2.date.mois&&
            r1.debut.heure==r2.debut.heure&&
            r1.debut.minute==r2.debut.minute&&
            r1.categorie==r2.categorie
            );
}

/*********************************
Exercice 4
Soit la structure suivante :

struct point{
	int x, y, color;
};

Dans un programme déclarer un tableau de NB_POINT (par exemple 10).
Faire une fonction d'initialisation. Cette fonction initialise chaque point
soit au hasard soit par des valeurs entrées par l'utilisateur.
Faire une fonction d'affichage
Faire une fonction qui permet de modifier les valeurs d'un des points du tableau.
Faire une fonction de mise à zéro de toutes les valeurs du tableau.
Donner un menu utilisateur avec les commandes : quitter, initialiser, afficher,
modifier, mise à 0
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define     TX          40  // taille zone de jeu
#define     TY          20
#define PTMAX           50
enum{EFFACE,COLOR};

typedef struct {
	int x, y, color;
}t_point;

int         menu            (void);
t_point     init            (void);
t_point     modif           (t_point p);
void        affiche         (t_point p, int color);
void        textcolor       (int color);
void        gotoxy          (int x, int y);

int main()
{
t_point ALL[PTMAX]={{0}};
int fin=0,i;

    while(!fin){

        switch(menu()){
            case 1 :
                for(i=0; i<PTMAX; i++)
                    ALL[i]=init();
                break;
            case 2 :
                for(i=0; i<PTMAX; i++)
                    affiche(ALL[i],COLOR);
                break;
            case 3 :
                gotoxy(0,TY+1);
                textcolor(15);
                printf("indice du point a modifier(entre 0 et %d)? ",PTMAX);
                scanf("%d",&i);
                rewind(stdin);
                ALL[i]=modif(ALL[i]);
                break;
            case 4 :
                // effacer avant de perdre les coordonnées
                for(i=0; i<PTMAX; i++)
                    affiche(ALL[i],EFFACE);

                // mise à 0, soit
                for(i=0; i<PTMAX; i++)
                    ALL[i]= ((t_point){0,0,0});

                // soit
                //memset(ALL,0,sizeof(t_point)*PTMAX);
                break;
            default : fin=1;
        }
    }
    gotoxy(0,TY+5);
    return 0;
}
// menu
int menu()
{
int res=0;

    textcolor(13);
    gotoxy(TX+1,TY/2-2);
    printf("1 : initialiser\n");
    gotoxy(TX+1,TY/2-1);
    printf("2 : afficher\n");
    gotoxy(TX+1,TY/2);
    printf("3 : modifier\n");
    gotoxy(TX+1,TY/2+1);
    printf("4 : mise a zero\n" );
    gotoxy(TX+1,TY/2+2);
    scanf("%d",&res);
    rewind(stdin);
    return res;
}

// initialisation
t_point init()
{
t_point p;

    p.x=rand()%TX;
    p.y=rand()%TY;
    p.color= 1+rand()%255;
    return p;
}
// affichage
void affiche(t_point p, int color)
{
    gotoxy(p.x,p.y);
    textcolor(p.color*color);
    putchar('A'+rand()%26);
}
// modification d'un point
t_point modif(t_point p)
{
int i;
char c;
    affiche(p,EFFACE);  // effacer avant éventuelle perte des coordonnées
    gotoxy(0,TY+2);
    textcolor(15);
    printf("modifier x ?(o/n)");
    scanf("%c",&c);
    rewind(stdin);
    if(c=='o'){
        printf("entrer x : ");
        scanf("%d",&p.x);
        rewind(stdin);
    }
    printf("modifier y ?(o/n)");
    scanf("%c",&c);
    rewind(stdin);
    if(c=='o'){
        printf("entrer y : ");
        scanf("%d",&p.y);
        rewind(stdin);
    }
    printf("modifier color ?(o/n)");
    scanf("%c",&c);
    rewind(stdin);
    if(c=='o'){
        printf("entrer color : ");
        scanf("%d",&p.color);
        rewind(stdin);
    }
    affiche(p,COLOR);// réafficher avec nouvelles et/ou anciennes valeurs

    // effacer texte
    textcolor(0);
    for (i=1; i<8; i++){
        gotoxy(0,TY+i);
        printf("%60s"," ");
    }
    return p;
}
//
void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
//
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
//

/*********************************
Exercice 5
Faire un programme qui permet d'afficher le signe du zodiaque à partir d'un
jour et d'un mois de naissance. Le jour est entré sous forme de nombre et le
mois sous forme de chaine de caractères. Voici les différents signes avec leur
période :

Capricorne      23 décembre - 19 janvier
Verseau         20 janvier - 19 février
Poisson         20 février - 20 mars
Bélier          21 mars - 19 avril
Taureau         20 avril - 20 mai
Gémeau          21 mai - 20 juin
Cancer          21 juin - 21 juillet
Lion            22 juillet - 22 aout
Vierge          23 aout - 22 septembre
Balance         23 septembre - 22 octobre
Scorpion        23 octobre - 21 novembre
Sagittaire      22 novembre - 22 décembre

Exemple d'exécution :

donner votre jour et votre mois de naissance :
11 july
*** erreur de nom de mois****
donner votre jour et votre mois de naissance :
16 janvier
vous êtes né sous le signe : capricorne

*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Algorithme 1:
// En fait pour savoir le signe à partir d'un jour et d'un mois
// il suffit de chercher le mois et ensuite de comparer la date de début
// si < c'est le signe précédent si >= c'est le signe courant.
// La structure de données peut être un tableau de 12 structures contenant chacune
// le signe la mois et la date de début.

typedef struct{
    int jour;  // début signe jour et mois
    char mois[80];
    char signe[80];
}SIGNE;

int main()
{
SIGNE date[12]={
                {23,"decembre","Capricorne"},
                {20,"janvier","Verseau"},
                {20,"fevrier","Poisson"},
                {21,"mars","Belier"},
                {20,"avril","Taureau"},
                {21,"mai","Gemeaux"},
                {21,"juin","Cancer"},
                {22,"juillet","Lion"},
                {23,"aout","Vierge"},
                {23,"septembre","Balance"},
                {23,"octobre","Sagittaire"},
                {22,"novembre","Scorpion"}
                };
int i,res,jour;
char mois[80],encore='o';

    while(encore=='o'){
        do{
            printf("entrer le mois de votre naissance (en minuscules) : ");
            scanf("%s",mois);
            rewind(stdin);
            for (i=0, res=0; i<12 && res==0; i++)
                if(strcmp(mois,date[i].mois)==0)
                    res=1;
            if(res==0)
                printf("*** erreur de nom de mois****\n");
        }while(res==0);

        printf("entrer le jour de votre naissance :");
        scanf("%d",&jour);
        rewind(stdin);

        printf("votre signe est : ");
        // 1 chercher le mois
        for (i=0, res=0; i<12; i++)
            if(strcmp(mois,date[i].mois)==0)
                if(jour<date[i].jour) // trouve le signe à partir du jour
                    printf("%s\n",date[(i-1+12)%12].signe);// précédent
                else
                    printf("%s\n",date[i].signe);// courant

        printf("encore ? (o/n)");
        scanf("%c",&encore);
        rewind(stdin);

    }
    return 0;
}

/*********************************
Exercice 6 :
Écrire un programme qui traduit une phrase entée au clavier en morse.
Les caractères susceptibles d'être codés sont les 26 lettres de l'alphabet,
les chiffres de 0 à 9 et le point.
Si le texte contient d'autres caractères que ceux-ci le programme affichera
des points d'interrogation à la place du code morse. Voici les codes morses :
A       B       C       D       E       F       G       H       I       J
.-      -...    -.-.    -..     .       ..-.    --.     ....    ..      .---

K       L       M       N       O       P       Q       R       S       T
-.-     .-..    --      -.      ---     .--.    --.-    .-.     ...     -

U       V       W       X       Y       Z
..-     ...-    .--     -..-    -.--    --..

0       1       2       3       4       5       6       7       8       9
-----   .----   ..---   ...--   ....-   .....   -....   --...   ---..   ----.

le point
.-.-.-

Chaque code est terminé par un ou deux espaces, un espace par des points d'interrogation,
par exemple "le langage C" donne :
.-..  .  ????? .-..  .-  -.  --.  .-  --.  .  ?????  -.-.
Le programme quitte uniquement si l'utilisateur le souhaite.


REMARQUE :
L'exercice 6 peut être traité avec juste un tableau de chaines de caractères (tableau de
tableaux de char). De ce fait cet exercice peut être déplacé en chap3 E.5.


*
#include <stdio.h>
#include <stdlib.h>

int main()
{
char code[][10]={
".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ",  // a-j
"-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ",// k-t
"..- ","...- ",".-- ","-..- ","-.-- ","--.. ",   // u-z
"----- ",".---- ","..--- ","...-- ","....- ","..... ","-.... ","--... ","---.. ","----. "// 0-9
//".-.-.- " // le point
};

char encore='o', s[256];
int i;

    while (encore=='o'){

        printf("entrer une phrase (en minuscules): ");
        fgets(s,256,stdin);
        rewind(stdin);
        for (i=0; s[i]!='\0'; i++){
            if(s[i]>='a' && s[i]<='z')
                printf("%s",code[s[i]-'a']);
            else if(s[i]>='0' && s[i]<='9')
                printf("%s",code[s[i]-'0'+27]);
            else if(s[i]=='.')
                printf(".-.-.- ");
            else if(s[i]==' ')
                printf("????? ");
        }
        putchar('\n');



        printf("encore ? (o/n)");
        scanf("%c",&encore);
        rewind(stdin);
    }


    return 0;
}

/*********************************
Exercice 7
A partir des données de l'exercice précédent, faire un traducteur dans l'autre sens du  morse
vers le langage normal. Le programme donne un menu : entrer un message en morse, générer un
pseudo message en morse (génération aléatoire du message), quitter.
Chaque message est traduit et affiché.

REMARQUE :
L'exercice 7, comme le 6 peut être traité avec juste un tableau de chaines de caractères
(tableau de tableaux de char). De ce fait cet exercice peut être déplacé en chap3 E.5.

*
// solution 1 avec le message décomposé en plusieurs chaines de caractères
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int menu()
{
int choix;
    printf("1 : entrer un message en morse\n"
           "2 : generer un pseudo message en morse\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}

int main()
{
char code[][10]={
".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ",  // a-j
"-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ",// k-t
"..- ","...- ",".-- ","-..- ","-.-- ","--.. ",   // u-z
"----- ",".---- ","..--- ","...-- ","....- ","..... ","-.... ","--... ","---.. ","----. "// 0-9
//".-.-.- " // le point
};

char s[256][10];
int i,j, fin=0,nbmot,nbcode,l,pos;


    while (!fin){

        memset(s,0,sizeof(char)*256*10); // tableau réinitialisé à 0
        switch(menu()){

            case 1 : // entrer un message en morse
                printf("nombre de lettres du message ? " );
                scanf("%d",&pos);
                rewind(stdin);
                for (i=0; i<pos;i++){
                    fgets(s[i],10,stdin);
                    l=strlen(s[i])-1;
                    s[i][l]=' '; // remplace le '\n' final par un espace
                }
                break;

            case 2 : // générer un message en morse
                nbmot=1+rand()%5;
                pos=0;
                while(nbmot--){
                    nbcode=1+rand()%7;
                    while(nbcode--){
                        l=rand()%26+10;
                        strcpy(s[pos++],code[l]);
                    }
                    strcpy(s[pos++],"????? ");
                }
                printf("pseudo msg en morse : ");
                for (i=0; i<pos; i++)
                    printf("%s",s[i]);
                putchar('\n');
                break;
            default : fin =1;

        }
        printf("traduction : ");
        for (i=0; i<pos; i++){
            for (j=0; j<26+10; j++){
                if (strcmp(s[i],code[j])==0)
                    if(j<26)
                        printf("%c",'a'+j);
                    else
                        printf("%c",'0'+j-26);
            }
            if(strcmp(s[i],"????? ")==0)
                putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}


/**
Solution 2 avec une seule chaine de caractères pour le message
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int menu()
{
int choix;
    printf("1 : entrer un message en morse\n"
           "2 : generer un pseudo message en morse\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}

int main()
{
char code[][10]={
".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ",  // a-j
"-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ",// k-t
"..- ","...- ",".-- ","-..- ","-.-- ","--.. ",   // u-z
"----- ",".---- ","..--- ","...-- ","....- ","..... ","-.... ","--... ","---.. ","----. "// 0-9
//".-.-.- " // le point
};
char s[1000]={0};
char buff[80]={0};
int fin=0,i,j,k,nbmot,nbcode,l;

    while (!fin){
        memset(s,0,1000); // mise à 0 chaine traduite
        switch(menu()){
            case 1 :
                printf("entrer les codes, taper enter entre chaque\n");
                while(strcmp(buff,"fin")!=0){
                    memset(buff,0,80); // mise à 0 buffer
                    scanf("%s",buff); // recup code
                    if(strcmp(buff,"fin")!=0){
                        buff[strlen(buff)]=' '; // si code ajout espace à la fin
                        strcat(s,buff);
                    }
                }
                printf("msg : %s\n",s);
                break;

            case 2 :
                nbmot=1+rand()%5;
                while(nbmot--){
                    nbcode=1+rand()%7;
                    while(nbcode--){
                        l=rand()%26+10;
                        strcat(s,code[l]);
                    }
                    strcat(s,"????? ");// espace entre chaque mot
                }
                printf("msg : %s\n",s);
                break;

            default : fin = 1;

        }
        // traduction
        memset(buff,0,80);
        for (i=0,j=0; s[i]!='\0'; i++){
            buff[j]=s[i];
            if(buff[j]!=' ')
                j++;
            else{ // un code retrouvé dans la chaine
                if(strcmp(buff,"????? ")==0)
                    putchar(' ');
                else{
                    for(k=0; k<26+10; k++){ // traduction
                        if(strcmp(buff,code[k])==0){
                            if(k<26)
                                putchar('a'+k);
                            else
                                putchar('0'+k-26);
                        }
                    }
                }
                memset(buff,0,80); // réinitialisation pour le suivant
                j=0;
            }
        }
        putchar('\n');
    }
    return 0;
}
/*********************************
Exercice 8
Réaliser un programme établissant une facture pour une commande de plusieurs articles.
Pour chaque article de la commande, l'utilisateur fournit la quantité et un numéro de
code à partir duquel le programme retrouve à la fois le libellé et le prix unitaire.
Le programme refuse les codes inexistants. A la fin il affiche un récapitulatif tenant
lieu de facture.
Les informations relatives aux différents articles sont définies en globale dans le
source du programme. Utilisez un catalogue de supermarché pour faire la liste et
inventez les codes.

1) Le programme propose un menu avec :
nouvelle commande
afficher la liste des articles disponibles

Prévoir une fonction de recherche des informations relatives à un article à partir de
son numéro de code et une fonction d'affichage de la facture récapitulative.
Exemple d'exécution :


ARTICLE			    NBRE		P-UNIT		MONTANT

centrifugeuse		33		    47.29		1560.57
Grille-pain		    12		    35.84		430.08
Four Raclette 6p	6		    51.33		307.98

TOTAL 							            2298.63

 2) Au moment de la commande il y a vérification que le nombre d'articles demandés est
 disponible sinon l'utilisateur est invité à modifier sa commande. Le stock disponible
 est mis à jour après chaque commande.


 ERRATUM :
 Pour avoir une fonction d'affichage de la facture qui est un tableau de structures
 nous avons besoin de la partie suivante "G.tableaux et fonctions" avec soit un tableau
 en global soit un tableau en paramètre de fonction. Comme le programme est petit et que
 l'affichage n'est demandé qu'une fois, une solution sans fonction d'affichage est acceptable.
 Sinon faire l'exercice avec la partie suivante.

*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBMAX   5

typedef struct{
    int code;     // le code de l'article est également donné par l'indice de l'articles dans le tableau stock
    char nom[100];
    int quantite;
    float prix;
}t_article;

t_article STOCK[NBMAX]={

    { 0,"lave-linge ouverture dessus",5,299.00},
    { 1,"lave-linge hublot",4,199.00},
    { 2,"Banquette-lit clic clac" ,2,149.25},
    { 3,"Lit mezzanine 90 cm",1,482.22},
    { 4,"Meuble a chaussures miroir",2,104.30}
    //(...)
};

int menu(void);
int saisie_code(void);
int saisie_quantite(int max);

int main()
{
int fin=0;
t_article commande[NBMAX];
int dispo[NBMAX];
int dernier=0,i,code,nb;
float total;
char autre,valider;

    while(!fin){

        switch(menu()){
            case 1 : // nouvelle commande

                for (i=0; i<NBMAX; i++)  // la disponibilité
                    dispo[i]=STOCK[i].quantite;
                memset(commande,0,sizeof(t_article)*NBMAX); // commande vierge (à 0)
                dernier=0;

                printf("Nouvelle commande : \n");
                do{
                    code=saisie_code();
                    printf( "Il reste %d %s.\n",dispo[code],STOCK[code].nom);
                    if(dispo[code]>0){

                        commande[dernier]=STOCK[code]; // copie
                        commande[dernier].code=code;  // save code
                        printf("Combien en voulez-vous ?");
                        nb=saisie_quantite(dispo[code]);
                        commande[dernier].quantite=nb;
                        dispo[code]-=nb;

                        // vérifier s'il y a plusieurs fois un même article dans la liste et regrouper
                        for(i=0;i<dernier;i++)
                            if(commande[i].code==commande[dernier].code)
                                break;
                        if(i<dernier)
                            commande[i].quantite+=commande[dernier].quantite;
                        else
                            dernier++;
                    }

                    printf("Autre article ? (o/n)");
                    scanf("%c",&autre);
                    rewind(stdin);
                }while(autre=='o');

                // afficher la commande
                printf("%35s%11s%11s%8s\n","ARTICLE","QUANTITE","PRIX UNIT.","TOTAL");
                for (i=0,total=0.0; i<dernier; i++){
                    printf("%35s%11d",commande[i].nom,commande[i].quantite);
                    printf("%10.2f%10.2f\n",commande[i].prix,commande[i].prix*commande[i].quantite);
                    total+=commande[i].prix*commande[i].quantite;
                }
                printf("%56s%10.2f\n","TOTAL",total);

                // validation et mise à jour stock
                printf("valider la commande ? (o/n)");
                scanf("%c",&valider);
                rewind(stdin);
                if(valider=='o')
                    for(i=0; i<dernier; i++)
                        STOCK[commande[i].code].quantite-=commande[i].quantite;
                break;

            case 2 : // affichage des articles disponibles
                printf("-------------------------------------------------\n");
                printf("%35s%11s%11s\n","CODE/NOM","QUANTITE","PRIX UNIT.");
                for (i=0; i<NBMAX; i++)
                    // ou possibilité utiliser tabulations
                    printf("%5d%30s%11d%10.2f\n",STOCK[i].code,STOCK[i].nom,STOCK[i].quantite,STOCK[i].prix);
                break;

            default : fin=1;
        }
    }
    return 0;
}
//
int menu()
{
int choix;
    printf("1 : commander\n"
           "2 : liste articles disponibles\n");
    scanf("%d",&choix);
    return choix;
}
//
int saisie_code()
{
int code=-1;
    // le contrôle est simple puisque les codes correspondent aux
    // indices du tableau. Il est inutile de le rechercher
    while(code < 0 || code >= NBMAX){
        printf("entrer code article : ");
        scanf("%d",&code);
        rewind(stdin);

        if(code<0 || code>=NBMAX)
            printf("code errone\n");
    }

    return code;
}
//
int saisie_quantite(int max)
{
int nb=0;
    scanf("%d",&nb);
    rewind(stdin);
    nb=(nb>max)? max : nb;   // donne ce qui est possible
    return nb;
}
/*********************************
*/
