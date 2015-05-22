#include "Agenda.hh"

	

//Constructors
	Agenda::Agenda(){
		rellotge.modificar_data_hora("20.04.15", "00:00");
	}

//Destructor
	Agenda::~Agenda(){}

//Modificadors
	void Agenda::apuntar_tasca(const string &data, const string &hora, const Tasca &t, bool &be) {
   	be = true;
   		Temps d;
   		if(not data.empty()) d.modificar_data(data);
   		else d.copiar_data(rellotge);

   		d.modificar_hora(hora);

        if (rellotge <= d) {
        	pair<map<Temps,Tasca>::iterator,bool> ret;
			ret = m.insert(pair<Temps,Tasca>(d, t));
			be = ret.second;
        }else be = false;
   	}

	void Agenda::modificar_tasca(const int &n, const string &titol, const string &data, const string &hora, bool &be){
		if(1 <= n and n <= menu.size() and menu[n-1].first){
			be = true;
			Temps daux;
			bool c_data;
			if(not data.empty() or not hora.empty()){
				if(not data.empty()){
					daux.modificar_data(data);
				}else daux.copiar_data(menu[n-1].second->first);
				
				if(not hora.empty()){
					daux.modificar_hora(hora);
				}else daux.copiar_hora(menu[n-1].second->first);
				c_data = true;
			}else c_data = false;
			
			if(not titol.empty()){
				menu[n-1].second->second.modificar_titol(titol);
			}

			if(c_data){
				if(rellotge <= daux){
					if(daux != menu[n-1].second->first){
						Tasca taux = menu[n-1].second->second;
						pair<map<Temps,Tasca>::iterator,bool> ret;
						ret = m.insert(pair<Temps,Tasca>(daux, taux));
						be = ret.second;
						if(ret.second){
							m.erase(menu[n-1].second);
							menu[n-1].second = ret.first;
						}
					}
				}else be = false;
			}
		}else be = false;
	}
	void Agenda::afegir_etiqueta_tasca(const int &n, const string &etiqueta, bool &be){
		if(1 <= n and n <= menu.size() and menu[n-1].first){
			menu[n-1].second->second.afegir_etiqueta(etiqueta, be);
		}else be = false;
	}

	void Agenda::tractar_esborrat(const int &n, const string &t, bool &be){
		if(1 <= n and n <= menu.size() and menu[n-1].first){
			if(t == "tasca"){
				m.erase(menu[n-1].second);
				menu[n-1].first = false;
			}else if(t == "etiquetes"){
				menu[n-1].second->second.esborrar_etiquetes();
			}else{
				menu[n-1].second->second.esborrar_etiqueta(t, be);
			}
		}
		else be = false;
	}

	void Agenda::avancar_rellotge(const string data, const string hora, bool &be){
		Temps d;
		if(not data.empty()) d.modificar_data(data);
		else d.copiar_data(rellotge);
		
		if(not hora.empty()) d.modificar_hora(hora);
		else d.copiar_hora(rellotge);

		if(d >= rellotge){
			rellotge = d;
			be = true;
			
			int n = menu.size();
			for(int i = 0; i < n; ++i){
				if(menu[i].first and menu[i].second->first < rellotge) menu[i].first = false;
			}

		}else be = false;

	}

//Consultors

	void Agenda::consulta(const string &d1, const string &d2, 
						const string &etiqueta, const string expressio){
		bool futures = false;
		menu.clear();
		Temps auxd1, auxd2;
		map<Temps,Tasca>::iterator itlow,itup;
		if(not d1.empty() and not d2.empty()){//Rang
			auxd1.modificar_data(d1);
			if(auxd1 < rellotge) auxd1 = rellotge;
			itlow = m.lower_bound(auxd1);
			
			auxd2.modificar_data(d2);
			auxd2.modificar_hora("23:59");
			itup = m.upper_bound(auxd2);	

		}else if(not d1.empty()){//Dia concret
			auxd1.modificar_data(d1);
			if(auxd1 < rellotge) auxd1 = rellotge;
			itlow = m.lower_bound(auxd1);

			auxd2.modificar_data(d1);
			auxd2.modificar_hora("23:59");
			itup = m.upper_bound(auxd2);	
		}else{//Futures
			itlow = m.lower_bound(rellotge);
			itup = m.end();
			futures = true;
		}
		if(futures or auxd1 <= auxd2){
			bool b;
			while(itlow != itup){
				b = true;
				
				if(not etiqueta.empty()) b = itlow->second.te_etiqueta(etiqueta);
				else if(not expressio.empty()){
					int auxi = 0;
					b = itlow->second.expressio(expressio, auxi);
				}

				if(b){
					pair<bool, map<Temps,Tasca>::iterator> par;
					par.first = true;
					par.second = itlow;
					menu.push_back(par);
				}
				++itlow;
			}			
			imprimir_menu();
		}
	}

	void Agenda::consulta_passat(){

		map<Temps,Tasca>::iterator it,itup;
		itup = m.lower_bound(rellotge);

		menu.clear();
		for(it = m.begin(); it != itup; ++it){
			pair<bool, map<Temps,Tasca>::iterator> par;
			par.first = false;
			par.second = it;
			menu.push_back(par);
		}
		imprimir_menu();
	}

	void Agenda::consulta_rellotge() const{
		rellotge.escriure_data();
		cout << endl;
	}

	void Agenda::imprimir_menu() const{
		int n = menu.size();		
		for(int i = 0; i < n; ++i){
			cout << (i+1) << " " << menu[i].second->second.consulta_titol() << " ";
			menu[i].second->first.escriure_data();
			menu[i].second->second.escriure_etiquetes();
			cout << endl;
		}
	}