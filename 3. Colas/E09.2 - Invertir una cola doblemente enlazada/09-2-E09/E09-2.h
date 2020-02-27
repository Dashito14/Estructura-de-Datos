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
		Nodo* n = this->fantasma->sig;
		while (n != this->fantasma) {
			cout << n->elem << " ";
			n = n->sig;

		}
		cout << endl;
	}
	//Invierte los nodos de una lista enlazada siple
	void invierte() {
		Nodo* act = this->fantasma->sig;
		Nodo* sig = act->sig;
		Nodo* ant = act->ant;
		
		//Hacemos el primer caso fuera para tener mas facilidad para dar la vuelta entera
		//Cambiamos el sentido de las flechas del nodo actual
		act->ant = sig;
		act->sig = ant;

		//Avanzamos una posicion todos los nodos
		ant = act;
		act = sig;
		sig = sig->sig;

		//Para dar la vuelta entera tenemos que cambiar la direccion del nodo fantasma tambien
		//por eso tenemos que esperar a que actual sea fantasma, y en la siguiente vuelta salir
		while (ant != this->fantasma){

			//Cambiamos el sentido de las flechas
			act->ant = sig;
			act->sig = ant;

			//Avanzamos una posicion todos los nodos
			ant = act;
			act = sig;
			sig = sig->sig;
	
		}

	}

};

#endif