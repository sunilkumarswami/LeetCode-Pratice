//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends

StackNode *root=new StackNode(0);
MyStack st;

//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    // Your Code
    if(top==NULL) {
        root->next=new StackNode(x);
        top=root;
    }
    else
    {
        top=top->next;
        top->next=new StackNode(x);
    }
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    if(top==root) {
        top=NULL;
        return root->next->data;
    }
    if(!top) return -1;
    StackNode* node=root;
    while(node->next!=top){
        node=node->next;
    }
    int ans=top->next->data;
    top->next=NULL;
    top=node;
    return ans;
}
