class element { 
    public:
    string name;
    double score;
    void set_data(string n, double s); 
};
void element::set_data(string n, double s) {
    name = n;
    score = s; 
}

class my_heap {
    element h[HSIZE];
    int csize;
    void adjust(int t_root);
    public :
    my_heap();
    my_heap(element a[], int n); 
    int h_size();  
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    double score_sum();
    double score_average();
    int node_delete_by_name(string tname); 
}; 
my_heap :: my_heap(){
    csize = 0;
}
int my_heap :: h_size(){
    return csize;
}
bool my_heap :: heap_empty(){
    return (csize == 0);
}
bool my_heap :: heap_full(){
    return (csize >= HSIZE -1);
}
void my_heap :: insert_heap(element t){
    int k;
    csize ++;
    k = csize;
    while(k!= 1 && (h[k/2].score < t.score)){
        h[k] = h[k/2];
        k /= 2;
    }
    h[k] = t;
}
element my_heap :: delete_heap(){
    element t, tmp;
    int parent, child;
    parent = 1;
    child = 2;
    tmp = h[csize];
    csize --;
    t = h[1];
    while(chile <= csize){
        if((child < csize) && (h[chile].score < h[child+1].score)){
            child ++;
        }
        if(tmp)
    }
}