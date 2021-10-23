#ifndef TDAPRIORITYQUEUE_NODO_H
#define TDAPRIORITYQUEUE_NODO_H

template<class T>
class Nodo {   //a //e
public:
	T* dato;
	Nodo* next;
	Nodo* prev;
public:
	Nodo();
	Nodo(T*);
	~Nodo();
	T* getDato()const;
	void setDato(T*);
	Nodo* getNext()const;
	void setNext(Nodo*);
	Nodo* getPrev()const;
	void setPrev(Nodo*);
};

template<class T>
inline Nodo<T>::Nodo() :dato(nullptr), next(nullptr), prev(nullptr) {}

template<class T>
inline Nodo<T>::Nodo(T* dato) : dato(dato), next(nullptr), prev(nullptr) {}

template<class T>
inline Nodo<T>::~Nodo() {
	if (dato)
	{
		delete dato;
	}
}

template<class T>
inline T* Nodo<T>::getDato() const {
	return dato;
}

template<class T>
inline void Nodo<T>::setDato(T* dato) {
	this->dato = dato;
}

template<class T>
inline Nodo<T>* Nodo<T>::getNext() const {
	return next;
}

template<class T>
inline void Nodo<T>::setNext(Nodo* next) {
	this->next = next;
}

template<class T>
inline Nodo<T>* Nodo<T>::getPrev() const {
	return prev;
}

template<class T>
inline void Nodo<T>::setPrev(Nodo* prev) {
	this->prev = prev;
}

#endif
