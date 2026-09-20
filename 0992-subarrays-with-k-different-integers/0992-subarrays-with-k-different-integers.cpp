class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int end = 0,start =0,count =0,total=0;
        int n = nums.size();
        while(end < n){
            m[nums[end]]++;
            if(m[nums[end]]==1)
            count++;

            while(count==k){
                total += n-end;
                m[nums[start]]--;
                if(m[nums[start]]==0){
                    count--;
                }
                start++;
            }
            end++;
        }
        end =0;
        start = 0;
        count=0;
        k++;
        m.clear();
        while(end < n){
            m[nums[end]]++;
            if(m[nums[end]]==1)
            count++;

            while(count==k){
                total -= n-end;
                m[nums[start]]--;
                if(m[nums[start]]==0){
                    count--;
                }
                start++;
            }
            end++;
        }
        return total;
    }
};