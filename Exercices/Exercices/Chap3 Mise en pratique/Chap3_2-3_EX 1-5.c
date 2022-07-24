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
*   Chapitre 3 : Les structures								            *
*   2.   Structures et fonctions                                        *
*   2.3 Mise en pratique                                                *
*************************************************************************

/*********************************
Exercice 1
Une menuiserie industrielle gère un stock de panneaux de bois. Chaque
panneau possède une largeur, une longueur, une épaisseur en millimètres,
un volume et un type de bois. Il y a trois types de bois : pin (code 0),
chêne (code 1), hêtre (code 2).
Définir une structure panneau contenant toutes les informations relatives
à un panneau de bois.
Écrire les fonctions de saisie d'un panneau de bois.
Écrire une fonction d'affichage d'un panneau de bois
Écrire une fonction qui calcule le volume en mètre cube d'un panneau.
Écrire une fonction qui affiche le volume d'un panneau de bois
*
#include <stdio.h>
#include <stdlib.h>

struct pan{
    int lg,larg,ep,vol;
    int type; //pin (code 0),chêne (code 1), hêtre (code 2).
};

struct pan saisie(void);
void affiche(struct pan p);
int volume(struct pan p);
void affiche_vol(struct pan p);

int main()
{
struct pan p;
    p=saisie();
    affiche(p);
    p.vol=volume(p);
    affiche_vol(p);
    return 0;
}
struct pan saisie()
{
struct pan p;
    printf("entrer longueur, largeur, epaisseur, type (0-2) : ");
    scanf("%d%d%d%d",&p.lg,&p.larg,&p.ep,&p.type);
    p.vol=volume(p);
    rewind(stdin);
    return p;
}
void affiche(struct pan p)
{
    printf("longueur  :%d\n",p.lg);
    printf("largeur   :%d\n",p.larg);
    printf("epaisseur :%d\n",p.ep);
    printf("volume    :%d\n",p.vol);
    printf("type      :%s\n",(p.type==0)?"pin":((p.type==1)?"chene":"hetre"));
    printf("---------------\n");
}
int volume(struct pan p)
{
    return p.ep*p.larg*p.lg;
}
void affiche_vol(struct pan p)
{
    printf("volume    :%d\n",p.vol);
}
/*********************************
Exercice 2
Un grossiste de composants électroniques vend quatre types de produits :
des cartes mères (code 1)
des processeurs (code 2)
des barrettes mémoire (code 3)
des cartes graphiques (code 4)

Chaque produit possède une référence, qui est un nombre entier, un prix
en euros et une quantité disponible.
Définir une structure "produit" qui code un produit
Écrire une fonction de saisie des données d'un produit
Écrire une fonction d'affichage des données d'un produit
Écrire une fonction qui permet à un utilisateur de saisir la commande
d'un produit.L'utilisateur identifie le produit et saisit la quantité demandée.
L'ordinateur affiche toutes les données de la commande y compris le prix.
*
#include <stdio.h>
#include <stdlib.h>

struct produit{
    int type; // cartes mères 1, processeurs 2, barrettes mémoire 3, cartes graphiques 4
    int ref;
    float prix;
    int nb;
};

struct produit saisie()
{
struct produit p;
    printf("entrer type, reference, prix, quantite :");
    scanf("%d%d%f%d",&p.type,&p.ref,&p.prix,&p.nb);
    rewind(stdin);
    return p;
}
void affiche(struct produit p)
{
    printf("- type : ");
    switch(p.type){ //cartes mères 1, processeurs 2, barrettes mémoire 3, cartes graphiques 4
        case 1 : printf("carte mere\n");        break;
        case 2 : printf("processeur\n");        break;
        case 3 : printf("barrette memoire\n");  break;
        case 4 : printf("cartes graphiques\n"); break;
    }
    printf("- reference :%d\n",p.ref);
    printf("- prix : %.2f\n",p.prix);
    printf("- quantite : %d\n",p.nb);
}
struct produit commande()
{
struct produit c;
    c=saisie();
    printf("commande : \n");
    affiche(c);
    return c;
}

int main()
{
struct produit c;

    c = commande();

    // remarque : dans cet exercice il n'est pas demandé de gérer
    // un stock des différents produits avec la quantité disponible
    // ou pas de chacun. Juste remplir une commande de nb produits
    // Pour autant la commande est ici sauvegardée (inutilement)à la fin.
    // pour quatre types de produits un stock est envisageable.
    // Il faut quatre struct produit, une par type donnant le nombre de
    // produits disponibles par type.

    return 0;
}
/*********************************
Exercice 3
Soit les deux  types de structure "date" et "personne"  :

struct date{
		int jour, mois, annee;
};
struct personne{
		int identifiant;
		struct date date_embauche;
		struct date date_poste;
};

Ecrire une fonction pour initialiser une structure de type "personne".
Ecrire une fonction d'affichage de façon à obtenir soit l'un soit
l'autre des deux affichages ci-dessous :
Identifiant : 1224
date embauche (jj mm aa) : 16 01 08
date poste = date embauche ? (O/N)  : O

Identifiant : 1224
date embauche (jj mm aa) : 16 01 08
date poste = date embauche ? (O/N)  : N
date poste (jj mm aa) :  01 09 08
*
#include <stdio.h>
#include <stdlib.h>

struct date{
		int j, m, a;
};
struct personne{
		int identifiant;
		struct date de;
		struct date dp;
};

struct personne init()
{
struct personne p;
    printf("identifiant ? ");
    scanf("%d",&p.identifiant);
    rewind(stdin);
    printf("date embauche (jj mm aa) : ");
    scanf("%d%d%d",&p.de.j,&p.de.m,&p.de.a );
    rewind(stdin);
    printf("date poste (jj mm aa) : ");
    scanf("%d%d%d",&p.dp.j,&p.dp.m,&p.dp.a );
    rewind(stdin);
    return p;
}
void affiche(struct personne p)
{
    printf("Identifiant : %d\n",p.identifiant);
    printf("date embauche (jj mm aa) : %3d%3d%3d\n",p.de.j,p.de.m,p.de.a);
    if (p.de.j==p.dp.j && p.de.m==p.dp.m &&p.de.a==p.dp.a )
        printf("date poste = date embauche ? (O/N)  : 0\n");
    else{
        printf("date poste = date embauche ? (O/N)  : N\n");
        printf("date poste (jj mm aa) :  %3d%3d%3d\n",p.dp.j,p.dp.m,p.dp.a);
    }
}

int main()
{
struct personne p;
    p=init();
    affiche(p);
    return 0;
}
/*********************************
Exercice 4
Soit une entité dans un jeu vidéo en mode console. Elle est définie par
une position, un déplacement, un type (rampant, grouillant, serpentant,
plombant, assommant), une couleur. L'entité a également un nom (une lettre)
qui sert pour son apparence et une série de taux : taux d'agressivité,
de colère, de convoitise,  de faim, de peur.
Définir la structure de données pour coder une entité.
Faire une fonction d'initialisation, une fonction de mise à 0 (reset)
et une fonction d'affichage.
Tester dans un programme avec un menu : quitter, afficher, initialiser, reset.
*
#include <stdio.h>
#include <stdlib.h>

struct entite{
    float x,y; // position
    float dx, dy ; // déplacement
    int type; // rampant 0, grouillant 1, serpentant 2,plombant 3, assommant 4
    char l; // nom (lettre)
    int agress; // les taux
    int colere;
    int convoit;
    int faim;
    int peur;
};

// toutes les valeurs peuvent être spécifiées en paramètre :
struct entite init( float x,float y,float dx,float dy,int type,char l,
                    int agress,int colere,int convoit,int faim,int peur)
{
 struct entite e;
    e.x=x;
    e.y=y;
    e.dx=dx;
    e.dy=dy ;
    e.type=type;
    e.l=l;
    e.agress=agress;
    e.colere=colere;
    e.convoit=convoit;
    e.faim=faim;
    e.peur=peur;
    return e;
}

struct entite reset()
{
struct entite e={0};// tous les autres champs sont initialisés avec des 0
    return e;
}

void affiche (struct entite e)
{
    printf("-----ENTITE : -----\n");
    printf("position      : (%.2f,%.2f)\n",e.x,e.y);
    printf("deplacement   : (%.2f,%.2f)\n",e.dx, e.dy) ;
    printf("type          : %d\n",e.type);
    printf("nom           : %c\n",e.l);
    printf("taux :\n");
    printf(" -agressivite : %d\n",e.agress);
    printf(" -colere      : %d\n",e.colere);
    printf(" -convoitise  : %d\n",e.convoit);
    printf(" -faim        : %d\n",e.faim);
    printf(" -peur        : %d\n",e.peur);
}

int menu()
{
int choix;
    printf("-----MENU  : -----\n");
    printf( "0 quitter\n"
            "1 afficher\n"
            "2 initialiser\n"
            "3 reset\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}

int main()
{
const int TX=80;
const TY=25;
int fin =0;
struct entite e={0};

    while(!fin){
        switch(menu()){
            case 1 :
                affiche(e);
                break;
            case 2 :
                e=init( rand()%TX, // position
                        rand()%TY, //
                        ((float)rand()/RAND_MAX)*4-2, // deplacement
                        ((float)rand()/RAND_MAX)*4-2,
                        rand()%5,  // type
                        'A'+rand()%26, // nom
                        rand()%100, // les taux
                        rand()%100,
                        rand()%100,
                        rand()%100,
                        rand()%100);
                break;
            case 3 :
                e=reset();
                break;
            default : fin =1;
        }
    }
    return 0;
}
/*********************************
*/
