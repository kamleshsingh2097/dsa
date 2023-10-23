
// //! 1 Generate all binary strings

// #include <iostream>
// using namespace std;

// void generateStringHelper(int N, string &str, int ind, vector<string> &ans) {

//     if (ind == N) {
//         // Terminate binary string and push it to the answer vector.
//         ans.push_back(str);

//         return;
//     }

//     // If the previous character is '1', then we put only '0' at the end of the string.
//     // For example, if str = "01", then the new string would be "010".
//     if (str[ind - 1] == '1') {
//         str[ind] = '0';
//         generateStringHelper(N, str, ind + 1, ans);
//     }

//     // If the previous character is '0', then we put both '1' and '0' at the end of the string.
//     // For example, if str = "00", then the new string would be "001" and "000".
//     if (str[ind - 1] == '0') {
//         str[ind] = '0';
//         generateStringHelper(N, str, ind + 1, ans);
//         str[ind] = '1';
//         generateStringHelper(N, str, ind + 1, ans);
//     }
// }

// vector<string> generateString(int N) {
//     vector<string> ans;
//     if (N == 0) {
//         return ans;
//     }
//     // Create a string with N elements.
//     string str(N, '0');

//     // First character is '0'.
//     str[0] = '0';

//     generateStringHelper(N, str, 1, ans);

//     // First character is '1'.
//     str[0] = '1';

//     generateStringHelper(N, str, 1, ans);
//     sort(ans.begin(), ans.end());

//     return ans;
// }

// int main(){
//     vector<string> ans=generateString(4);
//     for(auto str:ans){
//         cout<<str<<endl;
//     }
//     return 0;
// }
//
//
//
//
//

// //! 2 Generate all paranthesis

// #include <iostream>
// using namespace std;

// // Function to generate all the parentheses recursively.
// void generate(int total, int open, int close, string s, vector<string> &ans){

//     /*
//         If the string s contains total number of characters,
//         this means that s is a valid parenthesis.
//     */
//     if(s.size() == total){
//         ans.push_back(s);
//         return;
//     }

//     /*
//         If the count of open brackets is more than the count of
//         close brackets, we can give closing bracket at this position.
//     */
//     if(open > close){
//         generate(total, open, close + 1, s+')', ans);

//         /*
//             Again if the count of open brackets is less than
//             total / 2, we can give a opening bracket at this position.
//         */
//         if(open < total / 2){
//             generate(total, open+1, close, s+'(', ans);
//         }
//     }

//     /*
//         Else we can only give opening bracket at this index,
//         otherwise it will lead to an invalid parenthesis.
//     */
//     else{
//         generate(total, open+1, close, s+'(', ans);
//     }
// }

// vector<string> validParenthesis(int n){

//     // Total number of characters.
//     int total = 2 * n;

//     // Vector of string to store all the valid parentheses.
//     vector<string> ans;

//     /*
//         Calling the generating function to generate all the
//         valid parentheses. Count of opening bracket and closing
//         bracket will be zero and the string will be an empty string.
//     */
//     generate(total, 0, 0, "", ans);

//     return ans;

// }

// int main(){
//     vector<string> ans=validParenthesis(3);
//     for(auto str:ans){
//         cout<<str<<endl;
//     }
//     return 0;
// }
//
//
//
//
//

// //! 3 Power set [Bit manipulation]

// #include <iostream>
// using namespace std;
// vector<string> AllPossibleStrings(string s)
// {
//     int n = s.length();
//     vector<string> ans;
//     for (int num = 0; num < (1 << n); num++)
//     {
//         string sub = "";
//         for (int i = 0; i < n; i++)
//         {
//             // check if the ith bit is set or not
//             if (num & (1 << i))
//             {
//                 sub += s[i];
//             }
//         }
//         if (sub.length() > 0)
//         {
//             ans.push_back(sub);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     return ans;
// }
// int main()
// {
//     // int n=(7&(1<<0)); //*for concept check
//     // cout<<n;

//     string s = "abc";
//     vector<string> ans = AllPossibleStrings(s);
//     // printint all the subsequence.
//     cout << "All possible subsequences are " << endl;
//     for (auto it : ans)
//     {
//         cout << it << " ";
//     }
//     return 0;
// }
//
//
//
//
//

// //! 3 Power set [Using recursion{backtracking}]

// #include <iostream>
// using namespace std;
// void solve(int i, string s, string &f)
// {
//     if (i == s.length())
//     {

//         cout << f << " ";
//         return;
//     }
//     // picking
//     f = f + s[i];

//     solve(i + 1, s, f); //*when ele is taken
//     // poping out while backtracking
//     f.pop_back();

//     solve(i + 1, s, f); //*when ele is not taken
// }
// int main()
// {
//     string s = "abc";
//     string f = "";
//     cout << "All possible subsequences are: " << endl;
//     solve(0, s, f);
// }
//
//
//
//
//

// //! 4 Printing subsequences whose sum is k

// #include <iostream>
// using namespace std;

// void printSub(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//     if (ind == n)
//     {
//         if (s == sum)
//         {
//             for (auto a : ds)
//             {
//                 cout << a << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }
//     ds.push_back(arr[ind]);//*pick the element
//     s+=arr[ind];
//     printSub(ind+1, ds,s,sum, arr, n);//*pick condition
//     s-=arr[ind];
//     ds.pop_back();//*remove the picked element
//     printSub(ind+1, ds,s,sum, arr, n);//*not pick condition
// }

//     int main()
//     {
//         int arr[] = {1, 2, 1};
//         int n = 3;
//         int sum = 2;
//         vector<int> ds;
//         printSub(0, ds, 0, sum, arr, n);
//         return 0;
//     }
//
//
//
//
//

// //! 4 Printing ANY subsequences whose sum is k [not correct]

// #include <iostream>
// using namespace std;
// //*but use of global variables is discouraged for various reasons.
// bool flag=false;
// void printSub(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//     if (ind == n)
//     {
//         if (s == sum&&flag==false)
//         {
//             for (auto a : ds)
//             {   flag=true;
//                 cout << a << " ";
//             }
//             cout << endl;
//         }
//         return;
//     }
//     ds.push_back(arr[ind]);//*pick the element
//     s+=arr[ind];
//     printSub(ind+1, ds,s,sum, arr, n);//*pick condition
//     s-=arr[ind];
//     ds.pop_back();//*remove the picked element
//     printSub(ind+1, ds,s,sum, arr, n);//*not pick condition
// }

//     int main()
//     {
//         int arr[] = {1, 2, 1};
//         int n = 3;
//         int sum = 2;
//         vector<int> ds;
//         printSub(0, ds, 0, sum, arr, n);
//         return 0;
//     }
//
//
//
//
//
//
//
//
//
//

// // ! 4 Printing ANY subsequences whose sum is k [correct] or
// // ! 6 Check if there exists a subsequence with sum K

// #include <iostream>
// using namespace std;

// bool printSub(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//     if (ind == n)
//     { //*condition satisfied
//         if (s == sum)
//         {
//             for (auto a : ds)
//             {
//                 cout << a << " ";
//             }
//             cout << endl;
//             return true;
//         }
//         //*condition not satisfied
//         else
//             return false;
//     }
//     ds.push_back(arr[ind]);
//     s += arr[ind];

//     // pick
//     if (printSub(ind + 1, ds, s, sum, arr, n) == true)
//         return true;

//     s -= arr[ind];
//     ds.pop_back();

//     // not pick
//     if (printSub(ind + 1, ds, s, sum, arr, n) == true)
//         return true;
//     return false;
// }

// int main()
// {
//     int arr[] = {1, 2, 1};
//     int n = 3;
//     int sum = 2;
//     vector<int> ds;
//     printSub(0, ds, 0, sum, arr, n);//todo can store the bool value too but not needed
//     return 0;
// }
//
//
//
//
//

// //! 4 Count all subsequences with sum K
// //! 5 count all subsequences with sum K

// #include <iostream>
// using namespace std;

// int printSub(int ind, int s, int sum, int arr[], int n) //*no need for ds
// {   //*condition not satisfied
//     //*strictly done if arr contains positives only
//     if (s > sum)//*additional condition to decrease TC slightly(not neccessary to write)
//         return 0;
//     if (ind == n)
//     { //*condition satisfied
//         if (s == sum)
//         {
//             return 1;
//         }
//         //*condition not satisfied
//         else
//             return 0;
//     }
//     s += arr[ind];

//     // pick
//     int l = (printSub(ind + 1, s, sum, arr, n));

//     s -= arr[ind];

//     // not pick
//     int r = printSub(ind + 1, s, sum, arr, n);
//     return l + r;
// }

// int main()
// {
//     int arr[] = {1, 2, 1};
//     int n = 3;
//     int sum = 2;
//     int ans = printSub(0, 0, sum, arr, n);
//     cout << ans;
//     return 0;
// }
//
//
//
//
//

// //! 7 Combination Sum - 1

// #include <iostream>
// #include <vector>

// using namespace std;
// class Solution
// {
// public:
//     void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
//     {
//         if (ind == arr.size())
//         {
//             if (target == 0)
//             {
//                 ans.push_back(ds); //*adding data structure takes linear TC
//             }
//             return;
//         }
//         //*pick up the element and stay on the same index
//         if (arr[ind] <= target)
//         {
//             ds.push_back(arr[ind]);
//             findCombination(ind, target - arr[ind], arr, ans, ds);
//             ds.pop_back(); //*if we dont take this ele out it will still be in the ds
//         }

//         //*not picking the element and not stay on the same index
//         findCombination(ind + 1, target, arr, ans, ds);
//     }

// public:
//     vector<vector<int>> combinationSum(vector<int> &candidates, int target)
//     {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         findCombination(0, target, candidates, ans, ds);
//         return ans;
//     }
// };
// int main()
// {
//     Solution obj;

//     vector<int> v;
//     v.push_back(2);
//     v.push_back(3);
//     v.push_back(6);
//     v.push_back(7);
//     int target = 7;

//     vector<vector<int>> ans = obj.combinationSum(v, target);
//     cout << "Combinations are: " << endl;
//     for (int i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//             cout << ans[i][j] << " ";
//         cout << endl;
//     }
// }
//
//
//
//
//

// // ! 8 Combination Sum - 2

// #include <iostream>
// #include <vector>

// using namespace std;
// void findCombination(int ind, int target, vector < int > & arr, vector < vector < int > > & ans, vector < int > & ds) {
//   if (target == 0) {
//     ans.push_back(ds);
//     return;
//   }
//   for (int i = ind; i < arr.size(); i++) {
//     if (i > ind && arr[i] == arr[i - 1]) continue;//*(i>ind)means will ignore for starting index
//     if (arr[i] > target) break;//*instead can be written as (i!=ind) also
//     ds.push_back(arr[i]);
//     findCombination(i + 1, target - arr[i], arr, ans, ds);
//     ds.pop_back();
//   }
// }
// vector < vector < int > > combinationSum2(vector < int > & candidates, int target) {
//   sort(candidates.begin(), candidates.end());
//   vector < vector < int > > ans;
//   vector < int > ds;
//   findCombination(0, target, candidates, ans, ds);
//   return ans;
// }
// int main() {
//   vector<int> v;
//   v.push_back(10);
//   v.push_back(1);
//   v.push_back(2);
//   v.push_back(7);
//   v.push_back(6);
//   v.push_back(1);
//   v.push_back(5);
//   vector < vector < int > > comb = combinationSum2(v, 8);
//   cout << "[ ";
//   for (int i = 0; i < comb.size(); i++) {
//     cout << "[ ";
//     for (int j = 0; j < comb[i].size(); j++) {
//       cout << comb[i][j] << " ";
//     }
//     cout << "]";
//   }
//   cout << " ]";
// }
//
//
//
//
//

// //! 9 Subset Sum - 1 [Optimal Soln using recursion]

// #include<iostream>
// using namespace std;

// class Solution {
//   public:
//     void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
//       if (ind == n) {
//         ans.push_back(sum);
//         return;
//       }
//       //element is picked
//       subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
//       //element is not picked
//       subsetSumsHelper(ind + 1, arr, n, ans, sum);
//     }
//   vector < int > subsetSums(vector < int > arr, int n) {
//     vector < int > ans;
//     subsetSumsHelper(0, arr, n, ans, 0);
//     sort(ans.begin(), ans.end());
//     return ans;
//   }
// };

// int main() {
//   vector < int > arr;
//     arr.push_back(3);
//     arr.push_back(1);
//     arr.push_back(2);
//   Solution ob;
//   vector < int > ans = ob.subsetSums(arr, arr.size());
//   sort(ans.begin(), ans.end());
//   cout<<"The sum of each subset is "<<endl;
//   for (auto sum: ans) {
//     cout << sum << " ";
//   }
//   cout << endl;

//   return 0;
// }
//
//
//
//
//

// //! 10 Subset Sum - 2 (Brute force soln)

// #include<iostream>
// #include<set>
// #include<vector>
// using namespace std;

// void printAns(vector < vector < int > > & ans) {
//   cout << "The unique subsets are " << endl;
//   cout << "[ ";
//   for (int i = 0; i < ans.size(); i++) {
//     cout << "[ ";
//     for (int j = 0; j < ans[i].size(); j++)
//       cout << ans[i][j] << " ";
//     cout << "]";
//   }
//   cout << " ]";
// }
// class Solution {
//   public:
//     void fun(vector < int > & nums, int index, vector < int > ds, set < vector < int >  > & res) {
//       if (index == nums.size()) {
//         sort(ds.begin(), ds.end());
//         res.insert(ds);
//         return;
//       }
//       ds.push_back(nums[index]);
//       fun(nums, index + 1, ds, res);
//       ds.pop_back();
//       fun(nums, index + 1, ds, res);
//     }
//   vector < vector < int > > subsetsWithDup(vector < int > & nums) {
//     vector < vector < int > > ans;
//     set < vector < int > > res;
//     vector < int > ds;
//     fun(nums, 0, ds, res);
//     for (auto it = res.begin(); it != res.end(); it++) {
//       ans.push_back( * it);
//     }
//     return ans;
//   }
// };
// int main() {
//   Solution obj;
//   vector < int > nums;
//   nums.push_back(1);
//   nums.push_back(2);
//   nums.push_back(2);
//   vector < vector < int > > ans = obj.subsetsWithDup(nums);
//   printAns(ans);
//   return 0;
// }
//
//
//
//
//

// //! 10 Subset Sum - 2 (Optimal soln)

// #include <iostream>
// using namespace std;
// void printAns(vector<vector<int> > &ans)
// {
//     cout << "The unique subsets are " << endl;
//     cout << "[ ";
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << "[ ";
//         for (int j = 0; j < ans[i].size(); j++)
//             cout << ans[i][j] << " ";
//         cout << "]";
//     }
//     cout << " ]";
// }
// class Solution
// {
// private:
//     void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int> > &ans)
//     {//*no base case as the loop runs for the size of vector only.
//         ans.push_back(ds); //*O(n)for copying subset we are generating
//         for (int i = ind; i < nums.size(); i++)
//         {
//             if (i != ind && nums[i] == nums[i - 1])
//                 continue;
//             ds.push_back(nums[i]);
//             findSubsets(i + 1, nums, ds, ans);
//             ds.pop_back(); //*as for next recursion call we dont want the added element
//         }                  //*to be kept in the ds
//     }

// public:
//     vector<vector<int> > subsetsWithDup(vector<int> &nums)
//     {
//         vector<vector<int> > ans; // will be the ultimate answer
//         vector<int> ds;
//         sort(nums.begin(), nums.end()); //*as our method works only on sorted array
//         findSubsets(0, nums, ds, ans);
//         return ans;
//     }
// };
// int main()
// {
//     Solution obj;
//     vector<int> nums;
//     nums.push_back(1);
//     nums.push_back(2);
//     nums.push_back(2);
//     vector<vector<int> > ans = obj.subsetsWithDup(nums);
//     printAns(ans);
//     return 0;
// }
//
//
//
//
//

// // //! 11 Combination sum - 3 


// /*We can do a recursive solution where we will add an element in the combination greater than we 
// add in the last operation in this way will not create a similar combination again also we won’t
//  use the same element twice and in each will add an element if the total sum is <= n if the number
//  of elements in the combination is equal to k and sum is equal to n we will add to ‘ans’ matrix.
//   We will return this matrix after the end of the recursion.*/

// #include <iostream>
// using namespace std;

// // Helper function to create combination.
// void create(int i, int k, int n, vector < int > & temp, vector < vector < int > > & ans, int last) {

//     // If we have reached the last element then we can not add any more elements so check.
//     // The sum of elements in temp is equal to ‘n’ or not.
//     // If it is then add it to the answer.
//     if (i == k) {
//         if (n == 0) {
//             ans.push_back(temp);
//         }
//     }

//     // We can use every element once only so we will use the element greater than the previous elements.
//     // So for 'curr' in range [last+1, 9]
//     for (int curr = last + 1; curr < 10; curr++) {

//         // If 'curr' is greater than ‘n’ then we can not add it to 'temp'.
//         if (n - curr < 0) {
//             break;
//         }

//         // Add the current element to 'temp' and call the create function with n-curr.
//         temp.push_back(curr);
//         create(i + 1, k, n - curr, temp, ans, curr);

//         // Backtrack.
//         temp.pop_back();
//     }
// }

// vector < vector < int > > combinationSum(int k, int n) {

//     // Declare a 'ans' Matrix to store answers and one temporary array 'temp'.
//     vector < vector < int > > ans;
//     vector < int > temp;

//     // Call the create function with initial i= 0 as there is no element in temp.
//     // 'n' is initially 'n' as there is no element in temp.
//     // 'ans' is initially empty.
//     // The last element initially we take as 0 as we can take numbers between [1, 9].
//     // And in each case, We check from 'last'+1.
//     create(0, k, n, temp, ans, 0);

//     // Return 'ans'.
//     return ans;
// }

// int main(){
//     vector<vector<int> > ans2= combinationSum(3,7);
//     for(auto it:ans2){
//         for(auto it2:it){
//             cout<<it2<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }
//
//
//
//
//

// //! 12 Letter combinations of a phone number

// #include <iostream>
// #include<vector>
// using namespace std;

// // Function to recursively generate letter combinations.
// void generateCombinations(string& digits, int index, string& combination, vector<string>& mapping, vector<string>& result) {
//     // Base case: If we have processed all digits, add the current combination to the result.
//     if (index == digits.length()) {
//         result.push_back(combination);
//         return;
//     }

//     // Get the letters corresponding to the current digit.
//     string letters = mapping[digits[index] - '0'];

//     // Iterate over the letters and generate combinations.
//     for (char letter : letters) {
//         combination += letter;
//         generateCombinations(digits, index + 1, combination , mapping, result);
//         combination.pop_back();
//     }
// }

// // Function to generate letter combinations from digits.
// vector<string> letterCombinations(string digits) {
//     // Mapping of digits to letters.
//   vector<string> mapping ;
//     mapping.push_back("0");
//     mapping.push_back("1");
//     mapping.push_back("abc");
//     mapping.push_back("def");
//     mapping.push_back("ghi");
//     mapping.push_back("jkl");
//     mapping.push_back("mno");
//     mapping.push_back("pqrs");
//     mapping.push_back("tuv");
//     mapping.push_back("wxyz");
//     // Result vector to store the generated combinations.
//     vector<string> result;
//     string combination;

//     // Call the recursive function to generate combinations.
//     generateCombinations(digits, 0, combination, mapping, result);

//     // Return the result vector containing the generated combinations.
//     return result;
// }

// int main(){
//     vector<string> ans=letterCombinations("23");
//     for(auto it:ans){
//         cout<<it<<endl;
//     }
//     return 0;
// }
//
//
//
//
//