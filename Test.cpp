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

  TrajetSimple t3 ("Annecy", "Lyon", "Bus");
  TC.Ajouter(t3);
  TC.Afficher();
  //TrajetCompose TC2(
  
  Catalogue C;
  C.Ajouter(t);
  C.Ajouter(TC);
  //C.Ajouter(TC);
  //C.Afficher();
  
  //cout << "depart :" <<TC.GetDepart() <<endl;
	/*TrajetSimple t2("Paris","Dijon","Avion");
	TC.Ajouter(t2);
	TC.Afficher();*/
	return 0;
}
