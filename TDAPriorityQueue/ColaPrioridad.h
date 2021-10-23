#pragma once
#include "ListaDoble.h"
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
	int size();

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

template<class T>
inline ColaPrioridad<T>::ColaPrioridad(ColaPrioridad<T>*& colaCopiable)
{
	this->heap = new ListaDoble<T>(*(colaCopiable->getHeap()));
}



template<class T>
inline ColaPrioridad<T>::~ColaPrioridad()
{
	delete heap;
}

template<class T>
inline ListaDoble<T>* ColaPrioridad<T>::getHeap()
{
	return heap;
}

template<class T>
inline bool ColaPrioridad<T>::empty()
{
	return heap->getCuentaNodos() == 0;
}

template<class T>
inline void ColaPrioridad<T>::add(T* value)
{
	heap->insertar(value);
}

template<class T>
inline T* ColaPrioridad<T>::pop()
{
	return heap->eliminar();
}

template<class T>
inline T* ColaPrioridad<T>::front() const
{
	if (heap->getPrimero())
	{
		return heap->getPrimero()->dato;
	}
	return nullptr;
}

template<class T>
inline int ColaPrioridad<T>::size()
{
	return heap->getCuentaNodos();
}




