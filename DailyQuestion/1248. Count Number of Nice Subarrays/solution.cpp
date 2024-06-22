class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); 

        int n = nums.size();
        int leftOdd = 0, rightOdd = 0;
        int countOdd = 0;
        int result = 0;
        int leftSubarray = 0;

    

        while(rightOdd<n)
        {
            if(nums[rightOdd]%2 == 1)
            {
                countOdd++;
                leftSubarray =0;
            }
            while(countOdd == k)
            {
                if(nums[leftOdd]%2 ==1) countOdd--;
                leftSubarray++;
                leftOdd++;
            }
            result +=leftSubarray;
            rightOdd++;
        }
        return result;
    }
};
