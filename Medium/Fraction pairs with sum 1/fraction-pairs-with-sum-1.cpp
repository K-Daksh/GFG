//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        for(int i=0;i<n;i++)
        {
            int x=__gcd(numerator[i],denominator[i]);
            numerator[i]/=x;
            denominator[i]/=x;
        }
        map<pair<int,int>,int>map;
        for(int i=0;i<n;i++)
        {
            map[{denominator[i],numerator[i]}]++;
        }
        int ans=0;
        for(auto itr:map)
        {
            auto x=itr.first;
            int cnt=itr.second;
            if(x.first!=2)
            {
                ans+=(cnt*map[{x.first,x.first-x.second}]);
                map[x]=0;
                
            }
        }
        int y=map[{2,1}];
        ans+=(y*(y-1))/2;
        
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends