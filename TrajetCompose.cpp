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
//#define MAP

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC


//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher()
// Algorithme :
//
{
	cout << "Trajet compose : " <<endl;
  for (int i=0; i<curr_pos;i++){
	cout << "Sous-trajet " << i+1 <<" : " << endl;
	list[i]->Afficher();
  }
}

const char* TrajetCompose::GetDepart() const
// Algorithme :
//
{
	const char* a = list[0]->GetDepart();
	return a;
}

const char* TrajetCompose::GetArrivee() const
// Algorithme :
//
{
	const char* b=list[curr_pos-1]->GetArrivee();
	return b;
}

const char* TrajetCompose::GetTransport() const
// Algorithme :
//
{
	return "pas de transport pour un trajet compose";
}

bool TrajetCompose::VerifContrainte(const TrajetSimple& nouvTrajet)
// Algorithme :
//  Renvoie vrai lorsque la ville de départ du TrajetSimple à ajouter correspond à la ville d'arrivée du TrajetSimple précédemment rentré dans TrajetCompose
// Renvoie faux sinon
{
	if (!strcmp(nouvTrajet.GetDepart(), list[curr_pos-1]->GetArrivee())){
		return true;
	}
	else {
		return false;
	}
}

void TrajetCompose::Ajouter(const TrajetSimple &t)
// Algorithme :
// Ajoute le TrajetSimple à la liste s'il rempli les conditions du TrajetCompose et si la liste n'est pas totalement remplie, réallloue de la mémoire sinon
{
	if (VerifContrainte(t) ==true){
	  if (curr_pos < nb_elements){
		list[curr_pos]= new TrajetSimple(t);
		curr_pos++;
	  }
	  else {
			nb_elements *=2;
			Trajet ** tmp = new Trajet*[nb_elements];
			for (int i =0; i<curr_pos;i++){
				tmp[i]= list[i];
			}
			tmp[curr_pos] = new TrajetSimple(t);
			curr_pos++;
			delete [] list;
			list = tmp;
	  }
	}
	else {
		cout << "Opération échouée : il faut que la ville de départ corresponde à la ville d'arrivée du sous-trajet précédent" <<endl;
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
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
// Copie les paramètres de unTrajetCompose dans les paramètres du TrajetCompose appelant la méthode
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
 	
	if(!strcmp(t1.GetArrivee(),t2.GetDepart())){
    list[0]= new TrajetSimple(t1.GetDepart(), t1.GetArrivee(), t1.GetTransport());
    list[1]= new TrajetSimple (t2.GetDepart(), t2.GetArrivee(), t2.GetTransport());
	}else{
	cerr<<"erreur"<<endl;
	}
    
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
	//cout <<"this pointer points to " <<this <<endl;
	for (int i =0; i<curr_pos;i++){
		delete list[i];
	}
    delete [] list;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

