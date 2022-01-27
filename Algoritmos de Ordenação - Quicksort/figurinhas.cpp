#include <iostream>
#include <vector>
#include <sstream>
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
		for ( int i = p+1; i <= f  ; i++)
			if (arr [i] < arr [min])
			    min= i;		
		swap(arr[p], arr[min]);
		select(arr,p+1,f);
	}
}

int verifica(vector<int> &vet, vector<int> &vet2,int n){
	
    for(int i = 0; i < n ;i++){
    	if(vet[i] != vet2[i]){
   	   	   return  0;
		}		
	}
	
	return 1;   
             
}

int main(){
	string line,line2;
	int i=0,j=0, n;
	cin >> n;
	cin.ignore();
	getline(cin, line);
	getline(cin, line2);
	stringstream ss(line);
	stringstream sss(line2);
	vector<int> v;
	vector<int> v2;
	int value,value2;
		
	while(ss >> value)
		v.push_back(value);
	
	while(sss >> value2)
		v2.push_back(value2);
	
    
    select(v, 0, n-1 );
	select(v2, 0, n-1 );
	

	cout << verifica(v,v2,n) <<"\n";

	
}
