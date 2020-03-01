#ifndef E01_H
#define E01_H

#include <iostream>
#include <iomanip>

using namespace std;

class Hora {
private:
	int horas, minutos, segundos;

public:
	Hora() {};
	Hora(int h, int m, int s): horas(h), minutos(m), segundos(s){
		if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
			throw std::invalid_argument("ERROR");
		}
	};

	bool operator<(Hora const& other) const {
		return 3600 * horas + 60 * minutos + segundos <=
			3600 * other.horas + 60 * other.minutos + other.segundos;
	}
	int getH() const { return horas; };
	int getM() const { return minutos; };
	int getS() const { return segundos; };

protected: 
};

inline std::ostream & operator<< (std::ostream & out, Hora const & h) {
	out << setfill('0') << setw(2) << h.getH() << ':' << setfill('0') << setw(2) << h.getM() << ':' << setfill('0') << setw(2) << h.getS();
	return out;
}

#endif
