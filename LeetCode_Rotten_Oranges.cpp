class Solution {
public:
    vector<vector<int>> directions{{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int freshOranges = 0;
        int minutes = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) freshOranges++;
            }
        }
        if(freshOranges == 0) return 0;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int,int> front = q.front();
                q.pop();

                int i = front.first;
                int j = front.second;

                for(vector<int>& dir : directions) {
                    int ithIndex = i + dir[0];
                    int jthIndex = j + dir[1];
                    if(ithIndex >=0 && ithIndex < m && jthIndex >= 0 && jthIndex < n && grid[ithIndex][jthIndex] == 1) {
                        grid[ithIndex][jthIndex] = 2;
                        q.push({ithIndex,jthIndex});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }
        return (freshOranges == 0) ? minutes -1 : -1;
    }
};