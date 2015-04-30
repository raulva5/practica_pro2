/** @file Agenda.hh
    @brief Classe Agenda
 */

#ifndef AGENDA_HH
#define AGENDA_HH
#include "../utils.cc"
#include "Dat.hh"

/** @class Agenda
    @brief Representa una agenda.
 */
class Agenda {
private:

	Dat dt; // rellotge de tasca
	Dat dt_int; // rellotge intern
	map<Dat,Tasca> m;
	vector<Tasca> m;

public:
	/* Està posat a tot arreu "int i" però faltarà determinar els paràmetres finals*/
	
  //Constructors
	Agenda();
	Dat iniciar_hora();
  //Modificadors
    //Tasques
        void apuntar_tasca(int i);
	void tractar_modificacio(int i);
	void tractar_modificacio(const Comanda& c);
	void modificar_rellotge();
  	void es_esborrat(int& i,string& etiq);

  //Consultors
	void tractar_consulta(const Comanda& c);
	void tractar_rellotge(const Comanda& c); // en cas de que modifica el rellotge intern crida a modificar_rellotge()
	void passat();

};
#endif


