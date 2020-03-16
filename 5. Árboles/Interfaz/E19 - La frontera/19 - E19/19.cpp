#include "bintree_eda.h"

#include <fstream>
#include <iostream>

void frontera(bintree<int> arbol) {
	if (arbol.empty()) {
		return;
	}
	else {
		if (arbol.left().empty() && arbol.right().empty()) {
			std::cout << arbol.root() << " ";
			return;
		}

		frontera(arbol.left());
		frontera(arbol.right());
	}
}

bool resuelveCaso(int &casos) {

	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol(-1);

	//en la funcion frontera mostrara uno a uno los elementos que haya en las hojas
	frontera(arb);

	//Salto de linea para la salida, que no salgan todos los casos en la misma linea
	std::cout << std::endl;

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