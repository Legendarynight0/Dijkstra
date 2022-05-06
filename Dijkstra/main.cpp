#include "C:\Users\omar_\source\repos\Dijkstra\Dijkstra\Graph.h"

int main() {
	Graph s;

	s.add("0", "1", 2);
	s.add("0", "2", 3);
	s.add("1", "2", 10);
	s.add("1", "3", 2);
	s.add("2", "3", 4);
	s.add("3","4",6);
	s.add("3", "5", 1);
	s.add("4", "5", 10);
	//s.show();
	s.dijkstra(0);
	s.path(0,5);
	while (!s.road.empty()) {
		cout << " " << s.road.top()+1 << " ";
		s.road.pop();
	}
	//s.showList();
	
	
	
	//LinkedList<Pair> t ;
	//Pair x(1000, 2000);
	//t.add(x);
	//s.g.push_back(t);
	//s.g.at(0).add(x);
	//cout<<"value of first Linked at index 0 : " << s.g.at(0).get(0).v <<"\n";
	//cout << (s.get(2)).v;
	//s.show();

	return 0;
}