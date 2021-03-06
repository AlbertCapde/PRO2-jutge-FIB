#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
  /* Pre: el paràmetre implícit no està ple */
{
	b = false;
	int dni = est.consultar_DNI();
	int j = cerca_dicot(vest, 0, nest-1, dni);
	if (dni == vest[j].consultar_DNI()) b = true;
	else {
		++nest;
		int  i = nest-1;
		while (j < i) {
			vest[i] = vest[i-1];
			--i;
		}
		vest[j] = est;
		if(est.te_nota()) {
			suma_notes += est.consultar_nota();
			++nest_amb_nota;
		}
	}
}
  /* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */


  void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
  /* Pre: cert */   
{
	int i = 0;
	bool exists = false;
	while (!exists && i < nest) {
		if (vest[i].consultar_DNI() == dni) exists = true;
		++i;
	}
	if (!exists) b = false;
	else {
		b = true;
		if (vest[i-1].te_nota()) {
			suma_notes -= vest[i-1].consultar_nota();
			--nest_amb_nota;
		}
		for (int j = i; j < nest; ++j) vest[j-1] = vest[j];
		--nest;
	}
}
 /* Post: b indica si el paràmetre implícit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del paràmetre implícit */
