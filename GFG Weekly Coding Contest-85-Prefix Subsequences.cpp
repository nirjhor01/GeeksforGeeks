class Solution{
	public:
	int maximumPrefix(int n,int m,string s,string t)
	{
		//code here
		int ans = -1;
		vector<int>v[27];
		for(int i = 0; i < t.size(); ++i){
		    v[t[i] - 'a'].push_back(i + 1);
		}
		map<int,int>cs;

		cs[0] = 0;
		for(int i = 0; i < s.size(); ++i){
		    if(v[s[i] - 'a'].empty()) return i + 1;
		    auto lb = lower_bound(v[s[i]-'a'].begin(), v[s[i]-'a'].end(), cs[i - 1] + 1) - v[s[i]-'a'].begin();
		    if(lb == v[s[i]-'a'].size()){
		        ans = i + 1;
		        break;
		    }
		    cs[i] = v[s[i]-'a'][lb];
		    //v[s[i] - 'a'].erase(v[s[i] - 'a'].begin() + lb);
		}
		return ans;
			
	}
};
