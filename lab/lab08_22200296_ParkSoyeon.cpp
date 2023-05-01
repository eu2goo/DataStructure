#include <iostream>
using namespace std;

#define HSIZE 100

class element{
    public:
    string name;
    double score;
    void set_data(string n, double s);
};

void element :: set_data(string n, double s){
    name = n;
    score = s;
}
class my_heap{
    element h[HSIZE];
    int csize;//the number of elements
    public:
    my_heap(){
        csize = 0;
    }
    int h_size();
    element top_element();
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
};
bool my_heap :: heap_empty(){
    if(csize == 0) return true;
    return false;
}
bool my_heap :: heap_full(){
    if(csize >= HSIZE -1) return true;
    return false;
}
int my_heap::h_size(){
    return csize;
}
void my_heap::insert_heap(element t){
    int k;
    csize++;
    k = csize;
    while((k != 1)&&(t.score > h[k/2].score)){
        h[k] = h[k/2];
        k/=2;
    }
    h[k] = t;
}
element my_heap :: delete_heap(){
    element t, tmp;
    int parent,child;
    t = h[1];
    tmp = h[csize];
    csize--;
    parent = 1;
    child = 2;
    while(child <= csize){
        if((child < csize) && (h[child].score < h[child+1].score)) {
            child++;
        }
        if(tmp.score >= h[child].score){
            break;
        }
        h[parent] = h[child];
        parent = child;
        child  *= 2;
    }
    h[parent] = tmp;
    return t;
}
int printMenu(){
    int menu;
    cout << "\n\n";
    cout << "1. 원소 추가" << endl;
    cout << "2. 원소 삭제" << endl;
    cout << "3. 현재 원소 수 및  root 원소 조회" << endl;
    cout << "4. 종료" << endl;

    cout << "       Select Command: ";
    cin >> menu;
    cout << "\n\n";
    return menu;
}
element my_heap::top_element(){
    return h[1];
}
int main(){
   my_heap   h1;
   element   temp;
   int menu;
   while(1){
    menu = printMenu();
    if(menu == 1){
        if(!h1.heap_full()){
            string name;
            int score;
            cout << "Name: ";
            cin >> name;
            cout << "Score: ";
            cin >> score;

            temp.set_data(name,score);
            h1.insert_heap(temp); 
        }else{
            cout << "Heap is full!\n";
        }
    }
    else if(menu == 2){
        if(h1.heap_empty()){
            cout << "Heap is empty! Nothing to delete!\n";
        }else{
            temp = h1.delete_heap();
            cout << temp.name << " : " << temp.score << " is deleted!\n";
        }
    }
    else if(menu == 3){
        if(h1.heap_empty()){
            cout << "Heap is empty!\n";
        }else{
            temp = h1.top_element();
            cout << "Number of elements => " << h1.h_size() << endl;
            cout << "Root element => " << temp.name << " : " << temp.score << endl;
        }
    }
    else if(menu == 4){
        cout << "Exit!\n";
        break;
    }
    else{
        cout << "Enter the appropriate command!";
    }
   }
   return 0;
}