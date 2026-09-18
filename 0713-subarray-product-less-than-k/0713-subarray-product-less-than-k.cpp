class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1,start=0,end=0,total=0;
        while(end<nums.size()){
            product *= nums[end];
            while(product > k && start<= end){
                product /= nums[start];
                start++;
            }
            if(product<k){
                total += (end-start)+1;
            }
            end++;
        }
        return total;
    }
};