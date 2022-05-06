#include "Graph.h"


Pair::Pair(int x,int y) {
	v = x;
	w = y;
}
Pair::Pair() {
	Pair(-1, -1);
}

List::List() {
	prev = -1;
	sum = LONG_MAX;
	v = -1;

}
List::~List() {

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
void Graph::show() {
	for (int i = 0; i < g.size(); i++) {
		cout << "city: " << revMap[i] << "\n";
		for (int j = 0; j < g[i].size; j++) {
			cout << "connected to: " << revMap[g.at(i).get(j).v] << ", with weight is: " << g.at(i).get(j).w << "\n";
		}

	}
}

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
void Graph::clearList(int v) {
	ls = new List[g.size()];
	for (int i = 0; i < g.size(); i++) {
		ls[i].prev = -1;
		ls[i].v = i;
		ls[i].sum = LONG_MAX;
	}
	ls[v].sum = 0;

}
void Graph::showList() {
	for (int i = 0; i < g.size(); i++) {
		cout << "vertex: " << i << " cost: " << ls[i].sum << " prev: " << ls[i].prev <<"\n";
	}
}
void Graph::dijkstra(int index) {
	clearList(index);
	queue<int> s;
	bool* visited = new bool[g.size()];
	for (int i = 0; i < g.size(); i++)
	{
		visited[i] = false;
	}
	s.push(index);
	visited[index] = true;
	while (!s.empty()) {
		int v = s.front();
		s.pop();
		for (int i = 0; i < g.at(v).size; i++) {
			int u = g.at(v).get(i).v;
			long w = g.at(v).get(i).w;
			if (!visited[u]) {
				s.push(u);
				visited[u] = true;
			}
			if (ls[v].sum + w < ls[u].sum) {
				ls[u].prev = v;
				ls[u].sum = w + ls[v].sum;
			}

		}

	}

	
}
void Graph::path(int src,int dest) {
	if (src == dest || dest == -1) {
		road.push(src);
		return;
	}
	else {
		road.push(dest);
		path(src, ls[dest].prev);
	}
}
void Graph::test() {
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int v, u, w;
		cin >> v >> u >> w;
		//add(v, u, w);
	}
}