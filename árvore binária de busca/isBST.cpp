#include <iostream>
#include <vector>
#include <iomanip>      // std::setw 
#include <climits>

using namespace std;

template <typename T> 
class NodeTree{
    public:
    T key;
    int size;
    NodeTree<T> * left;
    NodeTree<T> * right;
    NodeTree(T key) : key(key), left(nullptr), right(nullptr) {};
    NodeTree(T key, NodeTree * l, NodeTree * r) : key(key), left(l), right(r) {};    
};


template <typename T> 
NodeTree<T> * createTree( vector<T> keys, vector<int> parent){

    NodeTree<T>* tree[keys.size()];
    NodeTree<T>* root;

    for(int i = 0; i < keys.size(); i++){
        tree[i] = new NodeTree<T>(keys[i]);
    }

    for(int i = 0; i < keys.size(); i++){

        if( parent[i] == -1)
            root = tree[i];
        else
        {
            NodeTree<T>* ptr = tree[ parent[i] ];

            if( ptr->left ){
                ptr->right = tree[i];
            }else{
                ptr->left = tree[i];
            }

        }
    }

    return root;

} 

//Utilize essa função auxiliar
template <typename T>
bool isBSTAux(NodeTree<T> * root, int min, int max){
    //caso base
    if(root == nullptr) return true;
    
    if (root->key < min || root->key > max) return false;

    return isBSTAux(root->left, min, root->key-1) && isBSTAux(root->right, root->key+1, max);
}

template <typename T>
bool isBST(NodeTree<T> * root){
    return isBSTAux(root, INT_MIN, INT_MAX);
}


template <typename T>
ostream& operator<<(ostream &output, const NodeTree<T> * ptr)
{
    static int offset = 0;

    

    if(ptr == nullptr){
        output << " " << setw(offset);
        output << "-\n";
    }
    else
    {
        offset += 3;
        output << ptr->left;
        offset -= 3;

        output << " " << setw(offset);
        output << ptr->key << endl;
        
        offset += 3;
        output << ptr->right;
        offset -= 3;
    }   
    return output;
}    


int main(){
    int n;
    vector <int> keys;
    vector <int> parent;

    cin >> n;

    keys.resize(n);
    parent.resize(n);


    for(int i = 0; i < n; i++)
        cin >> keys[i];

    for(int i = 0; i < n; i++)
        cin >> parent[i];
    
    NodeTree<int>* root = createTree(keys, parent);

    string res = isBST(root) ? "Yes" : "No"; 

    cout << res << endl ;

}