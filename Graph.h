#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>


using namespace std;


struct GraphNode {
	char key;
	int data; // Not necessary / used for Dijkstra algorithm
};


struct GraphEdge {
	GraphNode *from;
	GraphNode *to;	
	unsigned int weight;
};


class Graph{
	
	public:
		~Graph();
	
		GraphNode *AddNode(char key, int data = 0);
		GraphEdge *AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight = 0);
		
		string NodesToString() const;
		string ToString() const;

		static string GraphNodeToString(const GraphNode *gn);
		static string GraphEdgeToString(const GraphEdge *ge);
		
		
		const vector<GraphEdge*>& GetEdges(const GraphNode *gn) const;
		const vector<GraphNode*>& GetNodes() const;
		const GraphNode* NodeAt(unsigned int idx) const;
		size_t Size() const;
		

	private:
		// Your code goes here!
		vector<vector<GraphEdge*>> adjacencyMatrix;
		vector<GraphNode*> nodeList;
};

#endif