#ifndef TDAPRIORITYQUEUE_LISTADOBLE_H
#define TDAPRIORITYQUEUE_LISTADOBLE_H

#include"Nodo.h"
#include<string>
#include<sstream>

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
	void refreshOuterPointers(Nodo<T>* A);
	int areTheyNeighbours(Nodo<T>* A, Nodo<T>* B);

};

template<class T>
inline ListaDoble<T>::ListaDoble() {
	inicio = new Nodo<T>;
	fin = new Nodo<T>;
}

template<class T>
inline ListaDoble<T>::~ListaDoble() {
	Nodo<T>* temporal = inicio->getNext();
	while (temporal != nullptr) {
		inicio->setNext(temporal->getNext());
		delete temporal;
		temporal = inicio->getNext();
	}
}

template<class T>
inline Nodo<T>* ListaDoble<T>::getInicio() const {
	return inicio;
}

template<class T>
inline Nodo<T>* ListaDoble<T>::getFin() const {
	return fin;
}

template<class T>
inline Nodo<T>* ListaDoble<T>::getPrimero() const {
	return inicio->getNext();
}

template<class T>
inline void ListaDoble<T>::setInicio(Nodo<T>* inicio) {
	this->inicio = inicio;
}

template<class T>
inline Nodo<T>* ListaDoble<T>::getUltimo() {
	return fin->getPrev();
}

template<class T>
inline void ListaDoble<T>::setFin(Nodo<T>* fin) {
	this->fin = fin;
}

template<class T>
inline void ListaDoble<T>::agregarAlInicio(T* dato) {
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
inline void ListaDoble<T>::agregarAlFinal(T* dato) {
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
inline std::string ListaDoble<T>::toString() {
	std::stringstream ss;
	Nodo<T>* temporal = inicio;
	if (temporal->getNext() == nullptr) {
		ss << "Lista vacia\n\n";
	}
	else {
		temporal = temporal->getNext();
		ss << "NULLPTR  <-> ";
		while (temporal != nullptr) {
			ss << *(temporal->getDato());
			ss << " <-> ";
			temporal = temporal->getNext();
		}
		ss << " NULLPTR\n";
	}

	return ss.str();
}

template<class T>
inline IteradorListaDoble<T>* ListaDoble<T>::crearInterador() const {
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
	heapify(nuevo, (cuentaNodos - 1) / 2);
}

template<class T>
inline void ListaDoble<T>::heapify(Nodo<T>* actual, int index)
{

	
	if (actual->prev)
	{
		Nodo<T>* padreNodo = inicio->getNext();
		int counter = 0;
		while (counter < index)
		{
			padreNodo = padreNodo->getNext();
			counter++;
		}

		std::cout << "heappy: " << toString() << std::endl;
		std::cout << "heappy: " << toString() << std::endl;
		//eventualmente se llega al padre
		if (*(padreNodo->getDato()) > *(actual->getDato()))
		{
			std::cout << "padre dato: " << *(padreNodo->getDato()) << std::endl;
			std::cout << "actual dato: " << *(actual->getDato()) << std::endl;

			swap(actual, padreNodo);
			heapify(padreNodo, (index - 1) / 2);

			
		}
	}
	else
	{
		if (actual == inicio && cuentaNodos > 0)
		{
			Nodo<T>* temporal = inicio->next->next;
			T* valor = inicio->dato;
			delete inicio->next;
			inicio->next = temporal;
			temporal->prev = inicio;
			insertar(valor);

		}
	}
	
}

template<class T>
void ListaDoble<T>::swap(Nodo<T>* primeroPtr, Nodo<T>* segundoPtr) {
	T* aux = primeroPtr->dato;
	primeroPtr->dato = segundoPtr->getDato();
	segundoPtr->dato = aux;
}



//template<class T>
//inline void ListaDoble<T>::swap(Nodo<T>* A, Nodo<T>* B) {
//	Nodo<T>* swapperVector[4];
//	Nodo<T>*  temp;
//
//	if (A == B) return;
//
//	if (B->next == A) {
//		temp = A;
//		A = B;
//		B = temp;
//	}
//
//	swapperVector[0] = A->prev;
//	swapperVector[1] = B->prev;
//	swapperVector[2] = A->next;
//	swapperVector[3] = B->next;
//
//	if (areTheyNeighbours(A, B)) {
//		A->prev = swapperVector[2];
//		B->prev = swapperVector[0];
//		A->next = swapperVector[3];
//		B->next = swapperVector[1];
//	}
//	else {
//		A->prev = swapperVector[1];
//		B->prev = swapperVector[0];
//		A->next = swapperVector[3];
//		B->next = swapperVector[2];
//	}
//
//	refreshOuterPointers(A);
//	refreshOuterPointers(B);
//}

//template<class T>
//inline void ListaDoble<T>::swap(Nodo<T>* actual, Nodo<T>* padre)
//{
//	auto auxAnterior = actual->prev;
//	auto auxSig = actual->next;
//
//	actual->setNext(padre->next);
//	actual->setPrev(padre->prev);
//
//	padre->setNext(auxSig);
//	padre->setPrev(auxAnterior);
//}
template<class T>
int ListaDoble<T>::areTheyNeighbours(Nodo<T>* A, Nodo<T>* B) {
	return (A->next == B && B->prev == A) || (A->prev == B && B->next == A);
}

template<class T>
void ListaDoble<T>::refreshOuterPointers(Nodo<T>* A) {
	if (A->prev != NULL)
		A->prev->next = A;

	if (A->next != NULL)
		A->next->prev = A;
}



#endif 

