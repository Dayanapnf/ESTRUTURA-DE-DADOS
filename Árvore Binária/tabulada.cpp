#include <iostream>
#include <sstream>
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
    Node * root {nullptr};
    BTree(){
    }
    
    void carregaArvore(stringstream &ss, Node ** keys){
        string value;
        int k;
        ss >> value;
        
        if (value == "#") return;
        
        stringstream(value) >> k;
        *keys = new Node(k);
        
        carregaArvore(ss, &(*keys)->left);
        carregaArvore(ss, &(*keys)->right);
    }

    BTree(string serial){
        stringstream ss(serial);
        carregaArvore(ss, &root);
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

    void show(){
        _show(this->root);
    }
    
    
    void _show(Node * node, string inheritance = ""){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            _show(node->left , inheritance + "l");
        for(int i = 0; i < (int) inheritance.size() - 1; i++)
            cout << (inheritance[i] != inheritance[i + 1] ? "...." : "....");
        if(inheritance != "")
            cout << (inheritance.back() == 'l' ? "...." : "....");
        if(node == nullptr){
            cout << "#" << endl;
            return;
        }
        cout << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            _show(node->right, inheritance + "r");
    }

};


int main(){
    string line;
    getline(cin, line);
    BTree bt(line);
    bt.show();
}