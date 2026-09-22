class Solution {
public:
    int maxArea(vector<int>& height){
        int maxwater =0,totalwater=0;
        int start=0,end=height.size()-1;;
        while(start!=end){
            if(height[start]>height[end]){
                maxwater=height[end]*(end-start);
                end--;
            }else{
                maxwater=height[start]*(end-start);
                start++;
            }
            totalwater = max(maxwater,totalwater);
        }
        return totalwater;
    }
};