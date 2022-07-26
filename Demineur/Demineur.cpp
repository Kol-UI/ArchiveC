#include "stdafx.h"
#include <iostream>
#include "stdlib.h"
#include <string>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

//int random(int **tableauVerification, int ligne, int colonne, int mines);
//void affichageTableau(int **tableau, int ligne, int colonne);
int largeurTableau(bool fail1, int colonne);
int hauteurTableau(bool fail2, int ligne);
int nombreMineTableau(bool fail3, int mines);
//void verificationTableau(int **tableauVerification, int ligne, int colonne, int mines);

int main()
{
	bool preparation = false, fail1 = false, fail2 = false, fail3 = false;
	int colonne = 0, ligne = 0, mines = 0;
	//int **tableau, **tableauVerification;


	cout << "\t\t------Bienvenue dans le Demineur-----\n" << endl;
	
	while (!preparation) {
		colonne = largeurTableau(fail1, colonne);
		ligne = hauteurTableau(fail2, ligne);
		mines = nombreMineTableau(fail3, mines);
		preparation = true;
		break;
	}

	//tableau = new int*[ligne];
	//tableauVerification = new int*[ligne];
	//random(tableauVerification, ligne, colonne, mines);
	//affichageTableau(tableau, ligne, colonne);
	//verificationTableau(tableauVerification, ligne, colonne, mines);

	vector<vector<int>> tableau;
	for (short i = 0; i < ligne; i++)
	{
		tableau.push_back(vector<int>(colonne));
	}
	
	system("pause");

	return 0;
}


int largeurTableau(bool fail1, int colonne)
{
	while (!fail1) {
		cout << "Combien de case en largeur ? (Entre 5 et 30)" << endl;
		cin >> colonne;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			fail1 = false;
			cout << "Vous avez mal selectionner votre nombre de case en largeur, veuillez refaire la saisie..." << endl;
		}
		else {
			if (colonne > 4 && colonne < 31) {
				fail1 = true;
				return colonne;
				break;
			}
			else {
				cout << "Le nombre n'est pas correct." << endl;
			}
		}

	}
}


int hauteurTableau(bool fail2, int ligne)
{
	while (!fail2) {
		cout << "Combien de case en hauteur ? (Entre 5 et 30)" << endl;
		cin >> ligne;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			fail2 = false;
			cout << "Vous avez mal selectionner votre nombre de case en hauteur, veuillez refaire la saisie..." << endl;
		}
		else {
			if (ligne > 4 && ligne < 31) {
				fail2 = true;
				return ligne;
				break;
			}
			else {
				cout << "Le nombre n'est pas correct." << endl;
			}
		}
	}
}


int nombreMineTableau(bool fail3, int mines)
{
	while (!fail3) {
		cout << "Combien de mine en tout ? (Entre 5 et 15) " << endl;
		cin >> mines;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			fail3 = false;
			cout << "Vous avez mal selectionner votre nombre de mine dans le plateau de jeu, veuillez refaire la saisie..." << endl;
		}
		else {
			if (mines > 4 && mines < 16) {
				fail3 = true;
				return mines;
				break;
			}
			else {
				cout << "Le nombre n'est pas correct." << endl;
			}
		}
	}
}

/*
int random(int **tableauVerification, int ligne, int colonne, int mines)
{
	int mineNonPlacee = 0;
	srand(time(NULL));
	while (mineNonPlacee < mines) {
		int i = rand() % (ligne - 1);
		int j = rand() %( colonne - 1);
		cout << i << j << endl;
		if (tableauVerification[i][j] != 9)
		{
			tableauVerification[i][j] = 9;
			mineNonPlacee++;
		}
	}
	return **tableauVerification;
}
*/

/*
void affichageTableau(int **tableau, int ligne, int colonne)
{
	for (int i = 0; i < ligne; i++)
		tableau[i] = new int[colonne];
	for (int i = 0; i < ligne; i++)
		for (int j = 0; j < colonne; j++)
			tableau[i][j] = i * j;
	for (int i = 0; i < ligne; i++) {
		for (int j = 0; j < colonne; j++)
			cout << "[ ]";
		cout << endl;
	}
	cout << endl;
}
*/


/*
void verificationTableau(int **tableauVerification, int ligne, int colonne, int mines) 
{
	for (int i = 0; i < ligne; i++)
		tableauVerification[i] = new int[colonne];
	for (int i = 0; i < ligne; i++)
		for (int j = 0; j < colonne; j++)
			tableauVerification[i][j] = i * j;
	for (int i = 0; i < ligne; i++) {
		for (int j = 0; j < colonne; j++)
			if (tableauVerification[i][j] = 9) {
				cout << "X";
			}
			else {
				tableauVerification[i][j];
			}
		cout << endl;
	}
}
*/