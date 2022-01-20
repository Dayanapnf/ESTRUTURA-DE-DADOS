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

void ind(vector<int> &vet, vector<int> &copy,int n){
    for(int i=0; i<n;i++)
        for(int j=0;j<n;j++){
            if(vet[i] == copy[j] && i < n-1)
                cout << j <<" ";
            if(vet[i] == copy[j] && i >= n-1)
                cout << j <<"\n";
        }
            
}

int main(){
	string line;
	int i=0,j=0, n;
	cin >> n;
	cin.ignore();
	getline(cin, line);
	stringstream ss(line);
	vector<int> v;
	vector<int> vcopy;
	int value;
		
	while(ss >> value)
		v.push_back(value);
	
    while (i < n){
        vcopy.push_back(v[i]);
		i++;
	}
	select(v, j, n-1 );

	ind(v,vcopy,n);

	

}
