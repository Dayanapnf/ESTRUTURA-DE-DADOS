#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int main (){
    int aux = 65, value1, value2;
    queue < int >resultado;
  
    while (aux < 81){
        resultado.push (aux);
        aux++;
    }
    for (int i = 0; i < 15; i++){
        cin >> value1 >> value2;
        if (value1 > value2){
	    resultado.push (resultado.front ());
	    resultado.pop ();
	    resultado.pop ();
	}else{
    	    resultado.pop ();
    	    resultado.push (resultado.front ());
    	    resultado.pop ();
    	}
    }
    printf("%c\n",resultado.front());
}
