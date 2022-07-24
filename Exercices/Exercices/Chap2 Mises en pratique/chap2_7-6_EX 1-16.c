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
/********************************************************************
*   Chapitre 2 : Contrôles des blocs d'instruction                  *
*   7. Fonctions                                                    *
*  7.6 : Mise en pratique  : Fonctions            *
*********************************************************************

/*********************************
Exercice 1
Soit la fonction suivante :
void wait(int tmps)
{
int start=clock();
   while (clock()<start+tmps){}
}
Donnez le nombre et le type des paramètres, le nom de la fonction,
le type de la valeur de retour, les variables utilisées. Que fait la fonction ?

- nombre et type des paramètres : 1 paramètre de type int
- nom de la fonction : wait
- type de la valeur de retour : void
- variables utilisées : start et le paramètre tmps
- la fonction bloque les opétations pendant un temps spécifié par le paramètre tmps


/*********************************
Exercice 2
- Donner l'entête d'une fonction destinée à calculer la distance entre deux points
(la distance serait calculée avec le théorème de pythagore).
- Donner l'ensemble des ressources nécessaires pour écrire la fonction.

entête : int dist(int x1,int y1,int x2, int y2)
la fonction prend en paramètre les deux points et retourne la distance qui les sépare

Ressources : voici la fonction
#include <math.h> // abs et sqrt

int dist(int x1,int y1,int x2, int y2)
{
int dx,dy;

    dx=abs(x1-x2);
    dy=abs(y1-y2);
    return (int)sqrt(dx*dx+dy*dy);
}
/*********************************
Exercice 3
Quels sont les messages d'erreur produits par le programme suivant ?
*
#include <stdio.h>
#include <stdlib.h>

int main()
{
   affiche_bonjour(5);
   return 0;
}

void  affiche_bonjour ( int nb)
{
int i;

   for (i=0; i<nb; i++)
	   puts("bonjour");
}

message d'erreur :
warming-error
previous implicit declaration of 'affiche_bonjour' was here


Modifier ce programme pour qu'il fonctionne. Donnez deux solutions.
Procédures sans paramètre
*

// 1 déclarer la fonction
#include <stdio.h>
#include <stdlib.h>

void  affiche_bonjour ( int nb);

int main()
{
   affiche_bonjour(5);
   return 0;
}

void  affiche_bonjour ( int nb)
{
int i;

   for (i=0; i<nb; i++)
	   puts("bonjour");
}
// 2 placer la définition de la fonction avant le main
// (contraction de la définition et de la déclaration)

#include <stdio.h>
#include <stdlib.h>

void  affiche_bonjour ( int nb)
{
int i;

   for (i=0; i<nb; i++)
	   puts("bonjour");
}

int main()
{
   affiche_bonjour(5);
   return 0;
}

/*********************************
Exercice 4
Afin de tester la fonction rand() du point de vue statistique, faire une
fonction qui tire 100000 fois une valeur comprise entre 0 et 5, compte les
occurrences de chaque résultat et affiche le pourcentage de chaque résultat.
Appeler la fonction dans un programme.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void stat_rand()
{
int c0,c1,c2,c3,c4,c5,i;

    srand(time(NULL));
    c0=c1=c2=c3=c4=c5=0;
    for(i=0; i<100000; i++){
        switch(rand()%6){
            case 0 : c0++; break;
            case 1 : c1++; break;
            case 2 : c2++; break;
            case 3 : c3++; break;
            case 4 : c4++; break;
            case 5 : c5++; break;
        }
    }
    printf("0 : %d - %.2f pour cent\n",c0,(c0/100000.0)*100);
    printf("1 : %d - %.2f pour cent\n",c1,(c1/100000.0)*100);
    printf("2 : %d - %.2f pour cent\n",c2,(c2/100000.0)*100);
    printf("3 : %d - %.2f pour cent\n",c3,(c3/100000.0)*100);
    printf("4 : %d - %.2f pour cent\n",c4,(c4/100000.0)*100);
    printf("5 : %d - %.2f pour cent\n",c5,(c5/100000.0)*100);

}
int main()
{
    stat_rand();
	return 0;
}
/*********************************
Exercice 5
Faire une fonction damier qui affiche un damier de 20 sur 15 à l'écran.
Le damier est encadré en vert. Tester la fonction dans un programme.
*
#include <stdlib.h>
#include <stdio.h>
void damier(void);

int main()
{
    damier();
	return 0;
}

void damier()
{
int x,y;
    for (y=0; y<20; y++){
        for(x=0; x<15; x++)
            printf("%d", (x%2+y%2)%2);
        putchar('\n');
    }
}
/*********************************
Exercice 6
Faire une fonction qui affiche l'alphabet en boucle dans un rectangle de 20
lignes sur 40 colonnes. Chaque alphabet aura ses propres couleurs.
Tester dans un programme.
*
#include <stdlib.h>
#include <stdio.h>
void alphabet(void);

int main()
{
    alphabet();
    return 0;
}
void alphabet()
{
int x,y,l;

    for (y=0,l='A';y<20; y++){
        for (x=0; x<40;x++, l=(l+1)%26 + 'A')
            putchar(l);
        putchar('\n');
    }
}
/*********************************
Exercice 7
Faire une fonction qui génère automatiquement et affiche une phrase simple
différente à chaque appel. Tester dans un programme qui affiche une phrase
à chaque fois que l'on appuie sur une touche clavier. Le programme quitte
si l'on appuie sur la lettre q
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

void affiche_phrase(void);

int main()
{
int fin=0;
    srand(time(NULL));

    while(fin!='q'){
        if(kbhit()){
            fin=getch();
            affiche_phrase();
        }
    }
	return 0;
}
// remarque l'énoncé dit qu'il faut générer automatiquement une phrase simple
// mais à ce niveau du livre nous ne disposons pas des chaines de caractères
// considérons donc un choix parmi des phrases existantes :
void affiche_phrase()
{
    switch(rand()%5){
        case 0 : printf("il fait beau\n");                      break;
        case 1 : printf("je prends ma canne et mon chapeau\n"); break;
        case 2 : printf("et je m'en vais \n");                  break;
        case 3 : printf("faire une partie de domino\n");        break;
        case 4 : printf("chez mon oncle a Bobino\n");           break;
    }
}
/*********************************
Exercice 8
Dans un programme un menu propose les actions suivantes :
- bombardement d'un nombre aléatoire de lettres multicolores dans la
fenêtre console
- bombardement d'un nombre aléatoire de lignes verticales,
horizontales ou diagonales. Les  tailles sont toujours aléatoires.
Il est conseillé de faire une fonction par type de ligne.
- dessin d'un rectangle de taille aléatoire dans la fenêtre console
- bombardement aléatoire de lettres, de lignes ou de rectangles.
Faire le programme. Le programme quitte à la demande de l'utilisateur.
*
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

// déclaration des fonctions :
void lettre(void);
void lignes(void);
void ligne_h(void);
void ligne_v(void);
void ligne_d(void);
void rectangle(void);
void all(void);
void efface(void);
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond

int main()
{
int fin=0;
    srand(time(NULL));

    // la taille de la zone de jeu est supposée de 20 lignes sur 80 colonnes

    while(!fin){

        gotoxy(0,20+1);
        textcolor(15);
        printf( "1 : bombarde lettres \n"
                "2 : bombarde lignes\n"
                "3 : dessin rectangles\n"
                "4 : bombarde all\n"
                "5 : efface\n");

        switch(getch()){
            case '1' : lettre();     break;
            case '2' : lignes();     break;
            case '3' : rectangle(); break;
            case '4' : all();        break;
            case '5' : efface();     break;
            default: fin=1;
        }
    }

    gotoxy(0,20+7);
	return 0;
}

// définition des fonctions
void lettre()
{
int nb;
    nb=1+rand()%10;
    while(nb--){
        gotoxy(rand()%80,rand()%20);
        textcolor(rand()%256);
        putchar('A'+rand()%26);
    }
}
void lignes()
{
int nb=1+rand()%10;
    while(nb--){
        switch(rand()%3){
            case 0 : ligne_h(); break;
            case 1 : ligne_v(); break;
            case 2 : ligne_d(); break;
        }
    }
}
void ligne_h()
{
int x,y,tx,i;

    tx=1+rand()%20; // taille ligne entre 1 et 20
    x=rand()%80;// position h dans la zone
    y=rand()%20; //position h dans la zone

    textcolor((1+rand()%15)<<4); // couleur de fond
    for( i=x; i<x+tx && i<80; i++){
        gotoxy(i,y);
        putchar(' ');
    }
}
void ligne_v()
{
int x,y,ty,i;

    ty=1+rand()%10; // taille ligne entre 1 et 10
    y=rand()%20;// position h dans la zone
    x=rand()%80; //position h dans la zone
    textcolor((1+rand()%15)<<4);
    for( i=y; i<y+ty && i<20; i++){
        gotoxy(x,i);
        putchar(' ');
    }
}
void ligne_d()
{
int x,y,t,px,py;

    t=1+rand()%10;
    x=rand()%80;
    y=rand()%20;
    px=rand()%2*2-1; // -1 ou 1
    py=rand()%2*2-1;

    textcolor((1+rand()%15)<<4); // couleur de fond
    while(t--){
        if(x<80 && y<20 && x>=0 && y>=0){
            gotoxy(x,y);
            putchar(' ');
        }
        x+=px;
        y+=py;
    }
}
void rectangle()
{
int x,y,tx,ty,i,j;
    x=rand()%80;
    y=rand()%20;
    tx=1+rand()%10;
    ty=1+rand()%5;
    textcolor((1+rand()%15)<<4);
    for(j=y; j<y+ty && j<20; j++)
        for(i=x; i<x+tx && i<80; i++){
            gotoxy(i,j);
            putchar(' ');
        }
}
void all()
{
int nb=1+rand()%10;
    while(nb--){
        switch(rand()%3){
            case 0 : lettre();      break;
            case 1 : lignes();      break;
            case 2 : rectangle();  break;
        }
    }
}
void efface()
{
int x,y;
    textcolor(0);
    for(y=0;y<20;y++)
        for(x=0;x<80;x++){
            gotoxy(x,y);
            putchar(' ');
        }
}
void gotoxy(int x, int y)
{
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/*********************************
Exercice 9
Ecrire une fonction run() qui permet de faire bouger une lettre à
l'écran contrôlée par les flèches du clavier. La fonction renvoie
une valeur dont l'interprétation permet de mettre fin au programme.
*
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

// l'écriture de cette fonction suppose d'avoir la position
// de la lettre :
// - en "globale", c'est à dire accessible de toutes
// les fonctions du programme sur le même fichier.
// - ou en static locale à la fonction. Une variable static locale à une
// fonction est réservée en mémoire tout le temps de l'exécution du programme
// à partir du premier appel de la fonction. De ce fait une variable static
// conserve sa valeur d'un appel de la fonction à un autre.

//L'accessibilité des variables est détaillée au chapitre
// 3/H Gestion des variables p.21

// la taille de la zone de mouvement déclarée en globale
const int TX=40;
const int TY=20;

void gotoxy(int x, int y);
void textcolor(int color);
int run(void);

int main()
{
int fin=0;
    printf("appuyer sur les fleches");
    while(!fin){
        fin=run();
    }

	return 0;
}
int run()
{
// la position de la lettre déclarée en static
// l'initialisation a lieu une seule fois, lors du premier appel
static int x = 10;
static int y = 10;
int fin=0;
    if(kbhit()){
        textcolor(0);
        gotoxy(x,y);
        putchar('L');
        switch(getch()){
            case 72 :   y--;   break;  // haut
            case 77 :	x++;	break;	// droite
            case 80 :	y++;	break;	// bas
            case 75 :	x--;	break;	// gauche
            case 224 : 	        break;	// évacuer la touche combinée
            default :   fin=1;  break;  // autre touche : met fin au prg
        }
        // contrôler les bords
        if (x<0)
            x=TX;
        if (x>TX)
            x=0;
        if (y<0)
            y=TY;
        if (y>TY)
            y=0;
        textcolor(13);
        gotoxy(x,y);
        putchar('L');
    }
    return fin;
}
void gotoxy(int x, int y)
{
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


/*********************************
Exercice 10
Faire une fonction qui affiche le caractère (table ASCII) correspondant
à une valeur numérique décimale entre 0 et 255. A partir de cette fonction
faire une deuxième fonction qui affiche toute la table ASCII.
*
#include <stdlib.h>
#include <stdio.h>
void affiche(int c);
void ascii(void);
int main()
{
    ascii();
	return 0;
}
void affiche(int c)
{
        printf("%d : caractere %c\n", c,c);
}
void ascii()
{
 int i;
        for (i=0; i<256; i++)
            affiche(i);
}
/*********************************
Exercice 11
Faire une fonction qui donne la moyenne de trois nombres quels qu'ils soient
(flottants ou non). Tester dans un programme. Le programme quitte uniquement
lorsque l'utilisateur le demande.
*
#include <stdlib.h>
#include <stdio.h>
float moyenne(float a, float b, float c)
{
    return(a+b+c)/3;
}
int main()
{
char joue='o';
float v1,v2,v3;
    while(joue=='o'){
        printf("entrer trois nombres :");
        scanf("%f%f%f",&v1,&v2,&v3);
        rewind(stdin);

        printf("moyenne : %.2f\n",moyenne(v1,v2,v3));

        printf("continuer ?(o/n)");
        scanf("%c",&joue);
        rewind(stdin);
    }
	return 0;
}
/*********************************
Exercice 12
Ecrire une première fonction qui indique si un nombre entier est
multiple de 2 ou non. Ecrire une seconde fonction qui indique si
un nombre entier est multiple de 3 ou non. Utiliser ces deux fonctions
dans un programme qui lit un nombre entier et précise s'il est pair,
multiple de 3 et/ou multiple de 6. Le programme quitte uniquement
lorsque l'utilisateur le demande.
 Exemple d'exécution :

 	entrer un nombre : 9
 	il est multiple de 3

    Recommencer ?  (o/n)

Autre exemple :

entrer un nombre : 12
il est pair, multiple de 3 et divisible par 6

Recommencer ?  (o/n)
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
char joue='o';
int val;
    while(joue=='o'){
        printf("entrer un nombre :");
        scanf("%d",&val);
        rewind(stdin);

        printf("%s",multiple_2(val)? "multiple de deux\n": "n'est pas multiple de deux\n");
        printf("%s",multiple_3(val)? "multiple de trois\n": "n'est pas multiple de trois\n");
        (multiple_2(val)&&multiple_3(val)) ? printf("multiple de six\n") : printf("non multiple de six\n") ;

        printf("continuer ?(o/n)");
        scanf("%c",&joue);
        rewind(stdin);
    }


	return 0;
}

int multiple_2(int v)
{
    return v%2 == 0;
}
int multiple_3(int v)
{
    return v%3 == 0;
}
/*********************************
Exercice 13
Soit un barème de l'impôt défini comme suit : pour un ménage X avec
un revenu total R et un nombre n de membres du foyer, l'impôt est donné par :
	10% de R si r/n <500 euros
	20% de R si R/n >=500 euros

Écrire une fonction qui calcule le montant de l'impôt en fonction de R et de n
Écrire une fonction qui donne le revenu net d'un ménage après paiement de l'impôt
en fonction de R et de n. Tester dans un programme, R et n sont entrés par
l'utilisateur ensuite le montant de l'impôt et le revenu net du ménage sont affichés.
Le programme quitte uniquement lorsque l'utilisateur le demande.
*
#include <stdlib.h>
#include <stdio.h>

int impot(int R, int n);
int revenu_net(int R, int impot);

int main()
{
int joue='o';
int n, R;

    while(joue=='o'){
        printf("nombre de membre au foyer :" );
        scanf("%d",&n);
        rewind(stdin);

        printf("Revenu du foyer :" );
        scanf("%d",&R);
        rewind(stdin);

        printf("impot : %d\n",impot(R,n));
        printf("revenu net : %d\n",revenu_net(R, impot(R,n)));

        printf("continuer ?(o/n)");
        scanf("%c",&joue);
        rewind(stdin);
    }
	return 0;
}
int impot(int R, int n)
{
int res;
    if (R/n<500)
       res=R*0.1;
    else
        res=R*0.2;
    return res;
}
int revenu_net(int R, int impot)
{
    return R-impot;
}
/*********************************
Exercice 14
Ecrire une fonction qui reçoit en argument deux nombres flottants et un caractère
qui correspond à une opération (+, -, /, *, %). La fonction retourne le résultat
de l'opération spécifiée par le caractère. Le programme quitte uniquement lorsque
l'utilisateur le demande.
*
#include <stdlib.h>
#include <stdio.h>
float operation(float v1, float v2, char op);
int main()
{
int joue='o';
float v1,v2;
char op;

    while(joue=='o'){

        printf("entrer deux nombres :");
        scanf("%f%f",&v1,&v2);
        rewind(stdin);

        printf("operation ? (+ - * / \%\n");// le modulo ne s'affiche pas mais il marche
        scanf("%c",&op);
        rewind(stdin);

        printf("resultat : %.2f\n",operation(v1,v2,op));

        printf("continuer ?(o/n)");
        scanf("%c",&joue);
        rewind(stdin);
    }
	return 0;
}
float operation(float v1, float v2, char op)
{
    switch(op){
        case '+' : return v1+v2; break;
        case '-' : return v1-v2; break;
        case '*' : return v1*v2; break;
        case '/' : return v1/v2; break;
        case '%' : return (int)v1%(int)v2; break;
        default :
            printf("operateur inconnu\n");
            return 0;
    }
}
/*********************************
Exercice 15
Soit une zone maximum de 24 lignes par 79 colonnes, écrire tout d'abord une fonction
qui affiche un caractère à une position donnée et d'une couleur donnée. Ensuite :
Ecrire une fonction qui bombarde nb fois l'écran de lettres de façon aléatoire.
Le nombre des répétitions est entré par l'utilisateur.
- Ecrire une fonction qui remplit la zone en cible rectangulaire avec une lettre
différente pour chaque tour intérieur.
- Ecrire une fonction qui peut afficher un rectangle de lettres d'une couleur
donnée et d'une taille donnée dans la zone.
- Ecrire une fonction qui bombarde nb fois de rectangles colorés la zone
(attention à ne pas écrire en dehors de la zone).
- Ecrire une fonction qui affiche une spirale rectangulaire d'une taille
maximum donnée en paramètre.
Dans un programme de test proposer un menu à l'utilisateur.
Le programme quitte lorsque l'utilisateur en donne la commande.
*
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int     menu            (void);
void    lettre          (int x, int y, int l, int color);
void    bombarde_lettres(int nb);
void    ligne_v         (int x, int y1, int y2, int l, int color);
void    ligne_h         (int x1, int x2, int y,int l, int color);
void    cadre           (int x1, int y1, int x2, int y2, int l, int color);
void    cible           (int x1, int y1, int x2, int y2, int c1,int c2);
void    rectangle       (int x1, int y1, int x2, int y2, int l, int color);
void    bombarde_rect   (int nb);
void    spirale         (int x, int y, int tx, int ty, int l, int color);
void    gotoxy          (int x, int y);
void    textcolor       (int color);

// taille max en globale de la zone d'action
const int TX = 79;
const int TY = 24;

int main()
{
int nb,fin=0;
    srand(time(NULL));

    while (!fin){
        switch(menu()){ // attention getch retourne une valeur ascii
            case '1' :
                gotoxy(0,0);
                // c'est mieux sans l'entrée utilisateur
                //printf("combien de lettres ?\n");
                //scanf("%d",&nb);
                //rewind(stdin);
                //bombarde_lettres(nb);
                bombarde_lettres(1+rand()%15);
                break;

            case '2' :
                cible(0, 0, TX,TY,10,12);
                break;

            case '3' :
                bombarde_rect(1+rand()%10);
                break;

            case '4' :
                spirale(0, 0, TX, TY, ' ', 14<<4);
                break;

            default : fin=1;
        }
    }
    gotoxy(0,TY+5);
	return 0;
}
int menu()
{
    gotoxy(0,TY+1);
    textcolor(15);
    printf("1 : bombarde lettres\n"
           "2 : cible\n"
           "3 : bombarde rectangles\n"
           "4 : spirale\n");
    return getch();
}
void lettre(int x, int y, int l, int color)
{
    // vérifier que l'on est bien dans la fenêtre console
    // la taille supposée et la taille par défaut  de 80 par 25
    if(x>=0 && x<80 && y>=0 && y<25){
        gotoxy(x,y);
        textcolor(color);
        putchar(l);
    }
}
void bombarde_lettres(int nb)
{
    while(nb--)
        lettre(rand()%TX,rand()%TY,1+rand()%26,1+rand()%255);
}
void ligne_v(int x, int y1, int y2, int l, int color)
{
    if(y1>y2){
        y1^=y2;
        y2^=y1;
        y1^=y2;
    }
    while(y1 <= y2){
        lettre(x, y1, l, color);
        y1++;
    }
}
void ligne_h(int x1, int x2, int y,int l, int color)
{
    if(x1>x2){
        x1^=x2;
        x2^=x1;
        x1^=x2;
    }
    while(x1<=x2){
        lettre(x1,y,l,color);
        x1++;
    }
}
void cadre(int x1, int y1, int x2, int y2, int l, int color)
{
    ligne_v(x1, y1, y2, l, color);
    ligne_v(x2, y1, y2, l, color);
    ligne_h(x1, x2, y1, l, color);
    ligne_h(x1, x2, y2, l, color);
}
void cible(int x1, int y1, int x2, int y2, int c1,int c2)
{
int c,v=0;
int l;
// int tmps;

    while(x1<=x2 && y1<=y2){
        l='A'+rand()%26;
        c =(v==0) ? c1 : c2; // alternance 2 couleurs
        cadre(x1,y1,x2,y2,l,c);
        x1++;
        x2--;
        y1++;
        y2--;
        v=1-v; // alterne 0 et 1

        // pour voir le dessin se faire
        //tmps=clock();
        //while(clock()<tmps+500){}
    }

}
void rectangle(int x1,int y1,int x2,int y2,int l, int color)
{
    if(y1>y2){
        y1^=y2;
        y2^=y1;
        y1^=y2;
    }
    while(y1<y2){ // la ligne en y2 n'est pas comprise
        ligne_h(x1, x2, y1, l, color);
        y1++;
    }
}
void bombarde_rect(int nb)
{
    while(nb--)
        rectangle(rand()%TX,rand()%TY,rand()%TX,rand()%TY,rand()%26+'A',rand()%15+1);
}


void spirale(int x, int y, int tx, int ty, int l, int color)
{
int tmps;
    while(tx!=0 && ty!=0){

        ligne_v(x, y, y+ty, l, color);
        ligne_h(x, x+tx, y+ty, l, color);
        x=x+tx;
        y=y+ty;
        tx=(tx>0)? (tx-2)*-1 : (tx+2)*-1;
        ty=(ty>0)? (ty-2)*-1 : (ty+2)*-1;


        tmps=clock();
        while(clock()<tmps+100){}
    }
}


void gotoxy(int x, int y)
{
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
/*********************************
Exercice 16
Soit le programme ci-dessous,
- Dites ce qu'il fait,
- donnez les commentaires
- Remplacer les séquences de code qui se répètent par des fonctions
- Ecrire une fonction qui permet de tracer un rectangle à la position,
de la  taille et de la couleur et de la lettre que l'on veut et l'utiliser
pour le cadre.
- A quel endroit appeler cette fonction et avec quelles valeurs dans
le code ci-dessous ?
- Ecrire une fonction pour ralentir le processus.
- Tester le programme

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void    gotoxy          (int x, int y);
void    textcolor       (int color);

int main()
{
const int TX = 40;
const int TY = 20;
int x,y,res,i;

int fin=0;

    srand(time(NULL));

    // commentaire 1 : il s'agit de l'encadrement de la zone de jeu
    // trace un ligne de TX en haut fenetre console
    // caractere ' ' de couleur 12
    for(i=0; i<=TX; i++){
        gotoxy(i,0);
        textcolor(12*16);
        putchar(' ');
    }
    // com 2 : trace un ligne de TX en bas à TY dans la fenetre console
    // caractere ' ' de couleur 12
    for(i=0; i<=TX; i++) {
        gotoxy(i,TY);
        textcolor(12*16);
        putchar(' ');
    }
    // com 3 : trace ligne verticale de TY sur le bord gauche ,
    // caractère ' ', couleur 12
    for(i=0; i<=TY; i++){
        gotoxy(0,i);
        textcolor(12*16);
        putchar(' ');
    }
    // com 4 : trace une ligne verticale de TY à droite, colonne TX,
    // caractère ' ' couleur 12
    for(i=0; i<=TY; i++){
        gotoxy(TX,i);
        textcolor(12*16);
        putchar(' ');
    }

    // com 5 : initialisation position de départ lettre
    x=rand()%TX;
    y=rand()%TY;

    // com 6 : affichage lettre position de départ
    gotoxy(x,y);
    textcolor(10);
    putchar('P');

    // com 7 : boucle du jeu
    while (!fin){

        // com 8 : si touche appuyée
        if (kbhit()){

            // com 9 : effacer la lettre à sa position courante
            gotoxy(x,y);
            textcolor(0);
            putchar('P');

            // com 10 : récupérer la touche appuyée et modifier la position en fonction
            res=getch();
            switch(res){
                case 72 : y--; break;  // 11 : monte
                case 77 : x++; break;  // 12 : va à droite
                case 80 : y++; break;  // 13 : descend
                case 75 : x--; break;  // 14 : va à gauche
                case 224 : break;
                default : fin = 1;      // 15 : termine le programme
            }

            // com 16  : controle des bords, écran circulaire (passe d'un bord à l'autre)
            if (x < 1)
              x = TX-1;
            if (x>=TX)
              x = 1;
            if (y < 1)
              y = TY-1;
            if (y>=TY)
              y = 1;

            // com 17 : affiche la lettre à sa nouvelle position
            gotoxy(x,y);
            textcolor(10);
            putchar('P');
        }
    }
    gotoxy(0,TY+2);
    return 0;
}

void gotoxy(int x, int y)
{
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
*
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void    lettre      (int x, int y, int l, int color);
void    ligne_v     (int x, int y1, int y2, int l, int color);
void    ligne_h     (int x1, int x2, int y,int l, int color);
void    cadre       (int x1, int y1, int x2, int y2, int l, int color);
void    gotoxy      (int x, int y);
void    textcolor   (int color);

int main()
{
const int TX=40;
const int TY=20;
int fin=0;
int x,y,res;

    srand(time(NULL));

    cadre(0,0,TX,TY,' ',12*16);
    x=rand()%TX;
    y=rand()%TY;
    lettre(x,y,'P',10);

    while (!fin){

        if (kbhit()){

            lettre(x,y,'P',0);

            res=getch();
            switch(res){
                case 72 : y--; break;
                case 77 : x++; break;
                case 80 : y++; break;
                case 75 : x--; break;
                case 224 : break;
                default : fin = 1;
            }

            if (x < 1)
              x = TX-1;
            if (x>=TX)
              x = 1;
            if (y < 1)
              y = TY-1;
            if (y>=TY)
              y = 1;

            lettre(x,y,'P',10);
        }
    }
    gotoxy(0,TY+2);
	return 0;
}

void lettre(int x, int y, int l, int color)
{
    // vérifier que l'on est bien dans la fenêtre console
    // la taille supposée et la taille par défaut  de 80 par 25
    if(x>=0 && x<80 && y>=0 && y<25){
        gotoxy(x,y);
        textcolor(color);
        putchar(l);
    }
}
void ligne_v(int x, int y1, int y2, int l, int color)
{
    //verifier si y1 < y2 et sinon inverser
    if(y1>y2){
        y1^=y2;
        y2^=y1;
        y1^=y2;
    }
    while(y1 <= y2){
        lettre(x, y1, l, color);
        y1++;
    }
}
void ligne_h(int x1, int x2, int y,int l, int color)
{
    // vérifier si x1 est bien inférieur à x2
    // sinon inverser
    if(x1>x2){
        x1^=x2;
        x2^=x1;
        x1^=x2;
    }
    while(x1<=x2){
        lettre(x1,y,l,color);
        x1++;
    }
}
void cadre(int x1, int y1, int x2, int y2, int l, int color)
{
    ligne_v(x1, y1, y2, l, color);
    ligne_v(x2, y1, y2, l, color);
    ligne_h(x1, x2, y1, l, color);
    ligne_h(x1, x2, y2, l, color);
}
void gotoxy(int x, int y)
{
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void textcolor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
/*********************************
*/





