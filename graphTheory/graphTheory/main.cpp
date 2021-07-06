#include "DAG.h"
//shortest and longest path in a dag

int main()
{
	DAG tDag;

	tDag.addNode('a');
	tDag.addNode('b');
	tDag.addNode('c');
	tDag.addNode('d');
	tDag.addNode('e');
	tDag.addNode('f');
	tDag.addNode('g');
	tDag.addNode('h');
	tDag.addNode('i');
	tDag.addNode('j');
	tDag.addNode('k');
	tDag.addNode('l');
	tDag.addNode('m');

	tDag['a']->neighbours.emplace_back(tDag['d']);

	tDag['b']->neighbours.emplace_back(tDag['d']);

	tDag['c']->neighbours.emplace_back(tDag['a']);
	tDag['c']->neighbours.emplace_back(tDag['b']);

	tDag['d']->neighbours.emplace_back(tDag['h']);

	tDag['e']->neighbours.emplace_back(tDag['a']);
	tDag['e']->neighbours.emplace_back(tDag['f']);
	tDag['e']->neighbours.emplace_back(tDag['d']);

	tDag['f']->neighbours.emplace_back(tDag['k']);
	tDag['f']->neighbours.emplace_back(tDag['j']);

	tDag['g']->neighbours.emplace_back(tDag['i']);
	
	tDag['h']->neighbours.emplace_back(tDag['j']);
	tDag['h']->neighbours.emplace_back(tDag['i']);

	tDag['i']->neighbours.emplace_back(tDag['l']);

	tDag['j']->neighbours.emplace_back(tDag['l']);
	tDag['j']->neighbours.emplace_back(tDag['m']);

	tDag['k']->neighbours.emplace_back(tDag['j']);

	auto vec = tDag.topSort();

	for (auto& i : vec)
	{
		std::cout << (char)i->name << " ";
	}
}