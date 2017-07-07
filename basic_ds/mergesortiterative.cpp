#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

/* Iteratitve (Loop-based) MergeSort
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
    int multiplier = ceil(log2(r - l + 1));
    int delta = 1;
    for (int i = 1; i <= multiplier; i++) {
        delta *= 2;
        for (int j = 0; j <= r; j += delta) {
            int _l = j,
                _r = min(r, j + delta - 1);
            int m = _l + delta/2 - 1;
            if (m >= _r) continue;
            merge(iarr, _l, m, _r);
        }
    }
}

int main() {
    vector<int> num = {3, 2, 1, 4, 7, 6, 5, -98, 489, INT_MAX, INT_MIN};
    mergesort(num, 0, num.size() - 1);
    copy(num.begin(), num.end(), ostream_iterator<int>(std::cout, " "));
    return 0;
}
