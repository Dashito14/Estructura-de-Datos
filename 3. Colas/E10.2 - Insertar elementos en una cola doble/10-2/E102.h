#ifndef E102_H
#define E102_H

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

	void inserta(ListaInserta &other, int pos){
		Nodo* ini = this->fantasma->sig;
		Nodo* primLista2 = other.fantasma->sig;
		Nodo* ultLista2 = other.fantasma->ant;
		
		//Controlamos si hay que ponerlo en la primera posicion
		if (pos == 0){
			//Enganchamos el fantasma con el principio de la lista 2
			this->fantasma->sig = primLista2;
			primLista2->ant = this->fantasma;

			//Enganchamos el final de la lista 2 con el principio de la lista 1
			ultLista2->sig = ini;
			ini->ant = ultLista2;
		}
		else {
			int i = 0;
			//Buscamos el nodo anterior a la posicion en la que queremos colocar la lista
			while (i < pos - 1){
				ini = ini->sig;
				i++;
			}
			//Guardamos el nodo siguiente al que hemos encontrado
			Nodo* fin = ini->sig;

			//Enganchamos por delante
			ini->sig = primLista2;
			primLista2->ant = ini;

			//Enganchamos por detrás
			ultLista2->sig = fin;
			fin->ant = ultLista2;
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