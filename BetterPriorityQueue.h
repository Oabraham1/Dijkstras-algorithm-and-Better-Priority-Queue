#ifndef BETTERPRIORITYQUEUE_H
#define BETTERPRIORITYQUEUE_H

#include <queue>
#include "Graph.h"
#include <string>
#include <vector>
#include <string>
#include <climits>

using namespace std;

struct DNode {
	int pri = INT_MAX;
	bool visited = false;
	const GraphNode *node = nullptr;
	
	bool operator<(const DNode &other) const {
		return pri < other.pri;
	}

	bool operator>(const DNode &other) const {
		return pri > other.pri;
	}
	
	bool operator==(const DNode &other) const {
		return node == other.node;
	}
};




class BetterPriorityQueue: public priority_queue<DNode, vector<DNode>, greater<DNode>>::priority_queue 
{ 
    // ... your code goes here ...
    public:
        string ToString();
        int Contains(DNode dn);
        bool Update(DNode dn);
        static string DnodeToString(DNode dn);
};

#endif