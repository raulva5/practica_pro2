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

void Tasca::afegir_etiqueta(const string &e) 
{
	pair<map<string,bool>::iterator,bool> ret;
	ret = this->etiq.insert(pair<string,bool>(e, true));
}
 
void Tasca::esborrar_etiqueta(const string &e, bool &b)  
{
    int n = this->etiq.erase(e);
    if(n == 1) b = true;
    else b = false;
    //Escriure a Agenda error de no borrat
}
void Tasca::esborrar_etiquetes(){
	etiq.clear();
}
// Consultores

string Tasca::consulta_titol() const 
{
    return this->titol;
}

bool Tasca::te_etiqueta(const string &e) const{
	return (this->etiq.find(e) != this->etiq.end());
}

string Tasca::llegir_paraula(const string &s, int &i){
	string aux;
	while(s[i] != '.' and s[i] != ',' and s[i] != ')'){
		aux.push_back(s[i]);
		++i;
	}
	return aux;
}

bool Tasca::expressio(const string &expr, int &i){
	bool e1, e2;
	string aux;
	++i;
	//Avalua E esquerre	
	if(expr[i] == '(') e1 = expressio(expr, i);
	else{
		aux = llegir_paraula(expr, i);
		e1 = te_etiqueta(aux);
	}
	char op = expr[i];
	++i;
	
	//LAZY EVALUATION
	if(op == '.' and not e1){
		while(expr[i] != ')') ++i;
		++i;
		return false;
	}
	if(op == ',' and e1){
		while(expr[i] != ')') ++i;
		++i;
		return true;
	}
	//FI LAZY EVALUATION

	//Avalua E dret
	if(expr[i] == '(') e2 = expressio(expr, i);
	else{
		aux = llegir_paraula(expr, i);
		e2 = te_etiqueta(aux);
	}

	//Retorna (E op E)
	++i;
	if(op == '.') return e1 * e2;
	else return e1 + e2;
}

//Lector / Escritor
void Tasca::escriure_etiquetes() const 
{
	map<string,bool>::const_iterator it;
	
	for(it = this->etiq.begin(); it != this->etiq.end(); ++it){
		cout << " " << it->first;
	}
}
