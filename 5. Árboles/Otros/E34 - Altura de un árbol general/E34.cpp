#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

inline int resolver(int vacio) {
	int v;
	std::cin >> v;

	if (v == vacio)
		return 1;

	int altura = 0;

	for (int i = 0; i < v; i++) {
		altura = std::max(altura, resolver(vacio));
	}

	return altura + 1;
}

bool resuelveCaso(int& casos) {
	if (casos == 0)
		return false;

	casos--;

	int t = resolver(0);
	std::cout << t << '\n';

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