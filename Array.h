#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

template <class T>
class Array {
	public:
		//constructor
		Array();

		//destructor
		~Array();

		//other
		void add(const T&);
		void remove(const T&);
		int size() const;
		bool isFull() const;
		T& operator[](int);
		const T& operator[](int) const;
		Array<T>& operator+=(const T&);
		Array<T>& operator-=(const T&);
		void clear();

	private:
		int numElements;
		int capacity;
		T* elements;

};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARRAY];
	numElements = 0;
	capacity = MAX_ARRAY;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(const T& t){
	if (numElements >= capacity)   return;
  	elements[numElements++] = t;
}

template <class T>
void Array<T>::remove(const T& t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
}

template <class T>
int Array<T>::size() const{
	return numElements;
}

template <class T>
bool Array<T>::isFull() const{
	return numElements >= capacity;
}

template <class T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
const T& Array<T>::operator[](int index) const {
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <class T>
Array<T>& Array<T>::operator+=(const T& t) {
	add(t);
	return *this;
}

template <class T>
Array<T>& Array<T>::operator-=(const T& t) {
	remove(t);
	return *this;
}

template <class T>
void Array<T>::clear() {
	numElements = 0;
}

#endif
