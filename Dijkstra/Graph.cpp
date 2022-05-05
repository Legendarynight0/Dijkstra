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

void Graph ::add(string v, string u, int w) {
	if (map.find(v) == map.end()) {
		map[v] = map.size();
		revMap[revMap.size()] =v;

		LinkedList<Pair> t;
		g.push_back(t);
	}
	if (map.find(u) == map.end()) {
		map[u] = map.size();
		revMap[revMap.size()] = u;

		LinkedList<Pair> t;
		g.push_back(t);
	}
	int i = map.find(v)->second; //index of v
	int j = map.find(u)->second; //index of u
	Pair x(j, w);
	Pair y(i, w);
	g.at(i).add(x);
	g.at(j).add(y);


}
