#include "C:\Users\omar_\source\repos\Dijkstra\Dijkstra\Graph.h"

int main() {
	Graph s;
	LinkedList<Pair> t ;
	Pair x(1000, 2000);
	t.add(x);
	s.g.push_back(t);
	s.g.at(0).add(x);
	cout<<"value of first Linked at index 0 : " << s.g.at(0).get(0).v <<"\n";
	//cout << (s.get(2)).v;
	//s.show();

	return 0;
}