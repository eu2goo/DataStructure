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
int main(){
   my_heap   h1;
   element   temp;
   temp.set_data("Kim", 88);
   h1.insert_heap(temp);

   temp.set_data("Lee", 77);
   h1.insert_heap(temp);

   temp.set_data("Park", 98);
   h1.insert_heap(temp);

   temp.set_data("Choi", 74);
   h1.insert_heap(temp);

   temp.set_data("Ryu", 94);
   h1.insert_heap(temp);

   temp.set_data("Cho", 85);
   h1.insert_heap(temp);

   while (h1.h_size() > 0) {
    temp = h1.delete_heap();
    cout << temp.name << " : " << temp.score << "\n";
   }
   return 0;
}