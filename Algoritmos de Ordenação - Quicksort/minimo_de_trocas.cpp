#include <iostream>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


void swap(int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;

}

void select(vector<pair<int, int>> &array, int p, int f)
{
	if(p < f){
		int min = p;
		for ( int i = p+1; i < f  ; i++)
			if (array [i] < array [min])
			    min= i;		
		swap(array[p], array[min]);
		select(array,p+1,f);
	}
}
int minimo_select(vector<int> &arr, int n)
{
    
    vector<pair<int, int>> vet(n);
    for (int i = 0; i < n; i++)
    {
        vet[i].first = arr[i];
        vet[i].second = i;
    }

    
    select(vet, 0, n);
    
    int minimo_swaps = 0;
    int i = 0;
    while (i < n){
        if (vet[i].second == i || vet[i].first == arr[i]){
            ++i;
            continue;
        }
        else{
            swap(vet[i].first, vet[vet[i].second].first);
            swap(vet[i].second, vet[vet[i].second].second);
            if (vet[i].second != i)
                i--;
        }
        minimo_swaps++;
        ++i;
    }
    return minimo_swaps;
}

int main(){
    int n = 0, i,value;
    cin  >> n;
	vector<int> v,v2;
   
    
    for(i = 0; i < n; i++){
        cin >> value;
        v.push_back(value);
    }
  
    cout << minimo_select(v,  n) <<"\n";    

}