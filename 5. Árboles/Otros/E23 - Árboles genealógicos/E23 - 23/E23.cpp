#include "bintree_eda.h"

#include <fstream>

struct tSol {
	//Si es correcto o no
	bool genealogico;
	//Numero de generaciones
	int generaciones;
};

tSol gene(bintree<int> arbol) {
	if (arbol.empty())
		return{ true, 0 };

	tSol izq = gene(arbol.left());

	if (!izq.genealogico)
		return { false, 0 };

	tSol dcha = gene(arbol.right());

	if (!dcha.genealogico)
		return { false, 0 };

	if (arbol.left().empty() && !arbol.right().empty()) {
		return { false, 0 };
	}
	else if (!arbol.left().empty() && arbol.right().empty()) {
		if (arbol.root() - 18 < arbol.left().root())
			return { false, 0 };

		return{ true, izq.generaciones + 1 };
	}
	else if (!arbol.left().empty() && !arbol.right().empty()) {
		if (arbol.root() - 18 < arbol.left().root() ||
			arbol.left().root() - 2 < arbol.right().root())
			return{ false , 0 };

		return{ true, std::max(izq.generaciones, dcha.generaciones) + 1 };
	}
	else {
		return { true, 1 };
	}
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol(-1);

	tSol sol = gene(arb);

	if (sol.genealogico) {
		std::cout << "SI " << sol.generaciones << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}

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