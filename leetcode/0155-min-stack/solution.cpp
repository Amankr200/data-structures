class MinStack {
    stack<pair<int, int>> st;  // {value, current_min}
public:
   // Push operation
    void push(int x) {
        if (st.empty()) {
            st.push({x, x});
        } else {
            int currentMin = min(x, st.top().second);
            st.push({x, currentMin});
        }
    }

    // Pop operation
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    // Top element
    int top() {
        if (st.empty()) return -1;
        return st.top().first;
    }

    // Get minimum element
    int getMin() {
        if (st.empty()) return -1;
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
