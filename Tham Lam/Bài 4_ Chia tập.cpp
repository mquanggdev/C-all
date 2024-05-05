#include<bits/stdc++.h>
using namespace std;
/*
bài 4: Chia tập : cho mảng a gồm n phần tử và số K . hãy chia mảng a thành hai mảng có kích thước cỡ K và N - K sao cho
hiệu giua tổng hai mảng con là lớn nhất . 
-> cứ cửa sổ nào mà được chứa nhiều phần tử hơn thì nhét hết các phần tử lớn nhất vào cửa sổ đó 
*/
int main()
{
    int n  , k; cin >> n >> k ;
    long long a[n] ;
    long long ans1 = 0 ;
    long long ans2 = 0 ;
    for ( int i = 0 ; i < n ; i++){
        cin >> a[i] ;
    }
    sort (a,a+n);
    if ( k <= n / 2){
        for ( int i = n - 1; i >= (n - k)  ; i--){
            ans1 += a[i] ;
        }
        for ( int j = 0 ; j < n - k ; j++){
            ans2 += a[j] ;
        }
    }
    else {
         for ( int i = n - 1; i >= (n - k)  ; i--){
            ans2 += a[i] ;
        }
        for ( int j = 0 ; j < n - k ; j++){
            ans1 += a[j] ;
        }
    }
    cout << abs(ans2 - ans1) << endl;
    return 0;
}
/*
6 4
3 10 10 7 5 2
27
*/