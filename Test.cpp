#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <iostream>
#include "Catalogue.h"
using namespace std;

int main(){
  TrajetSimple* t = new TrajetSimple("Lyon","Marseille","bateau");
  
  TrajetSimple t1("Marseille","Paris","train");
  //TrajetCompose TC(*t,t1,2);

  TrajetSimple t2 ("Marseille", "Annecy", "train");
  //TC.Ajouter(t2);

  TrajetSimple t3 ("Annecy", "Londres", "Bus");
  //TC.Ajouter(t3);
  TrajetSimple t4(t3);
  //t4=t3;
  //t4.Afficher();
  //TC.Afficher();
  //TrajetCompose TC2(
  
  Catalogue C;
  C.Ajouter(t);
	
  C.Ajouter(&t2);
  //C.Ajouter(&TC);
  
  C.Ajouter(&t3);
 // C.Afficher();
  C.RechercheAvance("Lyon","Londres");
  //C.Recherche("Lyon","Marseille");
  
  delete t;
	return 0;
}
