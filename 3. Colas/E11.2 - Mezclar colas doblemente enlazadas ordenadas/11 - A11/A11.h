#ifndef A11_H
#define A11_H

#include "deque_eda.h"

#include <iostream>
#include <fstream>

template <class T>
class ListaInserta : public deque<T> {
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

	void inserta(ListaInserta &other){
		Nodo* pr = this->fantasma->sig;
		Nodo* p2 = other.fantasma->sig;
		Nodo* p2Sig = p2->sig;
	
		while (pr != this->fantasma && p2 != other.fantasma){
			if (p2->elem < pr->elem){

				//Enganchamos por detras
				pr->ant->sig = p2;
				p2->ant = pr->ant;

				//Enganchamos por delante
				p2->sig = pr;
				pr->ant = p2;

				//Movemos los punteros de la segunda lista
				p2 = p2Sig;
				p2Sig = p2Sig->sig;
			}
			else {
				//Avanzamos el puntero de la primera lista
				pr = pr->sig;
			}
		}

		//Si hemos salido del bucle porque la primera lista ha llegado al final pero aun quedan
		//elementos en la segunda, enganchamos los que quedan
		if (p2 != other.fantasma){
			Nodo* ult = other.fantasma->ant;

			//Enganchamos por delante
			this->fantasma->ant->sig = p2;
			p2->ant = this->fantasma->ant;


			//Enganchamos por detras
			ult->sig = this->fantasma;
			this->fantasma->ant = ult;
		}

		//Sumamos el numero de elementos de las dos listas para ver el total
		this->nelems += other.nelems;

		//Hacemos que el siguiente nodo y el anterior del fantasma sea el fantasma para anular la lista
		other.fantasma->sig = other.fantasma;
		other.fantasma->ant = other.fantasma;

		//Hacemos que la lista 2 no tenga elementos
		other.nelems = 0;
	}

};

#endif