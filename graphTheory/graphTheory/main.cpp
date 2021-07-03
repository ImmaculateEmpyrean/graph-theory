#include<iostream>
#include<string>
#include<queue>
#include<vector>

#include<optional>
#include<utility>

bool notRock(std::vector<int> rocks, int i) {
	for (auto rock : rocks) {
		if (rock == i)
			return false;
	}

	return true;
}

std::optional<std::vector<int>> shortestPath(int start, int end, std::vector<int> rocks, std::vector<std::vector<int>> adjacencyMatrix) {
	
	std::vector<int> visited = std::vector<int>(adjacencyMatrix.size(), 0);
	std::queue<std::pair<int,std::vector<int>>> visitationNodes;

	visitationNodes.push(std::make_pair(start,std::vector<int>()));
	visited[start] = 1;

	while (!visitationNodes.empty())
	{
		std::pair<int,std::vector<int>> processingNode = visitationNodes.front();
		visitationNodes.pop();

		if (processingNode.first == end)
		{
			processingNode.second.emplace_back(processingNode.first); //we no longer care about proper maintainence as the stack frame is destroyed by the return..
			return processingNode.second;
		}
			

		for (int i = 0; i < adjacencyMatrix[processingNode.first].size(); i++)
		{
			if (adjacencyMatrix[processingNode.first][i] == 1) {
				if (visited[i] == 0 && notRock(rocks,i))
				{
					visited[i] = 1;
					std::vector<int> history = processingNode.second;
					history.emplace_back(processingNode.first);
					visitationNodes.push(std::make_pair(i,history));
				}
			}
		}
	}

	return {};
}


int main() {
	std::vector<std::vector<int>> adjacencyMatrix = {
		std::vector<int>{0,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1}, //0
		std::vector<int>{1,0,1,-1,-1,1,-1,-1,-1,-1,-1,-1}, //1
		std::vector<int>{-1,1,0,1,-1,-1,1,-1,-1,-1,-1,-1}, //2
		std::vector<int>{-1,-1,1,0,-1,-1,-1,1,-1,-1,-1,-1}, //3
		std::vector<int>{1,-1,-1,-1,0,1,-1,-1,1,-1,-1,-1}, //4
		std::vector<int>{0,1,-1,-1,1,0,1,-1,-1,1,-1,-1},   //5
		std::vector<int>{-1,-1,1,-1,-1,1,0,1,-1-1,1-1},	   //6
		std::vector<int>{-1,-1,-1,1,-1,-1,1,0,-1,-1,-1,1}, //7
		std::vector<int>{-1,-1,-1,-1,1,-1,-1,-1,0,1,-1,-1}, //8
		std::vector<int>{-1,-1,-1,-1,-1,1,-1,-1,1,0,1,-1}, //9
		std::vector<int>{-1,-1,-1,-1,-1,-1,1,-1,-1,1,0,1}, //10
		std::vector<int>{-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,0}  //11
	};

	std::vector<int> rocks = std::vector<int>{ 5,6,8 };
	int start = 0;
	int end = 10;

	auto result = shortestPath(start, end, rocks, adjacencyMatrix);
	if (result.has_value()) {
		for (auto i : *result) {
			std::cout << i << " ";
		}
		std::cout << std::endl;
	}
}