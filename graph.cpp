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

void Graph::addNode(Node* X){
	Nodees.push_back(X);
	edges.push_back({});
	costs.push_back({});
	renumerate();
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
