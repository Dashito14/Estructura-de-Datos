#ifndef A17_H
#define A17_H

#include "deque_eda.h"

#include <iostream>
#include <fstream>

template <class T>
class ListaEngorda : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		int i = this->nelems;
		Nodo* n = this->fantasma->sig;
		while (i > 0) {
			std::cout << n->elem << " ";
			n = n->sig;
			i--;
		}
		std::cout << std::endl;
	}

	void engorda(ListaEngorda& le){
		Nodo* n = le.fantasma->sig;
		int i = 0;

		while (n != le.fantasma){
			Nodo * s = n->sig;

			if (i % 2 == 0){
				n->ant = this->fantasma;
				n->sig = this->fantasma->sig;
				this->fantasma->sig->ant = n;
				this->fantasma->sig = n;

				le.fantasma->sig = s;
				s->ant = le.fantasma;
			}
			else {
				n->ant = this->fantasma->ant;
				n->sig = this->fantasma;
				this->fantasma->ant->sig = n;
				this->fantasma->ant = n;

				le.fantasma->sig = s;
				s->ant = le.fantasma;

			}
			n = s;
			i++;
		}

		this->nelems += le.nelems;

		//vaciamos la segunda lista
		le.fantasma->sig = le.fantasma;
		le.fantasma->ant = le.fantasma;

		le.nelems = 0;
	}
};

#endif