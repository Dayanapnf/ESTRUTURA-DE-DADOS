#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


void verifica(vector<string> &vet, vector<string> &vet2,int n,int nbusca){
	
	int cont=0;
    for(int i = 0; i < nbusca ; i++){
    	for(int j = 0 ; j < n ; j++)
			if(vet2[i] == vet[j])
   	   	   	   cont++;
		
		if(i < nbusca-1)
 	   	    cout << cont << " ";
 	   	else 
 	   	    cout << cont << "\n";
 	   	cont = 0;	
	} 
}

int main(){
	string line,line2;
	int i=0,j=0,n,nbusca;
	vector<string> v;
	vector<string> v2;
	string value,value2;
	
	cin >> n;

	for (i=0;i<n;i++){
        cin >> value;	
        v.push_back(value);	
    }
	cin >> nbusca;
	while(j<nbusca){
	   cin >> value2; 
	   v2.push_back(value2);
	   j++;
	}
		
	
	

	verifica(v,v2,n,nbusca);


}
