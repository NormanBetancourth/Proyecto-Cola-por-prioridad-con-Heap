/*
Estructuras de Datos EIF 207- Grupo 3
Proyecto I. Implementación TDA Cola de Prioridad
Integrantes:
    Norman Betancourtt Mairena
    Héctor Méndez Fernández
    Rebeca Servellón Orellana
*/

#include "ColaPrioridad.h"
#include"Paciente.h"
#include<iostream>

void clearScreen() {
    std::cout<< "\nPresione ENTER para continuar";
    std::cin.ignore(1, '\n');
    std::cin.get();
    std::cout << std::string(50, '\n.');

}

int main() {
    ColaPrioridad<Paciente>* colaPrioridadPacientes = nullptr;
    Paciente* paciente = nullptr;
    int opcion = 0;
    int cedula = 0;
    int estadoDeGravedad = 0;
    std::string nombrePaciente;
    bool esMaximo = true;

    std::cout << "PROGRAMA PARA ATENDER COLA DE PACIENTES SEGUN SU ESTADO DE GRAVEDAD\n\n";
    std::cout << "Para iniciar, se tiene que elegir el orden de prioridad de la cola respectiva\n\n";
    std::cout << "[1] Prioridad maxima: 10 [Mayor Prioridad] - 1 [Menor Prioridad]\n";
    std::cout << "[2] Prioridad minima: 1 [Mayor Prioridad] - 10 [Prioridad Minima]\n\n";
    std::cout << "Ingrese la opcion: ";
    std::cin >> esMaximo;

    esMaximo ?  colaPrioridadPacientes = new ColaPrioridad<Paciente>(nullptr, esMaximo) :
        colaPrioridadPacientes = new ColaPrioridad<Paciente>(nullptr, 0);

  
    while (opcion != 4) {

        clearScreen();

        std::cout << "\nMENU";
        std::cout << "\n\n[1] Ingresar paciente";
        std::cout << "\n[2] Atender paciente con mayor gravedad en la cola";
        std::cout << "\n[3] Consultar informacion del paciente con mayor gravedad en la cola";
        std::cout << "\n[4] Salir\n\n";
        std::cout << "Ingrese la opcion: ";
        std::cin >> opcion;

        clearScreen();

        switch (opcion) {
        case 1:
        {
            std::cout << "\n[1] Ingresar paciente";
            std::cout << "\n\n";
            std::cout << "Ingrese el nombre: ";
            std::cin.ignore();
            std::getline(std::cin, nombrePaciente);
            std::cout << "Ingrese la identificacion: ";
            std::cin >> cedula;
            std::cout << "Ingrese el estado de gravedad [1 (menor gravedad) - 10 (gravedad maxima)]: ";
            std::cin >> estadoDeGravedad;
            colaPrioridadPacientes->add(new Paciente(nombrePaciente, cedula, estadoDeGravedad));
        }
        break;
        case 2:
        {
            try {
                std::cout << "\n[2] Atender paciente con mayor gravedad en la cola";
                std::cout << "\n\n";
                paciente = colaPrioridadPacientes->pop();
                std::cout << "Informacion del paciente\n";
                std::cout << *paciente;
                delete paciente;
                paciente = nullptr;
            }
            catch (std::string& exception) {
                std::cout << exception;
            }
        }
        break;
        case 3:
        {
            try {
                std::cout << "\n[3] Consultar informacion del paciente con mayor gravedad en la cola";
                std::cout << "\n\n";
                paciente = colaPrioridadPacientes->front();
                std::cout << "\tInformacion del paciente\n";

                std::cout << *paciente;
            }
            catch (std::string& exception) {
                std::cout << exception;
            }

        }
        break;
        case 4:
        {
            std::cout << "\nGracias por usar nuestros sistemas :)\n";
            std::cin.get();
        }
        break;
        default:
        {
            std::cout << "\nLa opcion ingresada no se encuentra disponible";
            break;
        }
        clearScreen();
        }
    }

    delete colaPrioridadPacientes;

	return 0;
}







