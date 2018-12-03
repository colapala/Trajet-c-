/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
int Catalogue::nb_trajets = 0;
int Catalogue::taille = 2;

//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::Afficher(){
	for (int i=0; i<nb_trajets; i++){
		cout << "Trajet " << i << endl;
		collection[i].Afficher();
	}
}

void Catalogue::Ajouter(Trajet t){
	if (nb_trajets <= taille){
    collection[nb_trajets]= new TrajetSimple(t.GetDepart(),t.GetArrivee(),t.GetTransport());
    nb_trajets++;
  }
  else {
	  taille *=2;
	  Trajet ** tmp = new Trajet*[taille*2];
	  for (int i =0; i<nb_trajets;i++){
		  tmp[i]= list[i];
		  //tmp[i] =new TrajetSimple(list[i]->GetDepart(), list[i]->GetArrivee(), list[i]->GetTransport());
		  //delete list[i];
	  }
	tmp[nb_trajets] = new TrajetSimple(t.GetDepart(), t.GetArrivee(), t.GetTransport());
	nb_trajets++;
	delete list;
	list = tmp;
	//delete tmp; le pointeur tmp est supprime par defaut a la fin de ajouter ?
	
  }
}
}
//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
	collection = new Trajet*[taille];
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
	for (int i =0; i<nb_trajets;i++){
		delete collection[i];
	}
	delete [] collection;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

