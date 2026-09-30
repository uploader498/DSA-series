class Solution {
public:
    // bool func(vector<vector<int>>&adj,vector<int>&color,int df,int node){
    //     for(int i=0;i<adj[node].size();i++){
    //         int x = adj[node][i];
    //         if(color[x]==-1){
    //             color[x]=(df+1)%2;

    //         }
    //     }
    // }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        for (int j = 0; j < v; j++) {
            if (color[j] == -1) {
                queue<int> q;
                q.push(j);
                color[j] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int i = 0; i < graph[node].size(); i++) {
                        int x = graph[node][i];
                        if (color[x] == -1) {
                            color[x] = (color[node] + 1) % 2;
                            q.push(x);
                        } else {
                            if (color[x] == color[node])
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};