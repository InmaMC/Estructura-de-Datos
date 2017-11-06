/**
  * @file StackMaxQ.cpp
  * @brief Implementación del TDA StackMaxQ
  *
  */
#include <cassert>
#include "StackMaxQ.h"

/* _________________________________________________________________________ */

//StackMaxQ::StackMaxQ(){}

/* _________________________________________________________________________ */

StackMaxQ::StackMaxQ(const StackMaxQ & copy){
	if (!copy.empty()){            //Si la pila original no está vacía
	    q_stackmax = copy.q_stackmax;
    }
}

/* _________________________________________________________________________ */

StackMaxQ & StackMaxQ::operator=(const StackMaxQ & copy){
	if (this!=&copy)
		q_stackmax=copy.q_stackmax;
  return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

/*_________________________________________________________________________ */

void StackMaxQ::push(int newvalue){
	int newmax;
	if(empty())
		newmax=newvalue;
	else
		newmax= top().max>newvalue ? top().max : newvalue;
	PairInt newpair(newvalue, newmax);
	q_stackmax.ponerFrente(newpair);
}

/* _________________________________________________________________________ */

void StackMaxQ::pop(){
  assert(!empty());
	q_stackmax.quitar();
}
