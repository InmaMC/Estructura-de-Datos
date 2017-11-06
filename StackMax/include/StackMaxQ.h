/**
  * @file StackMaxQ.h
  * @brief Fichero cabecera del TDA StackMaxQ
  *
  * Gestiona una secuencia de elementos con facilidades para la inserci�n y
  * borrado de elementos en un extremo
  *
  */

#ifndef __StackMaxQ_H__
#define __StackMaxQ_H__

#include <cassert>
#include "Queue.h"

struct PairInt{
	int value;			// Valor
	int max;			// Valor m�ximo
		
	/**
	* @brief Constructor por defecto
	*/
		    
	PairInt() : value(0), max(0){}
		     
	/**
	* @brief Constructor con par�metros
	* @param value Valor del elemento.
	* @param max Valor maximo de la pila hasta este elemento.
	*/
	PairInt(int v, int m): value(v), max(m){}
};


/**
 *  @brief T.D.A. StackMaxQ
 *
 *
 * Una instancia @e s del tipo de datos abstracto StackMaxQ es 
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
 * @author Alejandro Palencia Blanco
 * @author Inmaculada Marin Carballo 
 * @date Noviembre 2017
 */



class StackMaxQ{
	private:
		Cola<PairInt> q_stackmax;

	public:
    // ---------------  Constructores ----------------
    /**
     * @brief Constructor por defecto
     */
    StackMaxQ(){}

    /**
     * @brief Constructor de copias
     * @param copy La pila de la que se har� la copia.
     */
    StackMaxQ(const StackMaxQ & copy);

    // ------------------ Destructor ------------------
    /**
     * @brief Destructor
     */
    ~StackMaxQ(){}

    // --------------- Otras funciones ---------------
    /**
     * @brief Operador de asignaci�n
     * @param copy La pila que se va a asignar.
     */
    StackMaxQ & operator=(const StackMaxQ & copy);

    /**
     * @brief Comprueba si la pila est� vac�a
     */
    bool empty() const{
      return q_stackmax.vacia();
    }

    /**
     * @brief Devuelve el elemento del tope de la pila
     */
    PairInt & top(){
			assert(!empty());
			return q_stackmax.frente();
    }

    /**
     * @brief Devuelve el elemento del tope de una pila constante
     */
    const PairInt & top() const{
			assert(!empty());
			return q_stackmax.frente();
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
      return q_stackmax.num_elementos();
    }
};


#endif // __StackMaxQ_H__
