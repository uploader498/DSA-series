class Solution {
public:
    bool valid(int r,int c,int r1,int c1){
        return r1>=0&&r1<r&&c1>=0&&c1<c;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int timer = -1;
        while(!q.empty()){
            int curr = q.size();
            while(curr--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                int row[4]={-1,1,0,0};
                int col[4]={0,0,-1,1};
                for(int k=0;k<4;k++){
                    if(valid(r,c,i+row[k],j+col[k])&& grid[i+row[k]][j+col[k]]==1){
                        grid[i+row[k]][j+col[k]]=2;
                        q.push(make_pair(i+row[k],j+col[k]));
                        fresh--;
                    }
                }
            }
            timer++;
        }
        if(fresh>0)return -1;
        if(timer==-1)return 0;
        return timer;
    }
};