class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr =0;
        int count =1;
        int point;
        for(int i=0;i<nums.size();i++){
            if(nums[curr]!=nums[i]){
                count++;
                curr++;
                nums[curr]=nums[i];
                point=i;
                while(point!=curr){
                    nums[point]==-1;
                    point--;
                }
            }
        }
        return count;
    }
};