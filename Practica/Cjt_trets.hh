/** @file Cjt_trets.hh
    @brief Especificació de la classe Cjt_trets
*/

#ifndef _CJT_TRETS_
#define _CJT_TRETS_

#include "Tret.hh"
#include "Cjt_individus.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/*
 * Classe Cjt_trets
 */

/** @class Cjt_trets
	@brief Representa el conjunt de trets d'un experiment.
	
	Ofereix operacions per afegir, treure, consultar existencia i escriure trets.
*/

class Cjt_trets {
	// Descripció: conté el conjunt de trets d'un experiment i operacions per gestionar-lo
  
private:
  
	/** @brief Diccionari dels trets */
	map<string, Tret> trets;

public:

	// Constructora

	/** @brief Creadora per defecte
		@pre cert
		@post El resultat es un Cjt_trets buit
	*/
	Cjt_trets();

	//Modificadores
	
	/** @brief Modificadora del conjunt de trets
		\pre El tret no está present en el conjunt
		\post Si no hi era es crea, si hi era s'afegeix l'individu al tret
	*/
	void afegir(string tret, int id, Cjt_individus& x);
	
	/** @brief Modificadora del conjunt de trets
		\pre El tret está present en el conjunt
		\post Es treu l'individu del tret i si es qued buit s'elimina
	*/
	void treure(string tret, int id, Cjt_individus& x);
	
	// Consultores
	
	/** @brief Consulta si existeix el tret
		\pre cert
		\post Indica si existeix el tret
	*/
	bool existeix_tret(string tret);
	
	// Lectura i escriptura
	
	/** @brief Operació d'escriptura del tret
		\pre cert
		\post S'escriu pel el canal de sortida estàndard el tret
	*/
	void escriure_tret(string tret);
};
#endif
