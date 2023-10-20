
// //! 1 brute force sol

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // *constructor
//     Node(int data)
//     {

//         this->data = data;
//         this->next = NULL;
//     }
//     //*destructor
//     ~Node()
//     {
//         int value = this->data;
//         //*memory free
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << " memory is free for node with data " << value << endl;
//     }
// };

// void insertAtHead(Node *&head, int d)
// {

//     //* new node created
//     Node *temp = new Node(d);
//     temp->next = head; // * As 'head' is pointing to 'node1'
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     tail->next = temp;
//     tail = temp; //* or 'tail->next' instead of 'temp'
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     if (position == 1)
//     {
//         insertAtHead(head, d);
//         return;
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(int position, Node *&head,Node *&tail)
// {

//     //* deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         //* memory free start ndoe
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //* deleting any middle node or last node
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt = 1;
//         while (cnt < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//         //* For last node deletion
//         if(prev->next == NULL){
//             tail=prev;
//         }
//     }
// }

// Node* findMiddle(Node* head){
//     int l=0;
//     Node* temp=head;
//     while(temp){
//         l++;
//         temp=temp->next;
//     }
//     temp=head;
//     for(int i=0;i<l/2;i++){
//         temp=temp->next;
//     }
//     return temp;
// }

// int main()
// {

//     // created a new node
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     insertAtTail(tail, 20);
//     print(head);

//     insertAtTail(tail, 200);
//     print(head);

//     insertAtPosition(tail, head, 4, 90);
//     print(head);

//     insertAtPosition(tail, head, 4, 90);
//     print(head);

//     Node* temp=findMiddle(head);
//     cout<<temp->data<<endl;

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;

//     return 0;
// }

// //! 1 Optimal Solution [Tortoise-Hare-Algorithm]

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // *constructor
//     Node(int data)
//     {

//         this->data = data;
//         this->next = NULL;
//     }
//     //*destructor
//     ~Node()
//     {
//         int value = this->data;
//         //*memory free
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << " memory is free for node with data " << value << endl;
//     }
// };

// void insertAtHead(Node *&head, int d)
// {

//     //* new node created
//     Node *temp = new Node(d);
//     temp->next = head; // * As 'head' is pointing to 'node1'
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     tail->next = temp;
//     tail = temp; //* or 'tail->next' instead of 'temp'
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     if (position == 1)
//     {
//         insertAtHead(head, d);
//         return;
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(int position, Node *&head,Node *&tail)
// {

//     //* deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         //* memory free start ndoe
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //* deleting any middle node or last node
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt = 1;
//         while (cnt < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//         //* For last node deletion
//         if(prev->next == NULL){
//             tail=prev;
//         }
//     }
// }

// //todo
// Node* findMiddle(Node* head){
//     Node* slow=head;
//     Node* fast=head;
//     while(fast!=NULL && fast->next!=NULL){
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     return slow;
// }

// int main()
// {

//     // created a new node
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     insertAtTail(tail, 20);
//     print(head);

//     insertAtTail(tail, 200);
//     print(head);

//     insertAtPosition(tail, head, 4, 90);
//     print(head);

//     Node* temp=findMiddle(head);
//     cout<<temp->data<<endl;

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;

//     return 0;
// }
//
//
//
//
//

// // ! 2 Reverse a Linked List [ITERATIVE APPROACH]

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next; //* (temp->next) during 1st loop points to the node1's next
//         cnt++;             //* in reality i have made a ptr to the memory
//                            //* location that 'head' and 'node1' are also pointing to
//                            //* and then i am changing its value to the 'temp->next' address
//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next; //*if i do 'nodeToInsert' instead, i will be
//     temp->next = nodeToInsert;       //*making the 'nodeToInsert' ptr point to temp's 'next'
//     //*ie. pointing it to the agli allocated memory address and not changing
//     //*'nodeToInsert->next' value to 'temp->next'
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// void reverse(Node *&head)
// {
//     Node* prev_p=NULL;
//     Node* next_p=NULL;
//     Node* curr=head;

//     while(curr!=NULL){
//         next_p=curr->next;
//         curr->next=prev_p;
//         // curr->prev=next_p; //*as there is no value for curr->prev
//         prev_p=curr;
//         curr=next_p;
//         }

//     if(head==NULL || head->next==NULL){
//         head=prev_p;
//     }

//     //todo
//     //*Or we can also return the node by returning "prev_p"

// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     // Correction(empty list)
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     // todo
//     insertAtHead(head, tail, 12);
//     print(head);

//     insertAtHead(head, tail, 120);
//     print(head);

//     // todo
//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     // todo
//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     insertAtPosition(tail, head, 4, 90);
//     print(head);

//      cout << "reverse is: " << endl;
//     reverse(head);
//     print(head);

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// // ! 3 Reverse a Linked List [RECURSIVE APPROACH]

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next; //* (temp->next) during 1st loop points to the node1's next
//         cnt++;             //* in reality i have made a ptr to the memory
//                            //* location that 'head' and 'node1' are also pointing to
//                            //* and then i am changing its value to the 'temp->next' address
//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next; //*if i do 'nodeToInsert' instead, i will be
//     temp->next = nodeToInsert;       //*making the 'nodeToInsert' ptr point to temp's 'next'
//     //*ie. pointing it to the agli allocated memory address and not changing
//     //*'nodeToInsert->next' value to 'temp->next'
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// void reverse(Node* &head,Node* &curr,Node* &prev){

//         if(curr==NULL){ //* Runs for last when curr at null and prev at
//             head=prev;  //*last node
//             return;
//         }

//         reverse(head,curr->next,curr);

//         curr->next=prev;//* at 1st first recursive call return(ie.first return)
//         //*curr->next will change from "NULL" and points to prev which is at
//         //* 2nd last element at the time.

// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     // Correction(empty list)
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     // todo
//     insertAtHead(head, tail, 12);
//     print(head);

//     insertAtHead(head, tail, 120);
//     print(head);

//     // todo
//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     // todo
//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     insertAtPosition(tail, head, 4, 90);
//     print(head);

//      cout << "reverse is: " << endl;
//     Node* curr=head;
//     Node* prev=NULL;
//     reverse(head,curr,prev);
// print(head);

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 4 Brute Force Approach

// #include <iostream>
// #include <map>
// #include <unordered_set>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;

//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// void reverse(Node* &head,Node* &curr,Node* &prev){

//         if(curr==NULL){ //* Runs for last when curr at null and prev at
//             head=prev;  //*last node
//             return;
//         }

//         reverse(head,curr->next,curr);

//         curr->next=prev;
// }

// //*utility function to create cycle
// void createCycle(Node* &head,int a,int b) {
//     int cnta = 1,cntb = 1;
//     Node* p1 = head;
//     Node* p2 = head;
//     while(cnta != a || cntb != b) {
//         if(cnta != a) p1 = p1->next, ++cnta;
//         if(cntb != b) p2 = p2->next, ++cntb;
//     }
//     p2->next = p1;
// }

// //*utility function to detect cycle
// bool cycleDetect(Node* head) {
//     unordered_set<Node*> hashTable;
//     while(head != NULL) {
//         if(hashTable.find(head) != hashTable.end()) return true;
//         hashTable.insert(head);
//         head = head->next;
//     }
//     return false;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     insertAtHead(head, tail, 12);
//     print(head);

//     insertAtHead(head, tail, 120);
//     print(head);

//     // todo
//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     createCycle(head,1,3);//*creating cycle in the list

//     if(cycleDetect(head) == true)
//     cout<<"Cycle detected\n";
//     else
//     cout<<"Cycle not detected\n";

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 4 Optimal Approach [Tortoise and Hare algo]

// #include <iostream>
// #include <map>
// #include <unordered_set>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;

//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// void reverse(Node* &head,Node* &curr,Node* &prev){

//         if(curr==NULL){ //* Runs for last when curr at null and prev at
//             head=prev;  //*last node
//             return;
//         }

//         reverse(head,curr->next,curr);

//         curr->next=prev;
// }

// //*utility function to create cycle
// void createCycle(Node* &head,int a,int b) {
//     int cnta = 1,cntb = 1;
//     Node* p1 = head;
//     Node* p2 = head;
//     while(cnta != a || cntb != b) {
//         if(cnta != a) p1 = p1->next, ++cnta;
//         if(cntb != b) p2 = p2->next, ++cntb;
//     }
//     p2->next = p1;
// }

// //*utility function to detect cycle
// bool cycleDetect(Node* head) {
//     //* for empty LL and LL with single node
//     if(head == NULL || head->next==NULL) return false;
//     Node* fast = head;
//     Node* slow = head;

//     while(fast->next != NULL && fast->next->next != NULL) {//* "&" is important
//         fast = fast->next->next;  //*traverse the loop for 2 ele and observe
//         slow = slow->next;        //*how this "jugaad" is working
//         if(fast == slow) return true;
//     }
//     return false;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     insertAtHead(head, tail, 12);
//     print(head);

//     // insertAtHead(head, tail, 120);
//     // print(head);

//     // // todo
//     // insertAtTail(tail, head, 20);
//     // print(head);

//     // insertAtTail(tail, head, 200);
//     // print(head);

//     createCycle(head,1,2);//*creating cycle in the list

//     if(cycleDetect(head) == true)
//     cout<<"Cycle detected\n";
//     else
//     cout<<"Cycle not detected\n";

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 5 Brute force approach

// #include <iostream>
// #include <map>
// #include <unordered_set>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;

//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// void reverse(Node* &head,Node* &curr,Node* &prev){

//         if(curr==NULL){ //* Runs for last when curr at null and prev at
//             head=prev;  //*last node
//             return;
//         }

//         reverse(head,curr->next,curr);

//         curr->next=prev;
// }

// //*utility function to create cycle
// void createCycle(Node* &head,int a,int b) {
//     int cnta = 1,cntb = 1;
//     Node* p1 = head;
//     Node* p2 = head;
//     while(cnta != a || cntb != b) {
//         if(cnta != a) p1 = p1->next, ++cnta;
//         if(cntb != b) p2 = p2->next, ++cntb;
//     }
//     p2->next = p1;
// }

// //* process as per mentioned in solution
// Node* detectCycle(Node* head) {
//     unordered_set<Node*> st;
//     while(head != NULL) {
//         if(st.find(head) != st.end()) return head;
//         st.insert(head);
//         head = head->next;
//     }
//     return NULL;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     insertAtHead(head, tail, 12);
//     print(head);

//     insertAtHead(head, tail, 120);
//     print(head);

//     // todo
//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     createCycle(head,3,5);//*creating cycle in the list

//     Node* NodeRecieve = detectCycle(head);
//     if(NodeRecieve == NULL) cout<<"No cycle";
//     else {
//         Node* temp = head;
//         int pos = 1;
//         while(temp!=NodeRecieve) {
//             ++pos;
//             temp = temp->next;
//         }
//         cout<<"Tail connects at pos "<<pos<<endl;
//     }

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//
//

// //! 5 Optimal approach [Tortoise and Hare algo.]

// #include <iostream>
// #include <map>
// #include <unordered_set>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;

//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// void reverse(Node* &head,Node* &curr,Node* &prev){

//         if(curr==NULL){ //* Runs for last when curr at null and prev at
//             head=prev;  //*last node
//             return;
//         }

//         reverse(head,curr->next,curr);

//         curr->next=prev;
// }

// //*utility function to create cycle
// void createCycle(Node* &head,int a,int b) {
//     int cnta = 1,cntb = 1;
//     Node* p1 = head;
//     Node* p2 = head;
//     while(cnta != a || cntb != b) {
//         if(cnta != a) p1 = p1->next, ++cnta;
//         if(cntb != b) p2 = p2->next, ++cntb;
//     }
//     p2->next = p1;
// }

// //*process as per mentioned in solution
// Node* detectCycle(Node* head) {
//     if(head == NULL||head->next == NULL) return NULL;

//     Node* fast = head;
//     Node* slow = head;
//     Node* entry = head;

//     while(fast->next != NULL&&fast->next->next != NULL) {
//         slow = slow->next;
//         fast = fast->next->next;

//         if(slow == fast) {          //*means there is a cycle
//             while(slow != entry) { //*finding the entry location
//                 slow = slow->next;
//                 entry = entry->next;
//             }
//             return slow;
//         }
//     }
//     return NULL;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     insertAtHead(head, tail, 12);
//     print(head);

//     insertAtHead(head, tail, 120);
//     print(head);

//     // todo
//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     createCycle(head,2,5);//*creating cycle in the list

//     Node* NodeRecieve = detectCycle(head);
//     if(NodeRecieve == NULL) cout<<"No cycle";
//     else {
//         Node* temp = head;
//         int pos = 1;
//         while(temp!=NodeRecieve) {
//             ++pos;
//             temp = temp->next;
//         }
//         cout<<"Tail connects at pos "<<pos<<endl;
//     }

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 6 Brute Force Approach

// #include <iostream>
// #include <map>
// #include <unordered_set>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// void reverse(Node *&head, Node *&curr, Node *&prev)
// {

//     if (curr == NULL)
//     {                //* Runs for last when curr at null and prev at
//         head = prev; //*last node
//         return;
//     }

//     reverse(head, curr->next, curr);

//     curr->next = prev;
// }

// //*utility function to create cycle
// void createCycle(Node *&head, int a, int b)
// {
//     int cnta = 1, cntb = 1;
//     Node *p1 = head;
//     Node *p2 = head;
//     while (cnta != a || cntb != b)
//     {
//         if (cnta != a)
//             p1 = p1->next, ++cnta;
//         if (cntb != b)
//             p2 = p2->next, ++cntb;
//     }
//     p2->next = p1;
// }

// //*utility function to detect and find the length of the cycle
// int lengthOfCycle(Node *head)
// {
//     //* for empty LL and LL with single node
//     if (head == NULL || head->next == NULL)
//         return 0;

//     unordered_set<Node *> hashTable;
//     Node *temp;

//     //*to find if cycle exists or not
//     while (head != NULL)
//     {
//         if (hashTable.find(head) != hashTable.end())
//         {
//             temp = head;
//             break;
//         };
//         hashTable.insert(head);
//         head = head->next;
//     }
//     //* condition to return if loop does not exists
//     if (head == NULL)
//     {
//         return 0;
//     }
//     //* condition to return length if loop does exists
//     int cnt = 0;

//     Node *temp2 = temp;
//     while (1)
//     {
//         temp = temp->next;
//         cnt++;
//         if (temp == temp2)
//         {
//             return cnt;
//         }
//     }

//     return 0;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     insertAtHead(head, tail, 12);
//     print(head);

//     insertAtHead(head, tail, 120);
//     print(head);

//     // todo
//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     createCycle(head, 1, 5); //*creating cycle in the list

//     int length = lengthOfCycle(head);
//     cout << "length of the cycle is: " << length << endl;

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

//! 6 Optimal Approach [Tortoise and Hare algo]

// #include <iostream>
// #include <map>
// #include <unordered_set>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// void reverse(Node *&head, Node *&curr, Node *&prev)
// {

//     if (curr == NULL)
//     {                //* Runs for last when curr at null and prev at
//         head = prev; //*last node
//         return;
//     }

//     reverse(head, curr->next, curr);

//     curr->next = prev;
// }

// //*utility function to create cycle
// void createCycle(Node *&head, int a, int b)
// {
//     int cnta = 1, cntb = 1;
//     Node *p1 = head;
//     Node *p2 = head;
//     while (cnta != a || cntb != b)
//     {
//         if (cnta != a)
//             p1 = p1->next, ++cnta;
//         if (cntb != b)
//             p2 = p2->next, ++cntb;
//     }
//     p2->next = p1;
// }

// //*utility function to detect cycle
// int lengthOfCycle(Node *head)
// {
//     //* for empty LL and LL with single node
//     if (head == NULL || head->next == NULL)
//         return 0;
//     Node *fast = head;
//     Node *slow = head;

//     //* to detect a loop!!

//     while (fast->next != NULL && fast->next->next != NULL)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//         if (fast == slow)
//             break;
//     }
//     // todo: for [if loop does not exists]
//     if (fast->next == NULL || fast->next->next == NULL)
//     {
//         return 0;
//     }
//     //* if loop reaches here then 'slow' and 'fast' are at the collision
//     //* node therefore traverse the nodes till this node is reached again
//     //*then return the 'cnt'

//     int cnt = 0;

//     Node *temp = slow;
//     while (1)
//     {
//         slow = slow->next;
//         cnt++;
//         if (slow == temp)
//         {
//             return cnt;
//         }
//     }
//     return 0;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     insertAtHead(head, tail, 12);
//     print(head);

//     insertAtHead(head, tail, 120);
//     print(head);

//     insertAtTail(tail, head, 20);
//     print(head);

//     insertAtTail(tail, head, 200);
//     print(head);

//     createCycle(head, 2, 5); //*creating cycle in the list

//     int length = lengthOfCycle(head);
//     cout << "length of the cycle is: " << length << endl;

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 7 Brute force approach

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next; //* (temp->next) during 1st loop points to the node1's next
//         cnt++;             //* in reality i have made a ptr to the memory
//                            //* location that 'head' and 'node1' are also pointing to
//                            //* and then i am changing its value to the 'temp->next' address
//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next; //*if i do 'nodeToInsert' instead, i will be
//     temp->next = nodeToInsert;       //*making the 'nodeToInsert' ptr point to temp's 'next'
//     //*ie. pointing it to the agli allocated memory address and not changing
//     //*'nodeToInsert->next' value to 'temp->next'
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// bool isPalindrome(Node *head)
// {
//     vector<int> arr;
//     while (head != NULL)
//     {
//         arr.push_back(head->data);
//         head = head->next;
//     }
//     for (int i = 0; i < arr.size() / 2; i++)
//         if (arr[i] != arr[arr.size() - i - 1])
//             return false;
//     return true;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     // Correction(empty list)
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     // todo
//     insertAtTail(tail, head, 2);
//     print(head);

//     insertAtTail(tail, head, 10);
//     print(head);

//     isPalindrome(head) ? cout << "True" : cout << "False";
//     cout << endl;
//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 7 Optimal solution

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next; //* (temp->next) during 1st loop points to the node1's next
//         cnt++;             //* in reality i have made a ptr to the memory
//                            //* location that 'head' and 'node1' are also pointing to
//                            //* and then i am changing its value to the 'temp->next' address
//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next; //*if i do 'nodeToInsert' instead, i will be
//     temp->next = nodeToInsert;       //*making the 'nodeToInsert' ptr point to temp's 'next'
//     //*ie. pointing it to the agli allocated memory address and not changing
//     //*'nodeToInsert->next' value to 'temp->next'
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// Node* reverse(Node* ptr) {
//     Node* pre=NULL;
//     Node* nex=NULL;
//     while(ptr!=NULL) {
//         nex = ptr->next;
//         ptr->next = pre;
//         pre=ptr;
//         ptr=nex;
//     }
//     return pre;
// }

// bool isPalindrome(Node* head) {
//     //*if if head is the only ele or head is null it is always palindrome
//     if(head==NULL||head->next==NULL) return true;

//     Node* slow = head;
//     Node* fast = head;

//     //* to find the middle ele
//     while(fast->next!=NULL&&fast->next->next!=NULL) {//*[fast->next->next!=NULL]
//         slow = slow->next; //*to have 1st middle ele out of the two in case of even
//         fast = fast->next->next;
//     }

//     //*to reverse the LL
//     slow->next = reverse(slow->next);
//     slow = slow->next;//* moving slow to physically point to the first ele of
//                         //* the right half
//     Node* dummy = head;

//     //*checking if palindrome or not
//     while(slow!=NULL) {
//         if(dummy->data != slow->data) return false;
//         dummy = dummy->next;
//         slow = slow->next;
//     }
//     return true;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     // Correction(empty list)
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     // todo
//     insertAtTail(tail, head, 2);
//     print(head);

//     insertAtTail(tail, head, 20);
//     print(head);

//     isPalindrome(head) ? cout << "True" : cout << "False";
//     cout << endl;
//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// // //! 8 Optimal solution

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next; //* (temp->next) during 1st loop points to the node1's next
//         cnt++;             //* in reality i have made a ptr to the memory
//                            //* location that 'head' and 'node1' are also pointing to
//                            //* and then i am changing its value to the 'temp->next' address
//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next; //*if i do 'nodeToInsert' instead, i will be
//     temp->next = nodeToInsert;       //*making the 'nodeToInsert' ptr point to temp's 'next'
//     //*ie. pointing it to the agli allocated memory address and not changing
//     //*'nodeToInsert->next' value to 'temp->next'
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// Node *reverse(Node *ptr)
// {
//     Node *pre = NULL;
//     Node *nex = NULL;
//     while (ptr != NULL)
//     {
//         nex = ptr->next;
//         ptr->next = pre;
//         pre = ptr;
//         ptr = nex;
//     }
//     return pre;
// }

// void segregateEvenOdd(Node *&head_ref)
// {
//     Node *end = head_ref;
//     Node *prev = NULL;
//     Node *curr =head_ref;

//     /* Get pointer to the last node */
//     while (end->next != NULL)
//         end = end->next;

//     Node *new_end = end;

//     /* Consider all odd nodes before the first
//      even node and move then after end */
//     while (curr->data % 2 != 0 && curr != end)
//     {
//         new_end->next = curr;
//         curr = curr->next;
//         new_end->next->next = NULL;
//         new_end = new_end->next;
//     }

//     // 10->8->17->17->15
//     /* Do following steps only if
//     there is any even node */
//     if (curr->data % 2 == 0)
//     {
//         /* Change the head pointer to
//         point to first even node */
//         head_ref = curr;

//         /* now current points to
//         the first even node */
//         while (curr != end)
//         {
//             if ((curr->data) % 2 == 0)
//             {
//                 prev = curr;
//                 curr = curr->next;
//             }
//             else
//             {
//                 /* break the link between
//                 prev and current */
//                 prev->next = curr->next;

//                 /* Make next of curr as NULL */
//                 curr->next = NULL;

//                 /* Move curr to end */
//                 new_end->next = curr;

//                 /* make curr as new end of list */
//                 new_end = curr;

//                 /* Update current pointer to
//                 next of the moved node */
//                 curr = prev->next;
//             }
//         }
//     }

//     /* We must have prev set before executing
//     lines following this statement */
//     else
//         prev = curr;

//     /* If there are more than 1 odd nodes
//     and end of original list is odd then
//     move this node to end to maintain
//     same order of odd numbers in modified list */
//     if (new_end != end && (end->data) % 2 != 0)
//     {
//         prev->next = end->next;
//         end->next = NULL;
//         new_end->next = end;
//     }
//     return;
// }

// int main()
// {
//     Node *node1 = new Node(11);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     // Correction(empty list)
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     // todo
//     insertAtTail(tail, head, 2);
//     print(head);

//     insertAtTail(tail, head, 20);
//     print(head);

//     cout << "Original Linked list ";
//     print(head);

//     segregateEvenOdd(head);

//     cout << "\nModified Linked list ";
//     print(head);

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 9 Optimal solution

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // constructor
//     Node(int data)
//     { // * the “this” pointer is used to access the
//         //* "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertAtHead(Node *&head, Node *&tail, int d)
// {

//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head; // * As 'head' is pointing to 'node1'
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// {
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         tail->next = temp;
//         tail = temp; //* or 'tail->next' instead of 'temp'
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return; //*so that func returns and not execute following statements
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next; //* (temp->next) during 1st loop points to the node1's next
//         cnt++;             //* in reality i have made a ptr to the memory
//                            //* location that 'head' and 'node1' are also pointing to
//                            //* and then i am changing its value to the 'temp->next' address
//     }

//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, head, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next; //*if i do 'nodeToInsert' instead, i will be
//     temp->next = nodeToInsert;       //*making the 'nodeToInsert' ptr point to temp's 'next'
//     //*ie. pointing it to the agli allocated memory address and not changing
//     //*'nodeToInsert->next' value to 'temp->next'
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* Reversing our single linked list
// Node *reverse(Node *ptr)
// {
//     Node *pre = NULL;
//     Node *nex = NULL;
//     while (ptr != NULL)
//     {
//         nex = ptr->next;
//         ptr->next = pre;
//         pre = ptr;
//         ptr = nex;
//     }
//     return pre;
// }
// //todo
// Node* removeNthFromEnd(Node* head, int n) {
//         Node * start = new Node(11);//*can assign data as anything
//         start -> next = head;
//         Node* fast = start;
//         Node* slow = start;

//         for(int i = 1; i <= n; ++i)
//             fast = fast->next;

//         while(fast->next != NULL)
//         {
//             fast = fast->next;
//             slow = slow->next;
//         }

//         slow->next = slow->next->next;

//         return start->next;
//     }

// int main()
// {
//     Node *node1 = new Node(11);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // todo
//     // Correction(empty list)
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     // todo
//     insertAtTail(tail, head, 2);
//     print(head);

//     insertAtTail(tail, head, 20);
//     print(head);

//     cout<<"\n";
//     head=removeNthFromEnd(head,1);
//     print(head);

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 10 Optimal Solution [deleting mid node of LL]

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // *constructor
//     Node(int data)
//     {

//         this->data = data;
//         this->next = NULL;
//     }
//     //*destructor
//     ~Node()
//     {
//         int value = this->data;
//         //*memory free
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << " memory is free for node with data " << value << endl;
//     }
// };

// void insertAtHead(Node *&head, int d)
// {

//     //* new node created
//     Node *temp = new Node(d);
//     temp->next = head; // * As 'head' is pointing to 'node1'
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     tail->next = temp;
//     tail = temp; //* or 'tail->next' instead of 'temp'
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     if (position == 1)
//     {
//         insertAtHead(head, d);
//         return;
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(int position, Node *&head,Node *&tail)
// {

//     //* deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         //* memory free start ndoe
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //* deleting any middle node or last node
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt = 1;
//         while (cnt < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//         //* For last node deletion
//         if(prev->next == NULL){
//             tail=prev;
//         }
//     }
// }

// void findAndDeleteMiddle(Node* &head){
//     Node* slow=head;
//     Node* fast=head;
//     Node* prev=new Node(12);
//     prev->next=head;
//     while(fast!=NULL && fast->next!=NULL){
//         prev=prev->next;
//         slow=slow->next;
//         fast=fast->next->next;
//     }
//     prev->next=prev->next->next;
//     slow->next=NULL;  //*imp if not done then we are not breaking the link btw
//     delete(slow);//*slow and the next node which lead to the deletion of the
//                 //* whole node after that
// }

// int main()
// {

//     // created a new node
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     insertAtTail(tail, 20);
//     print(head);

//     insertAtTail(tail, 200);
//     print(head);

//     insertAtPosition(tail, head, 4, 90);
//     print(head);

//      insertAtTail(tail,300);
//     print(head);

//      insertAtTail(tail, 900);
//     print(head);

//    findAndDeleteMiddle(head);
//    print(head);

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;

//     return 0;
// }
//
//
//
//
//

//! 11 Optimal Solution [Sort LL]

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // *constructor
//     Node(int data)
//     {

//         this->data = data;
//         this->next = NULL;
//     }
//     //*destructor
//     ~Node()
//     {
//         int value = this->data;
//         //*memory free
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << " memory is free for node with data " << value << endl;
//     }
// };

// void insertAtHead(Node *&head, int d)
// {

//     //* new node created
//     Node *temp = new Node(d);
//     temp->next = head; // * As 'head' is pointing to 'node1'
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     tail->next = temp;
//     tail = temp; //* or 'tail->next' instead of 'temp'
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     if (position == 1)
//     {
//         insertAtHead(head, d);
//         return;
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(int position, Node *&head,Node *&tail)
// {

//     //* deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         //* memory free start ndoe
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //* deleting any middle node or last node
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt = 1;
//         while (cnt < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//         //* For last node deletion
//         if(prev->next == NULL){
//             tail=prev;
//         }
//     }
// }
// //todo to find the mid for breaking
// Node* findMid(Node* head) {
//     Node* slow = head;
//     Node* fast = head -> next;

//     while(fast != NULL && fast -> next != NULL) {
//         slow = slow -> next;
//         fast = fast -> next -> next;
//     }
//     return slow;
// }
// //todo to merge the two halves
// Node* merge(Node* left, Node* right) {

//     if(left == NULL)
//         return right;

//     if(right == NULL)
//         return left;

//     Node* ans = new Node(-1);
//     Node* temp = ans;

//     //merge 2 sorted Linked List
//     while(left != NULL && right != NULL) {
//         if(left -> data < right -> data ) {
//             temp -> next = left;
//             temp = left;
//             left = left -> next;
//         }
//         else
//         {
//             temp -> next = right;
//             temp = right;
//             right = right -> next;
//         }
//     }

//     while(left != NULL) {
//         temp -> next = left;
//         temp = left;
//         left = left -> next;
//     }

//     while(right != NULL) {
//         temp -> next = right;
//         temp = right;
//         right = right -> next;
//     }

//     ans = ans -> next;
//     return ans;

// }

// //todo to sort the linked list
// Node* mergeSort(Node *head) {
//     //base case
//     if( head == NULL || head -> next == NULL ) {
//         return head;
//     }

//     //* break linked list into 2 halvs, after finding mid
//     Node* mid = findMid(head);

//     Node* left = head;
//     Node* right = mid->next;
//     mid -> next = NULL;

//     //*recursive calls to sort both halves
//     left = mergeSort(left);
//     right = mergeSort(right);

//     //*merge both left and right halves
//     Node* result = merge(left, right);

//     return result;
// }

// int main()
// {

//     // created a new node
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     insertAtTail(tail, 20);
//     print(head);

//     insertAtTail(tail, 200);
//     print(head);

//     insertAtPosition(tail, head, 4, 90);
//     print(head);

//      insertAtTail(tail,300);
//     print(head);

//      insertAtTail(tail, 900);
//     print(head);

//     cout<<endl;
//     mergeSort(head);
//     print(head);

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;

//     return 0;
// }
//
//
//
//
//

// //! 12 Optimal Solution [Sort LL of 0s,1s,2s]

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // *constructor
//     Node(int data)
//     {

//         this->data = data;
//         this->next = NULL;
//     }
//     //*destructor
//     ~Node()
//     {
//         int value = this->data;
//         //*memory free
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << " memory is free for node with data " << value << endl;
//     }
// };

// void insertAtHead(Node *&head, int d)
// {

//     //* new node created
//     Node *temp = new Node(d);
//     temp->next = head; // * As 'head' is pointing to 'node1'
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     tail->next = temp;
//     tail = temp; //* or 'tail->next' instead of 'temp'
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     if (position == 1)
//     {
//         insertAtHead(head, d);
//         return;
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(int position, Node *&head,Node *&tail)
// {

//     //* deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         //* memory free start ndoe
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //* deleting any middle node or last node
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt = 1;
//         while (cnt < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//         //* For last node deletion
//         if(prev->next == NULL){
//             tail=prev;
//         }
//     }
// }

// //todo To sort the linked list of 0s,1s,2s
// Node* sortList(Node *head)
// {
//     Node *ptr = head;
//     int cnt[3] = {};

//     // Iterate while ptr is not empty
//     while(ptr)
//     {
//         cnt[ptr->data]++;
//         ptr = ptr->next;
//     }

//     ptr = head;
//     int i=0;

//     // Updating data.
//     while(ptr)
//     {
//         while(cnt[i] == 0)
//         {
//             i++;
//         }

//         ptr->data = i;
//         cnt[i]--;
//         ptr = ptr->next;
//     }

//     // Return head
//     return head;
// }

// int main()
// {

//     // created a new node
//     Node *node1 = new Node(1);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     insertAtTail(tail, 2);
//     print(head);

//     insertAtTail(tail, 0);
//     print(head);

//     insertAtPosition(tail, head, 4, 0);
//     print(head);

//      insertAtTail(tail,2);
//     print(head);

//      insertAtTail(tail, 1);
//     print(head);

//     cout<<endl;
//    sortList(head);
//     print(head);

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;

//     return 0;
// }
//
//
//
//
//

// // ! 13 Brute force solution [Find intersection of Two Linked Lists]

// #include<iostream>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int val) {
//             num = val;
//             next = NULL;
//         }
// };
// //utility function to insert node at the end of the linked list
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

// //utility function to check presence of intersection
// node* intersectionPresent(node* head1,node* head2) {
//     while(head2 != NULL) {
//         node* temp = head1;
//         while(temp != NULL) {
//             //if both nodes are same
//             if(temp == head2) return head2;
//             temp = temp->next;
//         }
//         head2 = head2->next;
//     }
//     //intersection is not present between the lists return null
//     return NULL;
// }

// //utility function to print linked list created
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     }
//     cout<<head->num<<endl;
// }

// int main() {
//     // creation of both lists
//     node* head = NULL;
//     insertNode(head,1);
//     insertNode(head,3);
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,4);
//     node* head1 = head;
//     head = head->next->next->next;
//     node* headSec = NULL;
//     insertNode(headSec,3);
//     node* head2 = headSec;
//     headSec->next = head;
//     //printing of the lists
//     cout<<"List1: "; printList(head1);
//     cout<<"List2: "; printList(head2);
//     //checking if intersection is present
//     node* answerNode = intersectionPresent(head1,head2);
//     if(answerNode == NULL )
//     cout<<"No intersection\n";
//     else
//     cout<<"The intersection point is "<<answerNode->num<<endl;
//     return 0;
// }
//
//
//
//
//

// // ! 13 Better solution [Find intersection of Two Linked Lists]

// #include<iostream>
// #include<unordered_set>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int val) {
//             num = val;
//             next = NULL;
//         }
// };
// //utility function to insert node at the end of the linked list
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

// //utility function to check presence of intersection
// node* intersectionPresent(node* head1,node* head2) {
//      unordered_set<node*> st;
//     while(head1 != NULL) {
//        st.insert(head1);
//        head1 = head1->next;
//     }
//     while(head2 != NULL) {
//         if(st.find(head2) != st.end()) return head2;
//         head2 = head2->next;
//     }
//     return NULL;

// }

// //utility function to print linked list created
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     }
//     cout<<head->num<<endl;
// }

// int main() {
//     // creation of both lists
//     node* head = NULL;
//     insertNode(head,1);
//     insertNode(head,3);
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,4);
//     node* head1 = head;
//     head = head->next->next->next;
//     node* headSec = NULL;
//     insertNode(headSec,3);
//     node* head2 = headSec;
//     headSec->next = head;
//     //printing of the lists
//     cout<<"List1: "; printList(head1);
//     cout<<"List2: "; printList(head2);
//     //checking if intersection is present
//     node* answerNode = intersectionPresent(head1,head2);
//     if(answerNode == NULL )
//     cout<<"No intersection\n";
//     else
//     cout<<"The intersection point is "<<answerNode->num<<endl;
//     return 0;
// }
//
//
//
//
//

// // ! 13 Optimal solution 1 [Find intersection of Two Linked Lists]

// #include<iostream>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int val) {
//             num = val;
//             next = NULL;
//         }
// };
// //utility function to insert node at the end of the linked list
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
// int getDifference(node* head1,node* head2) {
//      int len1 = 0,len2 = 0;
//         while(head1 != NULL || head2 != NULL) {
//             if(head1 != NULL) {
//                 ++len1; head1 = head1->next;
//             }
//             if(head2 != NULL) {
//                 ++len2; head2 = head2->next;
//             }

//         }
//         return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
// }

// //utility function to check presence of intersection
// node* intersectionPresent(node* head1,node* head2) {
//  int diff = getDifference(head1,head2);
//         if(diff < 0)
//             while(diff++ != 0) head2 = head2->next;
//         else while(diff-- != 0) head1 = head1->next;
//         while(head1 != NULL) {
//             if(head1 == head2) return head1;
//             head2 = head2->next;
//             head1 = head1->next;
//         }
//         return head1;

// }

// //utility function to print linked list created
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     }
//     cout<<head->num<<endl;
// }

// int main() {
//     // creation of both lists
//     node* head = NULL;
//     insertNode(head,1);
//     insertNode(head,3);
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,4);
//     node* head1 = head;
//     head = head->next->next->next;
//     node* headSec = NULL;
//     insertNode(headSec,3);
//     node* head2 = headSec;
//     headSec->next = head;
//     //printing of the lists
//     cout<<"List1: "; printList(head1);
//     cout<<"List2: "; printList(head2);
//     //checking if intersection is present
//     node* answerNode = intersectionPresent(head1,head2);
//     if(answerNode == NULL )
//     cout<<"No intersection\n";
//     else
//     cout<<"The intersection point is "<<answerNode->num<<endl;
//     return 0;
// }
//
//
//
//
//

// // ! 13 Optimal solution 2 [Find intersection of Two Linked Lists]

// #include<iostream>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int val) {
//             num = val;
//             next = NULL;
//         }
// };
// //utility function to insert node at the end of the linked list
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
// //*utility function to check presence of intersection
// node* intersectionPresent(node* head1,node* head2) {
//     if(head1 == NULL || head2 == NULL)return NULL;
//     node* d1 = head1;
//     node* d2 = head2;

//     while(d1 != d2) {
//     //*if d1 is "NULL" we shift it to the "head2" if not then move
//     //*it to the next node and same for d2
//         d1 = d1 == NULL? head2:d1->next;
//         d2 = d2 == NULL? head1:d2->next;
//     }

//     return d1;//*returns "NULL" if a==b;
// }

// //utility function to print linked list created
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     }
//     cout<<head->num<<endl;
// }

// int main() {
//     // creation of both lists
//     node* head = NULL;
//     insertNode(head,1);
//     insertNode(head,3);
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,4);
//     node* head1 = head;
//     head = head->next->next->next;
//     node* headSec = NULL;
//     insertNode(headSec,3);
//     node* head2 = headSec;
//     headSec->next = head;
//     //printing of the lists
//     cout<<"List1: "; printList(head1);
//     cout<<"List2: "; printList(head2);
//     //checking if intersection is present
//     node* answerNode = intersectionPresent(head1,head2);
//     if(answerNode == NULL )
//     cout<<"No intersection\n";
//     else
//     cout<<"The intersection point is "<<answerNode->num<<endl;
//     return 0;
// }
//
//
//
//
//

// // ! 14 Optimal Solution

// #include <iostream>
// #include <map>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     // *constructor
//     Node(int data)
//     {

//         this->data = data;
//         this->next = NULL;
//     }
//     //*destructor
//     ~Node()
//     {
//         int value = this->data;
//         //*memory free
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << " memory is free for node with data " << value << endl;
//     }
// };

// void insertAtHead(Node *&head, int d)
// {

//     //* new node created
//     Node *temp = new Node(d);
//     temp->next = head; // * As 'head' is pointing to 'node1'
//     head = temp;
// }

// void insertAtTail(Node *&tail, int d)
// {
//     Node *temp = new Node(d);
//     tail->next = temp;
//     tail = temp; //* or 'tail->next' instead of 'temp'
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     if (position == 1)
//     {
//         insertAtHead(head, d);
//         return;
//     }
//     int cnt = 1;
//     while (cnt < position - 1)
//     {
//         temp = temp->next;
//         cnt++;
//     }

//     if (temp->next == NULL)
//     {
//         insertAtTail(tail, d);
//         return;
//     }

//     // * Creating a node for d
//     Node *nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void deleteNode(int position, Node *&head, Node *&tail)
// {

//     //* deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         head = head->next;
//         //* memory free start ndoe
//         temp->next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //* deleting any middle node or last node
//         Node *curr = head;
//         Node *prev = NULL;

//         int cnt = 1;
//         while (cnt < position)
//         {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }

//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//         //* For last node deletion
//         if (prev->next == NULL)
//         {
//             tail = prev;
//         }
//     }
// }

// Node *reverse(Node *head)
// {
//     // If the list is empty or has just one node, return head.
//     if (head == NULL || head->next == NULL)
//     {
//         return head;
//     }

//     // Pointer to the previous node of the current node.
//     Node *prev = NULL;

//     // Pointer to the current node.
//     Node *curr = head;

//     while (curr != NULL)
//     {

//         // Pointer to the next node of the current node.
//         Node *ahead = curr->next;

//         // Inverting the links
//         curr->next = prev;
//         prev = curr;
//         curr = ahead;
//     }

//     return prev;
// }

// //todo Start

// Node *addOne(Node *head)
// {
//     // Reverse the list.
//     head = reverse(head);

//     Node *temp = head;

//     // Initialize a variable to store carry.
//     int carry = 1;

//     // Initialize a pointer to store previous node.
//     Node *prev = head;

//     // Adding 1 to the reversed linked list
//     while (head != NULL)
//     {
//         int sum = carry + head->data;
//         carry = sum / 10;
//         sum = sum % 10;
//         head->data = sum;
//         prev = head;
//         head = head->next;
//     }

//     // If there is carry after processing all nodes, add a new node at the end of the linked list.
//     if (carry != 0)
//     {

//         Node *newNode = new Node(0);
//         newNode->data = carry;

//         // Appending the newNode at the end of the resultant list.
//         if (prev != NULL)
//         {
//             prev->next = newNode;
//         }

//         else
//         {
//             // If the resultant list is empty
//             return newNode;
//         }
//     }
    

//     // Reverse the resultant list.
//     Node *ans = reverse(temp);

//     return ans;
// }

// int main()
// {

//     // created a new node
//     Node *node1 = new Node(9);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     insertAtTail(tail, 9);
//     print(head);

//     insertAtTail(tail, 4);
//     print(head);

//     insertAtPosition(tail, head, 4, 3);
//     print(head);

//     insertAtTail(tail, 2);
//     print(head);

//     insertAtTail(tail, 9);
//     print(head);

//     cout<<endl;
//     addOne(head);
//     print(head);

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;

//     return 0;
// }
//
//
//
//
//

// // ! 15 Optimal Solution

// #include <iostream>

// using namespace std;

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//   ListNode *dummy = new ListNode(0);
//   ListNode *temp = dummy;
//   int carry = 0;
//   while (l1 != NULL || l2 != NULL || carry) {
//     int sum = 0;
//     if (l1 != NULL) {
//       sum += l1->val;
//       l1 = l1->next;
//     }
//     if (l2 != NULL) {
//       sum += l2->val;
//       l2 = l2->next;
//     }
//     sum += carry;
//     carry = sum / 10;
//     ListNode *node = new ListNode(sum % 10);
//     temp->next = node;
//     temp = temp->next;
//   }
//   return dummy->next;
// }

// void printList(ListNode *head) {
//   while (head != NULL) {
//     cout << head->val << " ";
//     head = head->next;
//   }
//   cout << endl;
// }

// int main() {
//   ListNode *l1 = new ListNode(9);
//   l1->next = new ListNode(9);
//   l1->next->next = new ListNode(3);

//   ListNode *l2 = new ListNode(9);
//   l2->next = new ListNode(9);
//   l2->next->next = new ListNode(4);

//   ListNode *sumList = addTwoNumbers(l1, l2);

//   printList(sumList);

//   return 0;
// }
//
//
//
//
//