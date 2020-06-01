#ifndef E08_H
#define E08_H

#include "queue_eda.h"
#include <iostream>
#include <fstream>

template <class T>
class ListaDuplicada : public queue<T> {
	using Nodo = typename queue<T>::Nodo;

public:
	void print(std::ostream & o = std::cout) const {
		Nodo* n = this->prim;
		while (n != nullptr) {
			std::cout << n->elem << " ";
			n = n->sig;
		}
		std::cout << std::endl;
	}

	void duplica() {
		Nodo* n = this->prim;

		while (n != nullptr) {
			Nodo* d = new Nodo(n->elem, n->sig);

			n->sig = d;
			n = d->sig;


		}

		this->nelems *= 2;
	}
};

#endif
