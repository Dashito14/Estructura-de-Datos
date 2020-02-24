//Daniel Ibañez A38

#pragma once
#ifndef E09_H
#define E09_H

#include "queue_eda.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class ListaInvierte : public queue<T> {
	using Nodo = typename queue<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* n = this->prim;
		while (n != nullptr) {
			cout << n->elem << " ";
			n = n->sig;
		}
		cout << endl;
	}
	//Invierte los nodos de una lista enlazada siple
	void invierte() {
		//Creamos un nodo anterior para ir guardando el ultimo nodo que hemos cambiado de sentido
		//inicialmente a nullptr porque sera el ultimo nodo de la lista
		Nodo* p = nullptr;
		Nodo* s = this->prim;
		if (s != nullptr){
			Nodo* primeroLista = s->sig;
			this->ult = s;
			while (primeroLista != nullptr){
				//En cada vuelta que damos creamos un nodo auxiliar para no perder el elemento siguiente
				//puesto que vamos a cambiar el sentido de la flecha siguiente del nodo actual
				/*Nodo* aux = new Nodo(act->elem, act->sig);*/
				s->sig = p;
				//Hacemos que el nodo actual apunte al nodo anterior
				p = s;
				s = primeroLista;
				primeroLista = primeroLista->sig;
				//Hacemos que el nodo anterior sea el nodo actual
				/*ant = act;*/
				//El nodo actual sea el siguiente nodo del auxiliar, que era el mismo que el actual
				/*act = aux->sig;*/
			}
			//Finalmente el primer nodo ahora sera el ultimo que hemos cambiado de sentido en el bucle
			/*this->prim = ant;*/
			s->sig = p;
			this->prim = s;
		}
		
	}
	
};

#endif