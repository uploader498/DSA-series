class Solution {
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    int r, c;
    bool valid(int i, int j) { return i >= 0 && i < r && j >= 0 && j < c; }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        r = grid.size();
        c = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        int rw = q.front().first;
                        int cl = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            if (valid(rw + row[k], cl + col[k]) &&
                                grid[rw + row[k]][cl + col[k]] == '1') {
                                grid[rw + row[k]][cl + col[k]]= '0';
                                q.push(make_pair(rw + row[k], cl + col[k]));
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};