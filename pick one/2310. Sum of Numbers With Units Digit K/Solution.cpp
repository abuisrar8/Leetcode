class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(!(num) ) return 0;
        for(int i=1;i<=10;++i)
        if (((k*i) % 10 == num % 10) && i*k<=num) return i;
        return -1;
    }
};
