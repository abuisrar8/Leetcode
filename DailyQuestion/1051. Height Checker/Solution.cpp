class Solution {
public:
    int heightChecker(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int n = heights.size();
        vector<int> sortedheights = heights;
        sort(sortedheights.begin(),sortedheights.end());
        int count=0;
        for(int i=0;i<n;i++)
        {
            if (heights[i] != sortedheights[i]) count++;
        }
        return count;
    }
};
