#include <iostream>
#include <vector>
using namespace std;

int busca_binaria(vector<int> &vet, int n, int item){
    int inicio = 0, fim = n-1, cont = 0;
    
    while(inicio <= fim){
        int meio = (inicio + fim)/2;
        cont++;
        
        if(vet[meio] == item) break;
        else{
            if(vet[meio] > item) fim = meio - 1;
            else inicio = meio + 1;
        }
    }
    return cont;
}

int main(){
    int n,m,i,x=0,j=0;
    vector<int> v1;
    vector<int>v2;
    cin>> n; 
    cin >> m;
    
    int value,value2;

	for (i=0;i<n;i++){
        cin >> value;	
        v1.push_back(value);	
    }
	
	while(j<m){
	   cin >> value2; 
	   v2.push_back(value2);
	   j++;
	}
	
	while(x < m){
	   if(x < m-1) cout << busca_binaria(v1, n, v2[x]) <<" ";
	   else cout << busca_binaria(v1, n, v2[x]) <<"\n";
	   x++;
	}
}