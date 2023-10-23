
// //! 1 Recursive implementation of atoi()

// #include <iostream>
// #include <string>
// using namespace std;

// long atoi(string s, int sign, int i, long result)
// {
//     if (sign * result >= INT_MAX)
//     {
//         return INT_MAX;
//     }
//     if (sign * result <= INT_MIN)
//     {
//         return INT_MIN;
//     }
//     if (i >= s.size() || s[i] < '0' || s[i] > '9')
//     {
//         return sign * result;
//     }
//     //*upper 3 are the [base conditions]

//     result = atoi(s, sign, i + 1, (result * 10 + (s[i] - '0')));

//     return result;
// }

// int myAtoi(string s)
// {

//     int i = 0, n = s.size(), sign = 1;
//     while (i < n && s[i] == ' ')
//         ++i;

//     if (s[i] == '-')
//         sign = -1, ++i;
//     else if (s[i] == '+')
//         ++i;

//     //*will lead us to the main interger part
//     return atoi(s, sign, i, 0);
// }

// int main()
// {
//     string ch = "  -49";
//     int number = myAtoi(ch);
//     cout<<number;
//     return 0;
// }
//
//
//
//
//

// //! 2 Pow(x,n) [Brute force solution]

// #include<iostream>
// using namespace std;
// double myPow(double x, int n) {
//       double ans = 1.0;
//       for (int i = 0; i < n; i++) {
//         ans = ans * x;
//       }
//       return ans;
// }
// int main()
// {   //*can make this for negative values too by using code like optimal soln approach
//     //*ie. adding this line [if (n < 0) ans = (double)(1.0) / (double)(ans);]
//     cout<<myPow(2,10)<<endl;
// }

// //! 2 Pow(x,n) [Optimal solution]

// #include<iostream>

// using namespace std;
// double myPow(double x, int n) {
//   double ans = 1.0;
//   long long nn = n;
//   if (nn < 0) nn = -1 * nn;
//   while (nn) {
//     if (nn % 2) {
//       ans = ans * x;
//       nn = nn - 1;
//     } else {
//       x = x * x;
//       nn = nn / 2;
//     }
//   }
//   if (n < 0) ans = (double)(1.0) / (double)(ans);
//   return ans;
// }

// int main() {
//   cout << myPow(2, -10) << endl;
// }
//
//
//
//
//

// // //! 2 Pow(x,n) [Recursive approach]

// #include <iostream>
// using namespace std;

// double func(double x,int n){
//     if (n==0)return 1;//*Base condition
//     if (n%2==0){
//         return func(x*x,n/2);
//     }

//     else{
// //* n=n-1 not needed as--> the value of 5/2=4 only and we multiplied by x too
//         return x*func(x*x,n/2);
//     }
// }

// double myPow(double x,int n){
//     if (n<0){
//         double ans=func(x,n);
//         return 1/ans;
//     }
//     return func(x,n);
// }

// int main(){
//     cout<<myPow(2,-2);
//     return 0;
// }
//
//
//
//
//

// //! 3 Count Good Numbers

// #include <iostream>
// using namespace std;

// #define mod 1000000007

// long long power(long long x, long long n)
// {
//     if (n == 0)
//     {
//         return 1;
//     }
//     long long ans = power(x, n / 2);
//     ans *= ans;
//     ans %= mod;
//     if (n % 2 == 1)
//     {
//         ans *= x;
//         cout << ans << endl;
//         ans %= mod;
//     }
//     // cout<<ans<<endl;
//     return ans;
// }

// int countGoodNumbers(long long n)
// {
//     long long numberOfOddPlaces = n / 2;
//     long long numberOfEvenPlaces = n / 2 + n % 2;
//     return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces)) % mod;
// }

// int main()
// {
//     int n = countGoodNumbers(2);
//     cout << n;
//     return 0;
// }
//
//
//
//
//

// //! 4 Sort a stack using recursion

// #include <iostream>
// #include <stack>
// using namespace std;
// void sortedInsert(stack<int> &st, int element)
// {
//     if (st.empty() || element > st.top())
//         st.push(element);
//     else
//     {
//         int top_element = st.top();
//         st.pop();
//         sortedInsert(st, element);
//         st.push(top_element);
//     }
// }
// void sortStack(stack<int> &st)
// {
//     if (!st.empty())
//     {
//         int top_element = st.top();

//         cout << endl;
//         cout << top_element << " ";
//         cout << endl;

//         st.pop();
//         sortStack(st);

//         sortedInsert(st, top_element);
//     }
// }
// int main()
// {
//     stack<int> st;
//     int n;
//     cin >> n;
//     //* Run 12,33,21
//     while (n--)
//     {
//         int x;
//         cin >> x;
//         st.push(x);
//     }
//     sortStack(st);
//     while (!st.empty())
//     {
//         int top = st.top();
//         st.pop();
//         cout << top << endl;
//     }
//     return 0;
// }
//
//
//
//
//

// //! 5 Reverse a stack using recursion

// #include <iostream>
// #include <stack>
// using namespace std;

// /*is the insertAtBottom() function stopping and allowing stack.push(top) to 
// execute because it does not have any element after 1???if input is 1,2,3,4,5
//  in the stack???
 
//  Yes, the insertAtBottom() function will stop and allow stack.push(top) to 
//  execute when the input is 1, 2, 3, 4, 5. This is because the stack will be
//   empty after the element 1 is removed.

// */

// /*but in the removing condition it is written to push the element too. so what
//  will happen when there is no element after 1???
 
//  You are right. The insertAtBottom() function will try to push the top element
// back onto the stack after it has removed it. However, if the stack is empty
//  after the top element is removed, then the push() operation will fail.

// In the case of the input 1, 2, 3, 4, 5, the stack will be empty after the 
// element 1 is removed. Therefore, the push() operation will fail and the
//  function will return.*/

// void insertAtBottom(stack<int> &stack, int ele)
// {
//     if (stack.empty())
//     {
//         // If the stack is empty, simply push the element
//         stack.push(ele);
//         return;
//     }

//     // If the stack is not empty, remove the top element
//     int top = stack.top();
//     stack.pop();

//     // Recursively call insertAtBottom to insert the element at the bottom
//     insertAtBottom(stack, ele);

//     // Push the removed top element back onto the stack
//     stack.push(top);
// }

// // Function to reverse the elements of the stack
// void reverseStack(stack<int> &stack)
// {
//     if (stack.empty())
//     {
//         // Base case: If the stack is empty, no elements to reverse
//         return;
//     }

//     // If the stack is not empty, remove the top element
//     int top = stack.top();
//     stack.pop();

//     // Recursively call reverseStack to reverse the remaining elements
//     reverseStack(stack);

//     // After reversing the remaining elements, insert the removed top element at the bottom
//     insertAtBottom(stack, top);
// }

// int main()
// {
//     stack<int> st;
//     int n;
//     cin >> n;
//     while (n--)
//     {
//         int x;
//         cin >> x;
//         st.push(x);
//     }
//     reverseStack(st);//*for 1,2,3 will give O/P as 1,2,3 as stack is LIFO
//     while (!st.empty())
//     {
//         int top = st.top();
//         st.pop();
//         cout << top << endl;
//     }
//     return 0;
// }
//
//
//
//
//
