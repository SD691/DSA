class MyQueue {
public:
    stack<int> input,output;
    MyQueue() {
        
    }
    
    void push(int x) {
        
        input.push(x);
    }
    
    int pop() {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }

        if(output.empty()){
            return -1;
        }
        int y = output.top();
        output.pop();

        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        return y;
    }
    
    int peek() {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }

        if(output.empty()){
            return -1;
        }
        int z = output.top();
         while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        return z;
        
    }
    
    bool empty() {
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        if(output.empty()){
            return true;
        }
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