#define DisjuntosHpp
#include <vector>
#include <iostream>
using namespace std;

class Disjuntos{
    private:
        vector<int> conjunto, uniao;

    public:
        Disjuntos(int n){
            for (int i = 0; i < n; i < i++){
                conjunto.push_back(i);
        }
    }
  
    void une(int a, int b){
        bool A =true;
        bool B = true;
        for (int i = 0; i < uniao.size(); i++){
            if (uniao[i] == a)
                A = false;
            else if (uniao[i] == b)
                B = false;
        }
        if (A == true)
            uniao.push_back(a);
        if (B == true)
            uniao.push_back(b);
    }
  
    int mesmo(int x, int y){
        int cont = 0;
        for (int i : uniao)
            if (i == x || i == y)
                cont++;
            
        if (cont >= 2)
            return 1;
        return 0;
    }
};
