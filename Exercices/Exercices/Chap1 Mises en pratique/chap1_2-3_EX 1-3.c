/*
*   Pour tester la solution d'un exercice il faut :
*   - faire un projet c en mode console
*   - copier le code correspondant dans le fichier c
*   - compiler et exécuter
*
*   ou
*   - copier tout dans le fichier c du projet
*   - enlever les commentaires du code de l'exercice à tester
*   - mettre en commentaire tous les autres
*   - compiler et exécuter
*/

/********************************************************************
*   Chapitre 1 : Variables simples                                  *
*   2. Variables simples                                            *
*   2.3 Mise en pratique : avoir des variables dans un programme    *
*********************************************************************


/***********************************
Exercice 1
Combien y a t-il de type en C et quels sont-ils ?

6 types de variables simples :
char, short, int, long, float, double

(auxquels s'ajoutent également les variables ensembles
structures, tableaux, et les pointeurs)


Qu'est ce qui les différencie ?
Les types de variables simples se différencient par la taille en mémoire
et la virgule qui est présente ou pas.


Par défaut sont-ils signés ou non signés ?
Ils sont signés


Quelles sont les fourchettes de valeurs ?

Se reporter au tableau page ...

*/

/***********************************
Exercice 2
Quels sont les  types à choisir pour coder les nombres
45.876,  56.0,     77,    650987,    32769,  - 32765,   450009996   ?

45.876 et 56.0 :
float ou double (virgule)

77 :
un char suffit

650987 :
il faut 20 bits pour le codage en binaire, soit au moin 3 octets,
alors un int (en 4 octets) ou un long

32769 :
il faut 16 bits pour le codage binaire alors soit un unsigned short, soit un int (4 octets), soit un long.

- 32765
15 bits plus le bit de signe, 2 octets, alors un short ou un int

450009996 :
29 bits, 4 octets soit un int soit un long


Écrivez un programme dans lequel vous avez des variables susceptibles de recevoir ces valeurs.

*
#include <stdio.h>
#include <stdlib.h>
int main()
{
float f = 45.876;
double d = 56.0;
char c = 77;
int i = 650987;
unsigned short is = 32769;
short s = - 32765;
long l = 450009996;

    printf("%f\n",f);
    printf("%lf\n",d);
    printf("%d\n",c);
    printf("%d\n",i);
    printf("%d\n",is);
    printf("%d\n",s);
    printf("%ld\n",l);
    return 0;
}

/***********************************
Exercice 3
Soit dans un programme les déclarations suivantes :
	int 0t, ti, p0;
	freste float;
	double div-total;
	float tata, t2345, char c, cc :
	short Err_, _E_,
Indiquez, expliquez et corrigez les erreurs (vous pouvez utiliser le compilateur).


*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int 0t, ti, p0; // err 0t identificateur qui commence par un chiffre
freste float;   // err le type est avant l'identificateur dans une déclaration de variable
double div-total; // err le signe - ne peut pas être util;isé dans un nom de variable
float tata, t2345, char c, cc : // err ; obligatoire pour clore les déclaration de float avant char c
short Err_, _E_, // err ; après la variable _E_ pour clore sa déclaration

    return 0;
}
/*********************************
*/











