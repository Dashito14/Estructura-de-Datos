#include "bintree_eda.h"

#include <fstream>

struct tSol {
	//Si es accesible el nodo
	bool acc;
	//Altura a la que se encuentra
	int altura;
	//Valor del nodo 
	int v;
};

bool esPrimo(int n) {
	int i = 1;
	int d = 0;

	while (i <= n) {
		if (n%i == 0) {
			d++;
		}
		i++;
	}

	if (d == 2)
		return true;

	return false;
}

tSol barrera(bintree<int> a, int altura) {
	//Si el árbol está vacío devolvemos que no es accesible y valores nulos (0)
	if (a.empty())
		return{ false, 0, 0 };

	//Si el valor del árbol es primo convierte todo lo que hubiera antes en no accesible
	if (esPrimo(a.root()))
		return { false, 0, 0};

	//Si el valor de la raíz es divisible entre 7 es un valor válido y no hace falta que sigamos mirando más hacia abajo
	if (a.root() % 7 == 0)
		return{ true, altura, a.root() };

	//Vemos el árbol por las dos ramas
	tSol izq = barrera(a.left(), altura + 1);
	tSol dcha = barrera(a.right(), altura + 1);

	//Si el árbol de la izquierda es no accesible devolvemos el valor que traíamos del de la derecha
	if (!izq.acc)
		return dcha;

	//Si el de la derecha no es accesible devolvemos el valor del de la izquierda
	if (!dcha.acc)
		return izq;

	//Si ambos son accesibles y el de la derecha está más cerca de la raíz devolvemos el de la dercha
	if (dcha.altura < izq.altura)
		return dcha;

	//En este caso ambos son accesibles y el de la izquierda está a la misma altura o más cerca de la raíz que el de la derecha
	return izq;
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol(-1);

	//Pasamos a parte del árbol, la altura por la que vamos
	tSol sol = barrera(arb, 1);

	if (!sol.acc)
		std::cout << "NO HAY" << std::endl;

	else {
		std::cout << sol.v << " " << sol.altura << std::endl;
	}

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