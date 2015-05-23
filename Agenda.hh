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

#include "Temps.hh"
#include "Tasca.hh"
using namespace std;
/** @class Agenda
    @brief Representa una agenda.
    Invariants: Les tasques estan ordenades segons Temps, tant al menu com al map.
                Rellotge marca un Temps*/
class Agenda {
private:
	Temps rellotge;
	map<Temps,Tasca> m;
	vector<pair<bool, map<Temps,Tasca>::iterator> > menu;
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
    \post: b = true, Agenda conte una tasca nova
    	   b = false, la tasca no s'ha afegit */
    void apuntar_tasca(const string &data, const string &hora, const Tasca &t, bool &be);
    
    /** @brief Modifica titol, data o hora de la tasca n-essima del menu
    \pre: 0 <= n < tamany menu, no es modificaran els pertinents atributs de tasca per els p.e. buits
    \post: b = true, s'ha modificat els pertinents atributs de tasca per els p.e. no buits de la tasca 'n' del menu
           b = false, no s'ha modificat cap tasca */
	void modificar_tasca(const int &n, const string &titol, const string &data, const string &hora, bool &be);
  
    /** @brief Afageix una tasca a la n-essima tasca
    \pre: 0 <= n < tamany menu, no es modificaran els pertinents atributs de tasca per els p.e. buits
    \post: be = true, s'ha afegit l'etiqueta
           be = false, no s'ha afegit */
    void afegir_etiqueta_tasca(const int &n, const string &etiqueta, bool &be);
	
     /** @brief Tracta l'esborrat relacionat amb una tasca
    \pre: 0 <= n < tamany menu, t = "tasca" o t = "etiquetes" o bé t conte una etiqueta 
    \post: n fa referencia a la tasca si:
        t = "tasca" s'esborra la tasca
        t = "etiquetes" esborra totes les etiquetes
        altrament s'esborra la etiqueta t */
	void tractar_esborrat(const int &n, const string &t, bool &be);

	 /** @brief Avanca el rellotge d'hora
    \pre: si data o hora, es buit no es modifica
    \post: be = true, si el nou Temps és >= a rellotge, s'ha modificat
           be = false, si el nou Temps és < a rellotge, no s'ha modificat*/
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


