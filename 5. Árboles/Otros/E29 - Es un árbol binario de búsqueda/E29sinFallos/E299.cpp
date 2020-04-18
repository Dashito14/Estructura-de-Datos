#include <iostream>
#include <fstream>

#include "bintree_eda.h"

struct tSol {
	int min;
	int max;
	bool es;
};

tSol es_abb(bintree<int> a) {
	//Si el árbol está vacio se devuelve un valor mínimo de -1, un valor maximo de 0 y que es correcto el arbol
	if (a.empty())
		return { -1, 0, true };

	//Se navega por los dos hijos
	tSol iz = es_abb(a.left());
	tSol dcha = es_abb(a.right());

	//Si el hijo derecho estaba vacio hacemos que el valor minimo sea el de la raiz mas 1 para
	//que en el siguiente if se cumpla la condicion
	if (dcha.min == -1)
		dcha.min = a.root() + 1;

	if (iz.es && dcha.es && a.root() > iz.max && a.root() < dcha.min) {
		//Si el hijo izquierdo estaba vacio hacemos que el valor minimo sea el actual de la raiz
		if (iz.min == -1)
			iz.min = a.root();

		//Si el hijo derecho estaba vacio el maximo es la raiz ahora
		if (dcha.max == 0)
			dcha.max = a.root();

		return{ iz.min, dcha.max, true };
	}
	else {
		return{ 0, 0, false };
	}


}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol(-1);

	if (es_abb(arb).es)
		std::cout << "SI" << std::endl;

	else
		std::cout << "NO" << std::endl;

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