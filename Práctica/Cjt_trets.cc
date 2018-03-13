/** @file Cjt_trets.cc
    @brief Codi de la classe Cjt_trets
*/

#include "Cjt_trets.hh"

Cjt_trets::Cjt_trets() {}

bool Cjt_trets::existeix_tret(string tret) 
{
// No es constant, ja que, al ser un diccionari si es consulta i no existeix es crea
	bool existeix = true;
	map<string, Tret>::const_iterator it = trets.find(tret);
	if(it == trets.end()) {// Si no hi es s'elimina el tret creat al consultar
		existeix = false;
		trets.erase(tret);
	}
	return existeix;
}

void Cjt_trets::afegir(string tret, int id, Cjt_individus& x) 
{
	x.afegir_tret(id, tret);// S'afegeix el tret a l'individu
	trets[tret].afegir_individu(id, x);// Si no existeix en el conjunt es crea
}

void Cjt_trets::treure(string tret, int id, Cjt_individus& x) 
{
	x.treure_tret(id, tret);// Es true el tret de l'individu
	trets[tret].treure_individu(id, x);
	if(trets[tret].buit()) trets.erase(tret);// Si el tret queda buit s'elimina
}

void Cjt_trets::escriure_tret(string tret) 
{
	cout << "  " << tret << endl;
	trets[tret].escriure();
}
