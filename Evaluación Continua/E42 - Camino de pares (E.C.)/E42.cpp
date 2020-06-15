#include "bintree_eda.h"

#include <fstream>

typedef struct tSol{
	int maximo; //Longitud maxima
	int act; //Longitud actual
	int longMax; //Longitud de un hijo mas largo
};

tSol resolver(bintree<int> arb) {
	if (arb.empty())
		return { 0, 0, 0 };

	tSol iz = resolver(arb.left());
	tSol dcha = resolver(arb.right());

	if (arb.root() % 2 != 0) {
		int m = std::max(iz.maximo, dcha.maximo);
		int h = std::max(iz.act, dcha.act);

		return { std::max(h, m), 0, 0 };
	}

	int a = iz.longMax + dcha.longMax + 1;
	int lm = std::max(iz.longMax, dcha.longMax) + 1;
	int t = std::max(iz.maximo, dcha.maximo);
	int ma = std::max(t, a);

	return{ma, a, lm};
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol(-1);
	tSol r = resolver(arb);

	std::cout << r.maximo << std::endl;

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