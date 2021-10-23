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
	
	ColaPrioridad(bool isMax =true, Heap li = nullptr);
	ColaPrioridad(const ColaPrioridad<T>& colaCopiable);
	~ColaPrioridad();
	Heap getHeap();

	bool empty();
	void add(T* value);
	T* pop();
	T* front() const;
	int size();

};

template<class T>
inline ColaPrioridad<T>::ColaPrioridad(bool isMax, Heap li)
{
	this->heap = li;
	if (!heap)
	{
		heap = new ListaDoble<T>(isMax);
	}
}

template<class T>
inline ColaPrioridad<T>::ColaPrioridad(const ColaPrioridad<T>& colaCopiable)
{
	this->heap = new ListaDoble<T>(*(colaCopiable.getHeap()));
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
	if (heap->getCuentaNodos() > 0)
	{
		return nullptr;
	}
	else
	{
		if (heap->getPrimero() != heap->getInicio())
		{
			return heap->getPrimero()->dato;
		}
		else {
			return nullptr;
		}
	}
}

template<class T>
inline int ColaPrioridad<T>::size()
{
	return heap->getCuentaNodos();
}




