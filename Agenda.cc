#include "Agenda.hh"

	

//Constructors
	Agenda::Agenda(){
		this->rellotge.modificar_data_hora("20.04.15", "00:00");
	}

//Destructor
	Agenda::~Agenda(){}

//Modificadors
    void Agenda::apuntar_tasca(Comanda &c, bool &b){
    	b = true;
    	Tasca t;
    	Data d;
    	
    	if(c.te_titol()){
    		t.modificar_titol(c.titol());
    	}else b = false;
    	
    	int n = c.nombre_etiquetes();
    	for(int i = 1; i <= n; ++i){
    		t.afegir_etiqueta(c.etiqueta(i));
    	}

    	if(c.nombre_dates() == 0){
    		d.copiar_data(this->rellotge);
    	}else{
    		d.modificar_data(c.data(1));
    	}

    	if(c.te_hora()){
    		d.modificar_hora(c.hora());
    	}else b = false;
    	

    	if(b){
			pair<map<Data,Tasca>::iterator,bool> ret;
			ret = this->m.insert(pair<Data,Tasca>(d, t));
			b = ret.second;
		}
		
    }

	void Agenda::modificar_tasca(const int &n, const string &t, const string &data, 
                        const string &hora, const string &etiqueta, bool &be){
		be = true;
		bool data_modificada = false;
		Data daux;
		if(not data.empty() or not hora.empty()){
			if(not data.empty()){
				daux.modificar_data(data);
			}else daux.copiar_data(menu[n-1]->first);
			
			if(not hora.empty()){
				daux.modificar_hora(hora);
			}else daux.copiar_hora(menu[n-1]->first);
			
			data_modificada = true;
		}
		if(not t.empty()){
			menu[n-1]->second.modificar_titol(t);
		}
		if(not etiqueta.empty()){
			menu[n-1]->second.afegir_etiqueta(etiqueta);
		}
		if(data_modificada and this->rellotge <= daux){
			Tasca taux = menu[n-1]->second;
			m.erase(menu[n-1]);
			pair<map<Data,Tasca>::iterator,bool> ret;
			ret = this->m.insert(pair<Data,Tasca>(daux, taux));
			
			if(not ret.second) be = false;
			else menu[n-1] = ret.first;
		}
	}

	void Agenda::esborrar_tasca(const int &n, const string &t, bool &be){
		if(n <= menu.size()){
			if(t == "tasca"){
				m.erase(menu[n-1]);
			}else if(t == "etiquetes"){
				menu[n-1]->second.esborrar_etiquetes();
			}else{
				menu[n-1]->second.esborrar_etiqueta(t, be);
			}
		}
		else be = false;
	}

	void Agenda::avancar_rellotge(const string data, const string hora, bool &be){
		Data d;
		
		if(not data.empty()) d.modificar_data(data);
		else d.copiar_data(this->rellotge);
		
		if(not hora.empty()) d.modificar_hora(hora);
		else d.copiar_hora(this->rellotge);

		if(d >= this->rellotge){
			this->rellotge = d;
			be = true;
		}else be = false;

	}

//Consultors

	void Agenda::consulta(const string &d1, const string &d2, 
						const string &etiqueta, const string expressio){
		bool basic = false;
		menu.clear();
		Data auxd1, auxd2;
		map<Data,Tasca>::iterator itlow,itup;
		if(not d1.empty() and not d2.empty()){ // ? DD.MM.YY DD.MM.YY
			
			auxd1.modificar_data(d1);
			itlow = m.lower_bound(auxd1);
			
			auxd2.modificar_data(d2);
			auxd2.modificar_hora("23:59");
			itup = m.upper_bound(auxd2);	

		}else if(not d1.empty()){ //? DD.MM.YY
			auxd1.modificar_data(d1);
			auxd1.copiar_hora(this->rellotge);
			itlow = m.lower_bound(auxd1);

			auxd2.modificar_data(d1);
			auxd2.modificar_hora("23:59");
			itup = m.upper_bound(auxd2);	
		}else{ // ?
			auxd1.copiar_data(this->rellotge);
			auxd1.copiar_hora(this->rellotge);
			itlow = m.lower_bound(auxd1);

			itup = m.end();
			basic = true;
		}
		if(basic or (auxd1 < auxd2 and this->rellotge <= auxd1)){
			bool b;
			while(itlow != itup){
				b = true;
				
				if(not etiqueta.empty())	b = itlow->second.te_etiqueta(etiqueta);
				else if(not expressio.empty()){
					int auxi = 0;
					b = itlow->second.expressio(expressio, auxi);
				}

				if(b) menu.push_back(itlow);
				++itlow;
			}			
			imprimir_menu();
		}
	}

	void Agenda::consulta_passat(){

		map<Data,Tasca>::iterator it,itup;
		itup = m.lower_bound(this->rellotge);

		int i = 0;

		menu.clear();
		for(it = m.begin(); it != itup; ++it){
			menu.push_back(it);
			++i;
		}
		imprimir_menu();
	}

	void Agenda::consulta_rellotge() const{
		this->rellotge.escriure_data();
		cout << endl;
	}
	void Agenda::imprimir_menu() const{
		int n = menu.size();		
		for(int i = 0; i < n; ++i){
			cout << (i+1) << " " << menu[i]->second.consulta_titol() << " ";
			menu[i]->first.escriure_data();
			menu[i]->second.escriure_etiquetes();
			cout << endl;
		}
	}
