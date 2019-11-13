#include "GrapgAlgo.h"

using namespace std;

void GrapgAlgo::dfsAlgo(Graph* G, int num, std::vector<bool>& used, std::vector<std::pair<Vertex*, Vertex*>>& r){
	used[num] = true;
	for (auto j : G->edges[num])
	{
		if (!used[j])
			r.push_back({ G->vertexes[num], G->vertexes[j] });
			dfsAlgo(G, j, used, r);
	}
}

std::vector<std::pair<Vertex*, Vertex*>> GrapgAlgo::dfs(Graph* G, Vertex* X)
{
	vector<pair<Vertex*, Vertex*> > r;
	vector<bool> used(G->vertexes.size(), false);
	r.push_back({ nullptr, X });
	dfsAlgo(G, (X->getNum()), used, r);
	return r;
}

vector<pair<Vertex*, Vertex*> > GrapgAlgo::bfs(Graph* G,Vertex* X) {
	vector<pair<Vertex*, Vertex*> > r;
	vector<bool> used(G->vertexes.size(), false);
	vector<size_t> q;
	vector<int> pr(G->vertexes.size(), 0);
	r.push_back({ nullptr, X });
	used[X->getNum()] = true;
	q.push_back(X->getNum());

	while (!q.empty()) {
		size_t& i = *(q.begin());
		q.pop_back();
		if ((int)i != X->getNum())
			r.push_back({ G->vertexes[pr[i]], G->vertexes[i] });
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

std::vector<std::pair<std::pair<Vertex*, Vertex*>, long long>> GrapgAlgo::prima(Graph* G, Vertex* X)
{
	vector<pair<pair<Vertex*, Vertex*>, long long> > res;
	res.push_back({ {X, X}, 0 });
	set<pair<long long, pair<int, int> > > ed;
	vector<bool> used(G->vertexes.size(), false);

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
		res.push_back({ {G->vertexes[XNum], G->vertexes[YNum]}, sum });

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

std::vector<std::pair<std::pair<Vertex*, Vertex*>, long long>> GrapgAlgo::dijkstra(Graph* G, Vertex* X)
{
	vector<pair<pair<Vertex*, Vertex*>, long long> > res;
	res.push_back({ {X, X}, 0 });
	int N = G->vertexes.size();

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
				res.push_back({ {G->vertexes[XNum], G->vertexes[j]}, dist[j] });
				st.insert({ dist[j], j });
			}
		}
	}

	return res;
}
