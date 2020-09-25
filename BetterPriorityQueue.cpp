#include "BetterPriorityQueue.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

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


int BetterPriorityQueue::Contains(DNode dn){
    for(size_t i = 0; i < this->c.size(); i++){
        if(this->c.at(i) == dn){
            return i;
        }
    }

    return -1;
}

string BetterPriorityQueue::DnodeToString(DNode dn){
    static string result = "(";
    result = result + dn.node->key + ": " + to_string(dn.pri) + ")";
    

    return result; 
}

bool BetterPriorityQueue::Update(DNode dn){
    for(unsigned int i = 0; i < this->c.size(); i++){
        if(this->c.at(i).node->key == dn.node->key){
            if(this->c.at(i).pri > dn.pri){
                this->push(dn);
                return true;
            }
        }
    }

    return false;
}
