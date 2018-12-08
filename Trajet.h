/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-ma ) il               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H
//#include "TrajetSimple.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//
//------------------------------------------------------------------------

class Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

	virtual void Afficher();
    // Mode d'emploi :
    //  
    // Contrat :
    // aucun

	virtual const char* GetDepart() const =0;
    // Mode d'emploi :
    //
    // Contrat :
    // aucun

	virtual const char* GetArrivee() const =0;
    // Mode d'emploi :
    //
    // Contrat :
    // aucun

	virtual const char* GetTransport() const=0;
    // Mode d'emploi :
    //
    // Contrat :
    // aucun

//------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    // aucun

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    // aucun

    
    Trajet();
    // Mode d'emploi :
    //
    // Contrat :
    // aucun

    virtual ~Trajet ( );
    // Mode d'emploi :
    //  Destructeur de Trajets
    // Contrat :
    // aucun

//------------------------------------------------------------------ PRIVE

    protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

