#include<iostream>
#include<algorithm>

#include<vector>
#include<queue>
#include<string>

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
void bfs(node& current)
{
	std::queue<node*> nodeList; //queue to keep track of where I am
	nodeList.push(&current);
	current.visited = true;

	while (nodeList.size() > 0) {
		node* current = nodeList.front();
		nodeList.pop();

		std::cout << current->number << " ";

		for (node* neighbour : current->neighbours) {
			if (neighbour->visited == false) {
				nodeList.push(neighbour);
				neighbour->visited = true;
			}
				
		}
	}
}


int main() {
	std::vector<node> nodes;
	for (int i = 0; i < 13; i++) nodes.emplace_back(node());

	nodes[0].neighbours.emplace_back(&nodes[9]);
	nodes[0].neighbours.emplace_back(&nodes[7]);
	nodes[0].neighbours.emplace_back(&nodes[11]);

	nodes[1].neighbours.emplace_back(&nodes[10]);
	nodes[1].neighbours.emplace_back(&nodes[8]);

	nodes[2].neighbours.emplace_back(&nodes[12]);
	nodes[2].neighbours.emplace_back(&nodes[3]);

	nodes[3].neighbours.emplace_back(&nodes[7]);
	nodes[3].neighbours.emplace_back(&nodes[2]);
	nodes[3].neighbours.emplace_back(&nodes[4]);

	nodes[4].neighbours.emplace_back(&nodes[3]);

	nodes[5].neighbours.emplace_back(&nodes[6]);

	nodes[6].neighbours.emplace_back(&nodes[7]);
	nodes[6].neighbours.emplace_back(&nodes[5]);

	nodes[7].neighbours.emplace_back(&nodes[0]);
	nodes[7].neighbours.emplace_back(&nodes[3]);
	nodes[7].neighbours.emplace_back(&nodes[6]);
	nodes[7].neighbours.emplace_back(&nodes[11]);

	nodes[8].neighbours.emplace_back(&nodes[9]);
	nodes[8].neighbours.emplace_back(&nodes[1]);
	nodes[8].neighbours.emplace_back(&nodes[12]);

	nodes[9].neighbours.emplace_back(&nodes[10]);
	nodes[9].neighbours.emplace_back(&nodes[8]);
	nodes[9].neighbours.emplace_back(&nodes[0]);

	nodes[10].neighbours.emplace_back(&nodes[1]);
	nodes[10].neighbours.emplace_back(&nodes[9]);

	nodes[11].neighbours.emplace_back(&nodes[0]);
	nodes[11].neighbours.emplace_back(&nodes[7]);

	nodes[12].neighbours.emplace_back(&nodes[8]);
	nodes[12].neighbours.emplace_back(&nodes[2]);

	bfs(nodes[0]);
}