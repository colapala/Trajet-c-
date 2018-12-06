#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include "Catalogue.h"
using namespace std;

int main(){
	const int MAX_LENGTH=10;
	int choix;
	char* villeA=new char[MAX_LENGTH];
	char* villeB=new char[MAX_LENGTH];
	char* transport=new char[MAX_LENGTH];
	Catalogue C;
	bool arret=false; 


	while(!arret){
		C.Afficher();
		cout<<"Bonjour, et bienvenue dans notre catalogue de trajets"<<endl;
		cout<<"Tapez 1 pour ajouter un TrajetSimple"<<endl;
		cout<<"Tapez 2 pour ajouter un TrajetCompose"<<endl;
		cout<<"Tapez 3 pour faire une recherche"<<endl;
		cout<<"Tapez 4 pour Afficher le catalogue"<<endl;
		cout<<"Tapez 5 pour quitter le catalogue"<<endl;


		cin>>choix;

		switch(choix){

			case 1: 
				{
				cout<<"vous avez choisi l'ajout de TrajetSimple"<<endl;
				cout<<"veuillez renseigner la ville de depart, la ville d'arrivee et le moyen de transport"<<endl;

				cin>>villeA>>villeB>>transport;
				//cout << villeA << endl;
				TrajetSimple t(villeA,villeB,transport);
				C.Ajouter(&t);
				
				cout<<"ajoute"<<endl;
				break;
			}

			case 2:
				{
				cout<<"vous avez choisi l'ajout de Trajetcompose"<<endl;
				break;
				}

			case 3:
				{
				cout<<"vous avez choisi la recherche de trajets"<<endl;	
				cin>>villeA>>villeB;
				C.Recherche(villeA,villeB);
				break;
				}

			case 4:
				{
				cout<<"vous avez choisi l'affichage des trajets: "<<endl;
				C.Afficher();
				break;
				}

			case 5:
				{
				cout<<"Au revoir"<<endl;
				arret=true;
				break;
				}
		}
		cout<<"  "<<endl;
	}

	delete [] villeA;
	delete [] villeB;
	delete [] transport;
	return 0;
}
