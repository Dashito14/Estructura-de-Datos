#include "E53.h"

bool resuelveCaso() {
	int n, r;
	ListaIntercambiar<int> li;

	std::cin >> n;

	if (n == 0)
		return false;

	while (n != 0) {
		std::cin >> r;
		li.push(r);
		n--;
	}

	li.intercambiar();
	li.print();

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