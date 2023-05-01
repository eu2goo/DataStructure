#include <iostream>
using namespace std;

class node{
    public:
    char word;
    node *link;
    void set_data(char w);
};

void node::set_data(char w){
    word = w;
}
class my_list{
    node *head, *tail;
    public:
    my_list();
    void add_to_head(node t); //void push(node t)
    void pop();
    bool list_empty();
    bool palindrome(char w);
};
my_list::my_list(){
    head = NULL;
    tail = NULL;
}
void my_list:: add_to_head(node t){
    //head 부터 add
    node *p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if(tail==NULL){
        tail = p;
    }
}
void my_list::pop(){
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if(head == NULL){
        tail = NULL;
    }
}
bool my_list::list_empty(){
    //list 가 엠티인지 확인
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

bool my_list :: palindrome(char w){
    node *newnode,temp;
    newnode = head;
    if(newnode->word == w){
        return true;
    }else{
        return false;
    }
};


int main(void){
    my_list theWords;
    node tmp;
    string input;
    bool result;
    cout << "Enter the sentence to check palindrome: ";
    cin >> input;
    for(int i=0;i<input.size()/2;i++){
        tmp.set_data(input[i]);
        theWords.add_to_head(tmp);
    }
    int l = input.size()%2;
    int n = input.size()/2 + input.size()%2;
    while(1){
        result = theWords.palindrome(input[n]);
        if(result){
            theWords.pop();
            n++;
        }else{
            break;
        }
        if(n == input.size()){
            break;
        }
    }    
    
    if(result == true){
        cout << "Palindrome!\n";
    }else{
        cout << "Not a Palindrome!\n";
    }
    return 0;
}