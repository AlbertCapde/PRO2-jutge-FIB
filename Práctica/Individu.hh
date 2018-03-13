/** @file Individu.hh
    @brief Especificació de la classe Individu
*/

#ifndef _INDIVIDU_
#define _INDIVIDU_

#include "Cromosomes.hh"

#ifndef NO_DIAGRAM
#include <set>
#endif

/*
 * Classe Individu
 */

/** @class Individu
    @brief Representa les característiques d'un individu.
    
    Conté informació sobre l'individu, el parell de gens i els trets que presenta.
*/

class Individu {

private:

	/** @brief Cromosomes de l'individu */
	Cromosomes crom;

	/** @brief Conjunt dels trets que presenta */
	set<string> trets;

public:
	
	// Constructores
	
	/** @brief Creador per defecte
		@pre cert
		@post El resultat es un individu buit
	*/
	Individu();
	
	// Modificadores
	
	/** @brief Modificadora dels trets que presenta l'individu
		\pre L'individu no presenta el tret
		\post S'afegeix el tret a l'individu
	*/
	void afegir(string tret);
	
	/** @brief Modificadora dels trets que presenta l'individu
		\pre L'individu presenta el tret
		\post Es treu el tret de l'individu
	*/
	void treure(string tret);
	
	// Consultores
	
	/** @brief Consulta els cromosomes de l'individu
		\pre cert
		\post Indica els cromosomes
	*/
	Cromosomes consultar_crom() const;
	
	/** @brief Consulta si l'individu presenta el tret
		\pre cert
		\post Indica si presenta el tret
	*/
	bool te_tret(string tret);

	// Lectura i escriptura
	
	/** @brief Operació de lectura
		\pre cert
		\post El parametre implicit conté els cromosomes d'aquest
	*/
	void llegir_individu(int m);
	
	/** @brief Operació de escriptura
		\pre cert
		\post S'escriu pel el canal de sortida estàndard els cromosomes i els trets que presenta
	*/
	void escriure_individu() const;
};
#endif
