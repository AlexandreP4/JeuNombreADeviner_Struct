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
    /**Init joueur**/
    TJoueur joueur;
    InitJoueur(joueur, WhoAmI());
    cout << endl; //Pour faire jolie

    /**Start game**/
    cout << joueur.nom << ", tu vas jouer pour deviner un nombre secret \n" << endl;

    /**Game**/
    char oGame = 'N';
    do
    {  
        JouerPartie(joueur, TirerNombreMystere());
        cout << "Veux-tu rejouer ? y/N" << endl;
        cin >> oGame;
        cout << endl; //Pour faire jolie
    } while (oGame == 'y');
    
    /**End game**/
    AfficheResultatsJoueur(joueur);
    return 0;
}

