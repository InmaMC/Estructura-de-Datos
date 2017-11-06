/**
  * @file StackMaxVD.h
  * @brief Fichero cabecera del TDA StackMaxVD
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en un extremo
  *
  */

#ifndef __StackMaxVD_H__
#define __StackMaxVD_H__

#include <cassert>
#include "VD.h"


struct PairInt{
	int value;		// Valor
	int max;			// Valor m�ximo
};

/**
 *  @brief T.D.A. StackMaxVD
 *
 *
 * Una instancia @e s del tipo de datos abstracto StackMaxVD es 
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In, 
 * First Out). En una pila, las operaciones de inserci�n y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope. Una pila de longitud
 * @e n la denotamos
 *
 * - [a1,a2,a3,..,an>
 *
 * donde @e ai es el elemento de la posici�n i-�sima.
 *
 * En esta pila, tendremos acceso �nicamente al elemento del @e Tope, es decir, 
 * a @e an. El borrado o consulta de un elemento ser� sobre  @e an, y la
 * inserci�n de un nuevo elemento se har� sobre �ste. Quedando el elemento
 * insertado como @e Tope de la pila.
 *
 * Si @e n=0 diremos que la pila est� vac�a.
 *
 * Adem�s, esta pila est� dotada de un m�ximo, de forma que cada elemento
 * almacenado es un struct PairInt (un par de dos enteros), un nuevo valor y el
 * m�ximo de todos los valores almacenados hasta ese momento.
 *
 * El espacio requerido para el almacenamiento es O(n). Donde n es el n�mero de
 * elementos de la Pila.
 *
 * @author Inmaculada Mar�n Carballo
 * @author Alejandro Palencia Blanco
 * @date Noviembre 2017
 */

class StackMaxVD{
	private:
		VectorDinamico<PairInt> vd_stackmax;

	public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    StackMaxVD(){}

    /**
     * @brief Constructor de copias
     * @param copy La pila de la que se har� la copia.
     */
    StackMaxVD(const StackMaxVD & copy);

    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~StackMaxVD(){}

    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignaci�n
     * @param copy La pila que se va a asignar.
     */
    StackMaxVD & operator=(const StackMaxVD & copy);

    /**
     * @brief Comprueba si la pila est� vac�a
     */
    bool empty() const{
      return vd_stackmax.vacio();
    }

    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    PairInt & top(){
      assert(!empty());
      return vd_stackmax[vd_stackmax.getOcupados()-1];
    }

    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const PairInt & top() const{
      assert(!empty());
      return vd_stackmax[vd_stackmax.getOcupados()-1];
    }

    /**
     * @brief A�ade un elemento "encima" del tope de la pila
     * @param newvalue Elemento que se va a a�adir.
     */
    void push(int newvalue);

    /**
     * @brief Quita el elemento del tope de la pila
     */
    void pop();

    /**
     * @brief Devuelve el n�mero de elementos de la pila
     */
    int size() const{
      return vd_stackmax.getOcupados();
    }
};


#endif // __StackMaxVD_H__
