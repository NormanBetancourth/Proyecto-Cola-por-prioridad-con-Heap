#include<iostream>
#include"ListaDoble.h"
#include"IteradorListaDoble.h"







int main() {
    ListaDoble<int>* listaEnteros = new ListaDoble<int>;

    listaEnteros->insertar(new int(8));
    listaEnteros->insertar(new int(0));
    listaEnteros->insertar(new int(2));
    listaEnteros->insertar(new int(11));
    listaEnteros->insertar(new int(1));
    listaEnteros->insertar(new int(3));
    listaEnteros->insertar(new int(10));
    listaEnteros->insertar(new int(4));
    listaEnteros->insertar(new int(5));

    listaEnteros->insertar(new int(6));
    listaEnteros->insertar(new int(7));

    listaEnteros->insertar(new int(9));

    listaEnteros->insertar(new int(13));

    listaEnteros->insertar(new int(12));

    listaEnteros->insertar(new int(14));

    IteradorListaDoble<int>* itEnt = listaEnteros->crearInterador();
    for (itEnt->begin(); !itEnt->isEnd(); itEnt->next()) {
        std::cout << *itEnt->currentItem()->getDato() << "\n";
    }


    delete listaEnteros;
	return 0;
}
