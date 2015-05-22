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

void Tasca::afegir_etiqueta(const string &e, bool &be) 
{
	pair<map<string,bool>::iterator,bool> ret;
	ret = this->etiq.insert(pair<string,bool>(e, true));
	be = ret.second;
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
	int start = i;
	while(s[i] != '.' and s[i] != ',' and s[i] != ')') ++i;
	return s.substr(start,(i - start));
}

bool Tasca::expressio(const string &expr, int &i){ //Expr = ( E op E );
	bool e1,e2;
	++i;
	//Avalua E esquerre	
	if(expr[i] == '(') e1 = expressio(expr, i);
	else e1 = te_etiqueta(llegir_paraula(expr, i));
	char op = expr[i];
	++i;
	//Avalua E dret
	if(expr[i] == '(') e2 = expressio(expr, i);
	else e2 = te_etiqueta(llegir_paraula(expr, i));
	++i;
	//Retorna ( E op E )
	if(op == '.') return e1 and e2;
	else return e1 or e2;
}

//Lector / Escritor
void Tasca::escriure_etiquetes() const 
{
	map<string,bool>::const_iterator it;
	for(it = this->etiq.begin(); it != this->etiq.end(); ++it){
		cout << " " << it->first;
	}
}