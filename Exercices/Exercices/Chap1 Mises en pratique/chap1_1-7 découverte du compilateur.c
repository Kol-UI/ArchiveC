/*

1.  Introduction dans la programmation C

1.7 Mise en pratique : découverte du compilateur

Exercice 1
Installer un compilateur, Code::Blocks ou Visual Studio. Une recherche Google vous
indique où ces compilateurs sont téléchargeables sur Internet :
Pour codeblocks http://www.codeblocks.org/
et pour Visual Studio Express http://www.microsoft.com/fr-fr/download/details.aspx?id=40787

Une fois l'installation du compilateur terminée, repérer sur le disque l'emplacement
des dossiers include et lib du compilateur. Attention à ne rien modifier. Lancer le compilateur
que vous avez installé, Code::Blocks ou Visual Studio.
Repérer les étapes de la création d'un projet, créer un projet vide ou un projet "console
application". Attention à bien nommer votre projet et bien le positionner sur votre
disque dur. Pour Visual Studio, bien faire la distinction entre la solution, qui est un
ensemble de projets, et le projet qui est un élément d'une solution.

Exercice 2
Si le projet est vide, ajouter une page de code et écrire votre main(), puis afficher "ce
que vous voulez" avec la fonction printf(). Cette fonction s'obtient avec un include,
au-dessus du main(), de la librairie stdio.h.
Une fois le programme terminé, le compiler et l’exécuter. Si la fenêtre console s'ouvre
et se referme immédiatement, ajouter l'instruction suivante juste avant le return
final :
system("PAUSE");
Recompiler, relancer.
Recommencer en modifiant quelque chose à chaque fois, par exemple :
– Ajouter \n à la fin du message, des accents ô, à, é, è, ê, etc.
– Supprimer le point-virgule, un ou deux guillemets, une parenthèse...
Dans quels cas y a-t-il un message d'erreur et quel est-il ?

Exercice 3
Faire un dessin en utilisant plusieurs fois de suite la fonction printf() et plusieurs affichages
successifs de chaînes de caractères.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Ces questions supposent de la manipulation et il n'y a pas de corrige à faire!\n");
    return 0;
}
