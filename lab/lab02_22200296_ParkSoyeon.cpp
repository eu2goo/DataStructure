#include <iostream>
using namespace std;

class node{
    public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};
void node::set_data(string s, double n){
    name = s;
    score = n;
}
class my_list{
    node *head, *tail;
    public:
    my_list();
    void insert_node(node t);
    void show_all_data();
};
my_list::my_list(){
    head = NULL;
    tail = NULL;
}
void my_list::show_all_data(){
    node *p;
    for(p=head;p!=NULL;p=p->link){
        cout << p->name << ":" << p->score<<endl;
    }
}
void my_list::insert_node(node t){
    node *temp;
    temp = new node;
    (*temp) = t;

    if(head == NULL){
        head = temp;
        head->link = NULL;
        tail = head;
        return;
    }else{
        node *newnode =head;
        node *oldnode = NULL;
        while(newnode->link != NULL){
            if(newnode->score > temp->score){
                if(oldnode == NULL){

                    temp -> link = newnode;
                    head = temp;
                    return;
                }
                if(oldnode->score < temp->score){
                    oldnode->link = temp;
                    oldnode = temp;
                    temp->link = newnode;
                    return;
                }

            }
            else if(newnode->score < temp->score){
                oldnode = newnode;
                newnode = newnode->link;
            }
        }
        if(newnode->score < temp->score){
            newnode->link = temp;
            temp->link = NULL;
            tail = temp;
            return;
        }else if(newnode->score > temp->score){
            oldnode->link = temp;
            temp->link = newnode;
            return;
        }
    }
}
int main(){
    my_list thelist;
    node tmp;
    tmp.set_data("Kim", 73.5); 
    thelist.insert_node(tmp); 

    tmp.set_data("Lee", 82.2);
    thelist.insert_node(tmp); 

    tmp.set_data("Park", 51.3);
    thelist.insert_node(tmp); 

    tmp.set_data("Choi", 95.1);
    thelist.insert_node(tmp); 

    tmp.set_data("Ryu", 71.3);
    thelist.insert_node(tmp); 

    tmp.set_data("Yang", 58.2);
    thelist.insert_node(tmp); 

    tmp.set_data("Hong", 83.5);
    thelist.insert_node(tmp);

    cout << "The list after insertions \n"; 
    thelist.show_all_data();

    return 0;
}