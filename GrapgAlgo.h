#pragma once
#include <set>
#include "graph.h"

class GrapgAlgo
{
private:
	const long long MAX_COST = 1000000000;
	const long long MIN_COST = -MAX_COST;
	void dfsAlgo(Graph* G, int num, std::vector<bool>& used, std::vector<std::pair<Vertex*, Vertex*> >& r);
public:
	std::vector<std::pair<Vertex*, Vertex*> > dfs(Graph*, Vertex*);
	std::vector<std::pair<Vertex*, Vertex*> > bfs(Graph*, Vertex*);
	std::vector<std::pair<std::pair<Vertex*, Vertex*>, long long> > prima(Graph*, Vertex*);
	std::vector<std::pair<std::pair<Vertex*, Vertex*>, long long> > dijkstra(Graph*, Vertex*);
	GrapgAlgo() = default;
	~GrapgAlgo() = default;
};

