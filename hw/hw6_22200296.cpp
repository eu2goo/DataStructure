#include <iostream>
using namespace std;

#define Q_SIZE 20

class element{
    public:
    string name;
    int page;
    int price;
    void set_data(string s,int n1, int n2);
};
void element :: set_data(string s,int n1, int n2){
    name = s;
    page = n1;
    price = n2;
}
class my_queue{
    element q[Q_SIZE];
    int front,rear;
    public :
    my_queue();
    void display_q();
    void insert_q(element x);
    element delete_q();
    bool queue_full();
    bool queue_empty();
};
my_queue :: my_queue(){
    front = 0;
    rear = 0;
}
void my_queue::insert_q(element x){
    if(!queue_full()){
        string n;
        int p1, p2;
        cout << "Name of Book: ";
        cin >> n;
        cout << "Pages: ";
        cin >> p1;
        cout << "Price: ";
        cin >> p2;

        x.set_data(n,p1,p2);
        q[rear] = x;
        rear = (rear+1)%Q_SIZE;
        cout << "Inserted!\n";
    }else{
        cout << "Queue is full!\n";
    }
}
void my_queue::display_q(){
    cout << "\n\nFront element =>\n";
    cout << "Book name: " << q[front].name << "\n";
    cout << "Book pages: " << q[front].page << "\n";
    cout << "Price: " << q[front].price << "\n";
}

element my_queue::delete_q(){
    element tmp;
    if(!queue_empty()){
        tmp = q[front];
        front = (front+1)% Q_SIZE;
        cout << "Information of " << tmp.name << " is deleted!\n";
        return (tmp);
    }else{
        cout << "Queue is empty!\n";
        return (tmp);
    }
}
bool my_queue::queue_full(){
    if((rear+1)%Q_SIZE == front){
        return true;
    }else{
        return false;
    }
}
bool my_queue::queue_empty(){
    if(rear == front){
        return true;
    }else{
        return false;
    }
}
int printmenu(){
    int menu;
    cout << "\n\n-- Menu --\n\n";
    cout << "1) Insert a node\n";
    cout << "2) Delete a node\n";
    cout << "3) Show the front element\n";
    cout << "0) Quit\n";
    cout << "                            Select a command: ";
    cin >> menu;

    return menu;
}

int main(){
    int menu;
    my_queue book;

    while(1){
        element tmp;
        menu = printmenu();
        if(menu == 0){
            cout << "Quit!!\n";
            break;
        }
        if(menu == 1){
            book.insert_q(tmp);
        }
        if(menu == 2){
            book.delete_q();
        }
        if(menu == 3){
            if(!book.queue_empty()){
                book.display_q();
            }else{
                printf("No information! Queue is empty!\n");
            }
        }
    }
}
