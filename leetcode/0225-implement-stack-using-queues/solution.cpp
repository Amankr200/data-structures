class MyStack {
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int sz = q.size();

        // Rotate previous elements to back
        for (int i = 1; i < sz; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int topVal = q.front();
        q.pop();
        return topVal;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
