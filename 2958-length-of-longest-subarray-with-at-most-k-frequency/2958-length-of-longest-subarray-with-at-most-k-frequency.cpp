class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int start=0,end=0,count=0;
        while(end<nums.size()){
            m[nums[end]]++;
            while(m[nums[end]]>k){
                m[nums[start]]--;
                start++;
            }
            count=max(count,end-start+1);
            end++;
        }
        return count;
    }
};