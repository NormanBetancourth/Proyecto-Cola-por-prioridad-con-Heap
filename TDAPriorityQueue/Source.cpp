#include<iostream>
#include"ListaDoble.h"
#include"IteradorListaDoble.h"







int main() {
    ListaDoble<int> listaEnteros(true);

    listaEnteros.insertar(new int(1));
   
    listaEnteros.insertar(new int(3));
    listaEnteros.insertar(new int(6));
    
    listaEnteros.insertar(new int(5));
    listaEnteros.insertar(new int(9));
    listaEnteros.insertar(new int(8));

  

   /* int* valor = listaEnteros->eliminar();
    std::cout << "Valor: " << *valor << std::endl;
    int* valor2 = listaEnteros->eliminar();
    std::cout << "Valor: " << *valor2 << std::endl;*/
    
    

   


    

    //std::cout<<listaEnteros->toString();
 
    ListaDoble<int> listacopia(listaEnteros);
    
    

    std::cout << listacopia.toString();


  


    
	return 0;
}







