class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1)return strs[0];
        string s = strs[0];
        string ans;
        for(int i=1;i<strs.size();i++){
            ans="";
            string common = strs[i];
            for(int j=0;j<common.size();j++){
                if(s[j]==common[j]){
                    ans+=s[j];
                }else{
                    break;
                }
            }
            s = ans;
        }
        return ans;
    }
};