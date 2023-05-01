#include <iostream>
using namespace std;

#define SIZE 100

class op_stack{
    char s[SIZE];
    int top;
    public:
    op_stack();
    void push(char x);
    char pop();
    bool empty();
    char top_element();
};

op_stack::op_stack(){
    top = 0;
}
void op_stack :: push(char x){
    s[top++] = x;
    //top++;
}
char op_stack::pop(){
    top--;
    return(s[top]);
}
bool op_stack::empty(){
    return (top == 0);
}
char op_stack::top_element(){
    return (s[top-1]);
}

int main(void){
    string input;
    int result = 0;
    op_stack stack1;
    cout << "Input the sentence to check Palindrome: ";
    cin >> input;

    for(int i=0;i<input.size()/2;i++){
        stack1.push(input[i]);
    }
    int l = input.size()%2;
    for(int i=input.size()/2+l;i < input.size();i++){
        if(input[i] == stack1.top_element()){
            stack1.pop();
        }else{
            result = 1;
            break;
        }
    }


    if(result == 1){
        cout << "Not a palindrome!\n";
    }else{
        cout << "Palindrome!\n";
    }


}