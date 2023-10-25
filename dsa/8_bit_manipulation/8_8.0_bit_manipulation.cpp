
// //! 1 Optimal solution

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

// //! 3 Petr and a combination lock [using power set by bit manipulation]

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     std::cin >> n;

//     std::vector<int> arr(n);

//     // Read the n numbers from the input
//     for (int i = 0; i < n; i++) {
//         std::cin >> arr[i];
//     }

//     int flag=0;
//     // Iterate for using the power set
//     for (int num = 0; num < (1 << n); num++){
//         int sum=0;
//         for (int i = 0; i < n; i++) {
//             if (num & (1 << i)){
//                 // '1' is for '+'
//                 sum+=arr[i];}
//             else {
//                 sum-=arr[i];}

//         if (sum%360==0) {flag=1;break;}
//         }

//     }
//     cout<<flag;

//     return 0;
// }
//
//
//
//
//

// //! 4 Product of three numbers [Optimal soln]

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int a = 1, b = INT_MAX, c = 1;
//     for (int i = 2; i * i <= n; i++)
//     { // for determining factors excluding 1
//         if (n % i == 0)
//         {
//             a = i; // did not consider 'n/i' as if we get 'i' that will be the smallest factor
//             break;
//         }
//     }
//     // n = n / a; // dont remove 'a' from 'n' right now

//     for (int i = 2; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             if (i != a)
//             {
//                 b = min(b, i);
//             }
//             if ((n / i) != i)//as 'n/i' also is a possibility
//             {
//                 if ((n / i) != a)
//                 {
//                     b = min(b, n / i);
//                 }
//             }
//         }
//     }
//     c = (n / a)/b;

//     if (a != b && b != c && c != 1)
//     {   cout<<a<<" "<<b<<" "<<c;
//         cout << "Yes";
//     }
//     else
//         cout << "No";
//     return 0;
// }
//
//
//
//
//

// // ! 5 Check for Prime

// #include <iostream>
// using namespace std;

// bool checkPrime(int n){
//     int cnt=0;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0){
//             cnt++;
//             if((n/i)!=i){
//                 cnt++;
//             }
//         }
//     }

//     if(cnt==2)return true;//can write 0 or 1 too 
//     else return false; 
// }

// int main(){
//     int t;//no. of test cases
//     cin>>t;
//     while(t--){
//         int n;//values of number to be checked for prime
//         cin>>n;
//         if (checkPrime(n)){
//             cout<<"Yes";
//         }
//         else cout<<"No";
//     }
//     return 0;
// }
//
//
//
//
//

// //! 6 Sieve of Eratosthenes {NOT Working Sieve}

// #include <iostream>
// using namespace std;

// bool checkPrime(int n){
//     int cnt=0;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0){
//             cnt++;
//             if((n/i)!=i){
//                 cnt++;
//             }
//         }
//     }

//     if(cnt==2)return true;//can write 0 or 1 too 
//     else return false; 
// }
// //todo
// int N=1000000;
// bool sieve[1000001];
// void createSieve(){
//     for(int i=2;i<=N;i++){//make everyone as 'true' except '0' and '1'
//         sieve[i]=true;
//     }

//     for(int i=2;i<=N;i++){
//         if(sieve[i]==true){             //(j=i*2) as for 5 ,10 ie 5*2 is the first multiple and similarly for all .
//             for(int j=i*2;j<=N;j+=i){ //(j+=i) as 'j' will increase by the no. itself
//                 sieve[j]=false;
//             }
//         }
//     }
// }

// int main(){
//     int t;//no. of test cases
//     cin>>t;
//     while(t--){
//         int n;//values of number to be checked for prime
//         cin>>n;
//         if (checkPrime(n)){
//             cout<<"Yes";
//         }
//         else cout<<"No";
//     }
//     return 0;
// }
//
//
//
//
//

// //! 7 Sieve of Eratosthenes [First Optimisation]{NOT Working Sieve}

// #include <iostream>
// using namespace std;

// bool checkPrime(int n){
//     int cnt=0;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0){
//             cnt++;
//             if((n/i)!=i){
//                 cnt++;
//             }
//         }
//     }

//     if(cnt==2)return true;//can write 0 or 1 too 
//     else return false; 
// }

// int N=1000000;
// bool sieve[1000001];
// void createSieve(){
//     for(int i=2;i<=N;i++){//make everyone as 'true' except '0' and '1'
//         sieve[i]=true;
//     }

//     for(int i=2;i<=N;i++){
//         if(sieve[i]==true){             //(j=i*2) as for 5 ,10 ie 5*2 is the first multiple and similarly for all .
//             for(int j=i*i;j<=N;j+=i){ //(j+=i) as 'j' will increase by the no. itself
//                 sieve[j]=false;
//             }
//         }
//     }
// }

// int main(){
//     int t;//no. of test cases
//     cin>>t;
//     while(t--){
//         int n;//values of number to be checked for prime
//         cin>>n;
//         if (checkPrime(n)){
//             cout<<"Yes";
//         }
//         else cout<<"No";
//     }
//     return 0;
// }
//
//
//
//
//

// //! 8 Sieve of Eratosthenes [Second Optimisation]{Working Sieve}

// #include <iostream>
// using namespace std;

// bool checkPrime(int n){ //*no need of this func
//     int cnt=0;
//     for(int i=1;i*i<=n;i++){
//         if(n%i==0){
//             cnt++;
//             if((n/i)!=i){
//                 cnt++;
//             }
//         }
//     }

//     if(cnt==2)return true;//can write 0 or 1 too 
//     else return false; 
// }

// int N=1000000;
// bool sieve[1000001];
// void createSieve(){
//     for(int i=2;i<=N;i++){//make everyone as 'true' except '0' and '1'
//         sieve[i]=true;
//     }

//     for(int i=2;i*i<=N;i++){
//         if(sieve[i]==true){             //(j=i*2) as for 5 ,10 ie 5*2 is the first multiple and similarly for all .
//             for(int j=i*i;j<=N;j+=i){ //(j+=i) as 'j' will increase by the no. itself
//                 sieve[j]=false;
//             }
//         }
//     }
// }

// int main(){
//     //O(N log(logn))
//     createSieve();
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         if (sieve[n]==true){//TC to access an array is O(1)
//             cout<<"Yes";
//         }
//         else cout<<"No";
//     }
//     return 0;
// }
//
//
//
//
//
