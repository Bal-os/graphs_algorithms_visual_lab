#pragma once
#include "Button.h"
class GraphGraphic
{
private:
	Graph graph;
	GrapgAlgo algoritms;
	Node* prev;
	Node* thisNode;
	std::vector<std::pair<std::pair<Node*, Node*>, long long> > cur;
	int pos = -1;
	bool isThisMove = false;
	bool isPrevMove = false;
public:
	GraphGraphic();
	~GraphGraphic();
};

