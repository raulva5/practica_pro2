#include "Temps.hh"
    
    void Temps::str_to_data(const string &d){
        dia = (d[0]-48)*10 + (d[1] - 48);
        mes = (d[3]-48)*10 + (d[4] - 48);
        any = (d[6]-48)*10 + (d[7] - 48);
    }

    void Temps::str_to_hora(const string &h){
        hora = (h[0]-48)*10 + (h[1] - 48);
        minut = (h[3]-48)*10 + (h[4] - 48);
    }
	
    Temps::Temps(){
		dia = 0;
		mes = 0;
		any = 0;
		minut = 0;
		hora = 0;
		valid = false;

	}
    Temps::Temps(const string &d, const string &h){
        str_to_data(d);
        str_to_hora(h);
    }
	Temps::~Temps(){}

    void Temps::modificar_data(const string &d){
        str_to_data(d);
    }

    void Temps::modificar_hora(const string &h){
        str_to_hora(h);
    }

    void Temps::copiar_data(const Temps d){
        any = d.any;
        mes = d.mes;
        dia = d.dia;
    }

    void Temps::copiar_hora(const Temps d){
        hora = d.hora;
         minut = d.minut;
    }

	void Temps::escriure_data() const{
		if(dia < 10) cout << "0";
		cout << dia << ".";
		if(mes < 10) cout << "0";
		cout << mes << ".";
		if(any < 10) cout << "0";
		cout << any << " ";

		if(hora < 10) cout << "0";
		cout << hora << ":";
		if(minut < 10) cout << "0";
		cout << minut;
	}

    void Temps::modificar_data_hora(const string &d, const string &h){
    	str_to_data(d);
    	str_to_hora(h);
    }

    bool Temps::operator== (const Temps& d) const{ 
    	if(any != d.any) return false;
    	if(mes != d.mes) return false;
    	if(dia != d.dia) return false;
    	if(hora != d.hora) return false;
    	if(minut != d.minut) return false;
    	return true;
    }
    bool Temps::operator!= (const Temps& d) const{
    	if(any != d.any) return true;
    	if(mes != d.mes) return true;
    	if(dia != d.dia) return true;
    	if(hora != d.hora) return true;
    	if(minut != d.minut) return true;
    	return false;
    }
    bool Temps::operator<= (const Temps& d) const{
    	if(any != d.any) return any <= d.any;
        else if(mes != d.mes) return mes <= d.mes;
        else if(dia != d.dia) return dia <= d.dia;
        else if(hora != d.hora) return hora <= d.hora;
        else return minut <= d.minut;
    }
    bool Temps::operator< (const Temps& d) const{
    	if(any != d.any) return any < d.any;
        else if(mes != d.mes) return mes < d.mes;
        else if(dia != d.dia) return dia < d.dia;
        else if(hora != d.hora) return hora < d.hora;
        else return minut < d.minut;
    }
    bool Temps::operator> (const Temps& d) const{
        if(any != d.any) return any > d.any;
        else if(mes != d.mes) return mes > d.mes;
        else if(dia != d.dia) return dia > d.dia;
        else if(hora != d.hora) return hora > d.hora;
        else return minut > d.minut;
    }
    bool Temps::operator>= (const Temps& d) const{
        if(any != d.any) return any >= d.any;
        else if(mes != d.mes) return mes >= d.mes;
        else if(dia != d.dia) return dia >= d.dia;
        else if(hora != d.hora) return hora >= d.hora;
        else return minut >= d.minut;
    }