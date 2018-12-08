/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Trajet.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	void Afficher();
    // Mode d'emploi :
    // Affiche le catalogue
    // Contrat :
    // aucun

	void Ajouter( TrajetSimple* t);
    // Mode d'emploi :
    // Ajoute un TrajetSimple au catalogue
    // Contrat :
    // aucun
    
	void Ajouter(TrajetCompose *tc);
    // Mode d'emploi :
    // Ajoute un TrajetCompose au catalogue
    // Contrat :
    // aucun
    
	void Recherche(const char* depart,const char* arrivee);
    // Mode d'emploi :
    // Recherche un Trajet ayant les villes de départ et d'arrivée correspondantes aux villes placées en paramètres
    // Contrat :
    // aucun
    

//------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & unCatalogue );
    // Mode d'emploi :
    //
    // Contrat :
    // aucun


//-------------------------------------------- Constructeurs - destructeur
    Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    // Construit un catalogue à partir d'un autre catalogue
    // Contrat :
    // aucun

    Catalogue ();
    // Mode d'emploi :
    // Construit un catalogue vide
    // Contrat :
    // aucun

    virtual ~Catalogue ( );
    // Mode d'emploi :
    // Destructeur de catalogue
    // Contrat :
    // aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Trajet ** collection;
	static int taille;
	static int nb_trajets;
	
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H

