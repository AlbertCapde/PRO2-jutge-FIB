/** @file Cromosomes.cc
    @brief Codi de la classe Cromosomes
*/

#include "Cromosomes.hh"

Cromosomes::Cromosomes() {}

void Cromosomes::combinacio_crom(const Cromosomes& x)
{
	vector<char> comb;
	comb = x.crom;
	int tam = (crom.size())/2;
	int i = 0;
	while(i<tam) {
		if((crom[i] != comb[i]) or (crom[tam+i] != comb[tam+i])) {
			crom[i] = '-';
			crom[tam+i] = '-';	
		}
		++i;
	}
}

void Cromosomes::llegir_cromosomes(int m)
{
// Esl parell de cromosomes es llegeix com a un únic vector, més fàcil de tractar,
// i com es té un parell el tamany del vector sempre serà parell.
	int tam = 2*m;
	crom = vector<char>(tam);
	for (int i = 0; i < tam; ++i) cin >> crom[i];
}

void Cromosomes::escriure_cromosomes() const
{
// S'esecriu el vector en dos meitats, és a dir, el parell de cromosomes
	int tam = crom.size();
	int i = 0;
	cout << "  ";
	while (i < tam/2) {
		cout << crom[i];
		++i;
	}
	cout << endl;
	cout << "  ";
	while(i < tam) {
		cout << crom[i];
		++i;	
	}
	cout << endl;
}
