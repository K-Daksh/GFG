//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int i,int j,vector<vector<int>>&visited,vector<vector<int>>& A,int N,int M){
        if(i< 0 || i>=N || j<0 || j>=M || visited[i][j]==1 || A[i][j]==0){
          return false;
        }
        return true;
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(X==0 && Y==0) return 0;
        if(A[0][0]==0)
        {
            return -1;
        }
        queue<pair<pair<int, int>, int>>q;
        q.push({{0, 0}, 0});
        vector<vector<int>>vis(N, vector<int>(M, 0));
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, 1, 0, -1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int dist=it.second;
            
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(isValid(nr, nc, vis, A, N, M)){
                    if(nr==X && nc==Y){
                    return dist+1;
                    }
                    vis[nr][nc]=1;
                    q.push({{nr, nc}, dist+1});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends