#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename Iterator1, typename Iterator2>
auto merge(Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output) {
  while (true) {
        if (first1 == last1)
            return copy(first2, last2, output);

        if (first2 == last2)
            return copy(first1, last1, output);

        *output++ = (*first2 < *first1)? *first2++ : *first1++;
    }
}

int main() {
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(8);

    list<int> l1;
    l1.push_back(3);
    l1.push_back(5);
    l1.push_back(7);

    vector<int> v_mrg(v1.size() + l1.size());
    vector<int>::iterator first1 = v1.begin(), last1 = v1.end(), output = v_mrg.begin();
    list<int>::iterator first2 = l1.begin(), last2 = l1.end();

    merge<vector<int>::iterator, list<int>::iterator, vector<int>::iterator>(first1, last1, first2, last2, output);
    for(int i = 0; i < v_mrg.size(); i++)
      cout << v_mrg[i] << ' ';

    cout << endl;

    return 0;
}