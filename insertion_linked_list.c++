//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




 // } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    Node* create_list(Node* h , Node *t){
        Node* tem = h;
        Node* c = new Node(t->data);
        Node* p;
        c->data = t->data;
        if(c->data <= h->data ){
            c->next = h;
            h = c;
            return h;
        }
        while(tem != NULL && tem->data < c->data){
            p = tem ;
            tem = tem->next;
        }
        c->next = tem;
        p->next = c;
        return h;
    }
    
    Node* insertionSort(struct Node* head_ref)
    {
        
        Node* h = new Node(head_ref->data);
    
        Node* k = head_ref->next;
        while(k != NULL){
            h = create_list(h , k);
            k = k->next;
        }
        return h;
    
    }
    
};

// { Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}  // } Driver Code Ends