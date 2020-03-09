#include "E03.h"

bool resuelveCaso() {
	int nCasos, nIt;
	float r, i;
	std::cin >> nCasos;

	while (nCasos > 0) {
		std::cin >> r >> i >> nIt;
		Complejo z(0, 0);
		Complejo c(r, i);
		while (mod(z) < 2 && nIt > 0) {
			z = z * z + c;
			nIt--;
		}
		if (nIt == 0 && mod(z) < 2) {
			std::cout << "SI" << std::endl;
		}
		else {
			std::cout << "NO" << std::endl;
		}
		nCasos--;
	}

	return false;
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