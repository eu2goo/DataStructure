/*22200296 박소연 데이타구조 과제9*/

#include <iostream>
using namespace std;

class s_record {
    public:
    string s_id;
    string name;
    double score;
    s_record();
    s_record(string s1, string s2, double n);
};
s_record::s_record() {
    s_id = "";
    name = "";
    score = 0;
}
s_record :: s_record(string s1, string s2, double n){
    s_id = s1;
    name = s2;
    score = n;
}

void show_thelist(s_record a[], int n){
    for(int i = 0;i < n; i++){
        cout << a[i].s_id << " : " << a[i].name << " : " << a[i].score << endl;
    }
}

//sort
void insertion_sort(s_record a[], int n);
void bubble_sort(s_record a[], int n);
void selection_sort(s_record a[], int n);
void quick_sort(s_record a[], int left, int right);
void heap_sort(s_record a[], int n);
void merge_sort(s_record a[], int n);

void swap(s_record &a, s_record &b);
void adjust(s_record a[], int root, int n);
void merge_pass(s_record a[], s_record b[], int n, int s);
void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4);


int main(){
    s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 }, 
            { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },
            { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },
            { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };
    int n = 12;
    // insertion_sort(s_list, n);
    // bubble_sort(s_list, n);
    //selection_sort(s_list, n);
    //quick_sort(s_list, 0, n-1);
    //heap_sort(s_list, n);
    merge_sort(s_list, n);
    cout << "< The result of the sorting >" << endl;
    show_thelist(s_list, n);
    return 0;
}

/*-----------------------------------------------------------------*/

/*
현 위치 보다 앞쪽에서 자신보다 큰 값을 뒤로 이동
더 이상 큰 값이 없거나 맨 앞 위치에 도달하면 그곳에 원소를 넣음
*/
//Insertion sort
void insertion_sort(s_record a[], int n){
    for(int i = 1; i < n; i++){
        s_record temp = a[i];
        int k = i - 1;
        while((k >= 0) && (temp.s_id < a[k].s_id)){
            a[k + 1] = a[k];
            k--;
        }
        a[k+1] = temp;
    }
}

/*
인접한 두 원소를 비교, 앞쪽이 크면 교환
범위를 1씩 감소시키며 반복
*/
//Bubble sort
void bubble_sort(s_record a[], int n){
    for(int i = n-1; i >= 0 ; i--){
        for(int j = 0; j < i; j++){
            if(a[j].s_id > a[j+1].s_id){
                s_record temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

/*
대상 범위에서 가장 작은 값을 찾아
 대상 범위의 첫 원소와 교환
*/
//Selection sort
void selection_sort(s_record a[], int n){
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i + 1; j < n; j ++){
            if(a[min].s_id > a[j].s_id){
                min = j;
            }
        }
        s_record temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
void swap(s_record &a, s_record &b){
    s_record temp = a;
    a = b;
    b = temp;
}

/*
대상 범위의 원소수가 1 이하이면 return
대상 범위의 첫 원소를 기준 원소(pivot)로 하여
pivot 보다 key 값이 큰 원소는 뒤로, 작은 원소는 앞으로 이동하여 list를 분리(partitioning)
앞 부분과 뒷부분을 다시 quik sort 실행
recursion
*/
//Quick sort
// void quick_sort(s_record a[], int left, int right) {
//     s_record pivot, temp;
//     int i, j;
//     if (left >= right) return;
//     i = left+1;
//     j = right;
//     pivot = a[left];
//     while (i <= j) {
//         while (i <= right && a[i].s_id < pivot.s_id) {
//             i++;
//         }
//         while (a[j].s_id > pivot.s_id) {
//             j--;
//         }
//         if (i < j) {
//             swap(a[i], a[j]);
//         }else{
//             swap(a[left], a[j]);
//         }
//     }
//     quick_sort(a, left, j - 1);
//     quick_sort(a, j + 1, right);
// }
void quick_sort(s_record a[], int left, int right){
    s_record pivot, temp;
    int i,j;
    if(left >= right) return;
    i = left;
    j = right + 1;
    pivot = a[left];
    do{
        do{
            i++;
        }while((i <= right) && (a[i].s_id < pivot.s_id));
        do{
            j--;
        }while(a[j].s_id > pivot.s_id);
        if(i < j){
            swap(a[i],a[j]);
        }
    }while(i < j);
    swap(a[left],a[j]);
    quick_sort(a,left,j-1);
    quick_sort(a,j+1,right);
}

/*
초기 heap 구성
다음을 n-1회 반복
heap 에서 첫 원소와 끝 원소의 위치를 교환
heap의 사이즈를 1 감소 시킴
root를 기준으로 reheaping(adjust)
*/
//Heap sort (0번쨰 원소부터 채워진 경우)
void heap_sort(s_record a[], int n){
    int i;
    s_record temp;
    int size = n-1;
    
    for(i = (size-1)/2;i >= 0;i--){
        adjust(a,i,size);
    }
    for(int i=size-1;i>=0;i--){
        temp = a[0];
        a[0] = a[i+1];
        a[i+1] = temp;
        adjust(a,0,i);
    }
}
void adjust(s_record a[], int i, int size) {
    int j = 2 * i + 1;
    s_record temp = a[i];
    while (j <= size) {
        if (j < size && a[j].s_id < a[j + 1].s_id) {
            j++;
        }
        if (temp.s_id >= a[j].s_id) {
            break;
        }
        a[(j - 1) / 2] = a[j];
        j = 2 * j + 1;
    }
    a[(j - 1) / 2] = temp;
}


/*
사이즈를 1부터 시작하여 2배로 증가시켜서 다음을 반복
주어진 리스트를 크기 s의 sublist로 고려하여 2개씩 merge
s가 전체 크기가 될 때 까지 반복
*/
//Merge sort
void merge_sort(s_record a[], int n) {
    int s = 1;
    s_record* b = new s_record[n];
    while (s < n) {
        merge_pass(a, b, n - 1, s);
        s *= 2;
        merge_pass(b, a, n - 1, s);
        s *= 2;
    }
    delete[] b;
}

void merge_pass(s_record a[], s_record b[], int n, int s) {
    int i, j;
    for (i = 0; i <= n - 2 * s + 1; i += 2 * s) {
        merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
    }
    if (i + s <= n) {
        merge(a, b, i, i + s - 1, i + s, n);
    }
    else {
        for (j = i; j <= n; j++) {
            b[j] = a[j];
        }
    }
}

void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4) {
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;
    while (i <= n2 && j <= n4) {
        if (a[i].s_id <= a[j].s_id) {
            b[k++] = a[i++];
        }
        else {
            b[k++] = a[j++];
        }
    }
    if (i > n2) {
        for (t = j; t <= n4; t++) {
            b[t] = a[t];
        }
    }
    else {
        for (t = i; t <= n2; t++) {
            b[k+t-i] = a[t];
        }
    }
}
