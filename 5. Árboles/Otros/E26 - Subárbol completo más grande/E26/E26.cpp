#include "bintree_eda.h"

#include <fstream>

struct tSol {
	//Si es completo o no de momento
	bool completo;
	//Altura del arbol completo
	int alt;
	//Altura máxima de un árbol completo hasta el momento
	int max;
};

tSol completo(bintree<char> a) {
	if (a.empty())
		return { false, 0, 0 };
	
	if (a.left().empty() && a.right().empty())
		return { true, 1, 1 };
	
	tSol izq = completo(a.left());
	tSol dcha = completo(a.right());

	int maxim = std::max(izq.max, dcha.max);
	return { true, std::min(izq.alt, dcha.alt) + 1, std::max(maxim, std::min(izq.alt, dcha.alt) + 1) };

}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol('.');

	tSol sol = completo(arb);

	std::cout << sol.max << std::endl;

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