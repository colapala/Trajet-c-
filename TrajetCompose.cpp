/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include <cstring>
#define MAP

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void TrajetCompose::Afficher(){
	cout << "Trajet compose : " <<endl;
  for (int i=0; i<curr_pos;i++){
	cout << "Sous-trajet " << i+1 <<" : " << endl;
	list[i]->Afficher();
  }
}

const char* TrajetCompose::GetDepart() const{
	const char* a = list[0]->GetDepart();
	return a;
}
const char* TrajetCompose::GetArrivee() const{
	const char* b=list[curr_pos-1]->GetArrivee();
	return b;
}

const char* TrajetCompose::GetTransport() const{
	return "pas de transport pour un trajet compose";
}

void TrajetCompose::Ajouter(const TrajetSimple &t){
  if (curr_pos < nb_elements){
    list[curr_pos]= new TrajetSimple(t.GetDepart(),t.GetArrivee(),t.GetTransport());
    curr_pos++;
  }
  else {
		nb_elements *=2;
		Trajet ** tmp = new Trajet*[nb_elements];
		for (int i =0; i<curr_pos;i++){
			tmp[i]= list[i];
		  //tmp[i] =new TrajetSimple(list[i]->GetDepart(), list[i]->GetArrivee(), list[i]->GetTransport());
		  //delete list[i];
		}
		tmp[curr_pos] = new TrajetSimple(t.GetDepart(), t.GetArrivee(), t.GetTransport());
		curr_pos++;
		delete [] list;
		list = tmp;
	//delete tmp; le pointeur tmp est supprime par defaut a la fin de ajouter ?
	
  }
}
//------------------------------------------------- Surcharge d'opérateurs
TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel de l'operateur = du <TrajetCompose>" << endl;
#endif
	/*nb_elements=unTrajetCompose.nb_elements;
	curr_pos=unTrajetCompose.curr_pos;*/
	
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
//TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose ):Trajet(unTrajetCompose.list[0].Depart, unTrajetCompose.list[unTrajetCompose.nb_elements-1].Arrivee)
TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
	nb_elements=unTrajetCompose.nb_elements;
	curr_pos = unTrajetCompose.curr_pos;
	list = new Trajet*[nb_elements];
	for (int i =0; i<curr_pos;i++){
		list[i] = new TrajetSimple(unTrajetCompose.list[i]->GetDepart(), unTrajetCompose.list[i]->GetArrivee(), unTrajetCompose.list[i]->GetTransport());
	}
} //----- Fin de TrajetCompose (constructeur de copie)


/*TrajetCompose::TrajetCompose ( int nbelements ){
	nb_elements = nbelements;
	list = new Trajet*[nb_elements];
}*/
//TrajetCompose::TrajetCompose (TrajetSimple t1,TrajetSimple t2, int nbelements ):Trajet(t1.Depart,t2.Arrivee)
TrajetCompose::TrajetCompose (const TrajetSimple &t1,const TrajetSimple &t2, int nbelements )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
	
    nb_elements = nbelements;
    list = new Trajet*[nb_elements];
    curr_pos = 2;
 	

    list[0]= new TrajetSimple(t1.GetDepart(), t1.GetArrivee(), t1.GetTransport());
    list[1]= new TrajetSimple (t2.GetDepart(), t2.GetArrivee(), t2.GetTransport());
    
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	cout <<"this pointer points to " <<this <<endl;
	for (int i =0; i<curr_pos;i++){
		delete list[i];
	}
    delete [] list;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

