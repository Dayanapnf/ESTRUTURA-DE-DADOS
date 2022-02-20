#include <iostream>
#include <string>
using namespace std;
 

struct Node {
    int value;
    Node *left, *right;
    Node(int key)
    {
        value = key;
        left = right = nullptr;
    }
};
 
Node* insert(Node* root, int key)
{
    if (root == nullptr)
        return new Node(key);
    if (key < root->value)
        root->left = insert(root->left, key);
    else if (key > root->value)
        root->right = insert(root->right, key);
    return root;
}
 
Node* kesimo(Node* root, int & k)
{
    // caso base
    if (root == nullptr) return nullptr;

    Node * esq = kesimo(root->left, k);
 
    if (esq != nullptr) return esq;
 
    k--;
    if (k == 0) return root;
 
    return kesimo(root->right, k);
}

int main(){
    Node * root = nullptr;
    int tam, k, value;
    string keys;
    
    cin >> tam >> k;

    for(int i = 0; i < tam; i++){
        cin >> value;
        keys.push_back(value);
    }
    
    for(int i : keys){
        root = insert(root, i);
    }
    
    Node * aux = kesimo(root, k);
    
    cout << aux->value << endl;
}