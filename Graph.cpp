#include "Graph.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
 * This destructor iterates through the vector of nodes and 2D vector of edges and deallocates all of the dynamic memory used
 * It is important that this destructor is properly written to avoid memory leaks
*/

Graph::~Graph(){
    for(unsigned int i = 0; i < nodeList.size(); i++){
        delete (nodeList.at(i));
    }

    nodeList.clear();

    for(unsigned int i = 0; i < adjacencyMatrix.size(); i++){
        for(unsigned int j = 0; j < adjacencyMatrix.at(i).size(); j++){
            delete (adjacencyMatrix.at(i).at(j));

        }
        adjacencyMatrix.at(i).clear();
    }

    adjacencyMatrix.clear();

}

/*
 * This method creates a new GraphNode and adds it to the vector of GraphNodes
*/
GraphNode* Graph::AddNode(char key, int data){
    GraphNode *gn = new GraphNode();
    vector<GraphEdge*> temp;
    gn->key = key;
    gn->data = data;

    this->nodeList.push_back(gn);
    this->adjacencyMatrix.push_back(temp);
    
    return gn;
    
}

/*
 * This method creates a new GraphEdge that connects two nodes
 * These nodes are then stored in what is a 2D vector of GraphEdges were they are stored
 * based on the node where they connect from
 * This makes it easier to get an adjacency list of all of the nodes 
 * since the edges vector at every index simply connects nodes from the same origin
*/

GraphEdge* Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight){
    GraphEdge *ge = new GraphEdge();

    ge->from = gn1;
    ge->to = gn2;
    ge->weight = weight;

    for(unsigned int i = 0; i < nodeList.size(); i++){
        if(gn1->key == nodeList.at(i)->key){
            adjacencyMatrix.at(i).push_back(ge);
        }
    }

    return ge;
}

/*
 * This method returns a string representation of the distinct nodes of the graph
*/
string Graph::NodesToString() const{
    string result = "[";
    for(unsigned int i = 0; i < this->nodeList.size(); i++){
        result = result + "(" + this->nodeList.at(i)->key + ":" + to_string(this->nodeList.at(i)->data);
        if(i != this->nodeList.size()-1){
            result+="), ";
        }
        
        else{
            result += ")";
        }
    }
    
    result+="]";

    return result;
}


/*
 * This method returns a string representation of the entire graph, showing all of the different nodes and edges
 * It goes through the nodes vector to print each node and goes through the edges 2D vector to print the corresponding 
 * edges(if any) for that node
*/

string Graph::ToString() const{
    string result = "";

    for(unsigned int i = 0; i < nodeList.size(); i++){
        result = result + nodeList.at(i)->key + " | ";
        for(unsigned int j = 0; j < adjacencyMatrix.at(i).size(); j++){
            result = result + "[(" + adjacencyMatrix.at(i).at(j)->from->key + ":" + to_string(adjacencyMatrix.at(i).at(j)->from->data) + ")->(" + adjacencyMatrix.at(i).at(j)->to->key + ':' + to_string(adjacencyMatrix.at(i).at(j)->to->data) + ") w:" + to_string(adjacencyMatrix.at(i).at(j)->weight)+ "]";
            if(j != adjacencyMatrix.at(i).size()-1){
                result += ", ";
            }
        }
        result += "\n";
    } 

    return result;
}

/*
 * This method returns a string representation of any Graph node parsed into it
*/
string Graph::GraphNodeToString(const GraphNode *gn){
    string result = "(";
    result = result + gn->key + ":" + to_string(gn->data) + ")";

    return result;
}


/*
 * This method returns a string representation of the graph edge parsed into it
 * showing the different links between nodes, if ay
*/
string Graph::GraphEdgeToString(const GraphEdge *ge){
    string result = "[(";
    result = result + ge->from->key + ":" + to_string(ge->from->data) +") -> (" + ge->to->key + ":" + to_string(ge->to->data) + ")" + " w:" + to_string(ge->weight) + "]" ;

    return result;
}

/*
 * This method goes through the entire graph and get all of the edges and returns those edges
*/
const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn)const{
    unsigned int index;
    for(unsigned int i = 0; i < nodeList.size(); i++){
        if(gn->key == nodeList.at(i)->key){
            index = i;
        }
    }
    return adjacencyMatrix.at(index);
}

/*
 * This method returns a vector of all of the Nodes of the Graph
*/
const vector<GraphNode*>& Graph::GetNodes() const{
    return nodeList;
}

/*
 * This method returns a graphNode at a particular index
 * Since all of the nodes are stored in a vector, of nodes, the node at that index is returned
*/
const GraphNode* Graph::NodeAt(unsigned int idx) const{
    if(idx >= this->nodeList.size()){
        cout << "Invalid Index" << endl;
        return nullptr;
    }

    return (this->nodeList.at(idx));
}

/*
 * This method returns the size of the graph which is the number of dinstinct node it posseses
*/
size_t Graph::Size() const{
    return this->nodeList.size();
}

