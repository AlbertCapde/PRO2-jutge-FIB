/** @file Tret.hh
    @brief Especificació de la classe Tret
*/

#ifndef _TRET_
#define _TRET_

#include "Cjt_individus.hh"
#include "Cromosomes.hh"

#ifndef NO_DIAGRAM
#include <string>
#endif

/*
 * Classe Tret
 */

/** @class Tret
    @brief Representa l'informació i les operacions associades a un tret.
	
	Conté els individus que presenten el tret i la combinació de gens que el produeix.
*/

class Tret {

private:
	
	/** @brief Conjunt dels identificadores dels individus que presenten el tret */
	set<int> ids;
	
	/** @brief Combinacio dels cromosomes dels individus que manifestin el tret */
	Cromosomes combinacio;

public:

	// Constructores
	
	/** @brief Creador per defecte
		@pre cert
		@post El resultat es un tret buit
	*/
	Tret();
	
	// Modificadores
	
	/** @brief Modificadora dels individus que presenten el tret i la combinació
		\pre L'individu no presenta el tret
		\post S'afegeix l'individu al tret i calcula nova combinació
	*/
	void afegir_individu(int id, const Cjt_individus& x);
	
	/** @brief Modificadora dels individus que presenten el tret i la combinació
		\pre L'individu presenta el tret
		\post Es treu l'individu del tret i calcula nova combinació
	*/
	void treure_individu(int id, const Cjt_individus& x);
	
	// Consultores
	
	/** @brief Consulta el tret
		\pre cert
		\post Consulta si el tret no té cap individu
	*/
	bool buit() const;
	
	// Escriptura

	/** @brief Operació de escriptura
		\pre cert
		\post S'escriu pel el canal de sortida estàndard la combinació i els 
		individus que la presenten
	*/
	void escriure() const;
	

private:

	/** @brief Calcula la combinacio de tots els individus que presenten el tret
		\pre cert
		\post La combinació pasa a ser la intersecció del individus presents
	*/
	void calcular_combinacio(const Cjt_individus& x);
};
#endif
