#pragma once
#include <set>
#include "graph.h"

typedef std::vector<std::pair<std::pair<Node*, Node*>, long long> > result_vector;

class GrapgAlgo
{
private:
	const long long MAX_COST = 1000000000;
	const long long MIN_COST = -MAX_COST;
	void dfsAlgo(Graph* G, int num, std::vector<bool>& used, result_vector& r);
public:
	result_vector dfs(Graph*, Node*);
	result_vector bfs(Graph*, Node*);
	result_vector prima(Graph*, Node*);
	result_vector dijkstra(Graph*, Node*);
	GrapgAlgo() = default;
	~GrapgAlgo() = default;
};

