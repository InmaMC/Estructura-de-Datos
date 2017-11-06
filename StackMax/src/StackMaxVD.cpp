/**
  * @file StackMaxVD.cpp
  * @brief Implementación del TDA StackMaxVD
  *
  */
#include <cassert>
#include "StackMaxVD.h"

/* _________________________________________________________________________ */

StackMaxVD::StackMaxVD(const StackMaxVD & copy): vd_stackmax(copy.vd_stackmax){
}

/* _________________________________________________________________________ */

StackMaxVD & StackMaxVD::operator=(const StackMaxVD & copy){
	if (this!=&copy)
		vd_stackmax=copy.vd_stackmax;
  return *this; //Devolvemos el objeto para permitir el encadenamiento (a=b=c)
}

/*_________________________________________________________________________ */

void StackMaxVD::push(int newvalue){
	int newmax=newvalue;
	if (!empty())
		if (top().max>newvalue)
			newmax=top().max;
	PairInt newpair={newvalue, newmax};
	vd_stackmax.insertar(newpair, vd_stackmax.getOcupados());
}

/* _________________________________________________________________________ */

void StackMaxVD::pop(){
  assert(!empty());
	vd_stackmax.eliminar(vd_stackmax.getOcupados()-1);
}
