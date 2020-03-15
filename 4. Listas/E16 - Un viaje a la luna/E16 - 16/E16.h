#pragma once
#ifndef E16_H
#define E16_H

#include "list_eda.h"

#include <iostream>
#include <fstream>
#include <string>

class Persona {
private:
	int edad;
	std::string nombre;

public:
	Persona() {}
	Persona(int e, std::string n) : edad(e), nombre(n) {}

	int getE() const { return edad; }
	std::string getN() const { return nombre; }
};

inline std::ostream& operator <<(std::ostream &out, Persona const& p) {
	out << p.getN();
	return out;
}

template <class T>
class Lista : public list<T> {
private:
	using Nodo = typename deque<T>::Nodo; // para poder usar Nodo aquí
public:
	void print(std::ostream& o = std::cout) const {
		Nodo* n = this->fantasma->sig;

		while (n != this->fantasma) {
			std::cout << n->elem.getN() << std::endl;
			n = n->sig;
		}

		std::cout << "---" << std::endl;
	}

	template <class Predicate>
	void remove_if(Predicate pred) {
		auto it = this->begin();
		//Hasta que no llegue al final de la lista
		while (it != this->end()) {
			if (!pred(*it)) {
				//Eliminamos ese elemento de la lista
				it = this->erase(it);
			}
			else {
				++it;
			}
		}
	}

};

#endif