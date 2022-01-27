#include <iostream>
#include <vector>
using namespace std;

int N,C;

int verifica(int num, vector<int> &baias){
    int vacas = 1, p = baias[0];
    
    for(int i = 1; i < N; i++){
        if(baias[i] - p >= num){
            p = baias[i];
            vacas++;
            if(vacas == C) return 1;
        }
    }
    
    return 0;
}

int busca_binaria(vector<int> &baias){
    int inicio = 0, fim = baias[N-1], maximo = -1;
    
    while(fim > inicio){
        int meio = (inicio + fim)/2;
        
        if(verifica(meio, baias)==1){
            if(meio > maximo) maximo = meio;
            
            inicio = meio + 1;
        }
        else fim = meio;
    }
    
    return maximo;
}

void swap(int *x, int *y){
	int aux = *x;
	*x = *y;
	*y = aux;

}

void select(vector<int> &arr, int p, int f){
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
    int i, value;
    cin >> N;
    cin >> C;
    
    vector<int> baias;
    
    for(i = 0; i < N; i++){
        cin >> value;
        baias.push_back(value);
    }
    
    select(baias, 0, N-1);
    
    cout << busca_binaria(baias);
    cout<< endl;
    
}