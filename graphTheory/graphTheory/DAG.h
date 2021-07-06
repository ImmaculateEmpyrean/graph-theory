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
	
public:
	node* operator[](int name);
	
	node* getNode(int name);
	void  addNode(node n);
	void  addNode(int name);

	std::vector<node*> topSort();
	
	void initializeDfs();
	std::vector<node*> dfs(int startName);
	std::vector<node*> dfs(node* n, bool initialize = true);

	//std::vector<node*> bfs(int startName);

private:
	std::unordered_map<int, node> m_nodes;
	std::vector<node*> m_nodesVector;

	std::vector<int> visited;
};