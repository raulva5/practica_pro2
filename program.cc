#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "Agenda.hh"
#include "comanda.hh"
#include "Tasca.hh"
 
void preparar_apuntar_tasca(Comanda& c, Agenda &ag, bool &be) {
	Tasca t(c.titol());	
	int n = c.nombre_etiquetes();
	for(int i = 0; i < n; ++i){
		t.afegir_etiqueta(c.etiqueta(i+1));
	}

	string data;
	data.clear();
	if(c.nombre_dates() != 0) data = c.data(1);
	
	string hora;
	hora.clear();
	if(c.te_hora()) hora = c.hora();

	ag.apuntar_tasca(data, hora, t, be);
}

void preparar_consulta(Comanda& c, Agenda &ag) {

	string etiqueta;
	etiqueta.clear();
	if(c.nombre_etiquetes() != 0) etiqueta = c.etiqueta(1);

	string expr;
	expr.clear();
	if(c.te_expressio()) expr = c.expressio();
	
	string d1,d2;
	d1.clear();
	d2.clear();	
	if (c.nombre_dates() == 2){
		d1 = c.data(1);
		d2 = c.data(2);
	}
	else if(c.nombre_dates() == 1) d1 = c.data(1);

	ag.consulta(d1,d2,etiqueta,expr);
}

void preparar_modificacio(Comanda& c, Agenda &ag, bool &r) {
	
	int n_tasca = c.tasca();
	
	string titol;
	titol.clear();
	if(c.te_titol()){
		titol = c.titol();
	}

	int n = c.nombre_etiquetes();
	for(int i = 0; i < n; ++i) ag.afegir_etiqueta_tasca(n_tasca, c.etiqueta(i+1));

	string data;
	data.clear();
	if(c.nombre_dates() != 0){
		data = c.data(1);
	}

	string hora;
	hora.clear();
	if(c.te_hora()){
		hora = c.hora();
	}	
	
	ag.modificar_tasca(n_tasca, titol, data, hora, r);
}



int main() {

Comanda c;
Agenda ag;
bool r; //bool per respostes

	while(c.llegir(r)) {
		if(r){
			r = true;
			if(c.es_insercio()) {
				preparar_apuntar_tasca(c, ag, r);
			}
			else if(c.es_consulta()) {
				if(c.es_rellotge()) ag.consulta_rellotge();
				else if(c.es_passat()) 	ag.consulta_passat();
				else preparar_consulta(c, ag);
			}
			else if(c.es_modificacio()){
				preparar_modificacio(c, ag, r);
			}
			
			else if(c.es_rellotge()) {
			    string aux_d, aux_h;
			    aux_d.clear();
				aux_h.clear();
				if(c.nombre_dates() != 0) aux_d = c.data(1);
				if(c.te_hora()) aux_h = c.hora();				
				ag.avancar_rellotge(aux_d, aux_h, r);
							
			}
			else if(c.es_esborrat()){
				int n = c.tasca();
				string tipus = c.tipus_esborrat();
				if(tipus == "etiqueta") tipus = c.etiqueta(1);
				ag.tractar_esborrat(n, tipus, r);
			}
			if(not r) cout << "No s'ha realitzat" << endl;
		}
		
	}
}

