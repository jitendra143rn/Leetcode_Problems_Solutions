class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        stack<int>st;
        int size = nums.size();
        vector<int> nge(size, -1);
        int i = 0; 
        for(i = 2*size-1; i >= 0; i--)
        {
            int num = nums[i % size];
            while(!st.empty() && st.top() <= nums[i %size])
            {
                st.pop();
            }
            if(i < size)
            {
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(num); 
        }

        return nge;
    }
};
