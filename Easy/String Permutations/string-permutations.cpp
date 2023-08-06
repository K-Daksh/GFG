//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solvePermutation (string& s, vector<string>& storeString, int counter, int len){
        if(counter>=len){
            storeString.push_back(s);
            return;
        }else{
            for(int i=counter;i<=len;i++){
                swap(s[i],s[counter]);
                solvePermutation(s,storeString,counter+1,len);
                swap(s[i],s[counter]);
            }
        }
    }
    vector<string> permutation(string S)
    {
        int size=S.size();
        vector<string>storeString;
        solvePermutation(S,storeString,0,size-1);
        sort(storeString.begin(),storeString.end());
        return storeString;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends