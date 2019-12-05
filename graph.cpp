#include "graph.h"
using namespace std;

void Graph::renumerate(){
	for (int i = 0; i < Nodees.size(); ++i)
		Nodees[i]->setNum(i);
}

void Graph::resize(int size){
	edges.assign(size, vector<int>());
	costs.assign(size, vector<long long>());
	Nodees.assign(size, nullptr);
	for (size_t i = 0; i < size; ++i)Nodees[i] = new Node(0, 0);
	renumerate();
}

void Graph::deleteNode(int num) {
	for (size_t i = 0; i < edges.size(); ++i) {
		for (size_t j = 0; j < edges[i].size(); ++j) {
			if (edges[i][j] == num) {
				edges[i].erase(edges[i].begin() + j);
				costs[i].erase(costs[i].begin() + j);
				break;
			}
		}
	}
	for (size_t i = num; i + 1 < Nodees.size(); ++i) {
		Nodees[i] = Nodees[i + 1];
		costs[i] = costs[i + 1];
		edges[i] = edges[i + 1];
	}

	Nodees.pop_back();
	costs.pop_back();
	edges.pop_back();
	for (size_t i = 0; i < edges.size(); ++i) {
		for (int& j : edges[i])
			if (j >= num) j--;
	}

	renumerate();
}

void Graph::deleteNode(const Node* X) {
	deleteNode(X->getNum());
}

void Graph::addNode(Node* X){
	Nodees.push_back(X);
	edges.push_back({});
	costs.push_back({});
	renumerate();
}

void Graph::deleteEdge(int x, int y) {
	for (size_t i = 0; i < edges[x].size(); ++i)
		if (edges[x][i] == y) {
			edges[x].erase(edges[x].begin() + i);
			costs[x].erase(costs[x].begin() + i);
		}
	if (!oriented) {
		for (size_t i = 0; i < edges[y].size(); ++i)
			if (edges[y][i] == x) {
				edges[y].erase(edges[y].begin() + i);
				costs[y].erase(costs[y].begin() + i);
			}
	}
}
void Graph::deleteEdge(const Node* X, const Node* Y) {
	deleteEdge(X->getNum(), Y->getNum());
}

void Graph::addEdge(int XNum, int YNum, long long cost) {
	for (const int& nm : edges[XNum]) {
		if (nm == YNum) return;
	}
	edges[XNum].push_back(YNum);
	costs[XNum].push_back(cost);

	if (!oriented) {
		edges[YNum].push_back(XNum);
		costs[YNum].push_back(cost);
	}
}

void Graph::addEdge(const Node *X, const Node *Y, long long cost) {
	addEdge(X->getNum(), Y->getNum(), cost);
}

Graph::Graph(int size) {
	resize(size);
}

Graph::Graph() : Graph(0){
}

Graph::Graph(int size, bool oriented) : Graph(size) {
	this->oriented = oriented;
}

