#include <iostream>
#include <cassert>
#include <cstdlib>
#include "Cronologia.h"

using namespace std;


//Constructor por defecto
Cronologia::Cronologia(){
  cronol = 0;
} 


//Constructor copia
Cronologia::Cronologia(const Cronologia & c){
   cronol=c.cronol;
}


//Destructor
Cronologia::~Cronologia(){
}


//getNfechas()
int Cronologia::getNfechas() const{
	return cronol.getOcupados();
}


//Devuelve el año de una fecha dada su posición
int Cronologia::getAnio(int pos) const{
	assert(0<=pos && pos<getNfechas());
	return cronol[pos].getAnio();
}


//Operador []
FechaHistorica & Cronologia::operator[] (int i){
	assert(0<=i && i<getNfechas());
	return cronol[i];
}


//Operador [] constante
const FechaHistorica & Cronologia::operator[](int i) const{
	assert(0<=i && i<getNfechas());
	return cronol[i];
}


//Comprobar que está vacia
bool Cronologia::vacio() const{
	return cronol.getOcupados() == 0;
}


//Clear
void Cronologia::clear(){
	if (!cronol.vacio())
		cronol.resize(0);
}


//Buscar la posición de una fecha dado su año
int Cronologia::buscarAnio(int a) const{
	int inf=0, sup=cronol.getOcupados()-1, med;
	bool enc=0;
	
	while (!enc && inf<=sup){
		med=(sup+inf)/2;
		if (cronol[med].getAnio()<a)
			inf=med+1;
		else if(cronol[med].getAnio()>a)
			sup=med-1;
		else
			enc=1;
	}
	
	if (!enc)
		med=-1;
	
	return med;
}


//Buscar la posición de la fecha en la que está ubicado un hecho
int Cronologia::buscarHecho(const string & h) const{
	int pos=-1;
	int n=cronol.getOcupados();
	for (int i=0 ; i<n && pos==-1 ; ++i){
		int m = cronol[i].getNhechos();
		for(int j=0; j<m && pos==-1; ++j){
			if (h==cronol[i][j])
				pos=i;
		}
	}
		
	return pos;
}


//Insertar
void Cronologia::insertar(const FechaHistorica & fech){
	int a=fech.getAnio(), i=0, nfechas=cronol.getOcupados();
	while (i<nfechas && cronol[i].getAnio()<a)
		++i;
	if (i<nfechas && cronol[i] == a){
		int nhechos=fech.getNhechos();
		for (int j=0; j<nhechos; ++j)
			cronol[i] += fech[j];
	}else{
		cronol.insertar(fech, i);	//método insertar del VectorDinamico
	}
}


//Eliminar fecha por posición
void Cronologia::eliminarPorPos(int pos){
	assert(0<=pos && pos<getNfechas());
	cronol.eliminar(pos);
}


//Eliminar fecha por anio
void Cronologia::eliminarPorAnio(int a){
	int pos = buscarAnio(a);
	if(pos != -1){
		cronol.eliminar(pos);
	}
}

//operador =
Cronologia & Cronologia::operator=(const Cronologia & c){
	 if (this!=&c)
		 cronol = c.cronol;
	return *this;
}


//Subcronología a partir de una cadena
void Cronologia::crearSubcronologia(string & h, Cronologia & sub) const{
	int n = cronol.getOcupados();		
	sub.clear();		
	for(int i=0; i<n; ++i){
		int m = cronol[i].getNhechos();
		int a = cronol[i].getAnio();
		FechaHistorica fech(a);
		for(int j=0; j<m; ++j){
			if(cronol[i][j].find(h)!=string::npos)
				fech += cronol[i][j];
		}
		if(!fech.vacio()){
			sub.insertar(fech);
		}
	}
}


//Subcronología a partir de un rango de años
void Cronologia::crearSubcronologia(int a1, int a2, Cronologia & sub) const{
	if (a1>a2){
		int aux=a1;
		a1=a2;
		a2=aux;
	}
	
	sub.clear();
	int pos=0, n=cronol.getOcupados();
	while (pos<n && getAnio(pos)<a1)
		++pos;
	while (pos<n && getAnio(pos)<=a2){
		sub.insertar((*this)[pos]);
		++pos;
	}
}


//Unión
void Cronologia::unir(const Cronologia & c1, const Cronologia & c2){
	clear();
	int n1=c1.getNfechas(), n2=c2.getNfechas();
	for (int i=0; i<n1; ++i)
		insertar(c1[i]);
	for (int i=0; i<n2; ++i)
		insertar(c2[i]);
}


//Intersección
void Cronologia::intersecar(const Cronologia & c1, const Cronologia & c2){
	clear();
	int n1=c1.getNfechas(), n2=c2.getNfechas(), i=0, j=0;
	while (i<n1 && j<n2){
		if (c1[i].getAnio()<c2[j].getAnio())
			++i;
		else if (c1[i].getAnio()>c2[j].getAnio())
			++j;
		else{
			int m1=c1[i].getNhechos(), m2=c2[j].getNhechos();
			FechaHistorica aux(c1[i].getAnio());
			for (int k=0; k<m1; ++k)
				for (int l=0; l<m2; ++l)
					if (c1[i][k]==c2[j][l]){
						aux+=c1[i][k];
}
			if (!aux.vacio()){
				insertar(aux);
}
			++i;
			++j;
		}
	}
}


//operador +=
void Cronologia::operator+=(const Cronologia & c){
	int n = c.cronol.getOcupados();	
	for(int i=0; i<n; i++)
		insertar(c.cronol[i]);
}


//Operador <<
ostream & operator<<(ostream & os, const Cronologia & cron){
	int n=cron.getNfechas();
	if (0<n)
		os << cron.cronol[0];
	
	for(int i=1; i<n; ++i)
		os << endl << cron.cronol[i];
	
	return os;
}


//Operador >>
istream & operator>>(istream & is, Cronologia & cron){
	cron.clear();
	
	while(is.peek()!=-1){
		FechaHistorica aux;
		is >> aux;
		cron.insertar(aux);
	}
	
	return is;
}
