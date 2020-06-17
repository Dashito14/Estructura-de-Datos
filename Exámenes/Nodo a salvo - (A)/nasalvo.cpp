#include "bintree_eda.h"

#include <fstream>

/*En el enunciado pone que hay que devolver int de la función pero nos aclararon que no hacía falta*/
/*De todas formas es sencillo cambiar este código para que el valor t del struct pase a devolverse por función*/

typedef struct tSol {
	int c; //Numero de caballeros
	int t; //Numero total de nodos a salvo
};

tSol nodosSalvo(bintree<char>const &arb, int m) {
	//Si el árbol está vacío hay 0 nodos a salvo de momento y 0 caballeros
	if (arb.empty())
		return { 0, 0 };

	//Si el nodo por el que estamos bajando es un monstruo sumamos 1 al numero de monstruos que llevamos
	if (arb.root() == 'M')
		m += 1;

	//Recorremos los nodos de los dos lados
	tSol iz = nodosSalvo(arb.left(), m);
	tSol dcha = nodosSalvo(arb.right(), m);

	//Si es un caballero devolvemos la suma de los caballeros de los dos lados y el caballero actual, el total es la suma de los dos lados
	if (arb.root() == 'C')
		return{ iz.c + dcha.c + 1, iz.t + dcha.t };

	//Si es una dama y hay más caballeros que monstruos devolvemos uno más en el total
	if (arb.root() == 'D') {
		if (iz.c + dcha.c >= m)
			return { iz.c + dcha.c, iz.t + dcha.t + 1 };
	}

	//Si no se cumple nada de lo anterior solo devolvemos la suma de los dos lados
	return { iz.c + dcha.c, iz.t + dcha.t };

}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	int i = 0;

	//La o mayúscula es lo que indica el vacío, es tipo char
	auto arb = leerArbol('O');

	std::cout << nodosSalvo(arb, i).t << std::endl;

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