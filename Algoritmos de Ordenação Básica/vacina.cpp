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

void vacina(vector<int> &vac,vector<int> &pac,int n){
	int cont=0;
	for(int i=0; i< n ; i++){
		if(vac[i] >= pac[i])
			cont++;	
	}
	if(cont == n) cout << "Yes" << "\n";
	else cout << "No" << "\n";

}
int main(){
	
	string line,line2;
	
	int j=0, n;
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

	select(v, j, n-1 );
	select(v2, j, n-1 );

	vacina(v,v2,n);

	

}
