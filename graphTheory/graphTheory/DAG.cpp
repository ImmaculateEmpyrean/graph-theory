#include "DAG.h"
#include "utility.h"

/*DAG::DAG(std::vector<DAG::node> nodes)
{
	for (auto& n : nodes)
	{
		m_nodes[n.name] = std::move(n);
		m_nodesVector.emplace_back(&m_nodes[n.name]);
	}	
}*/
DAG::DAG(int number)
{
	for (int i = 0; i < number; i++)
		addNode(i);
}
DAG::node::node(int name)
	: name(name)
{
	neighbours = std::vector<node*>();
}


void DAG::addNode(DAG::node n)
{
	auto name = n.name;
	int index = m_nodesVector.size();
	n.setIndex(index);
	
	m_nodes.insert(std::make_pair(name, std::move(n)));
	auto casket = m_nodes.find(name);
	m_nodesVector.emplace_back(&casket->second);
}
void DAG::addNode(int name)
{
	DAG::node nd(name);
	addNode(nd);
}

DAG::node* DAG::operator[](int name)
{
	auto casket = m_nodes.find(name);
	if (casket == m_nodes.end())
	{
		std::cout << "error finding the node of given name : " << name <<" Line Number : "<< __LINE__ << std::endl;
		return nullptr;
	}
	else return &casket->second;
}
DAG::node* DAG::getNode(int name)
{
	return this->operator[](name);
}


std::vector<DAG::node*> DAG::topSort() 
{
	tempVector.clear();
	visited = std::vector<int>(m_nodesVector.size(), 0);
	
	std::vector<node*> topSort;

	while (topSort.size() < m_nodesVector.size())
	{
		int startNumber = random(0, m_nodesVector.size() - 1);
		if (visited[startNumber] != 1)
		{
			auto result = dfs(m_nodesVector[startNumber]);
			for (auto ele : result)
				topSort.insert(topSort.begin(), ele);
		}	
	}

	return topSort;
}


std::vector<DAG::node*> DAG::dfs(int name)
{
	auto nod = m_nodes.find(name);
	if (nod == m_nodes.end())
		return std::vector<DAG::node*>();

	node* startNode = &nod->second;
	
	
	
	//tempVector.clear();
	//visited = std::vector<int>(m_nodesVector.size(), 0);




	//return dfsHelper(startNode);
}


std::vector<DAG::node*> DAG::dfs(node* n,std::vector<int> visited)
{
	if (visited.size() <= n->getIndex())
	{
		std::vector<DAG::node*> result;
		for (node* neighbour : n->neighbours)
		{
			auto res = dfs(neighbour, visited);
			for (auto r : res)
				result.emplace_back(res);
		}
		result.insert(result.begin(), n);
		return result;
	}
}




/*std::vector<DAG::node*> DAG::dfsHelper(DAG::node* n)
{
	visited[n->getIndex()] = 1;

	for (node* neighbour : n->neighbours)
	{
		if (visited[neighbour->getIndex()] == 0)
			dfsHelper(neighbour);			
	}
		
	tempVector.emplace_back(n);
	return tempVector;
}*/