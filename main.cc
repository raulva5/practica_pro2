#include "utils.cc"
#include "./Comanda/Comanda.hh"
#include ".Agenda/Agenda.hh"
int main() {

Comanda c;
Agenda ag;
bool be;
	while(c.llegir(be)){
		if(!be) cout << "Error de format" << endl;
		else if{
			if(c.es_insercio())	ag.apuntar_tasca(c.titol, c.data, c.hora);
			else if(c.es_consulta()) ag.consulta(c);
			else if(c.es_passat()) {}
			else if(c.es_modificacio()) {}
			else if(c.es_rellotge()) {}
			else if(c.es_esborrat()) {}
		}
	}

	cout << "Has sortit" << endl;
}
