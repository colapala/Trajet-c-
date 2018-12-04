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

void Catalogue::Ajouter(const TrajetSimple &t){
	if (nb_trajets < taille){
		collection[nb_trajets]= new TrajetSimple(t.GetDepart(),t.GetArrivee(),t.GetTransport());
		nb_trajets++;
    }
    else {
	  taille *=2;
	  Trajet ** tmp = new Trajet*[taille*2];
	  for (int i =0; i<nb_trajets;i++){
		  tmp[i]= collection[i];
		  //tmp[i] =new TrajetSimple(list[i]->GetDepart(), list[i]->GetArrivee(), list[i]->GetTransport());
		  //delete list[i];
	  }
	tmp[nb_trajets] = new TrajetSimple(t.GetDepart(), t.GetArrivee(), t.GetTransport());
	nb_trajets++;
	delete [] collection;
	collection = tmp;
	//delete tmp; le pointeur tmp est supprime par defaut a la fin de ajouter ?
	
  }
}

void Catalogue::Ajouter(const TrajetCompose &tc){
	TrajetSimple tmp1 (tc.list[0]->GetDepart(), tc.list[0]->GetArrivee(), tc.list[0]->GetTransport());
	TrajetSimple tmp2(tc.list[1]->GetDepart(), tc.list[1]->GetArrivee(), tc.list[1]->GetTransport());
	if (nb_trajets <=taille){
		
		collection[nb_trajets] = new TrajetCompose(tmp1, tmp2,tc.nb_elements);
		//idee a tester : prendre un parametre un pointeur (Trajet* tc) et dire que collection[nb_trajets] = tc;
		//collection[nb_trajets] = tc;
		nb_trajets++;
	}
	else{
		taille *=2;
		Trajet ** tmp = new Trajet*[taille*2];
		for (int i =0; i<nb_trajets;i++){
			tmp[i]= collection[i];
		}
		tmp[nb_trajets] = new TrajetCompose(tmp1, tmp2, tc.nb_elements);
		/*if (tc.curr_pos>2){
			tmp[nb_trajets]->Ajouter(tc.list[2]);
		}*/
		nb_trajets++;
		delete [] collection;
		collection = tmp;
	}
	
	//recopier les autres sous trajets d'un trajet compose s'il y en a
	/*if (tc.curr_pos >2){
		for (int i = tc.curr_pos; i<tc.nb_elements;i++){
			TrajetSimple tmp_i (tc.list[i]->GetDepart(), tc.list[i]->GetArrivee(), tc.list[i]->GetTransport());
			collection[nb_trajets]->list[i] = TrajetSimple(tmp_i);
		}
	}*/
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
	for (int i =0; i<nb_trajets;i++){
		delete collection[i];
	}
	delete [] collection;
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

