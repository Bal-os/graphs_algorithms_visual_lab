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
	void setCost(int x, int y, long long cost);
	void addEdge(int XNum, int YNum, long long cost);
	int getCost(int x, int y) const;
public:
	void addNode(Node*);
	void addEdge(const Node*,const Node*, long long cost = 0);
	int getCost(const Node*, const Node*) const;
	void setCost(const Node* X, const Node* Y, long long cost);

	void deleteNode(const Node*);
	void deleteNode(int );
	void deleteEdge(int, int);
	void deleteEdge(const Node*, const Node*);
	std::vector<Node*> Nodees;
	std::vector < std::vector<int> > edges;
	std::vector< std::vector<long long> > costs;
	Graph();
	Graph(int size);
    Graph(int size, bool oriented);
	~Graph() = default;
};

