
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

template <class data_type>
struct LinkedListNode {
  data_type data;
  LinkedListNode *next;
  LinkedListNode(data_type _data) : data(_data), next(nullptr) {};
};

template <class data_type>
class CUSTOM_Q
{
    LinkedListNode<data_type> *front, *back;
public:
    CUSTOM_Q() : front(nullptr), back(nullptr) {};
    data_type pop() {
        if (front == back)
            back = nullptr;
        data_type ret = front->data;
        LinkedListNode<data_type> *tobedeleted = front;
        front = front->next;
        delete tobedeleted;
        return ret;
    }

    void push(data_type item) {
        auto *tobeinserted = new LinkedListNode<data_type>(item);
        if (front == nullptr) {
            front = back = tobeinserted;
            return;
        }
        back->next = tobeinserted;
        back = back->next;
    }

    bool isempty() {
        return front == nullptr;
    }
};

int main() {
    
    CUSTOM_Q<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.push(5);

    while(!q.isempty())
        cout << q.pop() << endl;

    return 0;
}
