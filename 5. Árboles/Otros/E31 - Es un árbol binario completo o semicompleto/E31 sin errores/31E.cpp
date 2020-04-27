#include "bintree_eda.h"

#include <fstream>
#include <iostream>
#include <string>

struct tSol {
	int alt;
	bool completo;
	bool semicompleto;
};

tSol esCompleto(bintree<char> a) {
	//Si el árbol es vacío es completo, semicompleto y de altura 0.
	if (a.empty()) {
		return { 0, true, true };
	}
	//Si es un nodo hoja devolvemos que es un arbol completo con la altura del nodo
	if (a.left().empty() && a.right().empty()) {
		return { 1, true, true };
	}

	//Sino, se miran los hijos
	tSol iz = esCompleto(a.left());
	tSol dcha = esCompleto(a.right());

	//Si ambos son completos y la altura es igual es completo y por lo tanto tambien semicompleto.
	if (iz.completo && dcha.completo && iz.alt == dcha.alt) {
		return { iz.alt + 1, true, true };
	}

	//Creo que innecesario
	if (iz.completo && dcha.completo && iz.alt - 1 == dcha.alt) {
		return { iz.alt + 1, false, true };
	}

	//Si el izquierdo es semicompleto, la unica forma de que sea semicompleto el total es que el derecho sea completo y tenga uno menos de altura
	if (iz.semicompleto && dcha.completo && dcha.alt + 1 == iz.alt) {
		return{ iz.alt + 1, false, true };
	}

	//Si el izquierdo es completo, la única forma de que el total sea semicompleto es que el derecho sea semicompleto y con igual altura que el izquierdo
	if (iz.completo && dcha.semicompleto && dcha.alt == iz.alt) {
		return{ iz.alt + 1, false, true };
	}

	return{ 0, false, false };
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol('.');

	tSol sol = esCompleto(arb);

	if (sol.completo)
		std::cout << "COMPLETO" << std::endl;

	else if (sol.semicompleto)
		std::cout << "SEMICOMPLETO" << std::endl;

	else
		std::cout << "NADA" << std::endl;

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