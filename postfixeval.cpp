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
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){
        return false;
    }
    return true;
}
int main(void){
    opstack mystack;
    string input;
    int num;
    cout << "Enter postfix eval: ";
    cin >> input;

    for(int i=0;i<input.size();i++){
        if(isoperand(input[i])){
            mystack.push(input[i] - '0');
        }else{
            int num1 = mystack.pop();
            int num2 = mystack.pop();
            if(input[i] == '+'){
                mystack.push((num1 + num2));
            }else if(input[i] == '-'){
                mystack.push(num2 - num1);
            }else if(input[i] == '*'){
                mystack.push(num1*num2);
            }else if(input[i] == '/'){
                mystack.push(num2/num1);
            }else{
                mystack.push(num2%num1);
            }
        }
    }
    num = mystack.pop();
    cout << num;
}