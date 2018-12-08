/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
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
    // Mode d'emploi :
    //  Affiche les villes de départ, d'arrivée et le moyen de transport
    // Contrat :
    // aucun

  const char* GetDepart() const;
    // Mode d'emploi :
    //  Renvoie la ville de départ
    // Contrat :
    // aucun

  const char* GetArrivee() const ;
    // Mode d'emploi :
    //  Renvoie la ville d'Arrivée
    // Contrat : 
    // aucun

  const char* GetTransport() const;
    // Mode d'emploi :
    //  Renvoie le moyen de transport
    // Contrat : 
    // aucun

//------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple & operator = ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi :
    //  Fait une Copie des paramètres de unTrajetSimple dans les paramètres du TrajetSimple appelé
    // Contrat : 
    // aucun

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple ( const TrajetSimple & unTrajetSimple );
    // Mode d'emploi (constructeur de copie) :
    //  Construit un trajetSimple à partir d'un trajetSimple
    // Contrat : 
    // aucun

    TrajetSimple(const char* depart,const char * arrivee,const char * t );
    // Mode d'emploi :
    //  Construit un trajetSimple à partir d'une ville de départ, d'une ville d'arrivée et d'un moyen de transport
    // Contrat :
    // aucun
    
    TrajetSimple ();
    // Mode d'emploi :
    //  Constructeur par Défaut
    // Contrat :
    // aucun

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //  Destructeur de TrajetSimple
    // Contrat :
    // aucun


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char* transport;
    char* Depart;
    char* Arrivee;
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H

