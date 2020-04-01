#include "bintree_eda.h"

#include <fstream>


bool simetrico(bintree<char> a, bintree<char> b) {
	//Si ambos árboles están vacíos es simétrico porque son iguales
	if (a.empty() && b.empty())
		return true;

	//Si solo uno de los lados está vacío no es simétrico, por tanto se devuelve falso
	if (a.empty() || b.empty())
		return false;

	//Si uno de los dos lados no es simétrico ya se devuelve falso porque no será simétrico nunca
	return (simetrico(a.left(), b.right()) && simetrico(a.right(), b.left()));

}

bool resuelveCaso(int &casos) {
	if (casos == 0)
		return false;

	casos--;

	auto arb = leerArbol('.');

	if (simetrico(arb.left(), arb.right()))
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