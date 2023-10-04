//User function Template for C++

class Solution{
    public:
    int maxAnd(int N, vector<int> A){
        // code here
        int choosePos = -1;
        vector<long long>bit(61, 0);
        for(int i = 0; i < A.size(); i++){
            for(int b = 61; b >= 0; b--){
                long long mask = (1ll<<b);
                if((mask&A[i])){
                    bit[b]++; // count set bit
                }
            }
        }
        
        // Find the position where all the elements holds set bit except one
        for(int i = 0; i < 61; i++){
           if(bit[i] == N - 1) choosePos = i;
    
        }

        if(choosePos != -1){
            for(int i = 0; i < A.size(); i++){
                long long mask = (1ll<<choosePos);
                if((mask & A[i]) == 0){
                    A[i] = ((1ll<<60) -1); // store maximum value
                    break;
                }
            }
        }
        int ans = A[0];
        for(int i = 1; i < A.size(); i++) ans &= A[i];
        
        return ans;
    }
};
