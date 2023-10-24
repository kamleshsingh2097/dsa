
// /*The approach of the code is to use bitwise manipulation to 
// find if there is any unset bit or not using N & (N+1). 

// For example ‘N’ = 15 is 1111 and (N+1)= 16 is 10000 so N & 
// (N+1)= 0 which means there’s no unset bit in ‘N’. 

// Once we have found if there’s any unset bit in ‘N’, we can 
// set the least significant unset bit of ‘N’ to 1 by using the
// bitwise OR operator with ‘N’ and (N + 1). (N+1) has the same
// set bits as ‘N’ up to the least significant unset bit of ‘N’.*/

// //! 1 Set the rightmost unset bit

// #include <iostream>

// using namespace std;

// int setBits(int N){
//     // Check if there's any unset bits.
//     if((N & (N+1)) == 0){
//         cout<<N<<endl;
//         return N;}
    
//     // Set the least significant unset bit of ‘N’ to 1 and return.
//     return N | (N+1);
// }

// int main() {
//   int N = 15;
//   cout << setBits(N) << endl;
//   return 0;
// }
//
//
//
//
//

/*The intuition here is that we can find the largest power of
2’s which can satisfy the equation 
‘dividend = divisor * maximum 2’s power + remainder’.

 

If found we set ‘quotient’ to ‘quotient = quotient +  maximum
2’s power’.*/

// //! 2 Divide Two Integers

// #include <iostream>
// using namespace std;

// int divideTwoInteger(int dividend, int divisor) 
// {
//     // Initially store  whether dividend, divisor are negative or positive.
    
//     bool isDividendNegative = false;
//     if(dividend < 0)
//     {
//         dividend *= -1;
//         isDividendNegative = true;
//     }

//     bool isDivisorNegative = false;
//     if(divisor < 0)
//     {
//         divisor *= -1;
//         isDivisorNegative = true;
//     }

//     long long b = divisor;
//     long long a = dividend;

//     long long quotient = 0;

//     for(int i = 30; i >= 0; i--) // for b=-3 and a=7
//     {                        //(b is not -3 but 3 because of above)
//         if((b<<i) <= a) //condition true on i=1
//         {
//             a -= (b<<i);       //a=1
//             quotient |= (1<<i);//quotient=2
//             //now since [a=1] if loop will never become true
//             //as even at [i=0] b=3
//         }
//     }

//     // Both are negative.
//     if(isDividendNegative && isDivisorNegative)
//     {
//         return quotient;
//     }

//     // Both are positive.
//     if(!isDividendNegative && !isDivisorNegative)
//     {
//         return quotient;
//     }

//     // One is negative and one is positive.
//     return -1*quotient;

// }

// int main(){
//     int ans =divideTwoInteger(10,-3);
//     cout<<ans<<endl;
//     return 0;
// }
//
//
//
//
//
