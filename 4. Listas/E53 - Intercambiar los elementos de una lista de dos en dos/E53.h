#ifndef E53_H
#define E53_H


#include "queue_eda.h"

#include <iostream>
#include <fstream>

template <class T>
class ListaIntercambiar : public queue<T> {
	using Nodo = typename queue<T>::Nodo;
public:
	void print(std::ostream& o = std::cout) const {
		int i = this->nelems;
		Nodo* n = this->prim;
		while (i > 0) {
			std::cout << n->elem << " ";
			n = n->sig;
			i--;
		}
		std::cout << std::endl;
	}

	void intercambiar() {
		Nodo* n = this->prim;

		//Si solo hay uno
		if (this->prim == this->ult) {
			return;
		}

		//Si hay dos nodos
		if (this->prim->sig == this->ult) {
			Nodo* r = this->prim->sig;
			this->ult = n;
			this->prim = r;

			r->sig = n;

			return;
		}

		Nodo* g = n->sig->sig;

		while (g != this->ult) {
			n->sig->sig = n;

			if (n == this->prim) {
				this->prim = n->sig;
			}

			n->sig = g->sig;
			n = g;

			if (g->sig == this->ult) {
				g->sig->sig = n;
				this->ult = n;
			}
			else {
				g = g->sig->sig;
			}

		}

		//Hay 3 elementos
		if (n == this->prim) {
			this->prim = n->sig;	
		}

		if (this->nelems % 2 != 0) {
			n->sig->sig = n;
			n->sig = g;
		}
	}
};

#endif