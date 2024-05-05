#include<bits./stdc++.h>
using namespace std;
/*
Bài 13 _ Dãy xâu nhị phân -Khá giống với xâu AB
*/

long long F[1001] ; // để lưu độ dài chuỗi
int find (int n , long long k){
    if ( n == 1 ) return 0 ;
    else if ( n == 2) return 1 ;
    long long mid = F[n - 2] ;
    if ( k > mid){
        return find(n - 1 , k - mid) ;
    }
    else return find(n - 2 , k );
}
int main()
{
   F[1] = F[2] = 1 ;
   for( int i = 3 ; i <= 92 ; i++ ){
    F[i]  = F[i - 2] + F[i - 1] ;
   }
   int n ;
   long long k ;
   cin >> n >> k ;
   cout << find(n , k) ;
    return 0;
}
/*
7 7
0
8 6
1
*/