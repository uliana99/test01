#include <iostream>
#include <vector>
using namespace std;

template <typename Iterator, typename T>
auto find_two_elements_with_sum(Iterator first, Iterator last, T c) {
  for (; first != last; ++first) {
    for (Iterator first_line = first; first_line != last; ++first_line) {
      if ((*first + *first_line) == c) {
        cout << *first << " " << *first_line << endl;
      }
    }
  }
}

int main() {
  vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  find_two_elements_with_sum(v1.begin(), v1.end(), 10);

  return 0;
}
