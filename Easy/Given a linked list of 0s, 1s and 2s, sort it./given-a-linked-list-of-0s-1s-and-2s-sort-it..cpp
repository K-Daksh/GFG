//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    Node* segregate(Node *head) {
        int count=0;
        int one=0,two=0,zero=0;
        struct Node *headd=head;
        while(headd!=NULL){
            int a=headd->data;
            if(a==0){
                zero++;
            }else if(a==1){
                one++;
            }else{
                two++;
            }
            headd=headd->next;
            count++;
        }
        struct Node *temp=head;
        int c=0,c1=0,c2=0;;
            if(zero>0){
                for(int i=0;i<zero;i++){
                head->data=0;
                head=head->next;
                c++;
                c1=c;
            }
            }
            if(one>0){
                for(int i=c;i<one+c;i++){
                head->data=1;
                head=head->next;
                c1++;
            }
            }
            if(two>0){
                for(int i=c1;i<two+c1;i++){
                head->data=2;
                head=head->next;
            }
            }

        return temp;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends