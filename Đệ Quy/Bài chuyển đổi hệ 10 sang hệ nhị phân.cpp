#include<bits/stdc++.h>
using namespace std;
/*Bài chuyển đổi cơ số : Chuyển từ hệ 10 sang hệ 2 : 
bài toán cơ sở , nếu n = 0 => in 0 ;
                 nếu n = 1 => in 1 ;
Công thức truy hồi : X = (n / 2)(lưu n%2) rồi lại lấy (n/2 )/2 ; 
*/
void DecmicaltoBinary(long long n){
    string ans ;
    if ( n < 2){
        cout << n ;
    }
    else {
        DecmicaltoBinary(n/2) ;
        cout << n % 2 ;
    }
}
int main()
{
    cout << "Please enter your decimal :\n";
    long long n ; cin >> n  ;
    cout << "Binary : ";
    DecmicaltoBinary(n) ;
    return 0 ;
}
/*
input : 282828282828
ouput : 100000111011001111000010001101111001100
*/