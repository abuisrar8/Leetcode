class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int frequency[1001] = {0};
        for(int i:nums1) frequency[i]++;
        vector<int> intersection;
        for(int i:nums2) if (0<frequency[i]--) intersection.push_back(i);
        return intersection;

        
    }
};
