#include <vector>
#include <stack>

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int val = input.top();
        input.pop();
        return val;
    }
    
    int peek() {
        int val = input.pop();
        stack<int> output;
        output.push(val)
        while (input) {
            int val = input.pop();
            output.push(val)
        }
        input = output;
        return val;
    }
    
    bool empty() {
        if(input.empty()) return true;
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */