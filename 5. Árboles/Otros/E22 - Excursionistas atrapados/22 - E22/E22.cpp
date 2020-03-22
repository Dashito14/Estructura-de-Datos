#include "bintree_eda.h"

#include <fstream>

struct tSol {
	//Si hay excursionistas en esa rama
	bool exc;
	//Numero de equipos necesarios para rescatar a todos
	int equipos;
	//Numero de personas en la rama m�s concurrida
	int personas;
};

tSol excursionistas(bintree<int> arbol) {
	if (arbol.empty())
		return{ false, 0, 0 };

	tSol dcha = excursionistas(arbol.right());
	tSol izq = excursionistas(arbol.left());

	//Si no hay excursionistas en el nodo actual
	if (arbol.root() == 0) {
		//Si hubiera excursionistas en nodos m�s abajo del actual
		if (dcha.exc || izq.exc)
			//Se devuelve que ya hay excursionistas, el numero de equipos necesarios para rescatar los grupos
			//atrapados en nodos m�s abajo y el�n�mero m�ximo de personas que llevamos por cada rama
			return { true, dcha.equipos + izq.equipos, std::max(dcha.personas,izq.personas) };

		//Si no hubiera excursionistas todav�a devolvemos todo anulado
		return { false, 0, 0 };
	}

	//Si tenemos alg�n excursionista ahora y ya hab�a excursionistas anteriormente
	if(dcha.exc || izq.exc)
		//Se devuelve que ya hay excursionistas, el n�mero de equipos que necesitabamos para rescatar los grupos anteriores
		//y el m�ximo de personas que llevamos por una rama contando los actuales
		return{ true, dcha.equipos + izq.equipos, std::max(dcha.personas + arbol.root(), izq.personas + arbol.root()) };

	//Igual que el anterior pero sumamos un equipo m�s para rescatar
	return{ true, 1, std::max(dcha.personas + arbol.root(), izq.personas + arbol.root()) };
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol(-1);

	tSol sol = excursionistas(arb);

	std::cout << sol.equipos << " " << sol.personas << std::endl;

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