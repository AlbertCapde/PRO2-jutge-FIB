#include "LlistaIOEstudiant.hh"


void LlegirLlistaEstudiant(list<Estudiant>& l) {
	list<Estudiant>::iterator it = l.end();
	bool fi = false;
	Estudiant est;
	while(!fi) {
		est.llegir();
		fi = (est.consultar_DNI() == 0 and est.consultar_nota() == 0);
		if (!fi) l.insert(it, est);
	}
}

/*void EscriureLlistaEstudiant(list<Estudiant>& l) {
	list<Estudiant>::const_iterator it = l.begin();
	while(it != l.end()) {
		(*it).escriure();
		++it;
	}
}*/
