#include "bintree_eda.h"

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

//Utilizamos el tipo genérico T para solo tener que hacer una función
template <typename T>
T minim(bintree<T> a) {
	
	if (a.right().empty() && a.left().empty())
		return a.root();
	
	if (a.right().empty())
		return std::min(a.root(), minim(a.left()));

	if (a.left().empty())
		return std::min(a.root(), minim(a.right()));

	T actMin = std::min(minim(a.left()), minim(a.right()));

	return std::min(a.root(), actMin);
}

bool resuelveCaso() {
	char t;
	std::cin >> t;

	if (!std::cin)
		return false;


	if (t == 'N') {
		//Leemos el árbol numérico porque se ha introducido una N
		auto arb = leerArbol(-1);
		int minimo = minim(arb);
		std::cout << minimo << std::endl;
	}
	else {
		//Declaramos el valor "vacío" del árbol para poder leerlo y que sea un bintree<string>
		std::string fin = "#";
		
		//Leemos el árbol de strings
		auto arb = leerArbol(fin);
		std::string minimo = minim(arb);
		std::cout << minimo << std::endl;
	}

	return true;
}

int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (resuelveCaso());
	system("PAUSE");
	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
#endif
	return 0;
}