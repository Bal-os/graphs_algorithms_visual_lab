#pragma once
#include <set>
#include "graph.h"

class GrapgAlgo
{
private:
	const long long MAX_COST = 1000000000;
	const long long MIN_COST = -MAX_COST;
	void dfsAlgo(Graph* G, int num, std::vector<bool>& used, std::vector<std::pair<Node*, Node*> >& r);
public:
	std::vector<std::pair<Node*, Node*> > dfs(Graph*, Node*);
	std::vector<std::pair<Node*, Node*> > bfs(Graph*, Node*);
	std::vector<std::pair<std::pair<Node*, Node*>, long long> > prima(Graph*, Node*);
	std::vector<std::pair<std::pair<Node*, Node*>, long long> > dijkstra(Graph*, Node*);
	GrapgAlgo() = default;
	~GrapgAlgo() = default;
};

