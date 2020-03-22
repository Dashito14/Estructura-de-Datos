#ifndef I21_h
#define I21_h

#include "bintree_eda.h"

#include <iostream>
#include <fstream>

struct tSol {
	int alt;
	int d;
};

template <class T>
class bintree_ext : public bintree <T> {
	using Link = typename bintree <T>::Link;
public:
	bintree_ext() : bintree <T>() {}
	bintree_ext(bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T>(l, e, r) {};

	tSol dia() {
		return diametro(this->raiz);
	}

private:
	tSol diametro(Link r) {
		if (r == nullptr)
			return{0, 0};

		tSol der = diametro(r->right);
		tSol izq = diametro(r->left);

		if (der.alt + izq.alt + 1 > der.d && der.alt + izq.alt + 1 > izq.d)
			return { std::max(der.alt, izq.alt) + 1, der.alt + izq.alt + 1 };

		return { std::max(der.alt, izq.alt) + 1, std::max(izq.d, der.d) };
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