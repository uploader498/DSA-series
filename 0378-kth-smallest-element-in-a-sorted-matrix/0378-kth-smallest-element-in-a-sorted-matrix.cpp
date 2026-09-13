class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<pair<int,pair<int,int>>>temp;
        for(int i=0;i<matrix.size();i++){
            temp.push_back(make_pair(matrix[i][0],make_pair(i,0)));
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());
        int ele,row,col;
        for(int i=0;i<k;i++){
            ele = p.top().first;
            row = p.top().second.first;
            col = p.top().second.second;
            p.pop();
            if(col+1<matrix[row].size()){
                col++;
                p.push(make_pair(matrix[row][col],make_pair(row,col)));
            }
        }
        return ele;
    }
};