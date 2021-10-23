#include<iostream>
#include"ListaDoble.h"
#include "ColaPrioridad.h"
#include"IteradorListaDoble.h"







int main() {
    ListaDoble<int>* listaEnteros = new ListaDoble<int>(true);

    listaEnteros->insertar(new int(1));
    listaEnteros->insertar(new int(3));
    listaEnteros->insertar(new int(6));
    listaEnteros->insertar(new int(5));
    listaEnteros->insertar(new int(9));
    listaEnteros->insertar(new int(8));

    
    

    ListaDoble<int>* listacopia = new ListaDoble<int>(*listaEnteros);
    delete listaEnteros;

    ColaPrioridad<int>* cola = new ColaPrioridad<int>(listacopia, true);
     ColaPrioridad<int>* nuevaCola = new ColaPrioridad<int>(cola);


     

    
     /*nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();
     nuevaCola->pop();*/

     if (nuevaCola->front() != nullptr)
     {
         std::cout << "\n " << *(nuevaCola->pop()) << std::endl;
     }


    

    
    

	return 0;
}







