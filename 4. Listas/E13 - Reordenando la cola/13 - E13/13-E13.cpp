#include "list_eda.h"

#include <iostream>
#include <fstream>

/*HAY QUE HACER BUSQUEDA BINARIA PA SABER DONDE METERLA SUBNORMAL*/

void print(list<int> l){
	auto it = l.begin();

	while (it != l.end()){
		std::cout << *it << " ";
		++it;
	}

	std::cout << std::endl;
	/*std::cout << *it << "/n";*/
}


bool resuelveCaso(){
	int nelem, i = 0, v;
	list<int> l;

	std::cin >> nelem;

	if (nelem == 0)
		return false;

	while (i < nelem){
		std::cin >> v;
		if (v <= 0){
			l.push_front(v);
		}
		else {
			l.push_back(v);
		}
		i++;
	}

	print(l);

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