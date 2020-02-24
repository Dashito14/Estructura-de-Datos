// Los k elementos mayores

// Alberto Verdejo

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

#include "E05.h"

template <class T>
void resuelve(T centinela) {
	int n;
	std::cin >> n;
	T elem;
	set<T> conj;
	cin >> elem;

	while (elem != centinela) {
		if (conj.size() < n)
			conj.insert(elem);
		//En el primer caso de prueba dice que el 5 si que lo contiene
		else if (!conj.contains(elem) && conj.min() < elem) {
			conj.erase_min();
			conj.insert(elem);
		}

		cin >> elem;
	}

	for (int i = n - 1; i > -1; i--) {
		cout << conj.get_datos(i) << " ";
	}

	cout << endl;
}

bool resuelveCaso() {
	char tipo;
	cin >> tipo;


	if (!cin)
		return false;

	if (tipo == 'N') { // el caso es de números
		resuelve(-1);
	}
	else { // el caso es de cadenas
		resuelve(string("FIN"));
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