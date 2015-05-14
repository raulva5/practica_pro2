#include "Tasca.hh"


/* Constructores */
Tasca::Tasca()
{	
	
}

Tasca::Tasca(const string &t)
{
	this->titol = t;   
}
//Destructor
    Tasca::~Tasca(){}
    
// Modificadores

void Tasca::modificar_titol(const string &t) 
{
	this->titol = t;
}

void Tasca::afegir_etiqueta(const string &e, bool &b) 
{
	pair<map<string,bool>::iterator,bool> ret;
	ret = this->etiq.insert(pair<string,bool>(e, true));
	if(ret.second) b = true;
	else b = false;
}
 
void Tasca::esborrar_etiqueta(const string &e, bool &b)  
{
    int n = this->etiq.erase(e);
    if(n == 1) b = true;
    else b = false;
    //Escriure a Agenda error de no borrat
}
// Consultores

string Tasca::consulta_titol() const 
{
    return this->titol;
}

bool Tasca::te_etiqueta(const string &e){
	return (this->etiq.find(e) != this->etiq.end());
}

//Lector / Escritor
void Tasca::escribir_etiquetes() const 
{
	map<string,bool>::const_iterator it;

	for(it = this->etiq.begin(); it != this->etiq.end(); ++it){
		cout << " #" << it->first;
	}
}
