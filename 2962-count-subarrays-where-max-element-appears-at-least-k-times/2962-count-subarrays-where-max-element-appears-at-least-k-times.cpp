class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int maxele =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxele = max(maxele,nums[i]);
        }
        long long total=0;
        int end =0,start=0,count =0;
        while(end < n){
            m[nums[end]]++;
            if(nums[end]==maxele){
                count++;
            }
            while(count==k){
                total += n-end;
                if(nums[start]==maxele){
                    count--;
                }
                start++;
            }
            end++;
        }
        return total;
    }
};