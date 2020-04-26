#ifndef I20_h
#define I20_h

#include "bintree_eda.h"

#include <iostream>
#include <fstream>
#include <vector>

template <class T>
class bintree_ext : public bintree <T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T>(l, e, r) {};
	T minim() {
		return mn(this->raiz);
	}
private:

	T mn(Link r) {
		if (r->left == nullptr && r->right == nullptr)
			return r->elem;

		if (r->right == nullptr)
			return std::min(r->elem, mn(r->left));

		if (r->left == nullptr)
			return std::min(r->elem, mn(r->right));

		T mAct = std::min(mn(r->left), mn(r->right));
		
		return std::min(r->elem, mAct);
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

