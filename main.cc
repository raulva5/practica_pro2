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

	while(c.llegir(be)) {
		be = true;
		if(!be) cout << "Error de format" << endl;
		else {

			if(c.es_insercio()){
				ag.apuntar_tasca(c, be);
				if(!be) cout << "No s'ha realitzat" << endl;
			}else if(c.es_consulta()){
				if(c.es_passat()) 	ag.consulta_passat();
				else ag.consulta(c);

			}
			else if(c.es_modificacio()) ag.modificar_tasca(c);
			
			else if(c.es_rellotge())  ag.tractar_rellotge(c);

			else if(c.es_esborrat())  ag.esborrar_tasca(c);
		}
	}

	cout << "Has sortit" << endl;
}

