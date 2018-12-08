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

void Catalogue::Afficher()
// Algorithme :
//
{
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

void Catalogue::Ajouter( TrajetSimple* t)
// Algorithme :
// Ajoute le TrajetSimple à la collection si la collection n'est pas totalement remplie, réallloue de la mémoire sinon
{
	if (nb_trajets < taille){
		collection[nb_trajets]=t;
		nb_trajets++;
    }
    else {
	  taille *=2;
	  Trajet ** tmp = new Trajet*[taille];
	  for (int i =0; i<nb_trajets;i++){
		  tmp[i]= collection[i];
	  }
	tmp[nb_trajets] =t;

	nb_trajets++;
	delete [] collection;
	collection = tmp;	
  }
}

void Catalogue::Ajouter(TrajetCompose *tc)
// Algorithme :
//Ajoute le TrajetCompose à la collection si la collection n'est pas totalement remplie, réallloue de la mémoire sinon
{

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
}

void Catalogue::Recherche(const char * depart, const char * arrivee)
// Algorithme :
//
{
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

void Catalogue::RechercheAvance(const char * depart, const char * arrivee)
// Algorithme :
//
{
	bool trouve=false;
	int NbTour=0;
	const char* NouvDepart=depart;

	for (int i=0;i<nb_trajets;i++){
		if(!strcmp(collection[i]->GetDepart(),depart) && !strcmp(collection[i]->GetArrivee(),arrivee) ){
			cout<<"Trajet n°"<<i+1<<endl;
			collection[i]->Afficher();
			trouve=true;
		}
		if(!strcmp(collection[i]->GetDepart(),NouvDepart)){
		   NouvDepart=collection[i]->GetArrivee();
			cout<<"Trajet n°"<<i+1<<endl;
			collection[i]->Afficher();
		   for(int j=0;j<nb_trajets;j++){
		    if(j!=i){
		     if(!strcmp(collection[j]->GetDepart(),NouvDepart) && !strcmp(collection[j]->GetArrivee(),arrivee) ){
			cout<<"Trajet n°"<<j+1<<endl;
			collection[j]->Afficher();
			trouve=true;
			break;
		        }
			if(!strcmp(collection[j]->GetDepart(),NouvDepart)){
			NouvDepart=collection[j]->GetArrivee();
			cout<<"Trajet n°"<<j+1<<endl;
			collection[j]->Afficher();
			j=0;
			NbTour++;
			if(NbTour>nb_trajets){
			break;
			}
			}
		    }
		   }
		}
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
	delete [] collection;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

