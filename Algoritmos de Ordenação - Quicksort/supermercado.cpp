#include <iostream>
#include <vector>
using namespace std;

class Product{
   
    
    public:
    string name;
    int price;
    Product(string n, int p){
        name = n;
        price = p;
    }
    Product();
    
    bool operator <(const Product & a){
        if(price != a.price) return price < a.price;
        else return name < a.name;
    }
    
    friend ostream& operator << (ostream& os, const Product& p); 
};
Product::Product()
{
    name = ' ';
    price = 0;
}


ostream& operator << (ostream& os, const Product& p){
    os << "(" << p.name << "," << p.price << ")";
    return os;
}

void swap(Product *x, Product *y)
{
	Product aux = *x;
	*x = *y;
	*y = aux;
}

void select(vector<Product> &arr, int p, int f)
{
	if(p < f){
		int min = p;
		for ( int i = p+1; i < f  ; i++)
			if (arr [i] < arr [min])
			    min = i;		
		swap(arr[p], arr[min]);
		select(arr,p+1,f);
	}
}
void ordena(vector<Product> &prod, int n, int m, int p, int q){
    
    select(prod, 0, n);
    select(prod, n, n+m);
    
    vector<Product> temp;
    
    for(int i = 0; i<p; i++) temp.push_back(prod[i]); 
    for(int j = n; j<n+q; j++) temp.push_back(prod[j]);

    select(temp,0,temp.size());
    
    for(int i=0; i<temp.size(); i++) {
        if(i<temp.size()-1)
            cout << temp[i].name << " ";
        else
            cout << temp[i].name << "\n";
    }
       
}

int main(){
    int n, p,m,q, i=0;
    string nome;
    int preco;
    cin >> n >> m >> p >>q;
    Product pe ;
    vector<Product> prod;
    
    while(i < n+m){
        cin >> nome >> preco;
        pe.name=nome;
        pe.price=preco;
        prod.push_back(pe);

        i++;
    }
   
    
    ordena(prod,n,m,p,q);
}