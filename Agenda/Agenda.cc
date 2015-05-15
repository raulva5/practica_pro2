#include "Agenda.hh"

//Constructors
	Agenda::Agenda(){
		this->rellotge.modificar_data_hora("20.04.15", "00:00");
	}

//Destructor
	Agenda::~Agenda(){
		
	}

//Modificadors
    void Agenda::apuntar_tasca(Comanda &c, bool &b){
    	/*b = true;
    	Tasca t;
    	Data d;
    	
    	if(c.te_titol()){
    		t.modificar_titol(c.titol());
    	}else b = false;
    	
    	int n = c.nombre_etiquetes();
    	for(int i = 1; i <= n; ++i){
    		t.afegir_etiqueta(c.etiqueta(i), b);
    		if(!b) cout << "No s'ha afegit: " << c.etiqueta(i) << endl;
    	}

    	if(c.nombre_dates() == 0){
    		d.modificar_data(this->rellotge.consultar_data());
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
		}*/
		
    }

	void Agenda::modificar_tasca(Comanda &c){

	}

	void Agenda::esborrar_tasca(Comanda &c){

	}

	void Agenda::modificar_rellotge(const string data, const string hora, bool &be){
		Data d;
		
		if(data != "") d.modificar_data(data);
		else d.copiar_data(this->rellotge);
		
		if(hora != "") d.modificar_hora(hora);
		else d.copiar_hora(this->rellotge);

		if(d > this->rellotge){
			this->rellotge = d;
			be = true;
		}else be = false;

	}

//Consultors

	void Agenda::consulta(Comanda &c){

	}

	void Agenda::consulta_passat(){

	}

	void Agenda::consulta_rellotge() const{
		this->rellotge.escriure_data();
		cout << endl;
	}
