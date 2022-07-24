/*
*   Pour tester la solution d'un exercice il faut :
*   - faire un projet c en mode console
*   - copier le code correspondant dans le fichier c
*   - compiler et exécuter
*
*   ou
*   - copier tous dans le fichier c du projet
*   - enlever le commentaires de l'exercice à tester
*   - mettre en commentaire tous les autres
*   - compiler et exécuter
*/
/********************************************************************
*   Chapitre 2 : Contrôles des blocs d'instruction                  *
*   1. Blocs d'instructions et conditions                           *
*   1.3 Mise en pratique : opérateurs de comparaison et NON         *
*********************************************************************
/*********************************
Exercice 1
Faire un programme qui affiche les résultats de ce qui suit :

int a, b, c;
	srand(5);
 	Imprimez les résultats de :
	a=rand()%256;
	b=rand()%256;
	c=rand()%256;

	a<128
	b>128
	c==223
	a < b >= rand()%2 == 1
	a= b !=c +rand()%50;
	b= a==c
	c= rand()%10 < rand()%10 >= rand()%10 != rand()%10 ==rand()%10
*
#include <stdlib.h>
#include <stdio.h>

int main()
{
int a, b, c;

	srand(5);

	a=rand()%256;
	b=rand()%256;
	c=rand()%256;

	printf("a=%d, b=%d, c=%d\n", a,b,c);

	printf("a<128 : %d\n",a<128);
	printf("b>128 : %d\n",b>128);
	printf("c==223 : %d\n",c==223);


	printf("res : %d\n",a < b >= rand()%2 == 1);
    printf("a : %d\n",a = b !=c +rand()%50);
    printf("b : %d\n",b = a==c);
	printf("c : %d\n",c = rand()%10 < rand()%10 >= rand()%10 != rand()%10 == rand()%10);

	return 0;
}


/*********************************
Exercice 2
Qu'imprime le programme suivant ?

int main()
{
int a=10, b=0, c=2;
	printf("a+b < c*10 vaut %d\n", a+b < c*10);
	printf("c*10 >= 15 vaut %d\n", c*10 >= 15);
	printf("a+b < c*10 >= 15 == 1 vaut %d\n",a+b < c*10 >= 15 == 1);
	printf("a+b < c*10 <= 15 == 1 vaut %d\n",a+b < c*10 <= 15 == 1);
	return 0;
}
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
    int a=10, b=0, c=2;
	printf("a+b < c*10 vaut %d\n", a+b < c*10);     // 1
	printf("c*10 >= 15 vaut %d\n", c*10 >= 15);     // 1
	printf("a+b < c*10 >= 15 == 1 vaut %d\n",a+b < c*10 >= 15 == 1);    // 0
	printf("a+b < c*10 <= 15 == 1 vaut %d\n",a+b < c*10 <= 15 == 1);    // 1
	return 0;

}
/*********************************
*/


