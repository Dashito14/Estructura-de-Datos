#include "E43.h"
#include <fstream>
#include <vector>

bool resuelveCaso() {
	int nNums;

	std::cin >> nNums;

	if (!std::cin)
		return false;

	std::unordered_map<numero, repeticiones> redundancia;
	std::vector<std::pair<int, int>> v;

	int n;

	//Una vuelta por cada numero que haya en la lista
	for (int i = 0; i < nNums; i++) {
		std::cin >> n;

		//Buscamos si está la clave introducido en el mapa
		auto it = redundancia.find(n);

		//Si el iterador no apunta a end(), está y si no es el primer valor que introducimos, sumamos uno a su valor
		if (it != redundancia.end() && i != 0) {
			redundancia[n]++;
		}
		//Si no está y no es el primer valor que introducimos, insertamos en el final el par, con un 1 porque es la primera repeticion
		else {
			redundancia.insert(redundancia.end(), std::pair<numero, repeticiones>(n, 1));
			v.push_back({ n, 1 });
		}
	}

	int i = 0;

	while (i < v.size()) {
		v[i].second = redundancia.at(v[i].first);
		i++;
	}

	i = 0;

	//Mostramos
	while (i < v.size())
	{
		std::cout << v[i].first << " " << v[i].second << std::endl;
		i++;
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