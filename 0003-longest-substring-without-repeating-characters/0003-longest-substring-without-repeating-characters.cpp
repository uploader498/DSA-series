class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>map;
        int start=0,end = 0,lenght =0;
        while(end<s.size()){
            map[s[end]]++;
            while(map[s[end]]>1){
                map[s[start]]--;
                start++;
            }
            lenght = max(lenght,end-start+1);
            end++;
        }
        return lenght;
    }
};