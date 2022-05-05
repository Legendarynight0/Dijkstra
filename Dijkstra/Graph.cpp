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
Graph::Graph(int v){}
Graph::~Graph() {}

bool Graph::remove(int, int) {
	return false;
}
bool Graph::updateEdge(int, int) {
	return false;
}
void Graph::show() {}

void Graph ::add(int v, int u, int w) {
	Pair* x = new Pair(u,w);
	Pair* y = new Pair(v, w);
	g.at(v).add(*x);
	g.at(u).add(*y);

}
