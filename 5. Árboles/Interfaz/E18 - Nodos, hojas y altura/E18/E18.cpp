#include "bintree_eda.h"

#include <fstream>
#include <iostream>



/*CUENTA EL NUMERO DE NODOS QUE TIENE EL ÁRBOL*/
void nodos(bintree<char> const &arbol, int &n) {
	//Cuando lleguemos al nodo nulo volvemos sin sumar nodo
	if (arbol.empty()) {
		return;
	}
	else {
		//Sumamos uno al numero de nodos puesto que no hemos llegado al nodo nulo
		n++;

		//Comprobamos el arbol por la izquierda
		nodos(arbol.left(), n);

		//Comprobamos el arbol por la derecha
		nodos(arbol.right(), n);
	}
}

void hojas(bintree<char> const &arbol, int &h) {
	if (arbol.empty()) {
		return;
	}
	else {
		if (arbol.left().empty() && arbol.right().empty()) {
			h++;
			return;
		}
		
		hojas(arbol.right(), h);
		hojas(arbol.left(), h);
	}
}


/*VEMOS LA ALTURA MÁXIMA, DEVOLVIENDO ESTE VALOR MÁXIMO*/
int altura(bintree<char> const &arbol) {
	if (arbol.empty()) {
		return 0;
	}
	else {
		//Devolvemos el que sea la altura máxima por cualquiera de los dos lados, sumando uno puesto que hay que contar la altura actual
		return std::max(altura(arbol.left()) + 1, altura(arbol.right()) + 1);
	}
}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	auto arb = leerArbol('.');
	
	//Contamos el numero de nodos con la función "nodos", tendremos el valor en la variable 'n'
	int n = 0;
	nodos(arb, n);

	//Contamos el número de hojas que tiene el árbol con la función "hojas", guardamos en la variable 'h'
	int h = 0;
	hojas(arb, h);

	//Vemos la altura del árbol, igualamos a la función "altura" ya que nos devolverá esta
	int a = altura(arb);

	std::cout << n << " " << h << " " << a << std::endl;

	casos--;
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