#include "E36.h"
#include <fstream>

bool resuelveCaso() {
	int eje;
	nombre n;
	std::string sol;

	evaluacion ev;

	std::cin >> eje;

	if (eje == 0)
		return false;

	for (int i = 0; i < eje; i++) {
		std::cin.ignore();
		std::getline(std::cin, n);
		std::cin >> sol;

		ev.ver_solucion(n, sol);
	}

	ev.mostrar();

	std::cout << "---" << std::endl;

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