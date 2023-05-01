#include <iostream>
using namespace std;
#include <string>
#define SIZE 100

class opstack{
    char s[SIZE];
    int top;
    public:
    opstack(){
        top = 0;
    }
    void push(char c);
    char pop();
    char topelement();
    bool empty();
};

void opstack:: push(char c){
    s[top] = c;
    top++;
}
char opstack::pop(){
    top --;
    return s[top];
}
char opstack::topelement(){
    return s[top-1];
}
bool opstack :: empty(){
    if(top == 0){
        return true;
    }
    return false;
}
bool isoperand(char c){
    if( c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
        return false;
    }
    return true;
}
int precedence(char c){
    if( c == '(' || c == '$'){
        return 0;
    }
    if( c == '+' || c == '-'){
        return 1;
    }
    if( c == '*' || c == '/' || c == '%'){
        return 2;
    }
    return (-1);
}
int main(void){
    opstack mystack;
    string input;
    string output;
    cout << "Enter the infix: ";
    cin >> input;

    for(int i=0;i < input.size();i++){
        if(isoperand(input[i])){
            output += input[i];
        }else{
            if(input[i] == '('){
                mystack.push(input[i]);
            }else if(input[i] == ')'){
                while(mystack.topelement() != '('){
                    output += mystack.pop();
                }
                mystack.pop();
            }
            else{
                while(!mystack.empty() && (precedence(input[i]) <= precedence(mystack.topelement()))){
                    output += mystack.pop();
                }
                mystack.push(input[i]);
            }
        }
    }
    while(!mystack.empty()){
        output += mystack.pop();
    }
    cout << "postfix: " << output;
}