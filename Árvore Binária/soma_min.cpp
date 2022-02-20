#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <climits>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root;
    BTree(){
        this->root = nullptr;
    }

    void clone(stringstream& ss, Node ** elo){
        string value;
        ss >> value;
        if(value == "#")
            return;
        int num;
        stringstream(value) >> num;
        *elo =  new Node(num);
        clone(ss, &(*elo)->left);
        clone(ss, &(*elo)->right);
    }

    BTree(string serial){
        stringstream ss(serial);
        clone(ss, &root);
    }

    void __destroy(Node * node){
        if(node == nullptr)
            return;
        __destroy(node->left);
        __destroy(node->right);
        delete node;
    }

    ~BTree(){
        __destroy(this->root);
    }

    int _sum(Node * root){
        if (root == nullptr) return 0;
    
        return (root->value + _sum(root->left) + _sum(root->right));
    }
    
    int sum(){
        return _sum(root);
    }
    
    int _min(Node * root){
        if (root == nullptr) return INT_MAX;
        
        int minimo = root->value;
        int esqNode  = _min(root->left);
        int dirNode = _min(root->right);
        
        if (esqNode < minimo) minimo = esqNode;
        
        if (dirNode < minimo) minimo = dirNode;
        
        return minimo;
    }

    int min(){
        return _min(root);
    }
};    


int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    getline(cin, line);
    cout << bt.sum() << " " << bt.min() << "\n";
}
