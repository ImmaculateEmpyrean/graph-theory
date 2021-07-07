#include "DAG.h"
#include "utility.h"

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

bool flag = true;
std::vector<DAG::node*> DAG::topSort() 
{
	std::vector<node*> topSort;
	visited.resize(m_nodesVector.size(), 0);

	while (topSort.size() < m_nodesVector.size())
	{
		int startNumber = random(0, m_nodesVector.size() - 1);
		if (visited[startNumber] != 1)
		{
			auto result = dfs(m_nodesVector[startNumber],flag);
			flag = false;
			for (auto ele : result)
			{
				topSort.insert(topSort.begin(), ele);
				visited[ele->getIndex()] = 1;
			}			
		}	
	}

	flag = true; //next time dfs is invoked.. better clean the provided array provided by the main.. 
	return topSort;
}


void DAG::initializeDfs()
{
	visited.clear();
	visited.resize(m_nodesVector.size(), 0);
}
std::vector<DAG::node*> DAG::dfs(int startName)
{
	auto nod = m_nodes.find(startName);
	if (nod == m_nodes.end())
		return std::vector<DAG::node*>();

	node* startNode = &nod->second;
	
	return dfs(startNode,true);
}
std::vector<DAG::node*> DAG::dfs(node* n,bool initialize)
{ 
	if (initialize == true)
		initializeDfs();

	visited[n->getIndex()] = 1;

	std::vector<DAG::node*> result;
	for (node* neighbour : n->neighbours)
	{
		if (visited[neighbour->getIndex()] == 0)
		{
			std::vector<node*> res = dfs(neighbour,false);
			for (node* i : res)
				result.emplace_back(i);
		}
	}
	result.emplace_back(n);
	return result;	
}

std::vector<DAG::node*> DAG::bfs(int startName)
{
	auto casket = m_nodes.find(startName);
	if (casket == m_nodes.end())
	{
		std::cout << "node : " << startName << " not found.. error in line : " << __LINE__
			<< " in file : " << __FILE__ << std::endl;
		return std::vector<DAG::node*>();
	}
	return DAG::bfs(&casket->second);
}
std::vector<DAG::node*> DAG::bfs(DAG::node* n)
{
	std::vector<int> visited = std::vector<int>(m_nodesVector.size(), 0);
	std::queue<node*> nodalQueue;
	std::vector<node*> result;

	visited[n->getIndex()] = 1;
	nodalQueue.push(n);

	while (nodalQueue.size() != 0)
	{
		node* current = nodalQueue.front();
		result.emplace_back(current);
		nodalQueue.pop();

		for (node* neighbour : current->neighbours)
		{
			if (visited[neighbour->getIndex()] == 0)
			{
				visited[neighbour->getIndex()] = 1;
				nodalQueue.push(neighbour);
			}
		}
	}

	return result;
}