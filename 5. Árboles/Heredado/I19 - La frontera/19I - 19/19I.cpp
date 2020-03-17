#include "19I.h"

bool resuelveCaso(int &casos) {

	if (casos == 0)
		return false;

	std::vector<int> v;
	casos--;

	auto arb = leerArbol_ext(-1);
	v = arb.frontera();
	
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}

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