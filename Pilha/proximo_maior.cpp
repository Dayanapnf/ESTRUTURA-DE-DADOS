#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main(){
    int n,value,j=0;
    vector<int> vec,resul;
    stack<int> pilha;
    cin >> n;
    resul.resize(n);
    
    for(int i=0; i<n; i++){
        cin >> value;
        vec.push_back(value);
      //  cout << vec[i];
    }
  
    for(int i=0; i<n; i++){
        
        if(i == 0){
            pilha.push(i);

        }
        else{
            if(vec[i] > vec[pilha.top()] && pilha.size() < 2){
                resul[pilha.top()] = i;
                pilha.pop();
                pilha.push(i);
            }
            else if(vec[i] > vec[pilha.top()] && pilha.size() >= 2){
                while(!pilha.empty()){
                    if(vec[i] > vec[pilha.top()]){
                        resul[pilha.top()]= i;
                        pilha.pop();
                    }
                    else break;
                }
                pilha.push(i);

            }
            else{
                pilha.push(i);
            }
        }
     
    }
    
    while(!pilha.empty()){
        resul[pilha.top()] = -1;
        pilha.pop();
    }
    
    for(int i = 0 ; i < resul.size(); i++){
        if(i == n -1) cout << resul[i] << "\n";
        else cout << resul[i] << " ";
    }
    
}
    
    
    
    