#include "E08.h"

bool resuelveCaso() {
	ListaDuplicada<int> ld;

	if (!std::cin)
		return false;

	int v;
	std::cin >> v;

	while (v != 0) {
		ld.push(v);
		std::cin >> v;
	}

	ld.duplica();
	ld.print();

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