#include<iostream>
#include<vector>
#include<string>

struct node {
public:
	int number;
	std::vector<node*> neighbours;
	
	bool visited = false;
};

void dfs(node current) {

	//no point in processing a node already visited
	if (current.visited == true)
		return;

	std::cout << current.number << " "; //print out the current node in processing
	current.visited = true;  //mark the current node as processed

	//perform dfs for all neighbours.. 
	for (auto neighbour : current.neighbours) {
		dfs(*neighbour);
	}

	return; //finish
}


int main() {
	node* one = new node{ 1,std::vector<node*>() };
	node* two = new node{ 2,std::vector<node*>() };
	node* three = new node{ 3, std::vector<node*>() };

	node* four = new node{ 4, std::vector<node*>{three} };
	node* zero = new node{ 0, std::vector<node*>{one,two,four} };

	dfs(*zero);
}