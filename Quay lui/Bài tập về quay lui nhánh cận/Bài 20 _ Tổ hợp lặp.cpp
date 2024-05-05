#include<bits/stdc++.h>
using namespace std;
/*bài 20 : Tổ hợp lặp : Cho xâu ký tự S gồm N chữ cái khác nhau , hãy liệt kê tổ hợp chập K của N ký tự trên và in ra theo thứ tự từ điển tăng dần*/
int n , a[1001] , x[1001];
int k ;
string str ;
void in(){
    for ( int u = 1 ; u <= k ; u++){
        cout << str[x[u]];
    }
    cout << endl;
}
void ql( int i , int  bd){
    for( int j = bd ; j <= n ;j++){ // luôn nhớ j là vị trí của các phần tử dãy còn x[i] là vị trí của phần tử đó trong cấu hình
        x[i] = j ;
        if ( i == k){
            in() ;
        }
        else ql(i + 1 , j  ) ;
    }
}
int main()
{
    cin >> n >> k >> str; 
    str = "0" + str ;
    ql(1,1) ;
    return 0 ;
}
/*
4 2
ABCD

AA
AB
AC
AD
BB
BC
BD
CC
CD
DD
*/