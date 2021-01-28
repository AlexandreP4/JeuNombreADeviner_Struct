/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;
#include "../include/JeuNombreADeviner.h"

int main()
{
    /**Init Game**/
    int nombreDeJoueur;
    char oGame = 'N';
    cout << "Nombre de Joueur : ";
    cin >> nombreDeJoueur;
    TJoueur joueur[nombreDeJoueur];
    TJoueur Winner[nombreDeJoueur];

    /**Init Joueur**/
    cout << endl; //Pour faire jolie
    CreationDesJoueurs(joueur, nombreDeJoueur);
    cout << endl; //Pour faire jolie

    /**Game**/
    do
    {  
        for (int i = 0; i < nombreDeJoueur; i++)
        {
            cout << Nom(joueur[i]) << ", tu vas jouer pour deviner un nombre secret \n" << endl;
            JouerPartie(joueur[i], TirerNombreMystere());  
        }
        cout << "Voulez-vous rejouer ? y/N" << endl;
        cin >> oGame;
        cout << endl; //Pour faire jolie
    } while (oGame == 'y');
    
    /**End game**/
    for (int i = 0; i < nombreDeJoueur; i++)
    {
        AfficheResultatsJoueur(joueur[i]);
        cout << "--------------" << endl; //Pour faire jolie
    }

    for (int y = 0; y < nombreDeJoueur; y++)
    {
        WhoWin(joueur[y], nombreDeJoueur, y, Winner);
    }
    ClearTable(Winner, nombreDeJoueur);

    cout << endl; //Pour faire jolie
    cout << "Victoire pour ";
    for (int y = 0; y < nombreDeJoueur; y++)
    {
        cout << Winner[y].nom << " ";
    }
    return 0;
}

