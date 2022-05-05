#pragma once


template <class T>
class Node {
public:
	T value;
	Node<T>* next;
	int size;
	Node(T v);
	Node();
	~Node();
};

template <class T>
class LinkedList
{
	//this class need to convert from primitive generic to obj generic
public:
	Node<T>* head;
	int size;

	LinkedList();
	~LinkedList();


	void add(T v); // add in the end
	void add(T v, int index); //add in a specific index
	void addFirst(T v);
	void deleteElement(T v); // find element then use deleteIndex function
	void deleteIndex(int index);
	int length(); // return size, if i forgot to change size in other functions[for testing must change to return size and make size private]
	bool findRecursive(T v); // a Recusive function for finding []
	int find(T v); //return index of element
	T pop();			//?
	T get(int); // implement it that return the element after i

	//operation on the entier list
	void sort();	//sort list asc
	void show();	



private:
	bool find(T v, Node<T>* node); // used in findRecusrsive
};






