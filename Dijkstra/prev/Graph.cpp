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

void Graph::add(string v, string u, int w) {
	if (map.find(v) == map.end()) {
		map[v] = map.size();
		revMap[revMap.size()] = v;

		vector<Pair> t;
		g.push_back(t);
	}
	if (map.find(u) == map.end()) {
		map[u] = map.size();
		revMap[revMap.size()] = u;

		vector<Pair> t;
		g.push_back(t);
	}
	int i = map.find(v)->second; //index of v
	int j = map.find(u)->second; //index of u
	Pair x(j, w);
	Pair y(i, w);
	g.at(i).push_back(x);
	g.at(j).push_back(y);


}
bool Graph::remove(int, int) {
	return false;
}
bool Graph::updateEdge(string v, string u, int w) {
	cout << "What is the Update?";
	string choose;
	cin >> choose;
	if (choose == "Add") {
	}
	else if(choose == "Remove") {
		return remove(map[v],map[u]);
	}
	else if (choose == "update") {
		if (map.find(v) == map.end() && map.find(u) == map.end()) {
			g.at(map[v]).at(map[u]).w = w;
			g.at(map[u]).at(map[v]).w = w;
			return true;
		}
	}

	return false;
}
void Graph::show() {
	for (int i = 0; i < g.size(); i++) {
		cout << "city: " << revMap[i] << "\n";
		for (int j = 0; j < g[i].size(); j++) {
			cout << "connected to: " << revMap[g.at(i).at(j).v] << ", with weight is: " << g.at(i).at(j).w << "\n";
		}

	}
}
void Graph::showList() {
	for (int i = 0; i < g.size(); i++) {
		cout << "vertex: " << revMap[i] << " cost: " << ls[i].sum << " prev: " << revMap[ls[i].prev] << "\n";
	}
	cout << "\n";
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
void Graph::dijkstra(int index) {
	clearList(index);
	queue<int> s;
	s.push(index);
	while (!s.empty()) {
		
		int v = s.front();
		//cout << "loop of:  " << revMap[v] << "\n";
		s.pop();
		for (int i = 0; i < g.at(v).size(); i++) {
			int x = g.at(v).at(i).v;
			int y = g.at(v).at(i).w;
			if (y + ls[v].sum < ls[x].sum) {
				//cout << revMap[x] << " this will change  " << revMap[ls[x].prev] << " to " << revMap[v] << "\n";
				ls[x].sum = y + ls[v].sum;
				ls[x].prev = v;
				s.push(x);
			}
		}
		//showList();
		
	}
	//show();
	cout << "finished dijkstra function";
}

void Graph::path(int dest) {
	if (dest == 0) {
		road.push(dest);
		return;
	}
	else {
		if (ls[dest].prev == -1) { road.push(-1); return; }
		road.push(dest);
		path(ls[dest].prev);
	}
}
void Graph::test() {
	string choose;
	cout << "Load Graph or Create? \n";
	cin >> choose;
	if (choose == "load") {
		//g = load();
	}
	else if (choose == "create") {
		int i = 1;
		string v, u;
		int  w;
		while (true) {
			cout << "Enter Data number: " << i++ << "\n";
			cin >> v >> u >> w;
			if (v == "- 1" || u ==  "- 1" || w == -1) {
				cout << "Graph created \n";
				break;
			}
			else {
				add(v, u, w);
			}
		}
	}
		string x, y;
		//cin >> v >> u >> w;
		//x = std::to_string(v);
		//y = std::to_string(u);
		//add(x, y, w);

}