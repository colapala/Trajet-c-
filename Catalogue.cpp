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
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
//#define MAP

//------------------------------------------------------------- Constantes
	int Catalogue::nb_trajets =0;
	int Catalogue::taille =2;
//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques
// type Catalogue::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Catalogue::Afficher(){
	if (nb_trajets==0){
		cout << "Catalogue vide" <<endl <<endl;
	}
	else {
		cout << "Affichage du catalogue : " <<endl;
		for (int i=0; i<nb_trajets; i++){
			cout << "Trajet " << i+1 << endl;
			collection[i]->Afficher();
		}
	}
}

void Catalogue::Ajouter( TrajetSimple* t){
	if (nb_trajets < taille){
		collection[nb_trajets]=t;
		//collection[nb_trajets]= new TrajetSimple(t.GetDepart(),t.GetArrivee(),t.GetTransport());
		nb_trajets++;
    }
    else {
	  taille *=2;
	  Trajet ** tmp = new Trajet*[taille];
	  for (int i =0; i<nb_trajets;i++){
		  tmp[i]= collection[i];
		  //tmp[i] =new TrajetSimple(list[i]->GetDepart(), list[i]->GetArrivee(), list[i]->GetTransport());
		  //delete list[i];
	  }
	tmp[nb_trajets] =t;
	//tmp[nb_trajets] = new TrajetSimple(t.GetDepart(), t.GetArrivee(), t.GetTransport());
	nb_trajets++;
	delete [] collection;
	collection = tmp;
	//delete tmp; le pointeur tmp est supprime par defaut a la fin de ajouter ?
	
  }
}

void Catalogue::Ajouter(TrajetCompose *tc){

	if (nb_trajets <taille){
		collection[nb_trajets] = tc;
		nb_trajets++;
	}
	else{
		taille *=2;
		Trajet ** tmp = new Trajet*[taille];
		for (int i =0; i<nb_trajets;i++){
			tmp[i]= collection[i];
		}
		tmp[nb_trajets] = tc;
		nb_trajets++;
		delete [] collection;
		collection = tmp;
	}
	//sdelete tc;
}

void Catalogue::Recherche(const char * depart, const char * arrivee){
	cout<<"Recherche en cours...pour aller de "<<depart<<" a "<<arrivee<<endl;
	bool trouve=false;
	for (int i=0;i<nb_trajets;i++){
		if(!strcmp(collection[i]->GetDepart(),depart) && !strcmp(collection[i]->GetArrivee(),arrivee) ){
		cout<<"Trajet n°"<<i+1<<endl;
		collection[i]->Afficher();
		trouve=true;
		}
	}
	if(trouve==false){
	cout<<"aucun Résultat pour votre recherche"<<endl;
	}
}
	
//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & unCatalogue )
// Algorithme :
//
{
	return *this;
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


Catalogue::Catalogue ()
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
	//cout <<"this pointer points to " <<this <<endl;
	/*for (int i =0; i<nb_trajets;i++){
		collection[i]->~Trajet();
		delete collection[i];
	}*/
	delete [] collection;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

