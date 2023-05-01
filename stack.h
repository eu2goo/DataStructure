#include <iostream>
using namespace std;

#define SIZE 5

class mystack{
    int s[SIZE];
    int top;
public:
    void init();
    /* init() or mystack() as constructor
    mystack(){
        top = 0;
    }*/
    void push(int x);
    int pop();
    bool stack_full();
    bool stack_empty();
};
 void mystack :: init(){
    top = 0;
 }
 void mystack :: push(int x){
    s[top] = x;
    top++;
 }
 int mystack :: pop(){
    top--;
    return s[top];
 }
 bool mystack :: stack_full(){
    if(top >= SIZE)
        return true;
    else
        return false;
 }
  bool mystack :: stack_empty(){
    if(top == 0)
        return true;
    else
        return false;
 }
