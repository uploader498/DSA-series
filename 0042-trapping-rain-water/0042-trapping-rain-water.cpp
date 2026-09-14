class Solution {
public:
    int lastwater(vector<int>& height,int index,int n){
        if(index==n)return 0;
        int currblock = 0;
        int totalwater = 0;
        int nextblock = 0;
        int addwater = 0;
        for(int i=index;i>=n;i--){
            nextblock=height[i];
            if(nextblock>currblock || nextblock==currblock){
                totalwater += addwater;
                addwater =0;
                currblock = nextblock;
            }else if(currblock){
                addwater += currblock-nextblock;
            }
        }
        return totalwater;
    }
    int trap(vector<int>& height) {
        int currblock = 0;
        int totalwater = 0;
        int nextblock = 0;
        int addwater = 0;
        for(int i=0;i<height.size();i++){
            nextblock=i;
            if(height[nextblock]>height[currblock] || height[currblock]==height[nextblock]){
                totalwater += addwater;
                addwater =0;
                currblock = nextblock;
            }
            addwater += height[currblock]-height[nextblock];
        }
        
        return totalwater+lastwater(height,height.size()-1,currblock);
        
    }
};