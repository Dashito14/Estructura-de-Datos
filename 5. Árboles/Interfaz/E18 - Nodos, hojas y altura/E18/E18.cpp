#include "bintree_eda.h"

#include <fstream>
#include <iostream>



/*CUENTA EL NUMERO DE NODOS QUE TIENE EL ÁRBOL*/
int nodos(bintree<char> const &arbol) {
	if (arbol.empty()) {
		return 0;
	}
	return nodos(arbol.left()) + nodos(arbol.right()) + 1;
}

int hojas(bintree<char> const &arbol) {
	if (arbol.empty()) {
		return 0;
	}

	if (arbol.right().empty() && arbol.left().empty())
		return 1;

	return hojas(arbol.right()) + hojas(arbol.left());
}


/*VEMOS LA ALTURA MÁXIMA, DEVOLVIENDO ESTE VALOR MÁXIMO*/
int altura(bintree<char> const &arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		//Devolvemos el que sea la altura máxima por cualquiera de los dos lados, sumando uno puesto que hay que contar la altura actual
		return std::max(altura(arbol.left()) + 1, altura(arbol.right()) + 1);
	}
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	auto arb = leerArbol('.');

	std::cout << nodos(arb) << " " << hojas(arb) << " " << altura(arb) << std::endl;

	casos--;
	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	int casos;
	std::cin >> casos;
	while (resuelveCaso(casos));
	system("PAUSE");
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}