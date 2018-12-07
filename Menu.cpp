#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include "Catalogue.h"
#include "Menu.h"
using namespace std;
//!! Ce programme peut faire des erreurs dûes à l'allocation de TS** de taille MAX_LENGTH, elles ne sont pas importantes, elles veulent juste dire que tout l'espace n'est pas utilisé
int main(){
	const int MAX_LENGTH=10;
	int choix;
	int nbElements;
	char* villeA=new char[MAX_LENGTH];
	char* villeB=new char[MAX_LENGTH];
	char* transport=new char[MAX_LENGTH];
	Catalogue C;
	TrajetSimple** TS=new TrajetSimple*[MAX_LENGTH];
	TrajetCompose** TC=new TrajetCompose*[MAX_LENGTH];		
	int indexSimple=0;
	int indexComp=0;
	bool arret=false; 


	while(!arret){
		cout<<"Bonjour, et bienvenue dans notre catalogue de trajets"<<endl;
		cout<<"Tapez 1 pour ajouter un TrajetSimple"<<endl;
		cout<<"Tapez 2 pour ajouter un TrajetCompose"<<endl;
		cout<<"Tapez 3 pour faire une recherche"<<endl;
		cout<<"Tapez 4 pour Afficher le catalogue"<<endl;
		cout<<"Tapez 5 pour quitter le catalogue"<<endl;


		cin>>choix;
		endl(cout);
		switch(choix){

			case 1: 
				
				cout<<"vous avez choisi l'ajout de TrajetSimple"<<endl;
				cout<<"veuillez renseigner la ville de depart, la ville d'arrivee et le moyen de transport"<<endl;

				cin>>villeA>>villeB>>transport;
				TS[indexSimple]=new TrajetSimple(villeA,villeB,transport);
				C.Ajouter(TS[indexSimple]);
				
				indexSimple++;
				break;
				
			
			case 2:
				
				cout<<"vous avez choisi l'ajout de Trajetcompose"<<endl;

						cout<<"veuillez renseigner le nombre de trajets a ajouter"<<endl;
				cin>>nbElements;
				
				for (int i=0;i<nbElements;i++)	{
					cout<<"veuillez renseigner la ville de depart, la ville d'arrivee et le moyen de transport du "<<i+1<<"e trajet"<<endl;
					cin>>villeA>>villeB>>transport;
					TS[indexSimple]=new TrajetSimple(villeA,villeB,transport);
					if(i==1){
						TC[indexComp]=new TrajetCompose(*TS[indexSimple-1],*TS[indexSimple],nbElements);
					}else if(i>1){
					TC[indexComp]->Ajouter(*TS[indexSimple]);
					}
					indexSimple++;
				}
				C.Ajouter(TC[indexComp]);
				indexComp++;
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
				endl(cout);
				C.Afficher();
				break;

			case 5:
				cout<<"Au revoir"<<endl;
				arret=true;
				break;
		}
		endl(cout);
	}

	for (int i =0; i<MAX_LENGTH;i++){
		delete TS[i];
	}
    	delete [] TS;

	for (int i =0; i<MAX_LENGTH;i++){
		delete TC[i];
	}
    	delete [] TC;

	delete [] villeA;
	delete [] villeB;
	delete [] transport;
	return 0;
}
