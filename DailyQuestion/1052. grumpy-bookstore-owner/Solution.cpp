
class Solution {
public:
    
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr); 
        
        int sumOfAllsatisfiedCustomer = 0;
        for(int i = 0;i<customers.size();i++) if(!grumpy[i]) sumOfAllsatisfiedCustomer +=customers[i];

        int currentSatisfactionWithSecretTech =0;       

        for(int i =0;i<minutes;i++) if(grumpy[i]) currentSatisfactionWithSecretTech +=customers[i];

        int maxSatisfactionWithSecretTech = currentSatisfactionWithSecretTech; 

        for(int i = minutes;i<customers.size();i++)
        {
            if(grumpy[i-minutes]) currentSatisfactionWithSecretTech -= customers[i-minutes]; 
            if(grumpy[i]) currentSatisfactionWithSecretTech += customers[i];
            maxSatisfactionWithSecretTech = max(maxSatisfactionWithSecretTech ,currentSatisfactionWithSecretTech);
        }
        

        return maxSatisfactionWithSecretTech+sumOfAllsatisfiedCustomer;

    }
};
