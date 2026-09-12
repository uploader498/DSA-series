class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1)return target[0]==1;
        priority_queue<long long>p;
        long long sum=0;
        for(int i=0;i<target.size();i++){
            p.push(target[i]);
            sum+=target[i];
        }
        long long maxm , remain , ele;
        while(p.top() != 1){
            maxm = p.top();
            p.pop();
            remain = sum - maxm;
            if(remain < 0 || remain >=maxm){
                return 0;
            }
            ele = maxm % remain;
            if(ele == 0){
                if(remain!=1)
                return 0;
                else
                return 1;
            }
            sum = remain + ele;
            p.push(ele);
        }
        return 1;
    }
};