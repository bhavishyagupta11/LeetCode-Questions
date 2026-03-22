class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        if(mat == target) return true;

        for(int rot = 0; rot < 4; rot++) {

            // transpose
            for(int i = 0; i < n; i++) {
                for(int j = i; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }

            // reverse rows
            for(int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }

            if(mat == target) return true;
        }

        return false;

/////////////////// Using Temporary Matrix ///////////////////////
        // int new_Row = 0;
        // int new_Col = 0;
        // for(int count = 0; count < 4; count++) {
        //     vector<vector<int>>temp(n, vector<int>(n,0));
        //     for(int i = 0; i < n; i++) {
        //         for(int j = 0; j < n; j++) {
        //             new_Row = j;
        //             new_Col = n - i - 1;

        //             temp[i][j] = mat[new_Row][new_Col];
        //         }
        //     }
        //     mat = temp;
        //     if(mat == target) return true;
        // }
        // return false;

/////////////////// Using co-ordinates ///////////////////////
        // vector<bool>flag(4 ,true);
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(flag[0] && mat[i][j] != target[i][j]) flag[0] = false;
        //         if(flag[1] && mat[i][j] != target[j][n - i - 1]) flag[1] = false;
        //         if(flag[2] && mat[i][j] != target[n - i - 1][n - j - 1]) flag[2] = false;
        //         if(flag[3] && mat[i][j] != target[n - j - 1][i]) flag[3] = false;
        //     }

        //     if(!flag[0] && !flag[1] && !flag[2] && !flag[3]) return false;
        // }
        // return flag[0] || flag[1] || flag[2] || flag[3];
    }
};
