#include<bits./stdc++.h>
using namespace std;
/*
Bài 10 : Cho dãy gồm n phần tử chỉ gồm số 0 và 1 , số 0 nằm trước số 1 : Hãy đếm các số 0 với độ phức tạp là O(log(n)) ;
Nhận thấy đề bài của bài này nó là : tìm vị trí cuối cùng mà phần tử bằng 0 thì in ra vị trí của nó sẽ là số phần tử số 0 -> tìm kiếm nhị phân
*/
//ở dưới là phiên bản code tổng quát , sẽ có cách ngắn hơn!
int  solve(int a[] , int l , int r , int x) {
    if ( l > r ) return -1  ;
    int mid = ( r + l) / 2 ;
    if ( a[mid] == x){
        int res = mid ;
        int t = solve(a,mid + 1,r,x);
        if (t != -1){
            res = t ;
        }
        return res ;
    }
    else if ( a[mid] < x ) return solve(a,mid+1,r,x);
    return solve(a,l,mid-1,x);
}
int main()
{
   int n ; cin >> n;
   int a[n] ;
   for ( int &x : a){ cin >> x;}
   int t = solve(a,0,n-1,0);
   cout << t + 1 << endl;
    return 0;
}
/*
5  
0 0 1 1 1
2
*/