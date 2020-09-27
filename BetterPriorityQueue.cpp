#include "BetterPriorityQueue.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/*
 * This method returns a string/visual representation of our BetterPriorityQueue
*/
string BetterPriorityQueue::ToString(){
    if(this->c.size() == 0){
        return "[]";
    }
    string result = "[";
    for(unsigned int i = 0; i < this->c.size(); i++){
        result = result + '(' + this->c.at(i).node->key + ": " + to_string(this->c.at(i).pri);
        if(i != this->c.size()-1){
            result+="), ";
        }

        else{
            result+=")";
        }

    }
    result+="]";
    
    

    return result;
}

/*
 * This method checks if the BetterPriorityQueue contains the specified node and returns the index if it does and -1 otherwise
*/
int BetterPriorityQueue::Contains(DNode dn){
    for(size_t i = 0; i < this->c.size(); i++){
        if(this->c.at(i) == dn){
            return i;
        }
    }

    return -1;
}

/*
 * This method returns a string representation of a D(Dijkstra's??)Node
*/
string BetterPriorityQueue::DnodeToString(DNode dn){
    string result;
    result = result + "(" + dn.node->key + ": " + to_string(dn.pri) + ")";
    

    return result; 
}

/*
 * This method updates a priority queue's priority value
 * if the node exists in the priority queue and its priority is less than the priority of what is already in the priority queue
 * it iterates over the vector that represents the queue which helps erase the former node and then add this new node to the priority queue
 * the internal workings of the priority queue gurantees that the priority queue is re-adjusted in the case of any changes
 * this method returns true if the node is replaced and false if it isn't
*/
bool BetterPriorityQueue::Update(DNode dn){
    for(unsigned int i = 0; i < this->c.size(); i++){
        if(this->c.at(i).node->key ==dn.node->key){
            if(this->c.at(i).pri > dn.pri){
                this->c.erase(this->c.begin() + i);

                this->push(dn);

                return true;
            }
        }
    }

    return false;
}