#include "E46.h"


bool resuelveCaso() {

	std::string op;

	std::cin >> op;

	carnet_puntos cp;

	if (!std::cin) {
		return false;
	}

	while (op != "FIN") {

		if (op == "nuevo") {
			dni dn;
			std::cin >> dn;
			try {
				cp.nuevo(dn);
			}
			catch (std::domain_error &de) {
				std::cout << de.what() << std::endl;
			}
		}
		else if (op == "cuantos_con_puntos") {
			puntos v;
			std::cin >> v;
			try {
				int a = cp.cuantos_con_puntos(v);
				std::cout << "Con " << v << " puntos hay " << a << std::endl;
			}
			catch (std::domain_error &de) {
				std::cout << de.what() << std::endl;
			}
		}
		else if (op == "quitar") {
			dni d;
			puntos p;
			std::cin >> d >> p;
			try {
				cp.quitar(d, p);
			}
			catch (std::domain_error &de) {
				std::cout << de.what() << std::endl;
			}
		}
		else /*consultar*/ {
			dni d;
			std::cin >> d;
			try {
				int a = cp.consultar(d);
				std::cout << "Puntos de " << d << ": " << a << std::endl;
			}
			catch (std::domain_error &de) {
				std::cout << de.what() << std::endl;
			}
		}

		std::cin >> op;
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
