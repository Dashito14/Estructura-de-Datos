#include "bintree_eda.h"

#include <fstream>
#include <iostream>
#include <string>

//Utilizamos el tipo genérico T para solo tener que hacer una función
template <typename T>
void min(bintree<T> arbol, T &mini) {
	//Si el árbol está vacío salimos de la función
	if (arbol.empty())
		return;

	//Declaramos el valor del nodo que tenemos
	T minimN = arbol.root();

	//Comparamos el valor del nodo actual con el valor mínimo que tenemos actualmente
	if (minimN < mini)
		//Si el valor actual es menor cambiamos el valor histórico del mínimo
		mini = minimN;

	//Comprobamos el árbol por los dos lados
	min(arbol.left(), mini);
	min(arbol.right(), mini);
}

bool resuelveCaso() {
	char t;
	std::cin >> t;
	
	if (!std::cin)
		return false;
	

	if (t == 'N') {
		//Leemos el árbol numérico porque se ha introducido una N
		auto arb = leerArbol(-1);

		//Declaramos el valor mínimo actual (el primer valor del árbol)
		int minimo = arb.root();

		//Buscamos el menor con la función
		min(arb, minimo);

		//Mostramos el valor mínimo encontrado
		std::cout << minimo << std::endl;
	}
	else {
		//Declaramos el valor "vacío" del árbol para poder leerlo y que sea un bintree<string>
		std::string fin = "#";

		//Leemos el árbol de strings
		auto arb = leerArbol(fin);

		//Declaramos el valor mínimo del árbol actual, el primero
		std::string minimo = arb.root();

		//Buscamos el menos con la función
		min(arb, minimo);

		//Mostramos el valor mínimo encontrado
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