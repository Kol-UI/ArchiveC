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
/************************************************************************
*   Chapitre 4 : Les tableaux								            *
*   2. Exemples d'utilisations de tableaux                              *
*   2.5 Mise en pratique tableaux                                       *
*************************************************************************

// REMARQUE :
// nous sommes dans la partie E "Exemples d'utilisation de tableaux".
// Les tableaux passés en paramètre de fonction viennent dans la partie G
// Pour cette raison nous évitons d'écrire des fonctions avec tableau en
// paramètre dans toutes ces solutions.
//
// De même ce chapitre vient avant les tableaux de structures qui sont
// abordés dans la partie suivante F. Pour cette raison nous évitons
// également d'avoir recours à des tableaux de structures.
// De ce fait nous retrouvons l'ancêtre de la structure :
// l'utilisation de tableaux en parallèle, une technique qui peut
// s'avérer utile le cas échéant.

/************************************************
*                                               *
*  Chaines de caractères                        *
*                                               *
************************************************/


/*********************************
Exercice 1
A partir d'un menu proposé à l'utilisateur faire le programme suivant :
-Saisir une chaîne de caractères
-Compter la longueur d'une chaîne
-Convertir la chaîne saisie en majuscules. Seuls les caractères en minuscule sont
modifiés les autres sont évités.
-Convertir la chaîne saisie en minuscules
-Comparer 2 chaînes à saisir. Il s'agit de dire si elles sont identiques et
laquelle est la première dans l'ordre lexicographique.
-Concaténer 2 chaînes dans la première (attention aux débordements)
-Crypter une chaîne en appliquant un décalage circulaire dont la valeur est
entrée par l’utilisateur
-Décrypter une chaîne de caractères cryptée en appliquant un décalage circulaire
inverse à partir d’une valeur entrée par l’utilisateur.
*

#include <stdio.h>
#include <stdlib.h>

int menu(void);
int main()
{
int fin=0;
char s[80]="chaine par defaut\n";
char s2[80];
int length,i,comp,k,cle=0;

    while(!fin){
        switch(menu()){
            case 1 :    // saisir chaine
                // attention fgets récupère dans la chaine le \n final
                // lorsque l'utilisateur tape enter. C'est un caractère de
                // plus dans le chaine
                printf("entrer chaine : ");
                fgets(s,80,stdin);
                rewind(stdin);
                break;

            case 2 :    // longueur
                for (length=0; s[length]!='\0';length++)
                    ;
                printf("%d caracteres dans la chaine : %s",length,s);
                break;

            case 3 :    //majuscule
                for (i=0; s[i]!='\0'; i++)
                    // si minuscule
                    if(s[i]>='a'&&s[i]<='z')
                        s[i]='A'+s[i]-'a'; // conversion
                printf("%s",s);
                break;
            case 4 :    // minuscule
                for (i=0; s[i]!='\0'; i++)
                    // si majuscule
                    if(s[i]>='A'&&s[i]<='Z')
                        s[i]='a'+s[i]-'A';
                printf("%s",s);
                break;

            case 5 :    //comparer deux chaines
                printf("entrer une autre chaine :");
                fgets(s2,80,stdin);
                rewind(stdin);
                // pour simplifier passer les deux chaines en minuscules
                // (vivement les tableaux en paramètre de fonctions )
                for (i=0; s[i]!='\0'; i++)
                    if(s[i]>='A'&&s[i]<='Z')
                        s[i]='a'+s[i]-'A';
                for (i=0; s2[i]!='\0'; i++)
                    if(s2[i]>='A'&&s2[i]<='Z')
                        s2[i]='a'+s2[i]-'A';
                // comparaison caractère par caractère
                for (comp=0,i=0; s[i]!='\0' || s2[i]!='\0'; i++){
                    comp=s[i]-s2[i];
                    if(comp!=0){ // si différence inutile de continuer
                        break;
                    }
                }
                // analyse résultat
                if (comp==0)
                    printf("%s et %s identiques\n",s,s2);
                else if (comp<0)
                    printf("%s avant %s\n",s,s2);
                else
                    printf("%s avant %s\n",s2,s);
                break;

            case 6 :    // concaténer
                printf("entrer une autre chaine :");
                fgets(s2,80,stdin);
                rewind(stdin);
                // fin première chaine
                for(i=0; s[i]!='\0'; i++)
                    ;
                // continuer avec la copie seconde à la suite,attention à
                // ne pas exéder la taille du tableau s et dans ce cas à avoir
                // tout de même un '\0' à la fin de la chaine s
                s[79]='\0';
                for (k=0 ; i<79; i++,k++){
                    s[i]=s2[k];
                    if (s2[k]=='\0')
                        break;
                }
                printf("concatenation : %s",s);
                break;

            case 7 :    //crypter
                // décrypter au cas ou la chaine est déjà cryptee
                if(cle!=0)
                    for (i=0; s[i]!='\0'; i++)
                        s[i]-=cle;

                cle+=5+rand()%20;
                for (i=0; s[i]!='\0'; i++)
                    s[i]+=cle;
                printf("chaine cryptee : %s",s);
                putchar('\n');
                break;
            case 8 :    //decrypter
                for (i=0; s[i]!='\0'; i++)
                    s[i]-=cle;
                cle=0;
                printf("chaine decryptee : %s",s);
                break;

            default : fin=1;
        }
    }
    return 0;
}
int menu()
{
int choix;
    printf("1 : saisir une chaine\n"
           "2 : longueur\n"
           "3 : majuscules\n"
           "4 : minuscules\n"
           "5 : comparer deux chaines\n"
           "6 : concatener deux chaines\n"
           "7 : crypter\n"
           "8 : decrypter\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}
/*********************************
Exercice 2
La commande suivante arrive par courriel :

"Bonjour,
Je souhaiterais un générateur de mots de passe aléatoires avec les possibilités suivantes :
choisir le nombre de mots de passe à générer
choisir la longueur du mot de passe (de 6 à 30 caractères max)
choisir les types de caractères utilisés (minuscules, majuscules, chiffres, signes)
vérification de l'usage de tous les types de caractères sélectionnés
Exclure les caractères O et I qui prêtent à confusion
...Merci, ...Cordialement,..."
Faire une proposition.
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
// tous les signes disponibles(extensible)
char signes[]={'-','+','$','#','@','&','~','/','!','?','.','*',';',':','%'};// etc.

char mot[100][31]={{0}}; // 100 mots maximum de 30 caractères maximum +1 pour '\0'
int nbm;                 // le nombre de mot récupéré
int length;              // la taille de mot
char type[4],nbtype;     // les types et nombre de type
char used[4],cntluse;    // les types utilisés, controle utilisation
int m,i,t,j;             // tools
char tourne='o';

    srand(time(NULL));

    while(tourne=='o'){
        printf("generer des mots de passe :\n");

        // ENTREE DES DONNEES
        printf("nombre de mots : ");
        scanf("%d",&nbm);
        rewind(stdin);
        if(nbm>100)
            nbm=100;

        printf("longueur des mots : ");
        scanf("%d",&length);
        rewind(stdin);
        if(length<6)
            length=6;
        if (length>30)
            length=30;

        printf("entrer type de caracteres utilises : \n");
        memset(type,0,sizeof(char)*4);// met type à 0
        for (i=0;i<4; i++){
            if(type[i]!='o'&&type[i]!='n'){
                switch(i){
                    case 0 : printf(" - minuscules ? (o/n)");   break;
                    case 1 : printf(" - majuscules ? (o/n)");   break;
                    case 2 : printf(" - chiffres   ? (o/n)");   break;
                    case 3 : printf(" - signes     ? (o/n)");   break;
                }
            }
            scanf("%c",&type[i]);
            rewind(stdin);
        }

        // conserver nombre de type pour controle utilisation
        for (i=0,nbtype=0; i<4; i++)
            if(type[i]=='o')
                nbtype++;

        // si aucune sélection
        if (nbtype==0){
            // sélection aléatoire avec oui au moins pour minuscules
            type[0]='o';
            nbtype=1;
            for (i=1; i<4; i++){
                if(rand()%2){
                    type[i]='o';
                    nbtype++;
                }
                else
                    type[i]='n';
            }
        }

        // GENERATION

        // pour chaque mot
        for (m=0; m<nbm; m++){

            // pour le controle d'utilisation des types
            memset(used,0,4);   // tous les utilsations à 0
            cntluse=rand()%(length-4); //détermine la position du contrôle dans la chaine
            // pour chaque lettre dans un mot
            for (i=0; i<length; i++){

                t=-1;
                // dans un interval choisi aléatoirement contrôler si tous les types
                // sélectionnés sont utilisés et si non forcer l'utilisation de ceux
                // qui n'ont pas encore été utilisés
               if(i>=cntluse && i<cntluse+nbtype){
                    //
                    for (j=0; j<4 && t==-1; j++){
                        if(type[j]=='o'&& used[j]==0 ){
                            t=j;
                            used[j]++;
                        }
                    }
                }
                // cas général
                if(t==-1){
                    // tirage aléatoire d'un type
                    t=rand()%4;
                    while(type[t]=='n') // chercher un type sélectionné
                        t=(t+1)%4;
                    used[t]++; // marque les utilisations d'un type
                }
                printf("t=%d ",t);
                // ensuite déterminer un caractère selon le type
                switch(t){
                    case 0 :    // minuscule
                        mot[m][i]='a'+rand()%26;
                        break;

                    case 1 :    // majuscule
                        mot[m][i]='A'+rand()%26;
                        if(mot[m][i]=='I' || mot[m][i]=='O')
                            mot[m][i]+=(rand()%2*2)-1;// 1 ou -1
                        break;

                    case 2 :    // chiffre
                        mot[m][i]='0'+rand()%10;
                        break;

                    case 3 :    // signe
                        mot[m][i]=signes[rand()%sizeof(signes)];
                        printf("%c",mot[m][i]);
                        break;

                }
                putchar('\n');
            }
            // fin mot de passe (une chaine de caractères : '\0')
            mot[m][i]='\0';
            printf("passe %d : %s\n",m,mot[m]);
        }
        // ici tous les mots de passe sont générés, possibilité de les
        // sauvegarder sur fichier ici (voir chapitre 4 / D fichiers)

        printf("autre generation ? (o/n)");
        scanf("%c",&tourne);
        rewind(stdin);
    }


    return 0;
}


/*********************************
Exercice 3
M. A est une lettre qui se déplace sur l'ensemble d'une aire de jeu définie.
Autour de lui sont placées au hasard des lettres de couleurs que M.A peut ramasser.
En fait une phrase (ou un mot ) est disséminée et il doit la reconstituer.
Chaque bonne lettre trouvée vient s'adosser derrière lui de sorte que la phrase
constitue progressivement une chenille. Il s'agit de reconstituer la phrase entière.
Le programme pourra tenir en réserve plusieurs phrases afin de pouvoir faire plusieurs
parties. Le choix des phrases est aléatoire. Programmer.
*

//
// 4 scenarios sont envisageables pour la chenille :
//  1) la chenille doit prendre les lettres dans l'ordre de la phrase
//  2) elle peut prendre les lettres dans le désordre et réorganise son corps
//    (la phrase) au fur et à mesure
//  3) la chenille est déjà constituée de la phrase entière mais ne donne à
//    voir que les lettres trouvées
//  4) la chenille est constituée des lettres trouvées dans le désordre et
//    et quand toutes les lettres sont trouvées la phrase est affichée
//
//  C'est la quatrième solution qui est traitée ici.
//  Par ailleurs la chenille peut se marcher dessus
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define  TX         80  // taille zone de jeu
#define  TY         20
#define  NBPHRASE   5   // nombre de phrases

void affiche_lettre(int x, int y, int l, int color);
void textcolor(int color);
void gotoxy(int x, int y);

int main()
{

// Chenille :
// chaque paire de pied correspond à un indice, la tete est à l'indice 0
int xx[TX*TY];      // coordonnées horizontales pieds chenille
int yy[TX*TY];      // coordonnées verticales pieds chenille
int ll[TX*TY];      // toutes les lettres du corps

                 // remarque : les trois tableaux sont utilisés en parallèle de sorte
                 // que pour chaque indice on dispose de trois variables. En fait cette
                 // solution peut être remplacée par un tableau de structures
                 // (voir partie F qui suit)

int dern=0;      // indice du dernier pied après la tête (tete en 0)

// zone de jeu :
int zone[TY][TX]={{0}}; // met à 0 au départ

// phrase et lettres
       // nombre total des phrases
char phrase[NBPHRASE][30]={        // le dico des phrases
    "tata fait du velo",
    "toto va a la plage",
    "tartempion est de retour",
    "C'est la valse des voyageurs",
    "tiens voila du boudin"
};
int sel;        // indice de la phrase selectionnée
int nbl;        // nombre de lettres qui restent à trouver
int lx,ly,c;

// tools
int fin=0,x,y,i,clav;

    srand(time(NULL));

    // initialisation + affichage départ
    xx[0]=TX/2; // tete (au départ pas de corps)
    yy[0]=TY/2;
    ll[0]='C';   // lettre de la tete
    affiche_lettre(xx[0],yy[0],ll[0],10);

    while(!fin){
        if(kbhit()){
            clav=getch();
            if(clav!=224){ // évacuer le code 224 nécessaire au touches flèches

                x=xx[0]; // recup coord chenille
                y=yy[0];

                switch(clav){
                    // move chenille ?
                    case 72 :   y--;    break;  // haut
                    case 77 :	x++;	break;	// droite
                    case 80 :	y++;	break;	// bas
                    case 75 :	x--;	break;	// gauche

                    // lettre et phrase
                    case 13 : // enter
                        // 0) effacer et réinitialiser la chenille
                        affiche_lettre(xx[0],yy[0],'C',0);
                        for(i=1; i<=dern; i++)
                            affiche_lettre(xx[i],yy[i],ll[i],0);

                        dern=0;       // pas de corps
                        x=xx[0]=TX/2; // tete
                        y=yy[0]=TY/2;
                        affiche_lettre(xx[0],yy[0],'C',10);

                        // effacer l'éventuel messge de fin précédent
                        gotoxy(0,TY+1);
                        textcolor(0);
                        printf ("GAGNE !");
                        gotoxy(0,TY+2);
                        textcolor(8);
                        printf("%30s"," ");

                        // 1) effacer et réinitialiser la zone de jeu (si partie non finie)
                        for (ly=0; ly<TY; ly++)
                            for (lx=0;lx<TX; lx++)
                                if(zone[ly][lx]!=0){
                                    zone[ly][lx]=0;
                                    affiche_lettre(lx,ly,' ',0);
                                }

                        // 2) choisir une phrase au hasard
                        sel=rand()%NBPHRASE;

                        // 3) compter les lettres à trouver
                        nbl=0;
                        for (i=0; phrase[sel][i]!='\0'; i++){
                            c=phrase[sel][i];
                            if ((c>='a' && c<='z')|| (c>='Z'&&c<='Z')){ // ne prend que les lettres
                                nbl++;
                                //4) positionner les lettres dans la zone de jeu
                                lx=rand()%TX;
                                ly=rand()%TY;
                                // si position dèjà occupée
                                while(zone[ly][lx]!=0 || (lx==x && ly==y)){
                                    if(rand()%2)  // trouver case libre
                                        lx=(lx+1%TX);
                                    else
                                        ly=(ly+1%TY);
                                }
                                // 5) stock et affiche la lettre
                                zone[ly][lx]=c;
                                affiche_lettre(lx,ly,c,15);
                            }
                        }
                        break;

                    // toute autre touche : met fin au prg
                    default :   fin=1;  break;
                }

                // move chenille
                // contrôler les bords
                if (x<0)
                    x=0;
                if (x>=TX)
                    x=TX-1;
                if (y<0)
                    y=0;
                if (y>=TY)
                    y=TY-1;

                // si mouvement
                if (x!=xx[0]||y!=yy[0]){

                    // si lettre trouvée
                    if (zone[y][x]!=0){
                        dern+=1;
                        ll[dern]=zone[y][x];
                        zone[y][x]=0;
                        nbl--;
                        if (nbl==0){
                            gotoxy(0,TY+1);
                            textcolor(9);
                            printf ("GAGNE !");
                            gotoxy(0,TY+2);
                            textcolor(8);
                            printf("%s",phrase[sel]);
                        }
                    }

                    // effacer la derniere position
                    affiche_lettre(xx[dern],yy[dern],ll[dern],0);

                    // chaque position récupère les coordonnées de la position précédente
                    for (i=dern; i>0; i--){
                        xx[i]=xx[i-1];
                        yy[i]=yy[i-1];
                    }
                    // la première position prend les coordonnées de la tête
                    xx[0]=x;
                    yy[0]=y;

                    // affichage
                    for(i=1; i<=dern; i++)
                        affiche_lettre(xx[i],yy[i],ll[i],12);
                    affiche_lettre(xx[0],yy[0],'C',10);
                }
            }
        }
    }
    gotoxy(0,TY+1);
    textcolor(15);
    return 0;
}
void affiche_lettre(int x, int y, int l, int color)
{
    gotoxy(x,y);
    textcolor(color);
    putchar(l);
}

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
//
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
/*********************************
Exercice 4
Le jeu du pendu. Le programme détermine un mot de sept lettres et le joueur doit
trouver ce mot. Pour ce faire il propose un mot. Si des lettres coïncident entre
le mot a trouver et le mot proposé elles sont affichées à leur bonne place (les
lettres non trouvées sont remplacées par des tirets). L'objectif est de trouver
le mot avec un minimum de proposition.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
char mot[3][8]={"bonjour", "bonsoir","fromage"};
char in[20];
char res[8]={"-------"};
int fin,nbtour,nbl,sel,i,j;
int joue='o';

    srand(time(NULL));
    while(joue=='o'){
        printf("trouver le mot cache de 7 lettres :\n");
        sel=rand()%3;
        fin=0;
        nbtour=0;
        while (!fin){
            printf("entrer un mot : ");
            scanf("%s",in);
            rewind(stdin);

            nbtour++;
            for(i=0; in[i]!='\0';i++ )
                for (j=0; mot[sel][j]!='\0'; j++)
                    if(in[i]==mot[sel][j])
                        res[j]=mot[sel][j];
            nbl=0;
            for (i=0; res[i]!='\0'; i++)
                if(res[i]!='-')
                    nbl++;
            printf("trouvee %d lettre(s) : %s\n",nbl,res);
            if(nbl==7)
                fin=1;

        }

        printf("TROUVE EN %d TOURS\n",nbtour);

        printf("autre partie ? (o/n)");
        scanf("%c",&joue);
        rewind(stdin);
    }
    return 0;
}

/*********************************
Exercice 5
Faire un générateur automatique de texte. Le principe est de créer des modèles de phrases.
C’est-à-dire des "moules à phrases"  que l’on désigne par le terme de "protophrases".
Une protophrase est construite à partir d’un enchaînement de catégories de mots ou
d’expressions. La protophrase de base est simple, du type : Nom / Adjectif / Verbe / Nom.
Chaque catégorie est un ensemble de mots du type correspondant. Pour faire une phrase
il suffit ensuite, selon le modèle initial, de faire un tirage aléatoire dans chaque
catégorie et d'assembler le résultat.

Pour chaque catégorie il y a une librairie de mots ou d’expressions rangés dans un
tableau directement dans le code source du programme. Bien sur des mots fixes peuvent
être ajoutés dans le protophrase afin d’augmenter les possibilités expressives, par exemple :
Nom / Verbe / AVEC / Nom / SUR / Nom. Les mots "avec" et "sur" sont fixes dans la protophrase.
*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define NB_NOM      10
#define NB_ADJ      8
#define NB_VERBE    8
// le nombre de protophrases disponibles
#define NB_PROTO    2

int main(int argc, char *argv[])
{
// les listes par catégorie de mot

char nom[NB_NOM][30]={"toto","un chien","un chat","un oiseau","un sale rat",
                   "titi","un turlututu","un cadeau","un hippopotame",
                   "un pinguoin" };


char adj[NB_ADJ][30]={"vert","bleu","effroyable","indomptable","merveilleux",
                   "effraye","rassure","joyeux"};


char verbe[NB_VERBE][30]={"mange","boit","court","regarde","marche",
                        "vole","s'applatit","se coince"};


int proto,fin=0;
int m1,m2,m3,m4,m5,m6;

   srand(time(NULL));
   printf("Test Generateur de texte :\n"
          "    - appuyer sur une touche\n"
          "    - 'q' pour quitter\n\n");

   while(fin!='q'){
      if (kbhit()){
         fin=getch();
         proto=rand()%NB_PROTO;
         switch(proto){
            // nom-verbe-avec-nom-SUR-nom
            case 0 :
               m1=rand()%NB_NOM;
               m2=rand()%NB_VERBE;
               m3=rand()%NB_NOM;
               m4=rand()%NB_NOM;
               printf("%s %s avec %s sur %s\n",nom[m1],verbe[m2],nom[m3],nom[m4]);
               break;

            // Lorsqu'-nom-adjectif-verbe-nom-verbe-tout-adjectif
            case 1 :
               m1=rand()%NB_NOM;
               m2=rand()%NB_ADJ;
               m3=rand()%NB_VERBE;
               m4=rand()%NB_NOM;
               m5=rand()%NB_VERBE;
               m6=rand()%NB_ADJ;
               printf("Lorsqu'%s %s %s, %s %s tout %s\n",
                      nom[m1],adj[m2],verbe[m3],nom[m4],verbe[m5],adj[m6]);
               break;
         }
      }
   }

  return 0;
}

/*********************************
Exercice 6
Remplir une matrice de lettres et, à partir d’une liste de mots que vous choisissez,
regarder si des mots sont présents par hasard. Le programme indique les mots présents.
Attention, les lettres du mot peuvent être consécutives mais il est plus probable qu’elles
soient  dispersées. En revanche vous considérerez qu’elles doivent arriver dans l’ordre.
Par exemple le mot TATA est dans la ligne ci-dessous :
resdarTferdorAafdcvmTnfertuhgfdsqArfdyui
Pour l'affichage utilisez les fonctions fournies en annexe.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define TX  20
#define TY  10

void lettre(int x, int y, int l, int color);
void textcolor(int color);
void gotoxy(int x, int y);

int main()
{
char mat[TY][TX];
char mot[20],joue='o',trouve;
int x,y,k,nbl,color;

    srand(time(NULL));

    while(joue=='o'){
        // initialisation matrice avec des lettres + affichage
        for(y=0; y<TY; y++)
            for (x=0; x<TX; x++){
                mat[y][x]='a'+rand()%26;
                lettre(x,y,mat[y][x],15);
            }

        // recherche de mots dedans
        trouve='o';
        while(trouve=='o'){
            // entrée d'un mot par l'utilisateur (plus pratique qu'une liste figée)
            gotoxy(0,TY+1);
            textcolor(15);
            printf("entrer un mot : ");
            scanf("%s",mot);
            rewind(stdin);

            // recherche du mot dans la matrice
            nbl=strlen(mot);
            color=1;
            for(k=0,y=0; y<TY; y++)
                for (x=0; x<TX; x++){
                    if(mat[y][x]==mot[k]){
                        lettre(x,y,mat[y][x],color);
                        k=(k+1)%nbl;
                        if(k==0)
                            color++;
                    }
                }
            gotoxy(0,TY+2);
            textcolor(10);
            printf("mot %s est trouve %d fois",mot,color-1);

            gotoxy(0,TY+3);
            textcolor(10);
            printf("autre mot ? (o/n)");
            scanf("%c",&trouve);
            rewind(stdin);

            // effacer texte précédent
            gotoxy(0,TY+1);
            textcolor(0);
            for(x=0; x<3; x++)
                printf("%70s\n"," ");
        }
        gotoxy(0,TY+4);
        textcolor(15);
        printf("autre test ? (o/n)");
        scanf("%c",&joue);
        rewind(stdin);

        gotoxy(0,TY+4);
        textcolor(0);
        printf("%70s\n"," ");
        printf("%70s"," ");
    }
    textcolor(15);
    return 0;
}

void lettre(int x, int y, int l, int color)
{
    gotoxy(x,y);
    textcolor(color);
    putchar(l);
}

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
//
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
/*********************************
Exercice 7
Dans un programme faire deux listes de mots. Choisir aléatoirement des mots dans ces
deux listes sélectionnées aléatoirement également et les recopier les uns à la suite des
autres dans une matrice de lettres. Parcourir ensuite la matrice et pour chaque mot retrouvé
dire s’il fait parti de la liste 1 ou de la liste 2 et reconstituez l'alternance du tirage
entre les deux listes.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

#define TX  20
#define TY  10

void textcolor(int color);
void gotoxy(int x, int y);


int main()
{
// deux listes de chaines de caractères (mots à trouver)
char L[2][26][20]={
    {"Aaaa","Bbbbbb","Cccccccc","Dddd","Eeeeeeeeeeeee",         // liste 1
     "Ffffff","Ggggggg","Hhhhh","Iiiiii","Jjjjjjjj","Kkkkkk",
     "Lllllll","Mmmmmm","Nnnnnn","Ooooo","Ppppppp","Qqqqqqq",
     "Rrrrr","Ssssssssss","Ttttttt","Uuuuuu","Vvvvvv","Wwwwww",
     "Xxxxxx","Yyyyyyyyyyyy","Zzzzzzzz"},
    {"aaaaaaaaaa","bbbbbb","ccccccc","dddd","eee","ffffff","gggg",// liste 2
    "hhhhhh","iiiii","jjj","kkkk","lllll","mmmmmm", "nnnnnnn","oo",
    "ppp","qqqqq","rrrrrr","sssssss","tttttttt","uuuuuuuuu","vvvv",
    "wwwww","xxx","yyyyy","zzzzzz"}
};
// la matrice de lettres
char mat[TY][TX];

// mot tiré
char mot[20];

char joue='o';
int x,y,i,l,m,cmpt;

    while (joue=='o'){

        textcolor(7);
        x=y=0;
        do{
            // 1 tirer un mot d'une des deux listes
            strcpy(mot,L[rand()%2][rand()%26]);

            // 2 copier le mot dans la matrice
            for(i=0; i<strlen(mot)+1;i++,x++){
                if(x>=TX){
                    x=0;
                    y++;
                    if(y>=TY)
                        break;
                }
                mat[y][x]=mot[i];
                gotoxy(x,y);
                putchar(mat[y][x]);
            }

        }while(y<TY);

        // analyse et reconstitution du tirage

        // 1) récupérer chaque mot
        cmpt=i=x=y=0;
        do{
            mot[i]=mat[y][x++];
            if(x>=TX){
                x=0;
                y++;
            }
            if (mot[i]=='\0'){
                // affichage des mots récupérés pour contrôle
                gotoxy(TX+4,cmpt);
                textcolor(0);
                printf("%50s"," ");
                gotoxy(TX+4,cmpt);
                textcolor(12);
                printf("%s",mot);

                // Maintenant qu'un mot est trouvé chercher à quelle liste il appartient
                // le résultat est stocké est affiché à côté du mot trouvé
                textcolor(13);
                for(l=0; l<2; l++)
                    for(m=0; m<26; m++)
                        if(strcmp(mot,L[l][m])==0)
                            printf(" : liste %d, mot %d",l+1,m+1);

                // pour la recherche du mot suivant
                cmpt++; // incrémentation compteur de mot
                i=0;    // réinitialisation indice pour le buffer mot
            }
            else
                i++;

        }while(y<TY);

        // effacement résidu liste précédente si liste plus courte
        textcolor(0);
        for(i=0; i<10; i++){
            gotoxy(TX+4,cmpt+i);
            printf("%50s"," ");
        }

        // suite test
        gotoxy(0,TY+2);
        textcolor(15);
        printf("autre test ? (o/n)");
        scanf("%c",&joue);
        rewind(stdin);
    }
    return 0;
}

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
//
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
/************************************************
*                                               *
*  Image, terrain de jeux                       *
*                                               *
************************************************/


/*********************************
Exercice 8
Dans un nouveau programme, déclarer une matrice de 10 lignes par 20 colonnes.
Nous allons considérer cette matrice comme une image en 256 couleurs, c'est à
dire pour laquelle il y a un maximum de 256 couleurs.

1) Remplir l'image avec des valeurs aléatoires comprises entre 0 et 255 (bornes comprises)

2) Afficher cette image à l’écran en respectant son aspect rectangulaire. Vous pouvez utiliser
la fonction gotoxy() et les fonctions pour la couleur fournies en annexe.

3) Calculer de l'histogramme de l'image.
L’histogramme d’une image étudie la répartition statistique de chaque valeur de  couleur dans
une image en 256 couleurs. Son principe consiste, dans un tableau histogramme de 256 cases de
type entier, à compter combien l’image contient de pixels de la couleur 0 et à stocker cette
valeur dans la case 0 du tableau histogramme, puis combien l’image contient de pixels de
couleur 1 à ranger le nombre obtenu dans la case 1 du tableau histogramme ... ainsi de suite
pour toutes les couleurs jusqu'à la couleur 255 comprise.
Une fois l'histogramme calculé, afficher le résultat de manière lisible à l’écran.

4) Binarisation de l'image
La binarisation d’une image consiste, dans une image secondaire afin de ne pas modifier
l’image originale, à mettre à 0 tous les pixels de l’image originale inférieurs à une
valeur seuil entrée par l’utilisateur, et à mettre à 255 tous les pixels de l’image
originale supérieurs ou égaux à cette valeur seuil. Une fois cette opération effectuée
afficher le résultat.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TY 10
#define TX 20

void affiche_lettre(int x, int y, int lettre, int color);
void textcolor(int color);
void gotoxy(int x, int y);
int wherey(void);   // retourne la position verticale du curseur

int main()
{
int mat[TY][TX];
int copie[TY][TX];
int histo[256]={0};
int x,y,seuil,pos;

    // initialisation et affichage
    for (y=0; y<TY; y++)
        for(x=0; x<TX; x++){
            mat[y][x]=rand()%255;
            affiche_lettre(x,y,'*',mat[y][x]);
        }
        // remarque : la couleur est codée sur un octet avec les quatre
        // premiers bits pour la couleur de la lettre et les quatre suivants
        // pour la couleur du fond. Il y a 16 couleurs en tout en mode console.
        // Ainsi les valeurs de 0 à 255 correspondent à deux couleurs, une pour
        // le fond et une pour la lettre


    // histogramme
    for(y=0; y<TY; y++)
        for(x=0; x<TX; x++)
            histo[mat[y][x]]++;

    gotoxy(0,TY+1);
    textcolor(15);

    for (y=0; y<256; y++)
        printf("couleur %3d : %3d\n",y,histo[y]);

    printf("Binarisation de l'image :\n");
    printf("entrer une valeur de seuil : ");
    scanf("%d",&seuil);
    rewind(stdin);

    memcpy(copie,mat,sizeof(int)*TX*TY);
    pos=wherey()+1;
    for (y=0; y<TY; y++)
        for(x=0; x<TX; x++){
            copie[y][x]=(mat[y][x]<=seuil)? 0 : 255;
            affiche_lettre(x,pos+y,'*',copie[y][x]);
        }

    putchar('\n');
    textcolor(15);
    return 0;
}
void affiche_lettre(int x, int y, int lettre, int color)
{
    gotoxy(x,y);
    textcolor(color);
    putchar(lettre);
}
void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
int wherey()
{
CONSOLE_SCREEN_BUFFER_INFO info;
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
   GetConsoleScreenBufferInfo(h,&info);
   return info.dwCursorPosition.Y;
}
/*********************************
Exercice 9
Dans un jeu vidéo, la technique du "tile map" sert à construire des terrains de jeu,
des paysages ou différents levels. Le principe est simple. A la base on a des petites
images élémentaires : par exemple gazon, mur, eau, feu. Chaque petite image correspond
à un numéro, par exemple 0 pour gazon, 1 pour mur, 2 pour eau, 3 pour feu. Ensuite
dans une matrice  est réalisé un dessin à partir de ces nombres. Dans le jeu lorsque
le terrain est appelé, l'image est construite à partir de la matrice et affichée à l'écran.
Initialisez une matrice de façon à faire un terrain de jeu de 10 par 15.
Affichez votre terrain avec la fonction gotoxy() et les fonctions pour la couleur
fournies en annexe
placez des objets de façon aléatoire sur votre terrain. Les objets ne peuvent pas être
sur les murs, ils ne peuvent être posés que sur le gazon. Attention, les objets ne sont
pas stockés dans la matrice du terrain de jeu. Ensuite affichez ces objets
après un temps qui lui est propre chaque objet change de place. Dans une boucle
d'évènements,  faites changer de place les objets chacun à son rythme.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// Remarque / ERRATUM :
//
// les deux matrices sont déclarées en globale c'est à dire en dehors du main
// et en dehors de toute fonction en haut du fichier. Le fait que ces matrices
// soient "globales" signifie qu'elles sont accessibles de partout dans le
// fichier. C'est à dire que les fonctions peuvent y accéder sans les avoir
// en paramètre. Ce point est détaillé en G. Tableaux et fonction page 195.
//
// en faisant le corrigé de l'exercice j'ai décidé d'utiliser cette propriété
// en avance sur le cours, afin que le programme soit mieux structuré.
// Pour cette raison cet exercice gagne à être déplacé en chap3_G5
//

// La matrice terrain
#define TX  15
#define TY  10
enum{GAZON,MUR,EAU,FEU}; // correspond aux indices 0,1,2,3
int TER[TY][TX]={
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,3,3,3,0,0,0,0,0,1,
    1,0,0,2,2,0,0,0,0,0,0,0,3,3,1,
    1,0,0,2,2,2,2,2,0,0,0,0,3,0,1,
    1,0,0,0,0,0,0,2,2,2,0,0,0,0,1,
    1,0,0,0,0,0,0,2,2,2,0,0,0,0,1,
    1,0,3,3,0,0,0,0,0,0,0,3,0,0,1,
    1,0,3,3,0,0,0,0,0,0,0,3,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,3,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};
// une matrice pour stocker les objets
// la valeur de chaque objet correspond à un nombre de tours
int OBJ[TY][TX]={0};

// les déclarations des fonctions
void    affiche_terrain     (void);
void    affiche_lettre      (int x, int y, int lettre, int color);
void    place_all_objet     (void);
void    place_objet         (void);
void    affiche_all_objet   (void);
void    cntl_objet          (void);
void    attendre            (int duree);
void    textcolor           (int color);
void    gotoxy              (int x, int y);

int main()
{
    srand(time(NULL));
    affiche_terrain();
    place_all_objet();
    affiche_all_objet();

    while(!kbhit()){

        cntl_objet();
        attendre(20);
    }
    textcolor(15);
    gotoxy(0,TY+2);
    return 0;
}

void affiche_terrain()
{
int x,y;
    for (y=0; y<TY; y++)
        for (x=0; x<TX; x++)
            switch(TER[y][x]){
                case GAZON : affiche_lettre(x, y, ' ', 10*16);    break;
                case EAU   : affiche_lettre(x, y, ' ', 11*16);    break;
                case FEU   : affiche_lettre(x, y, ' ', 14*16);    break;
                case MUR   : affiche_lettre(x, y, ' ', 7*16);     break;
            }
}

void place_all_objet()
{
int nbobjet;
    nbobjet=3+rand()%8; // entre 3 et 10
    while(nbobjet--)
        place_objet();
}

void place_objet()
{
int x,y;
    // remarque les objets ne  peuvent être que sur GAZON

    x=rand()%TX;    // position au hasard dans la zone
    y=rand()%TY;
    while(TER[y][x]!=GAZON || OBJ[y][x]>0){ // trouver une position GAZON sans objet
        if(rand()%2)
           x=(x+1)%TX;
        else
           y=(y+1)%TY;
    }
    OBJ[y][x]=10+rand()%100; // l'objet correspond à un temps en nombre de tours
}

void affiche_all_objet()
{
int x,y;

    for (y=0; y<TY; y++)
        for (x=0; x<TX; x++)
            if(OBJ[y][x])
                affiche_lettre(x, y,'O', 12+10*16);

}

void cntl_objet()
{
int x,y;
    for(y=0; y<TY; y++)
        for (x=0;x<TX; x++)
            if (OBJ[y][x]>1)
                OBJ[y][x]--;
            else if(OBJ[y][x]==1){
                OBJ[y][x]=0;
                affiche_lettre(x, y, ' ', 10*16); // efface l'objet avec couleur GAZON
                place_objet();
                affiche_all_objet();  // réaffiche les objets
            }
}

void affiche_lettre(int x, int y, int lettre, int color)
{
    gotoxy(x,y);
    textcolor(color);
    putchar(lettre);
}

void attendre(int duree)
{
int start=clock();
    while(clock()<start+duree){}
}

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}

void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
/*********************************
Exercice 10
Bientôt Noël peut-être ? Fabrication de guirlandes électriques clignotantes pour sapin.
Faire un programme qui simule une guirlande électrique avec plusieurs lampes de couleurs
différentes.
*

// Remarque / ERRATUM : comme pour exercice 9
//
// les tableaux sont déclarés en globale c'est à dire en dehors du main
// et en dehors de toute fonction en haut du fichier. Le fait que ces tableaux
// soient en "globale" signifie qu'ils sont accessibles de partout dans le
// fichier. C'est à dire que les fonctions peuvent y accéder sans les avoir
// en paramètre. Ce point est détaillé en G. Tableaux et fonction page 195.
//
// en faisant le corrigé de l'exercice j'ai décidé d'utiliser cette propriété
// en avance sur le cours, afin que le programme soit mieux structuré.
// Pour cette raison cet exercice gagne à être déplacé en chap3_G5
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// la zone
#define TX  80
#define TY  24
// la guirlande
#define MAXAMPOULES  80  // nombre d'ampoules au plus
int X[MAXAMPOULES];      // les coordonnées des chaque ampoule
int Y[MAXAMPOULES];
int C[MAXAMPOULES];      // la couleur pour chaque ampoule

 enum{EFFACE,COLOR};

void    init_guirlande      (void);
void    affiche_guirlande   (int color,int speed);
void    anime_guirlande     (void);
void    affiche_lettre      (int x, int y, int lettre, int color);
void    textcolor           (int color);
void    gotoxy              (int x, int y);
void    attendre            (int duree);

int main()
{
int fin=0;

    srand(time(NULL));
    printf("presser :\n"
           " - une touche pour nouvelleqqqq guirlande\n"
           " - q pour quitter\n");

    init_guirlande();

    while(fin!='q'){

        if(kbhit()){
            fin=getch();
            if(fin != 'q'){
                affiche_guirlande(EFFACE,0);
                init_guirlande();
            }
        }
        anime_guirlande();
        affiche_guirlande(COLOR,10+rand()%90);
    }
    textcolor(15);
    gotoxy(0,TY+2);
    return 0;
}

void init_guirlande()
{
int i,j,dir,rotat,nb;

    // Principe pour la construction :
    // la guirlande va du bord gauche vers le bord droit en avançant par segment
    // d'au moins 3 cases en montant (0), avançant (1 et 3) ou descendant(2).
    // Chaque montée ou descente est suivie d'une avance horizontale,
    // soit des séquences :
    //      avancer de n1, monter de n2, avancer de n3,descendre de n4 etc.  :
    //      A - M - A - D - A - M - ...
    // Mais au départ ça peut être A, M ou D, la suite s'organise en fonction

    // Algorithme :
    // 1) choisir direction au départ
    dir=rand()%4;

    // 2)choisir sens rotation
    rotat=rand()%2*2-1; // -1 ou 1

    // 3) créer segments
    // le premier est au milieu du bord gauche
    X[0]=0;
    Y[0]=TY/2;
    C[0]=(rand()%15)+1;

    for (i=1; i<MAXAMPOULES; i=j ){
        nb=2+rand()%7;          // entre 2 et et 8 en plus de la position courante
        for(j=i; j<i+nb && j<MAXAMPOULES; j++){  // pour chaque ampoule du segment courant
                                                 // attention à respecter la taille des tableaux
            C[j]=rand()%15+1;   //Choisir une couleur

            switch(dir){
                case 0 :        // Monter
                    X[j]=X[j-1];
                    Y[j]=Y[j-1]-1;
                    break;

                case 2 :        // Descendre
                    X[j]=X[j-1];
                    Y[j]=Y[j-1]+1;
                    break;

                case 1 :        // Avancer
                case 3 :
                    X[j]=X[j-1]+1;
                    Y[j]=Y[j-1];
                    break;
            }
        }
        dir= ((dir+rotat)+4)%4;
    }
    // finir s'il reste des ampoules
}

void affiche_guirlande(int color, int speed) // 0 pour non 1 pour oui
{
int i;
    for (i=0; i<MAXAMPOULES; i++){
        affiche_lettre(X[i],Y[i],' ',C[i]*16*color);
        attendre(speed);
    }
}

void anime_guirlande() // fait varier les couleurs
{
int i,c;
    if(rand()%2){ // si oui, chaque ampoule change de couleur
        for (i=0; i<MAXAMPOULES; i++){
            C[i]=(C[i]+1)%16;
            if(C[i]==0)
                C[i]=1 ;
        }
    }
    else{ // si non les couleurs tournent d'une ampoule à l'autre
        c=C[MAXAMPOULES-1];
        for (i=MAXAMPOULES-1;i>0; i-- )
            C[i]=C[i-1];
        C[0]=c;
    }
}

void affiche_lettre(int x, int y, int lettre, int color)
{
    if(x>=0 && y>=0 && x<TX &&y<TY){ // cequi sort du cadre n'est pas affiché
        gotoxy(x,y);
        textcolor(color);
        putchar(lettre);
    }
}

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}

void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}

void attendre(int duree)
{
int start=clock();
    while(clock()<start+duree){}
}

/*********************************
Exercice 11
Une quinzaine de petits carrés (obtenus avec l’affichage d’un espace pour lequel la
couleur de fond est spécifiée ) se déplacent à des vitesses différentes dans un
espace strictement délimité. Lorsqu’ils arrivent sur un bord ils rebondissent et
partent dans une autre direction.
*

// Remarque / ERRATUM : comme pour exercices 9 et 10
//
// les tableaux sont déclarés en globale c'est à dire en dehors du main
// et en dehors de toute fonction en haut du fichier. Le fait que ces tableaux
// soient en "globale" signifie qu'ils sont accessibles de partout dans le
// fichier. C'est à dire que les fonctions peuvent y accéder sans les avoir
// en paramètre. Ce point est détaillé en G. Tableaux et fonction page 195.
//
// en faisant le corrigé de l'exercice j'ai décidé d'utiliser cette propriété
// en avance sur le cours, afin que le programme soit mieux structuré.
// Pour cette raison cet exercice gagne à être déplacé en chap3_G5
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// la zone
#define TX  80
#define TY  24
// les carrés
#define NBMAX  20    // nombre de carrés au plus
float X[NBMAX];      // les coordonnées des carrés
float Y[NBMAX];
float DX[NBMAX];     // les déplacements des carrés
float DY[NBMAX];

enum{EFFACE,COLOR};

void    init                (void);
void    affiche             (int color);
void    move                (void);
void    affiche_lettre      (int x, int y, int lettre, int color);
void    textcolor           (int color);
void    gotoxy              (int x, int y);
void    attendre            (int duree);

int main()
{
    init();
    while(!kbhit()){
        affiche(EFFACE);
        move();
        affiche(COLOR);
        attendre(70);
    }
    textcolor(15);
    gotoxy(0,TY+2);
    return 0;
}

void init()
{
int i;
    for (i=0; i<NBMAX; i++){
        X[i]= rand()%TX;
        Y[i]= rand()%TY;
        DX[i]=((float)rand()/RAND_MAX)*4-2;
        DY[i]=((float)rand()/RAND_MAX)*4-2;
    }
}

void affiche(int color)
{
int i;
    for (i=0; i<NBMAX; i++)
        affiche_lettre(X[i],Y[i],' ',(14<<4)*color);
}

void move()
{
int i;
float x,y;

    for (i=0; i<NBMAX; i++){
        x=X[i]+DX[i];
        if (x<0 ||x>=TX){ // contrôle des bords
            DX[i]*=-1; // changement de direction
            x=(x<0)?0:((x>=TX)? TX-1:x);
        }
        y=Y[i]+DY[i];
        if (y<0 ||y>=TY){
            DY[i]*=-1;
            y=(y<0)?0:((y>=TY)?TY-1:y);
        }
        X[i]=x;
        Y[i]=y;
    }
}

void affiche_lettre(int x, int y, int lettre, int color)
{
    gotoxy(x,y);
    textcolor(color);
    putchar(lettre);
}

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}

void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}

void attendre(int duree)
{
int start=clock();
    while(clock()<start+duree){}
}
/*********************************
Exercice 12
Dans un terrain construit à partir d'une matrice déplacer un player. Le player
respecte les murs. S'il y a des objets sur le terrain le player les ramasse et
marque des points.
*

// Remarque / ERRATUM : comme pour exercices 9, 10, 11
//
// les tableaux sont déclarés en globale c'est à dire en dehors du main
// et en dehors de toute fonction en haut du fichier. Le fait que ces tableaux
// soient en "globale" signifie qu'ils sont accessibles de partout dans le
// fichier. C'est à dire que les fonctions peuvent y accéder sans les avoir
// en paramètre. Ce point est détaillé en G. Tableaux et fonction page 195.
//
// en faisant le corrigé de l'exercice j'ai décidé d'utiliser cette propriété
// en avance sur le cours, afin que le programme soit mieux structuré.
// Pour cette raison cet exercice gagne à être déplacé en chap3_G5
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

// la zone
#define TX    40  // taille zone de jeu en x
#define TY    20  //          "         en y
#define BORD   1   // dans la matrice signifie 1 bord
#define MUR    2   // dans la matrice signifie 1 mur

int TER[TY][TX]={
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,2,2,2,2,2,2,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,2,0,0,0,0,0,0,0,0,0,0,2,2,2,0,0,2,2,2,2,0,0,2,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,2,2,0,0,2,2,0,0,2,2,2,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,2,2,2,2,2,2,2,0,0,2,0,0,0,0,0,0,0,0,0,2,2,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,2,2,2,2,0,0,0,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

// la guirlande
#define PLAYER  10    // nombre d'objet et indice du player
int X[PLAYER+1];      // les coordonnées des objets et du player
int Y[PLAYER+1];

// pour un affichage décalé en (5,5)
#define DECX  5   // décalage par rapport au bord gauche
#define DECY  3   // décalage par rapport au bord haut

void    init_terrain        (void);
void    init_all_acteurs    (void);
void    trouve_pos          (int id);
void    affiche_lettre      (int x, int y, int lettre, int color);
void    textcolor           (int color);
void    gotoxy              (int x, int y);
void    fill_console        (char asciiChar, int color);
COORD   coord               (int x, int y);
void    clear_console       (void);

int main()
{
int fin=0;

    srand(time(NULL));
    init_terrain();
    init_all_acteurs();
    while(!fin){
       if(kbhit())
            fin=run();

    }
    textcolor(15);
    gotoxy(0,DECY+TY+2);
    return 0;
}
//
void init_terrain(){
int x,y,color,lettre;
   for (y=0; y<TY; y++)
      for (x=0; x<TX; x++){
         if(TER[y][x]==BORD){
            color=9;
            lettre='A'+rand()%26;
         }
         else if(TER[y][x]==MUR){
            color=12<<4;
            lettre=' ';
         }
         else{  // gazon, 0
            TER[y][x]=color=0;
            lettre=' ';
         }
         affiche_lettre(x,y,lettre,color);
    }
}
//
void trouve_pos(int id)
{
    // on prend une position au hasard dans la matrice
   X[id]=rand()%TX;
   Y[id]=rand()%TY;
   // si on tombe sur un bord ou sur un mur ou une autre entité on se déplace
   // jusqu'à rencontrer une position libre
   while (TER[Y[id]][X[id]]!=0){
      if (rand()%2)
         X[id]=(++X[id])%TX;
      else
         Y[id]=(++Y[id])%TY;
   }
}
//
void init_all_acteurs()
{
int i;

   // 1 initialisation des objets
   for (i=0;i<PLAYER; i++){

      trouve_pos(i);
      // marquer en négatif dans la matrice la position occupée par la salade i
      // (attention pour i==0)
      TER[Y[i]][X[i]]=-(i+10);
      // afficher à l'écran avec une lettre et une couleur aléatoires
      affiche_lettre(X[i],Y[i],'a'+rand()%26,1+rand()%255);
   }
   // 2 initialisation player
   trouve_pos(PLAYER);
   affiche_lettre(X[PLAYER],Y[PLAYER],'P',10);
}
//
int run()
{
static int score=0;
int px,py,touche,res=0;
char msg[80];

   px=X[PLAYER];
   py=Y[PLAYER];

   touche=getch();
   switch(touche){
      // touche escape, indique si fin du programme ou pas
      case 27 :
         res=1;
         break;
      // touche enter : réinitialise la partie
      case 13 :
         score=0;
         textcolor(0);
         clear_console();
         init_terrain();
         init_all_acteurs();
         break;
      // mouvements du player
      // pour chaque direction vérifier que l'on reste dans la matrice, que la
      // nouvelle position est libre (pas de mur) ou contient une salade (valeur
      // négative
      case 72 : //flèche haut
          if (py-1>=0 && TER[py-1][px]<=0)
             py--;
          break;
       case 80 ://flèche bas
          if (py+1<TY && TER[py+1][px]<=0)
            py++;
          break;
       case 77 ://flèche droite
          if (px+1<TX && TER[py][px+1]<=0)
            px++;
          break;
       case 75 : //flèche gauche
          if (px-1>=0 && TER[py][px-1]<=0)
             px--;
          break;
       default : break;
   }
   // si touche différente de enter et mouvement (réinitialisation du player
   // à une nouvelle position
   if (touche!=13 && (px!=X[PLAYER]||py!=Y[PLAYER])){
      // effacement coordonnées courantes
      affiche_lettre(X[PLAYER],Y[PLAYER],'P',0);
      // prise nouvelles coordonnées
      X[PLAYER]=px;
      Y[PLAYER]=py;
      // affichage nouvelles oordonnées
      affiche_lettre(X[PLAYER],Y[PLAYER],'P',10);
      // mise à jour si objet
      if (TER[Y[PLAYER]][X[PLAYER]]<0){
         TER[Y[PLAYER]][X[PLAYER]]=0;

         gotoxy(DECX,DECY/2);
         textcolor(12);
         printf("trouve objet : %d",++score);

         if (!(score%PLAYER)){ // tous les objets trouvés
            gotoxy(DECX,DECY/2+1);
            textcolor(15);
            printf("Plus d'objet... enter pour rab");
         }
      }
   }
   return res;
}
//
void affiche_lettre(int x, int y, int lettre, int color)
{
    gotoxy(x+DECX,y+DECY);
    textcolor(color);
    putchar(lettre);
}
//
void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
//
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
//
//fill_console fonction
//Remplit la fenêtre avec le caractère et la couleur _fond et
//face à la fois _spécifiés.
//
void fill_console(char asciiChar, int color)
{
HANDLE hstd=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO info;
static CHAR_INFO*dat=NULL;
static int w=0;
static int h=0;
static SMALL_RECT bRect;
int x,y;

	if (!GetConsoleScreenBufferInfo(hstd,&info)){
		printf("[fill_console]GetConsoleScreenBufferInfo");
		return;
	}

	// n'est refait qu'à chaque changement
	if (info.dwSize.X!=w || info.dwSize.Y!=h){
		w=info.dwSize.X;
		h=info.dwSize.Y;
		dat=(CHAR_INFO*)malloc(sizeof(CHAR_INFO)*w*h);

		bRect.Left = 0;
		bRect.Top = 0;
		bRect.Right = w-1;
		bRect.Bottom = h-1;
	}

	if ( color == 0 )
		memset(dat,0,sizeof(CHAR_INFO)*w*h);
	else{
		for (y=0; y<h; y++)
			for (x=0; x<w ; x++){
				dat[y*w+x].Attributes=color;
				dat[y*w+x].Char.AsciiChar = asciiChar;
				dat[y*w+x].Char.UnicodeChar = asciiChar;
			}
	}

	if (! WriteConsoleOutput(hstd,          // console active cible
                         dat,			 // les datas src à afficher
                         coord(w,h),	 // sa taille
                         coord(0,0),	 // coin src départ
                         &bRect) )		 // rect de destination
		printf("[fill_console]WriteConsoleOutput");

}
//
// initialise une structure COORD
//
COORD coord(int x, int y)
{
COORD c;
   c.X=x;
   c.Y=y;
   return c;
}
//
//clear_console fonction
//efface la console en noir
//
void clear_console()
{
	fill_console(0,0);
}
/*********************************
Exercice 13
Dans un zone de jeu, une chenille avance pilotée par les touches flèche. Elle
s'allonge de un tous les 5 tours. Faire le programme. Si ce n'est pas fait,
compléter le programme de façon à ce qu'elle ne puisse pas se marcher dessus.
*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define TX  80        // taille zone jeu
#define TY  20
#define MAX TX*TY    // taille chenille

void affiche_lettre(int x, int y, int l, int color);
void textcolor(int color);
void gotoxy(int x, int y);

int main()
{
// chaque paire de pied correspond à un indice, la tete est à l'indice 0
int xx[TX*TY];      // coordonnées horizontales pieds chenille
int yy[TX*TY];      // coordonnées verticales pieds chenille
int dern=2;      // indice du dernier pied après la tête (tete en 0)
int P[TY][TX];   // zone de jeu
int nbtours=0;     // pour compter les tours

int fin=0,x,y,i,clav,res;

    srand(time(NULL));

    // initialisation
    xx[0]=TX/2; // tete
    yy[0]=TY/2;
    affiche_lettre(xx[0],yy[0],'C',10);
    for (i=1; i<=dern; i++){ // corps
        xx[i]=xx[i-1]+1;
        yy[i]=yy[i-1];
        affiche_lettre(xx[i],yy[i],'C',12);
    }

    while(!fin){
        if(kbhit()){
            clav=getch();
            if(clav!=224){ // évacuer le code 224 nécessaire au touches flèches
                x=xx[0];
                y=yy[0];

                switch(clav){
                    case 72 :   y--;   break;  // haut
                    case 77 :	x++;	break;	// droite
                    case 80 :	y++;	break;	// bas
                    case 75 :	x--;	break;	// gauche
                    default :   fin=1;  break;  // autre touche : met fin au prg
                }
                // contrôler les bords
                if (x<0)
                    x=0;
                if (x>=TX)
                    x=TX-1;
                if (y<0)
                    y=0;
                if (y>=TY)
                    y=TY-1;
                // est ce que la chenille se marche dessus ?
                for(i=1,res=0; i<=dern && !res; i++){
                    if(xx[i]==x&&yy[i]==y)
                        res=1;
                }

                // si mouvement et que la chenille ne se marche pas dessus
                if ((x!=xx[0]||y!=yy[0])&& !res){

                    // le nombre de tours augmente
                    nbtours=(nbtours+1)%5;
                    if (nbtours!=4)
                        // effacer uniquement la derniere position
                        affiche_lettre(xx[dern],yy[dern],'C',0);
                    else
                        // allongement de la chenille si possible
                        if (dern<MAX-1)
                            dern++;

                    // chaque position récupère les coordonnées de la position précédente
                    for (i=dern; i>0; i--){
                        xx[i]=xx[i-1];
                        yy[i]=yy[i-1];
                    }
                    // la première position prend les coordonnées de la tête
                    xx[0]=x;
                    yy[0]=y;

                    // affichage de la tête et seconde (couleur)
                    affiche_lettre(xx[0],yy[0],'C',10);
                    affiche_lettre(xx[1],yy[1],'C',12);
                }
            }
        }
    }
    return 0;
}
void affiche_lettre(int x, int y, int l, int color)
{
    gotoxy(x,y);
    textcolor(color);
    putchar(l);
}

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
//
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}

/*********************************
Exercice 14
En utilisant la fonction gotoxy() faire un programme de neige qui tombe de
haut en bas de l’écran. Trouver une solution pour l’arrivée des flocons :
est ce qu’ils fondent ? est ce qu’ils s’accumulent ? Si oui jusqu’où ? …
*

// Remarque / ERRATUM : comme pour exercices 9, 10, 11, 12
//
// les tableaux sont déclarés en globale c'est à dire en dehors du main
// et en dehors de toute fonction en haut du fichier. Le fait que ces tableaux
// soient en "globale" signifie qu'ils sont accessibles de partout dans le
// fichier. C'est à dire que les fonctions peuvent y accéder sans les avoir
// en paramètre. Ce point est détaillé en G. Tableaux et fonction page 195.
//
// en faisant le corrigé de l'exercice j'ai décidé d'utiliser cette propriété
// en avance sur le cours, afin que le programme soit mieux structuré.
//
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define TX  80        // taille zone jeu
#define TY  24

float Y[TX];    // les flocons descendent
float DY[TX];
int L[TX];   // chacun correspond à une lettre

// pour gérer l'accumulation des flocons, ils sont dans une matrice
// et s'accumulent en bas. Chaque ligne compléte de flocon est supprimée
// un peu comme dans un tétris
int TER[TY][TX]={{0}};

void    init_flocon         (int id);
void    init_all_flocons    (void);
void    move_flocon         (int id);
void    move_all_flocons    (void);
void    supp_ligne_bas      (void);
void    affiche_lettre      (int x, int y, int l, int color);
void    textcolor           (int color);
void    gotoxy              (int x, int y);
void    attendre            (int duree);

int main()
{
    srand(time(NULL));
    init_all_flocons();
    while(!kbhit()){
        move_all_flocons();
        attendre(50);
        supp_ligne_bas();
    }
    return 0;
}

void init_flocon(int id)
{
    Y[id]=0;
    DY[id]=((float)rand()/RAND_MAX)*2; // entre 0 et 2
    if(DY[id]<0.1)
        DY[id]=0.1;
    L[id]=rand()%26+((rand()%2)?'a':'A');
}

void init_all_flocons()
{
int i;
    for (i=0; i<TX; i++){
        init_flocon(i);
        affiche_lettre(i,0,L[i],15);
    }
}

void move_flocon(int id)
{
float y;

    affiche_lettre(id,Y[id],L[id],0); //affiche en noir

    y=Y[id]+DY[id];
    if((int)y>TY-1 || TER[(int)Y[id]+1][id]>0 ){
       // solution avec un petit quelque chose de réaliste
       y=((int)y>TY-1) ? TY-1 : y;
       //la solution ci-dessous donne un empilement plus rigoureux
       //mais moins réaliste (cause DX[id] peut être supérieur à 1)
       //y=((int)y>TY-1) ? TY-1 :(int)Y[id] ;

       // dans les deux cas des colonnes finissent par se former
       // qu'il et possible de compenser avec un mécanisme supplémentaire
       // (que je ne fais pas ici)
       TER[(int)y][id]=L[id];
       init_flocon(id);
    }
    else
        Y[id]=y;

    affiche_lettre(id,y,L[id],15); // affiche en blanc
}

void move_all_flocons()
{
int i;
    for (i=0; i<TX; i++)
        move_flocon(i);
}

void supp_ligne_bas()
{
int i,y,x,cmpt;
    for (i=0,cmpt=0; i<TX; i++)
        if(TER[TY-1][i]>0)
            cmpt++;
    if(cmpt>=TX/10*9){// si toutes les postions du bas sont occupées
        // parcourir les sommets
        for (x=0; x<TX; x++)
            for (y=0; y<TY; y++)
                if(TER[y][x]>0){
                    affiche_lettre(x,y,' ',0); // effacer le sommet
                    TER[y][x]=0;
                    break; // uniquement le sommet, passer à la colone suivante
                }
    }
}

void affiche_lettre(int x, int y, int l, int color)
{
    gotoxy(x,y);
    textcolor(color);
    putchar(l);
}

void gotoxy(int x, int y)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(h,c);
}
//
void textcolor(int color)
{
HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,color);
}
//
void attendre(int duree)
{
int start=clock();
    while(clock()<start+duree){}
}

/*****************************************************
*                                                    *
*  Localisation de données via plusieurs dimensions  *
*                                                    *
*****************************************************/


/*********************************
Exercice 15
Mesures dans un laboratoire. Afin d’étudier des effets d’une molécule un
laboratoire organise une expérience avec 150 personnes. Ces personnes sont
réparties en trois groupes de 50, l’expérience dure 3 mois avec une série
de mesures spécifiques pour chaque mois et pour chaque groupe :
Le groupe 1 sert de référence et ne reçoit pas de traitement.
Le groupe 2 reçoit un « placebo » sans principe actif biologiquement.
Le groupe 3 reçoit le principe actif
Il y a quatre mesures différentes toutes les 60 secondes, 24h sur 24h et
la date doit être conservée (mois, jours). Les mesures sont température,
taux de lymphocytes (globules blancs), taux d’hématies (globules rouges)
et temps exacte où la mesure est effectuée. Comment stocker les résultats ?
Faire le programme qui permet d'entrer chacune des mesures.
*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
// on a :
//3         50          3       24      60          3
//groupes   personnes   mois    heures  minutes    mesures
// structure de données possible :
//int mesures[3][50][3][24][60][3];
// avec 6 indices
int gr,pe,mo,he,mi;
enum{temp,lympho,hemat};

// mais ça ne marche pas en statique, parce que la tille du tableau
// est trop importante. Il faudrait un tableau dynamique (voir pointeurs)
// Pour voir et tester je diminue le nombre des personnes de 50 à 5
int mesures[3][5][3][24][60][3];

    memset(mesures,0,sizeof(int)*3*5*3*24*60*3); // mise à 0
    // pour la prise des mesures
    for (gr=0; gr<3; gr++)
        for (pe=0; pe<5; pe++)
            for (mo=0; mo<3; mo++)
                for(he=0; he<24; he++)
                    for (mi=0; mi<60; mi++){
                        printf("Groupe %d, personne %d, mois %d, "
                               "heure %d, minute %d\n",gr,pe,mo+1,he,mi);
                        printf("entrez les quatres mesures :\n");
                        printf("- temperature ");
                        scanf("%d",&mesures[gr][pe][mo][he][mi][temp]);
                        rewind(stdin);
                        printf("- lymphocite ");
                        scanf("%d",&mesures[gr][pe][mo][he][mi][lympho]);
                        rewind(stdin);
                        printf("- hematies ");
                        scanf("%d",&mesures[gr][pe][mo][he][mi][hemat]);
                        rewind(stdin);
                    }
    return 0;
}
/*********************************
*/

