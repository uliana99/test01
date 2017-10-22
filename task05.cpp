#include <iostream>
#include <vector>
using namespace std;

template <typename T>
bool myCompare(T i, T j) {
    return (i < j);
}

template <typename Iterator, typename arrType>
void merge_sort(Iterator first, Iterator last) {
    std::sort(first, last, myCompare<arrType>);
}

template <typename Iterator1, typename Iterator2>
auto merge(Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output) {
  while(true) {
        if (first1 == last1)
            return copy(first2, last2, output);

        if (first2 == last2)
            return copy(first1, last1, output);

        *output++ = (*first2 < *first1)? *first2++ : *first1++;
    }
}

int main() {
    vector<int> v1;
    v1.push_back(4);
    v1.push_back(0);
    v1.push_back(2);

    vector<int> v2;
    v2.push_back(3);
    v2.push_back(1);
    v2.push_back(5);

    merge_sort<vector<int>::iterator, int>(v1.begin(), v1.end());
    merge_sort<vector<int>::iterator, int>(v2.begin(), v2.end());

    vector<int> v_mrg(v1.size() + v2.size());

    merge<vector<int>::iterator, vector<int>::iterator, vector<int>::iterator>(v1.begin(), v1.end(), v2.begin(), v2.end(), v_mrg.begin());
    
    for(int i = 0; i < v_mrg.size(); i++)
      cout << v_mrg[i] << ' ';

    cout << endl;

    return 0;
}