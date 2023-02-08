class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>st;
         vector<long long>mark(n, -1ll);
        for(long long i = 0; i < (long long)arr.size(); ++i){
                while(!st.empty() && arr[st.top()] < arr[i]){
                    mark[st.top()] =  arr[i];
                    st.pop();
                }
                st.push(i);
            
        }
        
        while(!st.empty()){
            st.pop();
        }
     
        return mark;
        
    }
};
