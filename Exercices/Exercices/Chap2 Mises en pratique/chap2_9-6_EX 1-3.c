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
*   9. Style, commentaires et indentation                        *
*   9.6 Mise en pratique : Style, indentation, commentaires         *
*********************************************************************

/*********************************
Exercice 1
Que fait le programme suivant ?
int main(int argc, char *argv[])
{int choix,res;printf ( " 1 : Affiche bonjour \n"" 2 : Affiche il fait beau
\n"" 3 : Entrer un nombre entier\n"" 0 : Quitter \n")
;do{scanf("%d",&choix);rewind(stdin);switch(choix){case
0:break;case 1:printf(" bonjour\n ");break;case 2:printf
("il fait beau\n ") ;break;case 3 :printf("Entrer un nombre
:\n");scanf("%d",&res);printf ("le nombre est :  %d",res);break ;
default:printf("Pas de commande%d\n",choix);break;}}while(choix !=0);return 0;}

Il n'y a pas d'erreur de syntaxe.
A part quelques allers à la ligne le programme fonctionne.
Refaites entièrement la mise en page de ce code, ensuite expliquez
ce qu'il fait sur une feuille à part et pour finir testez votre code
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int choix,res;
    printf (" 1 : Affiche bonjour \n"
            " 2 : Affiche il fait beau\n"
            " 3 : Entrer un nombre entier\n"
            " 0 : Quitter \n");
            do{
                scanf("%d",&choix);
                rewind(stdin);
                switch(choix){
                    case 0:
                        break;
                    case 1:
                        printf(" bonjour\n ");
                        break;
                    case 2:
                        printf("il fait beau\n ") ;
                        break;
                    case 3 :
                        printf("Entrer un nombre :\n");
                        scanf("%d",&res);
                        printf ("le nombre est :  %d",res);
                        break ;
                    default:
                        printf("Pas de commande%d\n",choix);
                        break;}
            }while(choix !=0);
            return 0;
}
/*********************************
Exercice 2
Que fait le programme suivant ?
int main(int argc, char *argv[]){int res ;printf("presser des touches :
(q pour quitter) \n");while ( res!='q'){if (kbhit()){res=getch() ;
printf(" touche %c pressee, val ascii : %d\n",res,res) ;}printf
("la boucle tourne\n");}return 0;}

Refaites la mise en page de ce code. Expliquez ce qu'il fait. Testez.
*
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>qqq
int main(int argc, char *argv[])
{int res ;
    printf("presser des touches : (q pour quitter) \n");
    while ( res!='q'){
        if (kbhit()){
            res=getch() ;
            printf(" touche %c pressee, val ascii : %d\n",res,res) ;
        }
        printf("la boucle tourne\n");
    }return 0;
}
/*********************************
Exercice 3
Que fait le programme suivant ?
#include <stdio.h>#include <stdlib.h>#include <time.h>#include <conio.c>
int main(int argc, char *argv[]){const int arborigene=20;const int chateau=10;
int pourquoi=0,martial,pomme,level;srand(time(NULL));pomme=1+rand()%arborigene;
level=1+rand()%chateau; gotoxy(pomme,level); putchar('o');while(!pourquoi)
{if(kbhit()){gotoxy(pomme,level);putchar(' ');martial=getch();switch(martial){case 72:level--;break;case 77: pomme++;	break;case 80:level++;break;case75:pomme--;break;default:pourquoi=1; break ;	}if (pomme<1)pomme=arborigene-1;if (pomme>arborigene-1)pomme=1;
if(level<1)level=chateau-1;if(level>chateau-1)level=1;gotoxy(pomme,level)
 ;putchar('o');}}return 0;}
Refaites la mise en page de ce code. Expliquez ce qu'il fait, renommez
les variables en conséquence. Testez et trouvez l'erreur.
*

// le programme final :

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // pour gotoxy et textcolor
#include <time.h>
#include <conio.h>  // getch() et kbhit()

// déclaration de deux fonctions incontournables dans ce contexte
void gotoxy(int x, int y);  // déplacer le curseur en écriture
void textcolor(int color);  // donner une couleur pour la lettre et son fond

int main(int argc, char *argv[])
{
const int TX=20;
const int TY=10;
int fin=0,touche,x,y;

    srand(time(NULL));
    x=1+rand()%TX;
    y=1+rand()%TY;
    gotoxy(x,y);
    putchar('o');

    while(!fin){
        if(kbhit()){
            gotoxy(x,y);
            putchar(' ');
            touche=getch();
            switch(touche){
                case 72: y--;   break;
                case 77: x++;	break;
                case 80: y++;   break;
                case 75: x--;   break;
                case 224 :      break;
                default: fin=1; break ;
            }
            if (x<1)
                x=TX-1;
            if (x>TX-1)
                x=1;
            if(y<1)
                y=TY-1;
            if(y>TY-1)
                y=1;
            gotoxy(x,y) ;
            putchar('o');
        }
    }
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


