#ifndef TDAPRIORITYQUEUE_LISTADOBLE_H
#define TDAPRIORITYQUEUE_LISTADOBLE_H

#include"Nodo.h"
#include<string>

template<class T>
class IteradorListaDoble;

template<class T>
class ListaDoble {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	int cuentaNodos;
public:
	ListaDoble();
	~ListaDoble();
	Nodo<T>* getInicio()const;
	Nodo<T>* getFin()const;
	Nodo<T>* getPrimero()const;
	void setInicio(Nodo<T>*);
	Nodo<T>* getUltimo();
	void setFin(Nodo<T>*);
	void agregarAlInicio(T*);
	void agregarAlFinal(T*);
	std::string toString();
	IteradorListaDoble<T>* crearInterador()const;
	void insertar(T*);
	void heapify(Nodo<T>*, int);
	void swap(Nodo<T>*, Nodo<T>*);
};

template<class T>
inline ListaDoble<T>::ListaDoble(){
	inicio = new Nodo<T>;
	fin = new Nodo<T>;
}

template<class T>
inline ListaDoble<T>::~ListaDoble(){
	Nodo<T>* temporal = inicio->getNext();
	while (temporal != nullptr) {
		inicio->setNext(temporal->getNext());
		delete temporal;
		temporal = inicio->getNext();
	}
}

template<class T>
inline Nodo<T>* ListaDoble<T>::getInicio() const{
	return inicio;
}

template<class T>
inline Nodo<T>* ListaDoble<T>::getFin() const{
	return fin;
}

template<class T>
inline Nodo<T>* ListaDoble<T>::getPrimero() const{
	return inicio->getNext();
}

template<class T>
inline void ListaDoble<T>::setInicio(Nodo<T>* inicio){
	this->inicio = inicio;
}

template<class T>
inline Nodo<T>* ListaDoble<T>::getUltimo(){
	return fin->getPrev();
}

template<class T>
inline void ListaDoble<T>::setFin(Nodo<T>* fin){
	this->fin = fin;
}

template<class T>
inline void ListaDoble<T>::agregarAlInicio(T* dato){
	Nodo<T>* tmp = inicio->getNext();
	Nodo<T>* nuevo = new Nodo<T>;
	nuevo->setDato(dato);
	nuevo->setPrev(nullptr);
	nuevo->setNext(inicio->getNext());
	inicio->setNext(nuevo);
	if (fin->getPrev() == nullptr) {
		fin->setPrev(nuevo);
	}
	if (tmp != nullptr) {
		tmp->setPrev(nuevo);
	}
}

template<class T>
inline void ListaDoble<T>::agregarAlFinal(T* dato){
	Nodo<T>* tmp = fin->getPrev();
	Nodo<T>* nuevo = new Nodo(dato);
	nuevo->setNext(nullptr);
	nuevo->setPrev(fin->getPrev());
	fin->setPrev(nuevo);
	if (tmp != nullptr) {
		tmp->setNext(nuevo);
	}
	if (inicio->getNext() == nullptr) {
		inicio->setNext(nuevo);
	}
}

template<class T>
inline std::string ListaDoble<T>::toString(){
	std::stringstream ss;
	Nodo<T>* temporal = inicio;
	if (temporal->getNext() == nullptr) {
		ss << "Lista vacia\n\n";
	}
	else {
		temporal = temporal->getNext();
		ss << "NULLPTR  <-> ";
		while (temporal != nullptr) {
			ss << temporal->getDato();
			ss << " <-> ";
			temporal = temporal->getNext();
		}
		ss << " NULLPTR\n";
	}

	return ss.str();
}

template<class T>
inline IteradorListaDoble<T>* ListaDoble<T>::crearInterador() const{
	return new IteradorListaDoble<T>(this);
}

template<class T>
inline void ListaDoble<T>::insertar(T* value)
{
	Nodo<T>* tmp = fin->getPrev();
	Nodo<T>* nuevo = new Nodo<T>(value);
	nuevo->setNext(nullptr);
	nuevo->setPrev(fin->getPrev());
	fin->setPrev(nuevo);
	if (tmp != nullptr) {
		tmp->setNext(nuevo);
	}
	if (inicio->getNext() == nullptr) {
		inicio->setNext(nuevo);
	}

	cuentaNodos++;
	heapify(nuevo, (cuentaNodos-1)/2);
}

template<class T>
inline void ListaDoble<T>::heapify(Nodo<T>* actual, int index)
{
	Nodo<T>* padreNodo = inicio->getNext();
	int counter = 0;
	while (counter != index)
	{
		padreNodo = padreNodo->getNext();
		counter++;
	}

	std::cout <<"heappy: " << *(padreNodo->getDato()) << std::endl;
	//eventualmente se llega al padre
	if (actual != inicio->getNext() && *(padreNodo->getDato()) < *(actual->getDato()))
	{
		swap(actual, padreNodo);
		heapify(padreNodo, (index - 1) / 2);
	}
}

template<class T>
inline void ListaDoble<T>::swap(Nodo<T>* actual, Nodo<T>* padre)
{
	auto auxAnterior = actual->prev;
	auto auxSig = actual->prev;

	actual->setNext(padre->next);
	actual->setPrev(padre->prev);

	padre->setNext(auxSig);
	padre->setPrev(auxAnterior);
}



#endif 