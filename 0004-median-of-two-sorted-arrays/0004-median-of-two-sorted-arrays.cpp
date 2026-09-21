class Solution {
public:
    vector<int> merge(vector<int>&nums1 ,vector<int>&nums2){
        vector<int>temp;
        int left = 0;
        int right = 0;
        while(left < nums1.size() && right < nums2.size()){
            if(nums1[left]<nums2[right]){
                temp.push_back(nums1[left]);
                left++;
            }else{
                temp.push_back(nums2[right]);
                right++;
            }
        }
        while(left < nums1.size()){
            temp.push_back(nums1[left]);
            left++;
        }
        while(right < nums2.size()){
            temp.push_back(nums2[right]);
            right++;
        }
        return temp;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>temp = merge(nums1,nums2);
        int n = temp.size();
        int mid = n/2;
        double ans =0;
        if(n%2==0){
            ans = temp[mid]+temp[mid-1];
            ans /= 2;
        }else{
            ans = temp[mid];
        }
        return ans;
    }
};