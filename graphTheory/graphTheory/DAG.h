#pragma once

#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>

#include<utility>
#include<optional>

class DAG
{
public:
	struct node
	{
		node() = delete;
		node(int name);

		int name;
		std::vector<node*> neighbours;
		
		int	 getIndex()			 { return m_index;  }
		void setIndex(int index) { m_index = index; }
	
	private:
		int m_index = -1;
	};

	DAG() = default;
	DAG(int number);
	//DAG(std::vector<node> nodes);
	
public:
	node* operator[](int name);
	
	node* getNode(int name);
	void  addNode(node n);
	void  addNode(int name);

	std::vector<node*> topSort();
	
	std::vector<node*> dfs(int startName);
	std::vector<node*> dfs(node* n, std::vector<int> visited = std::vector<int>());

	//std::vector<node*> bfs(int startName);

private:
	//std::vector<node*> dfsHelper(node* n);

private:
	std::unordered_map<int, node> m_nodes;
	std::vector<node*> m_nodesVector;

	std::queue<node*> tempQueue;

	std::vector<node*> tempVector;
	std::vector<int> visited;
};