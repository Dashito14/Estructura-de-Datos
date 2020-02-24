#include "E04.h"

bool resuelve() {
	Polinomio p;
	monomio m;
	int f, s;

	

	std::cin >> f;

	if (!std::cin){
		return false;
	}

	std::cin >> s;

	while (f != 0 || s != 0) {
		m.first = f;
		m.second = s;

		p.anadirMonomio(m);

		std::cin >> f;
		std::cin >> s;
	}

	int valores, x;
	std::cin >> valores;

	for (int i = 0; i < valores; i++) {
		std::cin >> x;
		std::cout << p.resolverPolinomio(x) << " ";
	}

	std::cout << std::endl;


	return true;
}

int main() {
	while (resuelve());
}