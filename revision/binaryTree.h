#include <iostream>
using namespace std;

class node{
    public:
    string name;
    double score;
    node *left, *right;
    void set_data(string s, double n){
        name = s;
        score = n;
    }
};
class my_tree{
    public:
    int node_count; //현재 node 수
    node *root; // root를 가리키는 pointer
    my_tree(){ // 초기화 constructor : 초기 empty 상태 설정 
        node_count = 0;
        root = NULL;
    }
    int insert_root(node t); // root로 내용 t 추가
    int insert_left(string tname, node tnode); // tname의 node 왼쪽에 t 추가
    int insert_right(string tname, node tnode); // tname의 node 오른쪽에 t 추가
    
    double score_sum(); // 모든 node의 score 합
    double score_average(); // 모든 node의 score 평균
    void print_data_inorder(); // inorder 순서로 모든 node의 값 출력
    void print_data_preorder(); // preorder 순서로 모든 node의 값 출력
    void print_data_postorder(); // postorder 순서로 모든 node의 값 출력

    double max_score();
    double get_score_byname(string tname);

    int n_d2_nodes();
    int n_d1_nodes();
    int n_leaf_nodes();

    void nonrecursive_inorder(); // non-recursive inorder traversal
    void print_data_levelorder();
};

//member 함수 아님
int node_insert_left(node *p, string tname, node tnode);
int node_insert_right(node *p, string tname, node tnode);
double sum_allnodes(node *p);
void inorder_print(node *p);
void preorder_print(node *p);
void postorder_print(node *p);

double maximum_score(node *p);
double score_searchname(node *p,string tname);

int num_degree2_nodes(node *p);
int num_degree1_nodes(node *p);
int num_leaf_nodes(node *p);

int my_tree::insert_root(node t){ //root로 내용 t 추가
    if(root != NULL){
        return 0;
    }
    node *p;
    p = new node;
    (*p) = t;
    p->left = NULL;
    p->right = NULL;
    root = p;
    node_count ++;
    return 1;
}
int my_tree::insert_left(string tname, node tnode){ // tname의 node 왼쪽에 t 추가
    int result;
    result = node_insert_left(root, tname, tnode);//member함수가 아님
    if(result == 1){
        node_count++;
    }
    return result;
}
int node_insert_left(node *p, string tname, node tnode){ //member 함수 아님 왼쪽에 추가
    int result;
    if(p == NULL) return 0;
    if(p->name == tname){
        if(p->left != NULL){
            return -1;
        }
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->left = t;
        return 1;
    }else{
        result = node_insert_left(p->left,tname,tnode);
        if(result != 0) return result;
        return node_insert_left(p->right,tname,tnode);
    }
}
int my_tree::insert_right(string tname, node tnode){
    int result;
    result = node_insert_right(root, tname, tnode);//member함수가 아님
    if(result == 1){
        node_count++;
    }
    return result;
}
int node_insert_right(node *p, string tname, node tnode){ //member 함수 아님 오른쪽 추가
    int result;
    if(p == NULL) return 0;
    if(p->name == tname){
        if(p->right != NULL){
            return -1;
        }
        node *t;
        t = new node;
        (*t) = tnode;
        t->left = NULL;
        t->right = NULL;
        p->right = t;
        return 1;
    }else{
        result = node_insert_right(p->right,tname,tnode);
        if(result != 0) return result;
        return node_insert_right(p->left,tname,tnode);
    }
}
double my_tree::score_sum(){
    return sum_allnodes(root);
}
double sum_allnodes(node *p){ //member 함수 아님 모든 노드의 score 더하기
    if(p == NULL){
        return 0;
    }
    return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}
void my_tree::print_data_inorder(){
    inorder_print(root);
}
void inorder_print(node *p){
    if(p == NULL) return;

    inorder_print(p->left);
    cout << p->name << " : " << p->score << endl;
    inorder_print(p->right);
}
void my_tree::print_data_preorder(){
    preorder_print(root);
}
void preorder_print(node *p){
    if(p == NULL) return;

    cout << p->name << " : " << p->score << endl;
    preorder_print(p->left);
    preorder_print(p->right);
}
void my_tree::print_data_postorder(){
    postorder_print(root);
}
void postorder_print(node *p){
    if(p == NULL) return;

    postorder_print(p->left);
    postorder_print(p->right);
    cout << p->name << " : " << p->score << endl;
}
double my_tree::score_average(){
    return score_sum() / node_count;
}
double my_tree::max_score(){
    return maximum_score(root);
}
double maximum_score(node *p){
    double max;
    if(p == NULL) return 0;
    max = p->score;
    if(max < maximum_score(p->left)){
        max = maximum_score(p->left);
    }
    if(max < maximum_score(p->right)){
        max = maximum_score(p->right);
    }
    return max;
}
double my_tree::get_score_byname(string tname){
    return score_searchname(root,tname);
}
double score_searchname(node *p,string tname){
    double result = -1;
    if(p == NULL) return -1;

    if(p->name == tname){
        return p->score;
    }
    else{
        result = score_searchname(p->left,tname);
        if(result > 0) return result;
        return score_searchname(p->right,tname); 
    }
    return result;
}
int my_tree:: n_d2_nodes(){
    return num_degree2_nodes(root);
}
int num_degree2_nodes(node *p){
    int result = 0;
    if (p == NULL) return 0;
    if(p->left != NULL && p->right != NULL){
        result = 1;
    }
    return num_degree2_nodes(p->left) + num_degree2_nodes(p->right) + result;
}
int my_tree:: n_d1_nodes(){
    return num_degree1_nodes(root);
}
int num_degree1_nodes(node *p){
    int result = 0;
    if (p == NULL) return 0;
    if((p->left != NULL && p->right == NULL)||(p->left == NULL && p->right != NULL)){
        result = 1;
    }
    return num_degree1_nodes(p->left) + num_degree1_nodes(p->right) + result;

}
int my_tree:: n_leaf_nodes(){
    return num_leaf_nodes(root);
}
int num_leaf_nodes(node *p){
    int result = 0;
    if(p == NULL) return 0;
    if(p->left == NULL && p->right == NULL){
        result = 1;
    }
    return num_leaf_nodes(p->left) + num_leaf_nodes(p->right) + result;
}
/*void my_tree:: nonrecursive_inorder(){
    nstack s1;
    node *t;
    t = root;
    while(1){
        while(t!=NULL){
            s1.push(t);
            t = t->left;
        }
        while(t==NULL){
            if(s1.stack_empty()){
                return;
            }
            t = s1.pop();
        }
        cout << t->name << ":" << t->score << endl;
        t=t->right;
    }
}*/
/*
void my_tree::print_data_levelorder(){
    my_queue a1;
    node *t;
    if(root == NULL) return;
    while(1){
        if(a1.q_empty()) return;

        t = a1.delete_q();
        cout << t->name << ":" << t->score << "\n";
        if(t->left != NULL){
            a1.insert_q(t->left);
        }
        if(t->right != NULL){
            a1.insert_1(t->right);
        }
    }
}
*/
void copy_tree(my_tree &t1, my_tree t2){ // t1 = 만들 tree, t2 = 이미 존재 하는 트리 
    t1.node_count = t2.node_count;
    t1.root = make_copy(t2.root);
}
node *make_copy(node *p){
    node *t;
    if(p == NULL) return NULL;
    t = new node;
    *t = *p; //data copy
    t->left = make_copy(p->left);
    t->right = make_copy(p->right);
    return t;
}
bool equal_tree(my_tree t1, my_tree t2){
    if(t1.node_count != t2.node_count) return false;
    return equal_test(t1.root, t2.root);
}
bool equal_test(node *p1, node *p2){
    if(p1 == NULL && p2 == NULL) return true;
    if(p1 == NULL) return false;
    if(p2 == NULL) return false;
    if(p1->name != p2->name) return false;
    if(p1->score != p2->score) return false;
    if(equal_test(p1->left,p2->left) && equal_test(p1->right, p2->right)) return true;

    return false;

}