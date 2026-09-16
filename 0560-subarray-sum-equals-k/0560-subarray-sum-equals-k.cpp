class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int presum = 0;
        m[0]=1;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            presum += nums[i];
            if(m.count(presum-k)){
                total += m[presum-k];
                m[presum]++;
            }else{
                m[presum]++;
            }
        }
        return total;
    }
};