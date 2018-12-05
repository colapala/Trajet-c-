#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include "Catalogue.h"
using namespace std;

int main(){
  TrajetSimple t("Lyon","Marseille","bateau");
  
  TrajetSimple t1("marseille","Paris","train");
  TrajetCompose TC(t,t1,2);

  TrajetSimple t2 ("Cherbourg", "Paris", "train");
  TC.Ajouter(t2);

  TrajetSimple t3 ("Annecy", "Londres", "Bus");
  TC.Ajouter(t3);
  //TC.Afficher();
  //TrajetCompose TC2(
  
  Catalogue C;
  C.Ajouter(t);
  TrajetCompose* TC_pt = & TC;
  C.Ajouter(TC_pt);
  C.Ajouter(t2);
  C.Ajouter(t3);
  C.Afficher();
  C.Recherche("Lyon","Londres");
  
  //cout << "depart :" <<TC.GetDepart() <<endl;
  //cout << c.collection[
  //cout<<"Arrivee: "<<TC.GetArrivee()<<endl;
	/*TrajetSimple t2("Paris","Dijon","Avion");
	TC.Ajouter(t2);
	TC.Afficher();*/
  //delete TC_pt;

	return 0;
}
