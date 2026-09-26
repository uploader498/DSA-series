class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        unordered_map<string,string>map;
        for(int i=0;i<knowledge.size();i++){
                map[knowledge[i][0]] = knowledge[i][1];
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                i++;
                string temp = "";
                while(s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                if(map.count(temp)){
                    ans += map[temp];
                }else{
                    ans += "?";
                }
            }else{
            ans+=s[i];
            }
        }
        return ans;
    }
};