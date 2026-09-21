class Solution {
public:
    unordered_map<char,int> m = {
    {'I',1}, {'V',5}, {'X',10},
    {'L',50}, {'C',100}, {'D',500}, {'M',1000}
    };
    int romanToInt(string s) {
        int ans=0;
        int prev = 10000;
        int temp =0;
        for(int i=0;i<s.size();i++){
            temp = m[s[i]];
            if(prev < temp){
                ans -= prev;
                ans += temp-prev;
            }else{
                ans += temp;
            }
            prev = temp;
        }
        return ans;
    }
};