#include <iostream>
#include <vector>
using namespace std;
 
void swap(vector<int>& iarr, int i, int j)
{
    int tmp = iarr[i];
    iarr[i] = iarr[j];
    iarr[j] = tmp;
}

int partition(vector<int>& iarr, int st, int en) {
    int pivot = iarr[st];
    int j = st + 1;
    for (int i = st + 1; i <= en; i++) {
        if (iarr[i] < pivot) {
            swap(iarr, i, j);
            j++;
        }
    }
    swap(iarr, j-1, st);
    return j - 1;
}
 
void _qsort(vector<int>& iarr, int l, int r) {
    if (l < r) {
        int p = partition(iarr, l, r);
        _qsort(iarr, l, p - 1);
        _qsort(iarr, p+1, r);
    }
}
 
void qsort(vector<int>& iarr) {
    _qsort(iarr, 0, iarr.size() - 1);
}
 
int main() {
    vector<int> iarr = { 4, 2, -1, 8, 5, 3};
    qsort(iarr);
    for (auto num : iarr)
        cout << num << endl;
    return 0;
}
