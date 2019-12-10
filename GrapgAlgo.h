#pragma once
#include <set>
#include <cmath>
#include "graph.h"

typedef std::vector<std::pair<std::pair<Node*, Node*>, long long> > result_vector;

class GrapgAlgo
{
private:
	const long long MAX_COST = 500;
	const long long MIN_COST = -MAX_COST;
	const long long INF_FLOW = 100000000;
	long long rnd() const;
	Node* randNode(int width, int height) const;
	void dfsAlgo(Graph* G, int num, std::vector<bool>& used, result_vector& r);
	long long findFlow(Graph *g, int X, long long flow, std::vector<bool>& visited, std::vector<int>* inv, int* sz, result_vector& cur, int Y);
private:
	const double STANDART_RADIUS = 5;
public:
	result_vector dfs(Graph*, Node*);
	result_vector bfs(Graph*, Node*);
	result_vector prima(Graph*, Node*);
	result_vector dijkstra(Graph*, Node*);
	result_vector ford_fulkerson(Graph*, Node*, Node*);
	Graph generateComponent(int size, int width, int height, double probality);
	GrapgAlgo() = default;
	~GrapgAlgo() = default;
};

