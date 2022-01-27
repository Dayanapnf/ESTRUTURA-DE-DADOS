#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


void elimina(vector<int> &vet, vector<int> &vet2,int n,int nbusca){
	
    int x=0;
    for(int i = 0; i < nbusca ; i++)
    	for(int j = 0 ; j < n ; j++)
			if(vet2[i] == vet[j])
			    vet[j] = 0;
			    
    while( x < n){
        if(vet[x]!= 0)
            cout << vet[x] << " ";
            
        
            
        
        x++;
        if(x == n )
            cout << "\n";
    } 
   	   	 
	
}

int main(){
	string line,line2;
	int i=0,j=0,n,qtd;
	vector<int> v;
	vector<int> v2;
	int value,value2;
	
	cin >> n;

	for (i=0;i<n;i++){
        cin >> value;	
        v.push_back(value);	
    }
	
	cin >> qtd;
	while(j<qtd){
	   cin >> value2; 
	   v2.push_back(value2);
	   j++;
	}
		
	elimina(v,v2,n,qtd);


}
