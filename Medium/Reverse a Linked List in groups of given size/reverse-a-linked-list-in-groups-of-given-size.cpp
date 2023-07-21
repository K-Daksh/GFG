//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends

void rev(node *head){
    node *prev = NULL, *next;
    while(head->next){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    head->next = prev;
}

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        node *temp = head, *prev = NULL, *res;
        while(temp){
            node *tail = temp;
            for(int i = 1; i < k && tail->next; i++)
                tail = tail->next;
            node *next = tail->next;
            tail->next = NULL;
            rev(temp);
            temp->next = next;
            if(prev)
                prev->next = tail;
            else
                res = tail;
            prev = temp;
            temp = next;
        }
        return res;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends