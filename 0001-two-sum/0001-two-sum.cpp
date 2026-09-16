class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>m;
        int remain = 0;
        for(int i=0;i<nums.size();i++){
            remain = target-nums[i];
            if(m.count(nums[i])){
                ans.push_back(m[nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else{
                m[remain]=i;
            }
        }
        return ans;
    }
};