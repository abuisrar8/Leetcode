class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
	    cin.tie(nullptr);cout.tie(nullptr);
        vector<int> frequency(n,0);
        for(auto& country:roads)
        {
            ++frequency[country[0]];    ++frequency[country[1]];
        }
        sort(frequency.begin(),frequency.end());
        long long maxImportance=0;
        for(long long i=0;i<n;i++) maxImportance +=frequency[i]*(i+1);

        return maxImportance;
        
        
    }
};
