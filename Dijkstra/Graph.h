#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
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
	vector<vector<Pair>> g;
	unordered_map<string, int> map;			 //used to map string to int, O(1) get and add operation
	unordered_map<int, string> revMap;		 //bidirectional map to retrive the original string, can be an array
	List* ls;								 //List Class
	stack <int> road;						 //stack for path
	bool direct = false;					 //true then directed
	string savingLoaction = "";


	//Graph functions
	Graph();
	Graph(int);								//creating graph for specific amount of vertices
	~Graph();								//for deleteing graph


	void add(string, string, int);			//adding and converting vertex to integer type
	void removeEdge(int, int);		
	void removeVertex(int);			
	void updateEdge();						//updating the W only, call delete edge and vertex
	void show();							//show the entier graph
	void test();

	//algorithm function
	void dijkstra(int);						//it will update a List to solve the problem
	void clearList(int);					//clear list for dijkstra
	void showList(int);
	void path(int, int);				   //recusivly call to find the path and return it to stack if there is,else output -1
	void loadGraph();
	void saveGraph(string);
};







