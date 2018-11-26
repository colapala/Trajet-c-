/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring> 

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
 
 void Trajet::Afficher(){
	cout<<Depart<<endl;
	cout<<Arrivee<<endl;
}

//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & unTrajet )
// Algorithme :
//
{
  
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif

    Depart = new char[strlen(unTrajet.Depart)+1];
    strcpy(Depart,unTrajet.Depart);
    Arrivee = new char[strlen(unTrajet.Arrivee)+1];
    strcpy(Arrivee,unTrajet.Arrivee);
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet (const char * villeA,const char *  villeB )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
    Depart = new char[strlen(villeA)+1];
    strcpy(Depart, villeA);
    Arrivee = new char[strlen(villeB)+1];
    strcpy(Arrivee,villeB);
} //----- Fin de Trajet

Trajet::Trajet(){
  
}

Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
    delete [] Depart;
    delete [] Arrivee;
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
