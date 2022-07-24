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
*   Chapitre 1 : Variables simples                                  *
*   3. Les opérations                                               *
*   3.7 Mise en pratique : opérations bits à bits                   *
*********************************************************************
/*
Exercice 1
Qu'imprime le programme suivant ?
donner les réponses et faite tourner le programme pour les vérifier
*/
#include <stdio.h>
int main()
{
	int x,y,z;

	x = 3;
	y = 2;
	z = 1;
	printf("%d\n", x | y & z);      // 3
	printf("%d\n", x | y & ~z);     // 3
	printf("%d\n", x ^ y & ~z);     // 1
	printf("%d\n", x & y & z);      // 0

    printf("---------------\n");
	x = 1;
	printf("%d\n", ~x | x);     // -1
	printf("%d\n", x & ~x);     // 0
	printf("%d\n", x ^ x);      // 0

    printf("---------------\n");

	x <<= 3;
	printf("%d\n",x); // 8

	y = -1; // attention le nombre binaire est le complément à deux de 1 : 111...1
	y <<= 3;
	printf("%d\n",y); // -8    111...1000
	y >>= 3;
	printf("%d\n",y);   // -1 mais attention, le signe peut être perdu.
                        //C ne garantit pas qu'il soit conservé àprès un décalage

	return 0;
}


