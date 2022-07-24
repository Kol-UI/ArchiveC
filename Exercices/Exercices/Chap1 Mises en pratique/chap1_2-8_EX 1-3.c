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
*   2. Variables simples                                            *
*   2.8 Mise en pratique : codage des informations numériques       *
*********************************************************************
/*********************************
Exercice 1
Combien d’informations pouvez-vous coder sur 2 bits ? sur 4 ? sur 8 bits ?
2 puissance 2, 4 informations
2 puissance 4, 16 informations
2 puissance 8, 256 informations

Quels sont les codes binaires associés à ces informations ?
Tous les nombres binaires associés,
sur 2 bits : 00, 01, 10, 11
sur 4 bits : 0000, 0001, 0010, 0011,
             0100, 0101, 0110, 0111,
             1000, 1001, 1010, 1111,
             1100, 1101, 1110, 1111

sur 8 bits, même principe.


Quelles sont les valeurs décimales associées à ces codes ? En signé ? En non-signé ?
en non signé :
sur 2 bits de 0  à 3    // (0 à (2 puissance 2)-1)
sur 4 bits de 0 à 15    // (0 à (2 puissance 4)-1)
sur 8 bits de 0 à 255   // (0 à (2 puissance 8)-1)

en signé :
sur 2 bits de -1 à 1        // de - 2 puissance 2 à 2 puissance 2-1
sur 4 bits de -             // de - 2 puissance 4 à 2 puissance 4-1
sur 8 bits de -128 à +127   // de - 2 puissance 8 à 2 puissance 8-1

Combien de bits faut-il pour coder un alphabet (chinois) de 4344 lettres ? Combien d'octets ?
4344 fait 1000011111000 en binaire, il faut donc 13 bits, 2 octets (16 bits)

*/

/*********************************
Exercice 2
Donner en binaire le codage des nombres -32, -77, 104, 258 sur 8 bits.

Utiliser une calculatrice pour avoir les nombres en binaire

-32 :
32 donne en binaire      : 00100000 le négatif -32 c'est le complément à deux :
l'inverse est            : 11011111
le complément à deux est : 11100000, codage binaire de -32 (valeur 224 en non signé)


-77
77 donne en binaire  : 01001101 le négatif -77 c'est le complément à deux
inverse              : 10110010
complément à deux    : 10110011, codage binaire de -77 (valeur 179 en non signé)

104 :  01101000
258 :  100000010 et sur 8 bits : 00000010, valeur 2 en decimal (troncature)


le programme ci-dessous permet de vérifier pour les valeurs non signées
des nombres négatifs.
*

#include <stdio.h>
#include <stdlib.h>
int main()
{
unsigned char v;
    v=-32;
    printf("%d\n", v);

    v=-77;
    printf("%d\n", v);

    return 0;
}
*/

/*********************************
Exercice 3
Si dans un programme :
	- j'affecte la valeur 266 à un char  et que je l'affiche quel est le résultat ?
 	- j'affecte la valeur 384 à un char et que je l'affiche quel est le résultat ?
	- j'affecte la valeur 768 à un char et que je l'affiche quel est le résultat ?
	- j'affecte la valeur 23277 à un char et que je l'affiche, résultat ?
	- combien donne sur un char -120+250 ?
	- combien donne sur un char -120-120 ?
Testez ou trouvez vos réponses avec un programme et expliquez les résultats.
*
#include <stdio.h>
#include <stdlib.h>
int main()
{
char v;
    v=266;
    printf("%d\n", v);   // 10 : 266 % 256  (le modulo "%" donne le reste de la division par 256)

    v=384;
    printf("%d\n", v);  //  -128 : 384 % 256 en signé

    v=768;
    printf("%d\n", v);  // 0     : 768 % 256 c'est 0

    v=23277;
    printf("%d\n", v);  // -19   : 23277 % 256 en signé

    v=-120+250;
    printf("%d\n", v);  //-126   : 130 en signé

    v=-120-120;
    printf("%d\n", v);  // 16    : 240 en signé

    return 0;
}
/*********************************
*/




