#ifndef TDAPRIORITYQUEUE_PACIENTE_H
#define TDAPRIORITYQUEUE_PACIENTE_H
#include<string>
#include<sstream>
#include<ostream>

class Paciente {
private:
	std::string nombre;
	int cedula;
	int estadoDeGravedad;
public:
	Paciente(std::string, int, int);
	~Paciente();

	void setNombre(std::string);
	void setCedula(int);
	void setEstadoDeGravedad(int);
	std::string getNombre()const;
	int getCedula()const;
	int getEstadoDeGravedad() const;
	std::string toString() const;
	bool operator<(const Paciente&);
	bool operator>(const Paciente&);
	friend std::ostream& operator<<(std::ostream&, const Paciente&);
};

#endif 
