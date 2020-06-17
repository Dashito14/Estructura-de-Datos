#include "bintree_eda.h"

#include <fstream>


typedef struct tSol {
	int pares; //Número de pares que hay por debajo
	int suma; //Total de nodos adivinos
};

tSol adivino(bintree<int>const &arb) {
	//Si el árbol está vacío devolvemos 0 numeros pares y 0 de suma total de momento
	if (arb.empty())
		return{ 0, 0 };

	//Recorremos los dos nodos hijos
	tSol iz = adivino(arb.left());
	tSol dcha = adivino(arb.right());

	//Inicializamos dos variables a la suma de los pares y la suma total de momento
	int pares = iz.pares + dcha.pares;
	int total = iz.suma + dcha.suma;

	//Si el nodo actual es par sumamos 1 a los pares
	if (arb.root() % 2 == 0)
		pares += 1;

	//Si la suma de pares es igual al número raíz significa que es un nodo adivino
	if (iz.pares + dcha.pares == arb.root())
		total += 1;

	//Devolvemos las dos variables creadas
	return { pares, total };
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol(-1);

	std::cout << adivino(arb).suma << std::endl;

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