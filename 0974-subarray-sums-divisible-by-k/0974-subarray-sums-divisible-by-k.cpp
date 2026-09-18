class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int presum = 0,rem =0,total =0;
        for(int i=0;i<nums.size();i++){
            presum += nums[i];
            rem = presum%k;
            if(rem<0){
                rem += k;
            }
            if(m.count(rem)){
                total += m[rem];
                m[rem]++;
            }else{
                m[rem]=1;
            }
        }
        return total;
    }
};