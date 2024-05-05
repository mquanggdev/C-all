#include<bits/stdc++.h>
using namespace std;
/*
Bài 14 : Tổ hợp có tổng bằng X : Cho mảng a gồm n số nguyên dương và số x  , nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng a có tổng bẵng X . Các số trong mảng A thì có thể sử dụng nhiều lần . mỗi tổ hợp của mảng A được in theo thứ tự tăng dần  . 
*/
int n , X , a[1001] , x[50] ;
void init(){
    cin >> n  >> X;
    for ( int i = 1 ; i <= n ; i++ ){
        cin >> a[i] ;
    }
    sort( a + 1, a + n + 1) ;
}
void in(int i){
    for ( int u = 1 ; u <= i ; u++ ){
        cout << a[x[u]] << " " ;
    }
    cout << endl ;
}
void ql(int i, int start , int sum){
    for ( int j = start ; j <= n ; j++ ){
        if ( sum + a[j]  <= X ){
           x[i] = j;
           if ( sum + a[j] == X){
            in(i);
           }
           else ql(i + 1 , j , sum + a[j]) ;
         }
    }
      
}
int main()
{
    init() ;
    ql(1 , 1 , 0) ;
    return 0 ;
}
/*
4 8
2 4 6 8
*/