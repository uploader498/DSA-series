class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p;
        for(int i=0;i<stones.size();i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int stone = p.top();
            p.pop();
            stone -= p.top();
            p.pop();
            if(stone){
                p.push(stone);
            }
        }
        return p.empty() ? 0 : p.top();
    }
};