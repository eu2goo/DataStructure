#include <iostream>
using namespace std;

int comb(int n, int k){
    if( k==0 || k == n){
        return 1;
    }else{
        return n * comb(n-1,k-1);
    }
}
int main(void){
    int n,k;
    cin >> n;
    cin >> k;
    int output = comb(n,k);
    cout << "num: "<<output;
}