class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, int n, vector<bool>& visited) {
        visited[node] = true;
        for(int V = 0;V<n;V++) {
            if(!visited[V] && isConnected[node][V] == 1) {
                dfs(V, isConnected, n, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n,false);
        int start = 0;
        int cnt = 0;
        for(int i =0;i<n;i++) {
            if(!visited[i]) {
                cnt++;
                dfs(i,isConnected,n,visited);
            }
        }
        return cnt;
    }
};

// class Solution {
// public:
//     void dfs(int node, vector<vector<int>>& adjList, int n, vector<bool>& visited) {
//         visited[node] = true;
//         for(int nbh : adjList[node]) {
//             if(!visited[nbh]) {
//                 dfs(nbh, adjList, n, visited);
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<vector<int>>adjList(n);
//         for(int i =0;i<n;i++) {
//             for(int j =0;j<n;j++) {
//                 if(isConnected[i][j]==1 && i!=j) {
//                     adjList[i].push_back(j);
//                     adjList[j].push_back(i);
//                 }
//             }
//         }
//         vector<bool>visited(n,false);
//         int start = 0;
//         int cnt = 0;
//         for(int i =0;i<n;i++) {
//             if(!visited[i]) {
//                 cnt++;
//                 dfs(i,adjList,n,visited);
//             }
//         }
//         return cnt;
//     }
// };

// class Solution {
// public:
//     void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
//         queue<int>q;

//         q.push(start);
//         visited[start] = true;
//         while(!q.empty()) {
//             int front = q.front();
//             visited[front] = true;
//             q.pop();

//             for(int nbh : adj[front]) {
//                 if(!visited[nbh]) {
//                     visited[nbh] = true;
//                     q.push(nbh);
//                 }
//             }
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected[0].size();
//         vector<vector<int>> adj(n);
//         for(int i=0;i<n;i++) {
//             for(int j=0; j<n;j++) {
//                 if(isConnected[i][j] == 1 && i!=j) {
//                 adj[i].push_back(j);
//                 adj[j].push_back(i);
//                 }
//             }
//         }

//         // Step 2 - BFS on each element
//         vector<bool>visited(n,false);
//         int cnt = 0;

//         for(int i =0;i<n;i++) {
//             if(!visited[i]) {
//                 cnt++;
//                 bfs(i, adj, visited);
//             }
//         }
//     return cnt;
//     }
// };