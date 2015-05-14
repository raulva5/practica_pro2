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
    	b = true;
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
			if(ret.second) b = true;
			else b = false;
		}
		
    }

	void Agenda::modificar_tasca(Comanda &c){

	}

	void Agenda::esborrar_tasca(Comanda &c){

	}

	void Agenda::tractar_rellotge(Comanda &c){

	}

	void Agenda::modificar_rellotge(const Data &d){

	}

//Consultors

	void Agenda::consulta(Comanda &c){

	}

	void Agenda::consulta_passat(){

	}

	void Agenda::consulta_rellotge() const{

	}
