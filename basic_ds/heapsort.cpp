#include <iostream>
#include <vector>
using namespace std;

#define LCHILD(i) (2*i)
#define RCHILD(i) (2*i + 1)

void swap(vector<int>& iarr, int i, int j)
{
    int tmp = iarr[i];
    iarr[i] = iarr[j];
    iarr[j] = tmp;
}

void heapify(vector<int>& iarr, int i)
{
    if (i > iarr.size() - 1)
        return;
    int lc = iarr[LCHILD(i)];
    int rc = iarr[RCHILD(i)];
    int sm = min(min(lc, rc), iarr[i]);
    if (sm != iarr[i]) {
        if (lc <= rc) {
            swap(iarr, i, LCHILD(i));
            heapify(iarr, LCHILD(i));
        } else {
            swap(iarr, i, RCHILD(i));
            heapify(iarr, RCHILD(i));
        }
    }
}

void buildheap(vector<int>& iarr)
{
    for (int i = iarr.size()/2; i > 0; i--)
        heapify(iarr, i);
}

int main() {
    vector<int> iarr = { 9999, 4, 2, -1, 8, 5, 3};
    buildheap(iarr);
    for (auto num : iarr)
        cout << num << endl;
    return 0;
}
