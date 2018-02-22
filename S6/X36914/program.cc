#include <iostream>
#include <list>
using namespace std;
#include "Estudiant.hh"
#include "LlistaIOEstudiant.hh"


int main() {
	list<Estudiant> l_est;
	LlegirLlistaEstudiant(l_est);
	//EscriureLlistaEstudiant(l_est);
	int dni;
	cin >> dni;
	list<Estudiant>::const_iterator it = l_est.begin();
	int cont = 0;
	while(it != l_est.end()) {
		if ((*it).consultar_DNI() == dni) ++cont;
		++it;
	}
	cout << dni << " " << cont << endl;
	//(*it).c
}
