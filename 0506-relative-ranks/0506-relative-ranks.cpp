class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>p;
        for(int i=0;i<score.size();i++){
            p.push(make_pair(score[i],i));
        }
        int s = score.size();
        vector<string>ans(s);
        for(int i=0;i<s;i++){
            int index = p.top().second;
            p.pop();
            if(i==0){
                ans[index]="Gold Medal";
            }
            else if(i==1){
                ans[index]="Silver Medal";
            }else if(i == 2){
                ans[index]="Bronze Medal";
            }else
                ans[index]=to_string(i+1);
        }
        return ans;
    }
};