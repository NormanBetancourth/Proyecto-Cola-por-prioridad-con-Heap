#include<iostream>
#include"ListaDoble.h"
#include"IteradorListaDoble.h"

int main() {
    ListaDoble<int>* listaEnteros = new ListaDoble<int>;
    listaEnteros->agregarAlInicio(new int(20));
    listaEnteros->agregarAlInicio(new int(30));
    listaEnteros->agregarAlInicio(new int(40));

    IteradorListaDoble<int>* itEnt = listaEnteros->crearInterador();
    for (itEnt->begin(); !itEnt->isEnd(); itEnt->next()) {
        std::cout << *itEnt->currentItem()->getDato() << "\n";
    }

    delete listaEnteros;

	return 0;
}