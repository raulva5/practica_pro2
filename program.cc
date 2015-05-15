#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Agenda/Agenda.hh"
#include "Comanda/Comanda.hh"

int main() {

Comanda c;
Agenda ag;
bool be; 
bool r; //bool per respostes

	while(c.llegir(be)) {
		r = true;
		be = true;
		if(!be) cout << "Error de format" << endl;
		else {

			if(c.es_insercio()){
				ag.apuntar_tasca(c, be);
			}else if(c.es_consulta()){
				if(c.es_rellotge()) ag.consulta_rellotge();
				else if(c.es_passat()) 	ag.consulta_passat();
				else ag.consulta(c);

			}
			else if(c.es_modificacio()) ag.modificar_tasca(c);
			
			else if(c.es_rellotge()){
			
				string aux_d = "";
				string aux_h = "";
				if(c.nombre_dates() != 0) aux_d = c.data(1);
				if(c.te_hora()) aux_h = c.hora();				
				ag.modificar_rellotge(aux_d, aux_h, r);
							
			}else if(c.es_esborrat())  ag.esborrar_tasca(c);
		}
		if(!r) cout << "No s'ha realitzat." << endl;
	}

	cout << "Has sortit" << endl;
}

