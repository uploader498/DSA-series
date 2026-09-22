class Solution {
public:
    bool isPalindrome(int x) {
        int dum = x;
        long long store =0;
        while(dum){
            int y = dum%10;
            if(y>=0){
            store*=10;
            store+=y;
            }
            dum/=10;
        }
        return store==x;
    }
};