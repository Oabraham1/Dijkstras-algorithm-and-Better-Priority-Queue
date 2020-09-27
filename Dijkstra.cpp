

#include "Graph.h"
#include "BetterPriorityQueue.h"
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

/*
 * This method implements the Dijkstra's algortihm 
 * This algorithm finds the shortest distance travelling from a node on a graph to another node
 * This function uses our already-implemented BetterPriorityQueue
*/
int dijkstra(const GraphNode *start, const GraphNode *end, Graph *g){\

	vector<GraphNode*> nodes = g->GetNodes(); //This returns a vector of the nodes of the graph
	BetterPriorityQueue *q = new BetterPriorityQueue();
	// your code goes here

	for(unsigned int i = 0; i < nodes.size(); i++){
		DNode dn;
		dn.node = nodes.at(i);
		if((dn.node == start)){ //This checks if the node is out start and if it is, it sets the priority to 0
			dn.pri = 0;
			q->push(dn);
		}

		else{
			dn.pri = INT_MAX;
			q->push(dn);
		}
	}


	int distance = 0;

	/*
	 * This part gets all of the edges of the node that is on top of the priority queue and updates the priority of its neigbors in the queue
	 * with the shortest weight
	 * This helps us always maintain the shortest distance for our Dijkstra's algorithm
	 * The overall complexity of this function is O((E*V)Log(V))
	*/
	while(!q->empty()){ //O(N) where N is the size of the queue which is also the number of vertices V
		DNode dn = q->top();
		vector<GraphEdge*> ge = g->GetEdges(dn.node);
		q->pop();  //O(Log(V)) where V is the number of vertices in the graph. This happens in O(Log(V)) because the priority queue is a binary heap which re-adjusts when the top element is popped
		cout << q->DnodeToString(dn) << endl;

		for(unsigned int i = 0; i < ge.size(); i++){ //O(E) where E is the maximum number of Edges
			DNode df;
			df.pri = ge.at(i)->weight + dn.pri;
			df.node = ge.at(i)->to;
			q->Update(df); //O(Log(V)) where V is the number of vertices in the graph. This happens in O(Log(V)) because the priority queue is a binary heap which re-adjusts when the update is called
		}
		
		distance = dn.pri;

	}

	

	if(distance == INT_MAX){
		cout << "No path between Nodes" << endl;
		return -1;
	}
	

	delete q;

	return distance;
}


int DijkstraTest(){
	// Note, when grading I will replace this with
	// other / more tests.  I recommend you do the same!
	
	Graph *g = new Graph();
	
	GraphNode *a = g->AddNode('1');
	GraphNode *b = g->AddNode('2');
	GraphNode *c = g->AddNode('3');
	GraphNode *d = g->AddNode('4');
	GraphNode *e = g->AddNode('5');
	GraphNode *f = g->AddNode('6');
	
	g->AddEdge(a, b, 7);
	g->AddEdge(b, a, 7);
	g->AddEdge(a, c, 9);
	g->AddEdge(c, a, 9);
	g->AddEdge(a, f, 14);
	g->AddEdge(f, a, 14);
	
	g->AddEdge(b, c, 10);
	g->AddEdge(c, b, 10);
	g->AddEdge(b, d, 15);
	g->AddEdge(d, b, 15);
	
	g->AddEdge(c, f, 2);
	g->AddEdge(f, c, 2);
	g->AddEdge(c, d, 11);
	g->AddEdge(d, c, 11);
	
	g->AddEdge(f, e, 9);
	g->AddEdge(e, f, 9);
	
	g->AddEdge(d, e, 6);
	g->AddEdge(e, d, 6);
	
	
	cout << g->ToString() << endl;
	
	unsigned int ans = dijkstra(g->NodeAt(0), e, g);
	assert(ans == 20);

	delete g;
		
	return ans;
}


int main(){
	
	int ans = DijkstraTest();
	cout << "ans: "  << ans << endl;
	
	return 0;
}