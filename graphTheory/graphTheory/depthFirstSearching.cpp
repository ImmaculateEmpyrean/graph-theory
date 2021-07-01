#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

struct node {
public:
	node() 
		: 
		number(m_counter++),
		neighbours(std::vector<node*>()),
		visited(false)
	{}
private:
	static int m_counter;

public:
	int number = -999;
	std::vector<node*> neighbours;
	
	bool visited = false;
	int id = -1;


};

int node::m_counter = 0;

void dfs(node& current,int currentId) {

	//no point in processing a node already visited
	if (current.visited == true)
		return;

	//std::cout << current.number << " "; //print out the current node in processing
	current.visited = true;  //mark the current node as processed
	current.id = currentId;

	//perform dfs for all neighbours.. 
	for (auto neighbour : current.neighbours) {
		dfs(*neighbour,currentId);
	}

	return; //finish
}


int main() {
	//node* nodes = new node[18];
	std::vector<node> nodes;
	for (int i = 0; i < 18; i++) nodes.emplace_back(node());

	nodes[0].neighbours.emplace_back(&nodes[8]);
	
	nodes[1].neighbours.emplace_back(&nodes[5]);

	nodes[2].neighbours.emplace_back(&nodes[15]);
	nodes[2].neighbours.emplace_back(&nodes[9]);

	nodes[3].neighbours.emplace_back(&nodes[9]);

	nodes[4].neighbours.emplace_back(&nodes[0]);

	nodes[5].neighbours.emplace_back(&nodes[17]);
	nodes[5].neighbours.emplace_back(&nodes[16]);

	nodes[6].neighbours.emplace_back(&nodes[7]);
	nodes[6].neighbours.emplace_back(&nodes[11]);

	nodes[7].neighbours.emplace_back(&nodes[6]);
	nodes[7].neighbours.emplace_back(&nodes[11]);

	nodes[8].neighbours.emplace_back(&nodes[4]);
	nodes[8].neighbours.emplace_back(&nodes[14]);

	nodes[9].neighbours.emplace_back(&nodes[3]);

	nodes[10].neighbours.emplace_back(&nodes[15]);

	nodes[11].neighbours.emplace_back(&nodes[6]);
	nodes[11].neighbours.emplace_back(&nodes[7]);

	//12 goes no where

	nodes[13].neighbours.emplace_back(&nodes[0]);

	nodes[14].neighbours.emplace_back(&nodes[0]);
	nodes[14].neighbours.emplace_back(&nodes[13]);

	nodes[15].neighbours.emplace_back(&nodes[10]);
	nodes[15].neighbours.emplace_back(&nodes[2]);

	// 16 and 17 go nowhere

	for (int i = 0; i < 18; i++) {
		dfs(nodes[i], i);
	}

	std::sort(nodes.begin(), nodes.end(), [](node& a, node& b) {
		return a.id < b.id;
	});

	for (int i = 0; i < 18; i++) {
		std::cout << std::endl;	
		std::cout << "node : " << nodes[i].number << " id : " << nodes[i].id;
	}
}