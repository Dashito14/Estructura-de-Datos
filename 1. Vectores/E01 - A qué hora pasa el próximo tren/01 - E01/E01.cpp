#include "E01.h"

#include <string>

const int MAX = 1000;
Hora v[MAX];

void leerDatos() {
	int nTrenes, nHoras;
	int h, m, s;
	char c;

	bool encontrado = false;
	int j = 0;

	cin >> nTrenes >> nHoras;

	
	while (nTrenes != 0 && nHoras != 0) {
		for (int i = 0; i < nTrenes; i++) {
			cin >> h >> c >> m >> c >> s;
			Hora hrs(h, m, s);
			v[i] = hrs;
		}
		for (int i = 0; i < nHoras; i++) {
			try {
				cin >> h >> c >> m >> c >> s;
				Hora hActual(h, m, s);

				while (!encontrado && j < nTrenes) {
					if (hActual.operator<(v[j])) {
						cout << v[j] << endl;
						encontrado = true;
					}
					j++;
				}

				if (!encontrado) {
					cout << "NO" << endl;
				}
				encontrado = false;
				j = 0;
			}
			catch (std::invalid_argument & ia) {
				std:cout << ia.what() << endl;
			}
		}
		cout << "---" << endl;
		cin >> nTrenes >> nHoras;
	}
}



int main() {

	leerDatos();

	return 0;
}
