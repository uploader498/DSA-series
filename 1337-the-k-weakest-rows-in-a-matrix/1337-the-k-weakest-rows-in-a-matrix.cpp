class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(int i=0;i<mat.size();i++){
            int soldier =0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                soldier++;
            }
            p.push(make_pair(soldier,i));
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};