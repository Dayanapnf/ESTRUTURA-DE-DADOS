#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){
	int j= vet.size()-1;
	int aux= vet[vet.size()-1];
	if(nrot >= 1){
		while ( j >= 1) {
				vet[j] = vet[j-1];
				j--;
		}
		vet[0] = aux;
		
		right_rotation(vet,--nrot);	
	}
}

void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){
    int size, nrot;
    cin >> size >> nrot;
    vector<int> vet(size);
    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}

