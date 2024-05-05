#include<bits/stdc++.h>
using namespace std;
/*
Bài 19 : Dãy con có tổng lẻ : cho mảng A gồm N phần tử , liệt kê các tập con (giữ đúng thứ tự trước sau) của mảng A[] có tổng các phần tử là số lẻ , mỗi phần tử chỉ được lấy 1 lần . chú ý nếu hai tập chứa 2 phần tử có giá trị giống nhau nhưng ở vị trí khác nhau thì được tính là hai tập khác nhau
 * 
*/
int n , a[1001] , used[101] , x[1001] ;
void init(){
    cin >> n ;
    for ( int i = 1 ; i <= n ; i++ ){
        cin >> a[i] ;
    }
}
void in(int i ){
    for ( int u = 1 ; u <= i ; u++){
        cout << a[x[u]] << " " ;
    }
    cout << endl ;
}
void ql(int i , int start , int sum ){
    for ( int j = start ; j <= n ; j++){
        if (!used[j]){
           x[i] = j ;
           used[j] = true ;
           if ( (sum + a[j]) % 2 == 1){
            in(i) ;
            } 
          ql(i + 1 ,j + 1 , sum + a[j]) ;
          used[j] = false ;
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
4
9 7 9 9
9
9 7 9
9 7 9
9 9 9
7
7 9 9
9
9
*/