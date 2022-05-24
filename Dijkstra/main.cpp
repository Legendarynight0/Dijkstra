#include "C:\Users\Legendary\source\repos\Dijkstra\Dijkstra\Graph.h"

#include <iostream>
#include <fstream>
#include<string>

using namespace std;
int main() {
	Graph g;
	g.test();
	while (true) {
		cout << "Enter your current city \n";
		string index;
		cin >> index;
		if (index == "-1") { cout << "Goodbye"; break; }
		transform(index.begin(), index.end(), index.begin(), tolower);
		if (g.map.find(index) == g.map.end()) {
			break;
		}
		else {
			cout << "Enter you distentation: \n ";
			string x;
			cin >> x;
			transform(x.begin(), x.end(), x.begin(), tolower);

			g.dijkstra(g.map[index]);
			g.showList(g.map[x]);
			g.path(g.map[index], g.map[x]);
			cout << "path is \n";
			while (!g.road.empty()) {
				
				cout << g.revMap[g.road.top()] << " ";
				g.road.pop();
			}
			cout << '\n';
		}
		

	}
	while (true) {
		g.updateEdge();
		cout << "continue? yes , no \n";
		string stopping;
		cin >> stopping;
		if (stopping != "yes") { break; }
	}
	int option;
	cout << "1-save 2-don't save" << endl;
	cin >> option;
	if (option == 1) {

		g.saveGraph(".txt");
		cout << "The Graph is saved" << endl;
	}
	else if (option == 2) {
		cout << "Graph has not been saved " << endl;
		return 0;

	}
	else {
		cout << "Wrong Choice !" << endl;
		return 0;
	}

	return 0;
}

