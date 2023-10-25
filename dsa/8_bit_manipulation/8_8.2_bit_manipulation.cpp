
// //! 1 Count no. of bits to be flipped to convert A to B

// #include <iostream>
// using namespace std;

// int flipBits(int A, int B){
    
//     // Compute the bitwise XOR of the two input integers 'A' and 'B', and store the result in a new integer variable 'k'. 
//     int k=A^B;
    
//     int count=0;
    
//     // Use a while loop to iterate over all the bits in 'k'.
//     while(k){

//         // Use the bitwise AND operator (&) with 1 to check the least significant bit of 'k'.
//         int bit=k&1;

//         // If the least significant bit is 1, increment the counter 'count' to track the number of bits that need to be flipped.
//         if(bit)count++;

//         // Right shift 'k' by 1 bit to move to the next bit position.
//         k=k>>1;
//     }
    
//     // After all bit positions have been checked, return the value of 'count'.
//     return count;
// }


// int main(){
//     int count =flipBits(7,12);
//     cout<<count<<endl;
//     return 0;
// }
//
//
//
//
//

// //! 2 Power set

// #include<iostream>
// using namespace std;
// vector<string> AllPossibleStrings(string s) {
// 	int n = s.length();
// 	vector<string>ans;
// 	for (int num = 0; num < (1 << n); num++) {
// 		string sub = "";
// 		for (int i = 0; i < n; i++) {
// 			//check if the ith bit is set or not
// 			if (num & (1 << i)) {
// 				sub += s[i];
// 			}
// 		}
// 		if (sub.length() > 0) {
// 			ans.push_back(sub);
// 		}
// 	}
// 	sort(ans.begin(), ans.end());
// 	return ans;
// }
// int main()
// {

// 	string s="abc";
// 	vector<string>ans = AllPossibleStrings(s);
// 	//printint all the subsequence.
// 	cout<<"All possible subsequences are "<<endl;
// 	for (auto it : ans) {
// 		cout << it << " ";
// 	}

// }
//
//
//
//
//

// //! 3 Optimal solution

// #include <iostream>
// #include <vector>
// using namespace std;

// std::pair<int, int> findUniqueNumbers(const std::vector<int>& arr) {
//     int XOR = 0;

//     // XOR all elements in the array
//     for (int num : arr) {
//         XOR ^= num;
//     }

//     // Find a set bit in the XOR result
//     int setBit = 1;
//     while ((setBit & XOR) == 0) {
//         setBit <<= 1;
//     }

//     int unique1 = 0, unique2 = 0;

//     // Traverse the array and XOR elements based on the set bit
//     for (int num : arr) {
//         if (num & setBit) {
//             unique1 ^= num;
//         } else {
//             unique2 ^= num;
//         }
//     }

//     return std::make_pair(unique1, unique2);
// }

// int main() {
//     std::vector<int> arr; // Two unique numbers are 5 and 7
//     arr.push_back(2);
//     arr.push_back(3);
//     arr.push_back(4);
//     arr.push_back(3);
//     arr.push_back(4);
//     arr.push_back(5);
//     arr.push_back(6);
//     arr.push_back(6);
//     arr.push_back(2);
//     arr.push_back(7);

//     std::pair<int, int> uniqueNumbers = findUniqueNumbers(arr);

//     std::cout << "Unique Numbers: " << uniqueNumbers.first << " and " << uniqueNumbers.second << std::endl;

//     return 0;
// }
//
//
//
//
//