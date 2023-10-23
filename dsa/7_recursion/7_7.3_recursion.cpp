
// //! 1 palindrome partitioning

// #include<iostream>
// using namespace std;

// class Solution {
//   public:
//     vector < vector < string > > partition(string s) {
//       vector < vector < string > > res;
//       vector < string > path;
//       partitionHelper(0, s, path, res);
//       return res;
//     }

//   void partitionHelper(int index, string s, vector < string > & path,
//     vector < vector < string > > & res) {
//     if (index == s.size()) {
//       res.push_back(path);
//       return;
//     }
//     for (int i = index; i < s.size(); ++i) {
//         //check for palindrome for (from index to i)
//       if (isPalindrome(s, index, i)) {
//         path.push_back(s.substr(index, i - index + 1));
//         partitionHelper(i + 1, s, path, res);
//         path.pop_back();
//       }
//     }
//   }

//   bool isPalindrome(string s, int start, int end) {
//     while (start <= end) {
//       if (s[start++] != s[end--])
//         return false;
//     }
//     return true;
//   }
// };
// int main() {
//   string s = "aabb";
//   Solution obj;
//   vector < vector < string > > ans = obj.partition(s);
//   int n = ans.size();
//   cout << "The Palindromic partitions are :-" << endl;
//   cout << " [ ";
//   for (auto i: ans) {
//     cout << "[ ";
//     for (auto j: i) {
//       cout << j << " ";
//     }
//     cout << "] ";
//   }
//   cout << "]";

//   return 0;
// }
//
//
//
//
//

// //! 2 word search

// /*Approach:  We are going to solve this by using backtracking, in this approach first
// we will linearly search the entire matrix to find the first letters matching our given
// string. If we found those letters then we can start backtracking in all four directions
//  to find the rest of the letters of the given string.

// Step 1: Find the first character of the given string.

// Step 2: Start Backtracking in all four directions until we find all the letters of
//          sequentially adjacent cells.

// Step 3: At the end, If we found our result then return true else return false.

// Edge cases: Now think about what will be our stopping condition, we can stop or return
//         false if we reach the end of the boundaries of the matrix OR the letter at which
//         we are making recursive calls is not the required letter.

// We will also return if we found all the letters of the given word i.e. we found the number
// of letters equal to the length of the given word.

// NOTE: Do not forget that we cannot reuse a cell again.

// That is, we have to somehow keep track of our position so that we cannot find the same
// letter again and again.

// In this approach, we are going to mark visited cells with some random character that will
// prevent us from revisiting them again and again.

// */

// #include<iostream>
// using namespace std;

//     bool searchNext(vector<vector<char> > &board, string word, int row, int col,
//     int index, int m, int n) {

//         // if index reaches at the end that means we have found the word
//         if (index == word.length())
//             return true;

//         // Checking the boundaries if the character at which we are placed is not
//         //the required character
//         if (row < 0 || col < 0 || row == m || col == n || board[row][col] !=
//         word[index] || board[row][col] == '!')
//             return false;

//         // this is to prevent reusing of the same character
//         char c = board[row][col];
//         board[row][col] = '!';

//         // top direction
//         bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
//         // right direction
//         bool right = searchNext(board, word, row, col + 1, index + 1, m, n);
//         // bottom direction
//         bool bottom = searchNext(board, word, row + 1, col, index + 1, m, n);
//         // left direction
//         bool left = searchNext(board, word, row, col - 1, index + 1, m, n);

//         board[row][col] = c; // undo change

//         return top || right || bottom || left;
//     }
//     bool exist(vector<vector<char> > board, string word) {

//         int m = board.size();//no. of rows
//         int n = board[0].size();//no. of columns

//         int index = 0;

//         // First search the first character
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {

//                 if (board[i][j] == word[index]) {
//                     if (searchNext(board, word, i, j, index, m, n))
//                         return true;
//                 }
//             }
//         }

//         return false;
//     }

//     int main() {
//         vector<vector<char> > board(3);

//         board[0].push_back('A');
//         board[0].push_back('B');
//         board[0].push_back('C');
//         board[0].push_back('E');
//         board[1].push_back('S');
//         board[1].push_back('F');
//         board[1].push_back('C');
//         board[1].push_back('S');
//         board[2].push_back('A');
//         board[2].push_back('D');
//         board[2].push_back('E');
//         board[2].push_back('E');

//         string word = "ABCCED";

//         bool res = exist(board, word);
//         if(res==1)
//         cout<<"True"<<endl;
//         else
//         cout<<"False"<<endl;
//     }
//
//
//
//
//

// //! 3 N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle

// #include<iostream>

// using namespace std;
// class Solution {
//   public:
//     bool isSafe1(int row, int col, vector < string > board, int n) {
//       // check upper diagonal
//       int duprow = row;
//       int dupcol = col;

//       while (row >= 0 && col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         row--;
//         col--;
//       }

//     //check left side
//       col = dupcol;
//       row = duprow;
//       while (col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         col--;
//       }

//     //check for lower diagonal
//       row = duprow;
//       col = dupcol;
//       while (row < n && col >= 0) {
//         if (board[row][col] == 'Q')
//           return false;
//         row++;
//         col--;
//       }
//       return true;//if did not find any queen
//     }

//   public:
//     void solve(int col, vector < string > & board, vector < vector < string > > & ans, int n) {
//       if (col == n) {                   //base case//if a combination reaches till 'n' that means it
//         ans.push_back(board);   //follows all below condition and then it returns (after pushing )and
//         return;     //it omits the Q with '.' and again try for different combinations
//       }
//       for (int row = 0; row < n; row++) {       //try every row for every col
//         if (isSafe1(row, col, board, n)) {      //check if its is safe to put Q here(in the row)
//           board[row][col] = 'Q';                //if it is safe put the Q
//           solve(col + 1, board, ans, n);        //then move to the next col

//           board[row][col] = '.';                //this condition is after coming back from recursion:
//                                     //remove the Q so that i can try for the next row in the SAME column
//         }                           //(this is backtracking ie. If you encounter a
//         //situation where you realize that the current path will not lead to a solution (e.g., a
//         //constraint violation), you undo the most recent choice (backtrack) and explore
//         //alternative choices.)
//       }
//     }

//   public:
//     vector < vector < string > > solveNQueens(int n) {
//       vector < vector < string > > ans;
//       vector < string > board(n);
//       string s(n, '.');
//       for (int i = 0; i < n; i++) {
//         board[i] = s;
//       }
//       solve(0, board, ans, n);
//       return ans;
//     }
// };
// int main() {
//   int n = 4; // we are taking 4*4 grid and 4 queens
//   Solution obj;
//   vector < vector < string > > ans = obj.solveNQueens(n);
//   for (int i = 0; i < ans.size(); i++) {
//     cout << "Arrangement " << i + 1 << "\n";
//     for (int j = 0; j < ans[0].size(); j++) {
//       cout << ans[i][j];
//       cout << endl;
//     }
//     cout << endl;
//   }
//   return 0;
// }
//
//
//
//
//

// /*Hashing is a technique or a general concept used in computer science, and it's not limited to a
// single function or data structure. It's a method of converting data (usually a key or value) into a
//  fixed-size hash code, often represented as a numerical value or a string of characters.*/

// //! 3 N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle [optimised]

// #include<iostream>

// using namespace std;
// class Solution {
//   public:
//     void solve(int col, vector < string > & board, vector < vector < string > > & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
//       if (col == n) {
//         ans.push_back(board);
//         return;
//       }
//       for (int row = 0; row < n; row++) {
//         if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
//           board[row][col] = 'Q';
//           leftrow[row] = 1;     //mark the hashes
//           lowerDiagonal[row + col] = 1;
//           upperDiagonal[n - 1 + col - row] = 1;
//           solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);

//           board[row][col] = '.';//remove the Q so that i can try for the next row in the SAME column

//           leftrow[row] = 0;     //but now we have to make sure that the hashes are unmarked too
//           lowerDiagonal[row + col] = 0; //so that it does not find 'Q' there for the next row in the
//           upperDiagonal[n - 1 + col - row] = 0;     //SAME column
//         }
//       }
//     }

//   public:
//     vector < vector < string > > solveNQueens(int n) {
//       vector < vector < string > > ans;
//       vector < string > board(n);
//       string s(n, '.');
//       for (int i = 0; i < n; i++) {
//         board[i] = s;
//       }
//       vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
//       solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
//       return ans;
//     }
// };
// int main() {
//   int n = 4; // we are taking 4*4 grid and 4 queens
//   Solution obj;
//   vector < vector < string > > ans = obj.solveNQueens(n);
//   for (int i = 0; i < ans.size(); i++) {
//     cout << "Arrangement " << i + 1 << "\n";
//     for (int j = 0; j < ans[0].size(); j++) {
//       cout << ans[i][j];
//       cout << endl;
//     }
//     cout << endl;
//   }
//   return 0;
// }
//
//
//
//
//

// //! 4 Rat in a maze

// #include<iostream>

// using namespace std;

// class Solution {
//   void findPathHelper(int i, int j, vector < vector < int > > & a, int n, vector < string > & ans, string move,
//     vector < vector < int > > & vis) {
//     if (i == n - 1 && j == n - 1) {
//       ans.push_back(move);
//       return;
//     }

//     // downward
//     if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
//       vis[i][j] = 1;
//       findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
//       vis[i][j] = 0;
//     }

//     // left
//     if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
//       vis[i][j] = 1;//mark it
//       findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
//       vis[i][j] = 0;//unmark it
//     }

//     // right
//     if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
//       vis[i][j] = 1;
//       findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
//       vis[i][j] = 0;
//     }

//     // upward
//     if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
//       vis[i][j] = 1;
//       findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
//       vis[i][j] = 0;
//     }

//   }
//   public:
//     vector < string > findPath(vector < vector < int > > & m, int n) {
//       vector < string > ans;
//       vector < vector < int > > vis(n, vector < int > (n, 0));

//       if (m[0][0] == 1) findPathHelper(0, 0, m, n, ans, "", vis);//==1 because needed to start the path
//       return ans;
//     }
// };

// int main() {
//   int n = 4;

//    vector < vector < int > > m(4);
//     m[0].push_back(1);
//     m[0].push_back(0);
//     m[0].push_back(0);
//     m[0].push_back(0);
//     m[1].push_back(1);
//     m[1].push_back(1);
//     m[1].push_back(0);
//     m[1].push_back(1);
//     m[2].push_back(1);
//     m[2].push_back(1);
//     m[2].push_back(0);
//     m[2].push_back(0);
//     m[3].push_back(0);
//     m[3].push_back(1);
//     m[3].push_back(1);
//     m[3].push_back(1);
//   Solution obj;
//   vector < string > result = obj.findPath(m, n);
//   if (result.size() == 0)
//     cout << -1;
//   else
//     for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
//   cout << endl;

//   return 0;
// }
//
//
//
//
//

// //! 4 Rat in a maze [But, writing an individual code for every direction is a lengthy process therefore
//       //! we truncate the 4 “if statements” into a single for loop using the following approach.]

// #include<iostream>

// using namespace std;

// class Solution {
//   void solve(int i, int j, vector < vector < int > > & a, int n, vector < string > & ans, string move,
//     vector < vector < int > > & vis, int di[], int dj[]) {
//     if (i == n - 1 && j == n - 1) {
//       ans.push_back(move);
//       return;
//     }
//     string dir = "DLRU";
//     for (int ind = 0; ind < 4; ind++) {
//       int nexti = i + di[ind];
//       int nextj = j + dj[ind];
//       if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
//         vis[i][j] = 1;
//         solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
//         vis[i][j] = 0;
//       }
//     }

//   }
//   public:
//     vector < string > findPath(vector < vector < int > > & m, int n) {
//       vector < string > ans;
//       vector < vector < int > > vis(n, vector < int > (n, 0));
//       int di[] = {
//         +1,
//         0,
//         0,
//         -1
//       };
//       int dj[] = {
//         0,
//         -1,
//         1,
//         0
//       };
//       if (m[0][0] == 1) solve(0, 0, m, n, ans, "", vis, di, dj);
//       return ans;
//     }
// };

// int main() {
//   int n = 4;

//    vector < vector < int > > m(4);
//     m[0].push_back(1);
//     m[0].push_back(0);
//     m[0].push_back(0);
//     m[0].push_back(0);
//     m[1].push_back(1);
//     m[1].push_back(1);
//     m[1].push_back(0);
//     m[1].push_back(1);
//     m[2].push_back(1);
//     m[2].push_back(1);
//     m[2].push_back(0);
//     m[2].push_back(0);
//     m[3].push_back(0);
//     m[3].push_back(1);
//     m[3].push_back(1);
//     m[3].push_back(1);

//   Solution obj;
//   vector < string > result = obj.findPath(m, n);
//   if (result.size() == 0)
//     cout << -1;
//   else
//     for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
//   cout << endl;

//   return 0;
// }

// //! 5 Word Break

// // A recursive program to print all possible
// // partitions of a given string into dictionary
// // words
// #include <iostream>
// using namespace std;

// /* A utility function to check whether a word
// is present in dictionary or not. An array of
// strings is used for dictionary. Using array
// of strings for dictionary is definitely not
// a good idea. We have used for simplicity of
// the program*/
// int dictionaryContains(string &word)
// {
// 	string dictionary[] = {"mobile","samsung","sam","sung",
// 							"man","mango", "icecream","and",
// 							"go","i","love","ice","cream"};
// 	int n = sizeof(dictionary)/sizeof(dictionary[0]);
// 	for (int i = 0; i < n; i++)
// 		if (dictionary[i].compare(word) == 0)
// 			return true;
// 	return false;
// }

// // Prototype of wordBreakUtil
// void wordBreakUtil(string str, int size, string result);

// // Prints all possible word breaks of given string
// void wordBreak(string str)
// {
// 	// Last argument is prefix
// 	wordBreakUtil(str, str.size(), "");
// }

// // Result store the current prefix with spaces
// // between words
// void wordBreakUtil(string str, int n, string result)
// {
// 	//Process all prefixes one by one
// 	for (int i=1; i<=n; i++)
// 	{
// 		// Extract substring from 0 to i in prefix
// 		string prefix = str.substr(0, i);

// 		// If dictionary contains this prefix, then
// 		// we check for remaining string. Otherwise
// 		// we ignore this prefix (there is no else for
// 		// this if) and try next
// 		if (dictionaryContains(prefix))
// 		{
// 			// If no more elements are there, print it
// 			if (i == n)
// 			{
// 				// Add this element to previous prefix
// 				result += prefix;
// 				cout << result << endl;
// 				return;
// 			}
// 			wordBreakUtil(str.substr(i, n-i), n-i,
// 								result + prefix + " ");
// 		}
// 	}
// }

// //Driver Code
// int main()
// {

// 	// Function call
// 	cout << "First Test:\n";
// 	wordBreak("iloveicecreamandmango");

// 	cout << "\nSecond Test:\n";
// 	wordBreak("ilovesamsungmobile");
// 	return 0;
// }
//
//
//
//
//

// //! 6 M-Coloring problem

// #include <iostream>
// using namespace std;
// //isSafe takes "col" which is the colour i am trying to do to this node
// bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
// {
//     for (int k = 0; k < n; k++)
//     {
//         if (k != node && graph[k][node] == 1 && color[k] == col)//means if it is a
//         {           //adjacent node with the same colour then return false
//             return false;
//         }
//     }
//     return true;//if none having same colour return true
// }
// bool solve(int node, int color[], int m, int N, bool graph[101][101])
// {
//     if (node == N)
//     {
//         return true;
//     }

//     for (int i = 1; i <= m; i++)//try every colour from 1 to m
//     {
//         if (isSafe(node, color, graph, N, i))
//         {
//             color[node] = i;
//             if (solve(node + 1, color, m, N, graph))
//                 return true;
//             color[node] = 0;//removing colour i did at 616 line no.
//         }
//     }
//     return false;//if not possible to colour it with any of the m colours then return false
// }

// // Function to determine if graph can be coloured with at most M colours such
// // that no two adjacent vertices of graph are coloured with same colour.
// bool graphColoring(bool graph[101][101], int m, int N)
// {   /*The error you're encountering is because you're trying to initialize an array
//  with a size determined by a variable (N) at compile time. In C++, arrays with a size
//  determined at runtime should be allocated using dynamic memory allocation (e.g., new
//  or malloc), or you can use a std::vector which is a dynamic array.*/

//     // int color[N] = {
//     //     0};
//     int color[4] = {
//         0};
//     if (solve(0, color, m, N, graph))
//         return true;
//     return false;
// }

// int main()
// {
//     int N = 4;
//     int m = 3;

//     bool graph[101][101];
//     memset(graph, false, sizeof graph);

//     // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
//     graph[0][1] = 1;/* This line sets the element in the adjacency matrix at row 0 and
//     column 1 to 1, indicating there is an edge from vertex 0 to vertex 1.*/
//     graph[1][0] = 1;
//     graph[1][2] = 1;
//     graph[2][1] = 1;
//     graph[2][3] = 1;
//     graph[3][2] = 1;
//     graph[3][0] = 1;
//     graph[0][3] = 1;
//     graph[0][2] = 1;
//     graph[2][0] = 1;

//     cout << graphColoring(graph, m, N);
// }
//
//
//
//
//

// //! 7 Sudoku Solver

// #include <iostream>
// #include <vector>

// using namespace std;

// bool isValid(vector<vector<char> > &board, int row, int col, char c)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         // for row
//         if (board[i][col] == c)
//             return false;
//         // for column
//         if (board[row][i] == c)
//             return false;
//         // for submatrix
//         if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
//             return false;
//     }
//     return true;
// }

// bool solveSudoku(vector<vector<char> > &board)
// {
//     for (int i = 0; i < board.size(); i++)
//     {
//         for (int j = 0; j < board[0].size(); j++)
//         {
//             if (board[i][j] == '.')
//             {
//                 for (char c = '1'; c <= '9'; c++)
//                 {
//                     if (isValid(board, i, j, c))
//                     {
//                         board[i][j] = c;

//                         if (solveSudoku(board))
//                             return true; //*when encounter true just return "true" dont go ahead and check for others
//                         else
//                             board[i][j] = '.';
//                     }
//                 }

//                 return false;
//             }
//         }
//     }
//     return true; //*if not found any remaining empty place then return true as sudoku is solved!!
// }
// int main()
// {
//     vector<vector<char> > board(9, vector<char>(9, '.')); // Initialize a 9x9 board with '.' initially

//     board[0][0] = '9';
//     board[0][1] = '.';
//     board[0][2] = '7';
//     board[0][4] = '1';
//     board[0][5] = '3';
//     board[0][7] = '8';
//     board[0][8] = '.';

//     board[1][0] = '4';
//     board[1][1] = '8';
//     board[1][2] = '3';
//     board[1][4] = '5';
//     board[1][5] = '7';
//     board[1][6] = '1';
//     board[1][8] = '6';

//     board[2][1] = '1';
//     board[2][2] = '2';
//     board[2][4] = '4';
//     board[2][5] = '9';
//     board[2][6] = '5';
//     board[2][7] = '3';
//     board[2][8] = '7';

//     board[3][0] = '1';
//     board[3][1] = '7';
//     board[3][3] = '3';
//     board[3][5] = '4';
//     board[3][6] = '9';
//     board[3][8] = '2';

//     // Fill in the rest of the elements similarly.

//     solveSudoku(board);

//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             cout << board[i][j] << " ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }
//
//
//
//
//

// //! 8 Expression Add Operators

// #include <iostream>
// #include <vector>

// using namespace std;

// class Solution {	/*1. Numbers ke beech mein operators dalna hain +,-,*.
//    	2. Teeno ko baari baari se try karna hain jisse target achieve ho to backtracking use karenge hi.
//    	3. Ab isme dhyan rakhna hain ki koi 
//    	- leading 0 na ho 
//    	- BODMAS rules are followed
//    	4. Subtraction and Addition rules to aasani se follow ho jayenge
//    	5. Multiplication mein hame previous operation ko hatana padega jaise agar prev operation sum that to vo operation hatake multiplication dalenge.
//    	6. First index pe hain to aage bad jayenge 
//    	7. Recursive Calls mein we will keep track of index in num,sumPath,sum,prev.*/

// //==============================================================================================================================
//     public:
//         void recursiveCall(int i, string sumPath, long sum, long prev, string num, int target, vector<string> &result)
//         {
//            	// If we have reached the end of 'num'
//             if (i == num.size())
//             {
//                 if (sum == target)
//                 {
//                    	// If the target is achieved, add the path to the result
//                     result.push_back(sumPath);
//                 }
//                 return;
//             }

//             for (int j = i; j < num.size(); j++)
//             {
//                 if (j > i && num[i] == '0')
//                 {
//                    	// Avoid leading zeros in the number
//                     break;
//                 }

//                 long number = stol(num.substr(i, j - i + 1));
//                	// Convert the substring to a long number
//                 string tempPath = num.substr(i, j - i + 1);
//                	// Temporary substring representing the path we have traversed so far

//                 if (i == 0)
//                 {
//                    	// If we are on the first index of 'num', start a new path
//                     recursiveCall(j + 1, tempPath, number, number, num, target, result);
//                 }
//                 else
//                 {
//                    	// Addition operation
//                     recursiveCall(j + 1, sumPath + '+' + tempPath, sum + number, number, num, target, result);
//                    	// Subtraction operation
//                     recursiveCall(j + 1, sumPath + '-' + tempPath, sum - number, -number, num, target, result);
//                    	// Multiplication operation
//                     recursiveCall(j + 1, sumPath + '*' + tempPath, sum - prev + (prev *number), prev *number, num, target, result);
//                    	// While doing the multiplication operation, we remove the previous operation and update it with the multiplication operation
//                    	// This is done to follow the BODMAS rules for correct precedence
//                 }
//         }
//     }

//     vector<string> addOperators(string num, int target) {
//        vector<string> result;
//         recursiveCall(0, "", 0, 0, num, target, result);
//     //recursiveCall(CurrentIndex,Path,sum,prev,num,target,result)
//         return result;
//     }
// };

// int main() {
//     Solution solution;
//     string num = "123";
//     int target = 6;

//     vector<string> result = solution.addOperators(num, target);

//     cout << "Possible expressions that evaluate to " << target << " are:" << endl;
//     for (const string &expression : result) {
//         cout << expression << endl;
//     }

//     return 0;
// }
//
//
//
//
//
