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
*   6. Typiques utilisations de boucles                          *
*   6.4 Mise en pratique : menus, boucles d'événements	            *
*********************************************************************

/*********************************
Exercice 1
En reprenant le code du cours :
ajouter un trèsor, quand l'utilisateur le trouve il marque un point,
son score est affiché
ajouter un ennemi mobile, si l'utilisateur est touché il a perdu.
ajouter un balon pour le player. Lorsque le player s'en approche il
peut shooter et conduire le ballon.


REMARQUE :
 sans fonction et sans structure le code est vite alourdi.
 pour répondre nous allons faire deux programmes :
  - le premier comprend joueur trésor et ennemi
  - le second un joueur de foot et son ballon

*
// 1 JOUEUR,TRESOR, ENNEMI

#include <stdlib.h>
#include <stdio.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

// déclaration de deux fonctions incontournables dans ce contexte
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond

int main()
{
int jx,jy; // coordonnées du joueur
int score,oldscore; // score du joueur
int tx,ty; // coordonnées trésor
int ex,ey,edx,edy; // ennemi mobile, position et deplacement

const int TX = 20; // taille zone de jeu
const int TY = 15;

int fin =0, start;

    // initialisations
    srand(time(NULL));

    // trésor
    tx=rand()%TX;
    ty=rand()%TY;
    gotoxy(tx,ty);
    textcolor(8);
    putchar('T');

    // joueur
    jx=rand()%TX;
    jy=rand()%TY;
    gotoxy(jx,jy);
    textcolor(10);
    putchar('J');

    // ennemi
    ex=rand()%TX;
    ey=rand()%TY;
    edx=0;
    edy=0;
    gotoxy(ex,ey);
    textcolor(11);
    putchar('E');

    // SCORE
    score=0;
    gotoxy(TX+1,TY/2);
    textcolor(3);
    printf("SCORE : %4d",score);

    // boucle du jeu
    start = clock(); // controle du temps pour l'ennemi
    while(!fin){

        // les actions de l'ennemi sont exécutées une fois tous les 200 millisecondes
        // mais ce n'est pas bloquant
        if(clock()>start+200){
            start=clock();

            // effacer
            gotoxy(ex,ey);
            textcolor(0);
            putchar('E');

            // bouger : l'ennemi cherche le joueur
            if(ex<jx )
                edx=1;
            else if(ex>jx)
                edx=-1;
            else
                edx=0;

            if(ey<jy )
                edy=1;
            else if(ey>jy)
                edy=-1;
            else
                edy=0;

            ex+=edx;
            ey+=edy;

            // controle bords : en principe inutile (cherche joueur)

            // joueur trouvé ?
            if(ex==jx&&ey==jy){
                gotoxy(TX+1,TY/2+1);
                textcolor(4);
                printf("PERDU !");
                fin=1;
            }

            // afficher
            gotoxy(ex,ey);
            textcolor(11);
            putchar('E');
        }

        if(kbhit()){

            // effacer le joueur à sa position
            gotoxy(jx,jy);
            textcolor(0);
            putchar('J');

            // récupérer la touche appuyée et en fonction
            // modifier ses coordonnées
            switch(getch()){
                case 72 :   jy--;   break;  // haut
                case 77 :	jx++;	break;	// droite
                case 80 :	jy++;	break;	// bas
                case 75 :	jx--;	break;	// gauche
                case 224 : 	        break;	// évacuer la touche combinée
                default :   fin=1;  break;  // autre touche : met fin au prg
            }
            // contrôler les bords
            if (jx<0)
               jx=TX;
            if (jx>TX)
                jx=0;
            if (jy<0)
                jy=TY;
            if (jy>TY)
                jy=0;

            // afficher joueur à ses nouvelles coordonnées
            gotoxy(jx,jy);
            textcolor(10);
            putchar('J');

            // un trésor trouvé ? si oui score et le trésor
            // saute à une nouvelle position
            oldscore=score;
            if(jx==tx && jy==ty){
                score++;
                tx=rand()%TX; // replace le trèsor ailleurs
                ty=rand()%TY;
                gotoxy(tx,ty);
                textcolor(8);
                putchar('T');
            }

            if(oldscore!=score){
                gotoxy(TX+1,TY/2);
                textcolor(3);
                printf("SCORE : %4d",score);
            }
        }
    }
    gotoxy(0,TY+1);
	return 0;
}
// définition des fonctions
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

/**
2) JOUEUR DE FOOT ET SON BALLON
*
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

//
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond

int main()
{
int jx,jy; // coordonnées du joueur
int bx,by,cntlb; // ballon position, controle ou pas
int dir=0; // direction deplacement : 0 rien, 1 haut, 2 droite, 3 bas, 4 gauche
int dist;  // distance shoot
    // caractèristiques du ballon :
    // - lorsque le joueur controle le ballon, le ballon est toujours devant le joueur
    // - la touche espace envoie le ballon en avant du joueur selon sa direction
    // - si le joueur n'est pas collé au ballon le ballon ne bouge pas

const int TX = 20; // taille zone de jeu
const int TY = 15;

int fin =0;

    // initialisations
    srand(time(NULL));

    // joueur
    jx=1+rand()%(TX-1);
    jy=1+rand()%(TY-1);
    gotoxy(jx,jy);
    textcolor(10);
    putchar('J');

    // ballon
    dir=0;
    bx=rand()%TX; // collé au joueur
    by=rand()%TY;
    cntlb=0;
    gotoxy(bx,by);
    textcolor(11);
    putchar('o');

    // boucle du jeu
    while(!fin){

        if(kbhit()){

            // faut-il controler le ballon ?
            if(bx>=jx-1 && bx<=jx+1 && by>=jy-1 && by<=jy+1)
                cntlb=1;

            // effacer le joueur à sa position
            gotoxy(jx,jy);
            textcolor(0);
            putchar('J');

            // effacer ballon
            gotoxy(bx,by);
            textcolor(0);
            putchar('o');

            // récupérer la touche appuyée et en fonction
            // modifier ses coordonnées avec controle des bords
            switch(getch()){
                case 72 :   // haut
                    if(jy-1>0){
                        jy--;
                        if(cntlb){
                            bx=jx;
                            by=jy-1;
                            dir=1;
                        }
                    }
                    break;

                case 77 :	// droite
                    if(jx+1<TX){
                        jx++;
                        if(cntlb){
                            bx=jx+1;
                            by=jy;
                            dir=2;
                        }
                    }
                    break;

                case 80 :	// bas
                    if(jy+1<TY){
                        jy++;
                        if(cntlb){
                            bx=jx;
                            by=jy+1;
                            dir=3;
                        }
                    }
                    break;

                case 75 :	// gauche
                    if(jx-1>0){
                        jx--;
                        if(cntlb){
                            bx=jx-1;
                            by=jy;
                            dir=4;
                        }
                    }
                    break;

                case 32 : // espace : tir ballon si ballon collé au joeur
                    if(cntlb){
                        dist=2+rand()%10;
                        switch(dir){
                            case 1 : // haut
                                by-=dist;
                                by=(by<0)? 0 : by;
                                break;
                            case 2 : // droite
                                bx+=dist;
                                bx=(bx>TX)? TX: bx;
                                break;
                            case 3 : // bas
                                by+=dist;
                                by=(by>TY)? TY : by;
                                break;
                            case 4 : // gauche
                                bx-=dist;
                                bx=(bx<0)? 0: bx;
                                break;
                        }
                        cntlb=0;
                    }
                    break;
                case 224 :
                    break;	// évacuer la touche combinée

                default :
                    fin=1;  break;  // autre touche : met fin au prg
            }

            // afficher joueur à ses nouvelles coordonnées
            gotoxy(jx,jy);
            textcolor(10);
            putchar('J');

            // afficher le ballon
            gotoxy(bx,by);
            textcolor(11);
            putchar('o');
        }
    }
    gotoxy(0,TY+1);
	return 0;
}
// définition des fonctions
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
Exercice 2
Faire un petit convertisseur franc-euro et euro-franc.
Le programme propose un menu avec les deux possibilités,
à l’issue d’une conversion il propose à l’utilisateur de
recommencer ou de quitter (1 euro vaut 6,55759 francs)
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int choix,fin=0;
float val;

    while(!fin){
        printf("conversion :\n");
        printf("1 : franc->euro\n"
               "2 : euro ->franc\n");
        choix=0; // si erreur au scanf() choix conservera valeur 0
                 //(case default dans le switch)
        scanf("%d",&choix);
        rewind(stdin);

        if(choix >=1 && choix<=2){
            printf("enter le montant :");
            scanf("%f",&val);
            rewind(stdin);
        }

        switch(choix){
            case 1 : printf("montant en euro  : %.2f\n",val/6.55759);   break;
            case 2 : printf("montant en franc : %.2f\n",val*6.55759);   break;
            default : fin=1;
        }
    }
	return 0;
}
/*********************************
Exercice 3
Faire le programme qui affiche des zéros en continue et,
si une touche est appuyée, un nombre aléatoire de fois la
lettre ou le chiffre correspondant.
*
#include <stdlib.h>
#include <stdio.h>
#include <conio.h> // fonctions getch() et kbhit()
int main()
{
 int nb,c=0;

    while(c!='q'){// q pour quitter
        putchar('0'); // 0 par defaut
        if(kbhit()){  // touche appuyée
            c=getch(); // recup touche
            nb=rand();  // tirage nombre de répétitions
            while(nb--)  // répétitions
                putchar(c);
        }
    }
	return 0;
}
/*********************************
Exercice 4
Imaginer un automate distributeur de boissons.
Comment fonctionne votre automate : interface, choix, monnaie,
approvisionnement ? Quelles sont les variables nécessaires à sa
réalisation ? Écrire l’algorithme et programmez une simulation
avec les entrées sorties scanf() et printf().
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
// 4 produits : coca, biere, soupe,choco
// pour chaque produit le prix (float) et le nombre disponible (int)

int d_coca,d_biere,d_soupe,d_choco,type ; // dispo produit
float p_coca,p_biere,p_soupe,p_choco,prix ; // prix produit

int choix,fin=0;
float monnaie,in;

    // initialisations :
    d_coca = d_biere = d_soupe = d_choco = 5; //5 au départ
    p_coca=0.40;
    p_biere=0.50;
    p_soupe=0.25;
    p_choco=0.35;

    while (!fin){
        // invite machine :
        printf("quel produit voulez-vous ?\n"
               "1 : coca\n"
               "2 : biere\n"
               "3 : soupe\n"
               "4 : choco\n");
        scanf("%d",&choix);
        rewind(stdin);

        // choix
        prix=0;
        type=choix;
        switch(choix){
            case 1 :
                if(d_coca>0)
                    prix=p_coca;
                break;
            case 2 :
                if(d_biere>0)
                    prix=p_biere;
                break;
            case 3 :
                if(d_soupe>0)
                    prix=p_soupe;
                break;
            case 4 :
                if(d_choco>0)
                    prix=p_choco;
                break;
            default : fin=1;

        }
        //paiement
        if(!prix &&fin==0)
            printf("desole, article indisponible\n");
        else{
            // entree de la monnaie
            // in 0 ou négatif provoque annulation
            monnaie=0;
            in=1;
            while (monnaie<prix && in>0){
                if(monnaie < prix)
                    printf("montant : %.2f reste : %.2f\n",monnaie, prix-monnaie);
                scanf("%f", &in);
                rewind(stdin);
                monnaie+=in;

                // si annulation
                if(in<=0){
                    printf("sortie monnaie entree : %.2f\n",monnaie);
                    printf("au revoir\n");
                }
            }
            // sortie boisson et monnaie, mise à jour dispo
            if (monnaie>=prix){
                printf("votre monnaie : %.2f\n",monnaie-prix);
                printf("votre boisson : ");
                switch(type){
                    case 1 :
                        d_coca--;
                        printf("coca\n");
                        break;
                    case 2 :
                        d_biere--;
                        printf("biere\n");
                        break;
                    case 3 :
                        d_soupe--;
                        printf("soupe\n");
                        break;
                    case 4 :
                        d_choco--;
                        printf("choco\n");
                        break;
                }
            }
        }
    }
	return 0;
}
/*********************************
Exercice 5
Le player se déplace à l’écran avec les touches flèche. Dans la
zone de mouvement il y a des trésors à découvrir. Le player marque
des points en fonction de ce qu'il ramasse sur le terrain. Faire
le programme.
*
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

// déclaration de deux fonctions incontournables dans ce contexte
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond

int main()
{
int jx,jy; // coordonnées du joueur
int score,oldscore; // score du joueur
int tx1,ty1,tx2,ty2,tx3,ty3; // coordonnées des trésors
int v1,v2,v3; // valeurs des trésors
const int TX = 20; // taille zone de jeu
const int TY = 15;

int fin =0;

    // initialisations
    srand(time(NULL));
    // trésor 1
    tx1=rand()%TX;
    ty1=rand()%TY;
    v1=1+rand()%15;
    gotoxy(tx1,ty1);
    textcolor(v1);
    putchar('1');
    // trésor 2
    tx2=rand()%TX;
    ty2=rand()%TY;
    v2=1+rand()%15;
    gotoxy(tx2,ty2);
    textcolor(v2);
    putchar('2');
    //trésor 3
    tx3=rand()%TX;
    ty3=rand()%TY;
    v3=1+rand()%15;
    gotoxy(tx3,ty3);
    textcolor(v3);
    putchar('3');
    // joueur
    jx=rand()%TX;
    jy=rand()%TY;
    gotoxy(jx,jy);
    textcolor(10);
    putchar('J');
    // SCORE
    score=0;
    gotoxy(TX+1,TY/2);
    textcolor(3);
    printf("SCORE : %4d",score);

    // boucle du jeu
    while(!fin){

        if(kbhit()){

            // effacer le joueur à sa position
            gotoxy(jx,jy);
            textcolor(0);
            putchar('J');

            // récupérer la touche appuyée et en fonction
            // modifier ses coordonnées
            switch(getch()){
                case 72 :   jy--;   break;  // haut
                case 77 :	jx++;	break;	// droite
                case 80 :	jy++;	break;	// bas
                case 75 :	jx--;	break;	// gauche
                case 224 : 	        break;	// évacuer la touche combinée
                default :   fin=1;  break;  // autre touche : met fin au prg
            }
            // contrôler les bords
            if (jx<0)
               jx=TX;
            if (jx>TX)
                jx=0;
            if (jy<0)
                jy=TY;
            if (jy>TY)
                jy=0;

            // afficher joueur à ses nouvelles coordonnées
            gotoxy(jx,jy);
            textcolor(10);
            putchar('J');

            // un trésor trouvé ? si oui score et le trésor
            // saute à une nouvelle position
            oldscore=score;
            if(jx==tx1 && jy==ty1){
                score+=v1;
                tx1=rand()%TX;
                ty1=rand()%TY;
                v1=1+rand()%15;
                gotoxy(tx1,ty1);
                textcolor(v1);
                putchar('1');
            }
            if(jx==tx2 && jy==ty2){
                score+=v2;
                tx2=rand()%TX;
                ty2=rand()%TY;
                v2=1+rand()%15;
                gotoxy(tx2,ty2);
                textcolor(v2);
                putchar('2');
            }
            if(jx==tx3 && jy==ty3){
                score+=v3;
                tx3=rand()%TX;
                ty3=rand()%TY;
                v1=1+rand()%15;
                gotoxy(tx3,ty3);
                textcolor(v3);
                putchar('3');
            }
            if(oldscore!=score){
                gotoxy(TX+1,TY/2);
                textcolor(3);
                printf("SCORE : %4d",score);
            }
        }
    }
    gotoxy(0,TY+1);
	return 0;
}
// définition des fonctions
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
Exercice 6
Deux lettres se déplacent dans une zone de jeu de façon plus ou moins
aléatoire. Lorsqu’elles atteignent un bord elles rebondissent et partent
dans l’autre sens. Faire le programme. Modifier ensuite le programme
afin que lorsque les deux lettres se rencontrent une phrase s'affiche.
*
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

// déclaration de deux fonctions incontournables dans ce contexte
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond

int main()
{
int x1,y1,dx1,dy1,c1,l1; // lettre 1 : position,deplacement, lettre, couleur
int x2,y2,dx2,dy2,c2,l2; // lettre 2
const int TX = 20;
const int TY = 15;
int fin =0,tmps;

    srand(time(NULL));
    // initialisations
    x1=rand()%TX;
    y1=rand()%TY;
    dx1=rand()%2*2-1; // valeur 1 ou -1
    dy1=rand()%2*2-1;
    l1='A'+rand()%26;
    c1=1+rand()%15;

    x2=rand()%TX;
    y2=rand()%TY;
    dx2=rand()%2*2-1; // valeur 1 ou -1
    dy2=rand()%2*2-1;
    l2='A'+rand()%26;
    c2=1+rand()%15;

    // boucle action
    while(!fin){

        // effacer
        gotoxy(x1,y1);
        textcolor(0);
        putchar(l1);

        gotoxy(x2,y2);
        textcolor(0);
        putchar(l2);

        // bouger + controle des bords
        x1+=dx1;
        if(x1<=0||x1>=TX) // si bord inverser le sens
            dx1*=-1;
        y1+=dy1;
        if (y1<=0 || y1>=TY)
            dy1*=-1;
        x2+=dx2;
        if(x2<=0||x2>=TX)
            dx2*=-1;
        y2+=dy2;
        if (y2<=0 || y2>=TY)
            dy2*=-1;

        // contrôle collision
        if(x1==x2 && y1==y2){
            gotoxy(TX+1,TY/2);
            textcolor(14);
            printf("Salut ca va ?");
            gotoxy(TX+1,TY/2+1);
            printf("Pas mal et toi ?");
        }
        // remarque :
        // avec le rebondi contre les bords, chaque entité a un cycle régulier de trajectoire
        // et il est probable qu'elles ne se rencontrent jamais.

        // afficher
        gotoxy(x1,y1);
        textcolor(c1);
        putchar(l1);

        gotoxy(x2,y2);
        textcolor(c2);
        putchar(l2);

        // ralentissement (sinon on ne voit rien)
        tmps=clock();
        while(clock()<tmps+100){ }

        // fin si une touche appuyée
        if(kbhit())
            fin=1;
    }
    gotoxy(0,TY+1);
	return 0;
}

// définition des fonctions
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
Exercice 7
Jeu. On dispose d'une dizaine de lettres. A chaque lettre est attribué
un facteur d'instabilité. Par exemple la lettre 'M' ; très stable a un
facteur d'instabilité de 0, par contre le 'V' a un facteur d'instabilité
de 9. En appuyant sur la touche espace, on empile verticalement des lettres,
choisies aléatoirement par le programme. Le but est d'atteindre un certain
seuil en hauteur mais si le cumul des facteurs d'instabilité est supérieur
ou égal à 50 tout s'écroule. Programmer.
*
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

// déclaration de deux fonctions incontournables dans ce contexte
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond


int main()
{
int l,lc,ly,li; // pour lettre, couleur, position verticale
                // et instabilité de la lettre courante

int nbl; // nombre de lettres accumulées
int instable; // instabilité totale

const int TX = 40;  // position horizontale de la colonne
const int TY = 15;  // sol de la colonne

int fin=0,tmps;

    // initialisation
    nbl=0;
    instable=0;
    gotoxy(TX+3,TY/4);
    textcolor(15);
    printf("nb lettre   : %4d",nbl);
    gotoxy(TX+3,TY/4+1);
    printf("instabilite : %4d",instable);

    while(fin!='q'){

        if(kbhit()){
            fin=getch();

            // au besoin effacement résultat partie précédente
            if (nbl==0){
                gotoxy(TX+3,TY/2);
                textcolor(0);
                printf("     ");
            }

            // lancer une nouvelle lettre
            l='A'+rand()%26; // la lettre
            lc=1+rand()%15; // couleur de la lettre
            ly=0; // départ en haut de la fenetre
            // facteur d'instabilité soit au hasard quelque soit la lettre
            //li=rand()%15;

            // soit en fonction de la lettre
            switch(l){
                case 'A' : li=5;    break;
                case 'B' : li=4;    break;
                case 'C' : li=5;    break;
                case 'D' : li=4;    break;
                case 'E' : li=0;    break;
                case 'F' : li=5;    break;
                case 'G' : li=5;    break;
                case 'H' : li=0;    break;
                case 'I' : li=7;    break;
                case 'J' : li=10;   break;
                case 'K' : li=0;    break;
                case 'L' : li=5;    break;
                case 'M' : li=0;    break;
                case 'N' : li=1;    break;
                case 'O' : li=10;   break;
                case 'P' : li=10;   break;
                case 'Q' : li=8;    break;
                case 'R' : li=5;    break;
                case 'S' : li=5;    break;
                case 'T' : li=5;    break;
                case 'U' : li=10;   break;
                case 'V' : li=10;   break;
                case 'W' : li=3;    break;
                case 'X' : li=0;    break;
                case 'Y' : li=4;    break;
                case 'Z' : li=0;    break;
            }

            // animation descente
            while(ly < TY-nbl){
                // effacer
                gotoxy(TX,ly);
                textcolor(0);
                putchar(l);
                // avancer
                ly++;

                // réafficher
                gotoxy(TX,ly);
                textcolor(lc);
                putchar(l);

                // ralenti
                tmps=clock();
                while(clock()<tmps+100){}
            }

            //actualisation et affichage des données du jeu
            nbl++;
            instable+=li;
            gotoxy(TX+3,TY/4);
            textcolor(15);
            printf("nb lettre   : %4d",nbl);
            gotoxy(TX+3,TY/4+1);
            printf("instabilite : %4d",instable);

            // contrôle
            if(instable >= 50 && nbl<10){
                gotoxy(TX+3,TY/2);
                textcolor(12);
                printf("PERDU");
                instable=nbl=0;
            }
            else if (instable<50 && nbl>=10){
                gotoxy(TX+3,TY/2);
                textcolor(10);
                printf("GAGNE");
                instable=nbl=0;
            }
        }
    }
    gotoxy(0,TY+2);
	return 0;
}
// définition des fonctions
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
Exercice 8
Un petit bonhomme monte un escalier qui débouche sur rien. Arrivé en haut
il avance et tombe dans le vide. Au sol il fait "aie !".  Le compteur compte
un point. Il revient à l'escalier, le remonte et retombe en faisant "aie" et
en marquant un point etc. Programmer.
*
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

// déclaration de deux fonctions incontournables dans ce contexte
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond

int main()
{
// escalier
int dx,dy;   // debut en bas de l'escalier
int ax,ay;   // arrivée en haut de l'escalier
int nbm;     // nombre de marches de l'escalier
int x,y;

// personnage
int px,py,color;

// boucle
int fin=0;
int tmps,n,a;

    // construction de l'escalier (ascii art): faire un dessin sur papier
    // une marche c'est 1 en hauteur et 2 en largeur, sinon les marches
    // sont plus hautes que larges et c'est moins bien visuellement
    //              __
    //            _|
    //          _|
    //        _|
    //      _|
    //

    // initialisation position de l'escalier
    nbm=10;
    dx=6;    // depart en x
    ay=3;    // arrivée en y
    ax=dx+nbm*2;  // arrivée en x
    dy=ay+nbm-1;    // depart en y

    textcolor(15);
    for (y=dy, x=dx; y>ay; y--, x+=2){
        gotoxy(x,y);
        printf("_|");
    }
    //La dernière marche
    gotoxy(x,y);
    putchar('_');

    // initialisation personnage au départ
    px=dx-2;
    py=dy;
    color=13;
    gotoxy(px,py);
    textcolor(color);
    putchar('o');

    while(!fin){

        if(kbhit())
            fin=1 ;

        // avance de 2 et monte 1 nbm fois plus ralenti
        for (n=0; n<nbm; n++){
            // avance
            for(a=0; a<2; a++){
                // effacer
                gotoxy(px,py);
                textcolor(0);
                putchar('o');
                // bouger
                px++;
                // afficher
                gotoxy(px,py);
                textcolor(color);
                putchar('o');
                // pause
                tmps=clock();
                while(clock()<tmps+100){}
            }
            if(n<nbm-1){
                // monte
                // effacer et restaurer la marche
                gotoxy(px,py);
                textcolor(15);
                putchar('_');
                // bouger
                py--;
                // afficher
                gotoxy(px,py);
                textcolor(color);
                putchar('o');
                // pause
                tmps=clock();
                while(clock()<tmps+100){}
            }
        }
        // chute :
        // effacer et restaurer la marche
        gotoxy(px,py);
        textcolor(15);
        putchar('_');
        // avancer de 1
        px++;
        // afficher
        gotoxy(px,py);
        textcolor(color);
        putchar('o');

        // tomber
        while (py<dy){
            // effacer
            gotoxy(px,py);
            textcolor(0);
            putchar(' ');
            // tomber
            py++;
            // afficher
            gotoxy(px,py);
            textcolor(color);
            putchar('o');
            // pause
            tmps=clock();
            while(clock()<tmps+150){}
        }
        // en bas crier aie!
        gotoxy(px+2,py);
        textcolor(color);
        printf("AIE !");
        // pause
        tmps=clock();
        while(clock()<tmps+1200){}
        // effacer crie
        gotoxy(px+2,py);
        textcolor(0);
        printf("aie !");

        // se replacer au départ
        while(px>=dx-1){
            // effacer
            gotoxy(px,py);
            textcolor(0);
            putchar('o');
            // restaurer la première marche effacée
            if(px==dx){
                textcolor(15);
                putchar('|');
            }

            // bouger
            px--;
            // afficher
            gotoxy(px,py);
            textcolor(color);
            putchar('o');
            // pause
            tmps=clock();
            while(clock()<tmps+100){}
        }
    }

    textcolor(15);
    gotoxy(0,dy+2);
	return 0;
}
// définition des fonctions
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
Jeu de dés à deux joueurs. Chaque joueur à son tour jette le dé autant de
fois qu'il veut. Il accumule les points qu'il obtient sauf s'il fait 1 et
s'il fait 1, il ne marque aucun point, il est obligé de s'arrêter et c'est
à l'autre joueur de jouer. Le gagnant est le premier qui dépasse 100.
Faire un programme pour jouer contre l'ordinateur. Le dé n'est pas pipé.
L'ordinateur joue honnêtement quand c'est son tour et lance le dé quand
c'est votre tour. Il affiche toujours ce qui sort et quand c'est à vous
de jouer il vous demande à chaque lancé si vous voulez continuer. Lorsque
la partie est finie il propose une autre partie ou de quitter.
La programmation de ce jeu suppose de concevoir une stratégie pour
l'ordinateur. Quand et comment décide t-il de s'arrêter de lancer le dé ?
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
int joueur; // le joueur courant 0: humain, 1: machine
int score1, score2; // scores joueurs 1 et deux

int de,joue,fin=0,cumul,nbmax; // le de

    srand(time(NULL));

    // initialisations
    score1=score2=0;
    joueur = rand()%2;

    while(!fin){

        // le joueur courant joue
        cumul=0;
        nbmax=0;
        joue='o';
        printf("\n-------------%s joue :\n", (joueur==0) ? "Humain":"Machine" );

        while(joue=='o'){
            de=1+rand()%6;
            // si 1 stop
            if(de==1){
                cumul=0;
                joue='n';
                printf("1 SORT !\n");
            }
            // sinon, cumuler et continuer ou pas
            else{
                // cumul des points
                cumul+=de;

                if(joueur==0){// joueur 1
                    printf("cumul = %3d\n",cumul);
                    printf("continuer ?(o/n)");
                    scanf("%c",&joue);
                    rewind(stdin);
                }
                else{// joueur 2
                    printf("cumul = %3d\n",cumul);
                    // IA machine : joue 5 fois maximum.
                    if ( (++nbmax) > 5)
                        joue='n';
                    // il y a mieux à faire !
                    // selon :
                    //  - nombre de points déjà obtenus
                    //  - fréquence des 1 sortis dans les derniers coups
                    //  - nombre des points du concurent
                }
            }
        }
        // récupération des points
        switch(joueur){
            case 0 :
                score1+=cumul;
                printf("Humain  : %d\n",score1);
                break;
            case 1 :
                score2+=cumul;
                printf("machine : %d\n",score2);
                break;
        }

        // y a-t-il un gagnant ?
        if(score1>50 || score2>50){
            fin=1;
            printf("%s GAGNE\n",(score1>score2) ? "Humain":"Machine");
        }
        joueur^=1;
    }

	return 0;
}
/*********************************
Exercice 10
Master_Mind répondeur. Il se joue avec des pions de couleurs. Le joueur
doit deviner une combinaison cachée faite avec des pions. Par exemple
avec 4 pions ROUGE, VERT, BLEU et JAUNE, voici une combinaison BLEU, JAUNE,
JAUNE, ROUGE,  l'ordre compte.
Pour jouer le joueur propose des combinaisons. Par exemple : ROUGE, VERT, JAUNE,
BLEU. En retour l'ordinateur indique combien de pions ont la bonne couleur ET
sont à la bonne place. Ici 1, JAUNE à la troisième place.
Il indique également le nombre total des bonnes couleurs trouvées, ici 2 couleurs
trouvées : rouge et jaune. Si le joueur à gagné l'ordinateur lui dit en combien
de coups et lui propose une autre partie ou d'arrêter.A chaque partie l'ordinateur
crée une nouvelle combinaison cachée et  répond aux propositions du joueur.
Faire le programme.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
char c1,c2,c3,c4;       // pour combinaison
char cc1,cc2,cc3,cc4;   // pour trouver
char r1,r2,r3,r4;       // combinaison entrée par utilisateur
int c,i,joue='o', nbtours=0;
int bonne_place=0, bonne_couleur;

    srand(time(NULL));
    while(joue=='o'){

        // fabriquer une combinaison cachée avec les lettres R V B J
        for (i=0; i<4; i++){
            c=rand()%4;
            switch(c){
                case 0 : c='R'; break;
                case 1 : c='V'; break;
                case 2 : c='B'; break;
                case 3 : c='J'; break;
            }
            switch(i){
                case 0 : c1=c; break;
                case 1 : c2=c; break;
                case 2 : c3=c; break;
                case 3 : c4=c; break;
            }
        }
        printf("solution = %c%c%c%c\n", c1,c2, c3, c4);

        // trouver la combinaison
        nbtours=0;
        bonne_place=0;
        while(bonne_place<4){

            // recherche
            bonne_place=0;
            bonne_couleur=0;
            printf("entrer une combinaison de RVBJ : ");
            scanf("%c%c%c%c",&r1,&r2,&r3,&r4);
            rewind(stdin);

            // évaluation
            cc1=c1;
            cc2=c2;
            cc3=c3;
            cc4=c4;
            // bonne_place (et bonne couleur)
            if (r1==c1){
                bonne_place++;
                cc1=0;
            }
            if (r2==c2){
                bonne_place++;
                cc2=0;
            }
            if (r3==c3){
                bonne_place++;
                cc3=0;
            }
            if (r4==c4){
                bonne_place++;
                cc4=0;
            }

            // bonne couleur mais mauvaise place dans les pions restants
            bonne_couleur+=(    (cc1==r2||cc1==r3||cc1==r4)+
                                (cc2==r1||cc2==r3||cc2==r4)+
                                (cc3==r1||cc3==r2||cc3==r4)+
                                (cc4==r1||cc4==r2||cc4==r3)
                            );
            // résultat
            printf("bonne place   : %d\n"
                   "bonne couleur : %d\n",bonne_place,bonne_couleur);
            nbtours++;


        }
        printf("TROUVE en %d tours !\n\n",nbtours);

        printf("faire une autre partie ? (o/n)");
        scanf("%c",&joue);
        rewind(stdin);
    }

	return 0;
}
/*********************************
Exercice 11
Faire le jeu du poulet qui traverse une route :

               p

......v.......................v......>
......v...........v..................>
<......v................v...........
<........v.........v................
P, le poulet doit arriver de l'autre côté de la route sans être touché
par une voiture v.  Il y a quatre voies avec au maximum deux voitures
ensembles par voie.
Décomposez la réalisation du programme en plusieurs étapes.
Par exemple : faire le poulet, faire une voie avec une voiture,
ajouter une voiture, ajouter une voie et deux voitures, ajouter
deux voies en sens inverse et quatre voitures.
*
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

// déclaration de deux fonctions incontournables dans ce contexte
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond

int main()
{
int gauche,droite,TX,TY; // la route
int px,py; // poulet
// les voitures, en float pour avoir des vitesses différentes entre 0 et 2
float v1,v2,v3,v4,v5,v6,v7,v8;
float d1,d2,d3,d4,d5,d6,d7,d8;

int fin=0,tmps,i,x,y;

    // initialisations

    // la route
    gauche=5;
    droite=gauche+70;
    TX=droite-gauche;
    TY=5;

    // le poulet
    py=TY/2;        // sur le bord haut
    px=TX/2+gauche; // au milieu de la route
    // afficher le poulet au départ
    gotoxy(px,py);
    textcolor(15);
    putchar('P');

    // les voitures
    v1=v2=v3=v4=droite;
    v5=v6=v7=v8=gauche;

    d1=-0.1+((float)rand()/RAND_MAX)*-1;  // de droite à gauche
    d2=-0.1+((float)rand()/RAND_MAX)*-1;
    d3=-0.1+((float)rand()/RAND_MAX)*-2;
    d4=-0.1+((float)rand()/RAND_MAX)*-2;

    d5=0.1+((float)rand()/RAND_MAX); // de gauche à droite
    d6=0.1+((float)rand()/RAND_MAX);
    d7=0.1+((float)rand()/RAND_MAX)*2;
    d8=0.1+((float)rand()/RAND_MAX)*2;

    // actions
    while(!fin){

        // deplacement du poulet
        if(kbhit()){
           // effacer
           gotoxy(px,py);
           textcolor(0);
           putchar('P');
           // bouger
           switch(getch()){
                case 72 :   py--;   break;  // haut
                case 77 :	px++;	break;	// droite
                case 80 :	py++;	break;	// bas
                case 75 :	px--;	break;	// gauche
                case 224 : 	        break;	// évacuer la touche combinée
                default :   fin=1;  break;  // autre touche : met fin au prg
           }
           // controle bords
           if (px>droite) px=droite;
           if (px<gauche) px=gauche;
           if (py<0)      py=0;
           if (py>TY+10)  py=TY+10;

           // remarque : je ne fais pas le controle des victoires.

           // afficher
           gotoxy(px,py);
           textcolor(15);
           putchar('P');
        }

        // deplacement des voitures :
        // effacer
        textcolor(0);
        for (i=0; i<8; i++){
            switch(i){
                case 0 :    x=v1;  y=TY;     break;
                case 1 :    x=v2;  y=TY;     break;
                case 2 :    x=v3;  y=TY+1;   break;
                case 3 :    x=v4;  y=TY+1;   break;
                case 4 :    x=v5;  y=TY+2;   break;
                case 5 :    x=v6;  y=TY+2;   break;
                case 6 :    x=v7;  y=TY+3;   break;
                case 7 :    x=v8;  y=TY+3;   break;
            }
            gotoxy(x,y);
            putchar('v');
        }

        // bouger droite à gauche
        v1+=d1;
        if (v1<gauche) v1=droite;
        v2+=d2;
        if (v2<gauche) v2=droite;
        v3+=d3;
        if (v3<gauche) v3=droite;
        v4+=d4;
        if (v4<gauche) v4=droite;
        // bouger gauche à droite
        v5+=d5;
        if (v5>droite) v5=gauche;
        v6+=d6;
        if (v6>droite) v6=gauche;
        v7+=d7;
        if (v7>droite) v7=gauche;
        v8+=d8;
        if (v8>droite) v8=gauche;

        // afficher
        textcolor(10);
        for (i=0; i<8; i++){
            switch(i){
                case 0 :    x=v1;  y=TY;     break;
                case 1 :    x=v2;  y=TY;     break;
                case 2 :    x=v3;  y=TY+1;   break;
                case 3 :    x=v4;  y=TY+1;   break;
                case 4 :    x=v5;  y=TY+2;   break;
                case 5 :    x=v6;  y=TY+2;   break;
                case 6 :    x=v7;  y=TY+3;   break;
                case 7 :    x=v8;  y=TY+3;   break;
            }
            gotoxy(x,y);
            putchar('v');
        }

        // collisions
        for (i=0; i<8; i++){
            switch(i){
                case 0 :    x=v1;  y=TY;     break;
                case 1 :    x=v2;  y=TY;     break;
                case 2 :    x=v3;  y=TY+1;   break;
                case 3 :    x=v4;  y=TY+1;   break;
                case 4 :    x=v5;  y=TY+2;   break;
                case 5 :    x=v6;  y=TY+2;   break;
                case 6 :    x=v7;  y=TY+3;   break;
                case 7 :    x=v8;  y=TY+3;   break;
            }
            if(px==x && py==y){ // collision
                textcolor(12);
                gotoxy(gauche+(TX/2)-3, 0);
                printf("PERDU !");

                tmps=clock();
                while(clock()<tmps+50){
                    gotoxy(gauche+rand()%TX,1+rand()%(TY+7));
                    putchar('P');
                }
            }
        }
        // ralenti
        tmps=clock();
        while (clock()<tmps+100){}
    }


    gotoxy(0,TY+8);
	return 0;
}
// définition des fonctions
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
*/
