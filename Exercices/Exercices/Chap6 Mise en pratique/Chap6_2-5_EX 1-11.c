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
*   Chapitre 6 :Les pointeurs											*
*   2.   Allocation dynamique de tableaux                               *
*   2.5 Mise en pratique : allocation dynamique                         *
*************************************************************************

/****************************************
Allouer dynamiquement des tableaux      *
*****************************************
Exercice 1
Dans un programme :
l'utilisateur entre une taille de tableau d'entiers
une fonction alloue le tableau
une fonction initialise le tableau avec des nombres aléatoires croissants
une fonction affiche le tableau
quitter ou recommencer (si recommencer libérer la mémoire)
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allouer(int nb)
{
    return malloc(sizeof(int)*nb);
}
void init(int t[],int nb)
{
int i;
    t[0]=rand()%10;
    for (i=1; i<nb; i++)
        t[i]=t[i-1]+rand()%10;
}
void affiche(int t[],int nb)
{
int i;
    for (i=0; i<nb; i++)
        printf("%d-",t[i]);
    putchar('\n');
}

int main()
{
char continuer='o';
int*tab,nb;
    srand(time(NULL));

    while(continuer=='o'){
        printf("entrer taille du tableau :");
        scanf("%d",&nb);
        rewind(stdin);

        tab=allouer(nb);
        init(tab,nb);
        affiche(tab,nb);
        free(tab);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*************************************
Exercice 2
Considérons la structure t_tableau suivante qui contient l'adresse d'un tableau et
le nombre d'éléments du tableau :
typedef struct{
	int nb_elem;			// nombre d'éléments
	int*tab;			// tableau potentiel
}t_tableau;

1) Écrire la fonction   :
t_tableau alloue_tableau (int n);
qui crée un tableau de n éléments.

2) Écrire la fonction   :
void destruct_tableau (t_tableau tab);
qui libère la mémoire occupée par un tableau

3) Écrire la fonction   :
void init_tableau (t_tableau tab);
qui initialise un tableau avec des valeurs.

4) Écrire la fonction   :
void affiche_tableau (t_tableau tab);
qui affiche le contenu d'un tableau.

5) Écrire la fonction   :
t_tableau double_tableau (t_tableau tab);
qui crée un nouveau tableau de même taille que tab mais initialisé avec le double
des valeurs de tab. Faire un programme avec un menu qui permet ces différentes opérations.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
	int nb_elem;			// nombre d'éléments
	int*tab;			// tableau potentiel
}t_tableau;


t_tableau alloue_tableau (int n)
{
t_tableau t;
    t.nb_elem=n;
    t.tab=(int*)malloc(sizeof(int)*n);
    memset(t.tab,0,sizeof(int)*n); // mise à 0
    return t;
}

t_tableau destruct_tableau (t_tableau tab)
{
    free(tab.tab);
    tab.tab=NULL;
    tab.nb_elem=0;
    return tab;             // un retour est important pour avoir tab.tab à null
}

void init_tableau (t_tableau tab)
{
int i;
    for (i=0; i<tab.nb_elem; i++)
        tab.tab[i]=rand()%100;
}

void affiche_tableau (t_tableau tab)
{
int i;
    for (i=0; i<tab.nb_elem; i++)
        printf("%4d",tab.tab[i]);
    putchar('\n');
}

t_tableau double_tableau (t_tableau tab)
{
t_tableau d;
int i;
    d=alloue_tableau(tab.nb_elem);
    for(i=0; i<d.nb_elem; i++)
        d.tab[i]=tab.tab[i]*2;
    return d;
}

int menu()
{
int choix;
    printf("1 : allouer un tableau\n"
           "2 : initialiser le tableau\n"
           "3 : afficher le tableau\n"
           "4 : double tableau\n"
           "5 : detruire tableau\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}


int main()
{
char continuer='o';
int nb;
t_tableau t={0,NULL},tt=t;

    srand(time(NULL));

    while(continuer=='o'){

        switch(menu()){
            case 1 : // allouer
                if(t.tab!=NULL) // si déjà allouer libérer
                    destruct_tableau(t);

                printf("entrer la taille du tableau :");
                scanf("%d",&nb);
                rewind(stdin);
                t=alloue_tableau(nb);
                break;

            case 2 : // initialiser
                if(t.tab!=NULL)
                    init_tableau(t);
                else
                    printf("tableau non alloue\n");
                break;

            case 3 : // afficher
                if(t.tab!=NULL)
                    affiche_tableau(t);
                else
                    printf("tableau non alloue\n");
                break;

            case 4 : //double de double
                if(t.tab!=NULL){
                    if(tt.tab!=NULL)
                        tt=destruct_tableau(tt);
                    tt=double_tableau(t);
                    affiche_tableau(tt);
                }
                else
                    printf("tableau non alloue\n");
                break;

            case 5 : // detruire le tableau
                if(t.tab!=NULL)
                    t=destruct_tableau(t);
                else
                    printf("tableau non alloue\n");
                break;

            default : continuer ='n';
        }
    }
    return 0;
}

/*************************************
Exercice 3
Dans un programme,
écrire une fonction de saisie d'une chaine de caractères ; la fonction n'a pas de paramètre
écrire une fonction de concaténation de deux chaines de caractères ; la fonction a deux
paramètres qui sont les chaines à concaténer et renvoie une troisième chaine qui est la concaténation.
saisir deux chaines et afficher la concaténation
quitter ou recommencer (attention à la mémoire).
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char* saisie(void);
char* concat(const char*s1, const char*s2);

int main()
{
char continuer='o';
char*s,*s1,*s2;
    srand(time(NULL));

    while(continuer=='o'){

        s1=saisie();
        s2=saisie();
        s=concat(s1,s2);
        printf("%s\n",s);

        free(s1);
        free(s2);
        free(s);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
char* saisie(void)
{
char*s;
char buff[1000];
    printf("entrer une chaine :");
    fgets(buff,1000,stdin);
    buff[strlen(buff)-1]='\0';
    s=malloc(strlen(buff)+1);
    strcpy(s,buff);
    return s;
}
char* concat(const char*s1, const char*s2)
{
char*s;
    s=malloc(strlen(s1)+strlen(s2)+1);
    strcpy(s,s1);
    strcat(s,s2);
    return s;
}


/*************************************
Exercice 4 (suppose connaissance fichier)
On se propose de réaliser une fonction de chargement d'un fichier texte en mémoire centrale.
Le formalisme du fichier est le suivant :
- la première ligne donne le nombre d'éléments dans le fichier
- les lignes suivantes contiennent chacune un nombre réel.
Par exemple :
	3
	4.98
	123.76
	45.99

Écrire la fonction de chargement qui prend en paramètre un tableau de la taille exacte
Écrire une fonction d'affichage du tableau
Tester dans un programme. Lancer plusieurs fois le programme en modifiant à chaque fois
le contenu du fichier texte.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PATH    "test.txt"

void creer_fichier(void);
void charge_val(int nb, float*tab, FILE*f);
void affiche(float*tab, int nb);

//
int main()
{
char continuer='o';
FILE*f;
int nb;
float*tab;

    srand(time(NULL));
    while(continuer=='o'){

        // creer un fichier texte avec des valeurs
        // (evite d'avoir à fermer relancer le programme)
        creer_fichier();

        // chargement
        if((f=fopen(PATH,"r"))!=NULL){
            fscanf(f,"%d",&nb);
            tab=(float*)malloc(sizeof(float)*nb);
            charge_val(nb, tab, f);
        }
        else
            printf("erreur ouverture du fichier\n");

        affiche(tab,nb);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
//
void creer_fichier()
{
FILE*f=NULL;
float val;
int i,nb; // nombre d'éléments
    if((f=fopen(PATH,"w"))!=NULL){
        nb=1+rand()%20;
        fprintf(f,"%d\n",nb);
        for (i=0; i<nb; i++){
            val=(rand()%1000)/100.0;
            fprintf(f,"%.2f\n", val);
        }
        fclose(f);
    }
    else
        printf("erreur creation fichier\n");

}
//
void charge_val(int nb, float*tab, FILE*f)
{
int i;
    for (i=0; i<nb; i++)
        fscanf(f,"%f",tab+i);
}
//
void affiche(float*tab, int nb)
{
int i;
    for (i=0; i<nb; i++)
        printf("%.2f\n",tab[i]);
    putchar('\n');
}

/*************************************
Exercice 5
Dans un programme,
saisir une phrase
passer cette phrase à une fonction qui retourne un des mots au hasard de la phrase
afficher la phrase et le mot sélectionné
quitter ou recommencer
*
// char* strtok(char*, char*);   dans <string.h>
// cette fonction recherche les mots de la chaine p1 en prenant comme
// ensemble de séparateurs les caractères de la chaine p2. LOrs du
// premier appel, la fonction strtok modifie la chaine p1 en déplacant
// le caractère '\0 à la fin du premier mot, et retourne l'adresse de ce mot.
// les appels suivants doivent être effectués avec NULL comme premier paramètre,
// la fonction conservant la position courante dans la chaine entre deux appels.
// Elle retourne NULL lorsqu'il n'y a plus de mot.

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

char* mot(char*s)
{
char*suiv,*res;
    res=suiv=strtok(s," "); // au départ res pointe sur le premier mot
    while ((suiv=strtok(NULL," "))!=NULL)
        if(rand()%2)
            res=suiv;
    return res;
}

int main()
{
char continuer='o';
char phrase[100];

    srand(time(NULL));
    while(continuer=='o'){

        printf("entrer une phrase :");
        fgets(phrase,100,stdin);
        printf("phrase : %s",phrase);
        printf("mot    : %s\n",mot(phrase));

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}

/*************************************
Allouer dynamiquement des matrices
**************************************
Exercice 6
Dans un programme :
l'utilisateur entre les deux dimensions d'une matrice d'entiers
une fonction alloue la matrice
une fonction initialise la matrice avec des nombres aléatoires croissants
une fonction affiche la matrice
quitter ou recommencer (si recommencer libérer la mémoire)
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int**allouer(int ty, int tx);
void liberer(int**m, int ty);
void init(int**m,int ty, int tx);
void affiche(int**m,int ty, int tx);

int main()
{
char continuer='o';
int**mat,ty,tx;

    srand(time(NULL));

    while(continuer=='o'){

        ty=1+rand()%20;
        tx=1+rand()%30;
        mat=allouer(ty,tx);
        init(mat, ty, tx);
        affiche(mat,ty,tx);
        liberer(mat,ty);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
int**allouer(int ty, int tx)
{
int**m,i;
    m=(int**)malloc(sizeof(int*)*ty);
    for(i=0; i<ty; i++)
        m[i]=(int*)malloc(sizeof(int)*tx);
    return m;
}
void liberer(int**m, int ty)
{
int i;
    for(i=0; i<ty; i++)
        free(m[i]);
    free(m);
}
void init(int**m,int ty, int tx)
{
int y,x;
    for (y=0; y<ty; y++)
        for (x=0; x<tx; x++)
            m[y][x]=rand()%100;
}
void affiche(int**m,int ty, int tx)
{
int y,x;
    for (y=0; y<ty; y++){
        for (x=0; x<tx; x++)
            printf("%3d",m[y][x]);
        putchar('\n');
    }
}
/*************************************
Exercice 7
Considérons la structure t_matrice suivante qui contient l'adresse d'une matrice,
le nombre de lignes et le nombre de colonnes :
typedef struct{
	int ty, tx;			// lignes, colonnes
	int**tab;			// matrice
}t_matrice;

1) Écrire la fonction   :
t_matrice allouer_matrice (int tx, int ty);
qui crée une matrice de ty*tx éléments.

2) Écrire la fonction   :
void destruct_matrice (t_matrice mat);
qui libère la mémoire occupée par une matrice

3) Écrire la fonction   :
void init_matrice (t_matrice mat);
qui initialise une matrice avec des valeurs.

4) Écrire la fonction   :
void affiche_matrice (t_matrice mat);
qui affiche le contenu d'une matrice.

5) Écrire la fonction   :
t_matrice double_matrice (t_matrice mat);
qui crée une nouvelle matrice d'une taille double que mat et initialisée dans la partie
double avec le double des valeurs de mat, simplement recopiée sinon.
Faire un programme avec un menu qui permet ces différentes opérations.

*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct{
	int ty, tx;			// lignes, colonnes
	int**tab;			// matrice
}t_matrice;


t_matrice allouer_matrice (int ty, int tx)
{
t_matrice m;
int y;
    m.ty=ty;
    m.tx=tx;
    m.tab=(int**)malloc(sizeof(int*)*ty);
    for (y=0; y<ty; y++){
        m.tab[y]=(int*)malloc(sizeof(int)*tx);
        memset(m.tab[y],0,sizeof(int)*tx); // mise à 0
    }

    return m;
}

t_matrice destruct_matrice (t_matrice mat) // retourne le resultat
{
int y;
    for (y=0; y<mat.ty; y++)
        free(mat.tab[y]);
    free(mat.tab);
    mat.tab=NULL;
    return mat;
}

void init_matrice (t_matrice mat)
{
int y,x;
    for(y=0; y<mat.ty; y++)
        for(x=0; x<mat.tx; x++)
            mat.tab[y][x]=rand()%100;
}

void affiche_matrice (t_matrice mat)
{
int y,x;
    for(y=0; y<mat.ty; y++){
        for(x=0; x<mat.tx; x++)
            printf("%4d",mat.tab[y][x]);
        putchar('\n');
    }
}

t_matrice double_matrice (t_matrice mat)
{
t_matrice m;
int y,x;
    m=allouer_matrice(mat.ty*2,mat.tx);  // la partie double en dessous
    for (y=0; y<mat.ty; y++)
        for (x=0;x<mat.tx; x++)
            m.tab[y][x]=mat.tab[y][x];  // recopie

    for (y=0 ; y<mat.ty; y++)  // partie en plus
        for (x=0;x<mat.tx; x++)
            m.tab[y+mat.ty][x]=mat.tab[y][x]*2;  // valeurs doublées
    return m;
}

t_matrice libere_matrice(t_matrice m)
{
int y;
    for (y=0; y<m.ty; y++)
        free(m.tab[y]);
    free(m.tab);
    m.tab=NULL;
    return m;
}

int menu()
{
int choix;
    printf("1 : allouer\n"
           "2 : initialiser\n"
           "3 : afficher\n"
           "4 : doublage\n"
           "5 : detruire\n");
    scanf("%d",&choix);
    return choix;
}
//
int main()
{
char continuer='o';
t_matrice m={0,0,NULL},mm=m;
int tx,ty;

    srand(time(NULL));
    while(continuer=='o'){
        switch(menu()){
            case 1 : // allouer
                if(m.tab!=NULL)
                    m=libere_matrice(m);

                printf("entrer taille ty et tx :");
                scanf("%d%d",&m.ty, &m.tx);
                rewind(stdin);
                m=allouer_matrice(m.ty,m.tx);
                break;

            case 2 : // initialiser
                if(m.tab!=NULL)
                    init_matrice(m);
                else
                    printf("matrice non allouee\n");
                break;

            case 3 : //afficher
                if(m.tab!=NULL)
                    affiche_matrice(m);
                else
                    printf("matrice non allouee\n");
                break;

            case 4 : // doublage
                if(m.tab!=NULL){
                    if(mm.tab!=NULL)
                        mm=libere_matrice(mm);
                    mm=double_matrice(m);
                    affiche_matrice(mm);
                }
                else
                    printf("matrice non allouee\n");
                break;

            case 5 : // liberer
                if(m.tab!=NULL)
                    m=libere_matrice(m);
                else
                    printf("matrice non allouee\n");
                break;

            default : // sortie
                continuer='n';
                if(m.tab!=NULL)
                    libere_matrice(m);
                if(mm.tab!=NULL)
                    libere_matrice(mm);
        }
    }
    return 0;
}

/*************************************
Exercice 8 (suppose connaissance fichier)
On se propose de réaliser une fonction de chargement d'un fichier texte en mémoire centrale.
Le formalisme du fichier est le suivant :
- la première ligne donne le nombre de lignes et de colonnes d'une matrice de char
- ensuite chaque ligne a nb colonne éléments
Par exemple :
	3  4
	abcd
	efgh
	ijkl

Écrire la fonction de chargement qui prend en paramètre une matrice de la bonne taille
Écrire une fonction d'affichage de la matrice
Tester dans un programme. Lancer plusieurs fois le programme en modifiant à chaque fois le
contenu du fichier texte.

*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define PATH    "test.txt"

typedef struct{
    int tx,ty;
    char**mat;
}t_mat;

void creer_fichier(void);
t_mat load_mat(void);
void affiche(t_mat m);
void libere(t_mat m);

//
int main()
{
char continuer='o';
t_mat m={0};

    srand(time(NULL));
    while(continuer=='o'){

        // creer un fichier texte avec des valeurs
        // (evite d'avoir à fermer relancer le programme)
        creer_fichier();

        // chargement et affichage
        m=load_mat();
        affiche(m);
        libere(m);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
//
void creer_fichier()
{
FILE*f=NULL;
int y,x,ty,tx; // nombre d'éléments
    if((f=fopen(PATH,"w"))!=NULL){
        ty=1+rand()%20;
        tx=1+rand()%70;
        fprintf(f,"%d %d",ty,tx);
        fputc('\n',f);
        for (y=0; y<ty; y++){
            for (x=0; x<tx; x++)
                fputc('a'+rand()%26,f);
            fputc('\n',f);
        }
        fclose(f);
    }
    else
        printf("erreur creation fichier\n");

}
//
t_mat load_mat()
{
FILE*f;
t_mat m;
int y,x;
char c;
    if((f=fopen(PATH,"r"))!=NULL){
        // allocation
        fscanf(f,"%d%d%c",&m.ty,&m.tx,&c); // c cause '\n', attention
        m.mat=(char**)malloc(sizeof(char*)*m.ty);
        for (y=0; y<m.ty; y++)
            m.mat[y]=(char*)malloc(sizeof(char)*m.tx);

        // recupération données
        x=y=0;
        while((c=fgetc(f))!=EOF){

            if(c=='\n'){
                y++;
                x=0;
            }
            else
                m.mat[y][x++]=c;
        }
    }
    else
        printf("probleme ouverture du fichier\n");

    return m;
}
//
void affiche(t_mat m)
{
int y,x;
    for (y=0; y<m.ty; y++){
        for (x=0; x<m.tx; x++)
            printf("%c",m.mat[y][x]);
        putchar('\n');
    }
}
//
void libere(t_mat m)
{
int y;
    for(y=0; y<m.ty; y++)
        free(m.mat[y]);
    free(m.mat);
}


/********************************************
Allocation dynamique calloc() et realloc()
*********************************************
Exercice 9
Dans un programme, un agenda est constitué de cellules comprenant nom, prénom, téléphone, adresse.
Première partie :
définir un type pour stocker une cellule
l'utilisateur entre le nombre de cellules qu'il veut intégrer
allouer dynamiquement un tableau pour stocker les cellules. A l'issue toutes les cellules sont à 0.
écrire une fonction d'initialisation d'une cellule et remplir le tableau
afficher le tableau rempli
sauver en binaire, le tableau et sa taille (si connaissance fichiers)
*
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nom[80];
    char prenom[80];
    char tel[80];
    char adresse[256];

}t_cell;
//
t_cell saisie_cell()
{
t_cell c;
    printf("Nom : ");
    fgets(c.nom,80,stdin);
    printf("prenom : ");
    fgets(c.prenom,80,stdin);
    printf("telephone : ");
    fgets(c.tel,80,stdin);
    printf("adresse : ");
    fgets(c.adresse,256,stdin);
    return c;
}
//
void afficher(t_cell t[], int nb)
{
int i;
    if(nb==0 || t==NULL)
        printf("agenda vide\n");
    else{
        printf("AGENDA COMPLET :\n");
        for(i=0; i<nb; i++){
            printf("nom       : %s", t[i].nom);
            printf("prenom    : %s", t[i].prenom);
            printf("telephone : %s", t[i].tel);
            printf("adresse   : %s", t[i].adresse);
            printf("---------------------------\n");
        }
    }
}
//
void save(t_cell t[], int nb)
{
FILE*f;

    if((f=fopen("agenda.bin","wb"))!=NULL ){
        fwrite(&nb,sizeof(int),1,f);
        fwrite(t,sizeof(t_cell),nb,f);
        fclose(f);
    }
    else
        printf("erreur creation fichier\n");

}
//
int menu()
{
int choix;
    printf ("1 : ajouter un contact\n"
            "2 : afficher tous les contacts\n"
            "3 : sauver les contacts\n"
            "4 : charger les contacts\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}
//
int main()
{
char continuer='o';
t_cell*agenda=NULL;
int nb=0;
FILE*f;

    while(continuer=='o'){
        switch(menu()){
            case 1 : // ajouter un contact
                agenda=(t_cell*)realloc(agenda,sizeof(t_cell)*(nb+1));
                agenda[nb++]=saisie_cell();
                printf("nb : %d\n",nb);
                break;

            case 2 :// afficher tous les contacts
                afficher(agenda,nb);
                break;

            case 3 : // sauver tous les contacts
                save(agenda,nb);
                break;

            case 4 : // charger tous les contacts
            // le chargement necessite de récuperer 2 valeurs nb et agenda
            // or une fonction ne peut retrouner qu'une valeur avec return
            // solution ? soit créer une structure agenda qui contient le tableau
            // et le nombre de contacts, soit faire deux fonction une pour le nombre
            // et une pour le tableau (bricolage à éviter), soit utiliser un passage
            // par référence, c'est l'idéal ici mais c'est expliqué dans la partie qui
            // suit. Pour le moment nous allons tout faire directement dans le switch :

                if((f=fopen("agenda.bin","rb"))!=NULL){
                    fread(&nb,sizeof(int),1,f); // recup du nombre de contacts sauvés
                    agenda=(t_cell*)realloc(agenda, sizeof(t_cell)*nb);// allocation
                    fread(agenda,sizeof(t_cell),nb,f);// recopie
                    fclose(f);
                }
                else
                    printf("erreur creation fichier\n");
                break;

            default :
                continuer ='n';
                if(agenda!=NULL)
                    free(agenda);
        }
    }
    return 0;
}

/*************************************
Exercice 10 (suppose connaissance fichier)
Dans un programme, reprendre le type défini dans l'exercice 9. L'objectif cette fois est de
pouvoir modifier la base de cellules enregistrées sur fichier binaire, soit en ajouter soit
en supprimer. Le programme propose maintenant un menu avec quatre possibilités :
loader : récupérer toute la base dans un tableau de la bonne taille
ajouter : augmenter la taille du tableau et ajouter une cellule
supprimer : choisir la cellule à supprimer, la mettre à la fin et diminuer la taille du tableau
sauvegarder : fichier binaire, tableau et taille.
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom[80];
    char prenom[80];
    char tel[80];
    char adresse[256];
}t_cell;

typedef struct{     // amélioration de la stucture de donnée
    int nb;
    t_cell*all;
}t_agenda;

t_agenda    ajouter         (t_agenda a);
t_cell      saisie_cell     (void);
t_agenda    supprimer_cell  (t_agenda);
void        afficher        (t_agenda);
void        save            (t_agenda);
t_agenda    charge          (void);
int         menu            (void);

int main()
{
char continuer='o';
t_agenda agenda={0,NULL};

    while(continuer=='o'){
        switch(menu()){
            case 1 : agenda=ajouter(agenda);        break;
            case 2 : agenda=supprimer_cell(agenda); break;
            case 3 : afficher(agenda);              break;
            case 4 : save(agenda);                  break;
            case 5 : agenda=charge();               break;
            default :
                continuer ='n';
                if(agenda.all!=NULL)
                    free(agenda.all);
        }
    }
    return 0;
}
//
t_cell saisie_cell()
{
t_cell c;
    printf("Nom : ");
    fgets(c.nom,80,stdin);
    printf("prenom : ");
    fgets(c.prenom,80,stdin);
    printf("telephone : ");
    fgets(c.tel,80,stdin);
    printf("adresse : ");
    fgets(c.adresse,256,stdin);
    return c;
}
//
t_agenda  ajouter  (t_agenda a)
{
    a.all=(t_cell*)realloc(a.all,sizeof(t_cell)*(a.nb+1));
    a.all[a.nb++]=saisie_cell();
    return a;
}
//
t_agenda supprimer_cell(t_agenda a)
{
char nom[80];
char prenom[80];
int i;
    if(a.nb>0){
        printf("entrer nom et prenom du contact a supprimer :\n");
        printf("nom : ");
        fgets(nom,80,stdin);
        printf("prenom : ");
        fgets(prenom,80,stdin);

        for (i=0; i<a.nb;i++)
            if(strcmp(nom,a.all[i].nom)==0 && strcmp(prenom,a.all[i].prenom)==0){
                a.all[i]=a.all[a.nb-1];
                a.nb--;
                a.all=(t_cell*)realloc(a.all,sizeof(t_cell)*a.nb);
            }
    }
    else
        printf("agenda vide\n");
    return a;
}
//
void afficher(t_agenda a)
{
int i;
    if(a.nb==0 || a.all==NULL)
        printf("agenda vide\n");
    else{
        printf("AGENDA COMPLET :\n");
        for(i=0; i<a.nb; i++){
            printf("nom       : %s", a.all[i].nom);
            printf("prenom    : %s", a.all[i].prenom);
            printf("telephone : %s", a.all[i].tel);
            printf("adresse   : %s", a.all[i].adresse);
            printf("---------------------------\n");
        }
    }
}
//
void save(t_agenda a)
{
FILE*f;

    if((f=fopen("agenda.bin","wb"))!=NULL ){
        // attention sizeof(a) vaut 8 octets un int et un pointeur
        // ce qui veut dire qu'il faut décomposer la sauvegarde :
        fwrite(&a.nb,sizeof(int),1,f);
        fwrite(a.all,sizeof(t_cell),a.nb,f);
        fclose(f);
    }
    else
        printf("erreur creation fichier\n");

}
//
t_agenda charge()
{
FILE*f;
t_agenda a={0,NULL};

    if((f=fopen("agenda.bin","rb"))!=NULL){
        fread(&a.nb,sizeof(int),1,f);
        a.all=(t_cell*)malloc(sizeof(t_cell)*a.nb);
        fread(a.all,sizeof(t_cell),a.nb,f);
        fclose(f);
    }
    else
        printf("erreur creation fichier\n");
    return a;
}
//
int menu()
{
int choix;
    printf ("1 : ajouter un contact\n"
            "2 : supprimer un contact\n"
            "3 : afficher tous les contacts\n"
            "4 : sauver les contacts\n"
            "5 : charger les contacts\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}
//

/*************************************
Exercice 11
Dans un programme, dans la boucle principale, la taille t d'un tableau est donnée au hasard :
une fonction alloue  dynamiquement un tableau de t pointeurs d'entiers. La première fois tous
les pointeurs sont à NULL c'est à dire en fait ((int*)0) .
une fonction initialise avec des valeurs et une fonction les affiche
le programme quitte ou recommence selon le souhait de l'utilisateur
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void init(int*t[],int nb);
void affiche(int*t[],int nb);
void libere(int*t[],int nb);

int main()
{
char continuer='o';
int**tab=NULL,nb;
    srand(time(NULL));

    while(continuer=='o'){

        nb=1+rand()%30;
        tab=(int**)malloc(sizeof(int*)*nb);
        memset(tab,0,sizeof(int*)*nb);  // mise à 0

        init(tab,nb);
        affiche(tab,nb);
        libere(tab,nb);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
void init(int*t[],int nb)
{
int i;
    for (i=0; i<nb; i++){
        t[i]=(int*)malloc(sizeof(int));
        *t[i]=rand()%100;
    }
}

void affiche(int*t[],int nb)
{
int i;
    for (i=0; i<nb; i++)
        printf("%3d",*t[i]);
    putchar('\n');
}

void libere(int*t[],int nb)
{
int i;
    if(t!=NULL){
        for (i=0; i<nb; i++){
            if(t[i]!=NULL)
                free(t[i]);
        }
        free(t);
    }
}
/*********************************
*/

