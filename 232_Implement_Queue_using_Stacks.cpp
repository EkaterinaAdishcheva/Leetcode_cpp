
#include <vector>
#include <stack>

using namespace std;

class MyQueue {
stack<int> input;
int firstElement;
public:
    MyQueue() {
    }
    
    void push(int x) {
        if(input.empty()) {
            firstElement = x;
        }
        input.push(x);
    }
    
    int pop() {
        stack<int> output;
        while(!input.empty()) {
            int val = input.top();
            output.push(val);
            input.pop();
        }
        int top = output.top();
        output.pop();
        if(output.size() > 0) {
            firstElement = output.top();
        } 
        while(!output.empty()) {
            int val = output.top();
            input.push(val);
            output.pop();
        }
        return top;
    }
    
    int peek() {
        return firstElement;
        
    }
    
    bool empty() {
        return input.empty();
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