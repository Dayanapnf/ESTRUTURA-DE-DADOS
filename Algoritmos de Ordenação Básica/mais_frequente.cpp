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

void frequencia(vector<int> &arr,int p, int f){
	int qnt=0;
	int cont = 0;
	int num = 0;
	for ( int i = p; i < f-1 ; i++){
		if(arr[i] == arr[i+1]){
			cont++;	
		}
		else 
			if(cont > qnt){
				num = arr[i];
				qnt= cont;
				cont=0;
			}
			else cont = 0;
			
	}
	cout << num <<" " <<qnt+1 <<"\n";
}

int main(){
	string line;
	int j=0, n;
	cin >> n;
	cin.ignore();
	getline(cin, line);
	stringstream ss(line);
	vector<int> v;
	vector<int> vcopy;
	int value;
		
	while(ss >> value)
		v.push_back(value);
	
	select(v, j, n-1 );
	frequencia(v,j,n);

}
