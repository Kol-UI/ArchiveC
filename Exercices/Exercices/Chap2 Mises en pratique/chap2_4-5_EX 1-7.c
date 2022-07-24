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
*   4. Les tests multi-conditions (ET/OU)                        *
*   4.5 Mise en pratique : les opérateurs logiques ET, OU           *
*********************************************************************

/*********************************
Exercice 1
Le jeu du bandit à bras multiple. Trois roues sont mises en parallèle
elles ont sur leur tranche des numéros ou des lettres. Au départ elles
sont lancées et tournent à des vitesses différentes lorsqu’elles s’arrêtent
trois numéros ou lettres sont alignés : A5R ou 67T, on gagne lorsque
certaines combinaisons sortent, par exemple :
AAA, BCD, OIO… Faire un programme pour tenter sa chance un seul coup.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
char c1,c2,c3; // solution aléatoire initialisée par la machine
char r1=0,r2=0,r3=0; // solutions entrées par l'utilisateur

    srand(time(NULL));
    //initialisation solution machine en caractères (lettre ou nombre)
    c1 = (rand()%2==0) ? '0'+rand()%10 : 'A'+rand()%26;
    c2 = (rand()%2==0) ? '0'+rand()%10 : 'A'+rand()%26;
    c3 = (rand()%2==0) ? '0'+rand()%10 : 'A'+rand()%26;

    // entrée utilisateur
    printf("Bandit a bras multiple : entrer trois lettres ou/et nombre :\n");
    scanf("%c%c%c",&r1,&r2,&r3);

    // évaluation résultat
    printf("solution : %c|%c|%c\n",c1,c2,c3);
    printf("entree   : %c|%c|%c\n",r1,r2,r3);

    // message sortie
    if(c1==r1 && c2==r2 && c3==r3)
        printf("GAGNE !\n");
    else
        printf("PERDU !\n");

	return 0;
}

/*********************************
Exercice 2
X,Y, et Z étant des variables numériques, on considère
les deux séquences algorithmiques S1 et S2 :
Séquence S1

si (X<5 ou Y>2) et Z>3 alors X=1
			          si (Z-Y) >0 alors Z=0
			      finsi
			         Y = Y+Z
sinon
	X = 2
	Z = Y+Z
finsi

Séquence S2

si  X<5 ou  (Y>2 et Z>3) alors X =1
			              si  (Z-Y) > 0 alors Z = 0
finsi
Y = Y+Z
sinon
	X = 2
	Z = Y+Z
finsi

1) Pour chacune des deux séquences, donner les valeurs, après exécution,
de X, Y, et Z si l’on suppose qu’à l’état initial ces trois variables
ont les valeurs :
a) X =4	Y =1		Z =4
b) X =4	Y =5		Z =4
c) X =1	Y =3		Z =1

2) Faire un programme pour vérifier vos réponses aux deux séquences.

// Solutions papier :
1 ) remettre en forme la séquence

    // sequence 1
    si (X<5 ou Y>2) et Z>3
        alors X=1
        si (Z-Y) >0
            alors Z=0
        finsi
        Y = Y+Z
    sinon
        X = 2
        Z = Y+Z
    finsi

2) faire de tête l'évaluation :
    a) pour X=4	Y=1	Z=4  res : X=1, Y=1, Z=0
    b) pour X=4	Y=5	Z=4  res : X=1, Y=9, Z=4
    c) pour X=1	Y=3	Z=1  res : X=2, Y=3, Z=4


    //Séquence S2
1 ) remettre en forme la séquence

    si  X<5 ou  (Y>2 et Z>3)  // seules changent les parenthèses
        alors X =1
        si  (Z-Y) > 0
            alors Z = 0
        finsi
        Y = Y+Z
    sinon
        X = 2
        Z = Y+Z
    finsi

2) faire de tête l'évaluation :
    a) pour X=4	Y=1	Z=4  res : X=1, Y=1, Z=0
    b) pour X=4	Y=5	Z=4  res : X=1, Y=9, Z=4
    c) pour X=1	Y=3	Z=1  res : X=1, Y=4, Z=1

*

// 3) vérifier les réponses avec un programme et comprendre l'erreur
// le cas échéant (dans le programme mal écrit ou l'évaluation ?)

#include <stdlib.h>
#include <stdio.h>
int main()
{
int X,Y,Z;

    // sequenc 1/a
    X=4;
    Y=1;
    Z=4;
    printf("sequence 1/a : X = %d, y = %d, Z = %d\n",X,Y,Z);
    if ((X<5||Y>2) && Z>3){
        X=1;
        if (Z-Y >0)
            Z=0;

        Y = Y+Z;
    }
    else{
        X = 2;
        Z = Y+Z;
    }
    printf("resultat : X = %d, y = %d, Z = %d\n", X,Y,Z);

    //sequence 1/b
    X=4;
    Y=5;
    Z=4;
    printf("sequence 1/b : X = %d, y = %d, Z = %d\n",X,Y,Z);
    if ((X<5||Y>2) && Z>3){
        X=1;
        if (Z-Y >0)
            Z=0;

        Y = Y+Z;
    }
    else{
        X = 2;
        Z = Y+Z;
    }
    printf("resultat : X = %d, y = %d, Z = %d\n", X,Y,Z);

    // sequence 1/c
    X=1;
    Y=3;
    Z=1;
    printf("sequence 1/c : X = %d, y = %d, Z = %d\n",X,Y,Z);
    if ((X<5||Y>2) && Z>3){
        X=1;
        if (Z-Y >0)
            Z=0;

        Y = Y+Z;
    }
    else{
        X = 2;
        Z = Y+Z;
    }
    printf("resultat : X = %d, y = %d, Z = %d\n", X,Y,Z);

    // sequence 2/a
    X=4;
    Y=1;
    Z=4;
    printf("sequence 2/a : X = %d, y = %d, Z = %d\n",X,Y,Z);
    if  (X<5 ||  (Y>2 && Z>3)) {  // ET prioritaire, les parenthèses peuvent être retirées
        X =1;
        if  (Z-Y > 0)
            Z = 0;
        Y = Y+Z;
    }
    else{
        X = 2;
        Z = Y+Z;
    }
    printf("resultat : X = %d, y = %d, Z = %d\n", X,Y,Z);

    // sequence 2/b
    X=4;
    Y=5;
    Z=4;
    printf("sequence 2/b : X = %d, y = %d, Z = %d\n",X,Y,Z);
    if  (X<5 ||  (Y>2 && Z>3)) {
        X =1;
        if  (Z-Y > 0)
            Z = 0;
        Y = Y+Z;
    }
    else{
        X = 2;
        Z = Y+Z;
    }
    printf("resultat : X = %d, y = %d, Z = %d\n", X,Y,Z);

    // sequence 2/c
    X=1;
    Y=3;
    Z=1;
    printf("sequence 2/c : X = %d, y = %d, Z = %d\n",X,Y,Z);
    if  (X<5 ||  (Y>2 && Z>3)) {
        X =1;
        if  (Z-Y > 0)
            Z = 0;
        Y = Y+Z;
    }
    else{
        X = 2;
        Z = Y+Z;
    }
    printf("resultat : X = %d, y = %d, Z = %d\n", X,Y,Z);
	return 0;
}

/*********************************
Exercice 3
Dans un algorithme qui analyse des résultats d’examen, 4 variables
permettent de décrire l’environnement :
les variables numériques Nlv, Nf, Nm, Np qui indiquent respectivement,
pour un candidat donné, des notes littéraires : langue vivante (Nlv),
de français (Nf) ,  et des notes scientifiques :  mathématiques (Nm),
et  physique (Np). On suppose que les notes sont calculées sur 20 et
quelles ont toutes le même coefficient.

Formez les expressions logiques (et seulement elles) correspondant
aux situations suivantes :
1) la moyenne des quatre notes est supérieure à 10
2) les notes de mathématiques et de français sont supérieures à la
moyenne des quatre notes
3) il y a au moins une note supérieure à 10
4) toutes les notes sont supérieures à 10
5) la moyenne (10) est obtenue pour l’un des deux types
(littéraire et scientifique)
6) la moyenne des quatre notes est supérieure ou égale à 10 et la
moyenne (10) est obtenue pour l’un des deux types.

// solution papier uniquement demandée :
1) la moyenne des quatre notes est supérieure à 10

    ((Nlv + Nf + Nm + Np) / 4 > 10 )


2) les notes de mathématiques et de français sont supérieures à la
moyenne des quatre notes

    pour alléger l'écriture prenons une variable m pour la moyenne :
    m = (Nlv + Nf + Nm + Np) / 4

    (Nm > m && Nf > m)


3) il y a au moins une note supérieure à 10

    (Nf > 10 || Nlv > 10 || Nm > 10 || Np > 10)

    (Attention le test doit être effectué pour chaque variable)


4) toutes les notes sont supérieures à 10

    (Nf > 10 && Nlv > 10 && Nm > 10 && Np > 10)


5) la moyenne (10) est obtenue pour l’un des deux types
(littéraire et scientifique)

    (Nf + Nlv) / 2 >= 10 || (Nm + Np) / 2 >= 10


6) la moyenne des quatre notes est supérieure ou égale à 10 et la
moyenne (10) est obtenue pour l’un des deux types.

    (Nlv + Nf + Nm + Np) / 4 >= 10 && ( (Nf + Nlv) / 2 >= 10 || (Nm + Np) / 2 >= 10 )


/*********************************
Exercice 4
Donnez l’algorithme qui détermine le nombre de valeurs distinctes parmi
trois variables à faire saisir par l’utilisateur.
(ex : 8, 8 et 8 saisi par l’utilisateur donne 1 valeur distincte…)

Comment faire avec 4 variables ?
*
#include <stdlib.h>
#include <stdio.h>
int main()
{
int v1,v2,v3,v4,res;

    printf("entrer 3 valeurs : ");
    scanf("%d%d%d",&v1,&v2,&v3);

    // solution 1 :
    // soit elles sont toutes distinctes : 3 valeurs
    // soit elles sont toutes égales : 1 valeur
    // sinon 2 valeurs
    if (v1==v2 && v2==v3)
       res=1;
    else if(v1!=v2 && v1!=v3 && v2!=v3)
        res=3;
    else
        res=2;

    printf("%d valeurs distinctes\n",res);

    // solution 2 : additionner le résultat des tests
    res= (v1!=v2)+(v1!=v3)+(v2!=v3);
    // juste corriger si toutes les val sont égale res= 0
    if (res==0)
        res=1;
    printf("%d valeurs distinctes\n",res);
    printf("-------------------------\n");

    //Pour quatre valeurs la piste de la solution 2 semble adaptée
    // mais il faut modifier le test afin d'isoler chaque valeur
    printf("entrer 4 valeurs : ");
    scanf("%d%d%d%d",&v1,&v2,&v3,&v4);
    res =(v1!=v2 && v1!=v3 && v1!=v4) +  // 0 ou 1
         (v2!=v3 && v2!=v4) +            // 0 ou 1
         (v3!=v4)                        // 0 ou 1
         + 1;                            // 1
    printf("%d valeurs distinctes\n",res);
	return 0;
}

/*********************************
Exercice 5
Nous sommes dans un jeu vidéo avec une résolution d’écran 640x480 pixels.
Au centre il y a une zone rectangulaire de 580x420. Cette zone est divisée
en quatre parties égales (z1,z2,z3,z4). Chaque partie est en fait un bouton
cliquable (voir dessin dans le livre)

Faire le programme qui :
initialise deux variables x et y avec une position choisie  aléatoirement
dans l'écran affiche dans quelle zone se trouve cette position
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int x,y;

// le mieux est de détreminer avec un papier les coordonnées de chaque
// zone (faire un dessin en notant les coordonnées)
const int x1=50,x2=340,x3=610;
const int y1=30,y2=240,y3=450;

    srand(time(NULL));
    x=rand()%640;
    y=rand()%480;

    if(x<x1 || x>x3 || y<y1 || y>y3)
        printf("(%d, %d) hors zone\n",x,y);
    else if(x>x1 && x<x2 && y>y1 && y<y2)
        printf("(%d, %d) zone 1\n",x,y);
    else if (x>x2 && x<x3 && y>y1 && y<y2)
        printf("(%d, %d) zone 2\n",x,y);
    else if (x>x1 && x<x2 && y>y2 && y<y3)
        printf("(%d, %d) zone 3\n",x,y);
    else if (x>x2 && x<x3 && y>y2 && y<y3)
        printf("(%d, %d) zone 4\n",x,y);
    else
        printf("(%d, %d) sur un trait\n",x,y);

	return 0;
}

/*********************************
Exercice 6
Un personnage dispose de plusieurs talents : Bravoure, force, patience,
persévérance, résistance à la magie. Chaque talent est une valeur entre 0 et 100.
Selon les épreuves, il peut prendre peur, se révéler faible, perdre patience,
être tenté de tout laisser tomber. Faire le programme qui répond aux questions
et situations suivantes :
- si la patience est inférieure à 50 la persévérance baisse de plusieurs degrés.
- a t-il autant de bravoure que de patience, et de force que de persévérance ?
- a t-il plus de patience que de force, bravoure et persévérance réunies ?
- est ce que sa résistance à la magie est égale à la moyenne des autres talents moins 1/10 ?
- pour se sortir d’une épreuve magique de niveau 1 il faut soit que sa bravoure et
sa force soient comprises entre 30 et 70 soit que sa patience et sa persévérance
soient supérieures à 40. Peut-il s'engager dans une telle épreuve ?
- il meurt dans une épreuve de survie de niveau 5 si sa force n’est pas au moins
supérieure à 50, a t-il des chances de survivre s'il s'y engage maintenant ?
- un sort magique d’anéantissement le réduit en ombre si la force du sort est
supérieure à la somme de ses talents multipliés par sa résistance à la magie.
Tester avec un sort de force aléatoire
- lorsqu’il a autant de bravoure que de force, patience et persévérance sa
résistance à la magie augmente de 20. Augmente t-il sa magie maintenant ?

*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int brav, force, patience, persev, resist, nb, sort;
float moyenne;
    // initialisation avec des valeurs aléatoires
    // des caractèristiques du personnage
    srand(time(NULL));
    brav=rand()%100;
    force=rand()%100;
    patience=rand()%100;
    persev=rand()%100;
    resist=rand()%100;
    printf("personnage : \n");
    printf("- bravoure     : %d\n"
           "- force        : %d\n"
           "- patience     : %d\n"
           "- perseverance : %d\n"
           "- resistance   : %d\n\n",brav,force,patience,persev,resist);

    // si la patience est inférieure à 50 la persévérance
    // baisse de plusieurs degrés.
    if(patience<50){
        nb=1+rand()%4;
        resist-=nb;
        if (resist<0)
            resist=0;
        printf("resistance %d a perdu %d cause patience <50\n\n",resist,nb);
    }
    // a t-il autant de bravoure que de patience, et de force
    // que de persévérance ?
    if (brav==patience && force==persev)
        printf("autant de bravoure que de patience \n"
               "et de force que de perseverance\n\n");
    else if(brav!=patience && force!=persev)
        printf ("n'a pas autant de bravoure que de patience \n"
               "ni autant de force que de perseverance\n\n");

    // a t-il plus de patience que de force, bravoure et
    // persévérance réunies ?
    if (patience>force+brav+persev)
        printf("patience superieure a force, bravoure et perseverance reunies\n\n");
    else
        printf("patience inferieure a force, bravoure et perseverance reunies\n\n");

    // est ce que sa résistance à la magie est égale à la moyenne
    // des autres talents moins 1/10 ?
    moyenne = (patience+force+brav+persev)/5.0;
    moyenne -= moyenne*0,1;
    if (resist==(int)moyenne)
        printf("resistance (%d) a la magie egale a moyenne - 1/10 (%d)\n\n",resist, (int)moyenne);
    else
        printf("resistance (%d) differente de moyenne - 1/10 (%d)\n\n",resist, (int)moyenne);

    // pour se sortir d’une épreuve magique de niveau 1 il faut soit que
    // sa bravoure et sa force soient comprises entre 30 et 70 soit
    // que sa patience et sa persévérance soient supérieures à 40.
    // Peut-il s'engager dans une telle épreuve ?
    if( (brav>30 && brav<70) || (persev>40 && patience>40))
        printf("peut s'engager dans une epreuve magique de niveau 1\n\n");
    else
        printf("ne peut pas s'engager dans une epreuve magique de niveau 1\n\n");

    // il meurt dans une épreuve de survie de niveau 5 si sa force n’est pas au moins
    // supérieure à 50, a t-il des chances de survivre s'il s'y engage maintenant ?
    if (force <=50)
        printf("aucune chance survie epreuve niveau 5\n\n");
    else
        printf("peut survivre epreuve niveau 5\n\n");

    // un sort magique d’anéantissement le réduit en ombre si la force du sort est
    // supérieure à la somme de ses talents multipliés par sa résistance à la magie.
    // Tester avec un sort de force aléatoire
    sort=rand()%1000;
    if(sort > (brav+persev+resist+force+patience)*resist)
        printf("reduit en ombre par sort de %d\n\n",sort);
    else
        printf("survit au sort de %d\n\n",sort);

    // lorsqu’il a autant de bravoure que de force, patience et persévérance sa
    // résistance à la magie augmente de 20. Augmente t-il sa magie maintenant ?
    if(brav==force && force==patience&&patience==persev){
        resist+=20;
        printf("resistance augmentee de 20\n\n");
    }
    else
        printf("n'augmente pas sa resistance a la magie\n\n");


	return 0;
}
/*********************************
Exercice 7
Nous sommes dans un monde de champignons microscopiques étranges :
lorsque trois entités de la même espèce se touchent elles en produisent
une quatrième de la même espèce puis se dispersent. En revanche s’il n’y
en a que deux qui sont de la même espèce la troisième est anéantie et les
deux autres restent solidaires. Si elles sont toutes d’espèces différentes
rien ne se passe.
Faire un programme simple qui simule le principe de cette interaction.
*
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main()
{
int e1,e2,e3,e4;

    srand(time(NULL));
    // trois entités
    e1=1+rand()%3; // trois espèces possible 1,2,3
    e2=1+rand()%3;
    e3=1+rand()%3;
    printf("e1 : %d\ne2 : %d\ne3 : %d\n",e1,e2,e3);

    // nous nous inspirons de l'exercice 4
    if(e1==e2 && e2==e3){
        e4=e1;
        printf("Trois de la meme espece : une nouvelle creee, e4\n");
    }
    else if(e1!=e2 && e1!=e3 && e2!=e3)
        printf("toutes differentes rien ne se passe\n");
    else if (e1==e2){
        e3=0;
        printf("e3 detruite\n");
    }
    else if (e1==e3){
        e2=0;
        printf("e2 detruite\n");
    }
    else if (e2==e3){
        e1=0;
        printf("e1 detruite\n");
    }

	return 0;
}
/*********************************
*/

