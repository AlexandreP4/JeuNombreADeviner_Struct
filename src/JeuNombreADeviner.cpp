/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;
#include "../include/JeuNombreAdeviner.h"
#include <ctime>

// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : un_nom
// Param�tres de sortie : joueurAcreer
// Param�tres d'entr�e/sortie : NULL

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbTentatives = 0;
}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
    srand(time(NULL));
    int nombreADeviner = (rand() % (10 - 1 + 1)) + 1;
    return nombreADeviner;
}



// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: nombreADeviner
// Param�tres de sortie: joueur
// Param�tres d'entr�e/sortie : NULL 

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int oTentative = 0;
    int oInput;
    bool oVictoire = false;
   do
    {
        oTentative += 1;
        if (oTentative > 4)
        {
            cout << "Tu as fais trop de  tentatives !" <<endl;
            cout << "Le  nombre etait " << nombreADeviner << "\n" << endl;
            break;
        }
        cout << "Quel est le nombre ? ";
        cin >> oInput;
        if (nombreADeviner > oInput)
            cout << "C'est plus !\n\n";
        else if (nombreADeviner < oInput)
            cout << "C'est moins !\n\n";
        else
        {
            cout << "\nTu as trouve le nombre mystere !\n";
            cout << "Tu as fais " << oTentative << " tentatives !\n\n";
            oVictoire = true;
        }
    } while (oInput != nombreADeviner);
    MajResultatsJoueur(un_joueur, oTentative, oVictoire);
}


// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: nbEssais et gagne
// Param�tres de sortie: joueur
// Param�tres d'entr�e/sortie : NULL

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
   if (gagne)
   {
       joueur.nbPartiesJouees += 1;
       joueur.nbPartiesGagnees += 1;
       joueur.nbTentatives += nbEssais;
   }else
   {
       joueur.nbPartiesJouees += 1;
       joueur.nbTentatives += nbEssais;
   }
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: joueur
// Param�tres de sortie: nbsucces, nbechec, nbessais
// Param�tres d'entr�e/sortie : NULL

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees-joueur.nbPartiesGagnees;
    nbessais = joueur.nbTentatives;
}

// Nom : AfficheResultatsJoueur
// R�le : Affiche les r�sultats du joueur pass� en param�tre
//        La fonction affiche les informations � l'�cran au format:
//        Victoire : XX
//        Echec : XX
//        Tentatives : XX
// Param�tres d'entr�e: joueur
// Param�tres de sortie: NULL
// Param�tres d'entr�e/sortie : NULL

void AfficheResultatsJoueur(TJoueur joueur){
    int oSucces, oEchec, oEssais;
    ResultatsJoueur(joueur, oSucces, oEchec, oEssais);
    cout << "Joueur : " << joueur.nom << endl;
    cout << "Victoire : " << oSucces << endl;
    cout << "Echec : " << oEchec << endl;
    cout << "Tentatives : " << oEssais << endl;
}

// Nom :WhoAmI
// R�le : demande et retourne le nom qu'un joueur a donnée
// Param�tres d'entr�e: numeroDuJoueur
// Valeur de retour : nom du joueur

string WhoAmI(int numeroDuJoueur){
    string oName;
    cout << "Playeur " << numeroDuJoueur << " : ";
    cin >> oName;
    return oName;
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

// Nom : CreationDesJoueurs
// R�le : Crée n joueur
// Param�tres d'entr�e: nb de joueur
// Param�tres d'entr�e/sortie : joueur[]

void CreationDesJoueurs(TJoueur joueur[], int nombreDeJoueur){
    for (int i = 0; i < nombreDeJoueur; i++)
    {
        InitJoueur(joueur[i], WhoAmI(i+1));
    }
}

// Nom : WhoWin
// R�le : Retourne le joueur gagant
// Param�tres d'entr�e: joueur[], nb de joueur
// Param�tres d'entr�e/sortie : NULL

string WhoWin(TJoueur joueur[], int nombreDeJoueur){
    TJoueur Winner;
    InitJoueur(Winner, "Winner");

    for (int i = 0; i < nombreDeJoueur; i++)
    {
        if (joueur[i].nbPartiesGagnees > Winner.nbPartiesGagnees)
        {
            Winner = joueur[i];       
        }else if (joueur[i].nbPartiesGagnees == Winner.nbPartiesGagnees)
        {
            if (joueur[i].nbTentatives < Winner.nbTentatives)
            {
                Winner = joueur[i];
            }else if (joueur[i].nbTentatives == Winner.nbTentatives)
            {
                cout << "eeeeeuh" << endl;
            }
        }
    }
    return Nom(Winner);
}