#include "C:\Users\Legendary\source\repos\Dijkstra\Dijkstra\Graph.h"
#include<string>
#include<iostream>
#include<fstream>
#include<set>
using namespace std;

Pair::Pair(int x, int y) {
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
Graph::Graph(int v) {}
Graph::~Graph() {}

void Graph::add(string v, string u, int w) {
	// don't add A C then C A
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
	bool flag = true;
	for (int k = 0; k < g.at(i).size(); k++) {
		if (g.at(i).at(k).v == j) {
			flag = false;
			break;
		}
	}
	if (flag) {
		g.at(i).push_back(x);
	}
	if (!direct) {
		for (int k = 0; k < g.at(j).size(); k++) {
			if (g.at(j).at(k).v == i) {
				return;
			}
		}
		g.at(j).push_back(y);

	}


}
bool Graph::removeEdge(int v, int u) {
	bool x = false;
	for (int i = 0; i < g.at(v).size(); i++) {
		if (g.at(v).at(i).v == u) {
			cout << "we remove \n";
			g.at(v).erase(g.at(v).begin() + i);
			x = true;
			break;
		}

	}

	for (int i = 0; i < g.at(u).size(); i++) {
		if (g.at(u).at(i).v == v) {
			cout << "we remove \n";
			g.at(u).erase(g.at(u).begin() + i);
			return true;
		}

	}
	cout << "Error";
	return false;
}
void Graph::updateEdge() {
	string v, u;
	int w;
	cout << "What is the Update? 1.Add 2.Remove vector 3.Remove edge 4.Update";
	int choose;
	cin >> choose;
	if (choose == 1) {

		cin >> v >> u >> w;
		add(v, u, w);
	}
	else if (choose ==2) {
		cin >> v;
		removeVertex(map[v]);
	}
	else if (choose == 3) {
		cin >> v >> u;

		while (g.at(map[v]).size() != 0) {
			removeEdge(map[v], g.at(map[v]).at(0).v);
		}
	}
	else if (choose ==4) {
		if (map.find(v) == map.end() && map.find(u) == map.end()) {
			cin >> v >> u >> w;
			g.at(map[v]).at(map[u]).w = w;
			g.at(map[u]).at(map[v]).w = w;
		}
	}
	else {
		cout << "invalid\n";
	}
	show();
}
void Graph::show() {
	for (int i = 0; i < g.size(); i++) {
		cout << "city: " << revMap[i] << "\n";
		for (int j = 0; j < g[i].size(); j++) {
			cout << "connected to: " << revMap[g.at(i).at(j).v] << ", with weight is: " << g.at(i).at(j).w << "\n";
		}

	}
}
void Graph::showList(int v) {
	if (ls[v].prev < 0) { cout << "no path to the city"; }
	else {
		cout << "Weight: " << revMap[v] << " cost: " << ls[v].sum;
	}
	//for (int i = 0; i < g.size(); i++) {
	//	
	//	if (ls[i].prev < 0) { cout << "No path to " <<revMap[i] << " prev: " << revMap[ls[i].prev] <<"\n"; }
	//	else {
	//		cout << "vertex: " << revMap[i] << " cost: " << ls[i].sum << " prev: " << revMap[ls[i].prev] << "\n";
	//	}
	//}
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
	//cout << "finished dijkstra function \n";
}

void Graph::path(int src, int dest) {
	if (dest == src) {
		road.push(dest);
		return;
	}
	else {
		road.push(dest);
		path(src,ls[dest].prev);
	}
}
void Graph::test() {
	string choose;
	cout << "Load Graph or Create? \n";
	cin >> choose;
	transform(choose.begin(), choose.end(), choose.begin(), tolower);
	if (choose == "load") {
		vector<vector<Pair>> g;
		loadGraph();
		show();
	}
	else if (choose == "create") {
		string dir;
		cout << "directed or undirected Graph?\n";
		cin >> dir;
		transform(dir.begin(), dir.end(), dir.begin(), tolower);
		if (dir == "directed") { direct = true; }
		else if (dir == "undirected") { direct = false; }
		else { cout << "invalid, the Graph will be on default settings"; }

		int i = 1;
		string v, u;
		int  w;
		int option;
		while (true) {
			cout << "Enter Data number: " << i++ << "\n";
			cin >> v >> u >> w;
			transform(v.begin(), v.end(), v.begin(), tolower);
			transform(u.begin(), u.end(), u.begin(), tolower);
			if (v == "- 1" || u == "- 1" || w == -1) {

				cout << "Graph created \n";
				

				break;
			}
			else {
				add(v, u, w);
			}
		}
	}


};


void Graph::saveGraph( string filename) {
	ofstream MyFile;
	cout << "Enter Graph name:" << endl;
	if (savingLoaction == "") {
		cin >> filename;
	}
	else {
		filename = savingLoaction;
	}
	

	MyFile.open(filename, ios::out | ios::app);
	for (int i = 0; i < g.size(); i++) {

		for (int j = 0; j < g[i].size(); j++)
		{

			MyFile << revMap[i] << " " << revMap[g[i][j].v] << " " << g[i][j].w << endl;;

		}


	}

	MyFile.close();

};

void  Graph::loadGraph() {
		
	string lines,filename;
	cout << "Enter the name of graph you want to load:" << endl;
	cin >> filename;
	savingLoaction = filename;
	ifstream myfile(filename);

	string dir;
	cout << "directed or undirected Graph?\n";
	cin >> dir;
	transform(dir.begin(), dir.end(), dir.begin(), tolower);
	if (dir == "directed") { direct = true; }
	else if (dir == "undirected") { direct = false; }

	if (myfile.is_open()) {
		while (getline(myfile, lines)) {
			string x = lines;
			int begin=0;
			string v, u;
			int w = -1;
			int num = 1;
			for (int i = 0; i < x.size(); i++)
			{
				if (x[i] == ' ') {
					if (num == 1) {
						
						v = x.substr(begin,i);
						begin = i+1;
						num++;
					}
					else if (num == 2) {
						u = x.substr(begin, i-2);
						begin = i;
						num++;
						w = stoi(x.substr(i + 1, x.size()));
						

						break;
					}
					
				}
			}
			if (w != -1) {
				add(v, u, w);
			}
		}
		//direct = true;
		myfile.close();
	}
	else {
		cout << "The Graph doesn't exist" << endl;
	}
};

void Graph::removeVertex(int v) {
	if (!direct) {
		while (g.at(v).size()) {
			removeEdge(g.at(v).at(0).v, v);
		}
	}
	g.at(v).clear();



}