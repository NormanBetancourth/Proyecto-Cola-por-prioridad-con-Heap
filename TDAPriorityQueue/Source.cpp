/*
Estructuras de Datos EIF 207- Grupo 3
Proyecto I. Implementación TDA Cola de Prioridad

Integrantes:
    Norman Betancourtt Mairena
    Héctor Méndez Fernández
    Rebeca Servellón Orellana

Planteamiento del problema que resuelve el proyecto
Este es un programa que se usa en una UCI, por la pandemia los centros
médicos han estado en alta demanda, es por esto que la UCI va a usar 
un programa que organice por prioridad con respecto al estado del 
paciente, la valoración es trabajo del médico a cargo, pero las 
prioridades están a manos de nuestro programa, a mayor sea el nivel 
de un paciente, más crítico este se encuentra.

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
            std::getline(std::cin, nombrePaciente);
            std::cout << "Ingrese la identificacion: ";
            std::cin >> cedula;
            std::cout << "Ingrese el estado de gravedad [1 - 10]: ";
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

/*Referencias

Heap Data Structures. (s. f.). Tutorialspoint. Recuperado 19 de octubre de 2021,
de https://www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm

CS241: Data Structures & Algorithms II. (s. f.). edu. Recuperado 20 de octubre de 2021,
de https://www.cpp.edu/%7Eftang/courses/CS241/notes/heap.htm

std::priority_queue - cppreference.com. (s. f.). Cppreference. Recuperado 19 de octubre
de 2021, de https://en.cppreference.com/w/cpp/container/priority_queue

Priority Queue Data Structure In C++ With Illustration. (2021, 27 septiembre). Software
Testing Help. Recuperado 18 de octubre de 2021, de https://www.softwaretestinghelp.com/priority-queue-in-cpp/
*/








