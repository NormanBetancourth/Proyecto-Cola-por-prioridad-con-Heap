#ifndef TDAPRIORITYQUEUE_ITERADORLISTADOBLE_H
#define TDAPRIORITYQUEUE_ITERADORLISTADOBLE_H

template<class T>
class Nodo;
template<class T>
class ListaDoble;

template<class T>
class IteradorListaDoble {
private:
	const ListaDoble<T>* listaDoble;
	Nodo<T>* index;
public:
	IteradorListaDoble(const ListaDoble<T>*);
	~IteradorListaDoble();
	void setListaDoble(const ListaDoble<T>*);
	void setIndex(Nodo<T>* index);
	const ListaDoble<T>* getListaDoble()const;
	Nodo<T>* getIndex()const;
	void begin();
	void prev();
	void next();
	void end();
	bool isEnd()const;
	Nodo<T>* currentItem();
};


template<class T>
inline IteradorListaDoble<T>::IteradorListaDoble(const ListaDoble<T>* listaDoble): listaDoble(listaDoble), index(nullptr){}

template<class T>
inline IteradorListaDoble<T>::~IteradorListaDoble(){
}

template<class T>
inline void IteradorListaDoble<T>::setListaDoble(const ListaDoble<T>* listaDoble){
	this->listaDoble = listaDoble;
}

template<class T>
inline void IteradorListaDoble<T>::setIndex(Nodo<T>* index){
	this->index = index;
}

template<class T>
inline const ListaDoble<T>* IteradorListaDoble<T>::getListaDoble() const{
	return listaDoble;
}

template<class T>
inline Nodo<T>* IteradorListaDoble<T>::getIndex() const{
	return index;
}

template<class T>
inline void IteradorListaDoble<T>::begin(){
	index = listaDoble->getPrimero();
}

template<class T>
inline void IteradorListaDoble<T>::prev(){
	index = index->getPrev();
}

template<class T>
inline void IteradorListaDoble<T>::next(){
	index = index->getNext();
}

template<class T>
inline void IteradorListaDoble<T>::end(){
	index = listaDoble->getUltimo();
}

template<class T>
inline bool IteradorListaDoble<T>::isEnd() const{
	return index == listaDoble->getFin();
}

template<class T>
inline Nodo<T>* IteradorListaDoble<T>::currentItem(){
	return index;
}

#endif
