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
*   5. Boucles                          *
*   5.6 Mise en pratique : les boucles while, do-while et for         *
*********************************************************************

/*********************************
Exercice 1
Faire un programme qui affiche pour chaque valeur de la table ascii
(de 0 à 255) le signe ou la lettre correspondant.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int i;
    for (i=0; i<256; i++)
        printf("asccii %3d - lettre %c\n",i,i);

	return 0;
}
/*********************************
Exercice 2
Faire un programme qui permet de :
Afficher tous les nombres de 0 à 1000
Afficher tous les nombres de 0 à 100 sur 10 colonnes
Afficher la table de multiplication
Afficher la table d'addition
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int i,j,cmp;
    printf("affiche nombres de 0 à 1000 :\n");
    for (i=0; i<=1000; i++)
        printf("%5d",i);
    putchar('\n');

    printf("affiche nombres de 0 à 100 sur 10 colonnes :\n");
    for(i=0,cmp=0; i<10;i++){
        for (j=0; j<10; j++,cmp++)
            printf("%4d",cmp);
        putchar('\n');
    }

    printf("affiche table de multiplication :\n");
    for(i=0; i<=10;i++){
        for (j=0; j<=10; j++)
            printf("%4d",i*j);
        putchar('\n');
    }

    printf("affiche table addition :\n");
    for(i=0; i<=10;i++){
        for (j=0; j<=10; j++)
            printf("%4d",i+j);
        putchar('\n');
    }

	return 0;
}
/*********************************
Exercice 3
Ecrire le code qui permet d'obtenir : AAAAAAABBBBBZZZZZZZZTTT
avec uniquement quatre appels de la fonction putchar()
Ecrire le code qui permet d'avoir 10 fois la séquence de code ci-dessus.
Combien de boucles faut-il utiliser pour obtenir l'affichage ci-dessous ?
00000100000
00001110000
00011111000
00111111100
01111111110
11111111111
Ecrire la séquence de code correspondante.
Tester le tout dans un programme.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int i,n,n1,n2,nbl;

    //obtenir : AAAAAAABBBBBZZZZZZZZTTT
    for( i=0; i<7; i++)
        putchar('A');
    for( i=0; i<5; i++)
        putchar('B');
    for( i=0; i<8; i++)
        putchar('Z');
    for( i=0; i<3; i++)
        putchar('T');
    putchar('\n');
    printf("------------------------------\n");

    //10 fois la séquence de code ci-dessus
    for (n=0; n<10; n++){
        for( i=0; i<7; i++)
            putchar('A');
        for( i=0; i<5; i++)
            putchar('B');
        for( i=0; i<8; i++)
            putchar('Z');
        for( i=0; i<3; i++)
            putchar('T');
        putchar('\n');
     }
     printf("------------------------------\n");

    // Combien de boucles faut-il utiliser pour obtenir l'affichage ci-dessous ?
    //00000100000
    //00001110000
    //00011111000
    //00111111100
    //01111111110
    //11111111111

    // reponse 1 : 16 boucles, trois par ligne, 1 seule pour la dernière
    // reponse 2 : 4 boucles, une pour les lignes + trois pour chaque ligne

    //séquence de code correspondante.
    //reponse 1 :
    // ligne 1 :
    for (i=0; i<5; i++)
        putchar('0');
    for (i=0; i<1; i++)
        putchar('1');
    for (i=0; i<5; i++)
        putchar('0');
    putchar('\n');
    // ligne 2 :
    for (i=0; i<4; i++)
        putchar('0');
    for (i=0; i<3; i++)
        putchar('1');
    for (i=0; i<4; i++)
        putchar('0');
    putchar('\n');
    // ligne 3 :
    for (i=0; i<3; i++)
        putchar('0');
    for (i=0; i<5; i++)
        putchar('1');
    for (i=0; i<3; i++)
        putchar('0');
    putchar('\n');
    // ligne 4 :
    for (i=0; i<2; i++)
        putchar('0');
    for (i=0; i<7; i++)
        putchar('1');
    for (i=0; i<2; i++)
        putchar('0');
    putchar('\n');
    // ligne 5 :
    for (i=0; i<1; i++)
        putchar('0');
    for (i=0; i<9; i++)
        putchar('1');
    for (i=0; i<1; i++)
        putchar('0');
    putchar('\n');
    // ligne 6 :
    for (i=0; i<11; i++)
        putchar('1');
    putchar('\n');
    printf("---------------------------\n");

    // réponse 2 :
    n1=5;
    n2=1;
    for (nbl=0; nbl<6; nbl++){
        for (i=0; i<n1; i++)
            putchar('0');
        for (i=0; i<n2; i++)
            putchar('1');
        for (i=0; i<n1; i++)
            putchar('0');
        putchar('\n');
        n1--;
        n2+=2;
    }

	return 0;
}
/*********************************
Exercice 4
Est-il possible avec scanf() de faire un programme qui affiche
des zéros en continue et, si une touche est appuyée, un nombre
aléatoire de fois la lettre ou le chiffre correspondant ?
Faire ce qui est possible.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
char l;
int nb;
    // réponse scanf() bloque le programme et attend une entrée utilisateur
    // il n'est dons pas possible d'afficher des 0 en continue
    // en revanche il est possible de récupéer la lettre à afficher un nombre
    // aléatoire de fois
    srand(time(NULL));
    printf("entrer une lettre :");
    scanf("%c",&l);
    nb=rand()%1000; // max 1000 répétitions
    printf("%d repetitions :\n",nb);
    while (nb--)
        putchar(l);

	return 0;
}
/*********************************
Exercice 5
Qu'imprime le code suivant :

int i;
	for (i=0; i<B ; i++)
	   printf("%d", B);

	putchar('\n');

	i--;
	while (i++ < B)
	   printf("A");

	do{
		printf("C");
	}while (i < B);

pour B=5, B= 1, B=0 ?

REPONSE :
    avec B=5, imprime :
    55555
    AC

    avec B=1, imprime :
    1
    AC

    avec B=0, imprime :

    AC
/*********************************
Exercice 6
Soit un segment horizontal [10, 100], faire un programme qui:
affiche toutes les postions par pas de un
affiche toutes les positions par pas de deux
affiche toutes les positions par un pas entré par l'utilisateur
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int i,pas;
    // seg [10, 100] pas de 1
    for (i=10; i<=100;i++)
        printf("%d-",i);
    putchar('\n');
    printf("--------------------\n");

    // seg [10, 100] pas de 2
    for (i=10; i<=100;i+=2)
        printf("%d-",i);
    putchar('\n');
    printf("--------------------\n");

    // seg [10, 100] pas entre par utilisateur
    printf("entrer un pas :");
    scanf("%d",&pas);
    for (i=10; i<=100;i+=pas)
        printf("%d-",i);
    putchar('\n');
    printf("--------------------\n");

	return 0;
}
/*********************************
Exercice 7
Soit un rectangle de position (10,20) coin haut gauche et
(115,80) coin bas droite. Afficher toutes les positions du
rectangle en en les numérotant à partir de 0 et en augmentant
de 1 pour chaque position (afficher avec la fonction printf(),
le rectangle  est collé à la marge de la console)
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int x,y,cmpt;

    for(y=20,cmpt=0; y<80; y++){
        for(x=10; x<115; x++,cmpt++)
            printf("%d|",cmpt);
        putchar('\n');
    }
    printf("----------------------\n");
    // remarque : la taille exède la taille par défault de la
    // fenêtre console, l'exemple ci-dessous permet de mieux voir
    // un rectangle de 10 lignes sur 15 colonnes
    for(y=10,cmpt=0; y<20; y++){
        for(x=20; x<35; x++,cmpt++)
            printf("%4d",cmpt);
        putchar('\n');
    }

	return 0;
}
/*********************************
Exercice 8
Dans un programme :
afficher un nombre aléatoire de fois le mot "bonjour"
afficher "je repete le bloc" tant que l'utilisateur le
demande(s'arrête quand l'utilisateur ne veut plus)
obliger l'utilisateur à entrer un nombre pair entre 100 et 1000.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int nb;
int play='o';

    srand(time(NULL));
    nb=rand()%50; // aléatoire de 0 à 49
    printf("affiche %d bonjour :\n",nb);
    while(nb--)
        printf("bonjour\n");
    printf("---------------------------\n");

    while(play=='o') {
        printf("je repete le bloc\n");

        printf("continuer ? (o/n)\n");
        scanf("%c",&play);
        rewind(stdin);
    }
    printf("---------------------------\n");

    do{
        printf("enter un nombre pair :");
        scanf("%d",&nb);
        rewind(stdin);
    }while(nb%2);

	return 0;
}
/*********************************
Exercice 9
Simulation d'une course d'escargots.
Au départ 4 à 5 escargots sur le bord gauche de la console.
L'arrivée est à une distance de 60 caractères vers la droite
(possibilité de la dessiner avec des 'I'). A l'issue de la course
le programme affiche quel est le vainqueur.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int e1=0,e2=0,e3=0,e4=0;
int fin=0,i;

    srand(time(NULL));
    while(!fin){
        switch(rand()%4){
            case 0 : e1++; break;
            case 1 : e2++; break;
            case 2 : e3++; break;
            case 3 : e4++; break;
        }
        //escargot 1
        for (i=0; i<=e1; i++) // avance de l'escargot avec bave de 1
            putchar('1');
        while(i++<60)        // pour tracer ligne arrivée
            putchar(' ');
        printf("|\n");

        // escargot 2
        for (i=0; i<=e2; i++)
            putchar('2');
        while(i++<60)
            putchar(' ');
        printf("|\n");

        // escargot 3
        for (i=0; i<=e3; i++)
            putchar('3');
        while(i++<60)
            putchar(' ');
        printf("|\n");

        // escargot 4
        for (i=0; i<=e4; i++)
            putchar('4');
        while(i++<60)
            putchar(' ');
        printf("|\n");

        printf("------------------------------------------------------------\n");

        if (e1>=60){        // fin si gagnant
            printf("e1 gagne !\n");
            break;
        }
        if (e2>=60){
            printf("e2 gagne !\n");
            break;
        }
        if (e3>=60){
            printf("e3 gagne !\n");
            break;
        }
        if (e4>=60){
            printf("e4 gagne !\n");
            break;
        }
    }
	return 0;
}
/*********************************
Exercice 10
Tirage aux dés. Écrivez un programme qui simule un nombre n, entré par
l'utilisateur, de  tirages avec 6 dés. Le programme compte et affiche à
la fin le nombre de coups où tous les dés ont eu la même valeur.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int nb,cmpt=0;
int d1,d2,d3,d4,d5,d6;

    srand(time(NULL));
    printf("entrer le nombre de tirages :");
    scanf("%d",&nb);
    while (nb--){
        d1=1+rand()%6;
        d2=1+rand()%6;
        d3=1+rand()%6;
        d4=1+rand()%6;
        d5=1+rand()%6;
        d6=1+rand()%6;
        if(d1==d2 && d2==d3&&d3==d4&&d4==d5&&d5==d6){
            printf("%d-%d-%d-%d-%d-%d\n",d1,d2,d3,d4,d5,d6);
            cmpt++;
        }
    }
    printf("%d tirages meme valeur\n",cmpt);
	return 0;
}
/*********************************
Exercice 11
Dichotomie. Écrire un programme qui génère aléatoirement un nombre que
l’utilisateur devra découvrir. A chaque saisie, le programme dira si le
nombre est plus petit ou plus grand. Si le nombre est trouvé par l’utilisateur,
le programme lui annoncera qu’il a gagné en indiquant le nombre d’essais qui
ont été nécessaires.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int nombre,test,cmpt=0;

    srand(time(NULL));
    nombre = rand()%20;
    while(nombre!=test){
        printf("entrer un nombre :" );
        scanf("%d",&test);
        rewind(stdin); // en cas d'erreur d'entree
        cmpt++;
        if(test<nombre)
            printf("trop petit\n");
        if(test>nombre)
            printf("trop grand\n");
    }
    printf("trouve en %d coups\n",cmpt);
	return 0;
}
/*********************************
Exercice 12
Fabriquer un dé pipé. Par exemple la face 6 sort plus souvent. Tester votre dés
pipé afin de mettre en évidence son efficacité. Sophistiquer le dé en privilégiant
3 faces, par exemple 1, 3, 6, tester pour voir si ça marche.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int d1,i,cmpt6=0,cmpt1=0, cmpt3=0;
    srand(time(NULL));
    printf ("Pour 100 tirages 100 du de : \n");
    for(i=0; i<100;i++){
        d1=1+rand()%8;
        if(d1>=6){
            d1=6;
            cmpt6++;
        }
    }
    printf("6 sort %d fois\n",cmpt6 );
    printf("---------------------------------\n");

    cmpt6=cmpt3=cmpt1=0;
    printf ("Pour 100 tirages du de : \n");
    for(i=0; i<100;i++){
        d1=rand()%100;
        if(d1>65){
            d1=6;
            cmpt6++;
        }
        else if (d1>40){
            d1=3;
            cmpt3++;
        }
        else if (d1>25){
            d1=1;
            cmpt1++;
        }
        else
            d1=1+rand()%6;

    }
    printf("6 sort %d fois\n",cmpt6 );
    printf("3 sort %d fois\n",cmpt3 );
    printf("1 sort %d fois\n",cmpt1 );

	return 0;
}
/*********************************
Exercice 13
Faire un programme où c'est l'ordinateur qui pipe un dé à six faces. Une valeur
revient plus souvent et vous ne savez pas laquelle. A l'issue de plusieurs tirages
vous gagnez si vous découvrez quelle est la face pipée. Éventuellement vous pouvez
vous aidez avec un compte des faces sorties. Faire le même programme avec cette fois
trois faces pipées.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int f1,f2,f3;  // faces 1, 2, 3
int v1,v2,v3;   // valeurs entrées par utilisateur
int c1,c2,c3,c4,c5,c6; // compte par face sortie
int de,i;   // le de

    srand(time(NULL));

    // une face pipée par l'ordinateur
    f1=1+rand()%6;
    while(v1!=f1){
        printf ("Pour 100 tirages du de : \n");
        for(i=0; i<100;i++){
            de=1+rand()%10;
            if(de>6){
                de=f1;
            }
            printf("%d\n",de);
        }
        printf("quel face est pipee ? ");
        scanf("%d",&v1);
        rewind(stdin);
    }
    printf("---------------------------------\n");

    // trois faces pipées par l'ordinateur
    f3=f2=f1=1+rand()%6;
    while(f2==f1)
        f2=rand()%6;
    while(f3==f2 || f3==f1)
        f3=1+rand()%6;

    //
    i=0;
    while(i<3){
        printf ("Pour 100 tirages du de : \n");
        c1=c2=c3=c4=c5=c6=0;

        for(i=0; i<100;i++){

            de=1+rand()%100;
            if(de>65)
                de=f1;
            else if(de>35)
                de=f2;
            else if (de>15)
                de=f3;
            else
                de=1+rand()%6;

            switch(de){
                case 1 : c1++; break;
                case 2 : c2++; break;
                case 3 : c3++; break;
                case 4 : c4++; break;
                case 5 : c5++; break;
                case 6 : c6++; break;
            }
        }
        printf("resultat tirages :\n");
        printf("1 : %d\n2 : %d\n3 : %d\n4 : %d\n5 : %d\n6 : %d\n",c1,c2,c3,c4,c5,c6);
        printf("quelles sont les faces pipees ? ");
        scanf("%d%d%d",&v1,&v2,&v3);
        rewind(stdin);

        i=0;
        if(v1==f1 ||v1==f2||v1==f3){
            printf("face %d trouvee\n",v1);
            i++;
        }
        if(v2==f1 ||v2==f2||v2==f3){
            printf("face %d trouvee\n",v2);
            i++;
        }
        if(v3==f1 ||v3==f2||v3==f3){
            printf("face %d trouvee\n",v3);
            i++;
        }
    }
	return 0;
}
/*********************************
Exercice 14
Faire un générateur de 100 mots imaginaires prononçables en français et produit
par la machine, par exemple : tariduse, ujinoq, elepit, popelepe… Les mots seront
affichés à l'écran les uns en dessous des autres.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
// pour un mot :
// - début voyelle ou consonne
// - nombre de lettres
// - alternance voyelle-consonne
// - affichage lettre par lettre
int alterne,nbl,l,i,j;

    srand(time(NULL));
    for (i=0; i<100;i++){  // 100 mots
        alterne=rand()%2; // 0 voyelle, 1 consonne
        nbl=2+rand()%10;   // mot entre 2 et 12 caractères
        for (j=0; j<nbl; j++){
            l='a'+rand()%26;
            if(alterne==0){ // si chercher une voyelle
                while(l!='a'&&l!='e'&&l!='i'&&l!='o'&&l!='u'&&l!='y'){
                    l++;
                    if(l >'z')
                        l='a';
                }
            }
            else if (alterne==1){ // si chercher une consonne
                while(l=='a'||l=='e'||l=='i'||l=='o'||l=='u'||l=='y'){
                    l++;
                    if(l >'z')
                        l='a';
                }

            }
            putchar(l);
            alterne=1-alterne; // alterne 0 et 1
        }
        putchar('\n');
    }

	return 0;
}
/*********************************
Exercice 15
Ecrire un programme qui convertit un entier naturel en chiffres romains,
en utilisant l’ancienne notation.
Exemple : 4 ( IIII), 9 ( VIIII), 900 ( DCCCC)

Rappelons les éléments de base :
I : 1, V :5, X : 10, L : 50, C : 100, D : 500, M : 1000.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int nb;
    printf("entrer un entier :");
    scanf("%d",&nb);
    rewind(stdin);

    printf("affichage romain :\n");
    while(nb>=1000){
        putchar('M');
        nb-=1000;
    }
    while(nb>=500){
        putchar('D');
        nb-=500;
    }
    while(nb>=100){
        putchar('C');
        nb-=100;
    }
    while(nb>=50){
        putchar('L');
        nb-=50;
    }
    while(nb>=10){
        putchar('X');
        nb-=10;
    }
    while(nb>=5){
        putchar('V');
        nb-=5;
    }
    while(nb>0){
        putchar('I');
        nb-=1;
    }
    putchar('\n');
	return 0;
}
/*********************************
Exercice 16
Inventer un système de comptage inspiré de celui des romains et faites un programme
qui convertit des entiers naturels entrés par l'utilisateur.
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
// dans le fond c'est aussi une sorte de cryptage.
// notre suysteme propose :
// 768 : A, 383 : b, 200 : C, 53 : D, 21 : E, 7 : F, 2 : O
// ensuite reprendre l'algorithme de l'exercice précédent :
int nb;
    printf("entrer un entier :");
    scanf("%d",&nb);
    rewind(stdin);

    printf("affichage crypte :\n");
    while(nb>=768){
        putchar('A');
        nb-=768;
    }
    while(nb>=383){
        putchar('B');
        nb-=383;
    }
    while(nb>=200){
        putchar('C');
        nb-=200;
    }
    while(nb>=53){
        putchar('D');
        nb-=53;
    }
    while(nb>=21){
        putchar('E');
        nb-=21;
    }
    while(nb>=7){
        putchar('F');
        nb-=7;
    }
    while(nb>=2){
        putchar('O');
        nb-=2;
    }
    if(nb==1)
        putchar('1');

    putchar('\n');
	return 0;
}
/*********************************
Exercice 17
Écrire un programme C qui propose à l’utilisateur de dessiner à l’écran certaines figures
composées d’étoiles triangle, carré, sablier, des lettres…

Les figures seront proposées par un menu (triangle, carré, sablier…). La hauteur de la
figure sera saisie par l’utilisateur.  Exemple :

hauteur=4
   *
  ***
 *****
*******

****
****
****
****

*******
 *****
  ***
   *
   *
  ***
 *****
*******
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int i,j,choix,hauteur,nbetoile, nbespace, nbligne;

    printf("1 : carre\n"
           "2 : triangle\n"
           "3 : sablier\n");
    scanf("%d",&choix);
    rewind(stdin);

    printf("entrer la taille :");
    scanf("%d",&hauteur);
    rewind(stdin);

    switch(choix){
        case 1 : // carre
            for(i=0; i<hauteur; i++){
                for(j=0; j<hauteur; j++)
                    putchar('*');
                putchar('\n');
            }
            break;

        case 2 : // triangle
            nbetoile=1;
            nbespace=hauteur-1;
            for(nbligne=0; nbligne<hauteur; nbligne++){
                for (i=0; i<nbespace; i++)
                    putchar(' ');
                for (i=0; i<nbetoile; i++)
                    putchar('*');
                putchar('\n');
                nbetoile+=2;
                nbespace--;
            }
            break;

        case 3 : // sablier
            nbetoile=hauteur*2-1;
            nbespace=0;
            for(nbligne=0; nbligne<hauteur; nbligne++){
                for (i=0; i<nbespace; i++)
                    putchar(' ');
                for (i=0; i<nbetoile; i++)
                    putchar('*');
                putchar('\n');
                nbetoile-=2;
                nbespace++;
            }
            nbetoile=1;
            nbespace=hauteur-1;
            for(nbligne=0; nbligne<hauteur; nbligne++){
                for (i=0; i<nbespace; i++)
                    putchar(' ');
                for (i=0; i<nbetoile; i++)
                    putchar('*');
                putchar('\n');
                nbetoile+=2;
                nbespace--;
            }
            break;
    }
	return 0;
}
/*********************************
*/



