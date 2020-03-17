#ifndef I19_h
#define I19_h

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
	std::vector<int> frontera() {
		std::vector<int> v;
		fro(this->raiz, v);
		return v;
	}
private:
	void fro(Link r, std::vector<int> &v) {
		if (r == nullptr)
			return;

		if (r->left == nullptr && r->right == nullptr)
			v.push_back(r->elem);

		fro(r->left, v);
		fro(r->right, v);
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
