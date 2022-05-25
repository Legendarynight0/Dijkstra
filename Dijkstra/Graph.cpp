#include "C:\Users\Legendary\source\repos\Dijkstra\Dijkstra\Graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <limits.h>
#include <queue>

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

void Graph::removeEdge(int v, int u) {
	bool isDeleted = false;
	for (int i = 0; i < g.at(v).size(); i++) {
		if (g.at(v).at(i).v == u) {
			g.at(v).erase(g.at(v).begin() + i);
			isDeleted = true;
		}
	}
	if (!direct) {
		for (int i = 0; i < g.at(u).size(); i++) {
			if (g.at(u).at(i).v == v) {
				g.at(u).erase(g.at(u).begin() + i);
				isDeleted = true;
			}

		}
	}
	
}
void Graph::updateEdge() {
	string v, u;
	int w;
	cout << "What is the Update?\n 1.Add\n 2.Remove vertex\n 3.Remove edge\n 4.Update\n";
	cout << "enter choice number : ";
	int choose;
	cin >> choose;
	if (choose == 1) {
		cout << "enter new vertex name : ";
		cin >> v >> u >> w;
		add(v, u, w);
		show();

	}
	else if (choose == 2) {
		cout << "enter vertex name : ";
		cin >> v;
		removeVertex(map[v]);
		show();

	}
	else if (choose == 3) {
		cout << "enter source, destination of the edge : ";
		cin >> v >> u;
		removeEdge(map[v], g.at(map[v]).at(0).v);
		show();
	}
	else if (choose == 4) {
		if (map.find(v) == map.end() && map.find(u) == map.end()) {
			cin >> v >> u >> w;
			for (int i = 0; i < g.at(map[v]).size(); i++)
			{
				if (g.at(map[v]).at(i).v == map[u]) {
					g.at(map[v]).at(i).w = w;
					break;
				}
			}
			if (!direct) {
				for (int i = 0; i < g.at(map[u]).size(); i++)
				{
					if (g.at(map[u]).at(i).v == map[v]) {
						g.at(map[u]).at(i).w = w;
						break;
					}
				}
			}

		}
		show();
	}
	else {
		cout << "invalid\n";
		return;
	}
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
		cout << "cost: " << ls[v].sum;
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
		s.pop();
		for (int i = 0; i < g.at(v).size(); i++) {
			int x = g.at(v).at(i).v;
			int y = g.at(v).at(i).w;
			if (y + ls[v].sum < ls[x].sum) {
				ls[x].sum = y + ls[v].sum;
				ls[x].prev = v;
				s.push(x);
			}
		}
	}
}

void Graph::path(int src, int dest) {
	if (ls[dest].prev < 0) return;

	if (dest == src) {
		road.push(dest);
		return;
	}
	else {
		road.push(dest);
		path(src, ls[dest].prev);
	}
}
void Graph::test() {
	cout << "1-Load Graph" << endl;
	cout << "2-Create New" << endl;
	cout << "enter choice number : ";
	int choose;
	cin >> choose;
	if (choose == 1) {
		vector<vector<Pair>> g;
		loadGraph();
		show();
	}
	else if (choose == 2) {
		cout << "1-directed  Graph" << endl;
		cout << "2-undirected Graph" << endl;
		cout << "enter choice number : ";
		int dir;
		cin >> dir;
		if (dir == 1) { direct = true; }
		else if (dir == 2) { direct = false; }
		else { cout << "invalid, the Graph will be on default settings\n"; }

		int i = 1;
		string v, u;
		int  w;
		int option;
		bool finished = false;
		while (!finished) {
			cout << "Enter way(source, destination, weight) number " << i++ << ":\n";
			cin >> v >> u >> w;
			transform(v.begin(), v.end(), v.begin(), ::tolower);
			transform(u.begin(), u.end(), u.begin(), ::tolower);
			if (v != "-1" && u != "-1" && w != -1) {
				add(v, u, w);
			}
			else
				break;
			cout << "Do you want to add another way?(y/n) ";
			char in; cin >> in;
			if (in == 'n') { 
				break;
			}
			else if (in != 'y') {
				cout << "invalid \n";
				break;
			}
				
		}

		cout << "Graph created \n";
	}

}


void Graph::saveGraph(string filename) {
	ofstream MyFile;
	cout << "Enter Graph name:" << endl;
	if (savingLoaction == "") {
		cin >> filename;
	}
	else {
		filename = savingLoaction;
	}

	MyFile.open(filename, ios::out);
	if (direct)
		MyFile << "directed" << endl;
	else
		MyFile << "undirected" << endl;

	for (int i = 0; i < g.size(); i++) {

		for (int j = 0; j < g[i].size(); j++)
		{

			MyFile << revMap[i] << " " << revMap[g[i][j].v] << " " << g[i][j].w << endl;;

		}


	}

	MyFile.close();

}

void  Graph::loadGraph() {

	string filename;
	cout << "Enter the name of graph you want to load:" << endl;
	cin >> filename;
	savingLoaction = filename;
	ifstream myfile(filename);

	if (myfile.is_open()) {
		string dir;
		if (getline(myfile, dir))
		{
			if (dir == "directed") direct = true;
			else direct = false;
		}

		string line;
		while (getline(myfile, line)) {
			int begin = 0;
			string v, u;
			int w = -1;
			int num = 1;
			for (int i = 0; i < line.size(); i++)
			{
				if (line[i] == ' ') {
					if (num == 1) {

						v = line.substr(begin, i);
						begin = i + 1;
						num++;
					}
					else if (num == 2) {
						u = line.substr(begin, i - 2);
						begin = i;
						num++;
						w = stoi(line.substr(i + 1, line.size()));
						break;
					}
				}
			}
			if (w != -1) {
				add(v, u, w);
			}
		}
		myfile.close();
	}
	else {
		cout << "The Graph doesn't exist" << endl;
	}
}

void Graph::removeVertex(int v) {
	if (!direct)
	{
		while (g.at(v).size()) {
			removeEdge(g.at(v).at(0).v, v);
		}
	}
	g.at(v).clear();
}