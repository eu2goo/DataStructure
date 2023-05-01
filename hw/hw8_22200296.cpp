#include <iostream>
using namespace std;

class node {
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
    my_list(){
        head = NULL;
        tail = NULL;
    }
    int printMenu();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    bool list_empty();
    void delete_select(string s);
    void show_all_data();
    int num_nodes();
    double max_score();
    double min_score();
    double sum_score();
};
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
bool my_list::list_empty(){
    //list 가 엠티인지 확인
    if(head == NULL){
        return true;
    }else{
        return false;
    }
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
void my_list::show_all_data(){
    //list에 있는 데이타 출력
    node *p;
    cout << "Name : Score\n";
    for(p=head;p!=NULL;p=p->link){
        cout << p->name << " : " << p->score<<endl;
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
double my_list::max_score(){
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
int my_list::printMenu(){
    int menu;
    cout << "\n----Menu----\n";
    cout << "1. 첫 원소 추가\n";
    cout << "2. 끝 원소 추가\n";
    cout << "3. 첫 원소 삭제\n";
    cout << "4. 지정한 이름의 원소 삭제\n";
    cout << "5. 순서대로 원소 값 출력\n";
    cout << "6. 현재 내용 분석(전체 원소수, 최대 점수, 최소 점수, 평균 점수 출력)\n";
    cout << "7. 종료\n";

    cout << "           Select a command: ";
    cin >> menu;
    cout <<"\n\n";

    return menu;

}
int main(void){
    my_list element;

    while(1){
        node tmp;
        string name;
        double score;
        int menu = element.printMenu();
        if(menu == 7){
            break;
        }
        if(menu == 1){
            cout << "이름: ";
            cin >> name;
            cout << name <<"의 점수: ";
            cin >> score;
            tmp.set_data(name,score);
            element.add_to_head(tmp);
            cout << "=> 추가됨!!\n";
        }
        if(menu == 2){
            cout << "이름: ";
            cin >> name;
            cout << name <<"의 점수: ";
            cin >> score;
            tmp.set_data(name,score);
            element.add_to_tail(tmp);
            cout << "=> 추가됨!!\n";
        }
        if(menu == 3){
            if(element.list_empty()){
                cout << "리스트가 비어있음!\n";
            }else{
                tmp = element.delete_from_head();
                cout << tmp.name <<"의 데이터가 삭제됨!!\n";
            }
        }
        if(menu == 4){
            if(element.list_empty()){
                cout << "리스트가 비어있음!\n";
            }else{
                cout << "삭제할 정보의 이름: ";
                cin >> name;
                element.delete_select(name);
            }
        }
        if(menu == 5){
            if(element.list_empty()){
                cout << "리스트가 비어있음!\n";
            }
            else{
                element.show_all_data();
            }
        }
        if(menu == 6){
            if(element.list_empty()){
                cout << "리스트가 비어있음!\n";
            }else{
                int total = element.num_nodes();
                double max = element.max_score();
                double min = element.min_score();
                double totalsum = element.sum_score();
                cout << "현재 내용 분석\n";
                cout << "\n전체 원소수: " << total << endl;
                cout << "Max Score: " << max << endl;
                cout << "Min Score: " << min << endl;
                cout << "Avg Score: " << totalsum/total << endl;
            }
        }
    }
    return 0;
}