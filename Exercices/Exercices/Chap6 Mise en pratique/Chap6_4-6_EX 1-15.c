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
*   Chapitre 6 : Les pointeurs											*
*   4.   Fichiers (type FILLE*)                                         *
*   4.6 Mise en pratique : fichiers                                     *
*************************************************************************

/*********************************
Exercice 1
Dans un programme ouvrir en lecture un fichier dont le nom est donné par
l'utilisateur.  Indiquer si l'opération a réussi. Si l'opération échoue,
le fichier n'existe pas, le créer et indiquer le résultat. Faire tourner
le programme une première fois, le fermer et le lancer une deuxième fois
pour vérifier que le fichier a bien été créé et s'ouvre correctement.
Allez sur le disque voir ou le fichier se trouve. Ne pas oublier dans
le programme de fermer le fichier quand il n'y a plus besoin de l'avoir ouvert.
*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void saisie(char*msg,char s[], int max)
{
    printf("%s",msg);
    fgets(s,max,stdin);
    s[strlen(s)-1]='\0';
    rewind(stdin);
}
int main()
{
char continuer='o';
char nom[256];
FILE*f;

    while(continuer=='o'){

        saisie("entrer le nom du fichier :\n",nom,256);
        if((f=fopen(nom,"r"))!=NULL)
            printf("fichier %s ouvert\n",nom);
        else{
            printf("fichier introuvable ou inexistant\n");
            if((f=fopen(nom,"w"))!=NULL)
                printf("creation du fichier\n");
            else
                printf("erreur creation du fichier\n");
        }
        if(f!=NULL)
            fclose(f);

        printf("continuer ? (o/n)");   // évite de ortir et relancer le programme
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*********************************
Exercice 2
Faire un programme qui ouvre ou crée un fichier dont le nom,
l'emplacement et le mode sont entrés par l'utilisateur. Ne pas
oublier de fermer le fichier lorsque ça a réussi et qu'un message
a été transmis à l'utilisateur.

*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void saisie(char*msg,char s[], int max)
{
    printf("%s",msg);
    fgets(s,max,stdin);
    s[strlen(s)-1]='\0';
    rewind(stdin);
}

int main()
{
char continuer='o';
char nom[256]={0};
char mode[16]={0};
char path[2048+256]={0};
FILE*f;

    while(continuer=='o'){
        saisie("entrer le nom du fichier   : ",nom,256);
        saisie("entrer l'emplacement       : ",path,2048);
        saisie("entrer le mode d'ouverture : ",mode,16);

        strcat(path,nom);

        if (strcmp(mode,"r")==0  || strcmp(mode,"r+")==0 ||
            strcmp(mode,"rb")==0 ||  strcmp(mode,"r+b")==0){
            if ((f=fopen(path,mode))!=NULL)
                printf("ouverture fichier existant reussie\n");
            else
                printf("fichier introuvable ou inexistant\n");
        }
        else if(strcmp(mode,"w")==0 || strcmp(mode,"w+")==0 ||
                strcmp(mode,"wb")==0|| strcmp(mode,"w+b")==0 ){
            if ((f=fopen(path,mode))!=NULL)
                printf("creation fichier reussie\n");
            else
                printf("creation fichier echoue\n");
        }
        else if (strcmp(mode,"a")==0 || strcmp(mode,"a+")==0 ||
                strcmp(mode,"ab")==0||strcmp(mode,"a+b")==0){
                if((f=fopen(path,mode))!=NULL)
                printf("ouverture ou creation fichier reussie\n");
            else
                printf("ouverture et creation fichier echoue\n");
        }
        else
        if(f!=NULL)
            fclose(f);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*********************************
Exercice 3
Un programme crée un fichier qui se trouve dans un dossier nommé
test dans le répertoire du programme. Vérifier que le fichier est
bien sur le disque dur. Modifier le programme pour ouvrir le fichier
en lecture uniquement et relancer le programme. ne pas oublier de fermer
le fichier.
*
#include <stdlib.h>
#include <stdio.h>

int main()
{
char continuer='o';
FILE*f;

    while(continuer=='o'){

        if((f=fopen("test/test.txt","r"))!=NULL)
            printf("fichier %s ouvert\n","test/test.txt");
        else{
            printf("fichier introuvable ou inexistant\n");
            if((f=fopen("test/test.txt","w"))!=NULL)
                printf("creation du fichier\n");
            else
                printf("erreur creation du fichier\n");
        }
        if(f!=NULL)
            fclose(f);

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*********************************
Exercice 4
Avec le bloc note créez un fichier que vous sauvez dans un répertoire
distant du programme.
Par rapport au programme il faut remonter de trois niveaux et redescendre
de quatre niveaux pour trouver le fichier. Faire le programme qui ouvre
le fichier et le referme.
*

#include <stdlib.h>
#include <stdio.h>

int main()
{
char continuer='o';
FILE*f;

    while(continuer=='o'){

        if((f=fopen("../../../n1/n2/n3/n4/test.txt","r"))!=NULL){
            printf("fichier ouvert\n");
            fclose(f);
        }
        else
            printf("fichier introuvable ou inexistant\n");


        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*********************************
Exercice 5
Ecrire un programme qui demande à l’usager d’entrer des mots un à un,
qui stocke ces mots à la fin d’un fichier texte, puis qui affiche le
contenu du fichier complet. Initialement, le programme doit créer le
fichier s’il n’existe pas, mais ne doit pas perdre son contenu s’il
existe déjà. Vérifier ce point en lançant deux fois de suite le programme.
*
#include <stdlib.h>
#include <stdio.h>

int main()
{
char continuer='o',stop;
FILE*f;
char mot[80],c;

    while(continuer=='o'){
        if((f=fopen("test.txt","a+"))!=NULL){

            // entrer des mots
            stop=0;
            while(stop!='\n'){
                printf("enter un mot : ");
                fgets(mot,80,stdin);
                rewind(stdin);
                stop=mot[0];
                if(stop!='\n')
                    fprintf(f,"%s",mot);
            }
            // affichage du contenu du fichier
            rewind(f);// remet le curseur au début du fichier
            while((c=fgetc(f))!=EOF)
                putchar(c);
            fclose(f);

        }
        else
            printf("probleme a la creation ou l'ouverture du fichier\n");

        printf("continuer ? (o/n)");  // évite la sortie du programme
        scanf("%c",&continuer);
        rewind(stdin);
    }

    return 0;
}
/*********************************
Exercice 6
Écrire un programme qui modifie le contenu d’un fichier texte comme suit :
Initialement le fichier texte contient sur chaque ligne une opération
arithmétique sur deux entiers par exemple :
3 + 5
4 – 7
2 * 9
Le programme doit interpréter correctement le contenu de chaque ligne et
écrire le résultat de l’opération dans le même fichier à la suite de chaque opération :
3 + 5 = 8
4 - 7 = -3
2 * 9 = 18
Se limiter aux quatre opérations arithmétiques de base (+, -, *, /) mais gérer
correctement les erreurs courantes :
fichier inaccessible ou inexistant
format de fichier incorrect
opération arithmétique inconnue.
*
#include <stdlib.h>
#include <stdio.h>

int main()
{
FILE*f, *fres;
int v1,v2,res,err=0;
char op;

    if((f=fopen("operations.txt","r"))!=NULL){
        fres=fopen("operation_res.txt","w");
        while(!feof(f)){
           fscanf(f,"%d %c %d",&v1,&op, &v2);
            switch(op){
                case '+' : res=v1+v2; break;
                case '-' : res=v1-v2; break;
                case '*' : res=v1*v2; break;
                case '/' : res=v1/v2; break;
                default :
                    printf("operation inconnue\n");
                    err=1;
            }
            if(!err)
                fprintf(fres,"%d %c %d = %d\n",v1,op, v2, res);
        }
        fclose(fres);
        fclose(f);
    }
    else
        printf("fichier introuvable ou inexistant\n");

    // remarque : en principe nous devrions pouvoir réécrire dans le fichier d'origine
    // avec le code
    //if((f=fopen("operations.txt","r+"))!=NULL){
    //    while(!feof(f)){
    //       fscanf(f,"%d %c %d",&v1,&op, &v2);
    //        switch(op){
    //             case '+' : res=v1+v2; break;
    //            case '-' : res=v1-v2; break;
    //            case '*' : res=v1*v2; break;
    //            case '/' : res=v1/v2; break;
    //        }
    //        // la récupération se fait bien
    //        printf("%d %c %d = %d\n",v1,op,v2,res);
    //        // mais l'écriture pose problème (mingw32, codeBlock(), visual studio)
    //        fprintf(f," = %d\n", res);
    //    }
    //    fclose(f);
    //}


    return 0;
}
/*********************************
Exercice 7
Ecrire un programme qui à partir d'un fichier texte détermine :
le nombre de caractères qu'il contient
le nombre de chacune des lettres de l'alphabet (on ne considérera
que les minuscules)
le nombre de mots
le nombre de lignes
Les fins de ligne ne sont pas comptabilisées dans les caractères.
On admettra que deux mots sont toujours séparés par un ou plusieurs
des caractères suivants :
fin de ligne
espace
ponctuation (, ; : ! . ?)
parenthèses ( )
guillemets "
apostrophe '
On admettra également, pour simplifier, qu'aucun mot ne peut être
commencé sur une ligne et finir sur la suivante.
Il est conseillé de réaliser une fonction permettant de décider si
un caractère donné, transmis en argument, est un des séparateurs
mentionnés ci-dessus. Elle renvoie 1 si oui et 0 si non.
*
#include <stdlib.h>
#include <stdio.h>

int is_separateur(char c);
int is_lettre(char c);

int main()
{
FILE*f;
int nbcar=0, nblettre=0,nblig=0,nbmot=0;
char oldc=' ',c;

    if((f=fopen("texte.txt","r"))!=NULL){
        while((c=fgetc(f))!=EOF){
            nbcar++;
            if(is_lettre(c))
                nblettre++;
            if(c=='\n')
                nblig++;
            if(is_separateur(oldc) && is_lettre(c))
                nbmot++;

            oldc=c;
        }
        printf("resultat :\n");
        printf("caracteres : %d\n"
               "lettres    : %d\n"
               "lignes     : %d\n"
               "mots       : %d\n",nbcar,nblettre,nblig,nbmot);

    }
    else
        printf("fichier introuvable ou inexistant\n");

    return 0;
}
int is_separateur(char c)
{
    return (c==' '||c=='.'||c==','||c==';'||c==':'||c=='\n'||c=='?'||c=='!'||c=='"');
}
int is_lettre(char c)
{
    return ((c>='a'&& c <='z')||(c>='A'&& c <='Z')// les maj sont aussi prises en compte
            || c=='à'||c=='é'||c=='è'||c=='ù'||c=='ê');
}
/*********************************
Exercice 8
Soit un fichier texte créé avec le bloc note. Écrire un programme qui
peut exécuter les opérations suivantes :
sauvegarder le contenu du fichier texte en fichier binaire
récupérer les données sur le fichier binaire
modifier  les données.
Chacune de ces opérations est contrôlée par un affichage dans la fenêtre
console ( au départ contenu du fichier texte, récupération sur fichier binaire,
chaque nouvelle modification effectuée sur les chaines, chaque nouvelle
récupération du fichier binaire).
*
#include <stdlib.h>
#include <stdio.h>

int main()
{
FILE*ftxt,*fbin;
char c=0,*buf=NULL;
int pos=0;

    if((ftxt=fopen("texte.txt","r"))!=NULL){

        if((fbin=fopen("texte.bin","wb+"))!=NULL){

            //sauvegarder le contenu du fichier texte en fichier binaire
            printf("FICHIER TEXTE :\n");
            while((c=fgetc(ftxt))!=EOF){
                putchar(c);// voir le texte dans la fenetre console
                fwrite(&c,sizeof(char),1,fbin); // copier dans le fichier binaire
            }

            //récupérer les données sur le fichier binaire
            rewind(fbin);
            printf("\nFICHIER BINAIRE :\n");
            while(fread(&c,sizeof(char),1,fbin)==1)
                putchar(c);

            //modifier  les données.
            rewind(fbin);
            printf("\nFICHIER BINAIRE CRYPTE:\n");
            while(fread(&c,sizeof(char),1,fbin)==1){

                c++;  // chaque lettre augmentée de 1 : a->b, b->c etc

				// la solution qui suit ne fonctionne pas (cause inconnue), fseek boucle sur la seconde lettre
                // fseek(fbin,-1,SEEK_CUR); // ensuite revenir avant lecture de la lettre
                // fwrite(&c,sizeof(char),1,fbin);// pour écrire la nouvelle dessus et passer à la suivante avec fread ensuite

				// alors je stocke tout dans un tableau
				buf=(char*)realloc(buf,sizeof(char)*pos+1);
				buf[pos++]=c;
            }

			// et je recopie le tableau dans le fichier
			rewind(fbin);
			fwrite(buf,sizeof(char),pos,fbin);

			// relecture du fichier
            rewind(fbin);
            printf("\nFICHIER BINAIRE CRYPTE:\n");
            while(fread(&c,sizeof(char),1,fbin)==1)
                putchar(c);
			putchar('\n');
        }
        else
            printf("erreur creation fichier binaire\n");
    }
    else
        printf("fichier introuvable ou inexistant\n");

    return 0;
}
/*********************************
Exercice 9
Soit une matrice dynamique de nombres dans un programme de nb1*nb2
aléatoires, faire les fonctions suivantes :
une fonction d'initialisation avec des valeurs aléatoires
une fonction d'affichage
deux fonctions, une save et une load,  de la matrice entière
deux fonctions, une save et une load, de la matrice ligne par ligne
deux fonctions, une save et une load, de la matrice nombre par nombre
Tester dans un programme qui donne le choix entre ces opérations via un menu
utilisateur. Commencez par initialisation et affichage, puis ajoutez saves
et loads, tester à chaque étape.
*
#include <stdlib.h>
#include <stdio.h>

int     menu            (void);
void    taille_mat      (int *n1, int*n2);
int**   alloue          (int n1, int n2);
void    libere          (int**m,int n1);
void    init            (int**m, int n1, int n2);
void    affiche         (int**m, int n1, int n2);
void    save_par_nombre (int**m, int n1, int n2);
int**   load_par_nombre (int *n1, int*n2);
void    save_par_ligne  (int**m, int n1, int n2);
int**   load_par_ligne  (int *n1, int*n2);
void    save_entiere    (int**m, int n1, int n2);
int**   load_entiere    (int*n1, int*n2);
void    affiche_ad_mem  (int**m, int n1, int n2);


int main()
{
char continuer='o';
int**mat=NULL;
int n1,n2;
    while(continuer=='o'){

        switch(menu()){

            case 1 : // allouer/initialiser
                if(mat!=NULL)
                    libere(mat,n1);
                taille_mat(&n1,&n2);
                mat=alloue(n1,n2);
                init(mat,n1,n2);
                affiche(mat,n1,n2);
                break;

            case 2 : // save par nombre
                save_par_nombre(mat, n1, n2);
                break;

            case 3 : // load par nombre
                if(mat!=NULL)
                    libere(mat,n1);
                mat=load_par_nombre(&n1, &n2);
                affiche(mat,n1,n2);
                break;

            case 4 : // par ligne
                save_par_ligne(mat, n1, n2);
                break;

            case 5 :
                if(mat!=NULL)
                    libere(mat,n1);
                mat=load_par_ligne(&n1, &n2);
                affiche(mat,n1,n2);
                break;

            case 6 : // entière
                save_entiere(mat,n1,n2);
                break;

            case 7 :
                if(mat!=NULL)
                    libere(mat,n1);
                mat=load_entiere(&n1, &n2);
                affiche(mat,n1,n2);
                break;

            case 8 : // affichage des adresses mémoire
                printf("Succession des adresses memoires :\n");
                if(mat!=NULL)
                    affiche_ad_mem(mat, n1, n2);
                else
                    printf("matrice non allouee\n");
                break;


            default : continuer='n';
        }
    }
    return 0;
}
//
int menu()
{
int choix=0;

    printf("1 : alouer/initialiser\n"
           "2 : sauver par nombre\n"
           "3 : loader par nombre\n"
           "4 : sauver par ligne\n"
           "5 : loader par ligne\n"
           "6 : sauver entiere (err en dynamique)\n"
           "7 : loader entiere (err en dynamique)\n"
           "8 : afficher les adresses memoire\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}
//
void taille_mat(int *n1, int*n2)
{
    printf("entrer nombre de lignes et colonnes : ");
    scanf("%d%d",n1,n2);
    rewind(stdin);
    *n1=(*n1<=0)? 1:*n1;
    *n2=(*n2<=0)? 1:*n2;
}
//
int** alloue(int n1, int n2)
{
int **m,i;
    m=(int**)malloc(sizeof(int*)*n1);
    for (i=0; i<n1; i++)
        m[i]=(int*)malloc(sizeof(int)*n2);
    return m;
}
//
void libere(int**m,int n1)
{
int i;
    for (i=0; i<n1; i++)
        free(m[i]);
    free(m);
}
//
void init(int**m, int n1, int n2)
{
int i,j;
    for (i=0; i<n1; i++)
        for (j=0; j<n2; j++)
            m[i][j]=rand()%100;
}
//
void affiche(int**m, int n1, int n2)
{
int i,j;
    for (i=0;i<n1; i++){
        for (j=0; j<n2; j++)
            printf("%3d",m[i][j]);
        putchar('\n');
    }
}
//
void save_par_nombre(int**m, int n1, int n2)
{
FILE*f;
int i,j,err;

    if(m==NULL){
        printf("matrice non allouee/initialisee\n");
        return;
    }

    if((f=fopen("save_mat.bin","wb"))!=NULL){
        err=fwrite(&n1,sizeof(int),1,f);
        err+=fwrite(&n2,sizeof(int),1,f);
        if(err==2){
            for (i=0; i<n1; i++)
                for (j=0; j<n2; j++)
                    fwrite(&m[i][j],sizeof(int),1,f);
        }
        fclose(f);
        printf("sauvegarde par nombre effectuee\n");
    }
    else
        printf("erreur creation fichier save\n");
}
//
int** load_par_nombre(int *n1, int*n2)
{
FILE*f;
int**m;
int i,j,err;
    if((f=fopen("save_mat.bin","rb"))!=NULL){
        err=fread(n1,sizeof(int),1,f);
        err+=fread(n2,sizeof(int),1,f);
        if(err==2){
            m=alloue(*n1,*n2);
            for (i=0; i<*n1; i++)
                for (j=0; j<*n2; j++)
                    fread(&m[i][j],sizeof(int),1,f);
        }
        else
            printf("erreur recuperation taille matrice\n");
        fclose(f);
    }
    else
        printf("erreur ouverture fichier save\n");
    return m;
}
//
void save_par_ligne(int**m, int n1, int n2)
{
FILE*f;
int i,err;

    if(m==NULL){
        printf("matrice non allouee/initialisee\n");
        return;
    }

    if((f=fopen("save_mat.bin","wb"))!=NULL){
        err=fwrite(&n1,sizeof(int),1,f);
        err+=fwrite(&n2,sizeof(int),1,f);
        if(err==2){
            for (i=0; i<n1; i++)
                fwrite(m[i],sizeof(int),n2,f);
        }
        fclose(f);
        printf("sauvegarde par ligne effectuee\n");
    }
    else
        printf("erreur creation fichier save\n");
}
//
int** load_par_ligne(int *n1, int*n2)
{
FILE*f;
int**m;
int i,err;
    if((f=fopen("save_mat.bin","rb"))!=NULL){
        err=fread(n1,sizeof(int),1,f);
        err+=fread(n2,sizeof(int),1,f);
        if(err==2){
            m=alloue(*n1,*n2);
            for (i=0; i<*n1; i++)
                fread(m[i],sizeof(int),*n2,f);
        }
        else
            printf("erreur recuperation taille matrice\n");
        fclose(f);
    }
    else
        printf("erreur ouverture fichier save\n");
    return m;
}
//
void save_entiere(int**m, int n1, int n2)
{
FILE*f;
int err;

    if(m==NULL){
        printf("matrice non allouee/initialisee\n");
        return;
    }

    if((f=fopen("save_mat.bin","wb"))!=NULL){
        err=fwrite(&n1,sizeof(int),1,f);
        err+=fwrite(&n2,sizeof(int),1,f);
        if(err==2)
            fwrite(m,sizeof(int),n1*n2,f);  // ne fonctionne pas avec une matrice dynamique
            // les adresses mémoire de chaque ligne ne se suivent pas et le bloc n'est pas homogène
            // comme le montre la fonction d'affichage des adresses mémoire
        fclose(f);
        printf("sauvegarde entiere effectuee\n");
    }
    else
        printf("erreur creation fichier save\n");
}
//
int** load_entiere(int*n1, int*n2)
{
FILE*f;
int**m;
int i,err;
    if((f=fopen("save_mat.bin","rb"))!=NULL){
        err=fread(n1,sizeof(int),1,f);
        err+=fread(n2,sizeof(int),1,f);
        if(err==2){
            m=alloue(*n1,*n2);
            fread(m,sizeof(int),(*n1)*(*n2),f);  // ne fonctionne pas avec une matrice dynamique
            // les adresses mémoire de chaque ligne ne se suivent pas et le bloc n'est pas homogène
            // comme le montre la fonction d'affichage des adresses mémoire
        }
        else
            printf("erreur recuperation taille matrice\n");
        fclose(f);
    }
    else
        printf("erreur ouverture fichier save\n");
    return m;
}
//
void affiche_ad_mem(int**m, int n1, int n2)
{
int i,j;
    for (i=0;i<n1; i++){
        for (j=0; j<n2; j++)
            printf("%p-",&m[i][j]);
        putchar('\n');
    }
}

/*********************************
Exercice 10
Créez un programme permettant de saisir un mot au clavier puis de le stocker
dans un fichier avant de le relire dans le fichier pour l’afficher à nouveau.
Dans cet exercice, le fichier sera ouvert au début du main() et ne sera refermé
qu’à la fin du main(), pas d’ouvertures puis de refermetures multiples.
*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
FILE*f;
char mot[256];
    f=fopen("test.txt","w+"); // ouverture en ecriture et lecture
    if(f!=NULL){
        printf("entrer un mot : ");
        scanf("%s",mot);
        rewind(stdin);

        fprintf(f,"%s",mot);

        memset(mot,0,256);
        rewind(f);
        fgets(mot,256,f);
        printf("mot dans le fichier : %s\n",mot);
        fclose(f);
    }
    else
        printf("erreur creation du fichier/n");

    return 0;
}
/*********************************
Exercice 11
Dans un programme écrire une phrase avec plusieurs mots dans un fichier
puis afficher le contenu du fichier à l'envers, lettre par lettre, en
commençant par la fin.
*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
char continuer='o';
FILE*f;
char buf[256],c;
int pos;
    while(continuer=='o'){

        printf("entrer une phrase : ");
        fgets(buf,256,stdin);
        // en mode texte avec la fonction fseek() le deplacement ne se
        // fait qu'à partir du début et au minimum de 4 en 4 lettres (octets)
        // en fait le mouvement avec fseek en mode texte est peu pratique
        printf("test mode texte :\n");
        if((f=fopen("test.txt","w+"))!=NULL){
            fprintf(f,"%s",buf);
            do{
				pos=ftell(f);
				pos-=4;
				fseek(f,pos,SEEK_SET);
				c=fgetc(f);
                putchar(c);

            }while(pos>0);
            fclose(f);
            putchar('\n');
        }
        else
            printf("erreur creation du fichier mode texte\n");

        // en mode binaire j'obtiens un déplacement de un en un octet
        printf("test mode binaire :\n");
        if((f=fopen("test.bin","wb+"))!=NULL){
            fwrite(buf,sizeof(char),strlen(buf)+1,f);
            do{
                pos=ftell(f);
                pos-=2;
                fseek(f,pos,SEEK_SET);
                fread(&c,sizeof(char),1,f);
				putchar(c);

            }while(pos!=0);
            fclose(f);
            putchar('\n');
        }
        else
            printf("erreur creation du fichier\n");

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*********************************
Exercice 12
Dans un programme, faire une fonction qui lit les caractères dans un fichier
texte selon un pas spécifié en paramètre. Par exemple 2 pour une lettre sur
deux, 3 pour une lettre sur trois, 10 pour une lettre sur dix etc. Lorsque
le pas est positif on avance du début vers la fin, Si le pas est négatif
on va de la fin vers le début.
*
#include <stdlib.h>
#include <stdio.h>
void parcourt(FILE*f,int pas)
{
char c;
int pos,res=1;
    if(pas>0)
        rewind(f);  // position au debut
    else{
        fseek(f,0,SEEK_END);
        pos=ftell(f);  // position finale
        pos+=(pas-1);
		fseek(f,pos,SEEK_SET);// position à la fin (devant \n)
    }

    while(res){
        res=fread(&c,sizeof(char),1,f);
        putchar(c);
        pos=ftell(f);
        pos+=(pas-1);
        if(fseek(f,pos,SEEK_SET)!=0)
			res=0;
    }
    putchar('\n');
}


int main()
{
char continuer='o';
FILE*f;
char buf[1024];
int pas;
    // creation du fichier texte
    printf("entrer un texte : ");
    fgets(buf,1024,stdin);
    if((f=fopen("test.txt","w+"))!=NULL){
        fprintf(f,"%s",buf);
        fclose(f);
    }

    // ouverture en binaire
    if((f=fopen("test.txt","rb"))!=NULL){
        // tests de parcourts
        while(continuer=='o'){
            printf("entrer le pas : ");
            scanf("%d",&pas);
            rewind(stdin);

            parcourt(f,pas);

            printf("continuer ? (o/n)");
            scanf("%c",&continuer);
            rewind(stdin);
        }
    }
    else
        printf("probleme ouverture en binaire\n");


    return 0;
}
/*********************************
Exercice 13
Faire une fonction de lecture de caractères qui peut afficher n'importe quel
caractère d'un fichier texte à partir de la position courante dans le fichier.
Le déplacement en positif ou négatif dans le fichier est spécifié en paramètre
de cette fonction d'affichage.
*
#include <stdlib.h>
#include <stdio.h>

FILE* creer_fichier()
{
FILE*f;
char buf[256];
    if((f=fopen("txt.txt","w+"))!=0){
        printf("entrer un texte dans le fichier :\n");
        fgets(buf,256,stdin);
        fputs(buf,f);
    }
    return f;
}

void hasard_pos(FILE*f)
{
int pos;
    if(f!=NULL){
        fseek(f,0,SEEK_END);
        pos=ftell(f);
        pos=rand()%pos;
        fseek(f,pos,SEEK_SET);
    }
}

int lire_char(int pas,FILE*f)
{
int pos,fin;
    pos=ftell(f);
    fseek(f,0,SEEK_END);
    fin=ftell(f);

    pos+=pas;
    pos=(pos<0)?0:((pos>fin)?fin:pos);

    fseek(f,pos,SEEK_SET);
    return fgetc(f);

    // remarque le déplacement du curseur au moment de la lecture
    // du caractère n'est pas pris en compte
}

int main()
{
char continuer='o';
FILE*f;
int pas=0;

    f=creer_fichier();
    hasard_pos(f);

    while(continuer=='o'){
        printf("entrer un pas (+ ou -) : ");
        scanf("%d",&pas);
        rewind(stdin);

        printf("%c",lire_char(pas,f));

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*********************************
Exercice 14
Un magasin d'articles de sport a une base de donnée pour gérer son fond. Pour
chaque article il faut stocker en mémoire : le code (valeur entière), le nom
du produit, le prix unitaire du produit, le stock disponible (valeur entière).
La base de données est un fichier binaire. Toutes les informations des articles
sont stockées article par article, les uns à la suite des autres sur le fichier.

Dans un programme, proposer à l'utilisateur les actions suivantes :
1) Définir un type approprié pour identifier les articles sachant que toutes les
opérations se font en accès directe sans stockage de la base en mémoire centrale (RAM)
2) Ecrire une fonction de saisie d'un nouvel article
3) Ecrire une fonction de sauvegarde d'un article dans la base
4) Ecrire une fonction d'affichage d'un article dont le code est passé en paramètre
5) Faire une fonction d'affichage de la base.
6) Ecrire une fonction de recherche du code d'un article à partir de sa dénomination
7) Ecrire une fonction permettant à un utilisateur de modifier un article dont le code
est passé en paramètre
8) Ecrire une fonction de suppression d'un article de la base soit par son code soit
par son nom.
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LIBRE   -1

typedef struct{
    int code;
    char nom[256];
    float prix;
    int stock;
}t_produit;


int         menu            (void);
t_produit   saisie          (void);
void        affiche         (t_produit p);
void        affiche_base    (FILE*f);
int         cherche_pos     (int code, FILE*f);
void        ajouter         (t_produit p, FILE*f);
int         trouve_code     (char*nom,FILE*f);
void        cherche_code    (FILE*f);
t_produit   trouve_article  (int code, FILE*f);
void        cherche_article (FILE*f);
void        modifier        (FILE*f);
int         question        (char*s);

int main()
{
char continuer=1;
FILE*f;
t_produit p;
    if((f=fopen("base.bin","rb+"))==NULL)
        if ((f=fopen("base.bin","wb+"))==NULL){
            printf("creation fichier impossible");
            exit(EXIT_FAILURE);
        }

    // la suite du programme suppose le fichier ouvert

    while(continuer){

        switch(menu()){
            case 1 : // saisie article
                p=saisie();
                affiche(p);
                ajouter(p,f);
                break;
            case 2 : // afficher un article selon code
                cherche_article(f);
                break;
            case 3 : // afficher toute la base
                affiche_base(f);
                break;
            case 4 : // recherche code article à partir du nom
                cherche_code(f);
                break;
            case 5 : // modifier un article via son code
                modifier(f);
                break;
            case 6 : // supprimer un article de la base

                break;

            default : continuer=0;
        }
    }
    return 0;
}

int menu()
{
int choix;
    printf("1 : saisir un nouvel article\n"
           "2 : afficher un article (code)\n"
           "3 : afficher toute la base\n"
           "4 : rechercher code article a partir du nom\n"
           "5 : modifier un article via son code\n"
           "6 : supprimer  un article de la base\n");
    scanf("%d",&choix);
    rewind(stdin);
    return choix;
}

//2) Ecrire une fonction de saisie d'un nouvel article
t_produit saisie()
{
t_produit p;
    printf("enter le code : ");
    scanf("%d",&p.code);
    rewind(stdin);

    printf("enter le nom : ");
    fgets(p.nom,256,stdin);
    p.nom[strlen(p.nom)-1]='\0';
    rewind(stdin);

    printf("entrer le prix : ");
    scanf("%f",&p.prix);
    rewind(stdin);

    printf("entrer quantite en stock : ");
    scanf("%d",&p.stock);
    rewind(stdin);
    return p;
}
//
void affiche(t_produit p)
{
    if(p.code!=LIBRE){
        printf("code     : %d\n",p.code);
        printf("nom      : %s\n",p.nom);
        printf("prix     : %.2f\n",p.prix);
        printf("quantite : %d\n",p.stock);
    }
    else
        printf("position libre\n");
}
//
void affiche_base(FILE*f)
{
t_produit enr;
    rewind(f);
    printf("CONTENU BASE :\n");
    while (fread(&enr,sizeof(t_produit),1,f)){
        affiche(enr);
        printf("---------\n");
    }
}
int cherche_pos(int code,FILE*f)
{
t_produit enr;
int trouve;

    fseek(f,0,SEEK_SET);
    do{
        trouve=fread(&enr,sizeof(t_produit),1,f);
    }while(enr.code!=code && trouve==1);
    // si position trouvée se placer au début de la position
    if(trouve==1)
        fseek(f,sizeof(t_produit)*-1,SEEK_CUR);
    return trouve;
}
//
void ajouter(t_produit p,FILE*f)
{
    cherche_pos(LIBRE,f);// trouver une position libre
    fwrite(&p,sizeof(t_produit),1,f);
}

//6) Ecrire une fonction de recherche du code d'un article à partir de sa dénomination
int trouve_code(char*nom,FILE*f)
{
t_produit p;
int code=LIBRE;
    while(fread(&p,sizeof(t_produit),1,f)){
        if (strcmp(nom,p.nom)==0){
            code=p.code;
            break;
        }
    }
    return code;
}
//
void cherche_code(FILE*f)
{
char buf[256];
int code;
    printf("entrer un nom d'article : ");
    fgets(buf,256,stdin);
    buf[strlen(buf)-1]='\0';
    code =trouve_code(buf,f);
    if (code>=0)
        printf("code de %s : %d\n",buf,code);
    else
        printf("aucun article %s dans la base\n",buf);
}
//
t_produit trouve_article(int code, FILE*f)
{
t_produit p={LIBRE};
    rewind(f);
    while(fread(&p,sizeof(t_produit),1,f))
        if (p.code==code){
            fseek(f,-sizeof(t_produit),SEEK_CUR);
            break;
        }
    return p;
}
//
void cherche_article(FILE*f)
{
t_produit p;
int code=LIBRE;
    printf("entrer le code de l'article : ");
    scanf("%d",&code);
    rewind(stdin);
    p=trouve_article(code,f);
    affiche(p);
}
//7) Ecrire une fonction permettant à un utilisateur de modifier un article dont le code
//est passé en paramètre
void modifier(FILE*f)
{
t_produit p;
int code;
char rep;

    printf("entrer code article a modifier : ");
    scanf("%d",&code);
    rewind(stdin);

    p=trouve_article(code,f);
    if(p.code!=LIBRE){
        if(question("modifier code ? (o/n) :")=='o'){
            printf("entrer nouveau code : ");
            scanf("%d",&p.code);
            rewind(stdin);
        }
        if(question("modifier nom ? (o/n) :")=='o'){
            printf("entrer nouveau nom : ");
            fgets(p.nom,256,stdin);
            p.nom[strlen(p.nom)-1]='\0';
            rewind(stdin);
        }
        if(question("modifier prix ? (o/n) :")=='o'){
            printf("entrer nouveau prix : ");
            scanf("%f",&p.prix);
            rewind(stdin);
        }
        if(question("modifier stock ? (o/n) :")=='o'){
            printf("entrer nouveau stock : ");
            scanf("%d",&p.stock);
            rewind(stdin);
        }
        fwrite(&p,sizeof(t_produit),1,f);
    }
}
int question(char*s)
{
int rep=0;
    printf("%s",s);
    scanf("%c",&rep);
    rewind(stdin);
    return rep;
}
//8) Ecrire une fonction de suppression d'un article de la base soit par son code soit
//par son nom.


/*********************************
Exercice 15
Reprendre l'exercice  14 mais cette fois avec possibilité de chargement
de la base dans le programme,
1) ajouter :
une fonction de chargement de la base
une fonction de sauvegarde de la base
2) modifier les autres fonctions en conséquence.
*
#include <stdlib.h>
#include <stdio.h>

int main()
{
char continuer='o';

    while(continuer=='o'){

        printf("continuer ? (o/n)");
        scanf("%c",&continuer);
        rewind(stdin);
    }
    return 0;
}
/*********************************
*/
