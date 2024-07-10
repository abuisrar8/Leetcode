class Solution {
public:
    int minOperations(vector<string>& logs) {
        int counter = 0;
        for (const auto& i : logs) {
            if (i=="../"){ if (counter > 0) --counter;}                
            else if (i!="./") ++counter;
            
        }
        return counter;
        
    }
};
