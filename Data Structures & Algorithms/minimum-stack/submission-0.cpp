class MinStack {
public:
    int ind = 0;
    unordered_map <int, int> idx;
    stack <int> mainStack;
    stack <int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || idx[minStack.top()] >= val){
            minStack.push(ind);
            idx[ind] = val;
            ind++;
        }
    }
    
    void pop() {
        if(idx[minStack.top()] == mainStack.top()){
            minStack.pop();
        }
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return idx[minStack.top()];
    }
};
