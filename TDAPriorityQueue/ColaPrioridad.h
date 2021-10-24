#ifndef TDAPRIORITYQUEUE_COLAPRIORIDAD_H
#define TDAPRIORITYQUEUE_COLAPRIORIDAD_H
#include "ListaDoble.h"

//Clase cola prioridad, implementa los metodos correspondientes para una cola prioridad
template<class T>
class ColaPrioridad
{
private:
	ListaDoble<T>* heap;
	
public:
	typedef Nodo<T>* valor;
	typedef ListaDoble<T>* Heap;
	
	ColaPrioridad( Heap li = nullptr, bool isMax = true );
	ColaPrioridad( ColaPrioridad<T>*& colaCopiable);
	~ColaPrioridad();
	Heap getHeap();

	bool empty();
	void add(T* value);
	T* pop();
	T* front() const;
	int size() const;

};

template<class T>
inline ColaPrioridad<T>::ColaPrioridad( Heap li, bool isMax )
{
	this->heap = li;
	if (!heap)
	{
		heap = new ListaDoble<T>(isMax);
	}
}

//constructor de clase
template<class T>
inline ColaPrioridad<T>::ColaPrioridad(ColaPrioridad<T>*& colaCopiable)
{
	this->heap = new ListaDoble<T>(*(colaCopiable->getHeap()));
}


//destructor de clase
template<class T>
inline ColaPrioridad<T>::~ColaPrioridad()
{
	delete heap;
}

//retorna el heap
template<class T>
inline ListaDoble<T>* ColaPrioridad<T>::getHeap()
{
	return heap;
}


//verifica si esta vacia la cola
template<class T>
inline bool ColaPrioridad<T>::empty()
{
	return heap->getCuentaNodos() == 0;
}


agrega elementos a la cola
template<class T>
inline void ColaPrioridad<T>::add(T* value)
{
	heap->insertar(value);
}

//elimina y reotrna el primer elemento de la cola en un tiempo de (O(1))
template<class T>
inline T* ColaPrioridad<T>::pop()
{
	if (heap->getPrimero()) {
		return heap->eliminar();
	}
	else {
		throw std::string("\nLa cola esta vacia\n");
	}
	return nullptr;
}


//obtiene el primer elemento de la lista O(1)
template<class T>
inline T* ColaPrioridad<T>::front() const
{
	if (heap->getPrimero())
	{
		return heap->getPrimero()->dato;
	}
	else {
		throw std::string("\nLa cola esta vacia\n");
	}
	return nullptr;
}


//me cuenta la cantidad de nodos que contiene el arbol
template<class T>
inline int ColaPrioridad<T>::size() const
{
	return heap->getCuentaNodos();
}

#endif 



