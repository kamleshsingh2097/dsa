
// //! 1 Delete all occurences of a given DLL

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

// Node * deleteAllOccurrences(Node* head, int k) {
//     if (head == NULL)
//         return head;

//     Node *temp = head;
//     while (temp != NULL) {
//         if (temp -> data == k) {
//             Node *temp2 = temp;

//             if (temp -> prev != NULL)
//                 temp -> prev -> next = temp -> next;
//             if (temp -> next != NULL)
//                 temp -> next -> prev = temp -> prev;

//             if (temp == head)
//                 head = head -> next;
//             temp = temp -> next;

//             delete temp2;
//         } else
//             temp = temp -> next;
//     }

//     return head;
// }

// int main()
// {
//     Node *node1 = new Node(10);
//     Node *head = node1;
//     Node *tail = node1;

//     // //* Correction : empty list
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 5);

//     insertAtHead(head, tail, 2);

//     insertAtTail(tail, head, 2);

//     insertAtPosition(tail, head, 4, 2);

//     insertAtPosition(tail, head, 5, 10);

//     insertAtPosition(tail, head, 6, 90);
//     print(head);
//     cout << "\n";

//     deleteAllOccurrences(head, 10);
//     print(head);

//     return 0;
// }
// //
// //
// //
// //
// //

// //! 2 Find pairs with given sum in DLL [Brute Force Solution]

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

// vector < pair< int,int > > findPairs(Node* head, int k)
// {
//     vector<pair<int, int> > ans;
//     Node * ptr1 = head;

//     // Traverse the linked list to the end.
//     while (ptr1 != NULL)
//     {
//         Node * ptr2 = ptr1->next;
//         while (ptr2 != NULL)
//         {
//             if (ptr1->data + ptr2->data == k)
//             {
//                 ans.push_back(make_pair(ptr1->data, ptr2->data));
//             }

//             ptr2 = ptr2->next;
//         }

//         ptr1 = ptr1->next;
//     }

//     return ans;
// }

// int main()
// {
//     Node *node1 = new Node(10);
//     Node *head = node1;
//     Node *tail = node1;

//     // //* Correction : empty list
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 2);

//     insertAtHead(head, tail, 6);

//     insertAtTail(tail, head, 6);

//     insertAtPosition(tail, head, 4, 2);

//     insertAtPosition(tail, head, 5, 10);

//     insertAtPosition(tail, head, 6, 90);
//     print(head);
//     cout << "\n";

//     vector<pair<int, int> > pairs=findPairs(head,12);
//     for(int i=0;i<pairs.size();i++){
//         cout<<"pairs are "<<pairs[i].first<<" "<<pairs[i].second<<endl;
//     }

//     return 0;
// }
//
//
//
//
//

// //! 2 Find pairs with given sum in DLL [Better Solution]

// #include <iostream>
// #include <unordered_set>
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

// vector<pair<int, int> > findPairs(Node* head, int k)
// {
//     vector<pair<int, int> > ans;
//     Node * ptr1 = head;

//     unordered_set<int> hash;

//     // Traverse the linked list to the end.
//     while (ptr1 != NULL)
//     {
//         int val = ptr1->data;
//         if (hash.find(k - val) != hash.end())
//         {
//             ans.emplace_back(val,k-val);
//         }
//         else
//         {
//             hash.insert(val);
//         }

//         ptr1 = ptr1->next;
//     }

//     return ans;
// }
// int main()
// {
//     Node *node1 = new Node(10);
//     Node *head = node1;
//     Node *tail = node1;

//     // //* Correction : empty list
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 2);

//     insertAtHead(head, tail, 6);

//     insertAtTail(tail, head, 6);

//     insertAtPosition(tail, head, 4, 2);

//     insertAtPosition(tail, head, 5, 10);

//     insertAtPosition(tail, head, 6, 90);
//     print(head);
//     cout << "\n";

//     vector<pair<int, int> > pairs=findPairs(head,12);
//     for(int i=0;i<pairs.size();i++){
//         cout<<"pairs are "<<pairs[i].first<<" "<<pairs[i].second<<endl;
//     }

//     return 0;
// }
//
//
//
//
//

/*The steps are as follows:

findPairs(Node * ‘head’, int ‘k’)

=Let ‘ans’ be the list of the valid pairs.

=Let ‘start’ and ‘end’ be two pointers, both initialized to ‘head’. Iterate 
 ‘end’ to the last node of the linked list.

=While ‘start→data’ < ‘end→data’ :
   If the sum of data at ‘start’ and ‘end’ is equal to ‘k’, add the pair of ‘start→data’ 
   and ‘end→data’ to ‘ans’ and update ‘start’ and ‘end’ to their next and previous nodes 
   respectively.
   
   
   If the sum is less than ‘k’, then we move ‘start’ in the forward direction.
   
   
   If the sum is greater than ‘k’, then we move ‘end’ in the backward direction.
=Return ‘ans’.
*/

// //! 2 Find pairs with given sum in DLL [Optimal Solution]

// #include <iostream>
// #include <unordered_set>
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

// vector<pair<int, int> > findPairs(Node* head, int k)
// {
//     vector<pair<int, int> > ans;
//     Node * start = head;
//     Node * end = head;

//     // Traverse the linked list to the end.
//     while (end->next != NULL)
//     {
//         end = end->next;
//     }

//     while (start->data < end->data)
//     {
//         int sum = start->data + end->data;
//         if (sum == k)
//         {
//             ans.push_back(make_pair(start->data, end->data));
//             start = start->next;
//             end = end->prev; //*as it is at the end and on moving previous its value will decrease
//         }//*therefore we have to increase the value of [start] by doing [start=start->next](because of sorted LL)

//         else if (sum < k)//*means we have to increase [start] as [end] cant be increase further
//         {
//             start = start->next;
//         }
//         else//*means sum is bigger than [k] therefore we have to decrease [end] as [start] can't
//             //* be decreased further
//         {
//             end = end->prev;
//         }

//     }

//     return ans;
// }

// int main()
// {
//     Node *node1 = new Node(7);
//     Node *head = node1;
//     Node *tail = node1;

//     // //* Correction : empty list
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 2);

//     insertAtHead(head, tail, 5);

//     insertAtTail(tail, head, 8);

//     insertAtTail(tail, head, 9);

    
//     print(head);
//     cout << "\n";

//     vector<pair<int, int> > pairs=findPairs(head,12);
//     for(int i=0;i<pairs.size();i++){
//         cout<<"pairs are "<<pairs[i].first<<" "<<pairs[i].second<<endl;
//     }

//     return 0;
// }
//
//
//
//
//

// // ! 3 Remove duplicates from a sorted DLL

// #include <iostream>
// #include <unordered_set>
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

// /*Check if the current element has the same value as the next element,
// if so adjust the pointers such that the next to next element of the 
// current element is the next element. Refer to the steps below for a
//  better understanding.*/

// Node * removeDuplicates(Node *head)
// {

//     // Initialize 'cur' to store head
//     Node * cur = head;
    
   
//     // Run a while loop
//     while (cur != NULL && cur -> next != NULL) {

//         // Next element has same value as the current element
//         if (cur -> next -> data == cur -> data) {
//             // Adjust links to remove the next element
//             cur -> next = cur -> next -> next;
            
//         }

//         // Next element is different from the current element
//         else {
//             cur = cur -> next;
//         }
//     }

//     return head;
// }

// int main()
// {
//     Node *node1 = new Node(7);
//     Node *head = node1;
//     Node *tail = node1;

//     // //* Correction : empty list
//     // Node *head = NULL;
//     // Node *tail = NULL;
//     // print(head);

//     insertAtHead(head, tail, 2);

//     insertAtHead(head, tail, 2);

//     insertAtTail(tail, head, 8);

//     insertAtTail(tail, head, 9);

//     print(head);
//     cout << "\n";

//    removeDuplicates(head);
//    print(head);
//     return 0;
// }
//
//
//
//
//

