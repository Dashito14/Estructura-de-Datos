#include "A17.h"

bool resuelveCaso(int &casos){
	if (casos == 0)
		return false;

	ListaEngorda<int> lp;
	ListaEngorda<int> ls;

	long int n, v;

	std::cin >> n;

	for (int i = 0; i < n; i++){
		std::cin >> v;
		lp.push_back(v);
	}

	std::cin >> n;

	for (int i = 0; i < n; i++){
		std::cin >> v;
		ls.push_back(v);
	}

	lp.engorda(ls);
	lp.print();

	casos--;

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