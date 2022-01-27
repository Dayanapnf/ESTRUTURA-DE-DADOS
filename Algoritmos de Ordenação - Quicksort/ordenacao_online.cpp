#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


void swap(int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;

}

void select(vector<int> &arr, int p, int f)
{
	if(p < f){
		int min = p;
		for ( int i = p+1; i < f  ; i++)
			if (arr [i] < arr [min])
			    min= i;		
		swap(arr[p], arr[min]);
		select(arr,p+1,f);
	}
}
void imprime(vector<int> &v,vector<int> &v2){
    vector<int> vet;
    int aux=0;
    for(int i=0; i < v.size(); i++){
        if(v[i] == 1){
            vet.push_back(v2[i]) ; 
        }
        else{
            if(v[i]==2){
                aux = v2[i];
                select(vet,0,vet.size());
                cout << vet[aux] << "\n";  
            }
		}
    }
}

int main(){
    int n = 0, i,value;
    cin  >> n;
	vector<int> v,v2;

    
    for(i = 0; i < n; i++){
        cin >> value;
        v.push_back(value);
        cin >> value;
        v2.push_back(value);
    }
  
    imprime(v,v2);    
	
   
}