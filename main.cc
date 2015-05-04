#include "utils.cc" //utils.PRO2
#include "Agenda.hh"
#include "./Comanda/Comanda.hh"
#include <string>

int main() {

Comanda c;
Agenda ag;
ag.iniciar_hora();
bool be;

	while(c.llegir(be)) {
		
		if(!be) cout << "Error de format" << endl;
		else {

			if(c.es_insercio()) ag.apuntar_tasca(c);
			
			else if(c.es_consulta()) ag.tractar_consulta(c);
			
			else if(c.es_passat()) 	ag.tractar_passat();

			else if(c.es_modificacaio()) ag.tractar_modificacio(c);
			
			else if(c.es_rellotge())  ag.tractar_rellotge(c);

			else if(c.es_esborrat())  ag.es_esborrat(c);
			

		}
	}

	cout << "Has sortit" << endl;
}

