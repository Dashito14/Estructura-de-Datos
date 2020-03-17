#ifndef I18_h
#define I18_h

#include "bintree_eda.h"

#include <iostream>
#include <fstream>

template <class T>
class bintree_ext : public bintree <T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T>(l, e, r) {};
	int nodos() {
		return nod(this->raiz);
	}
	int hojas() {
		return hoj(this->raiz);
	}
	int altura() {
		return alt(this->raiz);
	}
private:
	int nod(Link r) {
		if (r == nullptr) {
			return 0;
		}
		return nod(r->left) + nod(r->right) + 1;
	}

	int hoj(Link r) {
		if (r == nullptr) {
			return 0;
		}
		if (r->right == nullptr && r->left == nullptr)
			return 1;

		return hoj(r->right) + hoj(r->left);
	}
	int alt(Link r) {
		if (r == nullptr)
			return 0;

		return std::max(alt(r->right) + 1, alt(r->left) + 1);
	}
};

template <typename T >
inline bintree_ext <T> leerArbol_ext(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un arbol vacio
		return {};
	}
	else { // leer recursivamente los hijos
		bintree_ext <T> iz = leerArbol_ext(vacio);
		bintree_ext <T> dr = leerArbol_ext(vacio);
		return { iz , raiz , dr };
	}
}

#endif