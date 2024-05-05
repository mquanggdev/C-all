#include<bits/stdc++.h>
using namespace std;
/*
bài 3 : Max product sum : cho mảng A gồm N phần tử , nhiệm vụ của bạn là sắp đặt lại vị trí của các phần tử trong mảng và tính toán giá trị lớn nhất của biểu thức với max = a[i] * i ( i = 0 -> n - 1) ; 
*/
int main()
{
    int n ; cin >> n ;
    long long a[n] ;
    long long ans = 0 ;
    for ( int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    sort (a,a+n);
    for ( int i = 0 ; i < n ; i++){
        ans += 1ll*a[i] * i ;
    }
    cout << ans << endl;
    return 0;
}
/*
6
8 1 7 8 9 1
116
*/