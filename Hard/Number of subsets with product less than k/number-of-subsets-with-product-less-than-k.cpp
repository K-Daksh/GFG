//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int fun(int index,int k,int arr[],int n)
   {
       if(index>=n)
       {
           if(k>0)return 1;
           else return 0;
       }
       int not_take=fun(index+1,k,arr,n);
       int take=0;
       if(arr[index]<=k)take=fun(index+1,k/arr[index],arr,n);
       return (take+not_take);
   }
  
    int numOfSubsets(int arr[], int N, int K) 
    { 
        return fun(0,K,arr,N)-1;  //substracting 1 because we have to return the non empty subset 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>K;

        Solution ob;
        cout << ob.numOfSubsets(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends