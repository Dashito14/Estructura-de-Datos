#ifndef E07_H
#define E07_H

#include <iostream>
#include <fstream>
#include <iomanip>

//Clase Fecha para la fecha de los accidentes
class Fecha{
private:
	int dia, mes, anyo;
public:
	Fecha(){};
	Fecha(int d, int m, int a) : dia(d), mes(m), anyo(a){};

	int getD() const { return dia; };
	int getM() const { return mes; };
	int getA() const { return anyo; };
};
class Accidentes{
private:
	Fecha fecha, anterior;
	int victimas;

public:
	Accidentes(){};
	Accidentes(Fecha f, int v) : fecha(f), victimas(v){};
	Accidentes(Fecha f, int v, Fecha a) : fecha(f), victimas(v), anterior(a){};

	int getV() const { return victimas; };
	Fecha getF() const { return fecha; };
	
};

inline std::ostream & operator<< (std::ostream & out, Fecha const & h) {
	out << std::setfill('0') << std::setw(2) << h.getD() << '/' << std::setfill('0') << std::setw(2) << h.getM() << '/' << std::setfill('0') << std::setw(4) << h.getA();
	return out;
}
#endif