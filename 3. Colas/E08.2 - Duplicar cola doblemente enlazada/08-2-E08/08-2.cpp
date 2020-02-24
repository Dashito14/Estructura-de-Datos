#include "08-2.h"

bool resuelveCaso() {
	ListaDuplica<int> l;

	if (!cin) {
		return false;
	}

	int v;
	cin >> v;

	while (v != 0) {
		l.push_back(v);
		cin >> v;
	}

	l.duplica();
	l.print();

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