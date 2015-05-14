#include "Data.hh"
    
    void Data::validar_data(){
        bool v = true;

        if(this->dia > 31) v = false;
        if(this->mes > 12) v = false;
        if(this->any > 99) v = false;
        if(this->hora > 23) v = false;
        if(this->minut > 59) v = false;

        this->valid = v;
    }

    void Data::str_to_data(const string &d){
        this->dia = (d[0]-48)*10 + (d[1] - 48);
        this->mes = (d[3]-48)*10 + (d[4] - 48);
        this->any = (d[6]-48)*10 + (d[7] - 48);
    }

    void Data::str_to_hora(const string &h){
        this->hora = (h[0]-48)*10 + (h[1] - 48);
        this->minut = (h[3]-48)*10 + (h[4] - 48);
    }
	
    Data::Data(){
		this->dia = 0;
		this->mes = 0;
		this->any = 0;
		this->minut = 0;
		this->hora = 0;
		this->valid = false;

	}
    Data::Data(const string &d, const string &h){
        str_to_data(d);
        str_to_hora(h);
    }
	Data::~Data(){}

    void Data::modificar_data(const string &d){
        str_to_data(d);
        validar_data();
    }

    void Data::modificar_hora(const string &h){
        str_to_hora(h);
        validar_data();
    }

    string Data::consultar_data() const{
        string d;
        d[1] = dia / 10;
        d[2] = dia % 10;
        d[3] = '.';
        d[4] = mes / 10;
        d[5] = mes % 10;
        d[6] = '.';
        d[7] = any / 10;
        d[8] = any % 10;
        return d;
    }
    string Data::consultar_hora() const{
        string h;
        h[1] = hora / 10;
        h[2] = hora % 10;
        h[3] = ':';
        h[4] = minut / 10;
        h[5] = minut % 10;
        return h;
        
    }

	void Data::escriure_data(){
		if(dia < 10) cout << "0";
		cout << dia << ".";
		if(mes < 10) cout << "0";
		cout << mes << ".20";
		if(any < 10) cout << "0";
		cout << any << " ";

		if(hora < 10) cout << "0";
		cout << hora << ":";
		if(minut < 10) cout << "0";
		cout << minut;
	}

    void Data::modificar_data_hora(const string &d, const string &h){
    	str_to_data(d);
    	str_to_hora(h);
        validar_data();
    }

    bool Data::operator== (const Data& d){ 
    	if(this->any != d.any) return false;
    	if(this->mes != d.mes) return false;
    	if(this->dia != d.dia) return false;
    	if(this->hora != d.hora) return false;
    	if(this->minut != d.minut) return false;
    	return true;
    }
    bool Data::operator!= (const Data& d){
    	if(this->any != d.any) return true;
    	if(this->mes != d.mes) return true;
    	if(this->dia != d.dia) return true;
    	if(this->hora != d.hora) return true;
    	if(this->minut != d.minut) return true;
    	return false;
    }
    bool Data::operator<= (const Data& d){
    	if(this->any > d.any) return false;
        else if(this->any < d.any) return true;
        if(this->mes > d.mes) return false;
        else if(this->mes < d.mes) return true;
        if(this->dia > d.dia) return false;
        else if(this->dia < d.dia) return true;
        if(this->hora > d.hora) return false;
        else if(this->hora < d.hora) return true;
        if(this->minut > d.minut) return false;
        else return true;
    }
    bool Data::operator< (const Data& d){
    	if(this->any > d.any) return false;
        else if(this->any < d.any) return true;
        if(this->mes > d.mes) return false;
        else if(this->mes < d.mes) return true;
        if(this->dia > d.dia) return false;
        else if(this->dia < d.dia) return true;
        if(this->hora > d.hora) return false;
        else if(this->hora < d.hora) return true;
        if(this->minut >= d.minut) return false;
        else return true;
    }
    bool Data::operator> (const Data& d){
        if(this->any < d.any) return false;
        else if(this->any > d.any) return true;
        if(this->mes < d.mes) return false;
        else if(this->mes > d.mes) return true;
        if(this->dia < d.dia) return false;
        else if(this->dia > d.dia) return true;
        if(this->hora < d.hora) return false;
        else if(this->hora > d.hora) return true;
        if(this->minut <= d.minut) return false;
        else return true;
    }
    bool Data::operator>= (const Data& d){
        if(this->any < d.any) return false;
        else if(this->any > d.any) return true;
        if(this->mes < d.mes) return false;
        else if(this->mes > d.mes) return true;
        if(this->dia < d.dia) return false;
        else if(this->dia > d.dia) return true;
        if(this->hora < d.hora) return false;
        else if(this->hora > d.hora) return true;
        if(this->minut < d.minut) return false;
        else return true;
    }