#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    const int NB_VIE = 5, MAX = 100, MIN = 1;
    double resultat2 = 0, resultat3 = 0, absolu = 0, nb = -27, dessus = 0, nb2 = 52.71, nombrePow = 2, puissance = 2, resultatSqrt = 0, nombreSqrt = 100;
    int nombre1 = 0, nombre2 = 0, nombre3 = 0, nombre4 = 0, nombreIncrementation = 0, nombreDecrementation = 0, nombre = 2, resultat = 0, nombreDeVies = 5, niveau = 1, age = 0, poids = 0, argent = 0, fleche = 0, majeur = 1, experiance = 0, choixMenu, nombreEntre = 0, nombreEntre2 = 0, nombreDeviner = 0, nombreEntreTriple = 0, nombreTriple = 0,  nombreMystere = 0, argentConversion = 0;
    char prenom[100];
    int chant = 0, rendreLargent = 0;
    char lettrePorte = 0;
    char motSecretPorte[] = "SOLEIL";
    int lettreTrouveePorte[6] = {0};
    int coupsRestantsPorte = 10;
    int i = 0;

    /*
    nombreIncrementation = 1;
    printf("Incrementation = %d\n", nombreIncrementation);
    nombreIncrementation++;
    printf("Incrementation2 = %d\n", nombreIncrementation);
    nombreIncrementation++;
    printf("Incrementation3 = %d\n", nombreIncrementation);
    nombreIncrementation++;
    printf("Incrementation4 = %d\n", nombreIncrementation);
    nombreDecrementation = 4;
    printf("Decrementation = %d\n", nombreDecrementation);
    nombreDecrementation--;
    printf("Decrementation2 = %d\n", nombreDecrementation);
    nombreDecrementation--;
    printf("Decrementation3 = %d\n", nombreDecrementation);
    nombreDecrementation--;
    printf("Decrementation4 = %d\n", nombreDecrementation);
    nombre += 4;
    printf("valeur du nombre : %d\n", nombre);
    nombre -= 3;
    printf("valeur du nombre : %d\n", nombre);
    nombre *= 5;
    printf("valeur du nombre : %d\n", nombre);
    nombre /= 3;
    printf("valeur du nombre : %d\n", nombre);
    nombre %= 3;
    printf("valeur du nombre : %d\n", nombre);
    absolu = fabs(nb); // fabs = valeur au positif
    printf("la valeur absolu est %lf\n", absolu);
    dessus = ceil(nb2); // ceil = valeur au dessus
    printf("la valeur ceil est %lf \n", dessus);
    dessus = floor(nb2); // floor = valeur en dessous
    printf("la valeur floor est %lf \n", dessus);
    nombrePow = pow(nombrePow, puissance); // pow = valeur puissance une autre
    printf("la valeur pow est %lf \n", nombrePow);
    resultatSqrt = sqrt(nombreSqrt); // sqrt = racine carree d'un nombre
    printf("la valeur sqrt est %lf \n", resultatSqrt);
    resultat = 5 + 3;
    printf("5 + 3 = %d\n", resultat);
    resultat = 4 / 2;
    printf("4 / 2 = %d\n", resultat);
    resultat2 = 5.0 / 2.0;
    printf("5 / 2 = %f\n", resultat2);
    resultat3 = 4.0 / 5.0;
    printf("4 / 5 = %f\n", resultat3);
    resultat3 = 10.0 / 3.0;
    printf("10 / 3 = %f\n", resultat3);
    resultat = 5 % 2;
    printf("5 modulo 2 = %d\n", resultat);
    resultat = 14 % 3;
    printf("14 modulo 3 = %d\n", resultat);
    printf("Entrez le nombre 1 : ");
    scanf("%d", &nombre1);
    printf("Entrez le nombre 2 : ");
    scanf("%d", &nombre2);
    nombre3 = nombre1 + nombre2;
    printf("%d + %d = %d\n", nombre1, nombre2, nombre3);
    printf("Le nombre 3 (nb1+nb2) équivaut à : %d\n", nombre3);
    nombre4 = nombre1 + nombre2 + nombre3;
    printf("%d + %d + %d = %d\n", nombre1, nombre2, nombre3, nombre4);
    printf("Le nombre 4 (nb1+nb2+nb3) équivaut à : %d\n", nombre4);
*/

    printf("Quel age avez-vous ?\n");
    scanf("%d", &age);
    printf("Ah ! Vous avez %d ans. ", age);
        if (age >= 18) { printf("Vous etes donc majeur ! "); } else if (age > 4) { printf("Bon vous etes pas trop jeune quand meme...\n"); } else { printf("Vous etes beaucoup trop jeune, c'est tres dangereux par ici.\n"); }
        if (age > 17 && age < 25) { printf("Vous etes dans le bon age.\n"); }
        if (age < 5 || age > 50) { printf("Racontez pas n'importe quoi svp !\n"); }
        if (age == 18) { printf("Vous venez de devenir majeur !\n"); }
        if (age <= 17) {majeur = 0;}
    printf("Quel est votre poids ?\n");
    scanf("%d", &poids);
    printf("Votre poids est de %d kilos.\n", poids);
        if (poids >= 90) { printf("Attention a votre poids !\n"); } else { printf("Votre poids est correct.\n"); }
    printf("Combien d'argent avez vous ?\n");
    scanf("%d", &argent);
    printf("Vous avez actuellement %d gold !\n", argent);
        if (age > 30 || argent > 100) { printf("Bienvenue chez PicsouBanque !\n"); } else { printf("Vous etes vraiment trop pauvre, bougez votre cul !\n"); }
    printf("Combien avez vous de fleches ?\n");
    scanf("%d", &fleche);
    printf("Vous avez %d fleches sur vous.\n", fleche);
        if (fleche <= 10) {printf("Attention vous n'avez pas beaucoup de fleche mine de rien...\n"); }
    if (majeur == 1) {printf("Rappel : Tu es majeur\n");} else { printf("Rappel: tu es mineur\n");}
    printf("Combien d'année d'experiance avez vous ?\n");
    scanf("%d", &experiance);
    printf("Ah ! Vous avez %d années d'experiance.\n", experiance);
        switch (experiance) { case 1: printf("Ce n'est pas beaucoup.\n"); break; case 2: printf("2 années c'est déja un bon début.\n"); break; case 3: printf("Vous etes donc pret pour la suite.\n"); break; default: printf("Vous avez beaucoup d'experiance, c'est bien !\n"); break;}

    printf("Bon commençons par commander de quoi manger.\n\n");
    printf("=== Menu ===\n\n");
    printf("1. Royal Cheese\n");
    printf("2. Mc Deluxe\n");
    printf("3. Mc Bacon\n");
    printf("4. Big Mac\n");
    printf("\nVotre choix ? ");
    scanf("%d", &choixMenu);
    printf("\n");
    switch (choixMenu) { case 1: printf("Vous avez choisi le Royal Cheese. Bon choix!"); break; case 2: printf("Vous avez choisi le Mc Deluxe. Berk, trop de sauce..."); break; case 3: printf("Vous avez choisi le Mc Bacon. Bon, ca passe encore ca ;o)"); break; case 4: printf("Vous avez choisi le Big Mac. Vous devez avoir tres faim !"); break; default: printf("Vous n'avez pas rentre un nombre correct. Vous ne mangerez rien du tout !"); break; }
    printf("\n");

    printf("Nous allons affronter notre premier ennemi attention!\n");
    while (nombreEntre != 42) { printf("Tapez le nombre 42 pour le tuer ! "); scanf("%d", &nombreEntre); }
    printf("Bravo vous l'avez eu !\n");
    printf("Attention du renfort arrive !\n");
    while (nombreEntre2 != 42) { printf("Tapez le nombre 42 pour le tuer ! "); scanf("%d", &nombreEntre2); }
    printf("Bravo vous l'avez eu lui aussi\n");
    printf("Regardez ! Il a drop 100 gold !\n");
    argent += 100;
    printf("Vous avez maintenant %d gold", argent);

    printf("\nContinuons notre périple...\n");
    printf("Pour la prochaine étape nous allons devoir deviner la valeur de notre futur ennemi.\n");
    srand(time(NULL));
    nombreMystere = (rand() % (MAX - MIN +1)) + MIN;
    do { printf("Quel est le nombre mystere?"); scanf("%d", &nombreDeviner); if (nombreMystere > nombreDeviner) printf("C'est plus !\n\n"); else if (nombreMystere < nombreDeviner) printf("C'est moins !\n\n"); else printf("Bravo, vous avez trouv le nombre mystere !!!\n\n");} while (nombreDeviner != nombreMystere);
    printf("Bravo, celui la etait vraiment fort en plus !\n Regardez ! Il a drop 1000 gold\n");
    argent += 1000;
    printf("Vous avez maintenant %d gold", argent);
    printf("\n Regardez il protegeait un coffre ! Allez donc l'ouvrir !\n");
    printf("D'après vous, combien de gold il y a dedans ?");
    scanf("%d", &nombreEntreTriple);
    nombreTriple = triple(nombreEntreTriple);
    printf("Et bien non ! Il y a dedans le triple de ce que vous avez demandé, c'était un coffre magique !\n");
    printf("Le triple de ce nombre est alors %d\n", nombreTriple);
    argent += nombreTriple;
    printf("Vous avez maintenant %d gold", argent);
    printf("\n Apres plusieurs heures de voyage, vous arrivez sur un nouveau territoire, ici les gold ont beaucoup moins de valeur :(\n");
    argentConversion = argent / 100;
    printf("Vos %d gold deviennes finalement %d gold\n", argent, argentConversion);
    printf("C'est pas bien grave, continuons notre aventure... Utilisons cet argent pour manger, nous volerons d'autres ennemies plus tard.\n");
    switch (menu())
    {
        case 1:
            printf("Vous avez pris le poulet\n");
            break;
        case 2:
            printf("Vous avez pris les concombres\n");
            break;
        case 3:
            printf("Vous avez pris l'escalope\n");
            break;
        case 4:
            printf("Vous avez pris la surprise du Chef. Vous etes un sacre aventurier dites donc !\n");
            break;
    }
    printf("Aufait, vous ne m'avez pas dit votre nom, comment vous appellez vous ?\n");
    scanf("%s", prenom);
    printf("D'accord %s, bonne chance pour la suite de votre aventure !\n\n", prenom);
    printf("Toujours dans l'auberge, une personne propose de chanter, vous pouvez choisir d'écouter ou de partir de l'auberge.\n");
    printf("1- Pour écouter.\n");
    printf("2- Pour partir.\n");
    scanf("%d", &chant);

    switch (chant)
    {
        case 1: printf("Vous avez choisit de rester pour écouter : il se met a chanter...\n");
        break;
        case 2: printf("Vous avez choisit de partir.\n");
        break;
    }

    if (chant == 1) { printf("L'homme a fini de chanter, vous etes le seul a etre rester l'écouter... Pour prouver sa reconnaissance envers vous, il vous donne 20 gold.\n"); argent += 20; }

    printf("Vous décidez de sortir de l'auberge... Sur le chemin vous rencontrez un homme vraiment en colère, étrangement il pense que vous lui avez volé de l'argent... Vous lui donnez 500 gold ou vous l'affrontez ?\n");
    printf("1- Pour lui donner.\n 2- Pour le combattre");
    scanf("%d", &rendreLargent);
    if (rendreLargent == 1) { argent -= 500; printf("Vous avez maintenant %d gold.\n", argent);}
    printf("Très bien %s, partons à l'aventure maintenant...\n\n", prenom);


    printf("Après plusieurs jours de marche vous vous trouver devant une pyramide, vous décidez de la visiter afin d'y trouver une bonne quantité d'or...\nMais l'entrée est protégée par un méchanisme, il va falloir trouver le bon mot pour dévérouiller la porte !\nAttention cependant au bout de 10 échecs vous serez attaqué par le gardien de la porte.\n\n");
    while (coupsRestantsPorte > 0 && !gagne(lettreTrouveePorte))
    {
        printf("Il vous reste %d coups a jouer", coupsRestantsPorte);
        printf("\nQuel est le mot secret ?");
            for (i = 0 ; i < 6 ; i++)
            {
                if (lettreTrouveePorte[i])
                    printf("%c",motSecretPorte[i]);
                else
                    printf("*");
            }
        printf("\nProposez donc une lettre : ");
        lettrePorte = lireCaractere();
        if (!rechercheLettre(lettrePorte, motSecretPorte, lettreTrouveePorte))
            {
                coupsRestantsPorte--;
            }
        if (gagne(lettreTouvee))
            printf("\n\nGagné ! Le mot secret pour ouvrir la porte est bien : %s", motSecret);
        else
            printf("\n\nPerdu ! Le gardien vous tue en l'espace de deux secondes");
    }

    return 0;
}


int triple(int gain)
{
    return 3 * gain;
}

int menu() {
    int choix = 0;

    while (choix < 1 || choix > 4) {
        printf("Menu :\n");
        printf("1 : Poulet de dinde aux escargots rotis a la sauce bearnaise\n");
        printf("2 : Concombres sucres a la sauce de myrtilles enrobee de chocolat\n");
        printf("3 : Escalope de kangourou saignante et sa gelee aux fraises poivree\n");
        printf("4 : La surprise du Chef (j'en salive d'avance...)\n");
        printf("Votre choix ? ");
        scanf("%d", &choix);
    }

    return choix;
}

int gagne(int lettreTrouveePorte[])
{
    int i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < 6 ; i++)
    {
        if (lettreTrouveePorte[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}


/*
int rechercheLettre(char lettre, char motSecretPorte[], int lettreTouveePorte)
{
    int i = 0;
    int bonneLettre = 0;
    for (i = 0 ; motSecretPorte[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i])
        {
            bonneLettre = 1;
            lettreTrouvee[i] = 1;
        }
    }
    return bonneLettre;
}
 */



int main(int argc, char *argv[])
{
    int resultat = 0, nombre1 = 0, nombre2 = 0;

    // On demande les nombres 1 et 2 à l'utilisateur :

    printf("Entrez le nombre 1 : ");
    scanf("%d", &nombre1);
    printf("Entrez le nombre 2 : ");
    scanf("%d", &nombre2);

    // On fait le calcul :

    resultat = nombre1 + nombre2;

    // Et on affiche l'addition à l'écran :

    printf ("%d + %d = %d\n", nombre1, nombre2, resultat);

    return 0;
}