#include <bits/stdc++.h>
using namespace std;

class MaxStack {
    stack<int> st;
    stack<int> maximum;

public:
    void push(int x) {
        st.push(x);

        if (maximum.empty())
            maximum.push(x);
        else
            maximum.push(max(x, maximum.top()));
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is Empty\n";
            return;
        }

        st.pop();
        maximum.pop();
    }

    int top() {
        if (st.empty())
            return -1;

        return st.top();
    }

    int getMax() {
        if (maximum.empty())
            return -1;

        return maximum.top();
    }
};

int main() {
    MaxStack s;

    int n;
    cin >> n;

    while (n--) {
        string operation;
        cin >> operation;

        if (operation == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (operation == "pop") {
            s.pop();
        }
        else if (operation == "top") {
            cout << "Top: " << s.top() << endl;
        }
        else if (operation == "max") {
            cout << "Maximum: " << s.getMax() << endl;
        }
    }

    return 0;
}
