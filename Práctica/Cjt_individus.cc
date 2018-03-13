/** @file Cjt_individus.cc
    @brief Codi de la classe Cjt_individus
*/

#include "Cjt_individus.hh"

Cjt_individus::Cjt_individus() {}

Cromosomes Cjt_individus::consultar_crom_individu(int id) const
{
	return individus[id-1].consultar_crom();
}

bool Cjt_individus::individu_te_tret(int id, string tret)
{
	return individus[id-1].te_tret(tret);
}

void Cjt_individus::afegir_tret(int id, string tret)
{
	individus[id-1].afegir(tret);
}

void Cjt_individus::treure_tret(int id, string tret)
{
	individus[id-1].treure(tret);
}

void Cjt_individus::llegir_arbre_genealogic(BinTree<int>& a)
{
// Es llegeix l'abre en preordre
	int x;
	cin >> x;
	if (x!=0){
		BinTree<int> l;
		llegir_arbre_genealogic(l);
		BinTree<int> r;
		llegir_arbre_genealogic(r);
		a=BinTree<int>(x,l,r);
	}
}

void Cjt_individus::llegir(int n, int m)
{
	individus = vector<Individu>(n);
	llegir_arbre_genealogic(arbregen);
	for(int j = 0; j < n; ++j) {
		Individu x;
		x.llegir_individu(m);
		individus[j] = x;
	}
}

void Cjt_individus::escriure(int id) const
{
	individus[id-1].escriure_individu();
}

void Cjt_individus::distribucio(const BinTree<int>& a, BinTree<int>& dist, string tret)
{
	if(!a.empty()) {
		int x = a.value();
		if(a.left().empty()) {// Fulla
			if(individus[x-1].te_tret(tret)) dist = BinTree<int>(x);
			else dist = BinTree<int>();
		}
		else {
			BinTree<int> l;
			BinTree<int> r;
			distribucio(a.left(),l,tret);
			distribucio(a.right(),r,tret);
			if(individus[x-1].te_tret(tret)) dist = BinTree<int>(x, l, r);
			else {
				if(l.empty() and r.empty()) dist=BinTree<int>();// Si no té el tret i els progenitors tampoc llavors arbre buit
				else dist=BinTree<int>(-x,l,r);// Si no té el tret pero si els progenitors llavors s'afegeix amb signe '-'
			}
		}
	}
}

void Cjt_individus::escriure_distribucio(const BinTree<int>& a)
{
// Escriu arbre en inordre
	if (not a.empty()) {
		int x = a.value();
		escriure_distribucio(a.left()); 
		cout << " " << x;
		escriure_distribucio(a.right());
	}
}

void Cjt_individus::escriure_distribucio_tret(string tret)
{
	BinTree<int> dist;
	cout << " ";
	distribucio(arbregen, dist, tret);
	escriure_distribucio(dist);
	cout << endl;
}
