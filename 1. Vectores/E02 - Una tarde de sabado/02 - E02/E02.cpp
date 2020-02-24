#include "E02.h"

void solucion() {
	int pelis;
	char c;
	int h1, m1, s1;
	int h2, m2, s2;
	string titulo;
	vector <Pelicula> v;

	cin >> pelis;
	while (pelis != 0) {
		try {
			for (int i = 0; i < pelis; i++) {
				cin >> h1 >> c >> m1 >> c >> s1;
				cin >> h2 >> c >> m2 >> c >> s2;
				getline(cin, titulo);
				Hora hComienzo(h1, m1, s1);
				Hora duracion(h2, m2, s2);
				Pelicula p(hComienzo, duracion, titulo);

				Hora sum = p.getHC() + p.getD();
				Pelicula pS(sum, p.getTitulo());

				
				inserta(pS, v);
				
				
			}
			/*
			for (int j = 0; j < pelis; j++) {
				for (int i = 0; i < pelis - 1; i++) {
					if (!(v[i] < v[i + 1])) {
						Pelicula aux(v[i + 1].getFin(), v[i + 1].getTitulo());
						v[i + 1] = v[i];
						v[i] = aux;
					}
				}
			}*/

			for (int i = 0; i < pelis; i++) {
				cout << v[i] << endl;
			}

		}
		catch (std::invalid_argument & ia) {
		std:cout << ia.what() << endl;
		}

		cout << "---" << endl;
		v.clear();
		cin >> pelis;
	}
}

int main() {
	solucion();
	//system("PAUSE");
	return 0;
}