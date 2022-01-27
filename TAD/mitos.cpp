#ifndef RAIOS_HPP
#define RAIOS_HPP

#include <iostream>
#include <vector> 

using namespace std;

class Raios{

    private:
    int larg,comp;
    vector<pair<int, int>> mitos;
       
    public:
    
    Raios(int n, int m){ 
        this-> larg=n;
        this-> comp = m;
    }

    void add(int x, int y){
        mitos.push_back(make_pair(x,y));
    }

    int mesmo_lugar(){
       for(int i = 0; i < mitos.size(); i++){
           for(int j = i + 1; j < mitos.size(); j++){
               if((mitos[i].first == mitos[j].first) && (mitos[i].second == mitos[j].second)){
                   return 1;
               }
           }
       }
       
       return 0;
    }
};


#endif