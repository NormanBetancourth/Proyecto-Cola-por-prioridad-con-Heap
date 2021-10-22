#include<iostream>
#include"ListaDoble.h"
#include"IteradorListaDoble.h"







int main() {
    ListaDoble<int>* listaEnteros = new ListaDoble<int>;

    listaEnteros->insertar(new int(1));
   
    listaEnteros->insertar(new int(3));
    listaEnteros->insertar(new int(6));
    
    listaEnteros->insertar(new int(5));
    listaEnteros->insertar(new int(9));
    listaEnteros->insertar(new int(8));

  

    int* valor = listaEnteros->eliminar();
    std::cout << "Valor: " << *valor << std::endl;
    int* valor2 = listaEnteros->eliminar();
    std::cout << "Valor: " << *valor2 << std::endl;
    

    IteradorListaDoble<int>* itEnt = listaEnteros->crearInterador();
    for (itEnt->begin(); !itEnt->isEnd(); itEnt->next()) {
        std::cout << *itEnt->currentItem()->getDato() << "\n";
    }

    

    //std::cout<<listaEnteros->toString();
 
  


    delete listaEnteros;
	return 0;
}
