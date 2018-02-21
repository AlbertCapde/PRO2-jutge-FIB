#include "Cjt_estudiants.hh"


void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b)
  /* Pre: el paràmetre implícit no està ple */
{
	int dni= est.consultar_DNI();
	int i = cerca_dicot(vest, 0, nest-1, dni);
	if (vest[i].consultar_DNI() == dni) b = true;
	else {
		b = false;
		++nest;
		int j = nest-1;
		while (j > i) {
			vest[j] = vest[j-1];
			--j;
		}
		vest[j] = est;
		if (est.te_nota()) {
			int x = est.consultar_nota();
			if (x == 10) ++intervals[9];
			else ++intervals[x];
		}
	}
}
  /* Post: b = indica si el p.i. original conté un estudiant amb el dni d'est;
     si b = fals, s'ha afegit l'estudiant est al paràmetre implícit */

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b)
  /* Pre: cert */
{
	int i = 0;
	bool trobat = false;
	while (i < nest and !trobat) {
		if (dni == vest[i].consultar_DNI()) trobat = true;
		++i;
	}
	if(!trobat) b = false;
	else {
		b = true;
		if (vest[i-1].te_nota()) {
			int x = vest[i-1].consultar_nota();
			if (x == 10) --intervals[9];
			else --intervals[x];
		}
		for (int j = i; j < nest; ++j) vest[j-1] = vest[j];
		--nest;
	}
	
}
  /* Post: b indica si el paràmetre implícit original tenia un estudiant 
     amb el dni dni; si b, aquest estudiant ha quedat eliminat
     del paràmetre implícit */
