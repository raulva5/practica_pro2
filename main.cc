#include "utils.cc" //utils.PRO2
#include "Agenda.hh"
#include "./Comanda/Comanda.hh"

int main() {

Comanda c;
Agenda ag;
bool be;

	while(c.llegir(be)) {
		
		if(!be) cout << "Error de format" << endl;
		else {

			if(c.es_insercio()) ag.apuntar_tasca(c);
			
			else if(c.es_consulta()){
				if(c.es_passat()) 	ag.tractar_passat();
				else ag.tractar_consulta(c);

			}
			else if(c.es_modificacaio()) ag.modificar_tasca(c);
			
			else if(c.es_rellotge())  ag.tractar_rellotge(c);

			else if(c.es_esborrat())  ag.es_esborrat(c);
			

		}
	}

	cout << "Has sortit" << endl;
}

