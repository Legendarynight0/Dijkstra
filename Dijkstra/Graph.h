#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <limits.h>
#include <queue>
#include <string>

using namespace std;

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
	long sum;
	int prev;

	List();
	~List();
};


class Graph {
public:
	vector<vector<Pair>> g ;
	unordered_map<string, int> map;
	unordered_map<int, string> revMap; //check for bidirectional map
	List* ls;
	stack <int> road;
	int temp; //delete later


	//Graph functions
	Graph();
	Graph(int);						//creating graph for specific amount of vertices
	~Graph();						//for deleteing graph


	void add(string, string, int);			//adding edges
	bool remove(int, int);			//return true if success && delete the edge
	bool updateEdge(string, string,int);		//updating the W only
	void show();					//show the entier graph
	void test();
	
	//algorithm function
	void dijkstra(int);			//it will update a List to solve the problem
	void clearList(int);		//this clear or create list for dijkstra algorithm, it is used only in dijkstra 
	void showList();
	void path(int);				   //recusivly call to find the path and return it to stack if there is 
	vector<vector<Pair>> loadGraph();
	void saveGraph(vector<vector<Pair>>);
};






// how to validate the algorithm?
// important cases, if it is disconnected graph how should the algorithm behave
// if there is two paths with the same value, can there be a problem in this?
// what is the complexity of this algorithm?
// create vector from scratch
//
