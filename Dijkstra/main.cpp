#include "C:\Users\omar_\source\repos\Dijkstra\Dijkstra\Graph.h"

int main() {
	Graph s;
	string n = to_string(s.test());
	s.dijkstra(0);
	cout << "\n path is: \n";
	if (s.map.find(n) == s.map.end()) {
		cout << "-1";
	}else{
		s.path(s.map[n]);
		
		while (!s.road.empty()) {
			cout << s.revMap[s.road.top()] << " ";
			s.road.pop();
		}
	}
	
	//s.show();
	//s.showList();


	cout << "\n \n program ended";
	
	return 0;
}










//LinkedList<Pair> t ;
//Pair x(1000, 2000);
//t.add(x);
//s.g.push_back(t);
//s.g.at(0).add(x);
//cout<<"value of first Linked at index 0 : " << s.g.at(0).get(0).v <<"\n";
//cout << (s.get(2)).v;
//s.show();
//s.add("0", "1", 2);
/*s.add("0", "2", 3);
s.add("1", "2", 10);
s.add("1", "3", 2);
s.add("2", "3", 4);
s.add("3", "4", 6);
s.add("3", "5", 1);
s.add("4", "5", 10);*/
