#ifndef E11_H
#define E11_H


#include "queue_eda.h"

#include <iostream>
#include <fstream>

template <class T>
class ListaInserta : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
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

	void insertaOrdenado(ListaInserta& other){
		Nodo* p = this->prim;
		Nodo* p2 = other.prim;

		//Si el primer elemento de la segunda lista es nulo no hace falta hacer nada
		if (p2 == nullptr){
			return;
		}
		
		Nodo* p2Sig = p2->sig;
		Nodo* ant = nullptr;

		//Si el primer elemento de la lista principal es nulo, hacemos que la lista secundaria sea la principal
		if (p == nullptr){
			this->prim = other.prim;

			//Sumamos los elementos, va a ser igual a other.elems porque this->elems es 0
			this->nelems += other.nelems;

			//Anulamos la segunda lista
			other.prim = other.ult = nullptr;

			return;
		}

		if (p2->elem < p->elem){
			//Convertimos el primer elemento de la segunda lista en el primer elemento de
			//la lista principal
			this->prim = p2;

			//Enganchamos al primer elemento
			p2->sig = p;
			ant = p2;

			//Avanzamos los punteros de la segunda lista
			p2 = p2Sig;
			
			//Solo si el siguiente de p2 no era nulo lo podemos avanzar
			if (p2Sig != nullptr){
				p2Sig = p2Sig->sig;
			}
		}

		while (p2 != nullptr && p != nullptr){
			if (p2->elem < p->elem){
				//Enganchamos por detras
				ant->sig = p2;

				//Enganchamos por delante
				p2->sig = p;

				//Hacemos que el anterior sea el elemento de la lista actual
				ant = p2;

				//Avanzamos los punteros de la segunda lista
				p2 = p2Sig;

				//Solo si el siguiente de p2 no era nulo lo podemos avanzar
				if (p2Sig != nullptr){
					p2Sig = p2Sig->sig;
				}

			}
			else {
				//Avanzamos la lista principal
				ant = p;
				p = p->sig;
			}
		}

		//Si salimos del bucle porque la lista principal ha llegado al final
		if (p == nullptr){
			ant->sig = p2;
		}

		this->nelems += other.nelems;
		other.prim = other.ult = nullptr;
	}
};

#endif