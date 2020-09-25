#include "Graph.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;


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

GraphNode* Graph::AddNode(char key, int data){
    GraphNode *gn = new GraphNode();
    gn->key = key;
    gn->data = data;

    this->nodeList.push_back(gn);
    
    return gn;
    
}

GraphEdge* Graph::AddEdge(GraphNode *gn1, GraphNode *gn2, unsigned int weight){
    GraphEdge *ge = new GraphEdge();

    ge->from = gn1;
    ge->to = gn2;
    ge->weight = weight;

    //add new edge to adjacency list???
    vector<GraphEdge*> temp;

    if(this->adjacencyMatrix.size()!=0){
        for(unsigned int i = 0; i < this->adjacencyMatrix.size(); i++){
            if(ge->from->key == this->adjacencyMatrix.at(i).front()->from->key){
                this->adjacencyMatrix.at(i).push_back(ge);
                return ge;
            }
        }

        temp.push_back(ge);
        adjacencyMatrix.push_back(temp);
        return ge;
    }

    temp.push_back(ge);
    adjacencyMatrix.push_back(temp);


    return ge;
}

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




string Graph::ToString() const{
    string result = "";
    unsigned int x = 0;

    while(x < this->nodeList.size()){

        result = result + this->nodeList.at(x)->key + " | ";
    
        for(unsigned int i = 0; i < this->adjacencyMatrix.size(); i++){
            if(this->adjacencyMatrix.at(i).front()->from->key == this->nodeList.at(x)->key){
                for(unsigned j = 0; j < adjacencyMatrix.at(i).size(); j++){
                    result = result + "[(" + this->adjacencyMatrix.at(i).at(j)->from->key + ":" + to_string(this->adjacencyMatrix.at(i).at(j)->from->data) + ")" +"->(" + this->adjacencyMatrix.at(i).at(j)->to->key + ":" + to_string(this->adjacencyMatrix.at(i).at(j)->to->data) + ") w:" + to_string(this->adjacencyMatrix.at(i).at(j)->weight);
                    if(j != adjacencyMatrix.at(i).size()-1){
                        result += "], ";
                    }

                    else{
                        result += "]";
                    }
                
                }
                
            }
            
        }

        result +='\n';
        x++;

    }    
    return result;
}

string Graph::GraphNodeToString(const GraphNode *gn){
    string result = "(";
    result = result + gn->key + ":" + to_string(gn->data) + ")";

    return result;
}



string Graph::GraphEdgeToString(const GraphEdge *ge){
    string result = "[(";
    result = result + ge->from->key + ":" + to_string(ge->from->data) +") -> (" + ge->to->key + ":" + to_string(ge->to->data) + ")" + " w:" + to_string(ge->weight) + "], " ;

    result.at(result.size()-2) = '\0';

    result.at(result.size()-1) = '\0';

    return result;
}


const vector<GraphEdge*>& Graph::GetEdges(const GraphNode *gn)const{
    vector<GraphEdge*> *temp = new vector<GraphEdge*>();
    
    for(unsigned int i = 0; i < this->adjacencyMatrix.size(); i++){
        if(this->adjacencyMatrix.at(i).front()->from->key == gn->key){
            const GraphEdge *ge;
            for(unsigned j = 0; j < this->adjacencyMatrix.at(i).size(); j++){
                ge = (this->adjacencyMatrix.at(i).at(j));

                temp->push_back(new GraphEdge (*ge));
                
            }

        }
    }

    const vector<GraphEdge*> &result = *temp;
    return result;
}


const vector<GraphNode*>& Graph::GetNodes() const{
    vector<GraphNode*> *temp = new vector<GraphNode*>();

    for(unsigned int i = 0; i < this->nodeList.size(); i++){
        const GraphNode *gn;
        gn = (this->nodeList.at(i));
        temp->push_back(new GraphNode(*gn));
    }

    const vector<GraphNode*>& result = *temp;

    return result;
}


const GraphNode* Graph::NodeAt(unsigned int idx) const{
    if(idx >= this->nodeList.size()){
        cout << "Invalid Index" << endl;
        return nullptr;
    }

    return (this->nodeList.at(idx));
}


size_t Graph::Size() const{
    return this->nodeList.size();
}

