#include <iostream>
using namespace std;

#include <vector>

int main(void){
    vector <int> a;
   vector <double> b;

    a.push_back(2);
    a.push_back(3);
    a.push_back(5);

    cout << a.size() << endl;

    for(unsigned int i = 0; i < a.size();i++){
        cout << a[i] << endl;
    }
    vector <int> :: iterator p;

    for(p = a.begin(); p < a.end();p++){
        cout << *p << endl;
    }

}