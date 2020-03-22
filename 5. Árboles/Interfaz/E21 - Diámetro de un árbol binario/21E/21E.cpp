#include "bintree_eda.h"

#include <fstream>

struct tSol {
	int alt;
	int d;
};

tSol sol(bintree<char> arbol) {
	if (arbol.empty())
		return{ 0, 0 };

	tSol der = sol(arbol.right());
	tSol izq = sol(arbol.left());

	if(der.alt + izq.alt + 1 > der.d && der.alt + izq.alt + 1 > izq.d)
		return { std::max(der.alt, izq.alt) + 1, der.alt + izq.alt + 1};

	return { std::max(der.alt, izq.alt) + 1, std::max(izq.d, der.d)};
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol('.');
	
	std::cout << sol(arb).d << std::endl;

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