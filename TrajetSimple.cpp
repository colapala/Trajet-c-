/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"
#include "TrajetSimple.h"
#include <cstring>
//#define MAP


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type TrajetSimple::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetSimple::Afficher(){
  cout << Depart << endl;
  cout << Arrivee <<endl;
  cout<<transport<<endl <<endl;
}

const char* TrajetSimple::GetDepart() const{
	return Depart;
}

const char* TrajetSimple::GetArrivee() const{
	return Arrivee;
}

const char* TrajetSimple::GetTransport() const{
	return transport;
}
//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
	
	/*delete [] Depart;
	delete [] Arrivee;
	delete [] transport;*/
	
	Depart = new char[strlen(unTrajetSimple.Depart)+1];
    strcpy(Depart,unTrajetSimple.Depart);
	Arrivee = new char[strlen(unTrajetSimple.Arrivee)+1];
    strcpy(Arrivee,unTrajetSimple.Arrivee);
    transport = new char[strlen(unTrajetSimple.transport)+1];
    strcpy(transport,unTrajetSimple.transport);
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple ):Trajet(unTrajetSimple.Depart,unTrajetSimple.Arrivee)
TrajetSimple::TrajetSimple ( const TrajetSimple & unTrajetSimple )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    
#endif
	
    /*transport = new char[strlen(unTrajetSimple.transport)+1];
    strcpy(transport,unTrajetSimple.transport);
	Depart = new char[strlen(unTrajetSimple.Depart)+1];
    strcpy(Depart,unTrajetSimple.Depart);
	Arrivee = new char[strlen(unTrajetSimple.Arrivee)+1];
    strcpy(Arrivee,unTrajetSimple.Arrivee);*/
	*this=unTrajetSimple;
	
} //----- Fin de TrajetSimple (constructeur de copie)

//constructeur sans aucun parametres
TrajetSimple::TrajetSimple (){
#ifdef MAP
    cout << "Appel au constructeur sans param de <TrajetSimple>" << endl;
#endif
}

//TrajetSimple::TrajetSimple ( const char* depart, const char * arrivee,const char * t ):Trajet(Depart,Arrivee)
TrajetSimple::TrajetSimple ( const char* depart, const char * arrivee,const char * t )
										
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetSimple>" << endl;
#endif
	
	Depart = new char[strlen(depart)+1];
    strcpy(Depart,depart);
	Arrivee = new char[strlen(arrivee)+1];
    strcpy(Arrivee,arrivee);
    transport = new char[strlen(t)+1];
    strcpy(transport,t);
} //----- Fin de TrajetSimple


TrajetSimple::~TrajetSimple ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
	cout <<"this pointer points to " <<this <<endl;
	delete [] Depart;
	delete [] Arrivee;
    delete [] transport;
} //----- Fin de ~TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

