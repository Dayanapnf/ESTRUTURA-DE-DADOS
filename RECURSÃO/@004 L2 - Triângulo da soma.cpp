#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
using namespace std;

int tri(int **mat, int i,int tam, int j){

	if(tam == 1) return  mat [i][j];
	
	if(j < tam-1){
	mat[i+1][j] = mat[i][j]+ mat[i][j+1];
	    
		return tri(mat,i,tam,++j);
	}else{
		j=0;
		return tri(mat,++i,--tam,j);
	}
}
	
int main(){
	string line;
	getline(cin, line);
	stringstream ss(line);
	vector<int> v;
	int value;
	while(ss >> value)
	    v.push_back(value);
	
	int **mat;
    int tam2 = 0;
	int tam = v.size();
	
	mat = (int**) malloc(tam * sizeof(sizeof(int *)));	
	for(int x = 0; x < tam; x++){
		mat[x] = (int *) malloc(tam * sizeof(int));
	}
	
	for(int i=0;i<tam;i++){
		for(int j=0;j<tam;j++){
			mat[i][j]=v[j];
		}
	}
	
    tri(mat,0,tam,0);

    for(int i=tam-1; tam > 0; i--){
    	cout<<"[ ";
		for(int j=0; j <= tam2; j++){
			cout << mat[i][j]<< " ";
		}
		cout<<"]"<<"\n";
		--tam;
		++tam2;
	}
}