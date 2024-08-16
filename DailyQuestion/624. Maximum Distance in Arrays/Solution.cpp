class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int maxDistance =0;
        int low = arrays[0][0];
        int high = arrays[0].back();

        for(int i =1 ; i<arrays.size();++i)
        {
            maxDistance = max(maxDistance,abs(arrays[i].back()-low));
            maxDistance = max(maxDistance,abs(high-arrays[i][0]));
            low = min(low,arrays[i][0]);
            high = max(high,arrays[i].back());
        }
        return maxDistance;
        
    }
};
