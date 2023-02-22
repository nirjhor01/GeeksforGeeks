class Solution {
  public:
    int bitMagic(int n, vector<int> &a) {
        // code here
        int low = 0;
        int high = n - 1;
        int ans = 0;
        
        while(low <= high){
            if(a[low] != a[high]) ans++;
            low++;
            high--;
        }
        return (ans / 2) + (ans % 2 == 1);
    }
};
