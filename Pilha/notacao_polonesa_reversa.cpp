#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
using namespace std;

string expr;
int pos = 0;

string get_token()
{
    string token = "";
    
    if(pos == expr.size() ){
        token = "$";
        return token;
    }
    
    while( expr[pos] == ' ') pos++;

    if(expr[pos] == '+' || expr[pos] == '-' || expr[pos] == '/' || expr[pos] == '*'){
        token = token + expr[pos];
        pos = pos + 1;
        return token;
    }
    else if(isdigit(expr[pos]) ){
        while( isdigit(expr[pos]) ){
            token = token + expr[pos];
            pos = pos + 1;
        }
        return token;
    }

    return token;
}

int main(){
    
    
    getline( cin, expr );
    stack <int> s;
    string token = get_token();
    
    int operando1 ,operando2, resultado; 
    while(token != "$"){
        
        if( token == "+" )
        {
            operando1 = s.top();
            s.pop();
            operando2 = s.top();
            s.pop();
            resultado = operando1 + operando2;
            s.push(resultado);
            
        }
        else if( token == "-" )
        {
            operando1 = s.top();
            s.pop();
            operando2 = s.top();
            s.pop();
            resultado = operando1  - operando2;
            s.push(resultado);
            
        }
        else if( token == "*" )
        {
            operando1 = s.top();
            s.pop();
            operando2 = s.top();
            s.pop();
            resultado = operando1 * operando2;
            s.push(resultado);
        
        }
        else if( token == "/")
        {
            operando1 = s.top();
            s.pop();
            operando2 = s.top();
            s.pop();
            resultado = operando1 / operando2;
            s.push(resultado);
        }
        else {
            s.push( atoi(token.c_str() ) );
        }

        token = get_token();
        
    }

    cout << resultado << "\n";
}