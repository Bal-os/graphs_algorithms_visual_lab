#pragma once
#include <set>
#include "graph.h"

typedef std::vector<std::pair<std::pair<Node*, Node*>, long long> > result_vector;

class GrapgAlgo
{
private:
	const long long MAX_COST = 500;
	const long long MIN_COST = -MAX_COST;
	long long rnd() const;
	Node* randNode(int width, int height) const;
	void dfsAlgo(Graph* G, int num, std::vector<bool>& used, result_vector& r);
private:
	const double STANDART_RADIUS = 5;
public:
	result_vector dfs(Graph*, Node*);
	result_vector bfs(Graph*, Node*);
	result_vector prima(Graph*, Node*);
	result_vector dijkstra(Graph*, Node*);
	Graph generateComponent(int size, int width, int height, double probality);
	GrapgAlgo() = default;
	~GrapgAlgo() = default;
};

