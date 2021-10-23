#include "ColaPrioridad.h"
template<class T>
inline ColaPrioridad<T>::ColaPrioridad(bool isMax, ListaDoble<T>* li)
{
	Heap = new ListaDoble<T>(isMax);
	if (li)
	{
		
	}
	
	
	
}

template<class T>
ColaPrioridad<T>::ColaPrioridad(const ColaPrioridad<T>& colaCopiable)
{
}

template<class T>
ColaPrioridad<T>::~ColaPrioridad()
{
}

template<class T>
bool ColaPrioridad<T>::empty()
{
	return false;
}

template<class T>
void ColaPrioridad<T>::add(T* value)
{
}

template<class T>
T* ColaPrioridad<T>::pop()
{
	return nullptr;
}

template<class T>
T* ColaPrioridad<T>::front()
{
	return nullptr;
}

template<class T>
int ColaPrioridad<T>::size()
{
	return 0;
}
