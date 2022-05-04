#include "Graph.h"



Pair::Pair(int x,int y) {
	v = x;
	w = y;
}

Pair::Pair() {
	Pair(-1, -1);
}


Graph::Graph() {
	//g = new vector<LinkedList<Pair>>;

}


void Graph ::add(int v, int u, int w) {
	Pair* x = new Pair(u,w);
	Pair* y = new Pair(v, w);
	g->at(v).add(*x);
	g->at(u).add(*y);

}
