//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        int l = 0, r = 0;
        int store = 0;
        while(r<n-1) {
            int maxl=0;
            for(int i=l;i<=r;i++) {
                maxl = max(maxl, i+arr[i]);
            }
            l = r+1;
            if(r==maxl) return -1;
            r = maxl;
            store += 1;
        }
        return store;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends