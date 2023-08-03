//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        unordered_map<int,list<pair<int,int>>>vc;
        vector<int>vec(N,1e9);
        for(auto it:edges)
        {
            vc[it[0]].push_back({it[1],it[2]});
        }
        queue<int>que;
        vec[0] = 0;
        que.push(0);
        while(!que.empty())
        {
            auto it=que.front();
            que.pop();
            for(auto nbr:vc[it])
            {
                if(vec[it] + nbr.second < vec[nbr.first])
                {
                    vec[nbr.first] = vec[it]+nbr.second;
                    que.push(nbr.first);
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(vec[i] == 1e9) vec[i] = -1;
        }
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends