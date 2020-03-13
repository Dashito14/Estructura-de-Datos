#include <iostream>
#include <fstream>

#include "list_eda.h"

void colocarEnColaDoble(deque<int> &d, int v) {
	//Si la cola no esta vacia
	if (!d.empty()) {
		//Mientras la cola no se quede vacia y el elemento sea mayor que el ultimo de la cola eliminamos el ultimo
		while (!d.empty() && v > d.back()) {
			d.pop_back();
		}
	}
	//siempre tenemos que meter el ultimo valor
	d.push_back(v);
}

bool resuelveCaso() {
	int n, k, v, numV = 0;
	int max = -1;

	list<int> l;
	deque<int> d;

	//Creamos un iterador
	auto it = l.begin();

	std::cin >> n >> k;

	if (n == 0 && k == 0)
		return false;

	while (numV < n) {
		//Si es la primera lista de numeros los procesamos
		if (numV < k) {
			while (numV < k) {
				std::cin >> v;
				//Introducimos el valor en la lista
				l.push_back(v);
				numV++;
				//Colocamos en orden en la cola doble
				colocarEnColaDoble(d, v);
			}
			it = l.begin();
			//Mostramos el numero mas alto
			std::cout << d.front() << " ";
		}
		else{ 
			std::cin >> v;
			numV++;
			l.push_back(v);

			//Si el valor del lugar donde apunta el iterador es el valor mas alto de la lista
			if (*it == d.front()) {
				d.pop_front();
				colocarEnColaDoble(d, v);

				//Avanzamos uno el iterador;
				it++;
			}
			else {
				colocarEnColaDoble(d, v);
				it++;
			}

			std::cout << d.front() << " ";
		}
	}
	std::cout << std::endl;

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