#include <iostream>
using namespace std;
#define SIZE 5

class myqueue{
    int q[SIZE];
    int front, rear;
    public:
    myqueue(){
        front = 0;
        rear = 0;
    }
    void insertq(int x);
    int deleq();
    bool queuefull();
    bool queueempty();
    friend bool sum(myqueue a);

};
void myqueue :: insertq(int x){
    if(!queuefull()){
        q[rear] = x;
        rear = (rear+1)%SIZE;
    }else{
        cout << "Queue is full!\n";
    }
    
}
int myqueue::deleq(){
    int tmp = -1;
    if(!queueempty()){
        tmp = q[front];
        front = (front+1)%SIZE;
        return tmp;
    }
    return tmp;
}
bool myqueue :: queuefull(){
    if((rear+1)%SIZE == front){
        return true;
    }
    return false;
}
bool myqueue :: queueempty(){
    if(rear == front){
        return true;
    }else{
        return false;
    }
}
bool sum(myqueue a){
    a.front;
}