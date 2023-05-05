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
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    void show_all_data();
    void delete_low_score(double n);
    void delete_select(string s);
    void insert_node_ascending(node t);
    double max_score();
    double min_score();
    double sum_score();
    void list_merge(my_list b);
    friend void make_array_fromlist(node array[], my_list a);

    void invert();
    friend bool list_equal(my_list a, my_list b);
    
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
void my_list::add_to_tail(node t){
    //tail 로 add
    node *p;
    p = new node;
    (*p) = t;
    p->link = NULL;
    if(tail != NULL){
        tail->link = p;
    }else{
        head = p;
    }
    tail = p;
}
node my_list::delete_from_head(){
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if(head == NULL){
        tail = NULL;
    }
    return temp;
}
int my_list :: num_nodes(){
    //node의 num
    node *t;
    int count = 0;
    for(t = head;t != NULL;t = t->link){
        count++;
    }
    return count;
}
bool my_list::list_empty(){
    //list 가 엠티인지 확인
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}
void my_list::show_all_data(){
    //list에 있는 데이타 출력
    node *p;
    for(p=head;p!=NULL;p=p->link){
        cout << p->name << ":" << p->score<<endl;
    }
}
void my_list::delete_low_score(double n){
    //들어온 스코어보다 작은 데이터면 삭제
    if(head == NULL) return;
    node *newnode = head;
    node *temp;
    node *oldnode = NULL;
    while(newnode ->link != NULL){
        if(newnode->score < n && oldnode == NULL){
            temp = newnode;
            newnode = newnode->link;
            head = newnode;
            delete temp;
        }else if(newnode->score < n && oldnode != NULL){
            temp = newnode;
            newnode = newnode->link;
            oldnode->link = newnode;
            delete temp;
        }else{
            oldnode = newnode;
            newnode = newnode->link;
            
        }
    }
    if(newnode->score < n){
        temp = newnode;
        newnode = newnode->link;
        tail = oldnode;
        tail->link = NULL;
        if(newnode == NULL) head = NULL;

        delete temp;
    }
    else{
        tail = newnode;
        tail -> link = NULL;
    }

}
void my_list::delete_select(string s){
    node *newnode = head;
    node *oldnode = NULL;
    node *temp;
    int result = 0;
    if(newnode->name == s){
        temp = newnode;
        head = newnode->link;
        if(head == NULL){
            tail = NULL;
        }
        cout <<temp->name<< "의 데이터가 삭제됨!!\n";
        delete temp;
        result = 1;
        return;

    }
    while(newnode -> link != NULL){
        oldnode = newnode;
        newnode = newnode ->link;
        if(newnode->name == s){
            temp = newnode;
            oldnode->link = newnode->link;            
            if(newnode == tail){
                tail = oldnode;
            }
            cout <<temp->name<< "의 데이터가 삭제됨!!\n";
            delete temp;
            result = 1;
            return;
        }else{
            newnode = newnode->link;
            oldnode= oldnode->link;
        }
    }
    if(newnode->name == s){
        temp = newnode;
        tail = oldnode;
        oldnode->link = NULL;
        cout <<temp->name<< "의 데이터가 삭제됨!!\n";
        delete temp;
        result = 1;
        return;
    }
    cout << s << "의 데이터가 없음!\n";
    return;
}
void my_list::insert_node_ascending(node t){
    //ascending order로 list 정렬
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
double   my_list::max_score(){
    double max = 0;
    node *newnode = head;
    while(newnode -> link != NULL){
        if(newnode->score > max){
            max = newnode->score;
        }
        newnode = newnode->link;
    }
    if(newnode->score > max){
        max = newnode->score;
    }
    return max;
}
double my_list::min_score(){
    double min = 100;
    node *newnode = head;
    while(newnode -> link != NULL){
        if(newnode->score < min){
            min = newnode->score;
        }
        newnode = newnode->link;
    }
    if(newnode->score < min){
        min = newnode->score;
    }
    return min;
}
double my_list::sum_score(){
    double sum = 0;
    node *newnode = head;
    while(newnode -> link != NULL){
        sum += newnode->score;
        newnode = newnode->link;
    }
    sum += newnode->score;
    return sum;
}
void  make_array_fromlist(node array[], my_list a){
    if(a.head == NULL){
        return;
    }
    node *temp = a.head;
    int i=0;
    while(temp->link!= NULL){
        array[i].name = temp->name;
        array[i].score = temp->score;
        temp = temp->link;
        i++;
    }
    array[i].name = temp->name;
    array[i].score = temp->score;
}
void  my_list::list_merge(my_list b){
    node *end,*temp;
    temp = head;
    while(temp->link != NULL){
        temp = temp->link;
    }
    end = temp;
    end->link = b.head;
}
void my_list :: invert(){
    node *newhead = NULL;
    node *oldhead = head;
    node *tmp;
    while(oldhead != NULL){
        tmp = newhead;
        newhead = oldhead;
        oldhead = oldhead -> link;
        newhead -> link = tmp;
    }
    tail = head;
    head = newhead;
}
bool list_equal(my_list a, my_list b){
    return is_equal(a.head, b.head);
}
bool is_equal(node *p1, node *p2){
    if(p1 == NULL && p2 == NULL) return true;
    if((p1 == NULL) || (p2 == NULL)) return false;
    if((equal_data(*p1, *p2))){
        return (is_equal(p1->link, p2->link));
    }
    else{
        return false;
    }
}
bool equal_data(node t1, node t2){
    if(t1.name != t2.name){
        return false;
    }
    if(t1.score != t2.score){
        return false;
    }
    return true;
}