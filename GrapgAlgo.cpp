#include "GrapgAlgo.h"

using namespace std;

void GrapgAlgo::dfsAlgo(Graph* G, int num, std::vector<bool>& used, result_vector& r){
	used[num] = true;
	for (auto j : G->edges[num])
	{
		if (!used[j])
			r.push_back({{ G->Nodees[num], G->Nodees[j] }, 0});
			dfsAlgo(G, j, used, r);
	}
}

result_vector GrapgAlgo::dfs(Graph* G, Node* X)
{
	result_vector r;
	vector<bool> used(G->Nodees.size(), false);
	r.push_back({ { nullptr, X }, 0});
	dfsAlgo(G, (X->getNum()), used, r);
	return r;
}

result_vector GrapgAlgo::bfs(Graph* G,Node* X) {
	result_vector r;
	vector<bool> used(G->Nodees.size(), false);
	vector<size_t> q;
	vector<int> pr(G->Nodees.size(), 0);
	r.push_back({ { nullptr, X }, 0});
	used[X->getNum()] = true;
	q.push_back(X->getNum());

	while (!q.empty()) {
		size_t& i = *(q.begin());
		q.pop_back();
		if ((int)i != X->getNum())
			r.push_back({ { G->Nodees[pr[i]], G->Nodees[i] }, 0});
		for (auto j : G->edges[i]) {
			if (!used[j]) {
				pr[j] = i;
				used[j] = true;
				q.push_back(j);
			}
		}
	}

	return r;
}

result_vector GrapgAlgo::prima(Graph* G, Node* X)
{
	vector<pair<pair<Node*, Node*>, long long> > res;
	res.push_back({ {X, X}, 0 });
	set<pair<long long, pair<int, int> > > ed;
	vector<bool> used(G->Nodees.size(), false);

	int XNum = X->getNum();
	int YNum;
	used[XNum] = true;
	for (size_t i = 0; i < G->edges[XNum].size(); ++i) {
		ed.insert({ G->costs[XNum][i], {XNum, G->edges[XNum][i]} });
	}

	long long sum = 0;
	while (ed.size() > 0) {
		XNum = ed.begin()->second.first;
		YNum = ed.begin()->second.second;
		used[YNum] = true;

		sum += ed.begin()->first;
		ed.erase(ed.begin());
		res.push_back({ {G->Nodees[XNum], G->Nodees[YNum]}, sum });

		for (size_t i = 0; i < G->edges[YNum].size(); ++i) {
			int j = G->edges[YNum][i];
			if (used[j]) {
				ed.erase({ G->costs[YNum][i], {j, YNum} });
			}
			else {
				ed.insert({ G->costs[YNum][i], {YNum, j} });
			}
		}

	}

	return res;
}

result_vector GrapgAlgo::dijkstra(Graph* G, Node* X)
{
	result_vector res;
	res.push_back({ {X, X}, 0 });
	int N = G->Nodees.size();

	vector<long long> dist(N, N * MAX_COST);
	set<pair<long long, int > > st;

	int XNum = X->getNum();
	dist[XNum] = 0;

	st.insert({ dist[XNum], XNum });
	while (st.size() > 0) {
		XNum = st.begin()->second;
		st.erase(st.begin());
		for (size_t i = 0; i < G->edges[XNum].size(); ++i) {
			int j = G->edges[XNum][i];
			int cost = G->costs[XNum][i];
			if (dist[j] > dist[XNum] + cost) {
				st.erase({ dist[j], j });
				dist[j] = dist[XNum] + cost;
				res.push_back({ {G->Nodees[XNum], G->Nodees[j]}, dist[j] });
				st.insert({ dist[j], j });
			}
		}
	}
	return res;
}

long long GrapgAlgo::findFlow(Graph *g, int X, long long flow, vector<bool>& visited, vector<int>* inv, int* sz, result_vector& cur, int Y) {
	if (X == Y) return flow;
	visited[X] = true;
	for (size_t i = 0; i < g->edges[X].size(); ++i) {
		int to = g->edges[X][i];
		if (!visited[to] && g->costs[X][i] > 0) {
			int minResult = findFlow(g, to, min(flow, g->costs[X][i]), visited, inv, sz, cur, Y);
			if (minResult > 0) {
				int invers = inv[X][i];

				g->costs[X][i] -= minResult;
				g->costs[to][invers] += minResult;
				if (i < sz[X]) {
					cur.push_back({ {g->Nodees[X], g->Nodees[to]}, -minResult });
				}
				else if (invers < sz[to]) {
					cur.push_back({ {g->Nodees[to], g->Nodees[X]}, minResult });
				}

				return minResult;
			}
		}
	}
	return 0;
}

result_vector GrapgAlgo::ford_fulkerson(Graph* G, Node* X, Node* Y) {
	size_t N = static_cast<size_t>(G->Nodees.size());
	int *sz = new int [N];
	vector<int> *inv = new vector<int> [N];
	for (int i = 0; i < N; ++i) {
		sz[i] = G->edges[i].size();
		inv[i].resize(sz[i]);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < sz[i]; ++j) {
			int to = G->edges[i][j];
			inv[i][j] = G->edges[to].size();
			inv[to].push_back(j);

			G->edges[to].push_back(i);
			G->costs[to].push_back(0);
		}
	}

	int maxFlow = 0;
	int iterationResult = 0;
	result_vector res;
	result_vector cur;

	vector<bool> visited(N, false);
	while ((iterationResult = findFlow(G, X->getNum(), INF_FLOW, visited, inv, sz, cur, Y->getNum())) > 0) {
		visited.assign(N, false);

		reverse(cur.begin(), cur.end());
		for (size_t i = 0; i < cur.size(); ++i)res.push_back(cur[i]);
		cur.clear();
		res.push_back({ {nullptr, nullptr}, iterationResult });
	}

	for (size_t i = 0; i < N; ++i) {
		while (G->edges[i].size() > sz[i]) G->edges[i].pop_back();
		while (G->costs[i].size() > sz[i]) G->costs[i].pop_back();
	}

	for (size_t i = 0; i < res.size(); ++i) {
		if (res[i].first.first) {
			G->setCost(res[i].first.first, res[i].first.second, G->getCost(res[i].first.first, res[i].first.second) - res[i].second);
		}
	}

	return res;
}

long long GrapgAlgo::rnd() const {
	long long r = rand();
	return (r << 15) + rand();
}

Node* GrapgAlgo::randNode(int width, int height) const {
	double x = rand() % (width + 1) ;
	double y = rand() % (height + 1);
	return new Node(x, y);
}

Graph GrapgAlgo::generateComponent(int size, int width, int height, double probality) {
	Graph graph;
	vector<Node*> component(size);
	for (size_t i = 0; i < component.size(); ++i) {
		component[i] = randNode(width - STANDART_RADIUS * 2, height - STANDART_RADIUS * 2);
		graph.addNode(component[i]);
	}
	for (size_t i = 0; i < component.size(); ++i) {
		for (size_t j = 0; j < component.size(); ++j) {
			if (i == j) continue;
			if (i > j) continue;
			if (rand() % 10001 < probality * 10000) {
				graph.addEdge(component[i], component[j], rnd() % (MAX_COST + 1));
			}
		}
	}
	return graph;
}