/** @file Tret.cc
    @brief Codi de la classe Tret
*/

#include "Tret.hh"

Tret::Tret() {}

void Tret::calcular_combinacio(const Cjt_individus& x) 
{
	set<int>::const_iterator it = ids.begin();
	combinacio = x.consultar_crom_individu(*it);// Cobinacio es igual a cromosomes del primer individu
	++it;
	while (it != ids.end()) {
		Cromosomes crom;
		crom = x.consultar_crom_individu(*it);
		combinacio.combinacio_crom(crom);
		++it;
	}
}

void Tret::afegir_individu(int id, const Cjt_individus& x) 
{
// Al afegir nou individu no es necesari recalcular tota la combinacio, 
// només afegir les noves restriccions a les ja presents.
	ids.insert(id);
	Cromosomes comb;
	comb = x.consultar_crom_individu(id);
	if(ids.size() == 1) combinacio = comb;// En cas de que només hi hagi un individu que el presenti
	else {
		Cromosomes comb;
		comb = x.consultar_crom_individu(id);
		combinacio.combinacio_crom(comb);
	}
}

void Tret::treure_individu(int id, const Cjt_individus& x)
{
	ids.erase(id);
	if(!ids.empty()) calcular_combinacio(x);// Si no es queda buit es calcula nova combinació
}

bool Tret::buit() const 
{
	return ids.empty();
}

void Tret::escriure() const
{
	combinacio.escriure_cromosomes();
	set<int>::const_iterator it = ids.begin();
	while (it != ids.end()) {
		cout << "  " << *it << endl;
		++it;
	}
}
