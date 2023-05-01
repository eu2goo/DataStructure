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
    void add_to_head(node t);
    void delete_from_head();
    bool list_empty();
    bool palindrome(string input);
};
my_list::my_list(){
    head = NULL;
    tail = NULL;
}
void my_list:: add_to_head(node t){
    //head 부터 add
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
    if(tail==NULL){
        tail = p;
    }
}
void my_list::delete_from_head(){
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

bool my_list :: palindrome(string input){
    node *newnode,temp;
    newnode = head;
    int i = input.size()/2 + (input.size()%2);
    while(newnode -> link != NULL){
        if(newnode->word == input[i]){
            newnode = newnode ->link;
            i++;
        }else{
            return false;
        }
    }
    if(newnode->word == input[i]){
        return true;
    }else{
        return false;
    }
};


int main(void){
    my_list theWords;
    node tmp;
    string input;
    cout << "Enter the sentence to check palindrome: ";
    cin >> input;
    for(int i=0;i<input.size()/2;i++){
        tmp.set_data(input[i]);
        theWords.add_to_head(tmp);
    }
    if(theWords.palindrome(input)){
        cout << "Palindrome!\n";
    }else{
        cout << "Not a Palindrome!\n";
    }
    
    return 0;
}