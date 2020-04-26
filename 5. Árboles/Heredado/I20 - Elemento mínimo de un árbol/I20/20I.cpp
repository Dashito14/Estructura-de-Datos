#include "20I.h"

bool resuelveCaso() {

	char letra;

	std::cin >> letra;

	if (!std::cin)
		return false;

	if (letra == 'N') {
		auto arb = leerArbol_ext(-1);

		std::cout << arb.minim() << std::endl;
	}
	else {
		std::string fin = "#";
		auto arb = leerArbol_ext(fin);

		std::cout << arb.minim() << std::endl;
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