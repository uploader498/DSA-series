class Solution {
public:
    bool checkDivisibility(int n) {
        vector<int>nums;
        int v = n;
        while(n>0){
            nums.push_back(n%10);
            n = n/10;
        }
        int sumed = 0;
        int product = 1;
        int i = nums.size()-1;
        while(i>-1){
            sumed = sumed + nums[i];
            product=product * nums[i];
            i--;
        }
        if( v%(sumed+product) == 0){
            return true;
        }else
        return false;
    }
};