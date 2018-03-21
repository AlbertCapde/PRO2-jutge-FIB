/** @file Cjt_individus.hh
    @brief Especificació de la classe Cjt_individus
*/

#ifndef _CJT_INDIVIDUS_
#define _CJT_INDIVIDUS_

#include "Individu.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/*
 * Classe Cjt_individus
 */

/** @class Cjt_individus
	@brief Representa el conjunt d'individus d'un experiment.
	
	Ofereix operacions de lectura de l'experiment, escriptura i consultes d'un individu.
*/

class Cjt_individus {

private:

	/** @brief Arbre genealogic, on cada node té l'identificador d'un individu */
	BinTree<int> arbregen;

	/** @brief Vector d'individus

		Ordenat creixentment segons el seu identificador */
	vector<Individu> individus;
	
public:

	// Constructora

	/** @brief Creadora per defecte
		@pre cert
		@post El resultat es un Cjt_individus buit
	*/
	Cjt_individus();
	
	// Modificadores
	
	/** @brief Modificadora dels individus que presenten el tret
		\pre cert
		\post S'afegeix el tret a l'individu
	*/
	void afegir_tret(int id, string tret);
	
	/** @brief Modificadora dels individus que presenten el tret
		\pre cert
		\post Es treu el tret de l'individu
	*/
	void treure_tret(int id, string tret);
	
	// Consultores
	
	/** @brief Consulta els cromosomes d'un individu
		\pre cert
		\post Indica els cromosomes d'un individu
	*/
	Cromosomes consultar_crom_individu(int id) const;
	
	/** @brief Consulta si l'individu té el tret
		\pre cert
		\post Indica si presenta el tret
	*/
	bool individu_te_tret(int id, string tret);
	
	// Lectura i escriptura

	/** @brief Operació de lectura
		\pre Estàn preparats al canal estàndard d'entrada un enter n >= 3,
		que representa el nombre d'individus, i el nombre de gens de cada 
		cromosoma m >= 1
		\post El parametre implícit conté el conjunt d'individus llegit
		del canal estandard d'entrada
	*/
	void llegir(int n, int m);
	
	/** @brief Operació d'escriptura de l'individu
      \pre cert
      \post S'escriu pel el canal de sortida estàndard l'individu
    */
	void escriure(int id) const;
	
	/** @brief Operació d'escriptura de la distribució del tret
      \pre cert
      \post S'escriu pel canal de sortida estàndard la distribució
	*/
	void escriure_distribucio_tret(string tret);
	
private:

	/** @brief Operació de lectura de l'arbre genealògic
		\pre cert
		\post Es llegeix pel canal estàndard d'entrada la relació de parentiu i es 
		forma l'arbre genealògic
	*/
	static void llegir_arbre_genealogic(BinTree<int>& abregen);
	
	/** @brief Operació d'escriptura de la distribució del tret
		\pre cert
		\post S'escriu pel canal de sortida estàndard la distribució d'un tret en inordre
	*/
	static void escriure_distribucio(const BinTree<int>& dist);

	/** @brief Operació que obté la distribució d'un tret
		\pre cert
		\post Es forma un nou subarbre de la distribució
	*/
	void distribucio(const BinTree<int>& a, BinTree<int>& dist, string tret);
};
#endif
