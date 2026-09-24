class Solution {
public:
    int corect(int num){
        int temp = num%10;
        temp*=10;
        return num=temp;
    }
    int smallestIndex(vector<int>& nums){
        if(nums[0]==0)return 0;
        int temp,num;
        for(int i=0;i<nums.size();i++){
            num = nums[i];
            temp=0;
            while(num){
                temp+=num%10;
                num/=10;
            }
            if(temp==i)
            return i;
        }
        return -1;
    }
};