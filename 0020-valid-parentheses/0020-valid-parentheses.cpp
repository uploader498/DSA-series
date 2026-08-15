class Solution {
public:
    bool isValid(string s){
        stack<char>one;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' ){
                one.push(s[i]);
            }
            else{
                if(one.empty()){
                    return false;
                }
                char ch = one.top();
                one.pop();
                if(s[i]==')' && ch!='(')return false;
                if(s[i]==']' && ch!='[')return false;
                if(s[i]=='}' && ch!='{')return false;
            }
        }
        
        return one.empty();
    }
};