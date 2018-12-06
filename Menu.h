/*************************************************************************
                           Menu  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-ma ) il               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Menu> (fichier Menu.h) ----------------
#if ! defined ( Menu_H )
#define Menu_H
//#include "MenuSimple.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Menu>
//
//
//------------------------------------------------------------------------

class Menu 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
//------------------------------------------------- Surcharge d'opérateurs
    Menu & operator = ( const Menu & unMenu );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Menu ( const Menu & unMenu );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    // Mode d'emploi :
    //
    // Contrat :
    //
    Menu();
    virtual ~Menu ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

    protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

        
};

//-------------------------------- Autres définitions dépendantes de <Menu>

#endif // Menu_H

