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
int main()
{
        my_tree  thetree;
        node  tmp;

        tmp.set_data("Kim", 81.1);
        thetree.insert_root(tmp);
        tmp.set_data("Lee", 86.2);
        thetree.insert_left("Kim", tmp);
        tmp.set_data("Park", 79.4);
        thetree.insert_right("Kim", tmp);
        tmp.set_data("Choi", 77.8);
        thetree.insert_left("Lee", tmp);
        tmp.set_data("Ryu", 92.2);
        thetree.insert_right("Lee", tmp);
        tmp.set_data("Cho", 68.6);
        thetree.insert_right("Park", tmp);
        tmp.set_data("Yang", 72.8);
        thetree.insert_left("Ryu", tmp);
        tmp.set_data("Jung", 62.3);
        thetree.insert_left("Cho", tmp);
        cout << "the max. score  = " << thetree.max_score() << endl << endl;

        string tname;
        cout << "The student name for score-search : "; // 점수를 검색하고자 하는 학생의 이름
        cin >> tname;
        double tscore = thetree.get_score_byname(tname);
        if (tscore < 0)
                cout << "\nThe name "<< tname << " does not exist in the tree.\n\n";
        else
                cout << tname << "\'s score : " << tscore << endl;
        return 0;

}        
