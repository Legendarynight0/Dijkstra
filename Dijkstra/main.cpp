#include "C:\Users\omar_\source\repos\Dijkstra\Dijkstra\Graph.h"

int main() {
	Graph s;
	s.add("cairo", "alex", 45);
	s.add("alex", "luxor", 10);
	s.add("luxor", "cairo", 3);
	for (int i = 0; i < s.g.size(); i++){
		cout << "Vertex number: " << s.revMap[i] << "\n";
		for (int j = 0; j < s.g[i].size; j++){
			cout << s.revMap[s.g.at(i).get(j).v] << " and the weight is: " << s.g.at(i).get(j).w << "\n";
		}

	}
	cout << "seccusse";
	
	
	
	
	
	
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