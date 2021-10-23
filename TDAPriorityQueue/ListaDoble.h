#ifndef TDAPRIORITYQUEUE_LISTADOBLE_H
#define TDAPRIORITYQUEUE_LISTADOBLE_H
///
#include"Nodo.h"
#include<string>
#include<sstream>
#include<iostream>



template<class T>
class IteradorListaDoble;
//Heap
template<class T>
class ListaDoble {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
	int cuentaNodos;
	Nodo<T>* buscarHijo(int);
	int ban;
public:
	int getCuentaNodos();
	ListaDoble(bool isMax = true);
	ListaDoble(const ListaDoble<T>& li);
	bool getOrden();
	~ListaDoble();
	Nodo<T>* getInicio()const;
	Nodo<T>* getFin()const;
	Nodo<T>* getPrimero()const;
	void setInicio(Nodo<T>*);
	Nodo<T>* getUltimo() const;
	void setFin(Nodo<T>*);
	void agregarAlInicio(T*);
	void agregarAlFinal(T*);
	std::string toString();
	IteradorListaDoble<T>* crearInterador()const;
	void insertar(T*);
	T* eliminar();
	void heapifyUp(Nodo<T>*, int);
	void heapifyDown(Nodo<T>*, int);
	void swap(Nodo<T>*, Nodo<T>*);
	void refreshOuterPointers(Nodo<T>* A);
	int areTheyNeighbours(Nodo<T>* A, Nodo<T>* B);

};

template<class T>
inline Nodo<T>* ListaDoble<T>::buscarHijo(int index)
{
	Nodo<T>* Hijo = inicio->getNext();
	int counter = 0;
	while (counter < index && Hijo->getNext() != fin)
	{
		Hijo = Hijo->getNext();

		counter++;
	}
	return Hijo;
}

template<class T>
inline int ListaDoble<T>::getCuentaNodos()
{
	return cuentaNodos;
}



template<class T>
inline ListaDoble<T>::ListaDoble(bool isMax) {
	ban = isMax;
	inicio = new Nodo<T>;
	fin = new Nodo<T>;
	cuentaNodos = 0;
}

template<class T>
inline ListaDoble<T>::ListaDoble(const ListaDoble<T>& li)
{
	
	std::cout << "matenme";
	auto aux =  li.getPrimero();
	ban = li.ban;
	cuentaNodos = 0;
	inicio = new Nodo<T>;
	fin = new Nodo<T>;

	while (aux&&aux!= li.getFin())
	{
		insertar(new T(*(aux->dato)));
		aux = aux->next;
	}

}

template<class T>
inline bool ListaDoble<T>::getOrden()
{
	return ban;
}

template<class T>
inline ListaDoble<T>::~ListaDoble() {
	Nodo<T>* temporal = inicio->getNext();
	while (temporal != nullptr && temporal->getNext()) {
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
	return fin;//
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
inline Nodo<T>* ListaDoble<T>::getUltimo() const{
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
		while (temporal != nullptr && temporal!=fin) {
			ss << *(temporal->dato);
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
	heapifyUp(nuevo, (cuentaNodos - 1) / 2);
}

template<class T>
inline T* ListaDoble<T>::eliminar()
{
	T* value = nullptr;
		value = inicio->getNext()->getDato();
		swap(inicio->getNext(), fin->getPrev());
		Nodo<T>* anterior = getFin()->getPrev()->getPrev();
		Nodo<T>* eliminar = fin->getPrev();
		delete eliminar;
		if (fin->getPrev() == inicio->getNext()) { 
			inicio = new Nodo<T>;  
			fin = new Nodo<T>;
			return value;
		}
		else {
			anterior->setNext(fin);

			fin->setPrev(anterior);

			cuentaNodos--;
			heapifyDown(inicio->getNext(), 0);
		}

	return value;
}

template<class T>
inline void ListaDoble<T>::heapifyUp(Nodo<T>* actual, int index)
{

	if (!ban)
	{
		if (actual->getPrev())
		{
			Nodo<T>* padreNodo = inicio->getNext();
			int counter = 0;
			while (counter < index)
			{
				padreNodo = padreNodo->getNext();
				counter++;
			}


			//eventualmente se llega al padre
			if (*(padreNodo->getDato()) > *(actual->getDato()))
			{


				swap(actual, padreNodo);
				heapifyUp(padreNodo, (index - 1) / 2);


			}
		}
		else
		{
			if (actual == inicio && cuentaNodos > 0)
			{
				Nodo<T>* temporal = inicio->getNext()->getNext();
				T* valor = inicio->getDato();
				delete inicio->getNext();
				inicio->setNext(temporal);
				temporal->setPrev(inicio);
				insertar(valor);

			}
		}
	}
	else
	{
		if (actual->getPrev())
		{
			Nodo<T>* padreNodo = inicio->getNext();
			int counter = 0;
			while (counter < index)
			{
				padreNodo = padreNodo->getNext();
				counter++;
			}


			//eventualmente se llega al padre
			if (*(padreNodo->getDato()) < *(actual->getDato()))
			{


				swap(actual, padreNodo);
				heapifyUp(padreNodo, (index - 1) / 2);


			}
		}
		else
		{
			if (actual == inicio && cuentaNodos > 0)
			{
				Nodo<T>* temporal = inicio->getNext()->getNext();
				T* valor = inicio->getDato();
				delete inicio->getNext();
				inicio->setNext(temporal);
				temporal->setPrev(inicio);
				insertar(valor);

			}
		}
	}
	

}

template<class T>
inline void ListaDoble<T>::heapifyDown(Nodo<T>* actual, int index)
{
	auto izquierdo = buscarHijo((2 * index) + 1);
	auto derecho = buscarHijo((2 * index) + 2);

	if (!ban)
	{
		if (derecho == nullptr && izquierdo == nullptr)
		{
			return;
		}
		else
		{
			if (izquierdo && derecho == nullptr)
			{
				if (*(actual->getDato()) > *(izquierdo->getDato()))
				{
					swap(izquierdo, actual);
					heapifyDown(izquierdo, (2 * index) + 1);
				}
				else
				{
					if (izquierdo == nullptr && derecho)
					{
						if (*(actual->getDato()) > *(derecho->getDato()))
						{
							swap(actual, derecho);
							heapifyDown(derecho, (2 * index) + 2);
						}
					}
				}

			}
		}

		if (izquierdo && derecho)
		{
			if (*(derecho->getDato()) > *(izquierdo->getDato()))
			{
				//std::cout << *(izquierdo->getDato()) << "<- " << *(actual->getDato()) << " ->" << *(derecho->getDato()) << std::endl;
				if (*(actual->getDato()) > *(izquierdo->getDato()))
				{
					swap(izquierdo, actual);
					heapifyDown(izquierdo, (2 * index) + 1);
				}

			}
			else
			{
				if (*(actual->getDato()) > *(derecho->getDato()))
				{
					swap(actual, derecho);
					heapifyDown(derecho, (2 * index) + 2);
				}
			}
		}
	}
	else 
	{
		if (derecho == nullptr && izquierdo == nullptr)
		{
			return;
		}
		else
		{
			if (izquierdo && derecho == nullptr)
			{
				if (*(actual->getDato()) < *(izquierdo->getDato()))
				{
					swap(izquierdo, actual);
					heapifyDown(izquierdo, (2 * index) + 1);
				}
				else
				{
					if (izquierdo == nullptr && derecho)
					{
						if (*(actual->getDato()) < *(derecho->getDato()))
						{
							swap(actual, derecho);
							heapifyDown(derecho, (2 * index) + 2);
						}
					}
				}

			}
		}

		if (izquierdo && derecho)
		{
			if (*(derecho->getDato()) < *(izquierdo->getDato()))
			{
				//std::cout << *(izquierdo->getDato()) << "<- " << *(actual->getDato()) << " ->" << *(derecho->getDato()) << std::endl;
				if (*(actual->getDato()) < *(izquierdo->getDato()))
				{
					swap(izquierdo, actual);
					heapifyDown(izquierdo, (2 * index) + 1);
				}

			}
			else
			{
				if (*(actual->getDato()) < *(derecho->getDato()))
				{
					swap(actual, derecho);
					heapifyDown(derecho, (2 * index) + 2);
				}
			}
		}
	}

	


}

template<class T>
void ListaDoble<T>::swap(Nodo<T>* primeroPtr, Nodo<T>* segundoPtr) {
	T* aux = primeroPtr->getDato();
	primeroPtr->setDato(segundoPtr->getDato());
	segundoPtr->setDato(aux);
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
