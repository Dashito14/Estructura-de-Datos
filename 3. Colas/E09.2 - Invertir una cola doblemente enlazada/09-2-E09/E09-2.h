//Daniel Ibañez A38

#pragma once
#ifndef E09_H
#define E09_H

#include "deque_eda.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class ListaInvierte : public deque<T> {
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		int i = this->nelems;

		Nodo* n = this->fantasma->sig;
		while (i > 0) {
			cout << n->elem << " ";
			n = n->sig;
			i--;
		}
		cout << endl;
	}
	//Invierte los nodos de una lista enlazada siple
	void invierte() {
		Nodo* act = this->fantasma->sig;
		Nodo*prim = this->fantasma->sig;
		int i = 0;

		while (i < this->nelems){
			Nodo* aux = new Nodo(act->elem, act->ant, act->sig);
			act->sig = act->ant;
			act->ant = aux->sig;
			i++;
			act = aux->sig;
		}

		this->fantasma->sig = this->fantasma->ant;
		this->fantasma->ant = prim;
		/*
		//Creamos un nodo anterior para ir guardando el ultimo nodo que hemos cambiado de sentido
		//inicialmente a nullptr porque sera el ultimo nodo de la lista
		Nodo* ant = nullptr;
		//El nodo actual que vamos a utilizar, empezamos por el primero
		Nodo* act = this->prim;


		while (act != nullptr){
			//En cada vuelta que damos creamos un nodo auxiliar para no perder el elemento siguiente
			//puesto que vamos a cambiar el sentido de la flecha siguiente del nodo actual
			Nodo* aux = new Nodo(act->elem, act->sig);

			//Hacemos que el nodo actual apunte al nodo anterior
			act->sig = ant;
			//Hacemos que el nodo anterior sea el nodo actual
			ant = act;
			//El nodo actual sea el siguiente nodo del auxiliar, que era el mismo que el actual
			act = aux->sig;
		}
		//Finalmente el primer nodo ahora sera el ultimo que hemos cambiado de sentido en el bucle
		this->prim = ant;
		*/

	}

};

#endif