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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	virtual void Afficher();
	virtual const char* GetDepart() =0;
	virtual const char* GetArrivee() =0;
	//virtual const char* GetTransport() =0;
//------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator = ( const Trajet & unTrajet );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Trajet ( const Trajet & unTrajet );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    // Mode d'emploi :
    //
    // Contrat :
    //
    Trajet();
    virtual ~Trajet ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

    protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

        /*char * Depart;
        char *Arrivee;  */ 
};

//-------------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H

