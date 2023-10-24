
// // ! 1 Singly Linked List, Implementation of the Node :

// #include <iostream>
// #include <map>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;

//     // * constructor
//     Node(int data)
//     {   // * the “this” pointer is used to access the
//         // * "data and next” data member of the object.
//         this->data = data;
//         this->next = NULL;
//     }
// };

//     int main()
//     {
//         //todo
//         // * created a new node
//         Node *node1 = new Node(10);
//         cout << node1->data << endl;
//         cout << node1->next << endl;
//         return 0;
//     }
//
//
//
//
//

// // ! 2 Insertion And Traversing in SLL

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
//
//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, d);
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
//
//     //*inserting at Last Position
//     if (temp->next == NULL) //*Case 2
//     {
//         insertAtTail(tail, d);
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

// int main()
// {

//     // created a new node
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // //todo
//     // insertAtHead(head, 12);
//     // print(head);

//     // insertAtHead(head, 120);
//     // print(head);

//     // //todo
//     // insertAtTail(tail, 20);
//     // print(head);

//     // insertAtTail(tail, 200);
//     // print(head);

//     // // //todo
//     // insertAtTail(tail, 20);
//     // print(head);

//     // insertAtTail(tail, 200);
//     // print(head);

//     // insertAtPosition(tail, head, 4, 90);
//     // print(head);

//     // cout << "head " << head->data << endl;
//     // cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 2 Insertion with correction for empty list(SINGLY LL)

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

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);
//
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

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// //! 3 Deletion, Destructor in SLL

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

//     deleteNode(4, head,tail); //* tail only for "last node" deletion condition
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

// // ! 4 Length of SLL, Search an element in the SLL

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

// int lengthLinkedList(Node* head){
//     if (head==NULL){
//         return -1;
//     }
//     int len=1;
//     while(head->next!=NULL){
//         len++;
//         head=head->next;
//     }
//     return len;
// }

// int searchForPosition(Node* head,int element){
//     int pos=1;
//     while(head->data!=element){
//         head=head->next;
//         pos++;
//     }
//     return pos;
// }

// int main()
// {
//     Node *node1 = new Node(10);

//     //* head pointed to node1
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // Correction(empty list)
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 12);
//     print(head);

//     insertAtHead(head, tail, 120);
//     print(head);

//     insertAtTail(tail, head, 20);
//     print(head);

//     int length= lengthLinkedList(head);
//     cout<<"length: "<<length<<endl;

//     int position = searchForPosition(head,10);
//     cout<<"Position: "<<position<<endl;

//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     return 0;
// }
//
//
//
//
//

// // ! 5 Doubly Linked List, Implementation of node,traversing a linked list,length of the LL

// #include <iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node* prev;
//     Node* next;

//     //* constructor
//     Node(int d){
//         this->data=d;
//         this->prev=NULL;
//         this->next=NULL;
//     }
// };

// //* traversing a linked list
// void print(Node* head){
//     Node* temp= head;
//     while(temp!=NULL){
//         cout<<temp->data<<endl;
//         temp=temp->next;
//     }
// }

// //* gives length of linked list
// int getLength(Node* head){
//      Node* temp= head;
//      int len=0;
//     while(temp!=NULL){
//         len++;
//         temp=temp->next;
//     }
//     return len;
// }

// int main(){
//     Node* node1= new Node(10);
//     Node* head= node1;

//     print(head);

//     int length=getLength(head);
//     cout<<length<<endl;

//     return 0;
// }
//
//
//
//
//

// // ! 6 Insertion, Correction(empty list) in DLL

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *prev;
//     Node *next;

//     //* constructor
//     Node(int d)
//     {
//         this->data = d;
//         this->prev = NULL;
//         this->next = NULL;
//     }
// };

// //* traversing a linked list
// void print(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* gives length of linked list
// int getLength(Node *&head)
// {
//     Node *temp = head;
//     int len = 0;
//     while (temp != NULL)
//     {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }

// void insertAtHead(Node *&head, Node *&tail, int d)
// { //*empty list
//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head;
//         head->prev = temp;
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// { //*empty list
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->prev = tail;
//         tail->next = temp;
//         tail = temp;
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return;
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
//     temp->next->prev = nodeToInsert;
//     nodeToInsert->prev = temp;
// }

// int main()
// {
//     Node *node1 = new Node(10);
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);
//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     cout << endl;

//     // //* Correction : empty list
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 5);
//     print(head);
//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     cout << endl;
//     insertAtHead(head, tail, 2);
//     print(head);
//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     cout << endl;
//     insertAtTail(tail, head, 1);
//     print(head);
//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     cout << endl;
//     insertAtPosition(tail, head, 4, 9);
//     print(head);
//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     cout << endl;
//     insertAtPosition(tail, head, 5, 10);
//     print(head);
//     cout << "head " << head->data << endl;
//     cout << "tail " << tail->data << endl;
//     cout << endl;
//     insertAtPosition(tail, head, 6, 90);
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

// //! 7 Deletion in DLL

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *prev;
//     Node *next;

//     //* constructor
//     Node(int d)
//     {
//         this->data = d;
//         this->prev = NULL;
//         this->next = NULL;
//     }
//     ~Node()
//     {
//         int val = this->data;
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << "memory free for node with data " << val << endl;
//     }
// };

// //* traversing a linked list
// void print(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* gives length of linked list
// int getLength(Node *&head)
// {
//     Node *temp = head;
//     int len = 0;
//     while (temp != NULL)
//     {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }

// void insertAtHead(Node *&head, Node *&tail, int d)
// { //*empty list
//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head;
//         head->prev = temp;
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// { //*empty list
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->prev = tail;
//         tail->next = temp;
//         tail = temp;
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return;
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
//     temp->next->prev = nodeToInsert;
//     nodeToInsert->prev = temp;
// }

// void deleteNode(int position, Node *&head, Node *&tail)
// {

//     //* deleting first or start node
//     if (position == 1)
//     {
//         Node *temp = head;
//         temp->next->prev = NULL;
//         head = temp->next;
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

//         curr->prev=NULL;
//         prev->next=curr->next;
//         curr->next=NULL;
//         delete curr;
//         //* For last node deletion(so tail points to last ele)
//         if (prev->next == NULL)
//         {
//             tail = prev;
//         }
//     }
// }

// int main()
// {
//     Node *node1 = new Node(10);
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // //* Correction : empty list
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 5);
//     print(head);

//     insertAtHead(head, tail, 2);
//     print(head);

//     insertAtTail(tail, head, 1);
//     print(head);

//     insertAtPosition(tail, head, 4, 9);
//     print(head);

//     insertAtPosition(tail, head, 5, 10);
//     print(head);

//     insertAtPosition(tail, head, 6, 90);
//     print(head);

//     deleteNode(6,head,tail);
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

// // ! 8 Reverse a DLL

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *prev;
//     Node *next;

//     //* constructor
//     Node(int d)
//     {
//         this->data = d;
//         this->prev = NULL;
//         this->next = NULL;
//     }
// };

// //* traversing a linked list
// void print(Node *head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// //* gives length of linked list
// int getLength(Node *&head)
// {
//     Node *temp = head;
//     int len = 0;
//     while (temp != NULL)
//     {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }

// void insertAtHead(Node *&head, Node *&tail, int d)
// { //*empty list
//     if (head == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->next = head;
//         head->prev = temp;
//         head = temp;
//     }
// }

// void insertAtTail(Node *&tail, Node *&head, int d)
// { //*empty list
//     if (tail == NULL)
//     {
//         Node *temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         Node *temp = new Node(d);
//         temp->prev = tail;
//         tail->next = temp;
//         tail = temp;
//     }
// }

// void insertAtPosition(Node *&tail, Node *&head, int position, int d)
// {
//     Node *temp = head;

//     //*insert at Start
//     if (position == 1) //*Case 1
//     {
//         insertAtHead(head, tail, d);
//         return;
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
//     temp->next->prev = nodeToInsert;
//     nodeToInsert->prev = temp;
// }

// // Reversing our double linked list
// void reverse(Node *&head)
// {
//     Node *prev = NULL;
//     Node *curr = head;
//     Node *next = NULL;

//     while (curr != NULL)
//     {
//         next = curr->next;
//         curr->next = prev;
//         curr->prev = next;//*will work for SLL too(just remove this line)
//         prev = curr;      //* as (curr->prev) is not defined in SLL
//         curr = next;
//     }
    
//     cout << endl;
//     cout<<head->data << "   ";

//     //* If the linked list is empty or has only one node,
//     //* the head pointer will be pointing to NULL. We need to
//     //* set the head pointer to the previous node, which will
//     //* be the new head of the reversed linked list.
//     if (head == NULL || head->next == NULL) //*check o/p after removing this
//     {
//         head = prev;
//     }

//     cout << endl;
//     cout<< head->data << "   ";
// }

// int main()
// {
//     Node *node1 = new Node(10);
//     Node *head = node1;
//     Node *tail = node1;
//     print(head);

//     // //* Correction : empty list
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 5);
//     print(head);

//     insertAtHead(head, tail, 2);
//     print(head);

//     insertAtTail(tail, head, 1);
//     print(head);

//     insertAtPosition(tail, head, 4, 9);
//     print(head);

//     insertAtPosition(tail, head, 5, 10);
//     print(head);

//     insertAtPosition(tail, head, 6, 90);
//     print(head);

//     cout << "reverse is: " << endl;
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

// // ! 9 Singly Linked CLL,Implementation of Node,constructor,destructor

// #include <iostream>
// using namespace std;

// class Node{
//     int data;
//     Node* next;

//     //*constructor
//     Node(int data){
//         this->data=data;
//         this->next=NULL;
//     }

//     //*destructor
//     ~Node(){
//         int value= this->data;
//         if(this-> next != NULL){
//             delete next;
//             this-> next= NULL;
//         }
//         cout<<"memory is free for node with data "<<value<<endl;
//     }
// };

// int main(){

//     return 0;
// }
//
//
//
//
//

// // ! 10 Insertion, Traversing in CLL

// #include <iostream>
// using namespace std;

// class Node
// {   public:
//     int data;
//     Node* next;

//     //*constructor
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }

//     //*destructor
//     ~Node()
//     {
//         int value = this->data;
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << "memory is free for node with data " << value << endl;
//     }
// };

// void insertNode(Node* &tail, int element, int d) {

//     //*empty list
//     if(tail == NULL) {
//         Node* newNode = new Node(d);
//         tail = newNode;
//         newNode -> next = newNode;
//     }
//     else{
//         //*non-empty list
//         //*assuming that the element is present in the list

//         Node* curr = tail;

//         while(curr->data != element) {
//             curr = curr -> next;
//         }

//         //element found -> curr is representing element wala node
//         Node* temp = new Node(d);
//         temp -> next = curr -> next;
//         curr -> next = temp;

//     }

// }
// //* Traversing the CLL (imp not to use '&' in func def)
// void print(Node* tail) {

//     Node* temp = tail;

//     //empty list
//     if(tail == NULL) {
//         cout << "List is Empty "<< endl;
//         return ;
//     }

//     do {
//         cout << tail -> data << " ";
//         tail = tail -> next;
//     } while(tail != temp);

//     cout << endl;
// }

// int main()
// {   Node* tail= NULL;

//     insertNode(tail,3,5);
//     print(tail);

//     insertNode(tail,5,25);
//     print(tail);

//     insertNode(tail,5,2);
//     print(tail);
//     return 0;
// }
//
//
//
//
//

// // ! 11 Deletion in CLL

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     //*constructor
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }

//     //*destructor
//     ~Node()
//     {
//         int value = this->data;
//         if (this->next != NULL)
//         {
//             delete next;
//             this->next = NULL;
//         }
//         cout << "memory is free for node with data " << value << endl;
//     }
// };

// void insertNode(Node *&tail, int element, int d)
// {

//     //*empty list
//     if (tail == NULL)
//     {
//         Node *newNode = new Node(d);
//         tail = newNode;
//         newNode->next = newNode;
//     }
//     else
//     {
//         //*non-empty list
//         //*assuming that the element is present in the list

//         Node *curr = tail;

//         while (curr->data != element)
//         {
//             curr = curr->next;
//         }

//         // element found -> curr is representing element wala node
//         Node *temp = new Node(d);
//         temp->next = curr->next;
//         curr->next = temp;
//     }
// }

// //* Traversing the CLL
// void print(Node *tail)
// {

//     Node *temp = tail;

//     //*empty list
//     if (tail == NULL)
//     {
//         cout << "List is Empty " << endl;
//         return;
//     }

//     do
//     {
//         cout << tail->data << " ";
//         tail = tail->next;
//     } while (tail != temp);

//     cout << endl;
// }

// void deleteNode(Node *&tail, int value)
// {

//     //*empty list
//     if (tail == NULL)
//     {
//         cout << " List is empty, please check again" << endl;
//         return;
//     }
//     else
//     {
//         //*non-empty

//         //*assuming that "value" is present in the Linked List
//         Node *prev = tail;
//         Node *curr = prev->next;

//         while (curr->data != value)
//         {
//             prev = curr;
//             curr = curr->next;
//         }

//         prev->next = curr->next;

//         //* 1 Node Linked List
//         if(curr == prev) {
//             tail = NULL;
//         }

//         //* >=2 Node linked list
//         if (tail == curr)
//         {
//             tail = prev;
//         }

//         curr->next = NULL;
//         delete curr;
//     }
// }

// int main()
// {
//     Node *tail = NULL;

//     insertNode(tail, 3, 5);
//     print(tail);

//     insertNode(tail, 5, 25);
//     print(tail);

//     insertNode(tail, 5, 2);
//     print(tail);

//     insertNode(tail, 2, 99);
//     print(tail);

//     insertNode(tail, 99, 0);
//     print(tail);

//     deleteNode(tail,0);
//     print(tail);

//     deleteNode(tail, 5);
//     print(tail);

//     cout << "tail " << tail->data; //*will give SF for tail==NULL

//     return 0;
// }