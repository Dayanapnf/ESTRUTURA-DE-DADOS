#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void vet(vector<int> v,int i=0){
    
	if(i == v.size()-1) cout << v[i];
	else{
		cout << v[i] << " ";
        vet(v,i+1);
	}
}
void rvet(vector<int> v,int tam){
	
	if(tam==1) cout<< v[tam-1];
	else{
		cout<< v[tam-1] << " ";
		rvet(v,tam-1);
	}
}
int sum(vector<int> v,int tam){
	if (tam == 0) return 0;
	else return v[tam-1] +sum(v,tam-1);
}
int mult(vector<int> v,int tam){
	
	if( tam == 0)return 0;
	
	if(tam==1)return v[0];
	
	else return v[tam-1] * mult(v,tam-1);
	
}
int min(vector<int> v,int tam){
	if (tam == 1) return v [0];
    else {
      int minimo;
      minimo = min(v, tam-1); 
      if ( minimo < v[tam -1]) return minimo ;
      else return v[tam -1];
    }
}


void inv(vector<int> v,int i,int tam){
	int a;
    if(tam == 1) cout<< v[i];	
	else{
		if(i < v.size()/2){
			a = v[i];
			v[i]= v[tam-1];
			v[tam-1]=a;
			inv(v,i+1,tam-1);
		}else vet(v);
	}  
}



int  main (){
  	string line;
	getline(cin, line);
	stringstream ss(line);
	vector<int> v;
	int value;
	while(ss >> value)
	    v.push_back(value);
	
	int tam = v.size();
	cout<< "vet : [ ";
	vet(v);
	cout<<" ]\n";
	
	cout<< "rvet: [ ";
	rvet(v,tam);
	cout<<" ]\n";
	
	cout<< "sum : " << sum(v,tam)<< "\n";
	cout<< "mult: " << mult(v,tam) << "\n";
	cout<< "min : " << min(v,tam) << "\n";
	cout<< "inv : [ " ;
	inv(v,0,tam);
	cout<<" ]\n";
	return 0;
}



		
	
	
