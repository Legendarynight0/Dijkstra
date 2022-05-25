#include "C:\Users\Legendary\source\repos\Dijkstra\Dijkstra\Graph.h"

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	Graph g;
	g.test();
	while (true) {
		cout << "Enter your current city \n";
		string currCity;
		cin >> currCity;

		transform(currCity.begin(), currCity.end(), currCity.begin(), ::tolower);
		if (g.map.find(currCity) == g.map.end()) {
			break;
		}
		else {
			cout << "Enter you distentation:\n";
			string x;
			cin >> x;
			transform(x.begin(), x.end(), x.begin(), ::tolower);

			g.dijkstra(g.map[currCity]);
			g.showList(g.map[x]);
			g.path(g.map[currCity], g.map[x]);
			if (!g.road.empty())
			{
				cout << "path is : " << currCity;
			}
			while (!g.road.empty()) {
				cout << " -> " << g.revMap[g.road.top()];
				g.road.pop();
			}
			cout << '\n';
			cout << "Do you want to find another path?(y/n) ";
			char in; cin >> in;
			if (in == 'n')
				break;
		}
	}
	while (true) {
		g.updateEdge();
		cout << "continue?(y/n) ";
		char stopping;
		cin >> stopping;
		if (tolower(stopping) != 'y') { break; }
	}
	int option;
	cout << "1-save" << endl;
	cout << "2-don't save" << endl;
	cout << "enter choice number : ";
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

