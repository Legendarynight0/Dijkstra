#include "LinkedList.h"
#include <iostream>
using namespace std;

//Node functions
//
//
template <class T>
Node<T>::Node(){
	next = nullptr;
}
template<class T>
Node<T>::~Node(){
	delete next;
}
template<class T>
Node<T>::Node(T v) {
	Node();
	value = v;
}

//LinkedList functions: 
//
//most functions are tested

template <class T>
LinkedList<T>::LinkedList(){
	size = 0;
	head = new Node<T>();
	head->next = nullptr;
}
//not compeleted	
template<class T>								//[under construction]
LinkedList<T>::~LinkedList(){
	Node<T>* temp = head;

}

//correct
template <class T>
void LinkedList<T> ::add(T v) {
	Node<T>* obj = new Node<T>(v);
	Node<T>* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = obj;
	size++;
}

template <class T>
void LinkedList<T>::add(T v, int index)
{
	Node<T>* obj = new Node<T>(v);
	Node<T>* pointer = head;
	if (index != 0)
	{
		for (int i = 0; i < index; ++i)
		{
			pointer = pointer->next;
		}
		obj->next = pointer->next;
		pointer->next = obj;
	}
	else
	{
		obj->next = pointer->next;
		head->next = obj;
	}
	size++;
}

template <class T>
void LinkedList<T>::addFirst(T v)
{
	add(v, 0);
}

template <class T>
void LinkedList<T>::deleteElement(T v)
{
	deleteIndex(v, find(v));
}

template <class T>
void LinkedList<T>::deleteIndex(int index)
{
	if (index >= size && index < 0) {
		cout << "out of List index, Index: " << index;
	}
	else if (size == 0) {
		cout << "List is empty";
	}
	Node<T>* temp = head;
	Node<T>* del;
	while (index > 0) {
		temp = temp->next;
		index--;
	}
	del = temp->next;
	temp->next = del->next;
	del->next = NULL;

	size--;
}

template <class T>
int LinkedList<T>::length()
{
	Node<T>* temp = head->next;

	int counter = 0;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}
	return counter;
}

//return the index of the item, in this case it must be primitive data type not object					[under construction]: to obj
template <class T>
int LinkedList<T>::find(T v)
{
	Node<T>* temp = head->next;
	int counter = 0;
	while (temp != NULL) {
		if (temp->value == v)
		{
			return counter;
		}
		counter++;
		temp = temp->next;
	}
	return -1;
}

// not tested
template<class T>
bool LinkedList<T>::findRecursive(T v)
{
	find(v, head->next);
}

//it is used to find it using a recursive call and it is used in findRecusive function, (must be primitive)				[under construction]: to obj
template<class T>
bool LinkedList<T>::find(T v, Node<T>* node)
{
	if (node->next == NULL) {
		return false;
	}else {
		if (node->value == v) {
			return true;
		}
		else {
			find(v, node->next);
		}
	}
}

//modified, don't remember the original functionality 		[under construction]
template<class T>
T LinkedList<T>::pop()
{
	T = get(size - 1);
	deleteIndex(size - 1);
	return T;
	//(head->next)->value
}


//sorting the linkedlist asc				[under construction]
template <class T>
void LinkedList<T>::sort()
{
}

//display primitive data type				[under construction]: to obj
template <class T>
void LinkedList<T> ::show() {
	if (size == 0) {
		cout << "List Empty";

	}
	else {

		Node<T>* temp = head->next;
		while (temp != NULL) {
			std::cout << temp->value << " ";
			temp = temp->next;
		}
	}
}

//get object of index i						[under construction]
template <class T>
T LinkedList<T> ::get(int x) {
	Node<T>* temp = head->next;
	for (int i = 0; i < x && temp != NULL; i++){
		temp = temp->next;
	}
	return temp->value;
}