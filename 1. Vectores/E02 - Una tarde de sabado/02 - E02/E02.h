#ifndef E02_H
#define E02_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Hora {
private:
	int horas, minutos, segundos;

public:
	Hora() {};
	Hora(int h, int m, int s) : horas(h), minutos(m), segundos(s) {
		if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
			throw std::invalid_argument("ERROR");
		}
	};

	bool operator<(Hora const& other) const {
		return 3600 * horas + 60 * minutos + segundos <=
			3600 * other.horas + 60 * other.minutos + other.segundos;
	}

	Hora operator+(Hora const& other) const {
		int sumaH = horas + other.horas;
		int sumaM = minutos + other.minutos;
		int sumaS = segundos + other.segundos;

		if (sumaS > 59) {
			sumaM++;
			sumaS -= 60;
		}

		if (sumaM > 59) {
			sumaH++;
			sumaM -= 60;
		}

		Hora hr(sumaH, sumaM, sumaS);
		return hr;
	}

	bool operator== (Hora const& other) const {
		return (horas * 3600 + minutos * 60 + segundos == other.horas * 3600 + other.minutos * 60 + other.segundos);
	}

	int getH() const { return horas; };
	int getM() const { return minutos; };
	int getS() const { return segundos; };

protected:
};

class Pelicula {
private:
	Hora hComienzo;
	Hora duracion;
	Hora fin;
	string titulo;

public:
	Pelicula() {};
	Pelicula(Hora hc, Hora d, string t) : hComienzo(hc), duracion(d), titulo(t) {};
	Pelicula(Hora f, string t) : fin(f), titulo(t) {};

	Hora getHC() const { return hComienzo; };
	Hora getD() const { return duracion; };
	string getTitulo() const { return titulo; };
	Hora getFin() const { return fin; };

	bool operator< (Pelicula const& other) {
		bool ret = false;
		if (fin.getH() < other.getFin().getH()) {
			ret = true;
		}
		else if (fin.getH() == other.getFin().getH()) {
			if (fin.getM() < other.getFin().getM()) {
				ret = true;
			}
			else if (fin.getM() == other.getFin().getM()) {
				if (fin.getS() < other.getFin().getS()) {
					ret = true;
				}
				else if (fin.getS() < other.getFin().getS()){
					if (titulo < other.getTitulo()) {
						ret = true;
					}
				}
			}
		}

		return ret;
	}



protected:
};

void inserta(Pelicula p, vector<Pelicula>& v){

	int i = v.size();

	while (i > 0 && p < v[i - 1]){
		if (i == v.size()){
			v.push_back(v[i - 1]);
		}
		else {
			v[i] = v[i - 1];
		}
		i--;
	}

	
		while (i > 0 && p.getFin() == v[i - 1].getFin() && p.getTitulo() < v[i - 1].getTitulo()){
			if (i == v.size()){
				v.push_back(v[i-1]);
			}
			else {
				v[i] = v[i - 1];
			}
			i--;
		}
		if (i == v.size()){
			v.push_back(p);
		}
		else {
			v[i] = p;
		}
	

};

inline std::ostream & operator<< (std::ostream & out, Hora const & h) {
	out << setfill('0') << setw(2) << h.getH() << ':' << setfill('0') << setw(2) << h.getM() << ':' << setfill('0') << setw(2) << h.getS();
	return out;
}

inline std::ostream & operator<< (std::ostream & out, Pelicula const & p) {
	out << p.getFin() << " " << p.getTitulo();
	return out;
}

#endif