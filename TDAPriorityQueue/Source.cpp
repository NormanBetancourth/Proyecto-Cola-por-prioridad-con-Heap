#include<iostream>
#include"ListaDoble.h"
#include"IteradorListaDoble.h"







int main() {
    ListaDoble<int>* listaEnteros = new ListaDoble<int>;

    listaEnteros->insertar(new int(5));
    listaEnteros->insertar(new int(9));
    listaEnteros->insertar(new int(3));
    listaEnteros->insertar(new int(8));
    listaEnteros->insertar(new int(6));
    listaEnteros->insertar(new int(1));

    IteradorListaDoble<int>* itEnt = listaEnteros->crearInterador();
    for (itEnt->begin(); !itEnt->isEnd(); itEnt->next()) {
        std::cout << *itEnt->currentItem()->getDato() << "\n";
    }


    delete listaEnteros;
	return 0;
}