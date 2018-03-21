/** @mainpage

	En el mòdul program.cc es troba el programa principal.
	Per l'aplicació per a un laboratori de biologia, necesitarem un mòdul
	per representa l'Individu, un altre pel posible Tret, a més de dos mòduls per a
	cada conjunt d'aquests, Cjt_individus i Cjt_trets, i finalment un 
	mòdul Cromosomes. 

*/

/** @file program.cc

    @brief Programa principal
    
    <em>Aplicació per a un laboratori de biologia</em>.
*/

#include "Cjt_trets.hh"
#include "Cjt_individus.hh"

int main() 
{
	Cjt_individus i;
	Cjt_trets t;
	string op; // Nom de les operacions
	cin >> op;
	while(op!="fi") {
		string tret; // Nom del tret
		int id, n, m; // Identificador, nombre d'invidus i nombre de gens
		
		if(op=="experiment") {
			cin >> n >> m;
			i.llegir(n, m);
			cout << op << ' ' << n << ' ' << m << endl;
		}
		else if(op=="afegir") {
			cin >> tret >> id;
			cout << op << ' ' << tret << ' ' << id << endl;
			if(i.individu_te_tret(id, tret)) cout << "  error" << endl;
			else t.afegir(tret, id, i);
		}
		else if(op=="treure") {
			cin >> tret >> id;
			cout << op << ' ' << tret << ' ' << id << endl;
			if(!i.individu_te_tret(id, tret)) cout << "  error" << endl;
			else t.treure(tret, id, i);
		}
		else if(op=="consulta_tret") {
			cin >> tret;
			cout << op << ' ' << tret << endl;
			if(!t.existeix_tret(tret)) cout << "  error" << endl;
			else t.escriure_tret(tret);
		}
		else if(op=="consulta_individu") {
			cin >> id;
			cout << op << ' ' << id << endl;
			i.escriure(id);
		}
		else if(op=="distribucio_tret") {
			cin >> tret;
			cout << op << ' ' << tret << endl;
			if(!t.existeix_tret(tret)) cout << "  error" << endl;
			else i.escriure_distribucio_tret(tret);
		}
		cin >> op;
	}
	cout << "fi" << endl;
}
