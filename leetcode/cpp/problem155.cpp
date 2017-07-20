class MinStack {
    list<int>stack;
    list<int>minStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (minStack.empty() && stack.empty()) {
            stack.push_back(x);
            minStack.push_back(x);
        } else {
            stack.push_back(x);
            if (getMin() >= x) {
                minStack.push_back(x);
            }
        }

    }

    void pop() {
        int x = stack.back();
        stack.pop_back();
        if (x == minStack.back()) {
            minStack.pop_back();
        }

    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return minStack.back();
    }
};
