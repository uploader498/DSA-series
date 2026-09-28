class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        stack<char>stack;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stack.push(s[i]);
            }
            if(stack.size()>count){
                count=stack.size();
            }
            if(s[i]==')'){
                stack.pop();
            }
        }
        return count;
    }
};