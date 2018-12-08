/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined ( TRAJETCOMPOSE_H )
#define TRAJETCOMPOSE_H
#include "Trajet.h"
#include "TrajetSimple.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
//
//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
  
  virtual void Afficher();
    // Mode d'emploi :
    // Affiche "Trajet Compose :", puis "Sous-trajet " et son numéro, puis affiche les villes de départ, d'arrivée et le moyen de transport de chaque sous trajet contenu dans le TrajetCompose
    // Contrat :
    // aucun

  void Ajouter(const TrajetSimple &t);
    // Mode d'emploi :
    // Ajoute un TrajetSimple au TrajetCompose
    // Contrat :
    // aucun

  const char* GetDepart() const ;
    // Mode d'emploi :
    //  Renvoie la ville de départ du TrajetCompose
    // Contrat :
    // aucun

  const char* GetArrivee() const;
    // Mode d'emploi :
    // Renvoie la ville d'arrivée du TrajetCompose
    // Contrat :
    // aucun

  const char* GetTransport() const;
    // Mode d'emploi :
    // Renvoie le moyen de transport du TrajetCompose
    // Contrat :
    // aucun

  bool VerifContrainte(const TrajetSimple& nouvTrajet);
    // Mode d'emploi :
    // Teste si le TrajetSimple respecte les contraintes imposées par le TrajetCompose
    // Contrat :
    // aucun
  
//------------------------------------------------- Surcharge d'opérateurs
    TrajetCompose & operator = ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi :
    // 
    // Contrat :
    // aucun


//-------------------------------------------- Constructeurs - destructeur
    TrajetCompose ( const TrajetCompose & unTrajetCompose );
    // Mode d'emploi (constructeur de copie) :
    // Construit un TrajetCompose à partir d'un TrajetCompose 
    // Contrat :
    // aucun

    TrajetCompose (const TrajetSimple &t1, const TrajetSimple &t2, int nbelements );
    // Mode d'emploi :
    // Construit un TrajetCompose à partir de 2 TrajetSimples et d'un nombre d'éléments à rentrer
    // Contrat :
    // aucun

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // Destructeur de TrajetCompose
    // Contrat :
    // aucun
  
    friend class Catalogue;

//------------------------------------------------------------------ PRIVE

 protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int nb_elements;
    int curr_pos;
    Trajet ** list;
};

//-------------------------------- Autres définitions dépendantes de <TrajetCompose>

#endif // TRAJETCOMPOSE_H
