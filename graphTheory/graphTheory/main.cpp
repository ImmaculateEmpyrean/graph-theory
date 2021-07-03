#include<iostream>
#include<vector>
#include<string>

#include<stack>
#include<queue>
#include<optional>
#include<utility>

//topological sorting

struct node {
	char name;
	std::vector<node*> neighbours;
	bool visited = false;
};
node* a = new node{ 'a',std::vector<node*>() };
node* b = new node{ 'b',std::vector<node*>() };
node* c = new node{ 'c',std::vector<node*>() };
node* d = new node{ 'd',std::vector<node*>() };
node* e = new node{ 'e',std::vector<node*>() };
node* f = new node{ 'f',std::vector<node*>() };
node* g = new node{ 'g',std::vector<node*>() };
node* h = new node{ 'h',std::vector<node*>() };
node* i = new node{ 'i',std::vector<node*>() };
node* j = new node{ 'j',std::vector<node*>() };
node* k = new node{ 'k',std::vector<node*>() };
node* l = new node{ 'l',std::vector<node*>() };
node* m = new node{ 'm',std::vector<node*>() };


std::stack<node*> topologicalSort(node* start)
{
	static std::stack<node*> sortedNodes;
	if (start->visited == false)
	{
		start->visited = true;

		for (node* neighbour : start->neighbours)
		{
			if (neighbour->visited == false)
			{
				topologicalSort(neighbour);
			}
		}

		sortedNodes.push(start);
		return sortedNodes;
	}
	else return sortedNodes;
}

void constructGraph(){
	a->neighbours.emplace_back(d);

	b->neighbours.emplace_back(d);

	c->neighbours.emplace_back(a);
	c->neighbours.emplace_back(b);

	d->neighbours.emplace_back(h);
	d->neighbours.emplace_back(g);

	e->neighbours.emplace_back(a);
	e->neighbours.emplace_back(d);
	e->neighbours.emplace_back(f);

	f->neighbours.emplace_back(k);
	f->neighbours.emplace_back(j);

	g->neighbours.emplace_back(i);

	h->neighbours.emplace_back(j);
	h->neighbours.emplace_back(i);

	i->neighbours.emplace_back(l);

	j->neighbours.emplace_back(m);
	j->neighbours.emplace_back(l);

	k->neighbours.emplace_back(j);
}


int main() {
	constructGraph();
	
	//instead of randomly taking a starting point and checking if all nodes are accounted 
	//for after each iteration.. I simply decided to run topological sort n times 
	//the state between each call is being saved.. making the function useless when more than one graph has to be worked 
	//this was more efficient for the representation I used to represent the graph in memory
	topologicalSort(a);
	topologicalSort(b);
	topologicalSort(c);
	topologicalSort(d);
	topologicalSort(e);
	topologicalSort(f);
	topologicalSort(g);
	topologicalSort(h);
	topologicalSort(i);
	topologicalSort(j);
	topologicalSort(k);
	topologicalSort(l);
	auto result = topologicalSort(m);

	while (!result.empty()) {
		std::cout << result.top()->name << " ";
		result.pop();
	}
}