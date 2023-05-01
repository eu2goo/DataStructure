#include <iostream>
using namespace std;
#include <string>

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
bool is_openbracket(char ch){
    if((ch == '(')||(ch == '{')||(ch == '[')){
        return true;
    }else{
        return false;
    }
}
bool is_closebracket(char ch){
    if((ch == ')')||(ch == '}')||(ch == ']')){
        return true;
    }else{
        return false;
    }
}
int main(void){
    string input;
    int result=0;
    // 1 => brackets do not match
    op_stack stack1;
    cout << "Input the sentence to check: ";
    cin >> input;

    for(int i=0;i<input.size();i++){
        
        if(is_openbracket(input[i])){
            stack1.push(input[i]);
        }
        if(is_closebracket(input[i])){
            cout << input[i] << "  " << stack1.top_element() <<"\n";
            
            if(input[i] == ')' && stack1.top_element() != '('){
                result = 1;
                break;
            }
            else if(input[i] == ']' && stack1.top_element() != '['){
                result = 1;
                break;
            }
            else if(input[i] == '}' && stack1.top_element() != '{'){
                result = 1;
                break;
            }
            else{
                stack1.pop();
            }
        }
    }
    int open = 0,close = 0;
    for(int i=0;i<input.size();i++){
        if(is_openbracket(input[i])){
            open ++;
        }
        if(is_closebracket(input[i])){
            close ++;
        }
    }    
    if(!stack1.empty() ){
        if(open == close){
            cout << "괄호 불 일치!!\n";
        }else{
            cout << "닫는 괄호 누락!!\n";
        }
    }
    if(result == 0){
        cout << "정상!!\n";
    }

}