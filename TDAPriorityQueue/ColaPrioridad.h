#pragma once
#include "ListaDoble.h"
template<class T>
class ColaPrioridad
{
private:
	ListaDoble<T>* Heap;
	typedef Nodo<T>* valor;

	
public:
	ColaPrioridad(bool isMax =true, ListaDoble<T>* li = nullptr);
	ColaPrioridad(const ColaPrioridad<T>& colaCopiable);
	~ColaPrioridad();

	

	bool empty();
	void add(T* value);
	T* pop();
	T* front();
	int size();



	
	


};


