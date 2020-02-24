//Daniel Ibañez A38
//Tamara Huertas A78

#pragma once
#ifndef E082_H
#define E082_H

#include "deque_eda.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class ListaDuplica : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* n = this->fantasma->sig;
		while (n != this->fantasma) {
			cout << n->elem << " ";
			n = n->sig;
		}
		cout << endl;
	}
	// duplicar los nodos de una lista enlazada simple
	void duplica() {
		if (this->fantasma->sig != nullptr) {
			Nodo* act = this->fantasma->sig;
			while (act != this->fantasma) {
				Nodo* duplicado = new Nodo(act->elem, act, act->sig);
				act->sig = duplicado;
				act = duplicado->sig;
			}
			this->nelems = this->nelems * 2;
		}
	}
};

#endif