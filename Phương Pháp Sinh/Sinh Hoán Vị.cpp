#include<bits/stdc++.h>
using namespace std;
/*
Sinh Hoán Vị : Liệt kê tất cả hoán vị của một mảng gồm n phần tử : ví dụ dãy đang được sắp xếp tăng dần thì sau khi hoán vị nó sẽ sắp xếp giảm dần .
*/
int n , a[1001] , ok ;
void init(){
    for ( int  i = 1 ; i <= n ; i ++ ){
        a[i] = i ;
    }
}
void PermutationGen(){
    int i = n - 1 ; // duyệt từ phần tử cuối 
    while ( i >= 0 && a[i] > a[i+1]) --i ; // bước này để tìm ra vị trí i mà tại đó a[i] > a[i+1] ;
    if ( i == 0) ok = 0 ;
    else {
        int j = n ;
        while ( a[i] > a[j]) --j ; 
        swap(a[i] , a[j]) ;
        int l = i + 1 ;
        int r = n ;
        while( l < r){
            swap(a[l],a[r]) ;
            ++l ;
            --r;
        }
    }
}
int main()
{
    cin >> n ;
    init() ;
    ok = 1 ;
    while(ok){
        for ( int i = 1 ; i <= n ; i++){
            cout << a[i] << " " ;
        }
        cout << endl;
        PermutationGen() ;
    }
    return 0;
}