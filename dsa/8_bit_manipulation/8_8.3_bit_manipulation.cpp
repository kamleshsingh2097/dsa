
// //! 1 Print prime factors of a number [Using Sieve of Eratosthenes]

// #include <iostream>
// using namespace std;

// // int N=1000000;
// // bool sieve[1000001];
// // void createSieve(){
// //     for(int i=2;i<=N;i++){//make everyone as 'true' except '0' and '1'
// //         sieve[i]=true;
// //     }

// //     for(int i=2;i*i<=N;i++){
// //         if(sieve[i]==true){             //(j=i*2) as for 5 ,10 ie 5*2 is the first multiple and similarly for all .
// //             for(int j=i*i;j<=N;j+=i){ //(j+=i) as 'j' will increase by the no. itself
// //                 sieve[j]=false;
// //             }
// //         }
// //     }
// // }

// vector<int> countPrimes(int n)
// {
//     vector<bool> isPrime(n+1, true);
//     vector<int>ans;
//     // Counting prime numbers less than 'N'.
//     int count = 0;
//     for (int i = 2; i<= n; i++)//[i<=n] line important as will not execute for 5
//     {                          //if done like [i<=N]
//         if (isPrime[i] == true)
//         {
//             if (n % i == 0) {
//                 ans.push_back(i);
//             }
//             for (int j = i * i; j <= n; j += i)
//             {
//                 isPrime[j] = false;
//             }
//         }
//     }
//     return ans;
// }

// int main(){
//     // //O(N log(logn))
//     // createSieve();
//     // int t;
//     // cin>>t;
//     // while(t--){
//     //     int n;
//     //     cin>>n;
//     //     if (sieve[n]==true){//TC to access an array is O(1)
//     //         cout<<"Yes";
//     //     }
//     //     else cout<<"No";
//     // }
//     vector<int> ans=countPrimes(10);
//     for(auto it: ans){
//         cout<<it<<" ";
//     }
//     return 0;
// }
//
//
//
//
//

// //! 2 Sieve of Eratosthenes [Second Optimisation]{Working Sieve}

// #include <iostream>
// using namespace std;

// // bool checkPrime(int n){ //*no need of this func
// //     int cnt=0;
// //     for(int i=1;i*i<=n;i++){
// //         if(n%i==0){
// //             cnt++;
// //             if((n/i)!=i){
// //                 cnt++;
// //             }
// //         }
// //     }

// //     if(cnt==2)return true;//can write 0 or 1 too 
// //     else return false; 
// // }

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

