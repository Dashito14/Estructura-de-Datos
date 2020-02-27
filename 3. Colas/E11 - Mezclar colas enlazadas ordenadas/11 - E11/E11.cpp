#include "E11.h"

bool resuelveCaso(int &casos){
	int v;
	bool ret = true;
	ListaInserta<int> li;
	ListaInserta<int> sec;

	if (casos == 0){
		return false;
	}

	casos--;

	std::cin >> v;

	while (v != 0){
		li.push(v);
		std::cin >> v;
	}

	std::cin >> v;

	while (v != 0){
		sec.push(v);
		std::cin >> v;
	}

	li.insertaOrdenado(sec);
	li.print();

	return ret;
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