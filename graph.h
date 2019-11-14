#pragma once
#include <vector>
#include"Node.h"

class Graph
{
private:
	bool numbered = true;
	bool oriented = false;
	void resize(int size);
	void renumerate();
	void addEdge(int XNum, int YNum, long long cost);
public:
	void addNode(Node*);
	void addEdge(const Node*,const Node*, long long cost = 0);
	std::vector<Node*> Nodees;
	std::vector < std::vector<int> > edges;
	std::vector< std::vector<long long> > costs;
	Graph();
	Graph(int size);
    Graph(int size, bool oriented);
	~Graph() = default;
};

