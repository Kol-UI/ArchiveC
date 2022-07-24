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
*   Chapitre 4 : Les tableaux 									        *
*   4. Tableaux et fonctions                                            *
*   4.5 Mise en pratique : tableaux et fonctions                        *
*************************************************************************


/********************************************
Appels de fonctions, tableaux en paramètre  *
/********************************************
Exercice 1
Ecrire une fonction qui affiche une lettre sur deux d'une chaine de caractères
donnée en paramètre. Tester la fonction dans un programme
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche(char s[]);

int main()
{
char s[256];
    printf("entrer une phrase :\n");
    fgets(s,256,stdin);
    affiche(s);
    return 0;
}

void affiche(char s[])
{
int i,l;
    l=strlen(s);
    for(i=0; i<l;i+=2)
        putchar(s[i]);
}

/*********************************
Exercice 2
Faire une fonction qui reconnaît et affiche des lettres communes à deux mots ou
phrases saisies au clavier. La saisie est elle même une fonction. Tester dans un
programme qui s'arrête à la demande de l'utilisateur.
*

// les lettres communes à deux phrases ou deux mots peut s'interpréter de deux façons :
// - pour chaque phrase-mot les lettres identiques et à la même place
//   par exemple bonsoir et bonjour donne : bon_o_r
// - pour les deux phrases-mots le sous ensemble de lettre commun
//   par exemple bonsoir et bonjour donne : bonr


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256
void saisie(char i[],char s[]);
void commun1 (char s1[],char s2[],char rep[]);
void commun2 (char s1[],char s2[],char rep[]);

int main()
{
char continuer='o';
char s1[MAX];
char s2[MAX];
char res[MAX];

    while (continuer=='o'){

        saisie("entrer phrase-mot 1 : ", s1);
        saisie("entrer phrase-mot 2 : ", s2);

        commun1(s1,s2,res);
        printf("rep 1 : %s\n",res);

        commun2(s1,s2,res);
        printf("rep 2 : %s\n",res);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
//
void saisie(char i[],char s[])
{
    printf("%s",i);
    fgets(s,MAX,stdin);
    s[strlen(s)-1]='\0';// suppression \n final
}
//
void commun1 (char s1[],char s2[],char rep[])
{
int i;
    memset(rep,0,MAX); // mise à 0 de rep
    for(i=0; s1[i]!='\0' && s2[i]!='\0'; i++)
        if(s1[i]==s2[i])
            rep[i]=s1[i];
        else
            rep[i]='-';
}
//
void commun2 (char s1[],char s2[],char rep[])
{
char c[MAX]={0};
int i,j,k;

    // supprimer les lettres en doublons de la première phrase-mot
    for (i=0; s1[i]!='\0'; i++){
        for (k=0; c[k]!='\0'; k++)
            if(s1[i]==c[k])
                break;
        if(c[k]=='\0')
            c[k]=s1[i];
    }
    // initialisation rep à 0
    memset(rep,0,MAX);
    // trouver les lettres communes avec la phrase 2
    for(i=0,j=0; c[i]!='\0'; i++)
        for(k=0; s2[k]!='\0'; k++)
            if(c[i]==s2[k]){
                rep[j++]=c[i];
                break;
            }
}

/*********************************
Exercice 3
Faire une fonction qui compte le nombre de répétition des lettres dans un mot ou
une phrase entré par l'utilisateur. Le résultat est affiché avec une fonction
différente. Tester dans un programme qui s'arrête à la demande de l'utilisateur.
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saisie(char i[],char s[]);
void repeat(char s[256], int l[26]);
void result(int l[26]);

int main()
{
char continuer='o';
char s[256];
int l[26];

    while(continuer=='o'){

        saisie("entrer une phrase : ",s);
        repeat(s,l);
        result(l);

        printf("continuer ?(o/n)");
        scanf("%c",&continuer);
        rewind(stdin);

    }
    return 0;
}
//
void saisie(char i[],char s[256])
{
    printf("%s",i);
    fgets(s,256,stdin);
    s[strlen(s)-1]='\0';// suppression \n final
}
//
void repeat(char s[256], int l[26])
{
int i,c;
    memset(l,0,sizeof(int)*26);
    for(i=0; s[i]!='\0'; i++){
        // ne prend que les lettres (min et maj)
        if(s[i]>='a' && s[i]<='z')
            c=s[i]-'a';
        else if(s[i]>='A' && s[i]<='Z')
            c=s[i]-'A';
        else
            continue;

        l[c]++;
    }
}
//
void result(int l[26])
{
int i;
    printf("comptage lettres : \n");
    for (i=0; i<26; i++){
        if(l[i]!=0)
            printf("%c : %d\n",i+'a',l[i]);
    }

}
/*********************************
Exercice 4
Faire une fonction qui permet d'examiner la distribution des valeurs aléatoires
obtenues avec la fonction rand() pour un nombre n de tirages entrés par l'utilisateur
et sur 10 plages (des résultats de 0 à 9). Tester dans un programme qui s'arrête à la
demande de l'utilisateur.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void distrib(int res[10]);
void result(int res[10]);

int main()
{
char continuer ='o';
int res[10];

    srand(time(NULL);
    while(continuer=='o'){

        distrib(res);
        result(res);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
void distrib(int res[10])
{
int i,n;
    printf("entrer le nombre de repetitions : ");
    scanf("%d",&n);
    rewind(stdin);

    memset(res,0,sizeof(int)*10);
    for (i=0; i<n; i++)
        res[rand()%10]++;
}
//
void result(int res[10])
{
int i;
    for(i=0; i<10; i++)
        printf("%d : %d\n",i,res[i]);
}
/*********************************
Exercice 5
Il existe une méthode de détermination de nombres premiers connue sous le nom de
"crible d'Erastothène". Elle permet d'obtenir tous les nombres premiers inférieurs
à une valeur n donnée. La méthode consiste à faire la liste de tous les nombres de
1 à n et à rayer successivement tous les multiples des entiers.
La méthode est :
1) rayer 1 qui n'est pas un nombre premier
2) passer au suivant non rayé (au départ 2) et rayer tous ces multiples (et uniquement
ses multiples)
3) recommencer,  chercher le suivant non rayé et rayer tous ses multiples, jusqu'à
atteindre la fin de la liste
4) afficher la liste des nombres premiers.
Faire trois fonctions, une dans laquelle l'utilisateur spécifie le nombre n d'entiers
dans la liste, une pour déterminer les nombres entiers dans la liste, une pour l'affichage
de la liste. Le programme quitte si l'utilisateur le commande.
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000000

int saisie(void);
void erasto(char all[],int n);
void affiche (char all[], int n);

int main()
{
char continuer ='o';
char all[MAX];
int n;

    while(continuer=='o'){

        n=saisie();
        erasto(all,n);
        affiche(all,n);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}

int saisie()
{
int n;
    printf("entrer nombre : ");
    scanf("%d",&n);
    rewind(stdin);
    if(n>MAX)
        n=MAX;
    return n;
}
void erasto(char all[],int n)
{
int i,m;
    memset(all,0,MAX);
    all[0]=all[1]=1; // ne sont pas premiers
    for (i=2; i<n; i++ )
        if(all[i]==0)
            for (m=2; i*m<n; m++)
                all[i*m]=1;
}
//
void affiche (char all[], int n)
{
int i;
    printf("nombres premiers avant %d :\n",n);
    for (i=0; i<n; i++)
        if(all[i]==0)
            printf("%d\n",i);
}
/*********************************
Exercice 6
Master mind. Faire un programme qui choisit au hasard une combinaison à cinq chiffres
compris entre 1 et 8 et qui demande à l'utilisateur de la deviner. A chaque proposition
de l'utilisateur le programme précise :
le nombre de chiffres exactes ET à la bonne place
le nombre de chiffres exactes  PAS à la bonne place
Les propositions de l'utilisateur sont fournies sous la forme de cinq chiffres (pas de
séparateur ). L'entrée utilisateur doit être "blindée" c'est à dire traite les erreurs :
entrée de lettres, réponse trop courte ou trop longue, chiffres incorrectes (non compris
entre 1 et 8)
Un nombre maximum de coups est prévu pour chaque partie. Il est affiché et décroit à
chaque à chaque proposition. Si tous les coups possibles sont passés l'utilisateur à
perdu et le programme donne la réponse. Ensuite il propose une nouvelle partie.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 5
void    combinaison     (int comb[MAX]);
void    voir_combinaison(int c[MAX]);
void    saisie          (char*msg, int r[MAX]);
int     exact           (int c[MAX], int r[MAX]);
int     bonne_place     (int c[MAX], int r[MAX]);

int main()
{
int c[MAX],res[MAX];
char rejouer='o';
int nbcoup=0,bp=0;

    srand(time(NULL));
    while(rejouer=='o'){
        combinaison(c);
        while(nbcoup++<10 && bp<5 ){
            saisie("entrer 5 nombres entre 1 et 8 : ", res);
            printf("nb exactes                : %d\n", exact(c,res));
            bp=bonne_place(c,res);
            printf("nb exactes et bonne place : %d\n", bp);
        }

        printf("solution : ");
        voir_combinaison(c);

        if(bp<5)
           printf("PERDU! ");
        else
           printf("GAGNER! en %d coups, ",nbcoup-1);

        printf("rejouer ? (o/n)");
        scanf("%c",&rejouer);
        rewind(stdin);
    }

    return 0;
}
//
void combinaison(int comb[MAX])
{
int i;
    for (i=0; i<MAX; i++)
        comb[i]=1+rand()%8;
}
//
void voir_combinaison(int c[MAX])
{
    int i;
    for (i=0; i<MAX; i++)
        printf("%d",c[i]);
    putchar('\n');
}
//
void saisie(char*msg, int r[MAX])
{
char c;
int i,err;

    printf("%s",msg);
    memset(r,0,sizeof(int)*MAX);
    do{
        i=0;
        while((c=getchar())!='\n' && i <MAX)
            r[i++]=c-'0';
        rewind(stdin);
        voir_combinaison(r);
        for(i=0,err=0;i<MAX &&!err; i++)
            if(r[i]<1 ||r[i]>8){
                err=1;
                printf("nombre entre 1 et 8 uniquement\n");
            }
    }while(err);
}
//
int exact(int c[MAX], int r[MAX])
{
int i,j,cmp=0;
int res[MAX]={0};
    // attention : les nombres répétés dans la combinaison
    // sont comptés plusieurs fois pour une fois le nombre
    // entré par le joueur. Par exemple :
    // combi 12333, entrée 34555, exacte : 3
    for(i=0;i<MAX; i++)
        for(j=0; j<MAX; j++)
            if(c[i]==r[j]){
                cmp++;
                break;
            }
    return cmp;
}
//
int bonne_place(int c[MAX], int r[MAX])
{

int i,cmp=0;
    for(i=0; i<MAX; i++)
        if(c[i]==r[i])
            cmp++;
    return cmp;
}
/*********************************
Exercice 7
Afficher au hasard un certain nombre d'étoiles (*) dans un rectangle. Le nombre
d'étoile et la taille du rectangle sont entrées par l'utilisateur sachant que
la taille maximum est 25 par 80.
Attention, il ne peut pas y avoir d'étoiles superposées.
*
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define TX  80
#define TY  25

void pos_etoile(int nbe, char r[][TX],int tx, int ty);
void affiche_rect(char r[][TX], int tx, int ty);
void gotoxy(int x, int y);

int main()
{
char rect[TY][TX];
int tx,ty,nbe;

    printf("entrer hauteur et largeur du rectangle : ");
    scanf("%d%d",&ty,&tx);
    rewind(stdin);
    printf("entrer le nombre d'etoiles (max %d) :",tx*ty);
    scanf("%d",&nbe);
    rewind(stdin);

    tx=(tx>TX)?TX:tx;
    ty=(ty>TY)?TY:ty;
    nbe=(nbe>ty*tx)? ty*tx:nbe;

    pos_etoile(nbe,rect,tx,ty);
    affiche_rect(rect,tx,ty);
    return 0;
}
void pos_etoile(int nbe, char r[][TX],int tx, int ty)
{
int x,y;
    memset(r,0,TX*TY);
    while(nbe--){
        y=rand()%ty;
        x=rand()%tx;
        while(r[y][x]==1){
            if(rand()%2)
                x=(x+1)%tx;
            else
                y=(y+1)%ty;
        }
        r[y][x]=1;
    }
}
//
void affiche_rect(char r[][TX], int tx, int ty)
{
int x,y;
    for (y=0; y<ty; y++){
        for(x=0; x<tx; x++)
            putchar( (r[y][x]==0)? '-':'*' );
        putchar('\n');
    }
}

/*********************************
Exercice 8
Soit l'extrait de code suivant :
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.c>

#define TX    30  // taille zone de jeu en x
#define TY    20  //          "         en y
#define DECX  5   // décalage par rapport au bord gauche
#define DECY  5   // décalage par rapport au bord haut

// la  contrée des terres du milieu
#define BORD   1   // dans la matrice signifie 1 bord
#define MUR    2   // dans la matrice signifie 1 mur

int player[2];   // les coordonnées du player 0 pourx et 1 pour y
int level[TY][TX]={
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,2,2,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,2,2,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,2,2,0,2,2,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};
L'objectif est d'avoir un player qui se déplace au clavier dans le monde
représenté par la matrice level. Pour ce faire écrire quatre fonctions :
une fonction qui permet d'afficher à une position donnée, un caractère
donné d'une  couleur donnée
une fonction d'initialisation du terrain à partir de la matrice level
une fonction d'initialisation du player : il prend position dans son monde
en respectant le terrain et ces murs
une fonction qui gère les entrées clavier à savoir le déplacement du player
et la fin du programme.
*

// il y a deux solutions :
// - soit la matrice level est considérée en globale et les fonctions
// peuvent y accéder sans passer par un paramètre
// - soit les fonctions utilisent un paramètre pour passer la matrice.
// Comment choisir ?
// - si il n'y a qu'un monde et qu'il ny a aucun changement de level à prévoir
// la première solution est bonne
// - si vous envisagez d'avoir plusieurs levels (plusieurs matrices) alors il
// il faut prendre la seconde (à moins d'écrire une fonction qui permet de générer
// à la volée un nouveau monde)
//
// l'énoncé envisage une seule matrice et aucun changement de level. Nous allons la
// considérer comme globale.
// par ailleurs nous allons utiliser une structure également en globale pour le player.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define TX    30  // taille zone de jeu en x
#define TY    20  //          "         en y
#define DECX  5   // décalage par rapport au bord gauche
#define DECY  2   // décalage par rapport au bord haut

// la  contrée des terres du milieu
#define BORD   1   // dans la matrice signifie 1 bord
#define MUR    2   // dans la matrice signifie 1 mur

int LEVEL[TY][TX]={
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,2,2,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,2,2,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,2,2,0,2,2,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

struct{                 // le joueur
    int x,y,l,color;
}J;

void        affiche_terrain (void);
void        init_joueur     (void);
int         run             (void);
void        affiche_lettre  (int x, int y, int l, int color);
void        gotoxy          (int x, int y);
void        textcolor       (int color);

int main()
{
int fin=0;

    srand(time(NULL));
    affiche_terrain();
    init_joueur();
    affiche_lettre(J.x,J.y,J.l,J.color);

    while(!fin)
        fin=run();

    gotoxy(0,DECY+TY+1);
    return 0;
}
//
void affiche_terrain()
{
 int x,y,color;
    for (y=0; y<TY; y++)
        for(x=0; x<TX; x++){
            switch(LEVEL[y][x]){
                case 0 : color=0;   break;
                case 1 : color=12;  break;
                case 2 : color=10;  break;
            }
            textcolor(color);
            affiche_lettre(x, y,' ',color<<4);
        }
}
//
void init_joueur()
{
    J.x=rand()%TX;
    J.y=rand()%TY;
    while(LEVEL[J.y][J.x]!=0){
        if(rand()%2)
            J.x=(J.x+1)%TX;
        else
            J.y=(J.y+1)%TY;
    }
    J.l='J';
    J.color=1+rand()%15;
}
//
int run()
{
int res=0,x,y;
    if(kbhit()){
        x=J.x;
        y=J.y;
        switch(getch()){
            case 72 :   y--;    break;  // haut
            case 77 :	x++;	break;	// droite
            case 80 :	y++;	break;	// bas
            case 75 :	x--;	break;	// gauche
            case 224:           break;  // (à évacuer)
            default : res=1;
        }
        if(x>=0 && x<TX && y>=0 && y<TY){ // si dans zone de jeu
            if(LEVEL[y][x]==0){// et si on est sur du gazon

                affiche_lettre(J.x,J.y,J.l,0); // effacer
                J.x=x;
                J.y=y;
                affiche_lettre(J.x,J.y,J.l,J.color);
            }
        }
    }
    return res;
}
//
void affiche_lettre(int x, int y, int l, int color)
{
    gotoxy(DECX+x, DECY+y);
    textcolor(color);
    putchar(l);
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
Exercice 9
Dans un jeu de démineur le terrain est spécifié par une matrice de nombres.
Faire deux fonctions, une pour l'initialisation avec un nombre de mines
répandues aléatoirement dans le terrain et une autre pour indiquer combien
il y a de mines autour de chaque position dans la zone de jeu. Faire un
programme de test qui affiche les mines en rouge et pour chaque position
le nombre des mines à proximité s'il y en a (pas d'affichage sinon).
*
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// comme dans l'exercice prédédent la matrice terrain peut être en global
#define TY  24
#define TX  80
#define BOMBE   -1
int TERR[TY][TX];

void    init_terrain    (int densite);
int     compte_bombe    (int x, int y);
void    affiche_terrain (void);
void    gotoxy          (int x, int y);
void    textcolor       (int color);

int main()
{
    init_terrain(5);
    affiche_terrain();
    return 0;
}
//
void init_terrain(int densite)
{
int x,y;
    // mise en place des bombes
    memset(TERR,0,TX*TY*sizeof(int));
    for(y=0; y<TY;y++)
        for (x=0; x<TX; x++)
            if(rand()%100<densite)
                TERR[y][x]=BOMBE;
    // comptage des bombes
    for(y=0; y<TY;y++)
        for (x=0; x<TX; x++)
            if(TERR[y][x]==0)
                TERR[y][x]=compte_bombe(x,y);
}
//
int compte_bombe(int x, int y)
{
int nb=0,xo,yo;
    // regarder les huit positions voisines
    // si BOMBE incrementer nb de 1
    for(yo=y-1; yo<=y+1; yo++)
        for(xo=x-1; xo<=x+1;xo++)
            if( yo>=0 && yo<TY && xo>=0 && xo<TX){
                if(yo==y && xo==x )
                    continue;
                if( TERR[yo][xo]==BOMBE)
                    nb++;
            }
    return nb;
}
//
void affiche_terrain()
{
int y,x,l,color;
    for(y=0; y<TY;y++)
        for (x=0; x<TX; x++){

            if(TERR[y][x]==BOMBE){
                color=12<<4;
                l='B';
            }
            else if (TERR[y][x]>0){
                color=15;
                l=TERR[y][x]+'0';
            }
            else{
                color=15<<4;
                l=' ';
            }
            textcolor(color);
            putchar(l);
        }
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
Manipulations sur les chaines    *
/*********************************
Exercice 10
Ecrire vos propres versions des fonctions suivantes :
fgets() /saisir une chaine.
strlen() / compter la longueur de la chaine et retourner le résultat
strcpy() / copier une chaine dans une seconde
strcat() / concaténer deux chaines, la seconde à la suite de la première
strcmp() / comparer deux chaines et donner l'ordre lexicographique
Ensuite dans un programme, tester la différence de rapidité d'exécution
entre votre version et celle de la librairie standard (donner les deux vitesses).
Faites un menu qui permet de choisir la fonction à tester.
*
#include <stdio.h>
#include <stdlib.h>

int     menu        (void);
void    p_fgets     (char s[],int max);
int     p_strlen    (char s[]);
void    p_strcpy    (char s1[],char s2[]);
void    p_strcat    (char s1[], char s2[]);
int     p_strcmp    (char s1[], char s2[]);

int main()
{
char s[50]={"phrase par defaut"};
char s2[50*3];
int i,res,fin=0;
    while(!fin){
        switch(menu()){
            case 1 :
                printf("entrer une phrase : ");
                p_fgets(s,50);
                printf("%s\n",s);
                break;

            case 2 :
                printf("%s : %d caracteres\n",s,p_strlen(s));
                break;

            case 3 :
                p_strcpy(s2,s);
                printf("copie : %s\n",s2);
                break;

            case 4 :
                memset(s2,0,50*3);
                for (i=0; i<3; i++) // met à la suite s 3 fois
                    p_strcat(s2,s); // attention s2 doit être assez grande

                printf(" concatenation : %s\n",s2);
                break;

            case 5 :
                printf("entrer une deuxieme phrase : ");
                p_fgets(s2,50);
                res=p_strcmp(s,s2);
                printf("resultat : %s\n", (res==0)?"identiques":((res<0)?"s1 avant":"s1 apres") );
                break;
            default : fin =1;
        }
    }
    return 0;
}
//
int menu()
{
int choix;
    printf("Test versions perso de :\n"
           "1 : fgets\n"
           "2 : strlen\n"
           "3 : strcpy\n"
           "4 : strcat\n"
           "5 : strcmp\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}
void p_fgets(char s[],int max)
{
char c,i=0;
    memset(s,0,max);
    while((c=getchar())!='\n' && i <max-1)
        s[i++]=c;
    rewind(stdin);
}

int p_strlen(char s[])
{
int i;
    for(i=0; s[i]!='\0';i++)
        ;
    return i;
}

void p_strcpy(char s1[],char s2[])
{
int i;
    for (i=0; s2[i]!='\0'; i++)
        s1[i]=s2[i];
    s1[i]='\0';
}

void p_strcat(char s1[], char s2[])
{
int i,j;
    //trouver le dernier \0
    for (i=0; s1[i]!='\0';i++)
        ;
    // copier à la suite
    for( j=0 ; s2[j]!='\0'; j++,i++)
        s1[i]=s2[j];
    s1[i]='\0';
}

int p_strcmp(char s1[], char s2[])
{
int i,res=0;
char c1,c2;
    for (i=0; s1[i]!='\0' && s2[i]!='\0'; i++){
        // convertir en minuscule
        c1=s1[i];
        c2=s2[i];
        if(c1>='A' && c1<='Z')
            c1+='a'-'A';
        if(c2>='A' && c2<='Z')
            c2+='a'-'A';
        res=c1-c2;
        if(res!=0)
            break;
    }
    // pas de différence mais une chaine plus longue que l'autre
    if (res==0 && s1[i]!=s2[i]){
        if(s1[i]!='\0')
            res=1;
        else
            res=-1;
    }
    return res;


}

/*********************************
Exercice 11
La librairie standart <string.h> fournit d'autres fonctions pour le traitement
des chaines. Par exemple les trois fonctions : strncat(), strncmp(), strncpy().
Trouver comment utiliser ces fonctions et dans un programme, donner vous-même
un exemple de code  qui marche pour chacune des trois.
*

// char* strncat(char*, const char*, size_t)        in <string.h>
// Cette fonction concatène au plus p3 caractères de la chaines p2 à la suite
// de la chaine p1 et retourne p1. La zone mémoire pointée par p1 doit être
// suffisamment grande et accessible en écriture (la fonction recopie p3 + 1
// caractères)
//
// int strncmp(const char*, const char*, size_t)    in <string.h>
// Cette fonction compare les chaines de caractères p1 et p2 sur au plus p3
// caractères, et retourne une valeur négative, nulle, ou positive, selon
// que la première est inférieure, égale, ou supérieure à la seconde, pour
// l'ordre lexicographique
//
// char* strncpy(char*,const char*, size_t)         in <string.h>
// Cette fonction recopie au plus p3 caractères de la chaine de caractères
// p2 à l'adresse mémoire p1 et retourne p1, en complétant éventuellement avec
// des zéros si p2 est trop courte. La zone pointée par p1 doit être suffisamment
// grande et accessible en écriture


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

int main()
{
char s[MAX];
char s2[MAX]={0};
int i;

    printf("entrer une chaine :");
    fgets(s,MAX,stdin);
    s[strlen(s)-1]='\0';

    // char* strncat(char*, const char*, size_t)
    for(i=0; i<5;i++)
        strncat(s2, s, 10); // 5 fois les dix premiers caractères
    printf("strncat s2 : %s\n",s2);

    // int strncmp(const char*, const char*, size_t)
    strncmp(s,s2,10);
    printf("strncmp de s et s2 sur 10 : %d\n",strncmp(s,s2,10)); // en principe 0

    // char* strncpy(char*,const char*, size_t)
    strncpy(s,s2,25);
    printf("strncpy s  : %s\n",s);

    return 0;
}

/*********************************
Exercice 12
Faire une fonction qui compte le nombre de mots dans un texte (au choix, le
texte est fourni en dur dans le programme ou une phrase assez longue peut être
entrée par l'utilisateur). Tester dans un programme qui s'arrête à la demande
de l'utilisateur. Faire une deuxième fonction qui compte le nombre de segments
obtenus à partir de deux séparateurs quelconques entrés par l'utilisateur.
*
#include <stdio.h>
#include <stdlib.h>

char TXT[]={"L’informatique      se limitait, il y a encore quelques annees, "
"a un processeur ayant un unique coeur. Pour pallier au manque de performances "
"et de traitements, les constructeurs     inventerent les architectures multiprocesseur "
"dans une    même machine, les infrastructures de type cluster avec x machines, puis "
"le grid computing pour    une approche massivement distribuee. Pour des marches entreprises "
"et grand public, certains constructeurs ont voulu miser sur le biprocesseur et le 64-bit, "
"sans oublier la course a la frequence, le fameux Ghz. Finalement, les 3 approches ont "
"echoue aupres du grand public et de la majorite des entreprises et des developpeurs. "
"Pourquoi ?"};

int compte_mot(char t[]);
int compte_segment(char t[],char c1, char c2);

int main()
{
char s[256];
char continuer='o';
char c1,c2;
    //printf("dans le texte :\n%s\n",TXT);
    //printf("ily a %d mots\n",compte_mot(TXT));
    while(continuer=='o'){
        printf("entrer une phrase :");
        fgets(s,256,stdin);
        printf("il y a %d mots\n",compte_mot(s));

        printf("entrer deux separateurs : ");
        scanf("%c%c",&c1,&c2);
        rewind(stdin);

        printf("%d segments [%c,%c]\n",compte_segment(s,c1, c2),c1,c2);

        printf("continuer ? (o/n)?");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}

int compte_mot(char t[])
{
int i,cmp,n;
    // le nombre de mots est le nombre d'espace plus 1
    // avec un seul espace entre les mots (il faut passer les espaces supplémentaires
    for (i=0,cmp=0; t[i]!='\0'; i++){
        if(t[i]==' '){
            while (t[i++]==' '){}
            i--; // pour éviter de sauter la première lettre du mot suivant
            // ce n'est utile que si on veut par exemple afficher le mot
            // ne compte pour motque si le premier suivant est une lettre
            if(t[i]>='a' && t[i]<='z'||t[i]>='A' && t[i]<='Z')  // && prioritaire sur ||
                cmp++;
        }
    }
    return  cmp+1;
}
int compte_segment(char t[],char c1, char c2)
{
int i,k,cmp=0;
    // le problème est qu'il peut y avoir des segment imbriqués :
    // c1  c1  c2 c1 c2 c2  : 8 segments
    // à chaque fois que je tombe sur un c1 je compte les c2 suivants
    for(i=0; t[i]!='\0';i++){
        if(t[i]==c1){
            for (k=i+1; t[k]!='\0'; k++)
                if(t[k]==c2)
                    cmp++;

        }
    }
    return cmp;
}

/*********************************
Exercice 13
Faire un programme avec un menu utilisateur qui permet les opérations suivantes
tant que l'utilisateur le souhaite, chaque opération est une fonction :
saisir une chaine
compter le nombre de voyelles dans une chaine en paramètre et retourner le résultat.
compter le nombre de consonnes et retourner le résultat
supprimer toutes les consonnes d'une chaine et modifier la chaine en conséquence
supprimer toutes les voyelles d'une chaine sans modifier l'originale
inverser l'ordre des lettres de la chaine (bonjour -> ruojnob)
indiquer si une chaine est un palimdrôme (abccba, anna, azertytreza sont des palindromes)
crypter une chaine avec un décalage circulaire. La valeur de cryptage est entrée par
l'utilisateur.
décrypter la chaine si elle est cryptée.
*
#include <stdio.h>
#include <stdlib.h>

#define    MAX  256

int     menu            (void);
void    saisie          (char*msg, char s[],int max);
int     is_voyelle      (char c);
int     cmpt_voyelle    (char s[]);
void    supp_voyelle    (char s[]);
int     is_consonne     (char c);
int     cmpt_consonne   (char s[]);
void    supp_consonne   (char s[]);
void    inverse_lettres (char s[]);
int     palyndrome      (char s[]);
int     crypt           (char s[], int cle);
int     decrypt         (char s[], int cle);

int main()
{
int fin=0;
char s[MAX]={"chaine par defaut"};
int cle=0;

    while(!fin){
        switch(menu()){
            case 1 :
                saisie("enter une chaine : ",s,MAX);
                break;

            case 2 :
                printf("%s : %d voyelles\n ",s,cmpt_voyelle(s));
                break;

            case 3 :
                printf("%s : %d consonnes\n ",s,cmpt_consonne(s));
                break;

            case 4 :
                supp_voyelle(s);
                printf("%s : sans voyelle\n",s);
                break;

            case 5 :
                supp_consonne(s);
                printf("%s : sans consonne\n",s);
                break;

            case 6 :  // inverse
                inverse_lettres(s);
                printf("inverse : %s\n",s);
                break;

            case 7 : // palimdrome
                printf("%s un palimdrome\n",palyndrome(s)?"est":"n'est pas");
                break;

            case 8 :  // crypt
                cle=crypt(s,cle);
                puts(s);
                break;

            case 9 : // decrypt
                cle=decrypt(s,cle);
                puts(s);
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
    printf("1 : saisie\n"
           "2 : compte voyelle\n"
           "3 : compte les consonnes\n"
           "4 : supprime les voyelles\n"
           "5 : supprime les consonnes\n"
           "6 : inverse les lettres\n"
           "7 : palimdrome ?\n"
           "8 : cryptage\n"
           "9 : decryptage\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}
//
void saisie(char*msg, char*s,int max)
{
    printf("%s",msg);
    fgets(s,max,stdin);
    s[strlen(s)-1]='\0';
    rewind(stdin);
}
//
int is_voyelle(char c)
{
int res=0;
    if(c>='A'&& c<='Z')// si maj passe en min
        c+='a'-'A';
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
        res=1;
    return res;
}
//
int cmpt_voyelle(char*s)
{
int i,cmp=0;

    for(i=0; s[i]!='\0'; i++)
        cmp+=is_voyelle(s[i]);
    return cmp;
}
//
void supp_voyelle(char*s)
{
int i,k;
    for (i=0,k=0; s[k]!='\0'; k++)
        if(is_consonne(s[k]))
            s[i++]=s[k];
    s[i]='\0';
}
//
int is_consonne(char c)
{
int res=0;

    if( (c>='A'&& c<='Z') || (c>='a'&&c<='z') ){// si lettre
        if(c>='A'&&c<='Z')// si maj passe en min
            c+='a'-'A';
        res=!is_voyelle(c); // vaut 1 si pas voyelle
    }
    return res;
}
//
int cmpt_consonne(char*s)
{
int i,cmp=0;

    for(i=0; s[i]!='\0'; i++)
        cmp+=is_consonne(s[i]);

    return cmp;
}
//
void supp_consonne(char*s)
{
int i,k;
    for (i=0,k=0; s[k]!='\0'; k++)
        if(is_voyelle(s[k]))
            s[i++]=s[k];
    s[i]='\0';
}
//
void inverse_lettres(char*s)
{
int i,j;
char c;
    for (i=0, j=strlen(s)-1; i<j; i++,j--){
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
//
int palyndrome(char*s)
{
int i,j;
    for (i=0, j=strlen(s)-1; i<j; i++,j--){
        if(s[i]!=s[j])
            break;
    }
    return(i>=j); // palimdrome si vrai
}
//
int crypt(char*s, int cle)
{
int i,nb;

    printf("entrer une cle (entier) :");
    scanf("%d",&nb);
    rewind(stdin);
    for(i=0; s[i]!='\0'; i++)
       s[i]+=nb;

    cle+=nb;  // si plusieurs cryptages de suite
    return cle;
}
//
int decrypt(char*s, int cle)
{
int i;
    for(i=0; s[i]!='\0'; i++)
        s[i]-=cle;
    return 0;
}

/*********************************
Exercice 14
Dans un programme faire une fonction qui affiche la conjugaison au présent de l'indicatif
d'un verbe du premier groupe sous la forme :
je chante
tu chantes
il/elle chante
nous chantons
vous chantez
ils/elles chantent
Le verbe à conjuguer est entré par l'utilisateur et passé en argument à la fonction.
Au départ s'assurer que le verbe fourni se termine bien par "er". On suppose qu'il s'agit
d'un verbe régulier et que l'utilisateur ne fournit pas de verbe comme manger (cause nous
mongeons et non nous mangons).
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saisie(char*msg, char*s,int max);
void conjugue(char v[]);

int main()
{
char verbe[80];

    saisie("entrer infinitif verbe premier groupe :",verbe,80);
    conjugue(verbe);
    return 0;
}
void saisie(char*msg, char*s,int max)
{
    printf("%s",msg);
    fgets(s,max,stdin);
    s[strlen(s)-1]='\0';
    rewind(stdin);
}
//
void conjugue(char v[])
{
char conjug[6][80]={"je ","tu ","il/elle ","nous ","vous ","ils/elles "};
char termin[6][80]={"e","es","e","ons","ez","ent"};
char s[80]={0};
int i;
    strncpy(s,v,strlen(v)-2);
    for (i=0; i<6; i++)
        printf("%s%s%s\n",conjug[i],s,termin[i]); // juste afficher
}

/*********************************
Exercice 15
Écrire une fonction qui  compte le nombre de répétition des lettres utilisées dans un
petit texte. La saisie du texte n'est pas faite dans cette fonction. Le résultat est
affiché dans le contexte d'appel, après l'exécution de la fonction. Tester dans un programme.

ERRATUM :
identique exercice 3

*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void saisie(char i[],char s[]);
void repeat(char s[256], int l[26]);
void result(int l[26]);

int main()
{
char continuer='o';
char s[256];
int l[26];

    while(continuer=='o'){

        saisie("entrer une phrase : ",s);
        repeat(s,l);
        result(l);

        printf("continuer ?(o/n)");
        scanf("%c",&continuer);
        rewind(stdin);

    }
    return 0;
}
//
void saisie(char i[],char s[256])
{
    printf("%s",i);
    fgets(s,256,stdin);
    s[strlen(s)-1]='\0';// suppression \n final
}
//
void repeat(char s[256], int l[26])
{
int i,c;
    memset(l,0,sizeof(int)*26);
    for(i=0; s[i]!='\0'; i++){
        // ne prend que les lettres (min et maj)
        if(s[i]>='a' && s[i]<='z')
            c=s[i]-'a';
        else if(s[i]>='A' && s[i]<='Z')
            c=s[i]-'A';
        else
            continue;

        l[c]++;
    }
}
//
void result(int l[26])
{
int i;
    printf("comptage lettres : \n");
    for (i=0; i<26; i++){
        if(l[i]!=0)
            printf("%c : %d\n",i+'a',l[i]);
    }

}

/*********************************
Exercice 16
Problème mon clavier est cassé. A chaque fois que je tape sur s, j ou g ça écrit ch.
Dans un programme tester une fonction qui remplace toutes les lettres s, j et g d'un
petit texte passé en argument en ch : "suppose" devient "chuppoche", "je" devient "che",
"fromage" devient "fromache" etc.
Ensuite intégrer dans le programme le fait que l'utilisateur puisse choisir lui-même
la transformation à opérer. Faire une deuxième fonction qui prend en plus en argument
la lettre à transformer et en quelle autre lettre ou ensemble de lettres elle est
transformée.
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

void txt_saisie(char i[],char s[MAX]);
void modif1(char txt[], char res[]);
void transf_saisie(char t[26][10]);
void modif2(char txt[], char res[],char t[26][10]);

int main()
{
char continuer='o';
char txt[MAX];
char res[MAX*2];

char trans[26][10]; // stocke les transformations

    while(continuer=='o'){

        txt_saisie("entrer une phrase : ",txt);
        modif1(txt,res);
        printf("%s\n",res);

        transf_saisie(trans);
        modif2(txt,res,trans);
        printf("%s\n",res);

        printf("continuer ?(o/n)");
        scanf("%c",&continuer);
        rewind(stdin);

    }
    return 0;
}
//
void txt_saisie(char i[],char s[MAX])
{
    printf("%s",i);
    fgets(s,MAX,stdin);
    s[strlen(s)-1]='\0';// suppression \n final
}
//
void modif1(char txt[], char res[])
{
int i,j;
    memset(res,0,MAX*2);
    for (i=0,j=0; txt[i]!='\0'; i++)
        if(txt[i]=='s' || txt[i]=='j' || txt[i]=='g'){
            res[j++]='c';
            res[j++]='h';
        }
        else
            res[j++]=txt[i];
}
//
void transf_saisie(char t[26][10])
{
char c=0;
int pos;

    memset(t,0,26*10);
    while (1){
        printf("lettre (minuscule) a changer, entree pour stop : ");
        scanf("%c",&c);
        rewind(stdin);
        if(c=='\n')
            break;
        else if(c<'a' || c>'z')
            printf("erreur entree\n");
        else{
            pos=c-'a';
            printf("entrer sequence de transformation : ");
            fgets(t[pos],10,stdin);
            t[pos][strlen(t[pos])-1]='\0';
            rewind(stdin);
        }
    }
}
//
void modif2(char txt[], char res[],char t[26][10])
{
int i,j,k,c;
    memset(res,0,MAX*2);
    for (i=0,j=0; txt[i]!='\0'; i++){
        c=txt[i]-'a';
        if(c>=0 && c<26 && t[c][0]!=0) // transformation
            for(k=0; t[c][k]!='\0'; k++)
                res[j++]=t[c][k];
        else //pas de transformation
            res[j++]=txt[i];
    }
}
/*********************************
*/
