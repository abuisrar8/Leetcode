class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customer) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        
        double sum =0;
        int clockTime = customer[0][0];
        for(int i =0;i<customer.size();i++)
        {
            if(clockTime < customer[i][0]) clockTime = customer[i][0];
            clockTime += customer[i][1];
            sum += clockTime - customer[i][0];
        }
        return sum/customer.size();
    }
};
