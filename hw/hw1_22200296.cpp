#include <iostream>
using namespace std;

struct weight {
  int gram, kilo;

public:
  void set_weight(int k, int g);
  int get_weight();
};
weight add_weight(weight w1, weight w2) {
  weight w;
  w.gram = (w1.gram + w2.gram) % 1000;
  w.kilo = (w1.kilo + w2.kilo) + (w1.gram + w2.gram) / 1000;

  return w;
}
bool less_than(weight w1, weight w2) {
  int weight1, weight2;
  weight1 = w1.gram + w1.kilo * 1000;
  weight2 = w2.gram + w2.kilo * 1000;

  if (weight1 < weight2) {
    return true;
  } else {
    return false;
  }
}

void weight ::set_weight(int k, int g) {
  gram = g;
  kilo = k;
}

int weight ::get_weight() {
  return gram + kilo*1000;
}

int main(void) {

  weight w1, w2, w3; // weight라는 class object 3개 생성

  w1.set_weight(3, 400); // w1을 3kg 400 g으로

  w2.set_weight(2, 700); // w2을 2kg 700 g으로

  w3 = add_weight(w1, w2); // w1과 w2을 더하여 w3에 à w3는 6kg 100g

  cout << w3.get_weight() << "grams\n"; // w3의 값 ‘6100 grams’ 출력

  if (less_than(w1, w2)) // w1이 w2보다 작은 값인가 판단

    cout << "yes.\n";

  else

    cout << "no. \n"; // 작지 않으므로 ‘no’ 출력
}