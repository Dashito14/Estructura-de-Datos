#include "bintree_eda.h"

#include <fstream>

struct tSol {
	//Número de tramos navegables hasta el momento
	int tramos;
	//Caudal actual
	int actual;
};

tSol aguaslimpias(bintree<int> arbol) {
	//Si el árbol está vacío no devuelve ningún caudal
	if (arbol.empty())
		return { 0, 0 };

	//Si es un nodo hoja devolvemos 1 de caudal y 0 tramos actuales
	if (arbol.right().empty() && arbol.left().empty())
		return{ 0, 1 };

	//Miramos los dos nodos hijos
	tSol izq = aguaslimpias(arbol.left());
	tSol dcha = aguaslimpias(arbol.right());

	//Calculamos el caudal actual
	int vActual = izq.actual + dcha.actual - arbol.root();

	//Si el caudal fuera menor que 1 lo tenemos que convertir en 0, puesto que no hay caudales menores de 0
	if (vActual < 0)
		vActual = 0;

	//Si el caudal es menor que el pedido por el enunciado para que sea navegable se devuelve sin sumar
	//ningún tramo nuevo
	if(vActual < 3)
		return {izq.tramos + dcha.tramos , vActual };

	//Si hay que sumar tramo nuevo se hace aquí
	return { izq.tramos + dcha.tramos + 1, vActual };
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol(-1);

	tSol sol = aguaslimpias(arb);

	//Con la solución que he dado cuenta también si hubiera un tramo final en vez de parar en el último nodo
	//por si acaso se ha sumado un tramo más con este if lo descontamos
	if (sol.actual < 3) {
		std::cout << sol.tramos << std::endl;
	}
	else {
		std::cout << sol.tramos - 1 << std::endl;
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