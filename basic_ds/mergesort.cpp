#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

/* Iterator based MergeSort
 */

void merge(vector<int>& iarr, int l, int m, int r) {
    vector<int> left, right;
    left.assign(iarr.begin() + l, iarr.begin() + m + 1);
    right.assign(iarr.begin() + m + 1, iarr.begin() + r + 1);
    auto il = left.begin(), ir = right.begin();
    auto it = iarr.begin() + l;
    while (il != left.end() and ir != right.end()) {
        if (*il <= *ir)
            *it++ = *il++;
        else
            *it++ = *ir++;
    }
    while (il != left.end()) *it++ = *il++;;
    while (ir != right.end()) *it++ = *ir++;
}

void mergesort(vector<int>& iarr, int l, int r) {
    if (l < r) {
        auto m = l + ((r - l) >> 1);
        mergesort(iarr, l, m);
        mergesort(iarr, m + 1, r);
        merge(iarr, l, m , r);
    }
}

int main() {
    vector<int> num = {3, 2, 1, 4, 7, 6, 5, -98, 489, INT_MAX, INT_MIN};
    mergesort(num, 0, num.size() - 1);
    copy(num.begin(), num.end(), ostream_iterator<int>(std::cout, " "));
    return 0;
}
