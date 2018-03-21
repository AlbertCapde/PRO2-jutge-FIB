/** @file Individu.cc
    @brief Codi de la classe Individu
*/

#include "Individu.hh"

Individu::Individu() {}

Cromosomes Individu::consultar_crom() const
{
	return crom;
}

bool Individu::te_tret(string tret)
{
// No es constant, ja que, al ser un conjunt si es consulta i no existeix es crea
	bool te = true;
	set<string>::const_iterator it = trets.find(tret);
	if(it == trets.end()) {
		te = false;
		trets.erase(tret);
	}
	return te;
}

void Individu::afegir(string tret)
{
	trets.insert(tret);
}

void Individu::treure(string tret)
{
	trets.erase(tret);
}

void Individu::llegir_individu(int m)
{
	crom.llegir_cromosomes(m);
}

void Individu::escriure_individu() const
{
	crom.escriure_cromosomes();
	set<string>::iterator it = trets.begin();
	while (it != trets.end()) {
		cout << "  ";
		cout << *it << endl;
		++it;
	}
}
