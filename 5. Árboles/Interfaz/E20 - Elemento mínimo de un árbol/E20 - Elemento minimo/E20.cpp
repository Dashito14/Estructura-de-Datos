#include "bintree_eda.h"

#include <fstream>
#include <iostream>
#include <string>

//Utilizamos el tipo gen�rico T para solo tener que hacer una funci�n
template <typename T>
void min(bintree<T> arbol, T &mini) {
	//Si el �rbol est� vac�o salimos de la funci�n
	if (arbol.empty())
		return;

	//Declaramos el valor del nodo que tenemos
	T minimN = arbol.root();

	//Comparamos el valor del nodo actual con el valor m�nimo que tenemos actualmente
	if (minimN < mini)
		//Si el valor actual es menor cambiamos el valor hist�rico del m�nimo
		mini = minimN;

	//Comprobamos el �rbol por los dos lados
	min(arbol.left(), mini);
	min(arbol.right(), mini);
}

bool resuelveCaso() {
	char t;
	std::cin >> t;
	
	if (!std::cin)
		return false;
	

	if (t == 'N') {
		//Leemos el �rbol num�rico porque se ha introducido una N
		auto arb = leerArbol(-1);

		//Declaramos el valor m�nimo actual (el primer valor del �rbol)
		int minimo = arb.root();

		//Buscamos el menor con la funci�n
		min(arb, minimo);

		//Mostramos el valor m�nimo encontrado
		std::cout << minimo << std::endl;
	}
	else {
		//Declaramos el valor "vac�o" del �rbol para poder leerlo y que sea un bintree<string>
		std::string fin = "#";

		//Leemos el �rbol de strings
		auto arb = leerArbol(fin);

		//Declaramos el valor m�nimo del �rbol actual, el primero
		std::string minimo = arb.root();

		//Buscamos el menos con la funci�n
		min(arb, minimo);

		//Mostramos el valor m�nimo encontrado
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