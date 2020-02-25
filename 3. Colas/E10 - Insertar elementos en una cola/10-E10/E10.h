#ifndef E10_H
#define E10_H


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
	
	void inserta(ListaInserta &other, int pos){
		int i = 0;
		Nodo* ini = this->prim;
		Nodo* fin = nullptr;

		//Controlamos que se introduzca en el primer elemento
		if (pos == 0){
			other.ult->sig = this->prim;
			this->prim = other.prim;
		}
		else {
			//Bucle para saber en que posicion debemos parar
			//uno antes que la posicion en la que queremos insertar la otra lista
			while (i < pos - 1){
				ini = ini->sig;
				i++;
			}

			//Puntero siguiente de la primera lista para enlazarlo con el ultimo elemento
			//de la segunda lista
			fin = ini->sig;

			//Enlazamos la primera lista con el primer elemento de la segunda
			ini->sig = other.prim;

			//Enlazamos el ultimo elemento de la segunda lista con el puntero
			//que hemos creado antes 
			other.ult->sig = fin;
		}
		//Si hemos insertado en el ultimo lugar ponemos que el último sea el 
		//último de la lista que hemos insertado
		if (pos == this->nelems)
			this->ult = other.ult;

		//Aumnetamos el numero de elementos de la lista
		this->nelems += other.nelems;

		//Anulamos la segunda lista
		other.prim = other.ult = nullptr;

		//Ponemos el numero de elementos de la lista insertada a 0
		other.nelems = 0;
	}

	//Invierte los nodos de una lista enlazada siple
	void invierte() {
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

	}

};

#endif