/**
  * @file Cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include "VectorDinamico.h"
#include "FechaHistorica.h"

using namespace std;

/**
  *  @brief T.D.A. Cronologia
  *
  * Una instancia @e c del tipo de datos abstracto @c Cronologia es un
////////////////////////////////////
  * objeto compuesto por un vector dinamino de FechaHistorica, que representa, 
  * unas fechas con, cada una, un conjunto de acontecimientos ocurridos en 
  * esa fecha.
  *
  * Un ejemplo de su uso:
  * @include pruebacronologia.cpp
  *
  * @author Alejandro Palencia Blanco
  * @author Inmaculada Marín Carballo
  * @date Octubre 2017
  */


class Cronologia {

	private:
	/**
		* @page repConjunto Rep del TDA Cronologia
		*
		* @section faConjunto Función de abstracción
		*
		* Un objeto válido @e rep del TDA Cronologia representa al valor
		*
		* (rep.cronol)
		*
		*/
		
		VectorDinamico<FechaHistorica> cronol; /**< cronol */
		
	public:
		
	/**
		* @brief Constructor por defecto de la clase. Asigna NULL a cronolog 
		*/
		Cronologia(); 
			
	/**
		* @brief Contructor copia de la clase.
		*/ 
		Cronologia(const Cronologia & c);

	/**
		* @brief Destructor de la clase
		*/
		~Cronologia(); 

	/**
		* @brief Devuelve el número de fechas almacenadas
		*/ 
		int getNfechas() const;

	/**
		* @brief Devuelve el año de una FechaHistorica dada su posición
		* @pre 0<=i<getNfechas()
		*/ 
		int getAnio(int pos) const;

	/**
		* @brief Acceso a un hecho de una Cronologia
		* @param i la posición donde está el fecha
		* @pre 0<=i<getNfechas()
		* @return La referencia a la fecha. Por tanto, se puede usar para almacenar
		*   un hecho en esa posición.
		*/
		FechaHistorica & operator[] (int i);

	/**
		* @brief Acceso a un hecho de una Cronologia constante
		* @param i la posición donde está el fecha
		* @pre 0<=i<getNfechas()
		* @return La referencia al elemento. Se supone que la Cronologia no se
		*   puede modificar y por tanto es acceso de sólo lectura
		*/
		const FechaHistorica & operator[](int i) const;
 
	/**
		* @brief Comprueba si no hay ningún hecho guardado
		*/
		bool vacio() const;
	
	/**
		* @brief Elimina todas las fechas de la cronología si no está vacía
		*/
		void clear();
	
	/**
		* @brief Comprueba si un anio ya pertenece al vector cronol
		* @param a anio a comprobar
		* @return Devuelve la posición en que se encuentra ese anio (si no está devuelve -1) 
		*/
		int buscarAnio(int a) const;
 
	/**
		* @brief Busca la posición de la fecha a la que pertenece el hecho enunciado
		* @param h hecho a comprobar
		* @return Devuelve la posición de la fecha en la que se encuentra ese hecho (si no está devuelve -1) 
		*/
		int buscarHecho(const string & h) const; 
 
	/**
		* @brief Inserta una nueva fecha
		* @param fech FechaHistorica a insertar
		*/
		void insertar(const FechaHistorica & fech); 
	
	/**
		* @brief elimina una fecha de cronol dada su posición
		* @param pos Posición a borrar
		* @pre 0<=pos<getNfechas()
		*/ 
		void eliminarPorPos(int pos);

	/**
		* @brief elimina una fecha de cronol dado su año
		* @param a Año a borrar
		*/ 
		void eliminarPorAnio(int a);

	/**
		* @brief Operador de asignación de la clase
		* @param c.cronol vector de fechas
		*/
		Cronologia & operator=(const Cronologia & c);
	
	/**
		* @brief Obtiene la sub-cronología de los hechos que contienen a la cadena h
		* @param h Cadena que estará contenida en todos los hechos de la sub-cronología
		* @param sub Cronología en la que se guarda la sub-cronología obtenida
		* @return Devuelve la sub-cronología obtenida
		*/ 
		void crearSubcronologia(string & h, Cronologia & sub) const;
	
	/**
		* @brief Obtiene la sub-cronología de los hechos que ocurrieron entre los
		*   años dados (ambos incluidos)
		* @param a1 Primer año que genera el rango
		* @param a2 Segundo año que genera el rango
		* @param sub Cronología en la que se guarda la sub-cronología obtenida
		* @return Devuelve la sub-cronología obtenida
		*/ 
		void crearSubcronologia(int a1, int a2, Cronologia & sub) const;
	
	
	/**
		* @brief Obtiene la unión de dos cronologías
		* @param c1 Primera cronología a unir
		* @param c2 Segunda cronología a unir
		*/ 
		void unir(const Cronologia & c1, const Cronologia & c2);

	/**
		* @brief Obtiene la intersección de dos cronologías
		* @param c1 Primera cronología a intersecar
		* @param c2 Segunda cronología a intersecar
		*/ 
		void intersecar(const Cronologia & c1, const Cronologia & c2);
	
	/**
		* @brief Almacena todas las fechas de una cronologia en la que llama al método
		* @param c Cronologia cuyas fechas se van a incluir
		*/ 
		void operator+=(const Cronologia & c);
	
	/**
		* @brief Salida de una Cronologia a ostream
		* @param os stream de salida
		* @param c Cronologia a escribir
		* @post Se obtiene en \a os tantas cadenas como fechas históricas haya
		*   almacenadas, separadas por saltos de línea
		*/
		friend ostream & operator<<(ostream & os, const Cronologia & c);

	/**
		* @brief Entrada de una Cronologia desde istream
		* @param is stream de entrada
		* @param fecha Cronologia que recibe el valor
		* @retval La Cronologia leído en fecha
		* @pre La entrada tiene el formato de n cadenas (tantas como fechas)
		*   separadas por saltos de línea, cada una con el formato de FechaHistorica
		*/
		friend istream & operator>>(istream & is, Cronologia & c);
};


#endif
