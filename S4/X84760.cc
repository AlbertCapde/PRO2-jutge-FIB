#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
  /* Pre: el paràmetre implícit no està ple */
{
	int dni = est.consultar_DNI();
	int i = cerca_dicot(vest, 0, nest-1, dni);
	if (vest[i].consultar_DNI() == dni) b = true;
	else {
		b = false;
		++nest;
		for (int j = nest-1; j > i; --j) vest[j] = vest[j-1];
		vest[i] = est;
		recalcular_posicio_imax();
	}
}
  /* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */


void Cjt_estudiants::eliminar_estudiants_sense_nota()
  /* Pre: cert */
{
	vector<Estudiant> aux(nest, 0);
	int cont = 0;
	for (int  i = 0; i < nest; ++i) {
		if (vest[i].te_nota()) {
			aux[cont] = vest[i];
			++cont;
		}
	}
	nest = cont;
	for (int i = 0; i < nest; ++i) vest[i] = aux[i];
	if (cont != 0) recalcular_posicio_imax();
}
  /* Post: el paràmetre implicit no conté cap estudiant sense nota */
