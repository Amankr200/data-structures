class MinStack {
    stack<long long> st;
    long long mini;

public:
    

    // Push operation
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            mini = x;
        } 
        else if (x >= mini) {
            st.push(x);
        } 
        else {
            // Encode value
            long long encoded = 2LL * x - mini;
            st.push(encoded);
            mini = x;
        }
    }

    // Pop operation
    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini) {
            // Decode previous minimum
            mini = 2 * mini - topVal;
        }
    }

    // Top element
    int top() {
        if (st.empty()) return -1;

        long long topVal = st.top();

        if (topVal >= mini)
            return topVal;
        else
            return mini;  // Actual top was the current min
    }

    // Get minimum element
    int getMin() {
        if (st.empty()) return -1;
        return mini;
    }
};
