
// //! 1 Reverse LL in groups of size K

// #include<iostream>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int a) {
//             num = a;
//             next = NULL;
//         }
// };
// //utility function to insert node in the list
// void insertNode(node* &head,int val) {
//     node* newNode = new node(val);
//     if(head == NULL) {
//         head = newNode;
//         return;
//     }
    
//     node* temp = head;
//     while(temp->next != NULL) temp = temp->next;
    
//     temp->next = newNode;
//     return;
// }
// //utility function to find length of the list
// int lengthOfLinkedList(node* head) {
//     int length = 0;
//     while(head != NULL) {
//         ++length;
//         head = head->next;
//     }
//     return length;
// }
// //utility function to reverse k nodes in the list
// node* reverseKNodes(node* head,int k) {
//     if(head == NULL||head->next == NULL) return head;
    
//     int length = lengthOfLinkedList(head);
    
//     node* dummyHead = new node(0);
//     dummyHead->next = head;
    
//     node* pre = dummyHead;
//     node* cur;
//     node* nex;

//     /*My take on how dummy->next is pointing to new head.Initially dummy
//      and pre are referencing the same address so any change made to 
//      pre->next will also be reflected in dummy->next but after reversing
//     the first group pre is  assigned to a complete new address.Therefore
//     changes  made to pre later do not affect the dummy->next  as the 
//     latters job was over after first reversal itself.*/
    
//     while(length >= k) {
//         cur = pre->next;
//         nex = cur->next;
//         for(int i=1;i<k;i++) { //*doing (k-1) iterations
//             cur->next = nex->next;
//             nex->next = pre->next;
//             pre->next = nex;
//             nex = cur->next;
//         }
//         pre = cur;
//         length -= k;
//     }
//     return dummyHead->next;
// }
// //utility function to print the list
// void printLinkedList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     }
//     cout<<head->num<<"\n";
// }

// int main() {
//     node* head = NULL;
//     int k = 3;
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,3);
//     insertNode(head,4);
//     insertNode(head,5);
//     insertNode(head,6);
//     insertNode(head,7);
//     insertNode(head,8);
    
//     cout<<"Original Linked List: "; printLinkedList(head);
//     cout<<"After Reversal of k nodes: "; 
//     node* newHead = reverseKNodes(head,k);
//     printLinkedList(newHead);
    
//     return 0;
// }
//
//
//
//
//

// //! 2 Rotate a LL [Brute force Solution]

// #include<iostream>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int a) {
//             num = a;
//             next = NULL;
//         }
// };
// //utility function to insert node at the end of the list
// void insertNode(node* &head,int val) {
//     node* newNode = new node(val);
//     if(head == NULL) {
//         head = newNode;
//         return;
//     }
//     node* temp = head;
//     while(temp->next != NULL) temp = temp->next;
    
//     temp->next = newNode;
//     return;
// }

// //utility function to print list
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     } 
//     cout<<head->num<<endl;
//     return;
// }


// //* utility function to rotate list by k times
// node* rotateRight(node* head,int k) {
//     if(head == NULL||head->next == NULL) return head;
//     for(int i=0;i<k;i++) {
//         node* temp = head;
//         while(temp->next->next != NULL) temp = temp->next;
//         node* end = temp->next;
//         temp->next = NULL;
//         end->next = head;
//         head = end;
//     }
//     return head;
// }

// int main() {
//     node* head = NULL;
//     //inserting Node
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,3);
//     insertNode(head,4);
//     insertNode(head,5);
    
//     cout<<"Original list: ";
//     printList(head);
//     cout<<endl;
    
//     int k = 2;
//     node* newHead = rotateRight(head,k);//calling function for rotating 
//     // right of the nodes by k times
    
//     cout<<"After "<<k<<" iterations: ";
//     printList(newHead);//list after rotating nodes
//     return 0;
// }
//
//
//
//
//

// //! 2 Rotate a LL [Optimal Solution]

// #include<iostream>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int a) {
//             num = a;
//             next = NULL;
//         }
// };
// //utility function to insert node at the end of the list
// void insertNode(node* &head,int val) {
//     node* newNode = new node(val);
//     if(head == NULL) {
//         head = newNode;
//         return;
//     }
//     node* temp = head;
//     while(temp->next != NULL) temp = temp->next;
    
//     temp->next = newNode;
//     return;
// }

// //utility function to print list
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     } 
//     cout<<head->num<<endl;
//     return;
// }

// //* utility function to rotate list by k times
// node* rotateRight(node* head,int k) {
//     //edge cases
//     if(head == NULL||head->next == NULL||k == 0) return head;

//     //calculating length
//     node* temp = head;
//     int length = 1;
//     while(temp->next != NULL) {
//         ++length;
//         temp = temp->next;
//     }

//     //*link last node to first node
//     temp->next = head;
//     k = k%length; //*when k is more than length of list
//     int end = length-k; //*to get to the end of the list

//     while(end--) temp = temp->next;

//     //*breaking last node link and pointing to NULL
//     head = temp->next;
//     temp->next = NULL;
        
//     return head;
// }

// int main() {
//     node* head = NULL;
//     //inserting Node
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,3);
//     insertNode(head,4);
//     insertNode(head,5);
    
//     cout<<"Original list: ";
//     printList(head);
    
//     int k = 2;
//     node* newHead = rotateRight(head,k);//calling function for rotating right of the nodes by k times
    
//     cout<<"After "<<k<<" iterations: ";
//     printList(newHead);//list after rotating nodes
//     return 0;
// }
//
//
//
//
//

// //! 3 Flattening a LL

// #include <iostream>

// using namespace std;

// struct Node {
//   int data;
//   Node *next;
//   Node *bottom;

//   Node(int data) : data(data), next(nullptr), bottom(nullptr) {}
// };

// Node* mergeTwoLists(Node* a, Node* b) {
    
//     Node *temp = new Node(0);
//     Node *res = temp; 
    
//     while(a != NULL && b != NULL) {
//         if(a->data < b->data) {
//             temp->bottom = a; 
//             temp = temp->bottom; 
//             a = a->bottom; 
//         }
//         else {
//             temp->bottom = b;
//             temp = temp->bottom; 
//             b = b->bottom; 
//         }
//     }
    
//     if(a) temp->bottom = a; 
//     else temp->bottom = b; 
    
//     return res -> bottom; 
    
// }

// Node *flatten(Node *root)
// {
   
//         if (root == NULL || root->next == NULL) 
//             return root; 
  
//         //*recur for list on right ie. flatten L4 first then L3 then L2 then L1
//         root->next = flatten(root->next); 
  
//         //*now merge 
//         root = mergeTwoLists(root, root->next); 
  
//         //*return the root 
//         //*it will be in turn merged with its left ie. like L4 merged with L3 etc
//         return root; 
// }

// void printLinkedList(Node *head) {
//   while(head != NULL) {
//     cout << head->data << " ";
//     head = head->bottom;
//   }
// }

// int main() {
//   Node *root = new Node(5);
//   root->bottom = new Node(10);
//   root->bottom->bottom = new Node(19);
//   root->bottom->bottom->bottom = new Node(28);

//   Node *other = new Node(7);
//   other->bottom = new Node(20);
//   other->bottom->bottom = new Node(22);
//   other->bottom->bottom->bottom = new Node(35);

//   root->next = other;

//   Node *head = flatten(root);

//   printLinkedList(head);

//   return 0;
// }
//
//
//
//
//

// // ! 4 Clone a LL with Random and Next Pointer [Brute Force Soln]

// #include<iostream>
// using namespace std;

// class Node {
//     public:
//         int val;
//         Node* next;
//         Node* random;
//         Node(int value) {
//             val = value;
//             next = NULL;
//             random = NULL;
//         }
// };

// void printList(Node* head) {
//     while(head != NULL) {
//         cout<<head->val<<':';
//         head->next != NULL ? cout<<head->next->val:cout<<"NULL";
//         head->random != NULL ? cout<<","<<head->random->val:cout<<",NULL";
//         cout<<endl;
//         head = head->next;
//     }
// }

// Node* copyRandomList(Node* head) {
//     unordered_map<Node*,Node*> hashMap;
//     Node* temp = head;
// //first iteration for inserting deep nodes of every node in the hashmap.
//     while(temp != NULL) {
//         Node* newNode = new Node(temp->val);
//         hashMap[temp] = newNode;
//         temp = temp->next;
//     }
//     Node* t = head;
// //second iteration for linking next and random pointer as given question.
//     while(t != NULL) {
//         Node* node = hashMap[t];
//         node->next = (t->next != NULL) ? hashMap[t->next]:NULL;
//         node->random = (t->random != NULL) ? hashMap[t->random]:NULL;
//         t = t->next;
//     }
//     return hashMap[head];
// }

// int main() {
//     Node* head = NULL;
    
//     Node* node1 = new Node(1);
//     Node* node2 = new Node(2);
//     Node* node3 = new Node(3);
//     Node* node4 = new Node(4);
    
//     head = node1;
//     head->next = node2;
//     head->next->next = node3;
//     head->next->next->next = node4;
    
//     head->random = node4;
//     head->next->random = node1;
//     head->next->next->random = NULL;
//     head->next->next->next->random = node2;
    
//     cout<<"Original list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
//     printList(head);
    
//     cout<<"Copy list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    
//     Node* newHead = copyRandomList(head);
    
//     printList(newHead);

//     return 0;
// }
//
//
//
//
//

/*In computing, a deep copy is a copy of a data structure that duplicates
not only the structure itself, but all structures to which it is linked.*/

// // ! 4 Clone a LL with Random and Next Pointer [Optimal Soln]

// #include<iostream>
// using namespace std;

// class Node {
//     public:
//         int val;
//         Node* next;
//         Node* random;
//         Node(int value) {
//             val = value;
//             next = NULL;
//             random = NULL;
//         }
// };

// void printList(Node* head) {
//     while(head != NULL) {
//         cout<<head->val<<':';
//         head->next != NULL ? cout<<head->next->val:cout<<"NULL";
//         head->random != NULL ? cout<<","<<head->random->val:cout<<",NULL";
//         cout<<endl;
//         head = head->next;
//     }
// }

// Node* copyRandomList(Node* head) {
//      Node* temp = head;

// 	//step 1
//     while(temp != NULL) {
//         Node* newNode = new Node(temp->val);
//         newNode->next = temp->next;
//         temp->next = newNode;
//         temp = temp->next->next;
//     }

// 	//step 2
//     Node* itr = head;
//     while(itr != NULL) {
//         if(itr->random != NULL)
//             itr->next->random = itr->random->next;
        
//         if(itr->random == NULL){itr->next->random = NULL;}//*no need for this line as then the value for that (itr->next->random)
//         //* will remain what it was (ie. nothing which is "NULL" only)
//         itr = itr->next->next;
//     }

// 	//step 3
//     Node* dummy = new Node(0);//dummy for connecting to itr
//     itr = head;
//     temp = dummy;//dummy to move from 'dummy' to last ele with 'itr'
//     //so that 'itr' can remove original LL from the deep copy one and 
//     //'temp' will form connections with them before 'itr' can remove them
//     //and finally 'dummy' will return us our deep copy of the LL
//     Node* fast;
//     while(itr != NULL) {
//         fast = itr->next->next;
//         temp->next = itr->next;
//         itr->next = fast;
//         temp = temp->next;
//         itr = fast;
//     }
//     return dummy->next;

// }

// int main() {
//     Node* head = NULL;
    
//     Node* node1 = new Node(1);
//     Node* node2 = new Node(2);
//     Node* node3 = new Node(3);
//     Node* node4 = new Node(4);
    
//     head = node1;
//     head->next = node2;
//     head->next->next = node3;
//     head->next->next->next = node4;
    
//     head->random = node4;
//     head->next->random = node1;
//     head->next->next->random = NULL;
//     head->next->next->next->random = node2;
    
//     cout<<"Original list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
//     printList(head);
    
//     cout<<"Copy list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
//     Node* newHead = copyRandomList(head);
//     printList(newHead);
//     return 0;
// }
