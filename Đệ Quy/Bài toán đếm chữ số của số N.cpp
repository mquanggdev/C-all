#include<bits/stdc++.h>
using namespace std;
/*Đếm số chữ số của số N : 
Bài toán cơ sở : length = 1 -> N < 10 
Bài toán truy hồi : d(n) = 1 + d(n/10) nếu n > 10 ; 
*/
int LengthOfNumber(long long n){
    if (n < 10) return 1 ;
    else {
        return LengthOfNumber(n / 10) + 1; // mỗi lần chia cho mười tức là chữ số của   
    }
}
int main()
{
    long long n ; cin >> n ;
    cout << "Length of Number : " << endl ;
    cout << LengthOfNumber(n);
    return 0;
}
/*
input :
28282828
output :
8
*/