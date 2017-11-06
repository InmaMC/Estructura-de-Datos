#include "Cronologia.h"
#include "FechaHistorica.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){
	
	if (argc!=2){
		cout<<"Dime el nombre del fichero con la cronologia"<<endl;
		return 0;
	}
	
	ifstream f (argv[1]);
	if (!f){
		cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
		return 0;
	}
	
	Cronologia mi_cronologia;
	f>>mi_cronologia; //Cargamos en memoria la cronología.
	
	// - Obtener los eventos acaecidos en un año dado
	int mi_anio;
	cout << "Introduzca anio a buscar en la cronologia: ";
	cin >> mi_anio;
	int pos_mi_anio=mi_cronologia.buscarAnio(mi_anio);
	if (pos_mi_anio!=-1){
		FechaHistorica mi_fecha(mi_cronologia[pos_mi_anio]);
		cout << endl << "Hechos del anio " << mi_anio << ":" << endl;
		for (int i=0; i<mi_fecha.getNhechos(); ++i)
			cout << mi_fecha[i] << endl;
		cout << endl;
	}
	else
		cout << "El anio " << mi_anio << " no se encuentra en la cronologia" << endl << endl;
	
	
	
	// - Obtener la (sub)cronología de eventos históricos acaecidos en 
	// [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados 
	// por el usuario
	
	Cronologia subcron1;
	int anio1, anio2;
	cout << "Introduzca el rango de anios para crear la subcronologia:";
	cin >> anio1 >> anio2;
	mi_cronologia.crearSubcronologia(anio1, anio2, subcron1);
	cout << "La subcronologia resultante es:" << endl << subcron1 << endl << endl;
	
	
	// - Obtener la (sub)cronología de eventos históricos asociados a una 
	// palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
	
	Cronologia subcron2;
	string palabra_clave;
	cout << "Introduzca palabra clave para crear la subcronologia:";
	cin >> palabra_clave;
	mi_cronologia.crearSubcronologia(palabra_clave, subcron2);
	cout << "La subcronologia resultante es:" << endl << subcron2 << endl << endl;
	
	
	// - Unión de dos cronologías
	Cronologia mi_union;
	mi_union.unir(subcron1, subcron2);
	cout << "La union de las subcronologias es:" << endl << mi_union 
		<< endl << endl;
	
	
	// - Intersección de dos cronologías
	Cronologia mi_interseccion;
	mi_interseccion.intersecar(subcron1, subcron2);
	cout << "La interseccion de las subcronologias es:" << endl << mi_interseccion 
		<< endl << endl;
	
	
	return 0;
}
