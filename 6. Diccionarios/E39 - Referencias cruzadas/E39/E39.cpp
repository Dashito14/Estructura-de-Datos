#include "E39.h"

bool resuelveCaso() {
	int n;

	std::cin >> n;
	std::cin.ignore();

	if (n == 0)
		return false;

	std::map<palabra, fila> palabras;

	std::string cadena, pal;

	for (int i = 1; i < n + 1; i++) {

		std::getline(std::cin, cadena);
		std::stringstream s(cadena);

		s >> pal;

		while (s) {
			if (pal.length() > 2) {
				int j = 0;
				//Pasamos la palabra a minúsculas
				while (pal[j]) {
					pal[j] = tolower(pal[j]);
					j++;
				}

				std::vector<int>& apariciones = palabras[pal];

				if (apariciones.empty() || apariciones.back() != i) {
					apariciones.push_back(i);
				}


			}
			s >> pal;
		}
	}

	auto it = palabras.begin();

	while (it != palabras.end()) {
		std::cout << it->first;
		int i = 0;

		while (i < it->second.size()) {
			std::cout << " " << it->second[i];
			i++;
		}

		std::cout << std::endl;
		it++;
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