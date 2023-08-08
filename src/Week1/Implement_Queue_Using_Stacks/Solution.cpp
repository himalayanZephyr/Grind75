#include <stack>


class MyQueue {
    std::stack<int> stack1; // Acts as the front of the queue
    std::stack<int> stack2; // Acts as the back of the queue
public:
    MyQueue() {

    }
    
    void push(int x) {
        stack2.push(x);
    }
    
    int pop() {
        int top_element = peek();
        stack1.pop();
        return top_element;
    }
    
    int peek() {
        if(stack1.empty()) {
            while (!stack2.empty()){
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        return stack1.top();
    }
    
    bool empty() {
       if (stack1.empty() and stack2.empty()) {
           return true; 
       }
       else {
           return false;
       } 
    }
};