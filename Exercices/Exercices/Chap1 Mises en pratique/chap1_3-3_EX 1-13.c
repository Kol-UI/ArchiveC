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
*   3.3 Mise en pratique : opérations arithmétiques, cast           *
*********************************************************************




/***************************
Exercice 1
Soient les déclarations :

char c ='\x01' ; // '\xhh' pour un nombre hexadécimal
                // (0...9, a...f ou A...F)sur un octet max
short p=10;

Quels sont le type et la valeur de chacune des expressions suivantes :
p + 3                   type short, valeur 13
c + 1                   type char valeur 2
p + c                   type short valeur 12
3 * p + 5 * c           type short valeur 35
6.8 /7 + 'a' * 560      type float valeur 54320.971429
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("%f\n", 6.8 /7 + 'a' * 560);
    return 0;
}


/****************************
Exercice 2
Soient les déclarations :
char c='\x05';
int n=5;
long p=1000;
float x=1.25;
double z=5.5;
Quels sont les types et les valeurs des expressions suivantes :

n + c + p               type long
2 * x + c               type float
(char) n + c            type char
(float) z + n / 2       type float
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
char c='\x05';
int n=5;
long p=1000;
float x=1.25;
double z=5.5;
    printf("%ld\n", n + c + p);          // 1010
    printf("%f\n", 2 * x + c);          //  7.5
    printf("%d\n", (char) n + c);       //  10
    printf("%f\n", (float) z + n / 2);  //  7.5

    return 0;
}

/****************************
Exercice 3
Écrire un programme qui saisit un nombre entier, affiche son opposé et sa moitié exacte.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int nb;
    printf("entrer un nombre :\n");
    scanf("%d",&nb);

    printf("oppose : %d\n",-nb);
    printf("moitie exacte : %f\n", nb/2.0);

    return 0;
}


/****************************
Exercice 4
Faire un convertisseur francs/euros... (un euro = 6,55957 francs)
quelles sont les étapes du programme ?

    - entrer le montant
    - conversion
    - afficher le résultat

programmez
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
float nb;
    printf("entrer un montant en francs :\n");
    scanf("%f",&nb);

    // conversion (la conversion est sauvegardée)
    nb = nb/6.55957;

    printf("resultat en euro : %f\n",nb);

    return 0;
}


/****************************
Exercice 5
Pour convertir des degrés Fahrenheit en degrés Celsius, on a la formule suivante :
C= 5/9 * (F-32)
Pour convertir des degrés Celsius en degrés Fahrenheit on a :
F= ( (9*C ) / 5)+32
où F est une température en degrés Farenheit et C la température correspondante en degrés Celsius
Faire un programme qui convertit en degré Celsius une température entrée au clavier exprimée en degré Farenheit.
Même question avec une température exprimée en degré Celsius à convertir en degré Farenheit.
*

#include <stdio.h>
#include <stdlib.h>
int main()
{
int C, F;

    printf("entrer une temperature en farenheit \n");
    scanf("%d",&F);
    C = 5/9.0 * (F-32);
    printf("conversion en celsius : %d\n",C);

    printf("entrer une temperature en Celsius \n");
    scanf("%d",&C);
    F = ( (9*C ) / 5.0) + 32;
    printf("conversion en Farenheit : %d\n",F);

    return 0;
}


/****************************
Exercice 6
Ecrire un programme pour tester tous les cas de figure de la division en C afin
d'illustrer le problème des cast :
division d'un int par un int, rangé dans un int et affiché en %d
division d'un int par un int, rangé dans un float et affiché en %f
division d'un int par un float et rangé dans un float et affiché en %d et %f

Dans quel cas un cast est-il nécessaire ? tester avec cast.
Attention distinguez bien entre d'une part la division et son résultat et d'autre part
l'affichage du résultat selon tel ou tel format. Ce sont deux problèmes différents.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int a=10,b=20,ires;
float f=1.5,fres;

    ires = a/b;
    printf("%d\n", ires);

    fres = a/b;
    printf("%f\n",fres);

    fres = a/f;
    printf("%f - %d\n",fres,fres);
    // remarque : l'affichage du float en %d produit une erreur à l'exécution

    printf("-------------------------\n");

    // cast ?
    // le cast est inutile pour la première opération puisque de toute façon
    // le résultat de l'opération est stocké en int
    ires = a/(float)b;
    printf("%d\n", ires);

    // pour la seconde opération un cast est nécessaire pour avoir le résultat en float
    fres = a/(float)b;
    printf("%f\n",fres);

    // pour la troisième opération pas de cast, l'opération est effectuée en float

    return 0;
}


/****************************
Exercice 7
Un magasin d'informatique annonce une réduction de 10% sur les ordinateurs portables.
Écrire un programme qui lit le prix d'un ordinateur entré au clavier et affiche
le nouveau prix avec la réduction.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
float prix;
    printf("entrez le prix de l'ordinateur\n");
    scanf("%f",&prix);

    printf("prix avec réduction : %.2f\n", prix*0.9);

    return 0;
}


/****************************
Exercice 8
Soit une fonction mathématique f définie par f(x) = (2x+3)(3x2+2).
Ecrire le programme qui calcule l'image par f d'un nombre saisi au clavier.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int nb;
    printf("saisie nombre :\n");
    scanf("%d",&nb);

    nb= (nb*2 + 3) * (6*nb + 2);
    printf("f(x)=%d\n",nb);
    return 0;
}


/****************************
Exercice 9
Ecrire un programme qui lit un nombre au clavier, affiche 1
s'il est pair et 0 s'il est impair.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int nb;
    printf("saisie nombre :\n");
    scanf("%d",&nb);

    printf("%d\n",1 - nb%2);

    return 0;
}


/****************************
Exercice 10
Écrire un programme qui affiche le nombre des dizaines, puis des centaines
et des milliers d'un nombre saisie au clavier. Par exemple pour 31345 dizaine
c'est le nombre 4, centaine 3 et millier 1.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int nb;
    printf("saisie nombre :\n");
    scanf("%d",&nb);

    printf("%d\n", nb%10); // unité
    nb/=10;
    printf("%d\n", nb%10); // dizaine
    nb/=10;
    printf("%d\n", nb%10); // centaine
    nb/=10;
    printf("%d\n", nb); // millier

    return 0;
}


/****************************
Exercice 11
Ecrire un programme qui arrondi un nombre réel entré au clavier à deux chiffres uniquement
après la virgule.
*

#include <stdio.h>
#include <stdlib.h>
int main()
{
float f;
int i;
    printf("enter un reel :\n");
    scanf("%f",&f);

    i=f*100;
    f=i/100.0;

    printf("%f\n", f); // affiche des 0 après arrondi
    printf("%.2f", f); // n'affiche plus les 0

    return 0;
}


/****************************
Exercice 12
Ecrire un programme qui lit une valeur entière entrée par l'utilisateur dans une variable i
et qui affiche i, i++ et ++i. Qu'est ce que ça donne ? Pourquoi ?
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
int i;
    printf("entrer un nombre : ");
    scanf("%d",&i);

    // par exemple pour i = 1
    printf ("%d\n", i);  // affiche 1

    printf ("%d\n", i++); // affiche 1, l'incrémentation a lieu après affichage
    // ici i vaut 2
    printf ("%d\n", ++i); // affiche 3, l'incrémentation a lieu avant affichage
    return 0;
}

/****************************
Exercice 13
Quels résultats fournit le programme suivant :
répondre avant d'exécuter le programme !
l'exécution du programme donne la réponse
*
#include <stdio.h>

int main()
{
int i, j, n;
	i=0;
	n=i++;
	printf("A : i = %d,  n = %d \n", i, n);   // 1, 0

	i=10;
	n=++i;
	printf("B : i = %d,  n = %d \n", i, n);   // 11, 11

	i=20;
	j=5;
	n=i++ * ++j;
	printf("C : i = %d,  j = %d, n = %d \n", i, j, n); //21 , 6 , 120

	i=15;
	n= i += 3;
	printf("D : i = %d,  n = %d \n", i, n); // 18, 18

	i = 3;
	j = 5;
	n = i *= --j;
	printf("E : i = %d,  j = %d, n = %d \n", i, j, n); // 12, 4, 12
	return 0;
}
/*********************************
*/




