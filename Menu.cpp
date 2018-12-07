#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include "Catalogue.h"
using namespace std;

int main(){
	const int MAX_LENGTH=10;
	int choix;
	int nbElements;
	char* villeA=new char[MAX_LENGTH];
	char* villeB=new char[MAX_LENGTH];
	char* transport=new char[MAX_LENGTH];
	Catalogue C;
	TrajetSimple TS[MAX_LENGTH];
	int index=0;
	bool arret=false; 


	while(!arret){
		//C.Afficher();
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
				//TrajetSimple t(villeA,villeB,transport);
				TS[index]=TrajetSimple(villeA,villeB,transport);

				C.Ajouter(&TS[index]);
				
				cout<<"ajoute"<<endl;
				index++;
				break;
			}

			case 2:
				
				cout<<"vous avez choisi l'ajout de Trajetcompose"<<endl;

						cout<<"veuillez renseigner le nombre de trajets a ajouter"<<endl;
				cin>>nbElements;
				
				cout<<"veuillez renseigner la ville de depart, la ville d'arrivee et le moyen de transport du 1er trajet "<<endl;
				cin>>villeA>>villeB>>transport;
				static TrajetSimple t1(villeA,villeB,transport);

				cout<<"veuillez renseigner la ville de depart, la ville d'arrivee et le moyen de transport du 2e trajet"<<endl;
				cin>>villeA>>villeB>>transport;
				static TrajetSimple t2(villeA,villeB,transport);

				static TrajetCompose TC(t1,t2,nbElements);

				for (int i=3;i<=nbElements;i++)	{
					cout<<"veuillez renseigner la ville de depart, la ville d'arrivee et le moyen de transport du trajet"<<endl;
				cin>>villeA>>villeB>>transport;
				TrajetSimple t3(villeA,villeB,transport);
					TC.Ajouter(t3);
				}
				
				C.Ajouter(&TC);
				break;
				

			case 3:
				cout<<"vous avez choisi la recherche de trajets"<<endl;	
				cout<<"veuillez renseigner la ville de depart, la ville d'arrivee "<<endl;
				cin>>villeA>>villeB;
				endl(cout);
				C.Recherche(villeA,villeB);
				break;

			case 4:
				cout<<"vous avez choisi l'affichage des trajets: "<<endl;
				C.Afficher();
				break;

			case 5:
				cout<<"Au revoir"<<endl;
				arret=true;
				break;
		}
		endl(cout);
	}
    	delete [] TS;
	delete [] villeA;
	delete [] villeB;
	delete [] transport;
	return 0;
}
