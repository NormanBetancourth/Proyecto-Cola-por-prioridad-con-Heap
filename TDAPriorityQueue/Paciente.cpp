#include"Paciente.h"

Paciente::Paciente(std::string nombre, int cedula, int estadoDeGravedad):
nombre(nombre),cedula(cedula),estadoDeGravedad(estadoDeGravedad){}

Paciente::~Paciente(){}

void Paciente::setNombre(std::string nombre){
	this->nombre = nombre;
}

void Paciente::setCedula(int cedula) {
	this->cedula = cedula;
}

void Paciente::setEstadoDeGravedad(int estadoDeGravedad){
	this->estadoDeGravedad = estadoDeGravedad;
}

std::string Paciente::getNombre() const{
	return nombre;
}

int Paciente::getCedula() const{
	return cedula;
}

int Paciente::getEstadoDeGravedad() const{
	return estadoDeGravedad;
}

std::string Paciente::toString() const{
	std::stringstream ss{};
	ss << "\n\tNombre: " << getNombre();
	ss << "\n\tCedula: " << getCedula();
	ss << "\n\tEstado de gravedad: " << getEstadoDeGravedad();
	ss << "\n";
	return ss.str();
}

bool Paciente::operator<(const Paciente& paciente){
	return this->getEstadoDeGravedad() < paciente.getEstadoDeGravedad();
}

bool Paciente::operator>(const Paciente& paciente){
	return this->getEstadoDeGravedad() > paciente.getEstadoDeGravedad();
}

std::ostream& operator<<(std::ostream& os, const Paciente& paciente){
	os << paciente.toString();
	return os;
}
