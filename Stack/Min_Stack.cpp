class MinStack {
public:
    long mini;
    stack <long> st;
    //MinStack() {
     //   stack <int> st;
    //}
    
    void push(int val) {
        
        if(st.empty())
        {
            st.push(val);
            mini = val;
        }
        else
        {
            if(val > mini ) st.push(val);
            else
            {
                st.push(2L * val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        
        if(st.empty())
            return ;
        
        long x = st.top();
        st.pop();

        if(x < mini)
            mini = 2L *mini - x;
    }
    
    int top() {
        if(st.empty())
            return NULL;
        long x = st.top();

        if( mini < x) return x;

        return mini;
    }
    
    int getMin() {
        return mini;
        
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
