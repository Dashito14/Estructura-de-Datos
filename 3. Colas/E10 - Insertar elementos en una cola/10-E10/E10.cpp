#include "E10.h"

bool resuelveCaso(){
	int n, v, pos, x;
	bool ret = true;
	ListaInserta<int> li;
	ListaInserta<int> sec;

	std::cin >> n;

	if (!std::cin)
		return false;

	for (int i = 0; i < n; i++){
		std::cin >> v;
		li.push(v);
	}

	std::cin >> x;
	std::cin >> pos;

	for (int i = 0; i < x; i++){
		std::cin >> v;
		sec.push(v);
	}

	li.inserta(sec, pos);
	li.print();


	return ret;
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