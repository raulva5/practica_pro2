/** @file Agenda.hh
    @brief Classe Agenda
 */

#ifndef AGENDA_HH
#define AGENDA_HH

#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Data.hh"
#include "Tasca.hh"
#include "comanda.hh"
using namespace std;
/** @class Agenda
    @brief Representa una agenda.
*/

class Agenda {
private:
	Data rellotge;
	map<Data,Tasca> m;
	vector<map<Data, Tasca>::iterator> menu;

	void consulta_etiqueta(const string &e);
	void consulta_expressio(const string &s);
    void imprimir_menu() const;
public:
	
//Constructors
    /** @brief Constructora per defecte*/
	Agenda();

//Destructor
    /** @brief Destructora per defecte*/
	~Agenda();

//Modificadors
	/** @brief Afageix una tasca a l'Agenda
    \pre: 
    \post: b = true, map<Data,Tasca> m conte una tasca nova
    	   b = false, la tasca no s'ha afegit */
    void apuntar_tasca(Comanda &c, bool &b);
    
    /** @brief Modifica text, data o hora de la tasca 'n' del menu
    \pre: 0 <= n < menu.size(), no es modificaran els pertinents atributs de tasca per els p.e. buits
    \post: b = true, s'ha modificat els pertinents atributs de tasca per els p.e. no buits de la tasca 'n' del menu
           b = false, no s'ha modificat cap tasca */
	void modificar_tasca(const int &n, const string &t, const string &data, 
                        const string &hora, const string &etiqueta, bool &be);

	 /** @brief Esborra la tasca referenciada per n al menu
    \pre: 0 <= n < menu.size(), t = "tasca" o t = "etiquetes" o bé t conte una etiqueta 
    \post: n fa referencia a la tasca si:
        t = "tasca" s'esborra la tasca
        t = "etiquetes" esborra totes les etiquetes
        altrament s'esborra la etiqueta t */
	void esborrar_tasca(const int &n, const string &t, bool &be);

	 /** @brief Avanca el rellotge d'hora
    \pre: si data o hora, es buit no es modifica
    \post: be = true, si la nova Data és >= a rellotge, s'ha modificat
           be = false, si la nova Data és < a rellotge, no s'ha modificat*/
	void avancar_rellotge(const string data, const string hora, bool &be);

//Consultors
	 /** @brief Consulta tasques futures entre un interval de dades 
                i/o (que tinguin una etiqueta o compleixin una expressio booleana d'etiquetes)
    \pre: La consulta es fara amb les condicions que fan referencia els p.e. no buits
    \post: S'imprimeixen les tasques que compleixen totes les condicions i es posen a menu*/
	void consulta(const string &d1, const string &d2, 
                        const string &etiqueta, const string expressio);

	 /** @brief Crea un menu amb totes les tasques passades
    \pre: cert
    \post: S'imprimeixen totes les tasques amb data anterior al rellotge intern i es posen al menu*/
	void consulta_passat();
	
	 /** @brief Imprimeix data i hora del rellotge intern
    \pre: cert
    \post: S'escriu data i hora*/
	void consulta_rellotge() const;

};
#endif


