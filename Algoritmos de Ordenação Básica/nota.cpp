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

void select(vector<int> &arr,int p, int f)
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

int main(){
	string line;
	int j=0, n,cont=0;
	cin >> n;
	cin.ignore();
	getline(cin, line);
	stringstream ss(line);
	vector<int> v;
	int value;
	while(ss >> value)
		v.push_back(value);
		
	select(v,j,n-1);
	
    for(j=0; j<n ; j++){
        if(v[j+1] == v[j])
           cont++;
    }
    cout << cont <<"\n";
}



