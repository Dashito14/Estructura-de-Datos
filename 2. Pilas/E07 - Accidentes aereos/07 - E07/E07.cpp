#include "E07.h"
#include "stack_eda.h"

bool resuelveCaso(){
	char c;
	int d, m, a, v, nAcc;
	stack<Accidentes> pila;

	std::cin >> nAcc;

	if (!std::cin)
		return false;

	while (nAcc > 0){
		bool enc = false;
		std::cin >> d >> c >> m >> c >> a >> v;
		Fecha f(d, m, a);
		Accidentes acc(f, v);

		while (!enc && !pila.empty()){
			if (pila.top().getV() > v){
				std::cout << pila.top().getF() << std::endl;
				pila.push(acc);
				enc = true;
			}
			else {
				pila.pop();
			}
		}

		if (pila.empty()){
			std::cout << "NO HAY" << std::endl;
			pila.push(acc);
		}

		nAcc--;
	}

	std::cout << "---" << std::endl;
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