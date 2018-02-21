#include <iostream>
#include <vector>
using namespace std;

#include "Estudiant.hh"


vector<Estudiant> simplificar(const vector<Estudiant>& v, int nuevo_tam) 
{
	vector<Estudiant> simp(nuevo_tam);
	int dni = v[0].consultar_DNI();
	Estudiant y(dni);
	simp[0] = y;
	if(v[0].te_nota()) simp[0].afegir_nota(v[0].consultar_nota());
	int j = 0;
	for (int i = 1; i < v.size(); ++i) {
		if (v[i].consultar_DNI() != dni) {
			++j;
			dni = v[i].consultar_DNI();
			Estudiant x(dni);
			simp[j] = x;
			if(v[i].te_nota()) simp[j].afegir_nota(v[i].consultar_nota());
		}
		else if (v[i].te_nota()){
			if (simp[j].te_nota()) {
				if (simp[j].consultar_nota() < v[i].consultar_nota()) simp[j].modificar_nota(v[i].consultar_nota());
			}
			else simp[j].afegir_nota(v[i].consultar_nota());
		}
	}
	return simp;
}

void escribir(const vector<Estudiant>& v)
{
	for (int i = 0; i < v.size(); ++i) v[i].escriure();
}

int main() 
{
	int tam, dni = -1, ntam = 0;
	cin >> tam;
	vector<Estudiant> est(tam);
	for (int i = 0; i < tam; ++i) {
		est[i].llegir();
		if (est[i].consultar_DNI() != dni) ++ntam;
		dni = est[i].consultar_DNI();
	}
	vector<Estudiant> simplificado(ntam);
	simplificado = simplificar(est, ntam);
	escribir(simplificado);
}
