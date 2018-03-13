OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_individus.o Cjt_trets.o Individu.o Tret.o Cromosomes.o
	g++ -o program.exe *.o

Cjt_trets.o: Cjt_trets.cc Cjt_trets.hh Tret.hh Cjt_individus.hh
	g++ -c Cjt_trets.cc $(OPCIONS) 

Tret.o: Tret.cc Tret.hh Cjt_individus.hh Cromosomes.hh BinTree.hh
	g++ -c Tret.cc $(OPCIONS)
 
Cjt_individus.o: Cjt_individus.cc Cjt_individus.hh Individu.hh Cromosomes.hh BinTree.hh
	g++ -c Cjt_individus.cc $(OPCIONS) 

Individu.o: Individu.cc Individu.hh Cromosomes.hh
	g++ -c Individu.cc $(OPCIONS) 

Cromosomes.o: Cromosomes.cc Cromosomes.hh
	g++ -c Cromosomes.cc $(OPCIONS) 

program.o: program.cc Cjt_individus.hh Cjt_trets.hh
	g++ -c program.cc $(OPCIONS) 

practica.tar: Cjt_trets.hh Tret.hh Cjt_individus.hh Individu.hh Cromosomes.hh program.cc Cjt_trets.cc Tret.cc Cjt_individus.cc Individu.cc Cromosomes.cc Makefile
	tar -cvf practica.tar Cjt_trets.hh Tret.hh Cjt_individus.hh Individu.hh Cromosomes.hh program.cc Cjt_trets.cc Tret.cc Cjt_individus.cc Individu.cc Cromosomes.cc Makefile

clean:
	rm *.o
	rm *.exe

