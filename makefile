.PHONY: clean

Test.ex: Trajet.o TrajetSimple.o TrajetCompose.o Catalogue.o

main: Test.o Trajet.o
	g++ -g Test.o Trajet.o -o main
	valgrind --leak-check=yes ./main

Trajet.o: Trajet.cpp Trajet.h

TrajetSimple.o: TrajetSimple.cpp TrajetSimple.h

TrajetCompose.o: TrajetCompose.cpp TrajetCompose.h

Catalogue.o: Catalogue.cpp Catalogue.h

%.ex: 
	g++ -g $^ -o $@
	valgrind --leak-check=yes ./$@

%.o: %.cpp 
	g++ -ansi -pedantic -Wall -std=c++11 -c $< -o $@ 

clean : 
	rm -rf Test.ex core
