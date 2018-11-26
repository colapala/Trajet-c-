#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

int main(){
  TrajetSimple t("Lyon","Marseille","bateau");
  // t.Afficher();
  TrajetSimple t1("marseille","Paris","train");
  TrajetCompose TC(t,t1,4);
 TC.Afficher();
	/*TrajetSimple t2("Paris","Dijon","Avion");
	TC.Ajouter(t2);
	TC.Afficher();*/
	return 0;
}
