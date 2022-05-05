#pragma once
#include "LinkedList.cpp"
#include <vector>


class Pair {
public:
	int v;
	int w;
	Pair(int, int);
	Pair();
};

class List {
public:
	int v;
	int sum;
	int prev;

	List();
	~List();
};


class Graph {
public:
	vector<LinkedList<Pair>> g ;
	//use stack to save path

	bool visited[];

	//Graph functions
	Graph();
	Graph(int);						//creating graph for specific amount of vertices
	~Graph();						//for deleteing graph


	void add(int, int, int);			//adding edges
	bool remove(int, int);			//return true if success && delete the edge
	bool updateEdge(int, int);		//updating the W only
	void show();					//show the entier graph

	//algorithm function
	int dijkstra(int, int);			//it will update a LIst to solve the problem
	int path(int);				   //recusivly call to find the path and return it to stack if there is 

};






// how to validate the algorithm?
// important cases, if it is disconnected graph how should the algorithm behave
// if there is two paths with the same value, can there be a problem in this?
// what is the complexity of this algorithm?
// create vector from scratch
//
